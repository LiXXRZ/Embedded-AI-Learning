# 6 Buck-Boost 变换器笔记

## 一、这一讲的主线

基本 Buck-Boost 变换器既可以降压，也可以升压，  
但它的输出极性与输入相反。

理想 CCM 下：

$$
\frac{V_o}{V_d}=-\frac{D}{1-D}
$$

如果只看幅值：

$$
\frac{\lvert V_o\rvert}{V_d}=\frac{D}{1-D}
$$

---

## 二、为什么叫 Buck-Boost

当：

$$
D<0.5
$$

则：

$$
\lvert V_o\rvert<V_d
$$

表现为降压。

当：

$$
D>0.5
$$

则：

$$
\lvert V_o\rvert>V_d
$$

表现为升压。

当：

$$
D=0.5
$$

则：

$$
\lvert V_o\rvert=V_d
$$

---

## 三、两种开关状态

### 1. 开关导通

开关导通时：

- 输入电源给电感充电；
- 二极管反偏；
- 输出负载由电容供电；
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
\Delta i_{L,\mathrm{on}}=\frac{V_dDT_s}{L}
$$

### 2. 开关关断

开关关断时：

- 电感电流不能突变；
- 电感极性反转；
- 二极管导通；
- 电感向电容和负载释放能量。

若按输出电压 $V_o$ 为负来写，电感电压可写成：

$$
v_L=V_o
$$

由于 $V_o<0$，电感电流下降。

持续时间：

$$
(1-D)T_s
$$

---

## 四、用伏秒平衡推导增益

稳态时：

$$
V_dDT_s+V_o(1-D)T_s=0
$$

约去 $T_s$：

$$
V_dD+V_o(1-D)=0
$$

得到：

$$
V_o=-\frac{D}{1-D}V_d
$$

所以：

$$
\frac{V_o}{V_d}=-\frac{D}{1-D}
$$

---

## 五、电感电流纹波

导通阶段：

$$
\Delta i_L=\frac{V_dDT_s}{L}
$$

写成频率形式：

$$
\Delta i_L=\frac{V_dD}{Lf_s}
$$

---

## 六、输出电容纹波

开关导通时，负载由电容供电。  
因此与 Boost 类似：

$$
\Delta V_o\approx\frac{I_oD}{Cf_s}
$$

或：

$$
\frac{\Delta V_o}{\lvert V_o\rvert}\approx\frac{D}{RCf_s}
$$

---

## 七、边界导通条件

Buck-Boost 中输出电流不是电感平均电流。  
在关断阶段，电感才向输出侧供能。

边界模式下：

$$
I_{L,\mathrm{avg}}=\frac{\Delta i_L}{2}
$$

输出平均电流近似为关断区间内电感电流的平均贡献：

$$
I_o=(1-D)I_{L,\mathrm{avg}}
$$

可得到边界电感：

$$
L_b=\frac{(1-D)^2R}{2f_s}
$$

---

## 八、DCM 下为什么更麻烦

DCM 下一个周期分三段：

1. 开关导通，电感电流从零上升；
2. 开关关断，电感电流下降到零；
3. 电感电流为零，负载由电容供电。

此时电压增益不再只由 $D$ 决定，还与：

- $L$；
- $R$；
- $f_s$

有关。

---

## 九、参数设计模板

已知：

$$
V_d,\quad V_o,\quad R,\quad f_s,\quad \Delta i_L
$$

### 第一步：只看幅值求占空比

由：

$$
\frac{\lvert V_o\rvert}{V_d}=\frac{D}{1-D}
$$

得：

$$
D=\frac{\lvert V_o\rvert}{V_d+\lvert V_o\rvert}
$$

### 第二步：求输出电流

$$
I_o=\frac{\lvert V_o\rvert}{R}
$$

### 第三步：估算电感平均电流

由于输出只在关断阶段由电感提供：

$$
I_L\approx\frac{I_o}{1-D}
$$

### 第四步：选电感

$$
L=\frac{V_dD}{\Delta i_L f_s}
$$

### 第五步：检查 CCM

$$
I_L>\frac{\Delta i_L}{2}
$$

---

## 十、课件例题 7-2：先判断模式，再求占空比

题意：Buck-Boost 变换器，已知：

$$
f_s=20\ \mathrm{kHz},\qquad L=0.05\ \mathrm{mH}
$$

$$
V_d=15\ \mathrm{V},\qquad \lvert V_o\rvert=10\ \mathrm{V}
$$

输出功率：

$$
P_o=10\ \mathrm{W}
$$

求占空比 $D$。

### 第一步：求输出电流

$$
I_o=\frac{P_o}{\lvert V_o\rvert}
=\frac{10}{10}
=1\ \mathrm{A}
$$

周期：

$$
T_s=\frac1{f_s}
=\frac1{20\times10^3}
=50\ \mu s
$$

### 第二步：不要急着套 CCM 公式

如果先假设 CCM，则：

$$
\frac{\lvert V_o\rvert}{V_d}
=\frac{D}{1-D}
$$

$$
\frac{10}{15}
=\frac{D}{1-D}
$$

解得：

$$
D_{\mathrm{CCM}}=\frac{10}{15+10}=0.4
$$

但是这只是 CCM 下的占空比，必须检查是否真的连续导通。

### 第三步：计算边界输出电流

Buck-Boost 边界模式下，电感峰值为：

$$
I_{L,\mathrm{pk}}=\frac{V_dDT_s}{L}
$$

边界时关断区间持续约为 $(1-D)T_s$，输出电流是二极管电流三角波的平均值：

$$
I_{oB}
=\frac12 I_{L,\mathrm{pk}}(1-D)
$$

代入：

$$
I_{oB}
=\frac12\cdot\frac{V_dDT_s}{L}\cdot(1-D)
$$

用 $D=0.4$ 检查：

$$
I_{oB}
=\frac12\cdot
\frac{15\times0.4\times50\times10^{-6}}{0.05\times10^{-3}}
\cdot0.6
$$

先算电感峰值：

$$
I_{L,\mathrm{pk}}
=\frac{15\times0.4\times50\times10^{-6}}{50\times10^{-6}}
=6\ \mathrm{A}
$$

所以：

$$
I_{oB}
=\frac12\times6\times0.6
=1.8\ \mathrm{A}
$$

实际输出电流：

$$
I_o=1\ \mathrm{A}<I_{oB}=1.8\ \mathrm{A}
$$

因此电路实际工作在 DCM，不能用 $D=0.4$。

### 第四步：用 DCM 关系求 $D$

DCM 下，电感电流从零开始上升：

$$
I_{L,\mathrm{pk}}=\frac{V_dDT_s}{L}
$$

关断阶段电感电压幅值为 $\lvert V_o\rvert$，所以电流下降时间占比：

$$
D_2=\frac{V_d}{\lvert V_o\rvert}D
$$

输出电流等于关断阶段二极管三角波平均值：

$$
I_o=\frac12 I_{L,\mathrm{pk}}D_2
$$

代入：

$$
I_o
=\frac12
\left(\frac{V_dDT_s}{L}\right)
\left(\frac{V_d}{\lvert V_o\rvert}D\right)
$$

整理：

$$
I_o
=\frac{V_d^2D^2T_s}{2L\lvert V_o\rvert}
$$

因此：

$$
D=\sqrt{\frac{2L\lvert V_o\rvert I_o}{V_d^2T_s}}
$$

代入：

$$
D=\sqrt{
\frac{2\times50\times10^{-6}\times10\times1}
{15^2\times50\times10^{-6}}
}
$$

$$
D=\sqrt{0.0889}
\approx0.298
$$

所以本题正确占空比约为：

$$
D\approx0.30
$$

这个例题最重要的不是数值，而是步骤：先用 CCM 公式试算，再用边界电流判断模式，最后按实际模式求解。

---

## 十一、与 Buck 和 Boost 的比较

| 电路 | 输出极性 | CCM 增益 |
| :--- | :--- | :--- |
| Buck | 同极性 | $D$ |
| Boost | 同极性 | $\frac1{1-D}$ |
| Buck-Boost | 反极性 | $-\frac{D}{1-D}$ |

---

## 十二、这一讲最容易错的点

1. Buck-Boost 输出反相；
2. 电感导通时储能，关断时向输出放能；
3. 输出电容在导通阶段独自供电；
4. 电感平均电流不等于输出电流；
5. $D=0.5$ 只是幅值相等，不是输出极性相同。

---

## 课件对齐补充：边界输出电流

Buck-Boost 的边界输出电流可写成：

$$
I_{oB}=\frac{|V_o|(1-D)^2}{2Lf_s}
$$

对应边界电感：

$$
L_b=\frac{(1-D)^2R}{2f_s}
$$

判断时仍然是：

$$
I_o>I_{oB}\Rightarrow \mathrm{CCM},
\qquad
I_o<I_{oB}\Rightarrow \mathrm{DCM}
$$

它和 Boost 的边界式很像，但少了一个 $D$。原因是 Buck-Boost 的输出只在关断区间由电感供能。

## 复习例题 7-C：Buck-Boost 参数和波形

题意：$V_d=14\ \mathrm{V}$，$|V_o|=42\ \mathrm{V}$，$P_o=21\ \mathrm{W}$，$\Delta i_L=2\ \mathrm{A}$，$f_s=200\ \mathrm{kHz}$。

第一步，占空比：

$$
D=\frac{|V_o|}{V_d+|V_o|}
=\frac{42}{14+42}=0.75
$$

周期与导通时间：

$$
T_s=5\ \mu s,
\qquad
T_{on}=DT_s=3.75\ \mu s
$$

第二步，电感：

$$
L=\frac{V_dDT_s}{\Delta i_L}
=\frac{14\times3.75\times10^{-6}}{2}
=26.25\ \mu\mathrm{H}
$$

第三步，平均电流：

$$
I_o=\frac{21}{42}=0.5\ \mathrm{A},
\qquad
I_{in}=\frac{21}{14}=1.5\ \mathrm{A}
$$

Buck-Boost 中电感平均电流近似为：

$$
I_L=I_{in}+I_o=2\ \mathrm{A}
$$

因此：

$$
I_{L,\max}=3\ \mathrm{A},
\qquad
I_{L,\min}=1\ \mathrm{A}
$$

第四步，波形：

- 导通时：$v_L=+14\ \mathrm{V}$，二极管电流为 0，电容电流 $i_C=-I_o=-0.5\ \mathrm{A}$；
- 关断时：$v_L=-|V_o|=-42\ \mathrm{V}$，二极管导通，$i_C=i_D-I_o$；
- 关断区间开始：$i_C\approx3-0.5=2.5\ \mathrm{A}$；
- 关断区间结束：$i_C\approx1-0.5=0.5\ \mathrm{A}$。

## 复习例题：Buck-Boost 全输入范围保持 CCM

题意：$V_d=32\sim72\ \mathrm{V}$，$|V_o|=48\ \mathrm{V}$，$f_s=50\ \mathrm{kHz}$，$L=100\ \mu\mathrm{H}$，求全范围保持 CCM 的最小输出功率，并求开关电压应力。

占空比范围：

$$
D=\frac{|V_o|}{V_d+|V_o|}
$$

$$
V_d=32\Rightarrow D=0.6,
\qquad
V_d=72\Rightarrow D=0.4
$$

边界输出电流：

$$
I_{oB}=\frac{|V_o|(1-D)^2}{2Lf_s}
$$

最坏情况取 $D_{\min}=0.4$，因为 $(1-D)^2$ 最大：

$$
I_{oB}=\frac{48\times0.6^2}{2\times100\times10^{-6}\times50\times10^3}
=1.728\ \mathrm{A}
$$

$$
P_{o,\min}=48\times1.728\approx82.9\ \mathrm{W}
$$

开关关断时承受输入电压加输出电压幅值：

$$
V_{T,\max}\approx V_{d,\max}+|V_o|=72+48=120\ \mathrm{V}
$$

答优缺点时写：可升可降压；缺点是输出反极性，且开关/二极管电压电流应力较大。

## 复习例题：已知 $D$ 求电容和应力

题意：$V_d=24\ \mathrm{V}$，$D=0.6$，$f_s=50\ \mathrm{kHz}$，$P_o=360\ \mathrm{W}$，输出纹波率小于 $2\%$。

输出电压幅值：

$$
|V_o|=\frac{D}{1-D}V_d=\frac{0.6}{0.4}\times24=36\ \mathrm{V}
$$

输出电流：

$$
I_o=\frac{360}{36}=10\ \mathrm{A}
$$

允许纹波：

$$
\Delta V_o<0.02\times36=0.72\ \mathrm{V}
$$

电容：

$$
C\ge\frac{I_oD}{\Delta V_of_s}
=\frac{10\times0.6}{0.72\times50\times10^3}
\approx166.7\ \mu\mathrm{F}
$$

开关电压应力：

$$
V_T\approx V_d+|V_o|=60\ \mathrm{V}
$$

## 十三、考前速记

1. Buck-Boost 增益：

$$
\frac{V_o}{V_d}=-\frac{D}{1-D}
$$

2. 占空比：

$$
D=\frac{\lvert V_o\rvert}{V_d+\lvert V_o\rvert}
$$

3. 电感纹波：

$$
\Delta i_L=\frac{V_dD}{Lf_s}
$$

4. 边界电感：

$$
L_b=\frac{(1-D)^2R}{2f_s}
$$

5. 记忆：Buck-Boost = 能升降压，但输出反极性。
