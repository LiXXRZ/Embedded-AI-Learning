# 📚 高阶交流电路与正弦稳态分析 (极详笔记)

## 📌 核心知识框架
1. **复杂电路的相量分析法 (Phasor Analysis for Complex Circuits)**
2. **交流电路功率分析 (AC Circuit Power Analysis)**
3. **最大功率传输定理 (Maximum Power Transfer)**
4. **三相电路 (Three-phase Circuit)** *(注：本次课件仅在目录提及，未展开)*

---

## 模块一：基础知识回顾 (Review: Sinusoidal Signal and Phasor)

### 1. 正弦信号与相量的表达 (Expressions of a Phasor)
对于时域正弦信号：$i(t) = I_m \cos(\omega t + \varphi)$，其对应的相量形式（表示为 $\dot{I}_m$）有三种表达：
*   **指数形式 (Exponential form)**: $\dot{I}_m = I_m e^{j\varphi}$
*   **极坐标形式 (Polar form)**: $\dot{I}_m = I_m \angle \varphi$
*   **直角坐标形式 (Rectangular form)**: $\dot{I}_m = I_m \cos\varphi + j I_m \sin\varphi$

> ⚠️ **重要转换提示**：如果给定的时域信号是正弦函数 $\sin$，需要先转为余弦函数 $\cos$ 再提相量：
> $I_m \sin(\omega t + \varphi) \iff \dot{I}_m = I_m \angle (\varphi - 90^\circ) = -j I_m \angle \varphi$

### 2. 阻抗 (Impedance, Z) 与 导纳 (Admittance, Y)
定义：$Z = \frac{\dot{V}}{\dot{I}}$， $Y = \frac{\dot{I}}{\dot{V}} = \frac{1}{Z}$
*   **电阻 (Resistor)**: $Z_R = R$, $Y_R = \frac{1}{R}$
*   **电感 (Inductor)**: $Z_L = j\omega L$, $Y_L = \frac{1}{j\omega L}$ （电压超前电流90°）
*   **电容 (Capacitor)**: $Z_C = \frac{1}{j\omega C}$, $Y_C = j\omega C$ （电流超前电压90°）

基尔霍夫定律（KCL, KVL）在频域（相量域）同样成立：$\sum \dot{I}_k = 0$, $\sum \dot{V}_k = 0$。

---

## 模块二：稳态交流电路的相量分析法 (Phasor Analysis)

### 1. 适用条件与分析工具
*   **适用条件**：由**单一频率**激励的线性稳态交流电路。
*   **分析工具**：直流电路中的所有定律（欧姆定律、基尔霍夫定律）和分析方法（节点分析法、网孔分析法、叠加定理、戴维宁定理等）**均适用于交流相量分析**。
*   **辅助工具**：可使用**相量图 (Phasor Diagram)** 辅助判断电压电流的相位关系（超前 Leading / 滞后 Lagging）。

### 2. 标准解题三步曲 (Steps for Analysis)
1.  **转换 (Transform)**：将电路从时间域 $t$ 转换为相量/频率域 $\omega$（电源化为相量，元件化为阻抗 $Z$）。
2.  **求解 (Solve)**：应用电路分析技术（节点、网孔等）求出未知相量。
3.  **逆转换 (Inverse Transform)**：将求得的相量结果转换回时间域表达式。

### 3. 典型分析法示例
#### ① 节点分析法 / 网孔分析法 (Nodal / Mesh Analysis)
*   **要点**：列写KCL或KVL方程时，全盘使用复数（实部+虚部）。
*   **解题技巧**：涉及受控源时，先把受控变量用节点电压或网孔电流表示出来，然后代入方程组求解。

#### ② 戴维宁与诺顿等效电路 (Thevenin and Norton Equivalent)
用于将复杂的交流网络简化为一个电压源 $\dot{V}_{OC}$ 和一个串联阻抗 $Z_0$。
*   **求开路电压 $\dot{V}_{OC}$**：直接求端口断开时的电压。
*   **求等效阻抗 $Z_0$**：
    *   *常规法*：$Z_0 = \frac{\dot{V}_{OC}}{\dot{I}_{SC}}$ （求开路电压和短路电流之比）。
    *   *外加测试源法 (Alternative Method)*：将所有独立源置零（电压源短路、电流源开路），在端口处加上测试电压源 $\dot{V}_{eff} = 1V$，求流入的电流 $\dot{I}_{eff}$，则 $Z_0 = \frac{\dot{V}_{eff}}{\dot{I}_{eff}}$。

#### ③ 理想运放交流电路 (Op-Amp AC Circuits)
*   **核心法则**：**虚断** $i^+ = i^- = 0$ ； **虚短** $v^+ = v^-$。
*   **应用实例 (移相器 Phase Shifter)**：利用电容和电阻配置反馈网络，在不改变信号幅值的前提下，使输出信号相角产生偏移（如课件中将15cos(2000t) 转换为 2cos(2000t-90°)的设计）。

---

## 模块三：交流电路功率分析 (AC Circuit Power Analysis)

本章是交流电路的**核心重难点**，必须搞清各个功率分量的定义和换算。

### 1. 瞬时功率与平均功率 (Instantaneous and Average Power)
*   **瞬时功率 $p(t)$**：$p(t) = v(t) \cdot i(t)$
    *   反映任意时刻元件吸收能量的速率。难以直接测量。
*   **平均功率 $P$ (也称有功功率 Active Power)**：单位：**瓦特 (W)**
    *   定义：瞬时功率在一个周期内的平均值。$P = \frac{1}{T}\int_0^T p(t)dt$
    *   **电阻 $R$**：$P = \frac{1}{2}R I_m^2 = R I_{eff}^2 = \frac{V_{eff}^2}{R}$
    *   **电感 $L$、电容 $C$**：不消耗有功功率，$P = 0$。
    *   **一般公式**：$P = V_{eff} I_{eff} \cos(\theta_v - \theta_i) = V_{eff} I_{eff} \cos\varphi_Z$

### 2. 无功功率 (Reactive Power, $Q$)
反映电感和电容与电源进行能量交换的规模（不消耗，只交换）。单位：**乏 (Var)**。
*   **定义**：电感/电容瞬时功率的最大值。
*   **电感 $L$**：$Q_L = X_L I_{eff}^2 = \omega L I_{eff}^2 \ge 0$ （吸收正的无功）
*   **电容 $C$**：$Q_C = X_C I_{eff}^2 = -\frac{1}{\omega C} I_{eff}^2 \le 0$ （吸收负的无功 / 提供正无功）

### 3. 视在功率与功率因数 (Apparent Power & Power Factor)
*   **视在功率 $S$**：$S = V_{eff} I_{eff}$。单位：**伏安 (VA)**。
*   **功率因数 $pf$**：$pf = \frac{P}{S} = \cos\varphi_Z = \cos(\theta_v - \theta_i)$
    *   $\varphi_Z = \theta_v - \theta_i$ 称为**阻抗角/功率因数角**。
    *   **容性负载 (Capacitive)**：$\varphi_Z < 0$，电流超前电压，称为**超前功率因数 (Leading pf)**。
    *   **感性负载 (Inductive)**：$\varphi_Z > 0$，电流滞后电压，称为**滞后功率因数 (Lagging pf)**。
    *   **纯阻性 (Resistive)**：$\varphi_Z = 0$, $pf = 1, S = P$。

### 4. 复功率 (Complex Power, $\dot{S}$) —— 最强有力的计算工具
为了用一个式子同时包容 $P$ 和 $Q$，引入复功率（基于有效值相量推导）：
$$ \dot{S} = \dot{V}_{eff} \dot{I}_{eff}^* = (R + jX)I_{eff}^2 = P + jQ $$
*(注：$\dot{I}_{eff}^*$ 为电流相量的共轭复数)*
*   实部：$P = \text{Re}[\dot{S}] = V_{eff}I_{eff} \cos\varphi_Z$
*   虚部：$Q = \text{Im}[\dot{S}] = V_{eff}I_{eff} \sin\varphi_Z$
*   模长：$|\dot{S}| = S = \sqrt{P^2 + Q^2}$

### 5. 交流功率守恒 (Conservation of AC Power)
无论电路元件是串联还是并联，复功率在全电路中守恒：
$$ \dot{S}_{总} = \sum \dot{S}_k $$
$$ P_{总} = \sum P_{R_k} $$
$$ Q_{总} = \sum Q_L - \sum |Q_C| $$

> ⚠️ **避坑指南（Power Analysis Note）**：
> 求某部分阻抗 $Z$ 消耗的平均功率时，$P \neq \frac{V_{eff\_total}^2}{R}$。正确的做法是：$P = I_{eff}^2 R$ 或求出 $P = \text{Re}[\dot{V} \cdot \dot{I}^*]$。切勿将总电压直接套用到纯电阻的公式里。

---

## 模块四：功率因数校正 (Power Factor Correction)

**核心痛点**：大多数工业负载（如电动机）是感性的，导致电流滞后于电压（Lagging pf），产生大量的无功功率 $Q_L$，导致视在功率 $S$ 增大，增加电网负担和线路损耗。

**解决策略**：在负载两端**并联电容器 (Parallel C)**。
*   原理：电容提供容性无功功率 ($Q_C < 0$) 去抵消负载的感性无功功率 ($Q_L > 0$)。
*   效果：
    *   总有功功率 $P$ 保持不变（电容不耗能）。
    *   总无功功率 $Q_{new} = Q_{old} - |Q_C|$ 下降。
    *   总视在功率 $S_{new}$ 下降，总电流降低。
    *   功率因数 $\cos\varphi$ 提高（向1逼近）。

---

## 模块五：最大功率传输定理 (Maximum Power Transfer)

讨论如何配置负载阻抗 $Z_L$，使得从包含内阻的电源（或戴维宁等效电路，内阻 $Z_S = R_S + jX_S$）中提取最大的有功功率 $P$。
设负载阻抗为 $Z_L = R_L + jX_L$。负载获得的有功功率为：
$$ P = I_{eff}^2 R_L = \frac{V_{S(eff)}^2 R_L}{(R_S + R_L)^2 + (X_S + X_L)^2} $$

### 常见考法：两类匹配条件

#### 情况 1：共轭匹配 (Conjugate Match) —— (负载电阻、电抗均可调)
*   **匹配条件**：**$Z_L = Z_S^*$** （即 $R_L = R_S$, $X_L = -X_S$）。虚部完全抵消呈纯阻性。
*   **最大功率计算**：
    $$ P_{max} = \frac{V_{S(eff)}^2}{4R_S} = \frac{V_{OC(m)}^2}{8R_0} $$
    *(注：公式分子若是有效值用4倍分母，若是最大幅值用8倍分母)*

#### 情况 2：模值匹配 (Magnitude Match) —— (负载阻抗角 $\varphi$ 固定，仅模值 $|Z_L|$ 可调)
*   **适用场景**：例如扬声器（阻抗相角由物理特性决定），只能选择不同欧姆数值的型号。
*   **匹配条件**：**$|Z_L| = |Z_S|$** 
*   **求解逻辑**：通过对 $|Z_L|$ 求导数令偏导为0得到。此时获取的功率虽然是该条件下的最大值，但必定**小于**共轭匹配时的绝对最大值。

---
**复习建议 (To-Do based on page 36)**:
*   熟练掌握相量向时域的反向变换，千万别忘了把 $\omega$ 写对。
*   计算功率时，一定要分辨题目给出的是有效值 (rms / $V_{eff}$) 还是幅值 ($V_m$)。若给定 $v(t)=311\cos(314t)$，则 $V_m=311$；如果单独标 $V=220V$，一般指有效值。
*   请独立完成课件末尾布置的习题 (Prob. 1-1 到 1-11) 以巩固计算熟练度。尤其是复数运算（极坐标和直角坐标的互相转换）。