# 5 Boost 变换器笔记

## 一、这一讲的主线

Boost 变换器是升压型 DC-DC 变换器：

$$
V_o>V_d
$$

它的核心思想是：

> 开关导通时先把能量存入电感，开关关断时电源和电感一起向负载供能。

CCM 理想增益：

$$
\frac{V_o}{V_d}=\frac1{1-D}
$$

---

## 二、两种开关状态

### 1. 开关导通

开关 $S$ 导通时：

- 电感直接接在输入电源上；
- 二极管反偏；
- 负载主要由输出电容供电；
- 电感电流上升。

电感电压：

$$
v_L=V_d
$$

持续时间：

$$
DT_s
$$

电感电流上升量：

$$
\Delta i_{L,\mathrm{on}}
=\frac{V_dDT_s}{L}
$$

### 2. 开关关断

开关关断时：

- 电感电流不能突变；
- 电感电压反向；
- 输入源与电感串联，经二极管向负载供电；
- 电感电流下降。

电感电压：

$$
v_L=V_d-V_o
$$

由于 Boost 输出大于输入，所以该值为负。

持续时间：

$$
(1-D)T_s
$$

---

## 三、用伏秒平衡推导增益

稳态时：

$$
V_dDT_s+(V_d-V_o)(1-D)T_s=0
$$

约去 $T_s$：

$$
V_dD+V_d(1-D)-V_o(1-D)=0
$$

所以：

$$
V_d=V_o(1-D)
$$

得到：

$$
\frac{V_o}{V_d}=\frac1{1-D}
$$

---

## 四、电感电流纹波

由导通阶段：

$$
\Delta i_L=\frac{V_dDT_s}{L}
$$

写成频率形式：

$$
\Delta i_L=\frac{V_dD}{Lf_s}
$$

---

## 五、输出电容纹波

开关导通时，二极管截止，负载由输出电容供电。  
因此电容在导通时间内放电：

$$
\Delta Q\approx I_oDT_s
$$

所以：

$$
\Delta V_o\approx\frac{I_oD}{Cf_s}
$$

又因为：

$$
I_o=\frac{V_o}{R}
$$

可写为：

$$
\frac{\Delta V_o}{V_o}\approx\frac{D}{RCf_s}
$$

---

## 六、为什么 Boost 不能把 $D$ 调到 1

从理想公式：

$$
\frac{V_o}{V_d}=\frac1{1-D}
$$

看起来 $D\to1$ 时输出无限大。  
但实际不可能，因为：

- 电感电流会迅速增大；
- 开关和二极管有损耗；
- 电容有 ESR；
- 控制环和器件耐压有限；
- DCM/CCM 变化会影响增益。

所以实际 Boost 的占空比不能无限接近 1。

---

## 七、边界导通

Boost 中平均电感电流不是输出电流，而是输入电流。

功率近似守恒：

$$
V_dI_d\approx V_oI_o
$$

又有：

$$
V_o=\frac{V_d}{1-D}
$$

所以：

$$
I_L\approx I_d=\frac{I_o}{1-D}
$$

边界电感常写为：

$$
L_b=\frac{D(1-D)^2R}{2f_s}
$$

---

## 八、参数设计思路

### 1. 求占空比

由：

$$
V_o=\frac{V_d}{1-D}
$$

得到：

$$
D=1-\frac{V_d}{V_o}
$$

### 2. 按电感纹波选电感

$$
L=\frac{V_dD}{\Delta i_L f_s}
$$

### 3. 按输出纹波选电容

$$
C\approx\frac{I_oD}{\Delta V_o f_s}
$$

---

## 九、例题模板

已知：

$$
V_d,\quad V_o,\quad R,\quad f_s,\quad \Delta V_o
$$

### 第一步：求占空比

$$
D=1-\frac{V_d}{V_o}
$$

### 第二步：求输出电流

$$
I_o=\frac{V_o}{R}
$$

### 第三步：估算输入/电感平均电流

$$
I_L\approx\frac{I_o}{1-D}
$$

### 第四步：选 $L$ 与 $C$

$$
L=\frac{V_dD}{\Delta i_L f_s}
$$

$$
C=\frac{I_oD}{\Delta V_o f_s}
$$

### 第五步：检查器件应力

理想 Boost 中：

- 开关关断时承受约 $V_o$；
- 二极管反压约 $V_o$；
- 电感电流大于输出电流。

---

## 十、课件例题 7-B：Boost 参数和波形计算

题意：Boost 变换器工作于直流稳态，已知：

$$
V_{\mathrm{in}}=5\ \mathrm{V},\qquad V_o=12\ \mathrm{V}
$$

$$
P_o=10\ \mathrm{W},\qquad f_s=200\ \mathrm{kHz}
$$

电感电流纹波：

$$
\Delta i_L=2\ \mathrm{A}
$$

假设理想器件，求电感并描述主要波形。

### 第一步：求占空比

Boost 的 CCM 增益：

$$
\frac{V_o}{V_d}=\frac1{1-D}
$$

因此：

$$
D=1-\frac{V_d}{V_o}
$$

代入：

$$
D=1-\frac{5}{12}
=0.583
$$

### 第二步：求周期和导通时间

$$
T_s=\frac1{f_s}
=\frac1{200\times10^3}
=5\ \mu s
$$

$$
t_{\mathrm{on}}=DT_s
=0.583\times5
\approx2.917\ \mu s
$$

### 第三步：用纹波求电感

Boost 导通阶段：

$$
v_L=V_d=5\ \mathrm{V}
$$

电流上升量：

$$
\Delta i_L=\frac{V_dDT_s}{L}
$$

所以：

$$
L=\frac{V_dDT_s}{\Delta i_L}
$$

代入：

$$
L=\frac{5\times0.583\times5\times10^{-6}}{2}
\approx7.29\times10^{-6}\ \mathrm{H}
$$

即：

$$
L\approx7.3\ \mu\mathrm{H}
$$

### 第四步：求平均电流并判断 CCM

输出电流：

$$
I_o=\frac{P_o}{V_o}
=\frac{10}{12}
=0.833\ \mathrm{A}
$$

理想功率守恒：

$$
V_dI_d\approx V_oI_o=P_o
$$

所以输入平均电流，也就是电感平均电流：

$$
I_L\approx I_d=\frac{P_o}{V_d}
=\frac{10}{5}
=2\ \mathrm{A}
$$

电感电流上下限：

$$
I_{L,\max}=2+\frac{2}{2}=3\ \mathrm{A}
$$

$$
I_{L,\min}=2-\frac{2}{2}=1\ \mathrm{A}
$$

由于最小值仍大于零，所以确实为 CCM。

### 第五步：写电感电压波形

导通时：

$$
v_L=+5\ \mathrm{V}
$$

关断时：

$$
v_L=V_d-V_o=5-12=-7\ \mathrm{V}
$$

所以电感电流导通时线性上升，关断时线性下降。

### 第六步：写电容电流波形

导通时二极管截止，负载由电容供电：

$$
i_C=-I_o=-0.833\ \mathrm{A}
$$

关断时二极管导通，电容电流为：

$$
i_C=i_D-I_o
$$

关断开始附近：

$$
i_C\approx3-0.833=2.167\ \mathrm{A}
$$

关断结束附近：

$$
i_C\approx1-0.833=0.167\ \mathrm{A}
$$

这也解释了课件中电容电流从约 $2.167\ \mathrm{A}$ 降到约 $0.167\ \mathrm{A}$ 的波形。

---

## 十一、这一讲最容易错的点

1. Boost 中电感在输入侧，电感平均电流约等于输入电流，不等于输出电流；
2. 导通时负载靠电容供电；
3. 关断时输入和电感串联给负载供电，所以升压；
4. 占空比越大增益越高，但实际会受损耗和电流限制；
5. 输出电容纹波主要发生在开关导通阶段。

---

## 课件对齐补充：Boost 边界模式

Boost 的边界输出电流常写成：

$$
I_{oB}=\frac{V_oD(1-D)^2}{2Lf_s}
$$

也可写边界电感：

$$
L_b=\frac{D(1-D)^2R}{2f_s}
$$

判断方式：

$$
I_o>I_{oB}\Rightarrow \mathrm{CCM},
\qquad
I_o<I_{oB}\Rightarrow \mathrm{DCM}
$$

注意 Boost 中 $I_L\approx I_{in}$，不是 $I_o$。很多错误就是把输出电流直接当电感平均电流。

## 复习例题 7-1：要求 Boost 始终 DCM 时怎么选 $L$

题意：Boost 输出稳压 $V_o=48\ \mathrm{V}$，输入 $V_d=12\sim36\ \mathrm{V}$，最大输出功率 $120\ \mathrm{W}$，$f_s=50\ \mathrm{kHz}$，要求始终工作在 DCM，求可用的最大电感。

第一步，求最大输出电流：

$$
I_{o,\max}=\frac{120}{48}=2.5\ \mathrm{A}
$$

第二步，求占空比范围：

$$
D=1-\frac{V_d}{V_o}
$$

$$
V_d=12\ \mathrm{V}\Rightarrow D=0.75,
\qquad
V_d=36\ \mathrm{V}\Rightarrow D=0.25
$$

第三步，为保证最大功率时仍是 DCM，应让实际输出电流不超过边界电流。课件指出该范围内 $D=0.75$ 时 $I_{oB}$ 最小，所以取这个最坏点：

$$
L_{\max}=\frac{V_oD(1-D)^2}{2I_{o,\max}f_s}
$$

$$
L_{\max}=\frac{48\times0.75\times0.25^2}{2\times2.5\times50\times10^3}
=9\ \mu\mathrm{H}
$$

结论：若要进一步保证 DCM，应选小于 $9\ \mu\mathrm{H}$ 的电感。

## 复习例题：Boost 参数设计一题多问

题意：Boost，$V_d=18\ \mathrm{V}$，$V_o=30\ \mathrm{V}$，$f_s=20\ \mathrm{kHz}$，$P_o=180\ \mathrm{W}$。

第一步，占空比：

$$
D=1-\frac{18}{30}=0.4
$$

第二步，电容。若 $\Delta V_o/V_o<5\%$，则

$$
\Delta V_o<0.05\times30=1.5\ \mathrm{V}
$$

输出电流：

$$
I_o=\frac{180}{30}=6\ \mathrm{A}
$$

Boost 输出纹波近似：

$$
C\ge\frac{I_oD}{\Delta V_of_s}
=\frac{6\times0.4}{1.5\times20\times10^3}
=80\ \mu\mathrm{F}
$$

第三步，保证 $P_o\ge180\ \mathrm{W}$ 时 CCM 的最小电感。边界时取 $I_o=I_{oB}$：

$$
L_{\min}=\frac{V_oD(1-D)^2}{2I_of_s}
$$

$$
L_{\min}=\frac{30\times0.4\times0.6^2}{2\times6\times20\times10^3}
=18\ \mu\mathrm{H}
$$

严格 CCM 应选大于 $18\ \mu\mathrm{H}$；等于该值时是边界。

第四步，波形标注：

- 开关导通：$v_L=+18\ \mathrm{V}$，开关电压 $v_T\approx0$；
- 开关关断：$v_L=V_d-V_o=-12\ \mathrm{V}$，开关电压 $v_T\approx V_o=30\ \mathrm{V}$；
- $P_o=180\ \mathrm{W}$ 时输入/电感平均电流 $I_L\approx P_o/V_d=10\ \mathrm{A}$。

## 十二、考前速记

1. Boost 增益：

$$
\frac{V_o}{V_d}=\frac1{1-D}
$$

2. 占空比：

$$
D=1-\frac{V_d}{V_o}
$$

3. 电感纹波：

$$
\Delta i_L=\frac{V_dD}{Lf_s}
$$

4. 输出纹波：

$$
\frac{\Delta V_o}{V_o}\approx\frac{D}{RCf_s}
$$

5. 边界电感：

$$
L_b=\frac{D(1-D)^2R}{2f_s}
$$
