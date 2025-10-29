#include <LiquidCrystal.h>
#include <Servo.h>
#include <Wire.h>

// --- 并口LCD引脚定义 ---
const int rs = 7, en = 8, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// --- 舵机设置 ---
Servo fanServo;
const int SERVO_PIN = 9;

// --- 引脚定义 ---
#define TEMP_PIN A0
#define TOUCH_PIN 2
#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 6
#define BUZZER_PIN 4

// --- 模式和档位定义 ---
#define MODE_AUTO 0
#define MODE_GEAR_1 1
#define MODE_GEAR_2 2
#define MODE_GEAR_3 3
const int GEAR1_SWING = 20;
const int GEAR2_SWING = 45;
const int GEAR3_SWING = 70;

// --- 温度阈值 ---
const float WARM_TEMP = 26.0;
const float HOT_TEMP = 30.0;

// --- 全局变量 ---
int current_mode = MODE_AUTO;
unsigned long last_beep_time = 0;

// --- 非阻塞控制所需变量 ---
unsigned long last_touch_time = 0; 
unsigned long last_servo_move_time = 0;
int current_servo_pos = 90;
int servo_direction = 1;

// === 新增：用于慢速温度采集的变量 ===
unsigned long last_temp_read_time = 0;          // 记录上次读取温度的时间
const unsigned long temp_read_interval = 1000;  // 设置读取间隔为1000毫秒 (1秒)

// === 新增：用于存储当前状态的变量 ===
float current_temp = 0.0;
int current_swing_angle = 0;
String current_mode_string = "Auto";


// setup()函数：初始化
void setup() {
  Serial.begin(9600);
  
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(TOUCH_PIN, INPUT);

  fanServo.attach(SERVO_PIN);
  fanServo.write(current_servo_pos); 

  lcd.begin(16, 2);
  lcd.print("Smart Fan System");
  lcd.setCursor(0, 1);
  lcd.print("Final Version!");
  beep(500, 150);
  delay(2000);
}

// loop()函数：重构为高频和低频任务
void loop() {
  // =======================================================
  // 1. 高频任务：这些任务每次循环都执行，以保证最高响应度
  // =======================================================
  check_touch_input(); // 随时检查触摸
  control_servo_non_blocking(current_swing_angle); // 持续、平滑地控制舵机


  // =======================================================
  // 2. 低频任务：这些任务每隔一段时间才执行一次，以提高效率
  // =======================================================
  if (millis() - last_temp_read_time > temp_read_interval) {
    
    // 更新计时器
    last_temp_read_time = millis(); 

    // ---- 在这个if语句块内，执行所有和温度相关的“慢”任务 ----

    // a. 收集温度
    current_temp = read_temperature(); 

    // b. 根据模式和温度，决定系统状态 (LED颜色和摆动幅度)
    if (current_mode == MODE_AUTO) {
      current_mode_string = "Auto";
      if (current_temp >= HOT_TEMP) {
        current_swing_angle = GEAR3_SWING;
        set_led_color(255, 0, 0); 
        if (millis() - last_beep_time > 1000) {
          beep(1000, 100);
          last_beep_time = millis();
        }
      } else if (current_temp >= WARM_TEMP) {
        current_swing_angle = GEAR2_SWING;
        set_led_color(255, 150, 0);
      } else {
        current_swing_angle = GEAR1_SWING;
        set_led_color(0, 255, 0);
      }
    } else { 
      set_led_color(0, 100, 255);
      if (current_mode == MODE_GEAR_1) {
        current_mode_string = "Gear 1";
        current_swing_angle = GEAR1_SWING;
      } else if (current_mode == MODE_GEAR_2) {
        current_mode_string = "Gear 2";
        current_swing_angle = GEAR2_SWING;
      } else if (current_mode == MODE_GEAR_3) {
        current_mode_string = "Gear 3";
        current_swing_angle = GEAR3_SWING;
      }
    }
    
    // c. 用最新的状态，统一更新一次LCD屏幕
    update_lcd(current_temp, current_mode_string, current_swing_angle);
  }
}

// --- 所有辅助函数 (保持不变) ---

void check_touch_input() {
  if (digitalRead(TOUCH_PIN) == HIGH) {
    if (millis() - last_touch_time > 300) {
      current_mode = (current_mode + 1) % 4;
      beep(800, 100);
      last_touch_time = millis(); 
    }
  }
}

void control_servo_non_blocking(int swing) {
  if (millis() - last_servo_move_time > 15) {
    last_servo_move_time = millis();
    if (swing == 0) {
      fanServo.write(90);
      return;
    }
    current_servo_pos += servo_direction;
    fanServo.write(current_servo_pos);
    if (current_servo_pos >= 90 + swing || current_servo_pos <= 90 - swing) {
      servo_direction *= -1;
    }
  }
}

void update_lcd(float temp, String mode, int swing) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp, 1);
  lcd.print("C");
  lcd.setCursor(11, 0);
  lcd.print(mode);
  lcd.setCursor(0, 1);
  lcd.print("Swing: +/-");
  lcd.print(swing);
  lcd.print(" Deg");
}

float read_temperature() {
  int val = analogRead(TEMP_PIN);
  return (val / 1023.0) * 5000.0 / 10.0;
}

void set_led_color(int r, int g, int b) {
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
}

void beep(int frequency, int duration) {
  tone(BUZZER_PIN, frequency, duration);
}