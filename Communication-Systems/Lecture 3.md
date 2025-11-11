### **Fundamentals of Communication Systems - Lecture 3**
---

### **Part 1: Multiplexing (第一部分: 多路复用)**

#### **1. Multiplexing Definition (多路复用定义)**
*   **Multiplexing** is the process of simultaneously transmitting two or more individual signals over a single communication channel, cable or wireless. In effect, it increases the number of communication channels so that more information can be transmitted.
    *   **多路复用**是通过单一通信信道（电缆或无线）同时传输两个或多个独立信号的过程。实际上，它增加了通信信道的数量，从而可以传输更多的信息。
*   **Greatest Use:** The greatest use of multiplexing is in the telephone system, where millions of calls are multiplexed on cables, long-distance fiber-optic lines, satellites, and wireless paths.
    *   **主要应用:** 多路复用最广泛的应用是在电话系统中，数以百万计的通话被复用到电缆、长途光纤线路、卫星和无线路径上。
*   **Benefit:** Multiplexing increases the telephone carrier's ability to handle more calls while minimizing system costs and spectrum usage.
    *   **优点:** 多路复用提高了电话运营商处理更多通话的能力，同时最大限度地降低了系统成本和频谱使用。

#### **2. Dividing a Link into Channels (将链路划分为信道)**
*   **Multiplexer (MUX or MPX):** Combines all input signals into a single signal.
    *   **多路复用器 (MUX or MPX):** 将所有输入信号合并成一个单一信号。
*   **Demultiplexer (DEMUX):** Processes the combined input signal by sorting it out into the original individual signals.
    *   **解复用器 (DEMUX):** 处理合并后的输入信号，将其分离还原为原始的各个独立信号。

#### **3. Common Types of Multiplexing (常见的多路复用类型)**
*   The two most common types are **frequency-division multiplexing (FDM)** and **time-division multiplexing (TDM)**.
    *   两种最常见的类型是**频分多路复用 (FDM)** 和 **时分多路复用 (TDM)**。

*   **Frequency-Division Multiplexing (FDM) / 频分多路复用**
    *   An **analog technique**.
        *   一种**模拟**技术。
    *   Can be applied when the bandwidth of a link is greater than the combined bandwidth of the signals to be transmitted together.
        *   适用于链路带宽大于待传输信号总带宽的场景。
    *   **Process:** Original data modulates carriers of different frequencies. All carriers are combined into a single composite signal.
        *   **过程:** 原始数据调制不同频率的载波。所有载波被合并成一个复合信号。
    *   **Demultiplexing:** Bandpass filters select out individual channels, and demodulators recover the original signals.
        *   **解复用:** 带通滤波器选出单个信道，然后由解调器恢复原始信号。

*   **Time-Division Multiplexing (TDM) / 时分多路复用**
    *   A **digital technique** that allows several connections to share the high bandwidth of a link.
        *   一种允许多个连接共享链路高带宽的**数字**技术。
    *   **Process:** It provides equal time slots for each signal within a structure called a "frame". The MUX interleaves data from different signals into the data flow.
        *   **过程:** 它在一个称为“帧”的结构中为每个信号提供相等的时间片。复用器将来自不同信号的数据交错插入数据流中。

*   **Space-Division Multiplexing (SDM) / 空分多路复用**
    *   Allocates the same frequency band or all the available bandwidth to more than one user for all time, but user signals are confined to physically separate regions or zones (e.g., cells in a mobile network).
        *   将相同的频段或所有可用带宽永久分配给多个用户，但用户的信号被限制在物理上分离的区域或地带（例如，移动网络中的蜂窝小区）。

*   **Code-Division Multiplexing (CDM) / 码分多路复用**
    *   A sharing strategy where multiple users transmit in the same frequency band at the same time and in the same physical medium.
        *   一种共享策略，多个用户在同一时间、同一频段、同一物理介质中进行传输。
    *   **Secret:** Each user is assigned a unique pseudo-random code sequence with which their signal is spread over a wide bandwidth, giving it a noise-like appearance.
        *   **核心:** 每个用户都被分配一个独特的伪随机码序列，用它将信号扩展到一个很宽的带宽上，使其看起来像噪声。

### **Part 2: Modulation (第二部分: 调制)**

#### **1. Why Modulate? (为何需要调制?)**
*   To transmit information, it must be converted into an analogue or digital signal.
    *   为了传输信息，必须将其转换为模拟或数字信号。

*   **Problem 1: Antenna Height (天线高度)**
    *   For efficient radiation, antenna height must be comparable to the signal's wavelength (λ).
        *   为了高效辐射，天线高度必须与信号波长 (λ) 相当。
    *   Wavelength λ = C/f (Speed of Light / frequency).
    *   **Example (示例):** To transmit an audio frequency of `f = 20 KHz`:
        *   `λ = c/f = (3 x 10⁸ m/s) / (2 x 10⁴ Hz) = 1.5 x 10⁴ meters` (15 km).
        *   Required antenna height would be ~1500m, which is **practically impossible**.
        *   要传输一个频率为 `f = 20 KHz` 的音频信号：
        *   波长 `λ = c/f = (3 x 10⁸ 米/秒) / (2 x 10⁴ 赫兹) = 1.5 x 10⁴ 米` (15公里)。
        *   所需天线高度约为1500米，这在**实践中是不可能的**。
*   **Problem 2: Mixing of Signals (信号混合)**
    *   If signals are transmitted directly in the audio range (20 Hz to 20 kHz), signals from different sources would mix up, making it impossible to recover the desired signal at the receiver.
        *   如果信号直接在音频范围（20赫兹到20千赫）内传输，来自不同源的信号会混合在一起，导致接收端无法恢复所需的信号。
*   **Problem 3: Poor Radiation (辐射效率差)**
    *   The distance a signal can travel is proportional to its frequency. Audio frequency signals (20 Hz-20 kHz) can hardly travel more than a few meters on their own.
        *   信号可以传播的距离与其频率成正比。音频信号（20赫兹-20千赫）自身几乎无法传播超过几米。

#### **2. Advantages of Modulation (调制的优点)**
*   Accommodate multiple users on the same communication link.
    *   在同一通信链路上容纳多个用户。
*   Achieve efficient radiation in radio systems.
    *   在无线电系统中实现高效辐射。
*   Exploit the larger bandwidths available at higher radio frequencies.
    *   利用更高射频下可用的大带宽。
*   Use a frequency band best suited to the transmission medium.
    *   使用最适合传输介质的频段。

---

### **Part 3: Analogue Modulation (第三部分: 模拟调制)**

*   **Definition:** Analogue modulation is the representation of analogue information by an analogue signal.
    *   **定义:** 模拟调制是用一个模拟信号来表示模拟信息。
*   **Process:** A characteristic of a high-frequency **carrier signal**, `c(t) = Vc cos(2πfct + φ)`, is varied by a **message signal**, `m(t)`.
    *   **过程:** 高频**载波信号** `c(t) = Vc cos(2πfct + φ)` 的某个特性被**消息信号** `m(t)` 所改变。
*   A carrier signal c(t) = Vc cos(2πfct + φ) has three parameters that can be varied:
    *   一个载波信号 c(t) = Vc cos(2πfct + φ) 有三个可以改变的参数：
    1.  **Amplitude (振幅) Vc** → Amplitude Modulation (AM)
    2.  **Frequency (频率) fc** → Frequency Modulation (FM)
    3.  **Phase (相位) φ** → Phase Modulation (PM)

#### **1. Amplitude Modulation (AM) / 幅度调制**
*   The **amplitude** of the carrier is varied.
    *   载波的**幅度**被改变。
*   **Waveform:** The envelope of the AM waveform is defined by the message signal. `am(t) = [Vc + vm(t)] cos(2πfct)`. The peak value of the carrier amplitude is constant, but the peak value of the total AM signal is not.
    *   **波形:** AM波形的包络由消息信号定义。`am(t) = [Vc + vm(t)] cos(2πfct)`。载波的峰值幅度是恒定的，但整个AM信号的峰值是不恒定的。
*   **Spectrum:** An AM signal contains three frequency components:
    *   **频谱:** 一个AM信号包含三个频率分量：
    1.  Carrier frequency `fc` with amplitude `Vc`. (载波频率)
    2.  Lower Side Frequency (LSF) at `fc - fm` with amplitude `1/2 Vm`. (下边频)
    3.  Upper Side Frequency (USF) at `fc + fm` with amplitude `1/2 Vm`. (上边频)
*   **Bandwidth (带宽):** The bandwidth of an AM signal is equal to twice the bandwidth of the modulating signal. `BW_AM = 2 × BW_m`.
*   **AM Radio Standard:** The FCC allows 10 kHz for each AM station. Stations operate between 530 and 1700 kHz and must be separated by at least 10 kHz (guard band).
    *   **AM广播标准:** FCC为每个AM电台分配10kHz带宽。电台在530至1700kHz之间运营，且必须相隔至少10kHz（保护带）。
*   **Demodulation (解调):** The process of recovering the message signal. A simple **envelope detector** (or diode detector), consisting of a diode and an RC circuit, is commonly used.
    *   从已调制的载波中恢复消息信号的过程。通常使用一个简单的**包络检波器**（或二极管检波器），它由一个二极管和一个RC电路组成。
*   **Example (示例):** A 1 MHz carrier is modulated by a music signal from 20 Hz to 15 kHz.
    *   `fc = 1 MHz`, `f_m` ranges from `20 Hz` to `15 KHz`.
    *   **Frequencies in AM signal:**
        *   LSB Range: `(1 MHz - 15 KHz)` to `(1 MHz - 20 Hz)` = `985 KHz` to `999.98 KHz`.
        *   USB Range: `(1 MHz + 20 Hz)` to `(1 MHz + 15 KHz)` = `1000.02 KHz` to `1015 KHz`.
    *   **Transmission Bandwidth:** `BT = 2 × f_m(max) = 2 × 15 KHz = 30 KHz`.
    *   一个1MHz的载波被一个20Hz到15kHz的音乐信号调制。
    *   `fc = 1 MHz`，`f_m` 范围从 `20 Hz` 到 `15 KHz`。
    *   **AM信号中的频率：**
        *   下边带范围: 从 `(1 MHz - 15 KHz)` 到 `(1 MHz - 20 Hz)` = `985 KHz` 到 `999.98 KHz`。
        *   上边带范围: 从 `(1 MHz + 20 Hz)` 到 `(1 MHz + 15 KHz)` = `1000.02 KHz` 到 `1015 KHz`。
    *   **传输带宽:** `BT = 2 × f_m(max) = 2 × 15 KHz = 30 KHz`。

#### **2. Angle Modulation (Angle Modulation / 角度调制)**
*   Includes FM and PM.
    *   包括调频(FM)和调相(PM)。
*   **Advantages:** Noise reduction, improved system reliability, more efficient use of power.
    *   **优点:** 降低噪声，提高系统可靠性，更高效地利用功率。
*   **Disadvantages:** Increased bandwidth and use of more complex circuits.
    *   **缺点:** 增加了带宽需求和使用更复杂的电路。

*   **Frequency Modulation (FM) / 频率调制**
    *   The **frequency** of the carrier signal is modulated to follow the changing voltage level (amplitude) of the modulating signal.
        *   载波信号的**频率**被调制以跟随调制信号的电压电平（幅度）变化。
    *   The peak amplitude and phase of the carrier remain constant.
        *   载波的峰值幅度和相位保持不变。
    *   **Bandwidth (带宽):** The total bandwidth is several times that of the analogue signal. It can be estimated by Carson's Rule: `BW_FM = 2(β + 1)B`, where B is the message bandwidth and β is a modulation-dependent factor (a common value is 4).
        *   总带宽是模拟信号带宽的数倍。可用卡森法则估算：`BW_FM = 2(β + 1)B`，其中B是消息带宽，β是与调制相关的因子（一个常见值为4）。
    *   **FM Radio Standard:** The FCC allows 200 kHz (0.2 MHz) for each FM station, operating between 88 and 108 MHz. Stations must be separated by at least 200 kHz.
        *   **FM广播标准:** FCC为每个FM电台分配200kHz（0.2MHz）带宽，运营在88至108MHz之间。电台必须相隔至少200kHz。

*   **Phase Modulation (PM) / 相位调制**
    *   The **phase** of the carrier signal is modulated to follow the changing voltage level (amplitude) of the modulating signal.
        *   载波信号的**相位**被调制以跟随调制信号的电压电平（幅度）变化。
    *   The peak amplitude and frequency of the carrier remain constant.
        *   载波的峰值幅度和频率保持不变。
    *   **Relationship to FM:** PM can be considered a special case of FM where the carrier frequency modulation is given by the time derivative of the phase modulation.
        *   **与FM的关系:** PM可以看作是FM的一种特殊情况，其中载波频率的调制等于相位调制的时间导数。
    *   **Bandwidth (带宽):** Uses the same formula as FM, but the value of β is typically lower (around 1 for narrowband, 3 for wideband).
        *   使用与FM相同的公式，但β值通常较低（窄带约为1，宽带约为3）。

#### **3. Quiz Example from Slides (讲义中的测验示例)**
*   **Question:** Find the bandwidth to modulate a 5 KHz voice.
    *   **问题:** 调制一个5KHz的语音信号需要多少带宽？
*   **Solution (解答):**
    *   **a) AM:**
        *   `B_AM = 2 * 5 KHz = 10 KHz`
    *   **b) FM with β=5:**
        *   `B_FM = 2 * (5 + 1) * 5 KHz = 60 KHz`
    *   **c) PM with β=1:**
        *   `B_PM = 2 * (1 + 1) * 5 KHz = 20 KHz`

---

### **Part 4: Digital Modulation (第四部分: 数字调制)**

*   **Definition:** The process of encoding digital data into the amplitude, phase, or frequency of the carrier signal.
    *   **定义:** 将数字数据编码到载波信号的幅度、相位或频率中的过程。
*   **Data Element vs. Signal Element (数据元 vs. 信号元)**
    *   **Data element:** The smallest entity representing information (a bit, 0 or 1).
        *   **数据元:** 代表信息的最小实体（一个比特，0或1）。
    *   **Signal element (Symbol):** The smallest unit of a signal, which acts as a carrier for data elements. One symbol can carry one or more bits.
        *   **信号元 (符号):** 信号的最小单位，作为数据元的载体。一个符号可以承载一个或多个比特。
*   **Bit Rate vs. Baud Rate (比特率 vs. 波特率)**
    *   **Bit Rate (N):** The number of bits sent per second (bps).
        *   **比特率 (N):** 每秒发送的比特数 (bps)。
    *   **Baud Rate (S) / Symbol Rate:** The number of signal elements (symbols) sent per second (baud or symbols/sec).
        *   **波特率 (S) / 符号率:** 每秒发送的信号元素（符号）的数量（单位为波特或符号/秒）。
    *   **Relationship (关系):** `N = S × r`, where `r` is the number of bits per symbol (`r = log₂(L)`, L is the number of different signal elements).

#### **1. Digital Modulation Techniques (数字调制技术)**
*   **Amplitude-Shift Keying (ASK) / 幅移键控**
    *   The **amplitude** of the carrier signal is varied to create signal elements.
        *   载波信号的**幅度**被改变以创建信号元素。
    *   **Binary ASK (BASK) / On-Off Keying (OOK):** Uses two amplitude levels (e.g., carrier amplitude for '1', zero amplitude for '0').
        *   **二进制ASK (BASK) / 通断键控 (OOK):** 使用两个幅度级别（例如，用载波幅度代表'1'，零幅度代表'0'）。
    *   **Drawbacks:** Susceptible to sudden gain changes, inefficient.
        *   **缺点:** 易受增益突变影响，效率低下。

*   **Frequency-Shift Keying (FSK) / 频移键控**
    *   The **frequency** of the carrier signal is varied to represent data.
        *   载波信号的**频率**被改变以代表数据。
    *   **Binary FSK (BFSK):** Uses two carrier frequencies, `f₁` for '0' and `f₂` for '1'.
        *   **二进制FSK (BFSK):** 使用两个载波频率，`f₁` 代表 '0'，`f₂` 代表 '1'。
    *   **Properties:** Less susceptible to error than ASK. Can be used for full-duplex transmission.
        *   **特性:** 比ASK更不易出错。可用于全双工传输。

*   **Phase-Shift Keying (PSK) / 相移键控**
    *   The **phase** of the carrier is varied to create different signal elements. Peak amplitude and frequency remain constant.
        *   载波的**相位**被改变以创建不同的信号元素。峰值幅度和频率保持不变。
    *   **Binary PSK (BPSK):** Uses two phases (e.g., 0° and 180°).
        *   **二进制PSK (BPSK):** 使用两种相位（例如0°和180°）。
    *   **Quaternary PSK (QPSK):** An M-ary scheme where M=4. It uses four output phases, allowing two bits (a "dibit") to be encoded per symbol.
        *   **四进制PSK (QPSK):** 一种M=4的M进制方案。它使用四种输出相位，每个符号可以编码两个比特（一个“双比特”）。
    *   **Performance Comparison:** In terms of reliability against noise: **PSK > FSK > ASK**.
        *   **性能比较:** 在抗噪声可靠性方面：**PSK > FSK > ASK**。

*   **Quadrature Amplitude Modulation (QAM) / 正交幅度调制**
    *   A combination of **ASK and PSK**. Both the amplitude and phase of the carrier are changed. It is the most efficient of these options and is commonly used today.
        *   **ASK和PSK**的组合。载波的幅度和相位都被改变。这是这些选项中最高效的，也是当今普遍使用的方法。

*   **Constellation Diagram (星座图)**
    *   A representation of a digitally modulated signal. It displays the signal as a 2D scatter diagram.
        *   数字调制信号的一种表示方法。它将信号显示为一个二维散点图。
    *   The distance of a point from the origin represents the **amplitude**.
        *   点到原点的距离代表**幅度**。
    *   The angle of a point represents the **phase shift**.
        *   点的角度代表**相移**。

---

### **Part 5: Data Transmission Technologies (第五部分: 数据传输技术)**

#### **1. Modem (Modulator/Demodulator) / 调制解调器**
*   A device used to translate information from a source (computer, voice, etc.) into a format that can be transmitted over a line/cable or air (modulation) and to reverse the process at the destination (demodulation).
    *   一种用于将来自信源（计算机、语音等）的信息转换成可在线路/电缆或空气中传输的格式（调制），并在目的地反转该过程（解调）的设备。
*   **Applications:** Commonly used for long distances (Radio/TV, telephone communications) and sometimes short distances (Bluetooth, wireless LAN).
    *   **应用:** 通常用于长距离（广播/电视、电话通信），有时也用于短距离（蓝牙、无线局域网）。

#### **2. Access Technologies (接入技术)**
*   **Dial-up Modem (拨号调制解调器)**
    *   Used domestic telephone lines with a bandwidth of 3-4 kHz. For data, this was reduced to 2.4 kHz (600-3000 Hz).
        *   使用带宽为3-4kHz的家用电话线。对于数据传输，带宽被减至2.4kHz（600-3000赫兹）。
    *   **56K Modems:** Asymmetric, with an upload rate of 33.6 Kbps and a download rate of 56 Kbps.
        *   **56K调制解调器:** 非对称，上传速率为33.6Kbps，下载速率为56Kbps。

*   **High Speed Digital Access (高速数字接入)**
    *   Dominant technologies: **xDSL, Cable, Fiber**.
        *   主导技术: **xDSL, 有线电视网络, 光纤**。

    *   **DSL (Digital Subscriber Line) / 数字用户线路**
        *   Supports high-speed digital communication over existing telephone networks.
            *   在现有电话网络上支持高速数字通信。
        *   **ADSL (Asymmetric DSL):** Designed for residential users, provides higher bit rate downstream than upstream. Uses a splitter to separate voice and data signals.
            *   **ADSL (非对称DSL):** 为住宅用户设计，提供比上行更高的下行比特率。使用分离器来分离语音和数据信号。

    *   **Cable-based Access (基于有线电视网络的接入)**
        *   Uses the cable television company's existing infrastructure (coaxial cable).
            *   使用有线电视公司现有的基础设施（同轴电缆）。
        *   **HFC (Hybrid Fiber Coax):** A network architecture with fiber optic cables forming the backbone and coaxial cables connecting to individual homes. Homes share the access network.
            *   **HFC (混合光纤同轴电缆):** 一种网络架构，骨干网由光纤构成，同轴电缆连接到各个家庭。家庭共享接入网络。

    *   **Bandwidth Comparison (带宽比较):** (Slowest to Fastest) ADSL < VDSL < Fixed Wireless < Cable < Fiber.
        *   (从慢到快) ADSL < VDSL < 固定无线 < 有线电视网络 < 光纤。