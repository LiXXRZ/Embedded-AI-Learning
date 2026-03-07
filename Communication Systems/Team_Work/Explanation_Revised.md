没问题，同学。别紧张，这个作业的核心其实就是在 Simulink 里像搭积木一样，把公式 $s(t) = [A + m(t)] \times \cos(2\pi f_c t)$ 摆出来。

既然你不想写代码，我们就**完全在 Simulink 界面里操作**。请打开 MATLAB，点击 Simulink 按钮，新建一个 **Blank Model（空白模型）**，然后保存文件名为 `AM_System_GroupXX.slx`。

我们分 4 步走，每一步我都告诉你**找什么模块（Block）**，**怎么连线**，以及**参数怎么填**。

---

### 第一步：搭建发射机（AM Modulator）—— 对应 Part A

我们要造出 AM 信号。根据作业要求，**不能**用现成的 AM Modulator 模块，要用加法和乘法拼出来。

**1. 找齐这 5 个积木（在 Library Browser 里搜名字拖进去）：**
*   **Sine Wave** (作为你的信号 $m(t)$)
*   **Constant** (作为直流分量 $A_c$，防止过调制)
*   **Add** (加法器)
*   **Sine Wave** (作为载波 $c(t)$，注意这是第二个 Sine Wave)
*   **Product** (乘法器)
*   **Slider Gain**（拖一个）这是作业里的加分项，用来演示调节。双击，Low 填 0，High 填 2。把滑块拖到中间 1 的位置。

**2. 设置参数（双击模块修改）：**
*   **Sine Wave (信号):**
    *   Frequency (rad/sec): 填 `2*pi*5` (题目要求的 5Hz)
    *   Amplitude: 填 `1`
    *   Sample time: 填 `0.0001` (这点很重要，保证波形圆滑)
    *   *建议改名为 "Message Signal"*
*   **Constant:**
    *   Constant value: 填 `2` (必须比信号幅度大，不然解调会失真)
*   **Sine Wave (载波):**
    *   Frequency (rad/sec): 填 `2*pi*1000` (题目要求的 1kHz)
    *   Sample time: 填 `0.0001`
    *   *建议改名为 "Carrier Signal"*

**3. 连线操作：**
1.  把 **Message Signal** 连到 **Slider Gain** ，与 **Constant** 连到 **Add** 模块的两个输入端。
2.  把 **Add** 的输出连到 **Product** 的第一个输入端。
3.  把 **Carrier Signal** 连到 **Product** 的第二个输入端。
4.  **Product** 的输出就是你的 **AM 信号**了。

---

### 第二步：加入噪声通道 —— 对应 Part C

在信号传输过程中加点干扰。

**1. 找积木：**
*   **AWGN Channel**

**2. 设置参数：**
*   Mode: 选择 `Signal to noise ratio (SNR)`
*   SNR (dB): 先填 `20` (这个数字之后你要手动改，用来做测试)
*   Input Signal Power: 填 `referenced to 1 ohm` (简单处理)

**3. 连线操作：**
1.  把刚才 **Product** (AM 信号) 的输出连到 **AWGN Channel** 的输入。

---

### 第三步：搭建接收机（Demodulator）—— 对应 Part B

我们要把信号从高频载波里取出来。方法是：**整流（取绝对值） + 滤波（平滑）**。

**1. 找积木：**
*   **Abs** (绝对值，起到整流作用)
*   **Analog Filter Design** (滤波器)
*   **Subtract** 减法器（用来去直流）
    **Constant** 再拖一个新的（用来设定减去多少）
*   **Gain** 普通增益（三角形图标，用来把变小的信号放大）

**2. 设置参数：**
*   **Analog Filter Design:**
    *   Design Method: `Butterworth`
    *   Filter Type: `Lowpass` (低通)
    *   Filter Order: `2` (二阶就够了)
    *   Passband Edge Frequency (rad/s): 填 `2*pi*50`
        *   *解释：* 信号是 5Hz，载波是 1000Hz。我们要留住 5Hz，干掉 1000Hz，所以选个中间值 50Hz。
*   **Constant:** （先填 `1.2`，等会儿要调）
*   **Gain:** 把 `1` 改成 `1.6`（这也是估算的，等会儿微调）   

**3. 连线操作：**
1.  把 **AWGN Channel** 的输出连到 **Abs** 的输入。
2.  把 **Abs** 的输出连到 **Analog Filter Design** 的输入。
3.  **Analog Filter Design** 的输出就是 **解调后的信号 (Demodulated Signal)**。
4.  去直流： 滤波器的出口 -> 连到 Subtract 的 + 号口。
5.  新建那个 Constant 连到 Subtract 的 - 号口。
6.  放大： Subtract 的出口 -> 连到 Gain。此时，Gain 的出口就是最终解调出来的信号
---

### 第四步：观察与算分（可视化与 MSE）—— 对应 Part D

这步是为了生成作业报告里的图和数据。

**1. 找积木：**
*   **Scope** (示波器，看波形)
*   **Spectrum Analyzer** (频谱仪，看频率)
*   **Sum** (用来算误差)
*   **Math Function** (用来做平方)
*   **Mean** (算平均值，在 DSP System Toolbox -> Statistics 下，或者搜 "Mean")
*   **Display** (直接显示数字)

**2. 连线与设置（比较复杂，慢慢来）：**

*   **看波形 (Scope):**
    *   拖一个 Scope，双击它，在左上角齿轮图标里把 "Number of input ports" 改成 3。
    *   输入 1 连：最开始的 **Message Signal**。
    *   输入 2 连：中间的 **AWGN Channel** 输出 (看带噪声的 AM)。
    *   输入 3 连：最后的 **解调信号**。
    *   *运行后，点击 Scope 上面的“望远镜”图标自动缩放，截图就是作业的 Waveform 图。*

*   **看频谱 (Spectrum Analyzer):**
    *   直接连在 **Product** 输出或者 **Demodulator** 输出上，运行就能看到频谱图。

*   **算 MSE (均方误差):**
    *   逻辑：MSE = 平均值( (原信号 - 解调信号)^2 )
    *   **Sum 模块:** 双击把图标改成 `|+ -|` (减法)。
        *   正端 (+) 连 **Message Signal**。
        *   负端 (-) 连 **解调信号**。
    *   **Math Function:** 连在 Sum 后面，功能选 `square` (平方)。
    *   **Mean:** 连在平方后面。
    *   **Display:** 连在 Mean 后面。
    *   *注意：由于滤波器有延迟，这里的 MSE 不会完全是 0，只要数值比较小（比如 0.x 或 0.0x）且随 SNR 变大而变小就算成功。*

---


### 第五步：关键调试（让波形重合）

现在模型搭好了，但必须“校准”才能拿满分。

1.  点击上方绿色的 **Run** 按钮。
2.  双击打开 **Scope**，点击上方的“放大镜”图标（Autoscale）。
3.  观察 **第1条黄线（原始）** 和 **第3条黄线（解调）**。
    *   **情况 A：第3条线不在 0 轴附近（偏上或偏下）。**
        *   *解决：* 去改接收机里那个 `Subtract` 下面的 `Constant`。如果波形偏上，就把 1.2 改大点（比如 1.25）；偏下就改小点。
    *   **情况 B：第3条线幅度太小（比第1条扁）。**
        *   *解决：* 去改接收机最后的 `Gain`。如果扁了，就把 1.6 改成 1.7 或 1.8。
4.  **反复 Run 和 微调**，直到第1条线和第3条线看起来**几乎重合**（虽然会有左右一点点错位，那是正常的）。

---

### 🟢 第七步：抄数据写报告

调好之后，不要动参数了，开始做实验。

1.  **做实验：**
    *   去 **AWGN** 模块，把 SNR 改成 `0` -> Run -> 抄下 Display 的数字。
    *   把 SNR 改成 `10` -> Run -> 抄下数字。
    *   把 SNR 改成 `20` -> Run -> 抄下数字。
    *   把 SNR 改成 `30` -> Run -> 抄下数字。

2.  **画图表：**
    *   打开 MATLAB 主界面，新建 Script，把下面代码复制进去，填入你刚才抄的 4 个数字。
    *   运行代码，就会弹出一张漂亮的折线图，截图贴到报告里。

```matlab
% === 只需要改这里的数据 ===
snr = [0, 10, 20, 30]; 
mse = [0.152, 0.045, 0.012, 0.003]; % 把这行换成你自己 Display 显示的真实数字

% === 下面是自动画图 ===
figure('Color','w');
plot(snr, mse, 'b-o', 'LineWidth', 2, 'MarkerFaceColor', 'b');
grid on; xlabel('SNR (dB)'); ylabel('MSE');
title('MSE vs SNR Analysis');
```

---