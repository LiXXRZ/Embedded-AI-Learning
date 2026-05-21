# 电力电子考试重点速记

> 本速记按 PPT/PPTX 原课件中的知识点、例题和复习题整理。PDF 只作辅助对照，不采纳不确定批注。

## 一、做题通用顺序

电力电子计算题不要一上来套公式，先按下面顺序判断：

1. 判断拓扑：Buck、Boost、Buck-Boost、Cuk、Flyback、Forward、Push-Pull、Half-Bridge、Full-Bridge。
2. 判断工作模式：CCM、DCM、边界模式。
3. 写两个开关状态下的电感电压。
4. 用伏秒平衡求增益。
5. 用纹波公式求 $L$、$C$。
6. 检查器件应力：开关耐压、二极管反压、电流峰值。
7. 对实际电路补充：反向恢复、漏感尖峰、snubber、驱动与保护。

---

## 二、三个稳态原则

电感伏秒平衡：

$$
\int_0^{T_s}v_L(t)\,dt=0
$$

电容电荷平衡：

$$
\int_0^{T_s}i_C(t)\,dt=0
$$

理想变换器功率守恒：

$$
P_{\mathrm{in}}\approx P_o
$$

---

## 三、非隔离 DC-DC 核心公式

| 拓扑 | CCM 电压增益 | 占空比反解 | 边界电感 |
| :--- | :--- | :--- | :--- |
| Buck | $\dfrac{V_o}{V_d}=D$ | $D=\dfrac{V_o}{V_d}$ | $L_b=\dfrac{(1-D)R}{2f_s}$ |
| Boost | $\dfrac{V_o}{V_d}=\dfrac1{1-D}$ | $D=1-\dfrac{V_d}{V_o}$ | $L_b=\dfrac{D(1-D)^2R}{2f_s}$ |
| Buck-Boost | $\dfrac{V_o}{V_d}=-\dfrac{D}{1-D}$ | $D=\dfrac{\lvert V_o\rvert}{V_d+\lvert V_o\rvert}$ | $L_b=\dfrac{(1-D)^2R}{2f_s}$ |
| Cuk | $\dfrac{V_o}{V_d}=-\dfrac{D}{1-D}$ | $D=\dfrac{\lvert V_o\rvert}{V_d+\lvert V_o\rvert}$ | 重点看 $L_1,L_2,C_1$ 纹波 |

Buck 电感纹波：

$$
\Delta i_L=\frac{V_dD(1-D)}{Lf_s}
$$

Boost / Buck-Boost 电感纹波：

$$
\Delta i_L=\frac{V_dD}{Lf_s}
$$

Buck 输出电压纹波：

$$
\Delta V_o\approx\frac{\Delta i_L}{8Cf_s}
$$

Boost / Buck-Boost 输出纹波：

$$
\frac{\Delta V_o}{V_o}\approx\frac{D}{RCf_s}
$$

---

## 四、最容易考的模式判断

CCM 公式通常只在电感电流连续时成立。  
轻载、小电感、低频时容易进入 DCM。

判断方法：

1. 先假设 CCM，求 $D$。
2. 用边界电流或边界电感检查。
3. 若实际输出电流小于边界电流，则进入 DCM。
4. DCM 下不能直接用 CCM 增益。

Buck-Boost 课件例题的典型结论：

$$
I_o<I_{oB}
$$

所以实际是 DCM，最后求得：

$$
D\approx0.30
$$

而不是 CCM 假设下的 $0.4$。

---

## 五、Cuk 重点

Cuk 和 Buck-Boost 增益相同，但电流纹波特性不同：

$$
\frac{V_o}{V_d}=-\frac{D}{1-D}
$$

能量转移电容平均电压：

$$
V_{C1}=V_d+\lvert V_o\rvert
$$

Cuk 的优点：

- 输入电流连续；
- 输出电流连续；
- 纹波比基本 Buck-Boost 更友好。

Cuk 的核心理解：

- $L_1$ 平滑输入；
- $L_2$ 平滑输出；
- $C_1$ 负责能量转移，不是普通旁路电容。

---

## 六、隔离型 DC-DC 公式

设：

$$
n=\frac{N_s}{N_p}
$$

Flyback：

$$
\frac{V_o}{V_d}=n\frac{D}{1-D}
$$

Forward：

$$
\frac{V_o}{V_d}=nD
$$

Push-Pull：

$$
V_o=2DnV_d
$$

Half-Bridge：

$$
V_o=DnV_d
$$

Full-Bridge：

$$
V_o=2DnV_d
$$

---

## 七、隔离型拓扑对比

| 拓扑 | 磁芯使用 | 能量传递 | 重点问题 |
| :--- | :--- | :--- | :--- |
| Flyback | 单向励磁 | 导通储能，关断传能 | 漏感尖峰、储能磁芯、小功率 |
| Forward | 单向励磁 | 导通直接传能 | 磁复位，常见 $D<0.5$ |
| Push-Pull | 双向励磁 | 两管交替传能 | 磁偏、开关耐压约 $2V_d$ |
| Half-Bridge | 双向励磁 | 半母线电压传能 | 分压电容，电流较大 |
| Full-Bridge | 双向励磁 | 全母线电压传能 | 四开关、驱动复杂、大功率 |

Flyback 开关关断应力：

$$
V_{\mathrm{sw}}\approx V_d+\frac{N_p}{N_s}V_o
$$

Forward 若复位绕组 $N_3=N_1$，常取：

$$
D_{\max}\le0.5
$$

---

## 八、器件重点

二极管反向恢复：

$$
Q_{rr}\approx\frac12I_{rr}t_{rr}
$$

杂散电感过压：

$$
v=L_\sigma\frac{di}{dt}
$$

MOSFET 导通损耗：

$$
P_{\mathrm{cond}}=I_D^2R_{DS(on)}
$$

IGBT 导通损耗：

$$
P_{\mathrm{cond}}\approx V_{CE(sat)}I_C
$$

开关损耗：

$$
P_{\mathrm{sw}}=f_s(E_{\mathrm{on}}+E_{\mathrm{off}})
$$

SCR：

- 可控开通；
- 不可控关断；
- 需要关注 $I_L$、$I_H$、$di/dt$、$dv/dt$、$t_q$。

SCR 关断时间：

$$
t_q=t_{rr}+t_{gr}
$$

---

## 九、Snubber 与驱动

Snubber 的作用：

- 限制过电压；
- 限制 $dv/dt$；
- 限制过电流；
- 限制 $di/dt$；
- 改善开关轨迹；
- 降低器件瞬时应力。

常见类型：

| 类型 | 用途 |
| :--- | :--- |
| RC | 二极管、晶闸管反向恢复保护 |
| RCD turn-off | 受控开关关断缓冲 |
| Overvoltage snubber | 限制漏感过压 |
| LR turn-on | 限制开通 $di/dt$ |

驱动电路功能：

- 放大控制信号；
- 快速充放栅极；
- 必要时隔离；
- 提供负压关断；
- 提供 dead time；
- 过流、短路、欠压保护。

常见 IGBT 驱动：

$$
V_{GE+}\approx15\ \mathrm{V}
$$

$$
V_{GE-}\approx-5\sim-10\ \mathrm{V}
$$

门极电阻经验范围：

$$
R_G\approx3\sim30\ \Omega
$$

$R_G$ 小：开关快、损耗低、EMI 和过冲大。  
$R_G$ 大：开关慢、损耗高、EMI 和过冲小。

---

## 十、临考最容易错的点

1. Buck 的 $I_L\approx I_o$，Boost 的 $I_L\approx I_{\mathrm{in}}$。
2. Boost 导通时负载由电容供电。
3. Buck-Boost 和 Cuk 输出反极性。
4. DCM 下不能直接用 CCM 增益。
5. Flyback 的“变压器”本质上是储能耦合电感。
6. Forward 必须磁复位，否则磁通累积导致饱和。
7. Push-Pull 易磁偏，开关耐压高。
8. Half-Bridge 原边电压只有约 $V_d/2$。
9. Full-Bridge 适合较大功率，但驱动复杂。
10. Snubber 不改变稳态增益，它解决瞬态应力。

## 十一、补充速记：边界电流公式

已知 $L$ 时，用边界输出电流判断模式更快：

| 拓扑 | 边界输出电流 $I_{oB}$ | 判断 |
| :--- | :--- | :--- |
| Buck | $\dfrac{V_o(1-D)}{2Lf_s}$ | $I_o>I_{oB}$ 为 CCM |
| Boost | $\dfrac{V_oD(1-D)^2}{2Lf_s}$ | $I_o>I_{oB}$ 为 CCM |
| Buck-Boost | $\dfrac{|V_o|(1-D)^2}{2Lf_s}$ | $I_o>I_{oB}$ 为 CCM |

等号是边界模式。计算“最小电感”时，等号给的是边界值，真正连续导通要略大于它。

## 十二、补充速记：常见数值题答案

| 题型 | 关键结果 |
| :--- | :--- |
| Buck：$50\sim80\ \mathrm{V}\to40\ \mathrm{V}$，$L=60\ \mu H$，$40\ \mathrm{kHz}$ | 全范围 CCM：$P_{o,\min}\approx166.7\ \mathrm{W}$ |
| Buck：$12.5\to5\ \mathrm{V}$，$I_o=2\ \mathrm{A}$，$L=100\ \mu H$，$C=470\ \mu F$ | $D=0.4$，$\Delta i_L=1.5\ \mathrm{A}$，$\Delta V_o\approx20\ \mathrm{mV}$ |
| Boost：$18\to30\ \mathrm{V}$，$P_o=180\ \mathrm{W}$，$20\ \mathrm{kHz}$ | $D=0.4$，$C_{min}=80\ \mu F$，$L_{min}=18\ \mu H$ |
| Boost 课件 7-B：$5\to12\ \mathrm{V}$，$P_o=10\ \mathrm{W}$，$\Delta i_L=2\ \mathrm{A}$ | $D=0.583$，$L\approx7.3\ \mu H$，$I_L=2\ \mathrm{A}$ |
| Buck-Boost：$32\sim72\ \mathrm{V}\to48\ \mathrm{V}$，$L=100\ \mu H$ | $P_{o,\min}\approx82.9\ \mathrm{W}$，$V_{T,max}\approx120\ \mathrm{V}$ |
| Buck-Boost：$V_d=24\ \mathrm{V}$，$D=0.6$，$P_o=360\ \mathrm{W}$ | $|V_o|=36\ \mathrm{V}$，$C_{min}\approx166.7\ \mu F$，$V_T\approx60\ \mathrm{V}$ |
| Forward 10-B | $N_2/N_1=12$，$D=0.0225\sim0.5$，$L_{min}\approx97.8\ \mu H$ |

## 十三、补充速记：器件与驱动问答

- 功率二极管三类：普通整流二极管、快恢复二极管、肖特基二极管。
- SCR：电流触发、半控、可开通不可门极关断。
- IGBT/MOSFET：电压驱动；IGBT 适合中高压大功率，MOSFET 高频更强。
- MOSFET 易并联：$R_{DS(on)}$ 正温度系数帮助均流。
- RCD 缓冲元件作用：$C$ 吸收/限压，$R$ 放电/耗能，$D$ 提供快速充电或旁路通道。
- Gate driver 功能：接口、放大、隔离、快速充放电、整形、dead time、过流/短路/欠压保护。
- 桥式拓扑 $C_b$：隔直、防偏磁、帮助伏秒平衡。
