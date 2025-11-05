### **Fundamentals of Communication Systems - Lecture 4**
### **通信系统基础 - 第 4 讲**

---

#### **第一部分: 比特率与符号率 (Bit Rate vs. Symbol Rate)**

##### **幻灯片 2: 概述 (Overview)**

| English (英文) | Chinese (中文) |
| :--- | :--- |
| **Overview** | **本讲概述** |
| Bit Rate vs. Baud Rate / Symbol Rate | 比特率 vs. 波特率 / 符号率 |
| Data Rate Limits | 数据率限制 |
| Multi-level Digital Modulation | 多电平数字调制 |
| <ul><li>M-ASK</li><li>M-FSK</li><li>M-PSK</li><li>QAM</li></ul> | <ul><li>多电平幅移键控 (M-ASK)</li><li>多电平频移键控 (M-FSK)</li><li>多电平相移键控 (M-PSK)</li><li>正交幅度调制 (QAM)</li></ul> |

##### **幻灯片 4: 数字调制导论 (Introduction to Digital Modulation)**

*   **English:**
    *   In a digital modulation method, each **symbol** is typically a sine wave tone with a specific **frequency, amplitude, and phase**.
    *   **Symbol rate**, also known as **baud rate**, is the number of transmitted symbols (tones) per second.
    *   A single symbol can carry one or more bits of information.
    *   The system is time-slotted; it transmits '0's and '1's within discrete time slots.
    *   In each time slot, a simple sine wave (a symbol) is transmitted.
    *   **Diagram Explanation:** The diagram shows a binary stream `0, 1, 0, 0, 1` with a **Bit Rate of 5 bps**. Each bit is transmitted within one time slot, also called a **baud**. For this BPSK (Binary Phase Shift Keying) example, bit '0' is mapped to a phase of 0°, and bit '1' to 180°. Since one bit is sent per symbol, the **Baud Rate is 5 baud**, which is equal to the bit rate. The **constellation diagram** visually represents the phase mapping for '0' and '1'.

*   **中文:**
    *   在数字调制方法中，每个**符号 (symbol)** 通常是一个具有特定**频率、幅度和相位**的正弦波音频。
    *   **符号率 (Symbol rate)**，也称为**波特率 (baud rate)**，是每秒传输的符号（音频）数量。
    *   一个符号可以携带一个或多个比特的信息。
    *   系统是时隙化的，它在离散的时间片内传输 '0' 和 '1'。
    *   在每个时间片内，传输一个简单的正弦波（即一个符号）。
    *   **图示解析:** 该图展示了一个**比特率为 5 bps** 的二进制流 `0, 1, 0, 0, 1`。每个比特在一个时间片（也称为一个**波特 (baud)**）内传输。在这个 BPSK (二进制相移键控) 示例中，比特 '0' 映射到 0° 相位，比特 '1' 映射到 180° 相位。由于每个符号只发送一个比特，因此**波特率也是 5 波特**，与比特率相等。**星座图 (constellation diagram)** 直观地展示了 '0' 和 '1' 的相位映射关系。

##### **幻灯片 5-6: 比特率与波特率的定义与关系 (Definitions and Relationship)**

| 术语 (Term) | 英文定义 (English Definition) | 中文定义 (Chinese Definition) |
| :--- | :--- | :--- |
| **Bit Rate (N)** | The number of bits sent in one second. Unit: bps (bits per second). | 每秒发送的比特数量。单位：bps (比特/秒)。 |
| **Baud Rate (S)** | The number of signal elements (symbols) per second. Also known as symbol rate or modulation rate. Unit: baud (bd) or symbols per second. | 每秒发送的信号元素（符号）数量。也称为符号率或调制率。单位：波特 (bd) 或 符号/秒。 |
| **Symbol** | A signal element that persists for a fixed period. In digital modulation, it's typically a sine wave with specific frequency, amplitude, and phase. | 持续固定时间长度的一个信号元素。在数字调制中，它通常是具有特定频率、幅度和相位的正弦波。 |
| **r** | The number of bits per symbol. | 每个符号携带的比特数。 |
| **L** | The number of different signal elements (symbols). | 不同信号元素（符号）的总数。 |

*   **核心关系公式 (Key Relationship Formulas):**
    1.  **比特率 (Bit Rate):** `N = r * S`
    2.  **每符号比特数 (Bits per Symbol):** `r = log₂(L)`

##### **幻灯片 7: 二进制调制方案 (Binary Modulation Schemes)**

*   **English:**
    *   For binary modulation schemes like **BASK, BFSK, and BPSK**, the symbol rate is equal to the bit rate.
    *   **Reasoning:**
        *   In binary schemes, there are only two different signal elements (L=2). For example, two different amplitudes, frequencies, or phases.
        *   The number of bits per symbol is `r = log₂(L) = log₂(2) = 1`.
        *   Since `N = r * S`, and `r = 1`, it follows that `N = S`.
    *   **Conclusion:** For binary modulation, **BIT RATE = SYMBOL RATE**.
*   **中文:**
    *   对于像 **BASK (幅移键控), BFSK (频移键控), 和 BPSK (相移键控)** 这样的二进制调制方案，符号率等于比特率。
    *   **推导过程:**
        *   在二进制方案中，只有两种不同的信号元素 (L=2)，例如两种不同的幅度、频率或相位。
        *   因此，每个符号携带的比特数 `r = log₂(L) = log₂(2) = 1`。
        *   根据公式 `N = r * S`，当 `r = 1` 时，必然得出 `N = S`。
    *   **结论:** 对于二进制调制，**比特率 = 符号率**。

---

#### **第二部分: 数据率限制 (Data Rate Limits)**

##### **幻灯片 9: 最大数据率 (Maximum Data Rate)**

| 信道类型 (Channel Type) | 理论/定律 (Theory/Law) | 公式 (Formula) | 变量解释 (Variable Explanation) | 关键点 (Key Points) |
| :--- | :--- | :--- | :--- | :--- |
| **Noiseless Channel** | **Nyquist Law** | `C = 2B log₂(L)` | **C**: 最大比特率 (bps)<br>**B**: 信道带宽 (Hz)<br>**L**: 信号电平/符号数量 | <li>最大符号率 `S_max = 2B`。</li><li>L 不能无限增大，因为接收端区分符号的能力有限。</li> |
| **Noisy Channel** | **Shannon Capacity** | `C = B log₂(1 + S/N)` | **C**: 信道容量 (bps)<br>**B**: 信道带宽 (Hz)<br>**S/N**: 信噪比 (线性功率比，非dB) | <li>这是在有高斯白噪声(AWGN)干扰下，理论上可达到的无差错传输的最大速率。</li><li>S/N 是信号功率 (S) 与噪声功率 (N) 的比值。</li> |

##### **幻灯片 10-11: 测验与应用 (Quizzes and Applications)**

| 测验问题 (Quiz Question) | 已知参数 (Given Parameters) | 求解 (Solution) | 结论 (Conclusion) |
| :--- | :--- | :--- | :--- |
| **1. 极度嘈杂的信道**<br>信噪比 (SNR) 几乎为零，求信道容量 C。 | SNR ≈ 0 | `C = B log₂(1 + SNR)`<br>`= B log₂(1 + 0)`<br>`= B log₂(1) = B * 0 = 0` | 这种信道的容量为零，无论带宽多大都无法可靠地传输任何数据。 |
| **2. 普通电话线**<br>求其理论最大比特率。 | 带宽 (B) = 3000 Hz<br>信噪比 (SNR) = 3162 | `C = B log₂(1 + SNR)`<br>`= 3000 * log₂(1 + 3162)`<br>`= 3000 * log₂(3163)`<br>`≈ 3000 * 11.62 = 34,860 bps` | 该电话线的理论最大数据率为 34.86 kbps。要提高速率，必须增加带宽或改善信噪比。 |

---

#### **第三部分: 多电平数字调制 (Multi-Level Digital Modulation)**

##### **幻灯片 13-14: 多电平调制导论 (Introduction to Multi-Level Modulation)**

*   **English:**
    *   **Modulation Mechanisms:** Digital data is modulated onto an analog signal by altering one of its three characteristics: **amplitude (ASK), frequency (FSK), or phase (PSK)**.
    *   **QAM (Quadrature Amplitude Modulation):** A fourth, more efficient mechanism that combines changes in both **amplitude and phase**.
    *   **Multi-level (M-ary) Modulation:**
        *   Transmits multiple bits simultaneously by using more than two signal elements (L > 2).
        *   Each symbol represents more than one bit (`r > 1`).
        *   It allows for a higher bit rate (`N`) for a given symbol rate (`S`) and bandwidth. This is because `N = r * S`, and we increase `r`.
*   **中文:**
    *   **调制机制:** 通过改变模拟信号的三个特性之一：**幅度 (ASK)、频率 (FSK) 或 相位 (PSK)**，将数字数据调制上去。
    *   **QAM (正交幅度调制):** 第四种更高效的机制，它同时改变**幅度和相位**。
    *   **多电平 (M-ary) 调制:**
        *   通过使用两个以上的信号元素 (L > 2)，实现多个比特的同时传输。
        *   每个符号代表超过一个比特 (`r > 1`)。
        *   在给定的符号率 (`S`) 和带宽下，它能实现更高的比特率 (`N`)。这是因为 `N = r * S`，而我们增大了 `r`。

##### **幻灯片 15-16: 多电平幅移键控 (Multi-level ASK, M-ASK)**

*   **English:**
    *   Uses multiple (M) different amplitude values of the carrier.
    *   Each amplitude encodes a specific pattern of bits.
    *   Frequency and phase remain constant.
    *   **General Formula:** `sᵢ(t) = Aᵢ cos(2πf_c t + φ)`, where `0 ≤ t ≤ T_s` and `i = 1, 2, ..., L`. Only `Aᵢ` varies.
    *   **Example (4-ASK):** L=4. The four signal amplitudes could be, for instance, -3V, -1V, 1V, and 3V, each representing a 2-bit symbol (e.g., 00, 01, 10, 11).
*   **中文:**
    *   使用载波的多个 (M) 不同幅度值。
    *   每个幅度值编码一个特定的比特模式。
    *   频率和相位保持不变。
    *   **通用公式:** `sᵢ(t) = Aᵢ cos(2πf_c t + φ)`，其中 `0 ≤ t ≤ T_s` 且 `i = 1, 2, ..., L`。只有幅度 `Aᵢ` 变化。
    *   **示例 (4-ASK):** L=4。四个信号幅度可以是 -3V, -1V, 1V, 3V，每个幅度代表一个2比特的符号 (例如 00, 01, 10, 11)。

##### **幻灯片 17: 多电平频移键控 (Multi-level FSK, M-FSK)**

*   **English:**
    *   Uses L different carrier frequencies to represent multiple symbols.
    *   The frequencies must be carefully chosen to avoid interference.
    *   **Quiz:** Send 3 bits at a time (bit rate = 3 Mbps) using FSK. Calculate the number of frequencies (symbols) and the symbol rate.
    *   **Solution:**
        *   Bits per symbol `r = 3`.
        *   Number of symbols/frequencies `L = 2^r = 2³ = 8`.
        *   Symbol rate `S = N / r = 3 Mbps / 3 = 1 Mbaud`.
*   **中文:**
    *   使用 L 个不同的载波频率来代表多个符号。
    *   必须仔细选择这些频率以避免相互干扰。
    *   **测验:** 使用 FSK 一次发送3个比特（比特率为 3 Mbps）。计算所需频率（符号）的数量和符号率。
    *   **解答:**
        *   每符号比特数 `r = 3`。
        *   符号/频率数量 `L = 2^r = 2³ = 8` 个。
        *   符号率 `S = N / r = 3 Mbps / 3 = 1 Mbaud`。

##### **幻灯片 18-25: 多电平相移键控 (Multi-level PSK, M-PSK)**

| 主题 (Topic) | 英文描述 (English Description) | 中文描述 (Chinese Description) |
| :--- | :--- | :--- |
| **基本概念** | Uses L different carrier phase shifts. Each symbol is represented by one phase shift. | 使用 L 个不同的载波相移。每个符号由一个相移代表。 |
| **QPSK (4-PSK)** | Transmits one of 4 possible phase shifts per symbol. L=4, so `r = log₂(4) = 2` bits/symbol. It can double the data rate of BPSK with the same bandwidth. | 每个符号传输4个可能相移中的一个。L=4, 因此 `r = log₂(4) = 2` 比特/符号。在相同带宽下，其数据率可以是 BPSK 的两倍。 |
| **M-PSK 信号** | General formula: `sᵢ(t) = A cos(2πf_c t + φᵢ)`. The phase `φᵢ` is typically given by `φᵢ = (2π/L)(i-1) + constant`. | 通用公式: `sᵢ(t) = A cos(2πf_c t + φᵢ)`。相位 `φᵢ` 通常由 `φᵢ = (2π/L)(i-1) + 常数` 给出。 |
| **QPSK 信号分解** | QPSK signal can be written as `Acos(φᵢ)cos(2πf_c t) + (-Asin(φᵢ))sin(2πf_c t)`. This shows it utilizes two orthogonal carriers (in-phase and quadrature-phase components). | QPSK 信号可写作 `Acos(φᵢ)cos(2πf_c t) + (-Asin(φᵢ))sin(2πf_c t)`。这表明它利用了两个正交的载波（同相分量和正交分量）。 |
| **高阶 PSK** | Further increases bits per symbol by using more phase shifts. **8-PSK**: L=8, r=3 bits/symbol. **16-PSK**: L=16, r=4 bits/symbol. | 通过使用更多的相移来进一步增加每符号的比特数。**8-PSK**: L=8, r=3 比特/符号。**16-PSK**: L=16, r=4 比特/符号。 |
| **PSK 星座图** | For PSK, all symbols have the same amplitude. Therefore, on a constellation diagram, all points lie on a circle about the origin. | 对于 PSK，所有符号的幅度都相同。因此，在星座图上，所有的点都位于一个以原点为中心的圆上。 |
| **M-PSK 的局限性** | As L increases (e.g., 64-PSK, 128-PSK), the phase separation between symbols decreases. This makes the signal more susceptible to noise, leading to higher bit error rates. | 随着 L 的增加（例如 64-PSK, 128-PSK），符号之间的相位间隔减小。这使得信号更容易受到噪声的干扰，导致更高的比特误码率。 |

##### **幻灯片 26-32: 正交幅度调制 (Quadrature Amplitude Modulation, QAM)**

*   **English:**
    *   **Motivation:** To increase the distance between symbols and combat noise better than PSK, QAM modulates both **amplitude AND phase**.
    *   **Mechanism:** Uses two orthogonal carriers (sine and cosine), known as the **in-phase (I)** and **quadrature (Q)** components. The general M-QAM signal is `sᵢ(t) = Aᵢ,I cos(2πf_c t) + Aᵢ,Q sin(2πf_c t)`.
    *   This can also be viewed as a carrier with a specific amplitude `Aᵢ` and phase `φᵢ`, making it a hybrid of ASK and PSK.
    *   **4-QAM:** Is functionally identical to QPSK.
    *   **Higher-order QAM:**
        *   **Constellation:** Points are typically arranged in a square grid, allowing for larger distances between them compared to PSK for the same number of points.
        *   **Common Forms:** 16-QAM, 64-QAM, 256-QAM.
        *   **Applications:** Widely used in digital cable television and cable modems due to their high bandwidth efficiency.
*   **中文:**
    *   **动机:** 为了增大符号间的距离，比 PSK 更有效地抵抗噪声，QAM 同时调制**幅度和相位**。
    *   **机制:** 使用两个正交载波（正弦和余弦），称为**同相 (I) 分量**和**正交 (Q) 分量**。通用 M-QAM 信号为 `sᵢ(t) = Aᵢ,I cos(2πf_c t) + Aᵢ,Q sin(2πf_c t)`。
    *   这也可以看作是一个具有特定幅度 `Aᵢ` 和相位 `φᵢ` 的载波，使其成为 ASK 和 PSK 的混合体。
    *   **4-QAM:** 在功能上与 QPSK 相同。
    *   **高阶 QAM:**
        *   **星座图:** 符号点通常排列成方形网格，与相同点数的 PSK 相比，符号间距离更大。
        *   **常见形式:** 16-QAM、64-QAM、256-QAM。
        *   **应用:** 因其高带宽效率而广泛用于数字有线电视和电缆调制解อ器。

---

#### **第四部分: 总结 (Summary)**

##### **幻灯片 33: 比特率与符号率对比总结 (Bit and Symbol Rate Comparison Summary)**

| 调制方式 (Modulation) | 每符号比特数 (Bits/symbol, r) | 关系 (Relation) |
| :--- | :--- | :--- |
| BASK, BFSK, BPSK | 1 | Bit Rate = 1 x Symbol Rate |
| 4-PSK, 4-QAM | 2 | Bit Rate = 2 x Symbol Rate |
| 8-PSK, 8-QAM | 3 | Bit Rate = 3 x Symbol Rate |
| 16-PSK, 16-QAM | 4 | Bit Rate = 4 x Symbol Rate |
| 32-QAM | 5 | Bit Rate = 5 x Symbol Rate |
| 64-QAM | 6 | Bit Rate = 6 x Symbol Rate |
| 128-QAM | 7 | Bit Rate = 7 x Symbol Rate |
| 256-QAM | 8 | Bit Rate = 8 x Symbol Rate |