### **Lecture Notes: Proportional Action**
### **讲义：比例作用**

---

### **1. Introduction to Control Actions**
### **1. 控制作用简介**

Control actions are the strategies used by a controller to manipulate a system's output.
控制作用是控制器用来操纵系统输出的策略。

Proportional control is a fundamental type of control action where the controller's output is directly proportional to the error signal.
比例控制是一种基本的控制作用类型，其中控制器的输出与误差信号成正比。

The error (E) is the difference between the desired setpoint (D) and the actual output (X).
误差 (E) 是期望设定点 (D) 和实际输出 (X) 之间的差值。

---

### **2. Case Study: Control of a DC Motor**
### **2. 案例研究：直流电机的控制**

A DC motor is a common actuator that converts electrical energy (input voltage) into mechanical motion (output shaft speed).
直流电机是一种常见的执行器，它将电能（输入电压）转换为机械运动（输出轴速）。

#### **2.1 Open-Loop Control**
#### **2.1 开环控制**

In an open-loop system, the controller action is independent of the process output.
在开环系统中，控制器作用独立于过程输出。

The user specifies a desired speed (D), and the controller, acting as an electronic amplifier, generates an input voltage (U) for the motor.
用户指定一个期望速度 (D)，控制器作为一个电子放大器，为电机生成一个输入电压 (U)。

The control law is: U = Kp × D, where Kp is the proportional gain of the amplifier.
控制律为：U = Kp × D，其中 Kp 是放大器的比例增益。

**Key Limitation:** The actual motor speed is highly dependent on motor dynamics and any load disturbances, as there is no feedback to correct for errors.
**主要局限性：** 实际电机速度高度依赖于电机动态特性和任何负载扰动，因为没有反馈来纠正误差。

As seen in graphs, when a disturbance is introduced, the output speed deviates significantly from the desired speed, and the system cannot correct itself.
如图表所示，当引入扰动时，输出速度会显著偏离期望速度，且系统无法自行纠正。

#### **2.2 Closed-Loop (Proportional) Control**
#### **2.2 闭环（比例）控制**

In a closed-loop system, the controller action depends on the process output by using feedback.
在闭环系统中，控制器作用通过使用反馈来依赖于过程输出。

The actual motor speed (X) is measured, typically with a tachometer, which produces a voltage proportional to the speed.
实际电机速度 (X) 被测量，通常使用测速发电机，它产生一个与速度成正比的电压。

The controller compares the desired speed (D) with the actual speed (X) to calculate the error: E = D - X.
控制器比较期望速度 (D) 和实际速度 (X) 来计算误差：E = D - X。

The controller then produces an output voltage proportional to this error. The proportional control law is: U = Kp × E = Kp × (D - X).
然后控制器产生一个与此误差成正比的输出电压。比例控制律为：U = Kp × E = Kp × (D - X)。

**Key Advantage:** This system has a **reduced sensitivity to load disturbances**.
**主要优点：** 该系统对**负载扰动的敏感度降低**。

When a disturbance occurs, the actual speed (X) changes, which alters the error (E). The controller then automatically adjusts its output (U) to counteract the disturbance and bring the speed back towards the desired value.
当发生扰动时，实际速度 (X) 改变，从而改变误差 (E)。控制器随后会自动调整其输出 (U) 以对抗扰动，并将速度带回期望值附近。

---

### **3. Case Study: Proportional Control of Ventilation Rate**
### **3. 案例研究：通风率的比例控制**

#### **3.1 System Model**
#### **3.1 系统模型**

The ventilation system can be represented by a first-order transfer function model, which relates the input voltage (U) to the output airflow (X).
该通风系统可以用一个一阶传递函数模型来表示，该模型将输入电压 (U) 与输出气流 (X) 关联起来。

Plant Transfer Function: Gp(s) = X(s) / U(s) = 1.5 / (10s + 1).
被控对象传递函数：Gp(s) = X(s) / U(s) = 1.5 / (10s + 1)。

#### **3.2 Closed-Loop Transfer Function**
#### **3.2 闭环传递函数**

Using a proportional controller with gain Kp, the closed-loop transfer function relates the desired airflow (D) to the actual airflow (X).
使用一个增益为 Kp 的比例控制器，闭环传递函数将期望气流 (D) 与实际气流 (X) 关联起来。

For a unity negative feedback system, the formula is: T(s) = G(s) / (1 + G(s)), where G(s) = Kp × Gp(s).
对于单位负反馈系统，公式为：T(s) = G(s) / (1 + G(s))，其中 G(s) = Kp × Gp(s)。

Substituting and simplifying, we get the closed-loop transfer function:
代入并化简，我们得到闭环传递函数：
X(s) / D(s) = (1.5 Kp) / (10s + 1 + 1.5 Kp).
X(s) / D(s) = (1.5 Kp) / (10s + 1 + 1.5 Kp)。

#### **3.3 Characteristic Equation and System Dynamics**
#### **3.3 特征方程与系统动态**

The **characteristic equation** is the denominator of the closed-loop transfer function set to zero: 10s + 1 + 1.5 Kp = 0.
**特征方程**是闭环传递函数的分母置零：10s + 1 + 1.5 Kp = 0。

The roots of this equation are the **poles** of the system, which determine its stability and dynamic behavior.
该方程的根是系统的**极点**，它们决定了系统的稳定性和动态行为。

By rearranging the equation into the standard form (τ_new * s + 1 = 0), we find the new time constant: τ_new = 10 / (1 + 1.5 Kp).
通过将方程重排为标准形式 (τ_new * s + 1 = 0)，我们找到新的时间常数：τ_new = 10 / (1 + 1.5 Kp)。

This shows that **feedback changes the dynamics of the system**. A larger gain Kp results in a smaller time constant, meaning the system responds faster.
这表明**反馈改变了系统的动态特性**。更大的增益 Kp 会导致更小的时间常数，意味着系统响应更快。

#### **3.4 Stability Analysis**
#### **3.4 稳定性分析**

The pole of the system is s = -(1 + 1.5 Kp) / 10.
系统的极点是 s = -(1 + 1.5 Kp) / 10。

For the system to be stable, its poles must be in the left-half of the s-plane (i.e., have a negative real part).
为了使系统稳定，其极点必须位于 s 平面的左半部分（即，具有负实部）。

Assuming Kp is positive, the pole will always be negative, so this closed-loop system is always stable.
假设 Kp 为正，极点将永远为负，因此这个闭环系统总是稳定的。

#### **3.5 Steady-State Analysis**
#### **3.5 稳态分析**

The **steady-state value** is the final output of the system as time approaches infinity. It can be found using the Final Value Theorem (by setting s = 0 in the transfer function).
**稳态值**是当时间趋于无穷时系统的最终输出。它可以通过使用终值定理（在传递函数中令 s = 0）来找到。

Steady-State Value: x(t→∞) = [ (1.5 Kp) / (1 + 1.5 Kp) ] × d.
稳态值：x(t→∞) = [ (1.5 Kp) / (1 + 1.5 Kp) ] × d。

The **steady-state gain** is the ratio of the steady-state output to the input, which is (1.5 Kp) / (1 + 1.5 Kp).
**稳态增益**是稳态输出与输入之比，即 (1.5 Kp) / (1 + 1.5 Kp)。

Since this gain is always less than 1 (for Kp > 0), the actual output will always be less than the desired value.
由于该增益总是小于 1（对于 Kp > 0），实际输出将总是小于期望值。

This leads to a **Steady-State Error**, which is a fundamental characteristic of proportional control for this type of system.
这导致了**稳态误差**，这是比例控制对此类系统的一个基本特征。

Steady-State Error: e(∞) = d - x(∞) = d × [ 1 / (1 + 1.5 Kp) ].
稳态误差：e(∞) = d - x(∞) = d × [ 1 / (1 + 1.5 Kp) ]。

**Conclusion:** The larger the control gain (Kp), the smaller the steady-state error, but the error can never be completely eliminated with proportional control alone.
**结论：** 控制增益 (Kp) 越大，稳态误差越小，但仅靠比例控制永远无法完全消除误差。