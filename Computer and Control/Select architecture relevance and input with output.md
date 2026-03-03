### **Computers – Choices, architecture, relevance and I/Os**
### **计算机——选择、架构、相关性与输入/输出**

---

### **1. Introduction to Embedded Systems (Revision)**
### **1. 嵌入式系统简介（复习）**

A microcontroller (µC) is an embedded system on a single silicon chip that includes a microprocessor, timers, ADC, and other peripherals to control devices from within.
微控制器 (µC) 是单一硅芯片上的嵌入式系统，包含微处理器、定时器、ADC 和其他外围设备，用于从内部控制设备。

Microcontrollers are cost-effective, reliable, and unobtrusive, making them suitable for a wide range of applications.
微控制器具有成本效益、可靠且不引人注目的特点，使其适用于广泛的应用。

They are programmable in various languages, with the code being converted to machine code and stored in non-volatile flash memory.
它们可以用多种语言进行编程，代码被转换成机器码并存储在非易失性闪存中。

Programming environments often allow for simulation (fast) and debugging (slow) of the code before it is transferred to the device.
编程环境通常允许在将代码传输到设备之前进行仿真（速度快）和调试（速度慢）。

---

### **2. Embedded System Design Issues**
### **2. 嵌入式系统设计问题**

Engineers must consider two main design issues: selecting the appropriate device family and determining the necessary peripherals for a given application.
工程师必须考虑两个主要的设计问题：选择合适的设备系列和确定特定应用所需的外围设备。

Key factors to consider during the design process include:
在设计过程中需要考虑的关键因素包括：
*   **Cost:** The overall price of the components.
    **成本:** 组件的总价格。
*   **Familiarity:** How well the design team knows the hardware and software.
    **熟悉度:** 设计团队对硬件和软件的了解程度。
*   **Ease of integration:** How easily the system can be incorporated into a larger product.
    **集成难易度:** 系统集成到更大型产品中的难易程度。
*   **Use in existing products:** Whether the component is already used in other company products.
    **在现有产品中的使用:** 该组件是否已在公司其他产品中使用。
*   **Compatibility:** How well the device works with the application environment.
    **兼容性:** 设备与应用环境的配合程度。
*   **Obsolescence:** The risk of the device becoming outdated or unavailable.
    **过时性:** 设备变得过时或无法获得的风险。
*   **Peripherals:** The specific I/O devices needed.
    **外围设备:** 所需的特定输入/输出设备。

Once a device is chosen, further options include speed, package type, memory capacity, power consumption, and available interfaces like GPIO, I2C, Serial, and on-board ADCs.
一旦选定设备，还需考虑速度、封装类型、内存容量、功耗以及可用的接口，如 GPIO、I2C、串行和板载 ADC。

---

### **3. Fundamental Microcontroller (µC) Architecture and Operation**
### **3. 微控制器 (µC) 的基本架构和操作**

Microcontrollers fundamentally perform four tasks:
微控制器基本上执行四个任务：
1.  **Receive information:** Gathers signals from the environment.
    **接收信息:** 从环境中收集信号。
2.  **Encode and Store:** Converts signals into numbers and stores them in RAM.
    **编码和存储:** 将信号转换为数字并将其存储在 RAM 中。
3.  **Process:** Manipulates the numbers according to a program stored in ROM.
    **处理:** 根据存储在 ROM 中的程序处理这些数字。
4.  **Output information:** Produces an analogue or digital signal to perform work.
    **输出信息:** 产生模拟或数字信号以执行工作。

The core function is signal processing, not power delivery.
其核心功能是信号处理，而不是功率传输。

#### **Computer Architectures**
#### **计算机架构**

*   **Von Neumann Architecture:** Uses a single bus for both data and instructions, which is memory-efficient but can be slow as data and instructions cannot be accessed simultaneously.
    **冯·诺依曼架构:** 对数据和指令使用单一总线，内存效率高，但速度可能较慢，因为数据和指令无法同时访问。
*   **Harvard Architecture:** Uses separate buses and memory for data and instructions, allowing simultaneous retrieval, which is faster and more robust, though less memory-efficient.
    **哈佛架构:** 为数据和指令使用独立的总线和内存，允许同时检索，速度更快、更稳健，但内存效率较低。

#### **Instruction Set Architectures (ISAs)**
#### **指令集架构 (ISAs)**

*   **RISC (Reduced Instruction Set Computer):** Uses a small set of simple, fast instructions. Memory access is limited to specific load/store instructions, and it requires fewer transistors. (e.g., Atmel AVR, ARM).
    **精简指令集计算机 (RISC):** 使用一小组简单、快速的指令。内存访问仅限于特定的加载/存储指令，需要较少的晶体管。（例如 Atmel AVR, ARM）。
*   **CISC (Complex Instruction Set Computer):** Uses single commands that can execute several operations, resulting in a wide range of cycle operations per instruction. (e.g., MC6800, 8051, Z80).
    **复杂指令集计算机 (CISC):** 使用可以执行多个操作的单个命令，导致每条指令的周期操作范围很广。（例如 MC6800, 8051, Z80）。

---

### **4. Relevance to Control Engineering**
### **4. 与控制工程的相关性**

In a typical control system, the microcontroller acts as the **Controller**.
在典型的控制系统中，微控制器充当**控制器**的角色。

*   **Sensors** provide input to the microcontroller, measuring physical quantities.
    **传感器**向微控制器提供输入，测量物理量。
*   The **Microprocessor** (within the µC) processes this input based on a desired output.
    **微处理器**（在 µC 内部）根据期望的输出处理此输入。
*   The **Controller** sends a control signal to the **Actuators**.
    **控制器**向**执行器**发送控制信号。
*   **Actuators** produce an output that affects the **System**.
    **执行器**产生影响**系统**的输出。

#### **Sensors (Input Devices)**
#### **传感器（输入设备）**

Sensors gather information from the environment to inform the controller.
传感器从环境中收集信息以通知控制器。

*   **Analogue Sensors:** Provide a continuously varying signal (e.g., a varying voltage). Examples include thermistors, photoresistors, and potentiometers.
    **模拟传感器:** 提供连续变化的信号（例如，变化的电压）。例子包括热敏电阻、光敏电阻和电位器。
*   **Digital Sensors:** Provide a discrete signal, such as ON/OFF or encoded data. Examples include touch modules, key switches, and IR receivers.
    **数字传感器:** 提供离散信号，例如开/关或编码数据。例子包括触摸模块、按键开关和红外接收器。

To process an analogue signal, an **Analogue-to-Digital Converter (ADC)** is required.
为了处理模拟信号，需要一个**模数转换器 (ADC)**。

The Arduino Uno has six built-in ADCs with a 10-bit resolution, meaning they can represent an input voltage with 1024 discrete values (0-1023).
Arduino Uno 有六个内置的 10 位分辨率 ADC，这意味着它们可以用 1024 个离散值（0-1023）来表示输入电压。

#### **Actuators (Output Devices)**
#### **执行器（输出设备）**

Actuators are used to get a useful output from the system, such as motion, light, or data, to stimulate the plant/system.
执行器用于从系统中获得有用的输出，例如运动、光或数据，以刺激设备/系统。

Most actuators require a digital signal, which can be a simple ON/OFF signal or a more complex one like **Pulse Width Modulation (PWM)**.
大多数执行器需要数字信号，这可以是简单的开/关信号或更复杂的信号，如**脉宽调制 (PWM)**。
*   Examples of actuators include LEDs, servo motors, LCD displays, and buzzers.
    执行器的例子包括 LED、伺服电机、LCD 显示器和蜂鸣器。

If an actuator requires an analogue signal (a continuously varying voltage from 0-5V), a **Digital-to-Analogue Converter (DAC)** is needed.
如果执行器需要模拟信号（从 0-5V 连续变化的电压），则需要一个**数模转换器 (DAC)**。

The Arduino Uno does not have a built-in DAC, so an external one or a technique like PWM must be used to approximate an analogue output.
Arduino Uno 没有内置的 DAC，因此必须使用外部 DAC 或像 PWM 这样的技术来模拟模拟输出。

---

### **5. Microcontroller Device Families**
### **5. 微控制器设备系列**

*   **AVR Family (e.g., ATmega328P used in Arduino Uno):**
    **AVR 系列（例如，Arduino Uno 中使用的 ATmega328P）：**
    *   Manufactured by Atmel.
        由 Atmel 制造。
    *   Modified Harvard architecture and a RISC microprocessor.
        采用改进的哈佛架构和 RISC 微处理器。
    *   It is an 8-bit, single-chip microcontroller.
        它是一个 8 位单芯片微控制器。

*   **8051 Family:**
    **8051 系列：**
    *   Developed by Intel in 1980.
        由英特尔于 1980 年开发。
    *   Internal Harvard architecture with a CISC processor.
        采用内部哈佛架构和 CISC 处理器。
    *   Available in 8, 16, and 32-bit variants from many vendors.
        由许多供应商提供 8、16 和 32 位变体。

*   **Motorola MC68HC08 Series:**
    **摩托罗拉 MC68HC08 系列：**
    *   A long-standing family of CISC microprocessors using Von Neumann architecture.
        一个历史悠久的 CISC 微处理器系列，采用冯·诺依曼架构。

*   **PIC (Peripheral Interface Controller):**
    **PIC（外围接口控制器）：**
    *   Made by Microchip Technology.
        由 Microchip Technology 制造。
    *   Based on a Harvard architecture and RISC principles.
        基于哈佛架构和 RISC 原理。
    *   Known for being entry-level and easy to use, popular with hobbyists.
        以入门级和易于使用而闻名，深受业余爱好者欢迎。

*   **Raspberry Pi:**
    **树莓派：**
    *   A more powerful single-board computer, not a microcontroller.
        一个功能更强大的单板计算机，而不是微控制器。
    *   Uses a Broadcom SoC (System on a Chip) with an ARM Cortex processor.
        使用带有 ARM Cortex 处理器的 Broadcom SoC（片上系统）。
    *   Runs a full operating system (e.g., Raspbian) from an SD card.
        通过 SD 卡运行完整的操作系统（例如 Raspbian）。