### **Fundamentals of Communication Systems - Lecture 2**

#### **1. 信号是什么？- 回顾 (What is a signal? - Recap)**
*   **信号 (Signal)**: 一个或多个自变量的函数，其中包含某种信息。
    *   A function of one or more independent variables which contains some information is called a signal.
*   在电气意义上，信号可以是电压或电流。电压或电流是时间的函数。
    *   In electrical sense, the signal can be voltage or current. The voltage or current is the function of time.
*   电信号可以用电压源 (戴维南形式) 或电流源 (诺顿形式) 来表示。
    *   An electrical signal may be represented either in the form of a voltage source (Thevenin's form) or in the form of a current source (Norton's Form).

---

#### **2. 基本信号概念 (BASIC SIGNAL CONCEPTS)**

| 概念 (Concept) | 描述 (Description) | 示例 (Examples) |
| :--- | :--- | :--- |
| **连续时间 (CT) 信号 (Continuous-Time Signal)** | 在从 `-∞` 到 `+∞` 的时间范围内的每一个瞬间都有定义。表示为 `x(t)`。 | 正弦波、语音信号 |
| **离散时间 (DT) 信号 (Discrete-Time Signal)** | 仅在离散的时间瞬间有定义，因此它是一个称为 **采样 (samples)** 的数字序列。表示为 `{x[n]}`，n 为整数。 | 数字音频信号 |
| **模拟信号 (Analogue Signal)** | 在特定范围内可以取任意值；即模拟信号在 **值和时间上都是连续的**。 | 正弦波、语音、视频 |
| **数字信号 (Digital Signal)** | 在一系列时间点 `t = 0, Δ, 2Δ, ...` (其中 Δ 是采样周期) 只能取一组确定的值 (例如，二进制信号中的 0 和 1)。 | 摩尔斯电码、计算机中的串行二进制码 |

---

#### **3. 时域概念 (Time-Domain Concepts)**

*   **周期信号 (Periodic signal)**: 随时间重复的模拟或数字信号模式。
    *   `s(t + T) = s(t)`，其中 `T` 是信号的周期。
*   **非周期信号 (Aperiodic signal)**: 不随时间重复的模拟或数字信号模式。

**信号的关键参数 (Key Signal Parameters):**
| 参数 (Parameter) | 定义 (Definition) |
| :--- | :--- |
| **峰值振幅 (A) (Peak Amplitude)** | 信号随时间变化的最大值或强度，通常以伏特 (volts) 为单位。 |
| **频率 (f) (Frequency)** | 信号重复的速率，单位为周期/秒，即赫兹 (Hz)。 |
| **周期 (T) (Period)** | 信号完成一次重复所需的时间。`T = 1/f`。 |
| **相位 (Φ) (Phase)** | 在信号单个周期内相对于时间的测量位置。 |
| **波长 (λ) (Wavelength)** | 信号单个周期所占据的距离，或两个连续周期对应相应相位点之间的距离。 |

---

#### **4. 确定性与随机信号 (Deterministic and Random Signals)**

*   **确定性信号 (Deterministic Signal)**:
    *   对于每个时间值 `t`，其振幅是完全指定的，可以通过图形或解析式得知。
    *   **示例**: 正弦波形 `sin(4πt)`。
*   **随机信号 (Random Signal)**:
    *   其发生总是随机的，模式非常不规则。也称为非确定性信号。
    *   只能用概率来描述其行为。
    *   **示例**: 电路中产生的热噪声、语音和数据信号。
    *   对于随机信号，通常分析其统计特性，如 **平均值 (Average)**、**方差 (Variance)** 等。

---

#### **5. 偶信号与奇信号 (Even and Odd Signals)**

| 类型 (Type) | 特性 (Property) | 数学条件 (Mathematical Condition) |
| :--- | :--- | :--- |
| **偶信号 (Even Signal)** | 在时域中表现出对称性，关于原点对称。 | `x(t) = x(-t)` |
| **奇信号 (Odd Signal)** | 在时域中表现出反对称性，关于原点不对称。 | `x(t) = -x(-t)` |

---

#### **6. 信号分类总结 (General Classifications of Signals - Summary)**

| 分类 (Classification) | 子类别 (Sub-categories) | 示例 (Examples) | 信息内容 (Information Content) |
| :--- | :--- | :--- | :--- |
| **确定性 (Deterministic)** | 周期性 (Periodic) | 正弦波、三角波 | 包含信息 |
| | 非周期性 (Aperiodic) | 瞬态、单位脉冲 | 包含信息 |
| | 准周期性 (Quasi-periodic) | 心电图 (ECG) 波形 | 包含信息 |
| **随机性 (Stochastic)** | 平稳 (Stationary) | 电子电路中的噪声 | **不包含** 有用信息 (通常是噪声) |
| | 非平稳 (Non-stationary) | 语言、音乐 | 包含信息 |

---

#### **7. 频域概念 (Frequency-Domain Concepts)**

*   **基频 (Fundamental frequency)**: 当信号的所有频率分量都是某个频率的整数倍时，该频率被称为基频。
*   **频谱 (Spectrum)**: 信号所包含的频率范围。
*   **绝对带宽 (Absolute bandwidth)**: 信号频谱的宽度。
*   **有效带宽 (Effective bandwidth)**: 包含信号大部分能量的窄带频率范围。
*   **频域表示**: 在频域中，信号由其 **频谱** 表示。傅里叶级数和傅里叶变换用于获得频谱。
*   **傅里叶思想**: 任何周期函数都可以重写为不同频率的正弦和余弦的加权和。

---

#### **8. 信号运算 (Signals Operations)**

| 运算 (Operation) | 模拟信号 (Analogue) | 数字信号 (Digital) | 描述 (Description) |
| :--- | :--- | :--- | :--- |
| **幅度缩放 (Amplitude Scaling)** | `y(t) = ax(t)` | `y(n) = ax(n)` | `|a| > 1` 为放大，`|a| < 1` 为衰减。 |
| **时间缩放 (Time Scaling)** | `y(t) = x(bt)` | `y(n) = x(bn)` | `b > 1` 为时间压缩，`0 < b < 1` 为时间扩展。 |
| **时间平移 (Time Shifting)** | `y(t) = x(t - t₀)` | `y(n) = x(n - t₀)` | `t₀ > 0` 为右移 (延迟)，`t₀ < 0` 为左移 (提前)。 |
| **反射 (Reflection)** | `y(t) = x(-t)` | `y(n) = x(-n)` | 信号关于 y 轴翻转。偶信号满足 `x(t)=x(-t)`，奇信号满足 `x(t)=-x(-t)`。 |

---

#### **9. 传输介质与带宽 (Transmission Medium & Bandwidth)**

*   **传输介质 (Transmission Medium)**: 数据从一个地方发送到另一个地方所通过的途径。
    *   **导向介质 (有线)**: 双绞线、同轴电缆、光纤。
    *   **非导向介质 (无线)**: 无线电波、微波、红外线。
*   **介质与带宽**:
    *   每种介质都有其自身特性，只允许某些频率通过。
    *   发送包含多种频率的复合信号时，接收到的信号可能与原始信号不同 (例如，方波会变得圆滑)。
    *   光纤比铜线具有更大的带宽 (高达1000倍)，允许更多频率通过，因此数据吞吐量更大。
*   **模拟与数字带宽**:
    *   **模拟带宽 (Analogue Bandwidth)**: 介质能通过的频率范围，单位为赫兹 (Hz)。
    *   **数字带宽 (Digital Bandwidth)**: 介质能通过的最大比特率，单位为比特/秒 (bps)。
*   **带宽利用**:
    *   电磁频谱是一种宝贵的自然资源，通信工程致力于最大限度地利用有限的频谱。
    *   开发通信技术以最小化传输给定信息所需的带宽，从而节约频谱空间。

---

#### **10. 信噪比 (Signal-to-Noise Ratio - SNR)**
*   **定义**: 信噪比（SNR）是用于量化信号中噪声水平的参数。
    *   Signal-to-noise ratio (SNR) is a parameter used to quantify how much noise there is in a signal.
*   **意义**: 高信噪比意味着信号功率相对于噪声水平较高，从而得到高质量的信号。
    *   A high SNR means a high signal power relative to noise level, resulting in a good-quality signal.
*   **计算**:
    *   信噪比被定义为平均信号功率与平均噪声功率的比值。之所以考虑平均功率，是因为它们可能随时间变化。
    *   The signal-to-noise ratio is defined as the ratio of average signal power to average noise power. We consider the average power because they may change with time.
    *   **公式**: `SNR = 平均信号功率 / 平均噪声功率`
*   **分贝单位 (Decibels)**:
    *   由于SNR是两个功率的比值，通常用分贝（dB）单位来表示。
    *   Because SNR is the ratio of two powers, it is often described in decibel units, SNRdB.
    *   **公式**: `SNR_dB = 10 × log₁₀(SNR)`

---

#### **11. 数据速率限制 (Data Rate Limits)**

数据速率取决于三个因素：
1.  **可用带宽 (The bandwidth available)**
2.  **使用的信号电平数 (The level of the signals we use)**
3.  **信道质量 (噪声水平) (The quality of the channel (the level of noise))**

**两个理论公式:**

1.  **奈奎斯特定理 (无噪声信道) (Nyquist Bit Rate - Noiseless Channel)**:
    *   `比特率 (Bit Rate) = 2 × B × log₂(L)`
    *   `B` 是信道带宽 (Hz)
    *   `L` 是表示数据的信号电平数
    *   **示例问题**:
        > 我们需要在一个带宽为 20 kHz 的无噪声信道上传输 265 kbps 的数据。需要多少个信号电平？
        > **解**:
        > `265,000 = 2 × 20,000 × log₂(L)`
        > `log₂(L) = 265,000 / 40,000 = 6.625`
        > `L = 2^6.625 ≈ 98.7` 个电平。
        > 由于电平数通常是2的幂，我们可以选择 128 个电平 (2⁷)，此时比特率为 280 kbps。

2.  **香农定理 (有噪声信道) (Shannon Capacity - Noisy Channel)**:
    *   `信道容量 (Capacity, C) = B × log₂(1 + SNR)`
    *   `C` 是信道的理论最高数据速率 (bps)
    *   `B` 是信道带宽 (Hz)
    *   `SNR` 是信噪比 (Signal-to-Noise Ratio)。
    *   香农公式定义了信道的特性，与传输方法无关。无论我们使用多少信号电平，数据速率都不能超过信道容量。
    *   **示例问题 1**:
        > 电话线的带宽通常为 3000 Hz，信噪比通常为 3162。计算该信道的容量。
        > **解**:
        > `C = 3000 × log₂(1 + 3162) = 3000 × log₂(3163) ≈ 34,881 bps` 或 `34.881 kbps`。
    *   **示例问题 2**:
        > 一个 1 MHz 带宽的信道，SNR 为 63。求合适的比特率和信号电平。
        > **解**:
        > 1.  **用香农公式求上限**: `C = 10⁶ × log₂(1 + 63) = 10⁶ × log₂(64) = 6 Mbps`。
        > 2.  **选择一个较低的实际速率**: 例如 4 Mbps。
        > 3.  **用奈奎斯特公式求电平数**: `4 Mbps = 2 × 1 MHz × log₂(L)` → `log₂(L) = 2` → `L = 4` 个电平。

---

#### **12. 性能指标 (Performance Metrics)**

*   **吞吐量 (Throughput)**: 衡量我们能以多快的速度实际发送数据。
    *   带宽是链路的 **潜在** 速率，吞吐量是 **实际** 速率。
    *   **示例问题**:
        > 一个带宽为 10 Mbps 的网络，每分钟只能通过平均 12,000 个帧，每个帧平均携带 10,000 比特。该网络的吞吐量是多少？
        > **解**:
        > `吞吐量 = (12,000 帧 × 10,000 比特/帧) / 60 秒 = 2,000,000 bps = 2 Mbps`。
*   **延迟 (Latency/Delay)**: 整个消息从源端发送第一个比特开始到目的地完整接收最后一个比特所花费的时间。
    *   `延迟 = 传播时间 + 传输时间 + 排队时间 + 处理时间`
    *   **传播时间 (Propagation time)** = `距离 / 传播速度`
    *   **传输时间 (Transmission time)** = `消息大小 / 带宽`
    *   **排队时间 (Queuing time)**: 在设备队列中等待传输的时间，随网络负载变化。
    *   **处理时间 (Processing delay)**: 设备处理消息所需的时间。
*   **抖动 (Jitter)**: 数据包延迟的变化。对于音频和视频等实时应用，这是一个关键问题。

**延迟计算示例:**
> **问题**: 一个 `5 × 10⁶` 字节的消息，网络带宽为 1 Mbps。发送方和接收方相距 12,000 km，传播速度为 `2.4 × 10⁸ m/s`。求传播时间和传输时间。
> **解**:
> 1.  **传播时间**:
>     `时间 = (12,000 × 1000 m) / (2.4 × 10⁸ m/s) = 0.05 s = 50 ms`
> 2.  **传输时间**:
>     `消息大小 = 5,000,000 字节 × 8 比特/字节 = 40,000,000 比特`
>     `时间 = 40,000,000 比特 / 1,000,000 bps = 40 s`

---

#### **13. 电磁频谱与无线传输 (Electromagnetic Spectrum & Wireless Transmission)**

*   **无线电信号 (Radio Signals)**: 通过电磁波发送信息。频率单位为赫兹 (Hertz)，以先驱海因里希·赫兹命名。
*   **无线传输分类**:
    *   **无线电波 (Radio waves)**: 3 kHz - 1 GHz，通常是全向的，可以穿墙。
    *   **微波 (Microwaves)**: 1 GHz - 300 GHz，是单向的，视距传播，不能穿墙。
    *   **红外线 (Infrared waves)**: 频率高，不能穿墙，用于短距离通信 (如遥控器)。

---

#### **14. 多路复用 (Multiplexing)**

*   **定义**: 通过单个通信信道同时传输两个或多个独立信号的过程。它增加了可以传输的信息量。
*   **原因**: 提高传输设施的利用率，降低成本。
*   **主要类型**:
    *   **频分多路复用 (FDM - Frequency-Division Multiplexing)**:
        *   一种 **模拟** 技术。
        *   将链路的总带宽划分为多个不重叠的频带，每个信号占用一个频带。
    *   **时分多路复用 (TDM - Time-Division Multiplexing)**:
        *   一种 **数字** 技术。
        *   多个连接共享链路的高带宽，每个连接被分配一个固定的时间片 (time slot)。
    *   **码分多路复用 (CDM - Code Division Multiplexing)**:
        *   多个用户在同一时间和同一频带上传输。
        *   每个用户被分配一个唯一的伪随机码序列，用于将其信号扩展到一个很宽的带宽上。
    *   **空分多路复用 (SDM - Space Division Multiplexing)**:
        *   将相同的频带分配给多个用户，但这些用户的信号在物理上被限制在不同的区域或区域内。