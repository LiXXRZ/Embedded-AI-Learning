#### **第一部分: 简答与计算题 (Short Answer and Calculation Questions)**

##### **1. What is the relationship between symbol rate and bit rate?**
##### **1. 符号率和比特率之间有什么关系？**

*   **English Answer:**
    The relationship between bit rate (N) and symbol rate (S) is defined by the number of bits carried by each symbol (r). The formula is:
    **N = S × r**
    *   **Bit Rate (N):** The number of bits transmitted per second (unit: bps).
    *   **Symbol Rate (S):** Also known as Baud rate, it is the number of symbols (or signal elements) transmitted per second (unit: baud or symbols/sec).
    *   **Bits per Symbol (r):** The number of bits represented by a single symbol. This is determined by the number of different symbols (L) in the modulation scheme, where **r = log₂(L)**.

*   **中文解答:**
    比特率 (N) 和符号率 (S) 之间的关系由每个符号所承载的比特数 (r) 定义。其公式为：
    **N (比特率) = S (符号率) × r (每符号比特数)**
    *   **比特率 (N):** 每秒传输的比特数（单位：bps）。
    *   **符号率 (S):** 也称为波特率，是每秒传输的符号（或信号元素）的数量（单位：baud 或 符号/秒）。
    *   **每符号比特数 (r):** 单个符号所代表的比特数。它由调制方案中不同符号的总数 (L) 决定，其中 **r = log₂(L)**。

---

##### **2. Study the works of Shannon and Nyquist on channel capacity. How are the two related?**
##### **2. 研究香农和奈奎斯特关于信道容量的理论。两者有何关联？**

*   **English Answer:**
    Both Nyquist and Shannon provide upper limits on the data rate of a channel, but from different perspectives.

| 特性 (Feature) | **奈奎斯特定理 (Nyquist Theorem)** | **香农定理 (Shannon Theorem)** |
| :--- | :--- | :--- |
| **Channel Condition** | Assumes a **noiseless** channel. | Considers a realistic channel with **noise** (specifically, Additive White Gaussian Noise - AWGN). |
| **Limiting Factor** | **Bandwidth (B)** and the **number of signal levels (L)**. | **Bandwidth (B)** and the **Signal-to-Noise Ratio (S/N)**. |
| **Formula** | `C = 2 * B * log₂(L)` | `C = B * log₂(1 + S/N)` |
| **Meaning** | Defines the maximum symbol rate (`2B`) and how many bits can be carried per symbol. It answers: "Given a certain bandwidth, how fast can we send symbols, and how many bits can each symbol carry?" | Defines the **theoretical maximum error-free bit rate** possible, regardless of the number of signal levels used. It sets a fundamental limit imposed by noise. It answers: "Given noise and bandwidth, what is the ultimate speed limit of this channel?" |

    **Relationship:**
    Nyquist and Shannon's theorems are complementary. Nyquist's formula tells us that we can increase the bit rate by increasing the number of signal levels (L). However, Shannon's theorem sets a limit on this. In a noisy channel, increasing L makes the symbols closer together, making them more susceptible to noise. The Shannon capacity (C) is the ultimate limit that no amount of signal levels (L) or clever encoding can overcome for a given B and S/N. In practice, engineers use the Shannon capacity as a benchmark and then use the Nyquist formula to determine the required number of signal levels (L) to approach (but not exceed) that capacity.

*   **中文解答:**
    奈奎斯特和香农都为信道的最大数据率提供了上限，但他们基于不同的假设和方法。

| 特性 (Feature) | **奈奎斯特定理 (Nyquist Theorem)** | **香农定理 (Shannon Theorem)** |
| :--- | :--- | :--- |
| **信道条件** | 假设一个**无噪声**的理想信道。 | 考虑一个存在**噪声**的现实信道（特指加性高斯白噪声 - AWGN）。 |
| **限制因素** | **带宽 (B)** 和**信号电平数 (L)**。 | **带宽 (B)** 和**信噪比 (S/N)**。 |
| **公式** | `C = 2 * B * log₂(L)` | `C = B * log₂(1 + S/N)` |
| **含义** | 定义了最大符号率 (`2B`) 以及每个符号能携带多少比特。它回答：“在给定带宽下，我们能多快地发送符号，以及每个符号能代表多少信息？” | 定义了理论上可能达到的**最大无差错比特率**，无论使用多少信号电平。它设定了由噪声决定的根本物理极限。它回答：“在给定的噪声和带宽下，这个信道的终极速度极限是多少？” |

    **两者关系:**
    奈奎斯特和香农的理论是互补的。奈奎斯特定理告诉我们，可以通过增加信号电平数 (L) 来提高比特率。然而，香农定理为此设定了一个极限。在有噪声的信道中，增加 L 会使符号间的区分度降低，从而更容易受噪声干扰而出错。香农容量 (C) 是一个终极极限，对于给定的 B 和 S/N，无论 L 多大或编码多精巧，都无法超越。在实际工程中，工程师通常以香农容量为目标，然后运用奈奎斯特定理来计算需要多少信号电平 (L) 才能逼近（但不能超过）这个容量极限。

---

##### **3. How are binary values represented in amplitude shift keying, and what is the limitation of this approach?**
##### **3. 在幅移键控 (ASK) 中，二进制值是如何表示的？这种方法的局限性是什么？**

*   **English Answer:**
    *   **Representation:** In binary Amplitude Shift Keying (ASK), binary values ('0' and '1') are represented by two different amplitudes of the carrier signal. A common form is On-Off Keying (OOK), where one binary value (e.g., '1') is represented by the presence of the carrier signal at a specific amplitude, and the other value (e.g., '0') is represented by the absence of the carrier signal (zero amplitude).
    *   **Limitation:** The primary limitation of ASK is its **high susceptibility to noise**. Noise and interference typically manifest as changes in the signal's amplitude. Since ASK relies solely on amplitude levels to encode data, any unintended amplitude fluctuation can easily cause the receiver to misinterpret a '0' as a '1' or vice versa, leading to a high bit error rate (BER).

*   **中文解答:**
    *   **表示方法:** 在二进制幅移键控 (ASK) 中，二进制值（'0' 和 '1'）由载波信号的两种不同幅度来表示。一种常见的形式是开关键控 (OOK)，其中一个二进制值（例如 '1'）由特定幅度的载波信号存在来表示，而另一个值（例如 '0'）则由载波信号的缺失（零幅度）来表示。
    *   **局限性:** ASK 的主要局限性在于它**极易受到噪声的干扰**。噪声和干扰通常表现为信号幅度的变化。由于 ASK 完全依赖幅度电平来编码数据，任何非预期的幅度波动都很容易导致接收器将 '0' 误判为 '1'，或将 '1' 误判为 '0'，从而导致较高的比特误码率 (BER)。

---

##### **4. What is QAM?**
##### **4. 什么是 QAM？**

*   **English Answer:**
    QAM stands for **Quadrature Amplitude Modulation**. It is a highly bandwidth-efficient modulation scheme that combines aspects of both Amplitude Shift Keying (ASK) and Phase Shift Keying (PSK). It encodes data by varying both the **amplitude and the phase** of the carrier signal simultaneously. It uses two orthogonal carrier waves (a sine wave and a cosine wave), often called the **in-phase (I) component** and the **quadrature (Q) component**. By modulating the amplitudes of these two carriers independently, QAM can create a dense constellation of signal points, allowing multiple bits to be transmitted per symbol.

*   **中文解答:**
    QAM 是**正交幅度调制 (Quadrature Amplitude Modulation)** 的缩写。它是一种高带宽效率的调制方案，结合了幅移键控 (ASK) 和相移键控 (PSK) 的特点。它通过同时改变载波信号的**幅度和相位**来编码数据。QAM 使用两个相互正交的载波（一个正弦波和一个余弦波），通常被称为**同相 (I) 分量**和**正交 (Q) 分量**。通过独立地调制这两个载波的幅度，QAM 可以在星座图上产生密集的信号点，从而实现每个符号传输多个比特。

---

##### **5. What does the sampling theorem tell us concerning the rate of sampling required for an analogue signal?**
##### **5. 采样定理告诉我们对模拟信号进行采样所需的速率是多少？**

*   **English Answer:**
    The **Nyquist-Shannon sampling theorem** states that to perfectly reconstruct an analog signal from its samples without loss of information, the sampling rate (`f_s`) must be **at least twice the highest frequency component (`f_max`)** of the signal. This minimum sampling rate, `2 * f_max`, is called the Nyquist rate.
    **Formula: `f_s ≥ 2 * f_max`**
    If the sampling rate is lower than the Nyquist rate, a phenomenon called **aliasing** will occur, where high-frequency components in the original signal falsely appear as lower frequencies in the sampled signal, making accurate reconstruction impossible.

*   **中文解答:**
    **奈奎斯特-香农采样定理**指出，为了能从样本中无损地、完美地重建原始模拟信号，采样率 (`f_s`) 必须**至少是信号最高频率分量 (`f_max`) 的两倍**。这个最低采样率 `2 * f_max` 被称为奈奎斯特率。
    **公式: `f_s ≥ 2 * f_max`**
    如果采样率低于奈奎斯特率，就会发生一种称为**混叠 (aliasing)** 的现象，即原始信号中的高频分量在采样后的信号中被错误地表现为低频分量，导致无法准确重建原始信号。

---

##### **6. Consider a noiseless channel with a bandwidth of 125 KHz. Assume that QPSK is used. What is the theoretical maximum bit rate? What is the theoretical maximum symbol rate?**
##### **6. 考虑一个带宽为 125 KHz 的无噪声信道，使用 QPSK 调制。理论最大比特率是多少？理论最大符号率是多少？**

*   **English Answer:**
    *   **Maximum Symbol Rate:** For a noiseless channel, the maximum symbol rate is determined by the Nyquist theorem:
        `S_max = 2 * B = 2 * 125 KHz = 250,000 symbols/sec = 250 Kbaud`.
    *   **Maximum Bit Rate:** We use the Nyquist formula for capacity: `C = 2 * B * log₂(L)`.
        *   Modulation is **QPSK** (Quadrature Phase Shift Keying), which means there are 4 different signal states (phases). So, `L = 4`.
        *   Bits per symbol `r = log₂(L) = log₂(4) = 2`.
        *   `C = 2 * 125,000 Hz * log₂(4) = 250,000 * 2 = 500,000 bps = 500 Kbps`.
        *   Alternatively, using the symbol rate: `C = S_max * r = 250 Kbaud * 2 bits/symbol = 500 Kbps`.
    **Answer:** The theoretical maximum bit rate is **500 Kbps**, and the theoretical maximum symbol rate is **250 Kbaud**.

*   **中文解答:**
    *   **最大符号率:** 对于无噪声信道，最大符号率由奈奎斯特定理决定：
        `S_max = 2 * B = 2 * 125 KHz = 250,000 符号/秒 = 250 Kbaud`。
    *   **最大比特率:** 我们使用奈奎斯特容量公式： `C = 2 * B * log₂(L)`。
        *   调制方式为 **QPSK** (正交相移键控)，这意味着有 4 种不同的信号状态（相位）。因此，`L = 4`。
        *   每符号比特数 `r = log₂(L) = log₂(4) = 2`。
        *   `C = 2 * 125,000 Hz * log₂(4) = 250,000 * 2 = 500,000 bps = 500 Kbps`。
        *   或者，使用符号率计算：`C = S_max * r = 250 Kbaud * 2 比特/符号 = 500 Kbps`。
    **答案:** 理论最大比特率为 **500 Kbps**，理论最大符号率为 **250 Kbaud**。

---

##### **7. Consider a noisy channel with a bandwidth of 125 KHz. Assume that the average received power is 7 watts and the average AWGN noise power is 1 watt. What is the theoretical maximum bit rate for this channel?**
##### **7. 考虑一个带宽为 125 KHz 的有噪声信道，接收信号的平均功率为 7 瓦，平均 AWGN 噪声功率为 1 瓦。该信道的理论最大比特率是多少？**

*   **English Answer:**
    For a noisy channel, we use the Shannon-Hartley theorem: `C = B * log₂(1 + S/N)`.
    *   Bandwidth `B = 125 KHz = 125,000 Hz`.
    *   Signal power `S = 7 watts`.
    *   Noise power `N = 1 watt`.
    *   Signal-to-Noise Ratio `S/N = 7 / 1 = 7`.
    *   `C = 125,000 * log₂(1 + 7) = 125,000 * log₂(8)`.
    *   Since `2³ = 8`, `log₂(8) = 3`.
    *   `C = 125,000 * 3 = 375,000 bps = 375 Kbps`.
    **Answer:** The theoretical maximum bit rate for this channel is **375 Kbps**.

*   **中文解答:**
    对于有噪声的信道，我们使用香农-哈特利定理：`C = B * log₂(1 + S/N)`。
    *   带宽 `B = 125 KHz = 125,000 Hz`。
    *   信号功率 `S = 7 瓦`。
    *   噪声功率 `N = 1 瓦`。
    *   信噪比 `S/N = 7 / 1 = 7`。
    *   `C = 125,000 * log₂(1 + 7) = 125,000 * log₂(8)`。
    *   因为 `2³ = 8`, 所以 `log₂(8) = 3`。
    *   `C = 125,000 * 3 = 375,000 bps = 375 Kbps`。
    **答案:** 该信道的理论最大比特率为 **375 Kbps**。

---

##### **8. An analog signal has a bit rate of 8000 bps and a symbol rate of 1000 symbols per second. How many bits are carried by each signal element (symbol)? How many different symbols do we need?**
##### **8. 一个模拟信号的比特率为 8000 bps，符号率为 1000 符号/秒。每个信号元素（符号）携带多少比特？我们需要多少种不同的符号？**

*   **English Answer:**
    *   **Bits per Symbol (r):** We use the formula `N = S * r`.
        *   `r = N / S = 8000 bps / 1000 symbols/sec = 8 bits/symbol`.
    *   **Number of different symbols (L):** We use the formula `L = 2^r`.
        *   `L = 2⁸ = 256`.
    **Answer:** Each symbol carries **8 bits**. We need **256 different symbols**.

*   **中文解答:**
    *   **每符号比特数 (r):** 使用公式 `N = S * r`。
        *   `r = N / S = 8000 bps / 1000 符号/秒 = 8 比特/符号`。
    *   **不同符号的数量 (L):** 使用公式 `L = 2^r`。
        *   `L = 2⁸ = 256`。
    **答案:** 每个符号携带 **8 比特**。我们需要 **256** 种不同的符号。

---

##### **9. Suppose for a binary digital modulation, e.g., BPSK, the symbol rate is 600 Kbaud, then what is the bit rate?**
##### **9. 假设一个二进制数字调制（例如 BPSK），符号率为 600 Kbaud，那么比特率是多少？**

*   **English Answer:**
    *   For a **binary** modulation, each symbol represents only one bit. Therefore, `r = 1 bit/symbol`.
    *   `N = S * r = 600 Kbaud * 1 = 600 Kbps`.
    **Answer:** The bit rate is **600 Kbps**.

*   **中文解答:**
    *   对于**二进制**调制，每个符号只代表一个比特。因此，`r = 1 比特/符号`。
    *   `N = S * r = 600 Kbaud * 1 = 600 Kbps`。
    **答案:** 比特率是 **600 Kbps**。

---

##### **10. If the baud rate (symbol rate) is 600 Kbaud for an 8PSK signal, then what is the bit rate?**
##### **10. 如果一个 8PSK 信号的波特率（符号率）是 600 Kbaud，那么比特率是多少？**

*   **English Answer:**
    *   For an **8PSK** signal, there are `L = 8` different symbols (phases).
    *   The number of bits per symbol is `r = log₂(L) = log₂(8) = 3 bits/symbol`.
    *   `N = S * r = 600 Kbaud * 3 = 1800 Kbps = 1.8 Mbps`.
    **Answer:** The bit rate is **1.8 Mbps**.

*   **中文解答:**
    *   对于 **8PSK** 信号，有 `L = 8` 种不同的符号（相位）。
    *   每符号的比特数是 `r = log₂(L) = log₂(8) = 3 比特/符号`。
    *   `N = S * r = 600 Kbaud * 3 = 1800 Kbps = 1.8 Mbps`。
    **答案:** 比特率是 **1.8 Mbps**。

---
##### **11. Using the signal constellation diagram shown, answer the following questions.**
##### **11. 根据下图所示的信号星座图，回答以下问题。**
*(The diagram shows 8 points arranged in a circle around the origin)*
*(图表显示 8 个点围绕原点分布在一个圆上)*

*   **a) What type of modulation does this represent?**
    *   **Answer:** The diagram shows 8 distinct points, all at the same distance from the origin (constant amplitude) but with different angles (different phases). This represents **8-PSK (8-Phase Shift Keying)**.
*   **b) How many symbols are represented?**
    *   **Answer:** There are 8 points on the diagram, so **8 symbols** are represented (`L = 8`).
*   **c) How many bits per symbol are used?**
    *   **Answer:** `r = log₂(L) = log₂(8) = 3 bits per symbol`.
*   **d) If the Baud rate is 10,000 symbols/second, what is the bit rate?**
    *   **Answer:** `N = S * r = 10,000 symbols/sec * 3 bits/symbol = 30,000 bps = 30 Kbps`.
*   **e) Would 16-QAM be more or less susceptible to noise than this type of modulation?**
    *   **Answer:** **16-QAM would be more susceptible to noise.**
        *   **Reasoning:** Susceptibility to noise is related to the distance between constellation points. To transmit more bits per symbol, we need more points in the constellation (16 for 16-QAM vs. 8 for 8-PSK). Assuming similar average signal power, packing more points into the signal space forces them to be closer together. The smaller the distance between points, the less noise it takes to cause the receiver to mistake one symbol for an adjacent one. Therefore, 16-QAM is generally more susceptible to noise than 8-PSK.

*   **中文解答:**
    *   **a) 这代表了哪种调制类型？**
        *   **答案:** 该图显示了 8 个不同的点，所有点到原点的距离都相等（幅度恒定），但角度不同（相位不同）。这代表 **8-PSK (8-相移键控)**。
    *   **b) 图中代表了多少个符号？**
        *   **答案:** 图中有 8 个点，因此代表了 **8 个符号** (`L = 8`)。
    *   **c) 每个符号使用多少个比特？**
        *   **答案:** `r = log₂(L) = log₂(8) = 3 比特/符号`。
    *   **d) 如果波特率是 10,000 符号/秒，比特率是多少？**
        *   **答案:** `N = S * r = 10,000 符号/秒 * 3 比特/符号 = 30,000 bps = 30 Kbps`。
    *   **e) 与这种调制方式相比，16-QAM 对噪声的敏感度是更高还是更低？**
        *   **答案:** **16-QAM 对噪声的敏感度更高**。
        *   **原因:** 对噪声的敏感度与星座图中点与点之间的距离有关。为了每个符号传输更多的比特，星座图中需要更多的点（16-QAM 是 16 个点，而 8-PSK 是 8 个点）。在平均信号功率相近的情况下，将更多的点挤入信号空间会迫使它们彼此靠得更近。点之间的距离越小，一个较小的噪声就可能导致接收器将一个符号误判为相邻的另一个符号。因此，16-QAM 通常比 8-PSK 更容易受到噪声的干扰。

---
... (The remaining questions will follow the same detailed format) ...

*(Due to length limitations, I will continue with the rest of the questions. The formatting will be consistent.)*

---

##### **12. Consider a channel with a 1 MHz capacity and an SNR of 63.**
##### **12. 考虑一个带宽为 1 MHz，信噪比为 63 的信道。**

*   **a) What is the upper limit to the data rate that the channel can carry?**
    *   **English Answer:** This asks for the Shannon Capacity.
        `C = B * log₂(1 + SNR) = 1,000,000 * log₂(1 + 63) = 1,000,000 * log₂(64)`.
        Since `2⁶ = 64`, `log₂(64) = 6`.
        `C = 1,000,000 * 6 = 6,000,000 bps = 6 Mbps`.
        The upper limit is **6 Mbps**.
    *   **中文解答:** 这里要求的是香农容量。
        `C = B * log₂(1 + SNR) = 1,000,000 * log₂(1 + 63) = 1,000,000 * log₂(64)`。
        因为 `2⁶ = 64`，所以 `log₂(64) = 6`。
        `C = 1,000,000 * 6 = 6,000,000 bps = 6 Mbps`。
        数据率的上限是 **6 Mbps**。

*   **b) ...Assume we choose a data rate of 2/3 as the maximum theoretical limit. How many signal levels are needed to achieve this data rate?**
    *   **English Answer:**
        1.  Calculate the practical data rate: `N = (2/3) * C = (2/3) * 6 Mbps = 4 Mbps`.
        2.  Use the Nyquist formula to find the number of signal levels (L) required for this data rate: `N = 2 * B * log₂(L)`.
        3.  `4,000,000 = 2 * 1,000,000 * log₂(L)`.
        4.  `4 = 2 * log₂(L)`.
        5.  `log₂(L) = 2`.
        6.  `L = 2² = 4`.
        **4 signal levels** are needed.
    *   **中文解答:**
        1.  计算实际数据率： `N = (2/3) * C = (2/3) * 6 Mbps = 4 Mbps`。
        2.  使用奈奎斯特定理来找到实现该数据率所需的信号电平数 (L)：`N = 2 * B * log₂(L)`。
        3.  `4,000,000 = 2 * 1,000,000 * log₂(L)`。
        4.  `4 = 2 * log₂(L)`。
        5.  `log₂(L) = 2`。
        6.  `L = 2² = 4`。
        需要 **4 个信号电平**。

---

##### **13. A channel can transmit signals in the frequency range of 2500 kHz to 4000 kHz. Compute its bandwidth. Assuming SNRdB = 40, what will be the theoretical maximum capacity of this channel?**
##### **13. 一个信道可以传输 2500 kHz 到 4000 kHz 频率范围内的信号。计算其带宽。假设信噪比为 40 dB，该信道的理论最大容量是多少？**

*   **English Answer:**
    1.  **Compute Bandwidth (B):**
        `B = f_max - f_min = 4000 kHz - 2500 kHz = 1500 kHz = 1.5 MHz = 1,500,000 Hz`.
    2.  **Convert SNR from dB to a linear ratio:**
        `SNR_dB = 10 * log₁₀(S/N)`.
        `40 = 10 * log₁₀(S/N)`.
        `4 = log₁₀(S/N)`.
        `S/N = 10⁴ = 10,000`.
    3.  **Calculate Shannon Capacity (C):**
        `C = B * log₂(1 + S/N) = 1,500,000 * log₂(1 + 10000) = 1,500,000 * log₂(10001)`.
        Using a calculator, `log₂(10001) ≈ 13.289`.
        `C ≈ 1,500,000 * 13.289 ≈ 19,933,500 bps ≈ 19.93 Mbps`.
    **Answer:** The bandwidth is **1.5 MHz** and the theoretical maximum capacity is approximately **19.93 Mbps**.

*   **中文解答:**
    1.  **计算带宽 (B):**
        `B = f_max - f_min = 4000 kHz - 2500 kHz = 1500 kHz = 1.5 MHz = 1,500,000 Hz`。
    2.  **将信噪比从 dB 转换为线性比值:**
        `SNR_dB = 10 * log₁₀(S/N)`。
        `40 = 10 * log₁₀(S/N)`。
        `4 = log₁₀(S/N)`。
        `S/N = 10⁴ = 10,000`。
    3.  **计算香农容量 (C):**
        `C = B * log₂(1 + S/N) = 1,500,000 * log₂(1 + 10000) = 1,500,000 * log₂(10001)`。
        使用计算器，`log₂(10001) ≈ 13.289`。
        `C ≈ 1,500,000 * 13.289 ≈ 19,933,500 bps ≈ 19.93 Mbps`。
    **答案:** 带宽为 **1.5 MHz**，理论最大容量约为 **19.93 Mbps**。

---

##### **14. A 6-km-long cable has an attenuation of -0.25 dB/km. A signal with a power of 2.84 mW has been received at the end of the cable. Find out the power at which the signal was transmitted from the source.**
##### **14. 一根 6 公里长的电缆每公里的衰减为 -0.25 dB。在电缆末端接收到的信号功率为 2.84 mW。求信号从源端发送时的功率。**

*   **English Answer:**
    1.  **Calculate total attenuation:**
        `Total Attenuation = (-0.25 dB/km) * 6 km = -1.5 dB`.
    2.  **Use the attenuation formula:**
        `Attenuation (dB) = 10 * log₁₀(P_received / P_transmitted)`.
        `-1.5 = 10 * log₁₀(2.84 mW / P_transmitted)`.
        `-0.15 = log₁₀(2.84 / P_transmitted)`.
    3.  **Solve for P_transmitted:**
        `10⁻⁰.¹⁵ = 2.84 / P_transmitted`.
        `0.7079 = 2.84 / P_transmitted`.
        `P_transmitted = 2.84 / 0.7079 ≈ 4.012 mW`.
    **Answer:** The signal was transmitted with a power of approximately **4.01 mW**.

*   **中文解答:**
    1.  **计算总衰减:**
        `总衰减 = (-0.25 dB/km) * 6 km = -1.5 dB`。
    2.  **使用衰减公式:**
        `衰减 (dB) = 10 * log₁₀(P_接收 / P_发送)`。
        `-1.5 = 10 * log₁₀(2.84 mW / P_发送)`。
        `-0.15 = log₁₀(2.84 / P_发送)`。
    3.  **求解 P_发送:**
        `10⁻⁰.¹⁵ = 2.84 / P_发送`。
        `0.7079 = 2.84 / P_发送`。
        `P_发送 = 2.84 / 0.7079 ≈ 4.012 mW`。
    **答案:** 信号发送时的功率约为 **4.01 mW**。

---

##### **15. How many bits are needed for a QPSK signal? If the baud rate is 500 Mbaud, what will be the bit rate?**
##### **15. 一个 QPSK 信号需要多少比特？如果波特率是 500 Mbaud，比特率是多少？**

*   **English Answer:**
    *   **Bits per symbol for QPSK:** "Q" stands for Quadrature, implying 4 states. `L = 4`.
        `r = log₂(L) = log₂(4) = 2 bits`. A QPSK signal carries **2 bits** per symbol.
    *   **Calculate bit rate:**
        `N = S * r = 500 Mbaud * 2 bits/symbol = 1000 Mbps = 1 Gbps`.
    **Answer:** QPSK uses **2 bits** per symbol. The bit rate will be **1 Gbps**.

*   **中文解答:**
    *   **QPSK 的每符号比特数:** "Q" 代表正交，意味着 4 种状态。`L = 4`。
        `r = log₂(L) = log₂(4) = 2 比特`。一个 QPSK 信号每个符号携带 **2 比特**。
    *   **计算比特率:**
        `N = S * r = 500 Mbaud * 2 比特/符号 = 1000 Mbps = 1 Gbps`。
    **答案:** QPSK 每个符号使用 **2 比特**。比特率将是 **1 Gbps**。

---

##### **16. Given that r = 0.5, what is the required bandwidth for each of the following cases if the data rate is 8000 bps?**
##### **16. 给定 r = 0.5，如果数据率为 8000 bps，以下每种情况所需的带宽是多少？**
*(Note: Here, 'r' is interpreted as the roll-off factor (α) for pulse shaping, not bits per symbol. The formula for bandwidth with pulse shaping is `B = S * (1 + α)`)*
*(注：这里的 'r' 应被理解为脉冲成形中的滚降系数 (α)，而不是每符号比特数。带脉冲成形的带宽公式为 `B = S * (1 + α)`)*

*   **English Answer:**
    Data Rate `N = 8000 bps`. Roll-off factor `α = r = 0.5`.
    First, find the symbol rate (S) for each case using `S = N / log₂(L)`.

    *   **a. ASK (Binary ASK):**
        *   `L = 2`. `log₂(2) = 1`.
        *   `S = 8000 / 1 = 8000 baud`.
        *   `B = S * (1 + α) = 8000 * (1 + 0.5) = 8000 * 1.5 = 12,000 Hz = 12 KHz`.
    *   **b. QPSK:**
        *   `L = 4`. `log₂(4) = 2`.
        *   `S = 8000 / 2 = 4000 baud`.
        *   `B = S * (1 + α) = 4000 * (1 + 0.5) = 4000 * 1.5 = 6,000 Hz = 6 KHz`.
    *   **c. 64-QAM:**
        *   `L = 64`. `log₂(64) = 6`.
        *   `S = 8000 / 6 ≈ 1333.33 baud`.
        *   `B = S * (1 + α) ≈ 1333.33 * (1 + 0.5) ≈ 1333.33 * 1.5 = 2000 Hz = 2 KHz`.

*   **中文解答:**
    数据率 `N = 8000 bps`。滚降系数 `α = r = 0.5`。
    首先，使用 `S = N / log₂(L)` 为每种情况计算符号率 (S)。

    *   **a. ASK (二进制 ASK):**
        *   `L = 2`。`log₂(2) = 1`。
        *   `S = 8000 / 1 = 8000 baud`。
        *   `B = S * (1 + α) = 8000 * (1 + 0.5) = 8000 * 1.5 = 12,000 Hz = 12 KHz`。
    *   **b. QPSK:**
        *   `L = 4`。`log₂(4) = 2`。
        *   `S = 8000 / 2 = 4000 baud`。
        *   `B = S * (1 + α) = 4000 * (1 + 0.5) = 4000 * 1.5 = 6,000 Hz = 6 KHz`。
    *   **c. 64-QAM:**
        *   `L = 64`。`log₂(64) = 6`。
        *   `S = 8000 / 6 ≈ 1333.33 baud`。
        *   `B = S * (1 + α) ≈ 1333.33 * (1 + 0.5) ≈ 1333.33 * 1.5 = 2000 Hz = 2 KHz`。

---

#### **第二部分: 选择题 (Multiple Choice Questions)**

| 题号 | 问题 (Question) & 选项 (Options) | 正确答案 | 解释 (Explanation) |
| :--- | :--- | :--- | :--- |
| **1** | **What does the bit rate measure in digital communication?**<br>A) Number of symbols sent per second<br>B) Number of signal elements per second<br>C) Number of bits sent per second<br>D) Frequency of the carrier wave | **C** | Bit rate is the fundamental measure of information transfer speed, defined as bits per second. A and B describe the symbol rate (Baud rate). |
| **2** | **What is the relationship between bit rate N, symbol rate S, and bits per symbol r?**<br>A) N=S/r<br>B) N=S+r<br>C) N=S×r<br>D) N=S-r | **C** | The total number of bits per second (N) is the number of symbols sent per second (S) multiplied by the number of bits each symbol represents (r). |
| **3** | **Which modulation technique alters the amplitude of the carrier signal?**<br>A) FSK<br>B) ASK<br>C) PSK<br>D) QAM | **B & D** | ASK (Amplitude Shift Keying) alters only the amplitude. QAM (Quadrature Amplitude Modulation) alters both amplitude and phase. In the context of "alters," both are valid, but ASK is the primary technique that relies *solely* on amplitude. If only one answer is allowed, B is the most direct. |
| **4** | **In QAM, what are the two main components of the signal?**<br>A) In-phase and out-of-phase<br>B) Amplitude and frequency<br>C) In-phase and quadrature-phase<br>D) Amplitude and phase | **C** | QAM works by modulating two orthogonal carriers, known as the In-phase (I) and Quadrature-phase (Q) components. |
| **5** | **Which of the following describes the Baud rate in digital communication?**<br>A) The number of signal elements per second<br>B) The frequency of the signal<br>C) The amplitude of the signal<br>D) The modulation index | **A** | Baud rate is another name for symbol rate, which is the number of signal elements (symbols) transmitted per second. |
| **6** | **What is the symbol rate in BPSK if the bit rate is 10 Mbps?**<br>A) 5 Mbaud<br>B) 10 Mbaud<br>C) 15 Mbaud<br>D) 20 Mbaud | **B** | In BPSK (Binary PSK), each symbol carries 1 bit (r=1). Therefore, the symbol rate is equal to the bit rate. 10 Mbps = 10 Mbaud. |
| **7** | **Which modulation scheme uses both phase and amplitude changes to represent data?**<br>A) ASK<br>B) FSK<br>C) PSK<br>D) QAM | **D** | By definition, QAM combines amplitude and phase modulation to encode data, making it very efficient. |
| **8** | **In a noisy channel with a very low signal-to-noise ratio, the channel capacity approaches:**<br>A) Infinity<br>B) Zero<br>C) Half the bandwidth<br>D) Double the bandwidth | **B** | According to Shannon's formula `C = B*log₂(1+S/N)`, as S/N approaches 0, `log₂(1+0)` approaches `log₂(1)`, which is 0. Thus, the capacity C approaches zero. |
| **9** | **If the symbol rate is 2000 symbols/sec and each symbol represents 3 bits, what is the bit rate?**<br>A) 2000 bps<br>B) 4000 bps<br>C) 6000 bps<br>D) 8000 bps | **C** | Bit rate N = Symbol rate S × bits/symbol r. N = 2000 × 3 = 6000 bps. |
| **10**| **Which factor primarily limits the maximum number of symbols in M-PSK modulation?**<br>A) Signal frequency<br>B) Amplitude range<br>C) Susceptibility to noise<br>D) Bit rate | **C** | In M-PSK, as you increase the number of symbols (phases), the phase difference between adjacent symbols becomes smaller. This makes the signal more susceptible to noise, as a small phase shift caused by noise can lead to an error. |