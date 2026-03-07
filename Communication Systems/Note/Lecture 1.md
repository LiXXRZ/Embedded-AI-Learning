# 🎓 **SCC.160: Fundamentals of Communication Systems**

This guide synthesizes all key concepts from your lecture slides into a structured format perfect for exam preparation.

### **Part 1: Foundational Concepts of Communication**

#### **1.1 What is Communication?**

*   **Communication:** The process of exchanging information from a source to a destination.
    **通信 (Tōngxìn):** 是信息从信源交换到信宿的过程。

*   **Electronic Communication System:** A complete mechanism for electronically transmitting, receiving, and processing information.
    **电子通信系统 (Diànzǐ Tōngxìn Xìtǒng):** 是一个用于以电子方式传输、接收和处理信息的完整机制。

*   **Objectives and Needs of Communication:**
    *   **Interaction:** Enables timely interaction on a global scale (social, political, scientific).
        **互动 (Hùdòng):** 实现全球范围内的及时互动（社会、政治、科学领域）。
    *   **Information Transfer:** Transmits various forms of information like audio, video, text, and data.
        **信息传输 (Xìnxī Chuánshū):** 传输音频、视频、文本和数据等多种形式的信息。
    *   **Broadcasting:** Distributes information to a mass audience through radio and television.
        **广播 (Guǎngbō):** 通过广播和电视向大众传播信息。

#### **1.2 Elements of a Communication System**

A communication system consists of five core components:
一个通信系统由五个核心部分组成：

1.  **Information Source (信源):**
    *   **Function:** Produces the required message to be transmitted (e.g., speech, data).
        **功能:** 产生需要传输的消息（例如：语音、数据）。
    *   **Input Transducer:** A device that converts one form of energy into another.
        **输入换能器:** 一种将能量从一种形式转换为另一种形式的设备。
    *   **Example:** A microphone converts sound waves (acoustic energy) into an electrical signal.
        **示例:** 麦克风将声波（声能）转换为电信号。

2.  **Transmitter (发送器):**
    *   **Function:** Processes the input signal to produce a signal suitable for transmission over the channel.
        **功能:** 处理输入信号，生成一个适合在信道上传输的信号。
    *   **Key Process:** This often involves modulation.
        **关键过程:** 这通常涉及调制。

3.  **Channel / Transmission Medium (信道 / 传输介质):**
    *   **Function:** The physical path that provides a connection between the transmitter and receiver.
        **功能:** 提供发送器和接收器之间连接的物理路径。
    *   **Key Issue:** Noise is inevitably added to the signal within the channel.
        **关键问题:** 噪声不可避免地在信道中被添加到信号里。

4.  **Receiver (接收器):**
    *   **Function:** Extracts the original message signal from the degraded signal received from the channel.
        **功能:** 从信道接收到的降级信号中提取出原始的消息信号。
    *   **Key Processes:** This involves amplification, filtering, and demodulation.
        **关键过程:** 这涉及放大、滤波和解调。

5.  **Destination / Information Sink (信宿 / 信息汇):**
    *   **Function:** The final destination that accepts the received information.
        **功能:** 接收信息的最终目的地。
    *   **Output Transducer:** A device like a speaker converts the electrical signal back into sound waves.
        **输出换能器:** 像扬声器这样的设备将电信号转换回声波。

---

### **Part 2: Signals - The Carrier of Information**

#### **2.1 Signal Classification**

*   **Analog Signal (模拟信号):**
    *   A signal that is continuous in both time and amplitude.
        在时间和幅度上都连续的信号。
*   **Digital Signal (数字信号):**
    *   A signal made of discrete symbols from a finite set; it is discrete in amplitude but continuous in time.
        由有限集合中的离散符号构成的信号；它在幅度上是离散的，但在时间上是连续的。
*   **Periodic Signal (周期信号):**
    *   A signal that repeats a pattern over a measurable time frame called a period.
        在一个称为周期的可测量时间范围内重复一个模式的信号。
*   **Aperiodic (Non-periodic) Signal (非周期信号):**
    *   A signal that changes without exhibiting a repeating pattern or cycle, such as human speech.
        变化时没有表现出重复模式或周期的信号，例如人类语音。

#### **2.2 Signal Dimensionality**

*   **1D Signal:** A function of one variable (e.g., Speech, which varies over time).
    **一维信号:** 单一变量的函数（例如：随时间变化的语音）。
*   **2D Signal:** A function of two variables (e.g., a still Picture, with x and y coordinates).
    **二维信号:** 两个变量的函数（例如：具有x和y坐标的静态图片）。
*   **3D Signal:** A function of three variables (e.g., a Video signal, varying over x, y, and time).
    **三维信号:** 三个变量的函数（例如：随x、y和时间变化的视频信号）。

#### **2.3 Sine Wave Parameters (Analog Signals)**

A simple analog signal (sine wave) is defined by three parameters:
一个简单的模拟信号（正弦波）由三个参数定义：

*   **Peak Amplitude (A) (峰值幅度):**
    *   The absolute value of the signal's highest intensity, proportional to its energy.
        信号最高强度的绝对值，与其携带的能量成正比。
*   **Frequency (f) and Period (T) (频率和周期):**
    *   **Period (T):** The time required to complete one cycle, measured in seconds (s).
        **周期 (T):** 完成一个周期所需的时间，单位是秒 (s)。
    *   **Frequency (f):** The number of cycles completed in one second, measured in Hertz (Hz).
        **频率 (f):** 一秒钟内完成的周期数，单位是赫兹 (Hz)。
    *   **Critical Formula:** Frequency is the inverse of the period.
        **核心公式:** 频率是周期的倒数。
        `f = 1/T` and `T = 1/f`
*   **Phase (φ) (相位):**
    *   Describes the position of the waveform relative to time 0, measured in degrees or radians.
        描述波形相对于时间点 0 的位置，单位是度或弧度。

#### **2.4 Special Signal Concepts**

*   **Composite Signal (复合信号):**
    *   A signal made up of more than one frequency component (multiple sine waves).
        由多个频率分量（多个正弦波）构成的信号。
*   **Frequency as a Rate of Change:**
    *   A signal that changes rapidly has a high frequency; a signal that changes slowly has a low frequency.
        变化迅速的信号频率高；变化缓慢的信号频率低。
*   **DC (Direct Current) Signal (直流信号):**
    *   A signal with a constant amplitude has a **frequency of zero**.
        一个恒定幅度的信号其**频率为零**。

#### **2.5 Digital Signal Concepts**

*   **Bit Interval (比特间隔):** The time required to send one single bit (digital equivalent of period).
    发送一个比特所需的时间（周期的数字等效概念）。
*   **Bit Rate (比特率):** The number of bits sent in one second, in bits per second (bps) (digital equivalent of frequency).
    一秒钟内发送的比特数，单位是比特每秒 (bps)（频率的数字等效概念）。
*   **Digital Alphabet (数字字母表):**
    *   The size of the discrete alphabet is `2ⁿ`, where `n` is the number of bits.
        离散字母表的大小是 `2ⁿ`，其中 `n` 是比特数。
    *   **Example:** For 3 bits, the alphabet size is 2³ = 8 symbols {000, 001, ..., 111}.
        **示例:** 对于3个比特，字母表大小为 2³ = 8 个符号 {000, 001, ..., 111}。

---

### **Part 3: Communication Channels & Impairments**

#### **3.1 Types of Communication Channels**

*   **Guided Channels (导向信道):** The signal is guided along a physical path.
    信号沿着物理路径被引导。
    *   **Examples:** Twisted Wire Pair, Coaxial Cable, **Optical Fiber**.
        **示例:** 双绞线、同轴电缆、**光纤**。
*   **Unguided Channels (非导向信道):** The signal propagates freely without a physical path.
    信号在没有物理路径的情况下自由传播。
    *   **Examples:** Wireless Broadcast, Mobile Radio, Satellite.
        **示例:** 无线广播、移动无线电、卫星。

#### **3.2 Specific Channel Examples**

*   **Telephone Channel:** A bandpass channel with a bandwidth of **300 Hz to 3400 Hz**.
    **电话信道:** 一个带宽为 **300 Hz 到 3400 Hz** 的带通信道。
*   **Wireless Propagation Types:**
    *   **Ground Propagation (地波传播):** Below 2 MHz.
    *   **Sky Propagation (天波传播):** Bounced off the ionosphere.
    *   **Line-of-Sight Propagation (视线传播):** Above 30 MHz.

#### **3.3 Channel Impairments (信道损伤)**

The three primary causes of signal degradation in a channel are:
信道中信号降级的三个主要原因是：

1.  **Attenuation (衰减):**
    *   **Definition:** The loss of signal energy as it travels through the medium.
        **定义:** 信号在介质中传播时的能量损失。
    *   **Solution:** **Amplifiers** are used to boost the signal's energy.
        **解决方案:** 使用**放大器**来增强信号能量。

2.  **Distortion (失真):**
    *   **Definition:** The signal changes its original shape or form.
        **定义:** 信号改变了其原始的形状或形态。
    *   **Cause:** Different frequency components of a composite signal travel at different speeds.
        **原因:** 复合信号的不同频率分量以不同的速度传播。

3.  **Noise (噪声):**
    *   **Definition:** Random, unpredictable electrical signals that get superimposed onto the desired signal.
        **定义:** 叠加在期望信号上的随机、不可预测的电信号。
    *   **Types of Noise:** Thermal, Induced, Crosstalk, and Impulse noise.
        **噪声类型:** 热噪声、感应噪声、串扰和脉冲噪声。

#### **3.4 Measuring Impairments**

*   **Decibel (dB) (分贝):**
    *   **Purpose:** A logarithmic unit used to measure the ratio of two power levels, such as gain or loss.
        **用途:** 一种对数单位，用于衡量两个功率水平的比率，如增益或损耗。
    *   **Formula:** `dB = 10 log10(P₂ / P₁)`
    *   💡 **Exam Tip:** A loss of **3 dB (-3 dB)** is equivalent to losing **half the signal power**.
        **考试重点:** **3 dB (-3 dB)** 的损耗等同于损失**一半的信号功率**。
    *   **Key Advantage:** For a system with multiple stages, you can simply **add the dB gains and subtract the dB losses**.
        **核心优势:** 对于多级系统，你只需将**dB增益相加，并将dB损耗相减**。

*   **Signal-to-Noise Ratio (SNR) (信噪比):**
    *   **Definition:** The ratio of the average signal power to the average noise power; it measures signal quality.
        **定义:** 平均信号功率与平均噪声功率之比；它衡量信号的质量。
    *   **Formula (Ratio):** `SNR = Signal Power / Noise Power`
    *   **Formula (in dB):** `SNR_dB = 10 log10(SNR)`

---

### **Part 4: System Classification & Advanced Concepts**

#### **4.1 Classification by Direction of Communication**

*   **Simplex (单工):** Communication is unidirectional (one-way only). Example: TV broadcast.
    通信是单向的。示例：电视广播。
*   **Half-Duplex (半双工):** Communication is bidirectional, but not simultaneous. Example: Walkie-talkies.
    通信是双向的，但不是同时的。示例：对讲机。
*   **Full-Duplex (全双工):** Communication is bidirectional and simultaneous. Example: Telephone.
    通信是双向且同时的。示例：电话。

#### **4.2 Signaling and Modulation**

*   **Signaling (信令):** The general term for transforming data before it is transmitted.
    在数据传输前对其进行转换的通用术语。
*   **Modulation (调制):** The specific process of converting a signal into a form suitable for the transmission medium.
    将信号转换为适合传输介质的形式的具体过程。

#### **4.3 Advanced System Concepts**

*   **Receiver Components (接收器组件):**
    *   A receiver contains **amplifiers, oscillators, mixers, tuned circuits, filters, and a demodulator/detector**.
        接收器包含**放大器、振荡器、混频器、调谐电路、滤波器和一个解调器/检测器**。
*   **Digital Signals as Composite Analog Signals (数字信号作为复合模拟信号):**
    *   A digital signal with its sudden changes is fundamentally a **composite analog signal** with a very large (theoretically infinite) bandwidth.
        一个具有突变特性的数字信号，本质上是一个具有非常大（理论上无限）带宽的**复合模拟信号**。