### Multiple Choice Questions and Answers | 选择题与答案

| # | Question (English) | Answer (English) | 问题 (中文) | 答案 (中文) |
|---|---|---|---|---|
| 1 | What is the main purpose of analog-to-digital conversion? | B) To convert analog data into digital signals | 模拟到数字转换的主要目的是什么？ | B) 将模拟数据转换为数字信号 |
| 2 | Which device is used to convert analog data to digital and vice versa? | C) Codec | 哪种设备用于将模拟数据转换为数字数据，反之亦然？ | C) 编解码器 |
| 3 | What is the Nyquist rate for a signal with a maximum frequency of 4000 Hz? | B) 8000 samples per second | 最大频率为 4000 Hz 的信号的奈奎斯特率是多少？ | B) 8000 样本/秒 |
| 4 | Which quantization method assigns the middle value of each zone as the quantized value? | C) Linear quantization | 哪种量化方法将每个区域的中间值指定为量化值？ | C) 线性量化 |
| 5 | In polar Non-Return-to-Zero Level (NRZ-L) encoding, what represents a binary 0? | A) Positive voltage | 在极性不归零电平 (NRZ-L) 编码中，什么代表二进制 0？ | A) 正电压 |
| 6 | What is the main disadvantage of Return-to-Zero (RZ) encoding? | A) Complexity and higher bandwidth requirements | 归零 (RZ) 编码的主要缺点是什么？ | A) 复杂性和更高的带宽要求 |
| 7 | Which encoding technique is specified for the IEEE 802.3 Ethernet standard? | C) Manchester encoding | IEEE 802.3 以太网标准指定了哪种编码技术？ | C) 曼彻斯特编码 |
| 8 | In digital transmission, what is the signal rate for NRZ-I with a data rate of 10 Mbps? | C) 10 Mbaud | 在数字传输中，数据速率为 10 Mbps 的 NRZ-I 的信号速率是多少？ | C) 10 Mbaud |
| 9 | Which transmission mode is most suitable for multimedia applications, such as audio and video? | D) Isochronous | 哪种传输模式最适合多媒体应用，例如音频和视频？ | D) 同步 |
| 10 | Which of the following describes block coding? | C) Divides bits into blocks for improved error detection | 以下哪项描述了块编码？ | C) 将比特分成块以改进错误检测 |
| 11 | In 4B/5B block coding, how many bits are used to replace every 4-bit input? | C) 5 | 在 4B/5B 块编码中，用多少位替换每个 4 位输入？ | C) 5 |
| 12 | What problem does 4B/5B block coding solve in NRZ-I encoding? | C) Long sequence of 0s causing synchronization issues | 4B/5B 块编码解决了 NRZ-I 编码中的什么问题？ | C) 长序列的 0 导致同步问题 |
| 13 | In delta modulation, what does a '1' bit indicate? | C) Increase in amplitude | 在增量调制中，“1”位表示什么？ | C) 幅度增加 |
| 14 | Which digital-to-digital encoding technique has no DC component and self-synchronizing capability? | C) Differential Manchester | 哪种数字到数字编码技术没有直流分量和自同步能力？ | C) 差分曼彻斯特 |

### Open-ended Questions and Answers | 开放式问题与答案

**1. Explain the difference between NRZ-L and NRZ-I.**

*   **NRZ-L (Non-Return-to-Zero Level):** The voltage level directly represents the bit value. For instance, a positive voltage can represent a '1', and a negative voltage can represent a '0'. The level of the voltage determines the bit's value.
*   **NRZ-I (Non-Return-to-Zero Invert):** A transition in the voltage level at the beginning of a bit interval represents a '1', while no transition represents a '0'. The inversion or lack of inversion of the voltage determines the bit's value.

**1. 解释 NRZ-L 和 NRZ-I 之间的区别。**

*   **NRZ-L (不归零电平):** 电压电平直接代表比特值。例如，正电压可以代表“1”，负电压可以代表“0”。电压的电平决定了比特的值。
*   **NRZ-I (不归零反相):** 在比特间隔开始处的电压电平的跳变代表“1”，而没有跳变则代表“0”。电压的反相或不反相决定了比特的值。

**2. Find the 8-bit data stream for each case depicted in the following figure. For differential Manchester, there is no transition at the beginning of the first bit.**

*   **a. NRZ-I:** 01100101
*   **b. Differential Manchester:** 10110010
*   **c. AMI:** 01001101

**2. 找出下图中每种情况的 8 位数据流。对于差分曼彻斯特编码，第一位开始时没有跳变。**

*   **a. NRZ-I:** 01100101
*   **b. 差分曼彻斯特:** 10110010
*   **c. AMI:** 01001101

**3. Consider a stream of binary data consisting of a long sequence of 1s followed by a zero followed by a long string of 1s, e.g., 11111011111. Assume that the most recent preceding bit 1 for AMI has a negative voltage; and the most recent preceding bit 0 for pseudoternary has a negative voltage. Draw the waveform for this sequence using:**

*   **a. NRZ-L:** The waveform will be at a high level for the first five '1's, then drop to a low level for the '0', and then go back to a high level for the remaining '1's.
*   **b. Bipolar-AMI:** The waveform will alternate between positive and negative voltages for each '1', with zero voltage for the '0'.
*   **c. Pseudoternary:** The waveform will be at zero voltage for each '1' and will alternate between positive and negative voltages for each '0'.

**3. 考虑一个二进制数据流，由一长串 1 后跟一个 0，再后跟一长串 1 组成，例如 11111011111。假设 AMI 的最近的前一个比特 1 具有负电压；伪三元码的最近的前一个比特 0 具有负电压。使用以下方法绘制此序列的波形：**

*   **a. NRZ-L:** 波形在前五个“1”期间将处于高电平，然后在“0”期间降至低电平，然后在剩余的“1”期间返回高电平。
*   **b. 双极性-AMI:** 波形将在每个“1”的正负电压之间交替，对于“0”则为零电压。
*   **c. 伪三元码:** 每个“1”的波形将为零电压，每个“0”的波形将在正负电压之间交替。

**4. From the waveforms you draw in Q3, think about the following questions:**

*   **a. Does NRZ-L have the synchronization problem? If so, when?** Yes, NRZ-L has a synchronization problem, especially during long sequences of '1's or '0's where there are no transitions in the signal.
*   **b. Does AMI have the synchronization problem? If so, when?** Yes, AMI can have a synchronization problem during a long sequence of '0's, as the signal remains at zero voltage.
*   **c. Does pseudoternary have the synchronization problem? If so, when?** Yes, pseudoternary can have a synchronization problem during a long sequence of '1's, as the signal remains at zero voltage.

**4. 根据您在问题 3 中绘制的波形，思考以下问题：**

*   **a. NRZ-L 是否存在同步问题？如果是，在什么时候？** 是的，NRZ-L 存在同步问题，尤其是在信号没有跳变的长序列“1”或“0”期间。
*   **b. AMI 是否存在同步问题？如果是，在什么时候？** 是的，AMI 在长序列的“0”期间可能会出现同步问题，因为信号保持为零电压。
*   **c. 伪三元码是否存在同步问题？如果是，在什么时候？** 是的，伪三元码在长序列的“1”期间可能会出现同步问题，因为信号保持为零电压。

**5. What are the processes of a PCM encoder?**

A PCM (Pulse Code Modulation) encoder follows three main processes:
*   **Sampling:** The continuous-time analog signal is converted into a discrete-time signal by taking samples at regular intervals.
*   **Quantization:** The amplitude of each sample is mapped to the nearest value within a finite set of discrete levels.
*   **Encoding:** The quantized values are then converted into a binary code.

**5. PCM 编码器的过程是什么？**

PCM（脉冲编码调制）编码器遵循三个主要过程：
*   **采样:** 通过以固定的时间间隔取样，将连续时间的模拟信号转换为离散时间的信号。
*   **量化:** 将每个采样的幅度映射到一组有限的离散电平中的最近值。
*   **编码:** 然后将量化的值转换为二进制代码。

**6. What is the Nyquist sampling rate for each of the following signals?**

*   **a. A low-pass signal with bandwidth of 200 KHz?** According to the Nyquist theorem, the sampling rate must be at least twice the highest frequency. For a low-pass signal, the bandwidth is the highest frequency. Therefore, the Nyquist rate is 2 * 200 KHz = 400 KHz.
*   **b. A band-pass signal with bandwidth of 200 KHz if the lowest frequency is 100 KHz?** For a band-pass signal, the highest frequency is the sum of the lowest frequency and the bandwidth, which is 100 KHz + 200 KHz = 300 KHz. Therefore, the Nyquist rate is 2 * 300 KHz = 600 KHz.

**6. 以下每种信号的奈奎斯特采样率是多少？**

*   **a. 带宽为 200 KHz 的低通信号？** 根据奈奎斯特理论，采样率必须至少是最高频率的两倍。对于低通信号，带宽即为最高频率。因此，奈奎斯特率为 2 * 200 KHz = 400 KHz。
*   **b. 如果最低频率为 100 KHz，带宽为 200 KHz 的带通信号？** 对于带通信号，最高频率是最低频率和带宽之和，即 100 KHz + 200 KHz = 300 KHz。因此，奈奎斯特率为 2 * 300 KHz = 600 KHz。

**7. Consider an audio signal with spectral components in the range 300 to 3000 Hz. Assume that a sampling rate of 7000 samples per second will be used to generate a PCM signal.**

*   **a. For SNR = 30 dB, what is the number of uniform quantization levels needed?** The formula relating SNR to the number of quantization levels (L) is SNR ≈ 6.02 * n, where n is the number of bits per sample and L = 2^n. First, we find n: 30 ≈ 6.02 * n, which gives n ≈ 5. Then, the number of levels is L = 2^5 = 32.
*   **b. What data rate is required?** The data rate is calculated as the sampling rate multiplied by the number of bits per sample. Data Rate = 7000 samples/second * 5 bits/sample = 35,000 bps or 35 Kbps.

**7. 考虑一个频谱分量在 300 到 3000 Hz 范围内的音频信号。假设将使用每秒 7000 个样本的采样率来生成 PCM 信号。**

*   **a. 对于信噪比 = 30 dB，需要多少个均匀量化级别？** 将信噪比与量化级别数 (L) 相关联的公式为 SNR ≈ 6.02 * n，其中 n 是每个样本的比特数，L = 2^n。首先，我们求 n：30 ≈ 6.02 * n，得出 n ≈ 5。然后，级别数为 L = 2^5 = 32。
*   **b. 需要什么数据速率？** 数据速率计算为采样率乘以每个样本的比特数。数据速率 = 7000 样本/秒 * 5 比特/样本 = 35,000 bps 或 35 Kbps。