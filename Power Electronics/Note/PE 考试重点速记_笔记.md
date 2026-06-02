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

## 三、第一讲：电力电子系统速记

电力电子的作用：

> 用功率半导体器件和控制电路处理电能，使电压、电流、频率、相数、功率流向变成负载最需要的形式。

典型系统结构：

$$
\text{电源}\rightarrow\text{功率变换器}\rightarrow\text{负载}
$$

控制电路负责产生驱动信号，功率电路负责真正传递能量。

### 1. 为什么追求高效率和高功率密度

- 效率高：损耗小，散热压力小，运行成本低；
- 功率密度高：同样功率下设备更小、更轻；
- 开关电源比线性电源效率高，是因为开关管主要工作在“开通/关断”状态，而不是长期工作在线性区当可变电阻。

效率题常用：

$$
\eta=\frac{P_o}{P_{\mathrm{in}}}
$$

损耗：

$$
P_{\mathrm{loss}}=P_{\mathrm{in}}-P_o
$$

若散热能力给定为 $P_{\mathrm{loss},\max}$，则：

$$
P_o=\frac{\eta}{1-\eta}P_{\mathrm{loss},\max}
$$

效率从 89% 提高到 94% 时，在相同散热能力下输出功率会明显增大，这是 PPT Example 1-1 的核心。

### 2. 功率变换器分类

| 输入 | 输出 | 名称 | 关键词 |
| :--- | :--- | :--- | :--- |
| AC | DC | Rectifier 整流器 | 工频整流、相控整流 |
| DC | DC | Chopper / DC-DC converter | Buck、Boost 等 |
| DC | AC | Inverter 逆变器 | 变频、UPS、电机驱动 |
| AC | AC | AC controller / Cycloconverter | 调压、变频 |

按器件换流方式：

- line-frequency / naturally commutated：工频自然换流；
- switched / forced-commutated：高频开关强迫换流；
- resonant / quasi-resonant：谐振或准谐振。

### 3. 常见应用

- 开关电源：把输入电能变成稳定 DC；
- UPS：电网异常时维持负载供电；
- 电机调速：改变电压幅值和频率；
- 电力系统：HVDC、FACTS、无功补偿、谐波抑制；
- 新能源：光伏 DC 接口、风电变流器；
- 电加热/焊接/照明/交通等。

---

## 四、功率半导体器件总表

### 1. 按可控程度分类

| 类型 | 代表器件 | 记忆 |
| :--- | :--- | :--- |
| 不可控 | Power Diode | 电路条件决定导通/关断 |
| 半控 | SCR/Thyristor | 门极只能触发开通，不能关断 |
| 全控 | MOSFET、IGBT、BJT/GTR、GTO、IGCT | 控制信号可控制开通和关断 |

练习题常考四种器件特点：

- Diode：不控，结构简单，可靠；
- SCR：半控，电压电流容量最高，适合大功率；
- MOSFET：电压驱动，高输入阻抗，开关快，高频低压场合好；
- IGBT：电压驱动，兼有 MOSFET 易驱动和双极型低导通压降，适合中高压中大功率。

### 2. 电流驱动还是电压驱动

| 器件 | 控制方式 |
| :--- | :--- |
| Diode | 不控 |
| SCR | 电流触发 |
| BJT/GTR | 电流驱动 |
| MOSFET | 电压驱动 |
| IGBT | 电压驱动 |
| GTO | 电流驱动，关断需要较大负门极电流 |

### 3. 单极型、双极型、复合型

| 类型 | 器件 | 特点 |
| :--- | :--- | :--- |
| 单极型 | MOSFET | 多数载流子导电，开关快，输入阻抗高，低压高频优势大 |
| 双极型 | BJT、SCR、GTO | 通态压降低，耐压/电流容量大，但开关慢 |
| 复合型 | IGBT | 易驱动 + 低导通损耗，频率通常低于 MOSFET |

MOSFET 容易并联的原因：

$$
R_{DS(on)}\text{ 具有正温度系数}
$$

即某管电流偏大时温度升高，$R_{DS(on)}$ 变大，电流自然回落，有利于均流。

### 4. 三类功率二极管

| 类型 | 特点 | 用途 |
| :--- | :--- | :--- |
| 普通整流二极管 | 通态压降低，$t_{rr}$ 大 | 工频整流 |
| 快恢复二极管 FRD | $t_{rr}$ 小，通常小于 $1\ \mu s$ | 高频开关电路 |
| 肖特基二极管 | 正向压降低，几乎无反向恢复，耐压低 | 低压高频输出整流 |

反向恢复为什么重要：

- 正向导通时 PN 结内积累少数载流子；
- 反偏后少子没有立刻消失，二极管会短时间反向导通；
- 会带来反向恢复电流、额外损耗、电压尖峰和 EMI。

常记：

$$
Q_{rr}\approx\frac12I_{rr}t_{rr}
$$

---

## 五、器件损耗计算速记

器件损耗分三类：

$$
P=P_{\mathrm{cond}}+P_{\mathrm{sw}}+P_{\mathrm{off}}
$$

断态漏电流通常很小：

$$
P_{\mathrm{off}}\approx0
$$

### 1. 导通损耗

MOSFET：

$$
P_{\mathrm{cond}}=I_{\mathrm{rms}}^2R_{DS(on)}
$$

IGBT / BJT / SCR 常用压降模型：

$$
P_{\mathrm{cond}}\approx V_{\mathrm{on}}I_{\mathrm{avg,on}}D_{\mathrm{on}}
$$

练习题中若给“通态电阻”，用电阻模型；若给 $V_{CE(sat)}$ 或 $V_{\mathrm{sat}}$，用压降模型。

### 2. 开关损耗

线性化波形常用：

$$
E_{\mathrm{on}}\approx\frac12V_oI_o(t_{ri}+t_{fv})
$$

$$
E_{\mathrm{off}}\approx\frac12V_oI_o(t_{rv}+t_{fi})
$$

$$
P_{\mathrm{sw}}=f_s(E_{\mathrm{on}}+E_{\mathrm{off}})
$$

开关损耗与下面量成正比：

- 电压 $V$；
- 电流 $I$；
- 开通/关断时间；
- 开关频率 $f_s$。

降低开关损耗的方法：

- 选用开关更快的器件，如 SiC、GaN；
- 降低开关频率；
- 优化驱动，加快栅极充放电；
- 使用软开关；
- 加合适 snubber 限制过冲和改善轨迹。

---

## 六、SCR / Thyristor 重点

SCR 又叫晶闸管、可控硅，属于半控型器件。

### 1. 三个状态

| 状态 | 条件 |
| :--- | :--- |
| 反向阻断 | $v_{AK}<0$ |
| 正向阻断 | $v_{AK}>0$，但未触发 |
| 导通 | $v_{AK}>0$ 且门极有正触发脉冲，导通后自锁 |

SCR 最关键一句：

> 门极只能触发开通，不能关断；关断必须靠外部电路让阳极电流降到接近 0，并保持足够反压时间。

### 2. 擎住电流和维持电流

维持电流 $I_H$：

> SCR 已经导通后，维持导通所需的最小阳极电流。

擎住电流 $I_L$：

> 刚触发开通后，去掉门极信号仍能保持导通所需的最小阳极电流。

常见关系：

$$
I_L\approx(2\sim4)I_H
$$

温度升高时：

$$
I_H\downarrow
$$

### 3. $di/dt$、$dv/dt$、$t_q$

$di/dt$ 过大：

- SCR 导通面积还没扩展完全；
- 局部电流密度过大；
- 可能烧坏器件。

$dv/dt$ 过大：

- 阻断状态下结电容电流变大；
- 可能造成误触发。

晶闸管关断时间：

$$
t_q=t_{rr}+t_{gr}
$$

成功关断要求：

$$
t_{\mathrm{reverse}}>t_q
$$

### 4. SCR 额定电流怎么算

SCR 额定电流通常按“工频正弦半波平均值”标称，但实际任意波形选型要先算实际电流有效值。

做题顺序：

1. 算实际波形的 $I_{\mathrm{rms}}$；
2. 令它等于额定正弦半波电流的有效值；
3. 再换算成额定平均通态电流 $I_{T(AV)}$。

对工频正弦半波，若峰值为 $I_m$：

$$
I_{\mathrm{rms}}=\frac{I_m}{2}
$$

$$
I_{\mathrm{avg}}=\frac{I_m}{\pi}
$$

因此：

$$
I_{T(AV)}=\frac{2}{\pi}I_{\mathrm{rms}}
$$

---

## 七、非隔离 DC-DC 核心公式

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

## 八、最容易考的模式判断

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

## 九、Cuk 重点

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

## 十、隔离型 DC-DC 公式

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

## 十一、隔离型拓扑对比

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

## 十二、Forward 去磁绕组专项

Forward 的主输出关系：

$$
\frac{V_o}{V_d}=D\frac{N_2}{N_1}
$$

去磁绕组作用：

- 给磁化电流 $i_m$ 提供复位通路；
- 避免磁通一周期一周期累积；
- 防止磁芯饱和。

若去磁绕组匝数为 $N_3$，要按题目课件采用的口径写。复习时记这三个量的逻辑最重要：

1. 导通时磁化电感加 $+V_d$；
2. 关断去磁时加反向复位电压；
3. 一周期内磁化电感伏秒为 0。

课件/笔记中常用推导：

$$
t_m=\frac{N_3}{N_1}t_{on}
$$

因此：

$$
D_{\max}=\frac{1}{1+N_3/N_1}
$$

若 $N_3=N_1$：

$$
D_{\max}=0.5
$$

开关去磁阶段电压应力按 PE09 笔记课件口径：

$$
V_T\approx\left(1+\frac{N_1}{N_3}\right)V_d
$$

但练习题中也出现了按 $V_T=(1+N_3/N_1)V_d$ 给分的版本。遇到这种题，优先跟题目图、课堂答案和同名端标注走，核心不要错：复位绕组反射电压会叠加在输入电压上，形成开关关断峰值应力。

设计题套路：

1. 先由复位条件求 $D_{\max}$；
2. 为使 $N_2/N_1$ 尽量小，取 $V_{d,\min}$ 和 $D_{\max}$；
3. 用

$$
\frac{N_2}{N_1}=\frac{V_o}{D_{\max}V_{d,\min}}
$$

4. 再用最小负载电流和最大纹波条件求输出滤波电感。

---

## 十三、Snubber 与驱动

杂散电感过压：

$$
v=L_\sigma\frac{di}{dt}
$$

RCD 缓冲吸收电路：

- $C_s$：吸收尖峰能量，降低 $dv/dt$；
- $D_s$：提供 $C_s$ 快速充电通道；
- $R_s$：给 $C_s$ 放电并消耗能量。

Gate driver 功能：

- 控制电路与主电路接口；
- 信号放大；
- 电气隔离；
- 快速充放栅极；
- 波形整形；
- dead time；
- 过压、过流、短路、欠压保护。

---

## 十四、Snubber 类型速记

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

## 十五、临考最容易错的点

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
11. SCR 门极不能关断 SCR，只能触发开通。
12. MOSFET 高频低压好，IGBT 中高压中大功率好。
13. 二极管反向恢复会造成额外损耗和电压尖峰，高频要用 FRD 或肖特基。
14. 负载开路但占空比固定时，Boost / Buck-Boost 类输出电容可能持续被充电，电压上升甚至击穿。
15. Buck 负载开路且占空比固定时，理想情况下输出电压会上升，最高趋近输入电压；Buck-Boost 开路更危险，电感会继续向输出电容灌能。

## 十六、补充速记：边界电流公式

已知 $L$ 时，用边界输出电流判断模式更快：

| 拓扑 | 边界输出电流 $I_{oB}$ | 判断 |
| :--- | :--- | :--- |
| Buck | $\dfrac{V_o(1-D)}{2Lf_s}$ | $I_o>I_{oB}$ 为 CCM |
| Boost | $\dfrac{V_oD(1-D)^2}{2Lf_s}$ | $I_o>I_{oB}$ 为 CCM |
| Buck-Boost | $\dfrac{|V_o|(1-D)^2}{2Lf_s}$ | $I_o>I_{oB}$ 为 CCM |

等号是边界模式。计算“最小电感”时，等号给的是边界值，真正连续导通要略大于它。

## 十七、补充速记：常见数值题答案

| 题型 | 关键结果 |
| :--- | :--- |
| Buck：$50\sim80\ \mathrm{V}\to40\ \mathrm{V}$，$L=60\ \mu H$，$40\ \mathrm{kHz}$ | 全范围 CCM：$P_{o,\min}\approx166.7\ \mathrm{W}$ |
| Buck：$12.5\to5\ \mathrm{V}$，$I_o=2\ \mathrm{A}$，$L=100\ \mu H$，$C=470\ \mu F$ | $D=0.4$，$\Delta i_L=1.5\ \mathrm{A}$，$\Delta V_o\approx20\ \mathrm{mV}$ |
| Boost：$18\to30\ \mathrm{V}$，$P_o=180\ \mathrm{W}$，$20\ \mathrm{kHz}$ | $D=0.4$，$C_{min}=80\ \mu F$，$L_{min}=18\ \mu H$ |
| Boost 课件 7-B：$5\to12\ \mathrm{V}$，$P_o=10\ \mathrm{W}$，$\Delta i_L=2\ \mathrm{A}$ | $D=0.583$，$L\approx7.3\ \mu H$，$I_L=2\ \mathrm{A}$ |
| Buck-Boost：$32\sim72\ \mathrm{V}\to48\ \mathrm{V}$，$L=100\ \mu H$ | $P_{o,\min}\approx82.9\ \mathrm{W}$，$V_{T,max}\approx120\ \mathrm{V}$ |
| Buck-Boost：$V_d=24\ \mathrm{V}$，$D=0.6$，$P_o=360\ \mathrm{W}$ | $|V_o|=36\ \mathrm{V}$，$C_{min}\approx166.7\ \mu F$，$V_T\approx60\ \mathrm{V}$ |
| Buck-Boost：$12\sim48\ \mathrm{V}\to24\ \mathrm{V}$，$L=50\ \mu H$，$50\ \mathrm{kHz}$ | $P_{o,\min}\approx51.2\ \mathrm{W}$，$V_T=V_D\approx72\ \mathrm{V}$ |
| Boost：$18\to30\ \mathrm{V}$，$P_o=180\ \mathrm{W}$ | $V_{T,peak}=30\ \mathrm{V}$，$I_L=P_o/V_d=10\ \mathrm{A}$ |
| Forward 10-B | $N_2/N_1=12$，$D=0.0225\sim0.5$，$L_{min}\approx97.8\ \mu H$ |
| Forward：$20\sim28\to100\ \mathrm{V}$，$N_3=2N_1$ | 练习题给分：$D_{\max}=1/3$，$N_2/N_1=15$，$V_T=84\ \mathrm{V}$ |

## 十八、补充速记：器件与驱动问答

- 功率二极管三类：普通整流二极管、快恢复二极管、肖特基二极管。
- SCR：电流触发、半控、可开通不可门极关断。
- IGBT/MOSFET：电压驱动；IGBT 适合中高压大功率，MOSFET 高频更强。
- MOSFET 易并联：$R_{DS(on)}$ 正温度系数帮助均流。
- RCD 缓冲元件作用：$C$ 吸收/限压，$R$ 放电/耗能，$D$ 提供快速充电或旁路通道。
- Gate driver 功能：接口、放大、隔离、快速充放电、整形、dead time、过流/短路/欠压保护。
- 桥式拓扑 $C_b$：隔直、防偏磁、帮助伏秒平衡。
