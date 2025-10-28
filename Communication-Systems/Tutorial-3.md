### **Multiple Choice Questions (选择题)**

1.  **In analogue-to-analogue conversion, why is modulation necessary for transmitting signals like audio frequencies?**
    *   **在模拟-模拟转换中，为什么传输像音频这样的信号时必须进行调制？**
    *   **Answer (答案):** **A) To prevent signal mixing** and **C) To adjust antenna height for efficient radiation**. Both are key reasons discussed in the lecture. Low-frequency signals would mix if transmitted together in the same band, and they require impractically large antennas.
    *   **A) 防止信号混合** 和 **C) 为实现高效辐射而调整天线高度**。两者都是讲座中讨论的关键原因。低频信号如果在同一频段内一起传输会发生混合，并且它们需要不切实际的巨大天线。

2.  **Which of the following types of mechanism allows for the accommodation of multiple users on the same communication link?**
    *   **以下哪种机制允许在同一通信链路上容纳多个用户？**
    *   **Answer (答案):** **C) Multiplexing**. This is the specific technique for combining multiple signals onto a single channel.
    *   **C) 多路复用**。这是将多个信号组合到单一信道上的专门技术。

3.  **In amplitude modulation (AM), what primarily defines the envelope of the AM waveform?**
    *   **在幅度调制(AM)中，主要是什么定义了AM波形的包络？**
    *   **Answer (答案):** **B) The amplitude of the modulating signal**. The message/modulating signal's amplitude shape forms the envelope of the high-frequency carrier.
    *   **B) 调制信号的幅度**。消息/调制信号的幅度形状构成了高频载波的包络。

4.  **Which of the following is NOT an advantage of modulation in communication systems?**
    *   **以下哪项不是调制在通信系统中的优点？**
    *   **Answer (答案):** **C) Reduced need for bandwidth**. Modulation, especially angle modulation like FM, often *increases* the need for bandwidth compared to the original baseband signal.
    *   **C) 减少了对带宽的需求**。调制，特别是像FM这样的角度调制，通常会比原始基带信号*增加*带宽需求。

5.  **In Frequency Modulation (FM), what aspect of the carrier signal is modified in response to the amplitude of the modulating signal?**
    *   **在频率调制(FM)中，载波信号的哪个方面会响应调制信号的幅度而改变？**
    *   **Answer (答案):** **B) Carrier frequency**. In FM, the instantaneous frequency of the carrier deviates from its center frequency in proportion to the modulating signal's amplitude.
    *   **B) 载波频率**。在FM中，载波的瞬时频率会根据调制信号的幅度偏离其中心频率。

6.  **What is the relationship between the bandwidth of an AM signal and the modulating signal?**
    *   **AM信号的带宽和调制信号的带宽之间有什么关系？**
    *   **Answer (答案):** **B) AM bandwidth is double the bandwidth of the modulating signal.** (BW_AM = 2 * BW_modulating).
    *   **B) AM带宽是调制信号带宽的两倍。** (BW_AM = 2 * BW_调制)。

7.  **In a simple AM demodulation circuit, which component is primarily responsible for recovering the modulating signal from the carrier?**
    *   **在一个简单的AM解调电路（包络检波器）中，哪个元件主要负责从载波中恢复调制信号？**
    *   **Answer (答案):** **C) Diode**. The diode rectifies the signal, allowing only the positive (or negative) half to pass, which is the first step in tracing the envelope.
    *   **C) 二极管**。二极管对信号进行整流，只允许正（或负）半周通过，这是追踪包络的第一步。

8.  **What is the primary drawback of amplitude modulation (AM) compared to other modulation techniques like FM or PM?**
    *   **与FM或PM等其他调制技术相比，幅度调制(AM)的主要缺点是什么？**
    *   **Answer (答案):** **B) AM is highly susceptible to noise**. Noise is often additive and directly affects the amplitude of the signal, which is where the information is stored in AM.
    *   **B) AM极易受噪声干扰**。噪声通常是加性的，会直接影响信号的幅度，而AM的信息正是存储在幅度中。

9.  **In Frequency Shift Keying (FSK), what remains constant while the frequency is varied to represent the digital data?**
    *   **在频移键控(FSK)中，当频率被改变以代表数字数据时，什么保持不变？**
    *   **Answer (答案):** **C) Amplitude**. In FSK, both amplitude and phase typically remain constant for each frequency tone.
    *   **C) 幅度**。在FSK中，每个频率音调的幅度和相位通常保持不变。

10. **Which of the following digital modulation schemes combines both amplitude and phase modulation to achieve higher efficiency?**
    *   **以下哪种数字调制方案结合了幅度和相位调制以实现更高效率？**
    *   **Answer (答案):** **C) Quadrature Amplitude Modulation (QAM)**. QAM varies both amplitude and phase to create its constellation points, allowing more bits per symbol.
    *   **C) 正交幅度调制 (QAM)**。QAM通过改变幅度和相位来创建其星座点，从而允许每个符号携带更多比特。

11. **The Shannon Capacity theorem suggests that the maximum rate of data transfer for error-free communication is influenced by which two factors?**
    *   **香农容量定理指出，无差错通信的最大数据传输速率受哪两个因素影响？**
    *   **Answer (答案):** **B) Bandwidth and noise levels**. The formula is C = B * log₂(1 + SNR), where B is bandwidth and SNR is the signal-to-noise ratio.
    *   **B) 带宽和噪声水平**。其公式为 C = B * log₂(1 + SNR)，其中B是带宽，SNR是信噪比。

12. **In Binary Phase Shift Keying (BPSK), how many signal elements are used, and how are they differentiated?**
    *   **在二进制相移键控(BPSK)中，使用了多少个信号元素，它们是如何区分的？**
    *   **Answer (答案):** **C) Two signal elements, differentiated by phase**. For example, 0° for a '1' and 180° for a '0'.
    *   **C) 两个信号元素，通过相位区分**。例如，用0°代表'1'，用180°代表'0'。

13. **In an FM signal, what happens to the bandwidth as the modulation index (β) increases?**
    *   **在一个FM信号中，当调制指数(β)增加时，带宽会发生什么变化？**
    *   **Answer (答案):** **C) The bandwidth increases**. According to Carson's Rule (BW ≈ 2(β+1)B), as β increases, the total bandwidth increases.
    *   **C) 带宽增加**。根据卡森法则 (BW ≈ 2(β+1)B)，当β增加时，总带宽也会增加。

14. **Which of the following correctly describes the concept of symbol rate in digital modulation?**
    *   **以下哪项正确描述了数字调制中符号率的概念？**
    *   **Answer (答案):** **C) It is the number of signal elements transmitted per second**. Symbol rate (or baud rate) is the rate at which symbols are changed.
    *   **C) 它是每秒传输的信号元素的数量**。符号率（或波特率）是符号变化的速率。

15. **What modulation technique is typically used to transmit digital data over optical fibre?**
    *   **哪种调制技术通常用于通过光纤传输数字数据？**
    *   **Answer (答案):** **D) On-Off Keying (OOK)**. This is a form of ASK where the presence of light represents a '1' and the absence of light represents a '0'. It is simple and effective for fiber optics.
    *   **D) 通断键控 (OOK)**。这是一种ASK的形式，其中光的存在代表'1'，光的缺失代表'0'。它对光纤来说既简单又有效。

---

### **Understanding (第一组理解题)**

1.  **Distinguish between baseband transmission and broadband transmission.**
    *   **区分基带传输和宽带传输。**
    *   **Answer:** **Baseband transmission** sends a digital or analog signal directly over a channel in its original frequency range without modulation to a higher frequency. **Broadband transmission** uses modulation to shift the signal to a higher carrier frequency, allowing multiple signals to be transmitted simultaneously using FDM.
    *   **答：****基带传输**是将数字或模拟信号在其原始频段内直接通过信道发送，不经过调制到更高频率。**宽带传输**则使用调制将信号移至一个更高的载波频率，从而允许使用FDM技术同时传输多个信号。

2.  **We send a voice signal from a microphone to a recorder. Is this baseband or broadband transmission?**
    *   **我们把一个声音信号从麦克风发送到录音机。这是基带传输还是宽带传输？**
    *   **Answer:** **Baseband**. The electrical signal from the microphone, which corresponds directly to the voice frequencies, is sent over the wire to the recorder without being modulated to a higher carrier frequency.
    *   **答：****基带**。来自麦克风的电信号直接对应于语音频率，它通过电线被发送到录音机，没有被调制到更高的载波频率上。

3.  **Can we say if a signal is periodic or nonperiodic by just looking at its frequency-domain plot? How?**
    *   **我们能仅通过观察信号的频域图来判断它是周期信号还是非周期信号吗？如何判断？**
    *   **Answer:** **Yes**. A **periodic** signal has a discrete frequency-domain plot (a series of spikes at integer multiples of the fundamental frequency). A **nonperiodic** signal has a continuous frequency-domain plot.
    *   **答：****可以**。一个**周期**信号的频域图是离散的（在基频的整数倍处出现一系列尖峰）。一个**非周期**信号的频域图是连续的。

4.  **Which of the following defines the theoretical maximum bit rate of a noiseless channel?**
    *   **以下哪项定义了无噪声信道的理论最大比特率？**
    *   **Answer:** **Nyquist theorem**. (C = 2 * B * log₂L). Shannon Capacity defines the limit for a channel *with* noise.
    *   **答：****奈奎斯特准则**。（C = 2 * B * log₂L）。香农容量定义的是*有*噪声信道的极限。

5.  **Distinguish between a signal element and a data element.**
    *   **区分信号元素和数据元素。**
    *   **Answer:** A **data element** is the smallest piece of information to be sent (e.g., a bit). A **signal element** (or symbol) is the physical representation of data elements in the signal for a fixed period. One signal element can carry one or more data elements.
    *   **答：****数据元素**是要发送的最小信息单元（例如一个比特）。**信号元素**（或符号）是数据元素在信号中持续固定时间的物理表现形式。一个信号元素可以承载一个或多个数据元素。

6.  **Which of the four digital-to-analogue conversion techniques (ASK, FSK, PSK, or QAM) is the most susceptible to noise?**
    *   **四种数模转换技术（ASK, FSK, PSK, 或 QAM）中，哪一种最容易受到噪声的干扰？**
    *   **Answer:** **ASK (Amplitude Shift Keying)**. Because noise primarily affects the amplitude of a signal, ASK is the most vulnerable as its information is encoded solely in the amplitude.
    *   **答：****ASK（幅移键控）**。因为噪声主要影响信号的幅度，所以ASK最脆弱，因为它的信息完全编码在幅度中。

7.  **What is the difference between AM (Amplitude Modulation) and FM (Frequency Modulation)?**
    *   **AM（幅度调制）和FM（频率调制）有什么区别？**
    *   **Answer:** In **AM**, the amplitude of the carrier wave is varied in accordance with the modulating signal, while its frequency remains constant. In **FM**, the frequency of the carrier is varied, while its amplitude remains constant.
    *   **答：**在**AM**中，载波的幅度随调制信号而变化，而其频率保持不变。在**FM**中，载波的频率随调制信号而变化，而其幅度保持不变。

8.  **What is the difference between Analogue and Digital Modulation? Use AM and ASK as an example.**
    *   **模拟调制和数字调制有什么区别？用AM和ASK作为例子来解释。**
    *   **Answer:** **Analogue modulation** uses a continuous analogue signal to modify the carrier (e.g., in **AM**, a continuous voice signal smoothly varies the carrier's amplitude). **Digital modulation** uses a discrete digital signal (bits) to modify the carrier (e.g., in **ASK**, the carrier's amplitude switches between distinct, predefined levels to represent 0s and 1s).
    *   **答：****模拟调制**使用一个连续的模拟信号来修改载波（例如，在**AM**中，一个连续的声音信号平滑地改变载波的幅度）。**数字调制**使用一个离散的数字信号（比特）来修改载波（例如，在**ASK**中，载波的幅度在预定义的、不连续的电平之间切换，以代表0和1）。

9.  **Which characteristic is changed to represent the digital data in ASK, FSK, and PSK?**
    *   **在ASK、FSK和PSK中，改变了哪个特性来代表数字数据？**
    *   **Answer:**
        *   **ASK:** Amplitude (幅度)
        *   **FSK:** Frequency (频率)
        *   **PSK:** Phase (相位)

10. **Which characteristic is changed to represent the analogue signal in AM, PM, and FM?**
    *   **在AM、PM和FM中，改变了哪个特性来代表模拟信号？**
    *   **Answer:**
        *   **AM:** Amplitude (幅度)
        *   **PM:** Phase (相位)
        *   **FM:** Frequency (频率)

---

### **Understanding (第二组理解与计算题)**

1.  **What is the bandwidth of a signal composed of sine waves with frequencies 0, 20, 50, 100, and 200 Hz? Draw the bandwidth.**
    *   **一个由频率为0, 20, 50, 100, 和 200 Hz的正弦波组成的信号，其带宽是多少？画出带宽。**
    *   **Answer:** The bandwidth is the range from the lowest to the highest frequency. `Bandwidth = f_max - f_min = 200 Hz - 0 Hz = 200 Hz`.
    *   **答：**带宽是最高频率与最低频率之差。`带宽 = f_max - f_min = 200 Hz - 0 Hz = 200 Hz`。
    *   **Drawing (图示):**
        ```
        Amplitude
          ^
          | x     x     x     x     x
          |
          +---|-----|-----|-----|-----|---> Frequency (Hz)
          0   20    50   100   200
          <--------------------------->
                 Bandwidth = 200 Hz
        ```

2.  **Give the bit rate for each of the following signals.**
    *   **计算下列信号的比特率。**
    *   **Answer (答):**
        *   a. 1 bit lasts 0.001 s: `Bit Rate = 1 bit / 0.001 s = 1000 bps = 1 kbps`
        *   b. 1 bit lasts 2 ms: `Bit Rate = 1 bit / (2 * 10⁻³ s) = 500 bps`
        *   c. 10 bits last 20 μs: `Bit Rate = 10 bits / (20 * 10⁻⁶ s) = 500,000 bps = 500 kbps`

3.  **A device is sending out data at 1000 bps.**
    *   **一个设备以1000 bps的速率发送数据。**
    *   **Answer (答):**
        *   a. How long to send 10 bits? `Time = 10 bits / 1000 bps = 0.01 s`
        *   b. How long to send a single character (8 bits)? `Time = 8 bits / 1000 bps = 0.008 s`
        *   c. How long to send a file of 100,000 characters? `Total bits = 100,000 * 8 = 800,000 bits`. `Time = 800,000 bits / 1000 bps = 800 s`

4.  **A line has a signal-to-noise ratio of 1000 and a bandwidth of 4000 kHz. What is the maximum data rate?**
    *   **一条线路的信噪比为1000，带宽为4000 kHz。其支持的最大数据速率是多少？**
    *   **Answer:** Use Shannon's Capacity formula: `C = B * log₂(1 + SNR)`.
        *   `B = 4000 kHz = 4,000,000 Hz`
        *   `SNR = 1000`
        *   `C = 4,000,000 * log₂(1 + 1000) = 4,000,000 * log₂(1001)`
        *   `log₂(1001) ≈ 9.967`
        *   `C ≈ 4,000,000 * 9.967 ≈ 39,868,000 bps ≈ 39.87 Mbps`
    *   **答：**使用香农容量公式：`C = B * log₂(1 + SNR)`。
        *   `C ≈ 39.87 Mbps`。

5.  **A signal with 200-mW power passes through 10 devices, each with an average noise of 2 μW. What is the SNR? What is the SNRdB?**
    *   **一个功率为200毫瓦的信号通过10个设备，每个设备产生2微瓦的平均噪声。SNR是多少？SNRdB是多少？**
    *   **Answer:**
        *   `Signal Power = 200 mW = 0.2 W`
        *   `Total Noise Power = 10 devices * 2 μW/device = 20 μW = 20 * 10⁻⁶ W`
        *   **`SNR = Signal Power / Noise Power = 0.2 / (20 * 10⁻⁶) = 10,000`**
        *   **`SNRdB = 10 * log₁₀(SNR) = 10 * log₁₀(10000) = 10 * 4 = 40 dB`**
    *   **答：**SNR为**10,000**。SNRdB为**40 dB**。

6.  **We need to upgrade a channel to a higher bandwidth.**
    *   **我们需要升级一个信道以获得更高带宽。**
    *   **Answer (答):**
        *   a. How is the rate improved if we double the bandwidth? According to Shannon's formula, the capacity (rate) is directly proportional to bandwidth. **Doubling the bandwidth will approximately double the rate.**
        *   a. 如果我们将带宽加倍，速率会如何提升？根据香农公式，容量（速率）与带宽成正比。**将带宽加倍会使速率大约也加倍。**
        *   b. How is the rate improved if we double the SNR? The capacity is proportional to `log₂(1 + SNR)`. It does not double. The improvement is additive, not multiplicative. For a large initial SNR, doubling it has a small effect. For a small initial SNR, the effect is larger but still not double.
        *   b. 如果我们将信噪比加倍，速率会如何提升？容量与`log₂(1 + SNR)`成正比。速率不会加倍。这种提升是加性的，而不是乘性的。对于一个原本就很大的SNR，将其加倍影响很小。对于一个较小的SNR，影响会大一些，但仍然不会加倍。

7.  **Assume a voice channel occupies 4 kHz. We need to multiplex 10 voice channels with guard bands of 500 Hz using FDM. Calculate the required bandwidth.**
    *   **假设一个语音信道占用4kHz。我们需要用FDM复用10个这样的语音信道，并设置500Hz的保护带。计算所需的总带宽。**
    *   **Answer:** We need 10 channels and 9 guard bands between them.
        *   `Total Bandwidth = (10 * Channel Bandwidth) + (9 * Guard Band)`
        *   `Total Bandwidth = (10 * 4000 Hz) + (9 * 500 Hz)`
        *   `Total Bandwidth = 40,000 Hz + 4,500 Hz = 44,500 Hz = 44.5 kHz`
    *   **答：**我们需要10个信道和它们之间的9个保护带。总带宽为**44.5 kHz**。

8.  **Which signal has a wider bandwidth, a sine wave with a frequency of 100 Hz or a sine wave with a frequency of 200 Hz?**
    *   **一个100Hz的正弦波和一个200Hz的正弦波，哪个信号的带宽更宽？**
    *   **Answer:** **Neither**. A pure sine wave is a single frequency. Theoretically, it has a bandwidth of 0 Hz.
    *   **答：****都不是**。一个纯正弦波只包含单一频率。理论上，它的带宽为0赫兹。

9.  **When implementing Amplitude Modulation, what is the modulated signal's bandwidth of a 4 kHz speech signal if transmitted on a carrier of 30 kHz?**
    *   **在实现幅度调制时，如果一个4kHz的语音信号被一个30kHz的载波调制，那么调制后信号的带宽是多少？**
    *   **Answer:** The bandwidth of an AM signal is twice the bandwidth of the modulating signal, regardless of the carrier frequency.
        *   `Bandwidth = 2 * 4 kHz = 8 kHz`
    *   **答：**AM信号的带宽是调制信号带宽的两倍，与载波频率无关。带宽为**8 kHz**。

10. **Draw the constellation diagram for the following:**
    *   **为下列情况画出星座图：**
    *   **Answer (答):**
        *   a. **BASK, two symbols having peak amplitude values of 1 and 3:**
            ```
                ^ Y (Quadrature)
                |
                |
            ----+---.-------.-----> X (In-phase)
                0   1       3
            ```
        *   b. **BPSK, two symbols having a peak amplitude value of 2 but 180 degrees difference between their phases:**
            ```
                ^ Y (Quadrature)
                |
                .
            ----+-------------.-----> X (In-phase)
               -2             2
                .
                |
            ```

11. **Calculate the symbol rate / baud rate for the given bit rate and type of modulation.**
    *   **根据给定的比特率和调制类型，计算符号率/波特率。**
    *   **Answer (答):**
        *   a. 2000 bps, BFSK: Binary FSK (BFSK) uses 2 symbols, so each symbol carries `log₂(2) = 1` bit. `Baud Rate = Bit Rate / 1 = 2000 baud`.
        *   b. 4000 bps, BASK: Binary ASK (BASK) also has `r=1`. `Baud Rate = 4000 / 1 = 4000 baud`.

12. **An audio signal having a frequency of 20 KHz is directly transmitted without modulation. What is the length of the antenna? (propagation speed is 3×10⁸ m/s)**
    *   **一个频率为20KHz的音频信号未经调制直接发射。天线的长度是多少？（传播速度为 3×10⁸ m/s）**
    *   **Answer:**
        *   First, calculate the wavelength (λ): `λ = c / f = (3 * 10⁸ m/s) / (20 * 10³ Hz) = 15,000 meters`.
        *   Antenna length is typically half the wavelength (λ/2).
        *   `Antenna Length = 15,000 m / 2 = 7,500 meters = 7.5 km`.
    *   **答：**首先计算波长 (λ) 为15,000米。天线长度通常是波长的一半。天线长度为**7,500米**或**7.5公里**。