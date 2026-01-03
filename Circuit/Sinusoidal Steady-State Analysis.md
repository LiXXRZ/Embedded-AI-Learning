## 零、 数学基石：复数与欧拉公式 (Prerequisites)
*在正弦分析前，必须掌握的数学武器。*
1.  **复数的表达**：
    *   **直角坐标**：$A = a + jb$（用于加减法，$j$ 是虚数单位）。
    *   **极坐标**：$A = |A|\angle\theta$（用于乘除法）。其中 $|A| = \sqrt{a^2+b^2}$，$\theta = \arctan(b/a)$。
2.  **欧拉公式 (Euler's Identity)**：
    *   $e^{j\theta} = \cos\theta + j\sin\theta$。
    *   **推论**：$\cos\theta = \text{Re}[e^{j\theta}]$。这说明正弦量可以看作旋转复指数信号在实轴上的投影。

---

## 第一部分：正弦量的物理特性 (Slides 4-7)

### 1. 理论详解：三大要素
*   **数学表达式**：$v(t) = V_m \sin(\omega t + \theta)$。
*   **角频率 $\omega$**：单位 rad/s，$\omega = 2\pi f = 2\pi / T$。
*   **相位差 $\Phi_{12} = \theta_1 - \theta_2$**：
    *   $\Phi_{12} > 0$：$f_1$ 超前 (leads) $f_2$。
    *   $\Phi_{12} < 0$：$f_1$ 滞后 (lags) $f_2$。
    *   **比较前提**：①频率相同；②振幅为正；③函数统一（课件强调统一化为 cosine）。

---

## 第二部分：元件相位的微积分推导 (Slides 8-9)

### 【理论 + 例题 1】电容的相位关系 (Slide 8)
*   **已知条件**：电容两端电压 $v_C(t) = V_m \sin\omega t$。
*   **理论推导**：根据电容伏安关系 $i = C \frac{dv}{dt}$。
*   **计算过程**：$i_C = C \frac{d}{dt}(V_m \sin\omega t) = \omega C V_m \cos\omega t$。
*   **相位变换**：$\cos\omega t = \sin(\omega t + 90^\circ)$。
*   **结论**：$\theta_i = \theta_v + 90^\circ$。**电容电流超前电压 90°**。

### 【理论 + 例题 2】电感的相位关系 (Slide 9)
*   **已知条件**：通过电感电流 $i_L(t) = I_m \sin\omega t$。
*   **理论推导**：根据电感伏安关系 $v = L \frac{di}{dt}$。
*   **计算过程**：$v_L = L \frac{d}{dt}(I_m \sin\omega t) = \omega L I_m \cos\omega t$。
*   **相位变换**：$\cos\omega t = \sin(\omega t + 90^\circ)$。
*   **结论**：$\theta_v = \theta_i + 90^\circ$。**电感电压超前电流 90°**。

---

## 第三部分：有效值 (RMS) 与周期信号 (Slides 10-12)

### 1. 理论详解
*   **定义**：周期电流 $i$ 的有效值等于在相同电阻上产生同等热量的直流电流值。
*   **正弦量公式**：$I_{eff} = I_m / \sqrt{2} \approx 0.707 I_m$。
*   **周期信号级数展开 (Slide 10)**：若 $i = I_0 + I_{1m}\sin(\omega t + \theta_1) + I_{2m}\sin(2\omega t + \theta_2) + \dots$
    *   **总有效值**：$I_{eff} = \sqrt{I_0^2 + I_1^2 + I_2^2 + \dots}$，其中 $I_j$ 是各谐波分量的有效值。

### 2. 【例题 3】混合电流有效值计算 (Slide 12)
*   **题目 A**：220V, 50Hz AC。则有效值 $V_{eff} = 220V$，峰值 $V_m = 220\sqrt{2} \approx 311V$。
*   **题目 B**：已知电流 $i = 1 + 2\sin\omega t$ A。
    *   **分析**：包含直流分量 $I_0 = 1A$ 和正弦分量峰值 $I_{1m} = 2A$。
    *   **计算**：$I_{eff} = \sqrt{1^2 + (2/\sqrt{2})^2} = \sqrt{1 + 2} = \sqrt{3} A$。

---

## 第四部分：强制响应与相量的诞生 (Slides 13-16)

### 1. 理论详解：稳态响应
*   **暂态与稳态 (Slide 13)**：开关动作后，电路先经历暂态波动。本章只关注稳定后的正弦波。
*   **频率不变性**：线性电路在正弦激励下，稳态结果的频率 $\omega$ 不变，只需解出振幅和相位。

### 2. 【例题 4】时域微分方程的“苦劳” (Slide 14-15)
*   **已知**：$L=1, R=2, v_s = 10\cos t$。初始 $i(0)=1A$。
*   **步骤**：
    1. 列 KVL 方程：$i' + 2i = 10\cos t$。
    2. 设稳态特解：$i_f = A\cos t + B\sin t$。
    3. 代入求得系数：$A=4, B=2$。
    4. 结合全响应公式求得：$i(t) = -3e^{-2t} + 4\cos t + 2\sin t$。
*   **稳态部分结果**：$4\cos t + 2\sin t = 2\sqrt{5}\cos(t - 26.6^\circ)$。
*   **结论 (Slide 16)**：过程极其繁琐，引出**相量法**——一种将微积分方程降级为代数方程的工具。

---

## 第五部分：相量法核心工具 (Slides 17-26)

### 1. 转换理论 (Slide 19)
*   **时域 $\rightarrow$ 相量域**：$i(t) = I_m \cos(\omega t + \phi) \longleftrightarrow \dot{I}_m = I_m \angle \phi$。
*   **重要变换**：$\sin(\omega t + \phi) \rightarrow I_m \angle(\phi - 90^\circ)$。

### 2. 运算特性 (Slide 21)
*   **微分变换**：$\frac{di}{dt} \longleftrightarrow j\omega \dot{I}$。
*   **积分变换**：$\int i dt \longleftrightarrow \frac{\dot{I}}{j\omega}$。

### 3. 【例题 5】相量变换练习 (Slide 20)
*   $i_1(t) = 10\sin(\omega t - 60^\circ) \rightarrow \dot{I}_{m1} = 10 \angle -150^\circ A$。
*   $i_2(t) = 15\cos(314t + 57^\circ) \rightarrow \dot{I}_{m2} = 15 \angle 57^\circ A$。
*   $v(t) = 200\sin \omega t \rightarrow \dot{V}_m = 200 \angle -90^\circ V$。

### 4. 【例题 6】已知有效值相量求时域电压 (Slide 23)
*   **已知**：$\dot{V}_1 = 110, \dot{V}_2 = -55 - j95.5$。
*   **计算 $\dot{V}_2$ 极坐标**：模为 $\sqrt{55^2 + 95.5^2} = 110$，角为 $\arctan(-95.5/-55) = -120^\circ$。
*   **还原时域**：$v_2(t) = 110\sqrt{2}\cos(\omega t - 120^\circ) V$。

### 5. 【例题 7】相量加法应用 (Slide 24)
*   **求 $i_1 + i_2$**：$i_1 = 6\cos(\omega t + 30^\circ), i_2 = 4\cos(\omega t + 60^\circ)$。
*   **计算**：$\dot{I}_{m1} = 5.2 + j3$；$\dot{I}_{m2} = 2 + j3.5$。
*   **求和**：$\dot{I}_{m1} + \dot{I}_{m2} = 7.2 + j6.5 = 9.67 \angle 41.9^\circ$。
*   **还原**：$i_1 + i_2 = 9.67 \cos(\omega t + 41.9^\circ) A$。

### 6. 【例题 8】复数乘除法练习 (Slide 25)
*   已知 $\dot{V} = -55 + j95.5$，$\dot{I} = 2 + j3.5$。
*   **求 $\dot{V}/\dot{I}$**：利用极坐标 $(110.2\angle 120^\circ) / (4.03\angle 60^\circ) \approx 27.3\angle 60^\circ$。计算结果为 $j27.3$。
*   **求 $\dot{V}\dot{I}^*$**：利用共轭复数计算得出 $444j$。

---

## 第六部分：阻抗与导纳 (Slides 27-38)

### 1. 元件相量关系理论总结 (Slides 27-29, 32-35)
*   **电阻 R**：$Z_R = R$。电压电流同相。
*   **电感 L**：$Z_L = j\omega L$。电压超前电流 90°（感性网络虚部为正）。
*   **电容 C**：$Z_C = \frac{1}{j\omega C} = -j\frac{1}{\omega C}$。电流超前电压 90°（容性网络虚部为负）。
*   **导纳 Y**：$Y = 1/Z = G + jB$。并联电路中导纳直接相加。

### 2. 【例题 9】KVL 相量分析 (Slide 31)
*   **题目**：已知回路中三个元件电压 $v_1=5\cos(\omega t+\phi), v_2=-V_{2m}\sin\omega t, v_3=3\cos\omega t$。
*   **相量方程**：$5\angle \phi = \dot{V}_{2m} + 3\angle 0^\circ$。其中 $\dot{V}_{2m} = V_{2m}\angle 90^\circ = jV_{2m}$。
*   **列代数式**：$5\cos\phi + j5\sin\phi = 3 + jV_{2m}$。
*   **求解**：$5\cos\phi = 3 \implies \phi = 53.1^\circ$；$5\sin\phi = V_{2m} \implies V_{2m} = 4$。

### 3. 【例题 10】混合阻抗计算 (Slide 37)
*   **题目**：$60\Omega$ 电阻串联一个支路（$-j25\Omega$ 电容并联 $j20\Omega$ 电感）。
*   **计算并联部分**：$Z_p = \frac{(-j25)(j20)}{-j25 + j20} = \frac{500}{-j5} = j100 \Omega$。
*   **总阻抗**：$Z = 60 + j100 \Omega$。极坐标：$116.6 \angle 59^\circ \Omega$。

### 4. 理论：星角变换 (Slide 38)
*   **理论**：形式与直流电路完全相同，只需将电阻 $R$ 替换为阻抗 $Z$。

---

## 第七部分：正弦稳态综合分析技术 (Slides 39-44)

### 1. 【例题 11】相量法重解 RL 电路 (Slide 40)
*   **题目条件**：同例题 4。$\omega=1, \dot{V}_{sm}=10\angle 0^\circ$。
*   **阻抗分析**：$Z = R + j\omega L = 2 + j1 = \sqrt{5} \angle 26.6^\circ$。
*   **计算电流**：$\dot{I}_m = \dot{V}_{sm} / Z = (10\angle 0^\circ) / (\sqrt{5}\angle 26.6^\circ) = 2\sqrt{5} \angle -26.6^\circ$。
*   **结论**：一行算式解决微分方程两页纸的工作量。

### 2. 【例题 12】多支路复阻抗网络 (Slide 41-42)
*   **题目条件**：$\omega = 3000$，电源 $v_s = 40\sin 3000t$。元件有 $1.5k, 1k, 1/3H, 1/6\mu F$。
*   **相量转换**：$\dot{V}_{sm} = 40\angle -90^\circ$。$Z_L = j1k\Omega, Z_C = -j2k\Omega$。
*   **等效阻抗 $Z_{eq}$**：先求右侧并联支路 $Z_{right} = \frac{j1 \cdot (1 - j2)}{j1 + (1 - j2)} = \dots = 0.5 + j1.5 k\Omega$。
    *   总 $Z_{eq} = 1.5 + 0.5 + j1.5 = 2 + j1.5 = 2.5 \angle 36.9^\circ k\Omega$。
*   **求电流**：$\dot{I}_m = \frac{40\angle -90^\circ}{2.5\angle 36.9^\circ} = 16 \angle -126.9^\circ mA$。
*   **时域还原**：$i(t) = 16\cos(3000t - 126.9^\circ) mA$。

### 3. 【难题例题 13】参数设计题 (Slide 43)
*   **已知**：$v_1$ 频率为 $168kHz$，输入阻抗模长为 $100\sqrt{5}\Omega$，输出 $v_2$ 滞后输入 $60^\circ$。电路为 RC 串联，输出取自 C。
*   **方程 1 (模长)**：$R^2 + (1/\omega C)^2 = 50000$。
*   **方程 2 (相位)**：根据分压比 $\frac{1/j\omega C}{R + 1/j\omega C} = \frac{1}{1+j\omega CR}$。
    *   滞后 60° 代表分母角度为 60° $\implies \omega CR = \tan 60^\circ = \sqrt{3}$。
*   **求解**：联立得 $C \approx 8.5nF, R \approx 193.6\Omega$。

### 4. 【理论证明例题 14】移相桥电路 (Slide 44)
*   **题目**：证明 $V_{bd}$ 的相位在 $R$ 变化时范围为 $0^\circ \sim 180^\circ$。
*   **推导步骤**：
    1. 写出电位：$\dot{V}_b = \frac{1}{2}\dot{V}_1$（由等值电阻 $R_1, R_1$ 分压）。
    2. 写出电位：$\dot{V}_d = \frac{1/j\omega C}{R + 1/j\omega C}\dot{V}_1 = \frac{1}{1+j\omega CR}\dot{V}_1$。
    3. 求电压差 $\dot{V}_{bd} = \dot{V}_d - \dot{V}_b$。
    4. 整理得到相位项包含 $180^\circ - 2\arctan(\omega CR)$。
*   **结论**：当 $R=0$ 时相位差 $180^\circ$；当 $R\to\infty$ 时相位差 $0^\circ$。

---

## 八、 总结：考试必备思维 (Slide 46)
1.  **相量法**的核心是“一转（时域转相量）”、“二算（代数运算）”、“三回（还原时域）”。
2.  **$V = ZI$** 是交流下的欧姆定律，$Z$ 是频率的函数。
3.  **不同频率的电源**：这是全章唯一的“坑”。如果电路里有 50Hz 和 100Hz 两个电源，**严禁使用相量求和**。必须用叠加定理，对每一个频率画一个相量图，各自计算后，回到时域将 $f(t)$ 函数相加。