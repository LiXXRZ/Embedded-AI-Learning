# 9 Flyback 与 Forward 变换器

## 一、本章主线

本章讨论隔离型 DC-DC 变换器，重点是：

- 需要电气隔离；
- 需要较高的电压变换比；
- 需要较高效率和较小体积；
- 需要能理解磁通、磁化电流、绕组电压这些波形量。

本章核心器件是两类：

- Flyback：反激变换器；
- Forward：正激变换器。

它们都使用高频变压器，但能量传递方式完全不同。

---

## 二、磁路与变压器基础

隔离型变换器里，很多限制不是从电路图直接看出来的，而是由磁路决定的。

### 1. 常用物理量

| 符号 | 含义 |
| :--- | :--- |
| `F = NI` | 磁动势 |
| `H` | 磁场强度 |
| `B` | 磁通密度 |
| `Phi` | 磁通 |
| `lambda = N Phi` | 磁链 |
| `Rm` | 磁阻 |
| `Lm` | 磁化电感 |

### 2. 基本电磁关系

由法拉第定律：

$$
v = N\frac{d\Phi}{dt}
$$

由电感定义：

$$
v_L = L\frac{di}{dt}
$$

$$
W = \frac{1}{2}Li^2
$$

所以只要绕组上有电压，磁通就会变化；只要电感两端有电压，电流就会线性变化。

### 3. 物理量如何对应到波形图

- `v1` / `v2`：原边、次边绕组电压；
- `i1`：原边绕组电流；
- `i2`：次边绕组电流；
- `im`：磁化电流，表示磁芯中储能状态；
- `iD`：二极管电流；
- `vT`：开关管两端电压；
- `Phi`：磁通。

要注意：

`im` 不总是等于 `i1`。

在反激中，开关导通时 `i1 = im`；开关关断后，`i1 = 0`，但 `im` 通过副边电流继续释放。

更一般地说，变压器绕组上“有电压”和“有电流”不是一回事：

- 绕组有感应电压：说明磁通在变化；
- 绕组有电流：还要求外部回路导通。

所以可能出现：

$$
v_2 \ne 0,\quad D_1\ \text{反偏},\quad i_2 = 0
$$

这在正激去磁阶段尤其容易混淆。

---

## 三、Flyback 反激变换器

### 1. 本质

反激不是“变压器直接传能”，而是：

> 先储能，再放能。

更准确地说，它更像一个带隔离的 Buck-Boost。

![Flyback topology from PPT](assets/pe09/flyback_topology_ppt.png)

### 2. 导通阶段 `0 < t < ton`

![Flyback ton current path from PPT](assets/pe09/flyback_ton_path_ppt.png)

开关 `T` 导通时：

$$
v_1 = V_d
$$

磁化电感两端加正电压，磁化电流线性上升：

$$
\frac{di_m}{dt} = \frac{V_d}{L_m}
$$

$$
i_m(t) = i_m(0) + \frac{V_d}{L_m}t
$$

磁通也线性上升：

$$
\phi(t) = \phi(0) + \frac{V_d}{N_1}t
$$

这时副边二极管反偏：

$$
i_2 = i_D = 0
$$

所以负载由输出电容单独供电。

这一阶段为什么 `i1 = im`？

在反激等效模型中，磁化电感 `Lm` 与理想变压器并联在原边。导通时副边二极管截止，所以副边没有电流：

$$
i_2 = 0
$$

原边电流只流入磁化电感，因此：

$$
i_1 = i_m
$$

这说明导通阶段输入源并没有直接把能量送到负载，而是把能量储存在磁化电感中。

### 3. 关断阶段 `ton < t < Ts`

![Flyback toff current path from PPT](assets/pe09/flyback_toff_path_ppt.png)

开关关断后，原边回路断开，`i1 = 0`。但磁化电流不能突变，所以磁场能量必须通过副边释放。

此时副边电压翻转：

$$
v_2 = -V_o
$$

$$
v_1 = -\frac{N_1}{N_2}V_o
$$

因此磁化电流线性下降：

$$
\frac{di_m}{dt}
= \frac{v_{L_m}}{L_m}
= -\frac{\frac{N_1}{N_2}V_o}{L_m}
$$

对应的电流关系是：

$$
i_2 = i_D = \frac{N_1}{N_2}i_m
$$

所以关断时的关键结论是：

- $i_1 = 0$：原边外部开关支路断开；
- $i_m$ 线性下降：磁化能量正在释放；
- $i_2$ 线性下降：副边二极管导通，副边承担能量释放通道。

这里的 `i1 = 0` 和 `im` 下降并不矛盾。`i1` 是原边外部支路电流，开关断开后原边没有闭合回路，所以：

$$
i_1 = 0
$$

但 `im` 是磁芯储能状态对应的磁化电流，它不能突变。原边通路断开后，磁通使副边电压极性翻转，二极管导通，于是磁化能量通过副边释放。

用等效关系看：

$$
i_m = i_1 - \frac{N_2}{N_1}i_2
$$

导通时：

$$
i_2 = 0 \Rightarrow i_m = i_1
$$

关断时：

$$
i_1 = 0 \Rightarrow i_m = -\frac{N_2}{N_1}i_2
$$

负号表示参考方向相反，按大小可写为：

$$
i_2 = \frac{N_1}{N_2}i_m
$$

因此，反激关断时不是“磁化电流消失”，而是“磁化电流从原边电流的表现形式，转移为副边电流的表现形式”。

### 4. 开关管电压应力

关断时开关管承受：

$$
v_T = V_d + \frac{N_1}{N_2}V_o
$$

这也是反激开关管应力较高的原因之一。

推导思路如下：

开关导通时，开关近似短路：

$$
v_T \approx 0
$$

开关关断时，副边二极管导通，输出电压 `Vo` 被反射到原边，反射电压大小为：

$$
V_{\text{reflected}} = \frac{N_1}{N_2}V_o
$$

这个反射电压与输入电压 `Vd` 叠加在开关管两端，所以：

$$
v_T
= V_d + V_{\text{reflected}}
= V_d + \frac{N_1}{N_2}V_o
$$

实际电路还会叠加漏感尖峰，所以真实开关耐压要留裕量。

### 5. CCM 电压增益推导

稳态时磁通一个周期回到原值，故伏秒平衡成立：

$$
\frac{V_d}{N_1}t_{on} - \frac{V_o}{N_2}t_{off} = 0
$$

令：

$$
t_{on}=DT_s,\quad t_{off}=(1-D)T_s
$$

则：

$$
\frac{V_d}{N_1}DT_s
= \frac{V_o}{N_2}(1-D)T_s
$$

化简得：

$$
\frac{V_o}{V_d}
= \frac{N_2}{N_1}\frac{D}{1-D}
$$

这就是反激在 CCM 下的电压传输比。

### 6. 三种工作模式

![Flyback CCM waveforms from PPT](assets/pe09/flyback_ccm_waveforms_ppt.png)

- DCM：电感电流在一个周期内降到 0；
- 临界模式：刚好降到 0；
- CCM：电感电流始终大于 0。

### 7. Flyback 小结

- 导通时储能；
- 关断时放能；
- 本质是“隔离 Buck-Boost”；
- 变压器更像“双绕组电感”；
- 设计时常要考虑漏感尖峰和吸收电路。

---

## 四、Forward 正激变换器

### 1. 本质

正激可以看成：

> 隔离型 Buck + 变压器。

也就是开关导通时，能量直接传到输出；输出电感负责平滑电流。

![Forward practical topology from PPT](assets/pe09/forward_practical_topology_ppt.png)

这张图里的关键不是“多输出电源应用”，而是正激工作状态需要同时看三条支路：

- `N1` 原边主绕组支路：开关导通时有 `i1`，关断后主开关支路断开；
- `N2-D1-L-C-R` 输出传能支路：导通时 `D1` 导通，输出电感吸收能量；
- `N3-D3` 去磁支路：关断后的去磁阶段导通，把磁化能量送回输入侧。

### 2. 导通阶段 `0 < t < ton`

![Forward ton current path from PPT](assets/pe09/forward_ton_path_ppt.png)

此时：

- $D_1$ 导通；
- $D_2$ 反偏；
- $D_3$ 反偏。

副边向输出传能，输出电感电压为：

$$
v_L = \frac{N_2}{N_1}V_d - V_o
$$

所以：

$$
\frac{di_L}{dt}
= \frac{\frac{N_2}{N_1}V_d - V_o}{L}
$$

输出电感电流 `iL` 线性上升。

同时磁化电感也在储能：

$$
\frac{di_m}{dt}=\frac{V_d}{L_m}
$$

这一阶段要注意两种电流同时存在：

$$
i_1 = i_m + i'_2
$$

其中 $i'_2$ 是副边传能电流折算到原边的分量。也就是说，正激导通时 `i1` 不是单纯的磁化电流，它还包含向输出传能所需要的反射电流；这点和反激导通阶段 $i_1=i_m$ 不一样。

### 3. 关断与去磁阶段 `ton < t < ton + tm`

![Forward demagnetizing current path from PPT](assets/pe09/forward_demag_path_ppt.png)

开关关断后，`D1` 反偏，主传能通路断开；但磁化电流 `im` 不能突变，所以必须通过去磁绕组 `N3` 和二极管 `D3` 复位。

此时：

- $D_2$ 导通，输出电感续流；
- $D_3$ 导通，磁化能量回馈输入；
- $D_1$ 关断，副边主传能支路中断。

这一段最容易混淆的是 `i2`、`i3`、`iL`：

- $i_2$：变压器副边 $N_2$ / $D_1$ 主传能支路电流；
- $i_3$：去磁绕组 $N_3$ / $D_3$ 复位支路电流；
- $i_L$：输出电感电流。

在 `ton < t < ton + tm`：

$$
D_1\ \text{反偏} \Rightarrow i_2=0
$$

$$
D_3\ \text{导通} \Rightarrow i_3\ne 0
$$

$$
D_2\ \text{导通} \Rightarrow i_L\ \text{续流}
$$

也就是说，`i3` 存在是因为磁化电流需要通过去磁绕组释放；`i2 = 0` 是因为副边主整流二极管 `D1` 截止。输出侧仍有电流，但那是 `iL` 经 `D2` 续流，不是变压器副边电流 `i2`。

此时 `v2` 仍然可以存在。原因是只要磁通在变化，所有耦合绕组都会感应电压；但 `v2` 的极性使 `D1` 反偏，所以有电压、无电流：

$$
v_2 \ne 0,\quad i_2=0
$$

磁化绕组电压变为：

$$
v_1 = -\frac{N_1}{N_3}V_d
$$

于是：

$$
\frac{di_m}{dt}
= -\frac{\frac{N_1}{N_3}V_d}{L_m}
$$

这条式子的含义是：磁化电感两端加了一个反向电压，所以磁化电流以固定斜率下降。它来自电感基本公式：

$$
v = L\frac{di}{dt}
$$

所以：

$$
\frac{di}{dt}=\frac{v}{L}
$$

去磁阶段折算到原边的磁化电感电压为负：

$$
v_{L_m}= -\frac{N_1}{N_3}V_d
$$

所以：

$$
\frac{di_m}{dt}
= \frac{v_{L_m}}{L_m}
= -\frac{\frac{N_1}{N_3}V_d}{L_m}
$$

输出电感此时只有负载回路：

$$
v_L=-V_o
$$

$$
\frac{di_L}{dt}=-\frac{V_o}{L}
$$

去磁阶段中 $i_3$ 存在、$i_2=0$ 并不矛盾。$i_3$ 是磁化电流的复位通道；$i_2$ 属于副边主整流支路，而这一段 $D_1$ 已经被反偏切断。输出侧确实还有电流，但它走的是 $L-D_2-C/R$ 的续流回路，不经过变压器副边主绕组。

### 4. 去磁结束后的续流阶段 `ton + tm < t < Ts`

![Forward freewheel current path from PPT](assets/pe09/forward_freewheel_path_ppt.png)

去磁结束后，磁化电流已经降到零：

$$
i_m=i_1=i_3=0
$$

此时 $D_1$、$D_3$ 都关断，只有输出电感通过 $D_2$ 向负载续流：

$$
i_{D2}=i_L
$$

输出电感电压仍为：

$$
v_L=-V_o
$$

所以：

$$
\frac{di_L}{dt}=-\frac{V_o}{L}
$$

这一段和上一段的输出电感斜率相同，区别在于：上一段还同时存在去磁电流 $i_3$；这一段去磁已经结束，只剩输出侧续流。

### 5. 为什么正激要加去磁绕组

如果没有去磁绕组，磁芯中的磁通不能回到初值，`im` 会一周期比一周期高，最后进入饱和。

因此正激必须提供一个复位通道：

$N_3 + D_3$。

### 6. 去磁时间与最大占空比

由导通和去磁的磁通变化量相等：

$$
\frac{V_d}{N_1}t_{on}
= \frac{V_d}{N_3}t_m
$$

得到：

$$
t_m=\frac{N_3}{N_1}t_{on}
$$

这个式子也可以从磁化电流变化量理解。

导通阶段：

$$
\Delta i_{m,on}=\frac{V_d}{L_m}t_{on}
$$

去磁阶段：

$$
\Delta i_{m,reset}
= \frac{\frac{N_1}{N_3}V_d}{L_m}t_m
$$

稳态时，磁化电流每周期必须回到原来的值，所以：

$$
\Delta i_{m,on}=\Delta i_{m,reset}
$$

即：

$$
\frac{V_d}{L_m}t_{on}
= \frac{\frac{N_1}{N_3}V_d}{L_m}t_m
$$

化简后仍然得到：

$$
t_m=\frac{N_3}{N_1}t_{on}
$$

这说明“伏秒平衡”本质上是在保证磁通不累积，也等价于保证磁化电流不一周期比一周期高。

为了在一个周期内完成复位，需要：

$$
t_m \le T_s-t_{on}
$$

所以：

$$
D_{\max}
= \frac{t_{on}}{T_s}
= \frac{1}{1+N_3/N_1}
$$

若常取：

$$
N_3=N_1
$$

则：

$$
D_{\max}=0.5,\quad t_m=t_{on}
$$

注意：`N3 = N1` 不是物理定律，而是 PPT 和许多单管正激电源常用的设计取法。这样做有三个直接结果：

1. $t_m=t_{on}$，复位时间和导通时间相等；
2. $D_{\max}=0.5$，便于保证磁芯每周期复位；
3. $v_T(\text{reset})=2V_d$，开关电压应力清楚且常见。

如果 `N3` 不等于 `N1`，也可以工作，但 `tm`、`Dmax`、`vT` 都会改变。

### 7. 开关电压

去磁期间开关管两端电压为：

$$
v_T=V_d+\frac{N_1}{N_3}V_d
= \left(1+\frac{N_1}{N_3}\right)V_d
$$

去磁结束后，开关仍关断，但去磁电流已归零，此时开关只承受输入电压：

$$
v_T=V_d
$$

因此正激开关电压有三个典型平台：

- $T$ 导通：$v_T=0$；
- $T$ 关断且正在去磁：$v_T=\left(1+\frac{N_1}{N_3}\right)V_d$；
- 去磁结束但仍关断：$v_T=V_d$。

若 `N3 = N1`，去磁平台就是：

$$
v_T=2V_d
$$

### 8. CCM 电压增益推导

对输出电感做伏秒平衡：

$$
(nV_d - V_o)DT_s + (-V_o)(1-D)T_s=0
$$

其中：

$$
n=\frac{N_2}{N_1}
$$

化简得到：

$$
\frac{V_o}{V_d}=nD
$$

也就是正激的电压传输比和 Buck 完全一致，只是前面多了变压器匝比。

![Forward CCM waveforms from PPT](assets/pe09/forward_ccm_waveforms_ppt.png)

### 9. Forward 小结

- 导通时直接传能；
- 输出电感负责连续电流；
- 磁化电感必须每周期复位；
- 常见设计取 `N3 = N1`，因此 `Dmax = 0.5`。

---

## 五、Example 10-B 详细解答

题目：

> 设计一个基于 Forward converter 的光伏电源，输出 `Vo = 12V`，输入 `Vd` 在 `2V ~ 44.4V` 之间变化，要求输出恒定 12V。已知 `R = 2 ohm`，开关频率 `f = 10 kHz`。

![Example 10-B question from PPT](assets/pe09/example_10b_question_ppt.png)

### (a) 最大匝比 `N1:N2`

正激 CCM 下：

$$
\frac{V_o}{V_d}=\frac{N_2}{N_1}D
$$

又因为正激必须满足：

$$
D \le 0.5
$$

在最低输入电压 `Vd_min = 2V` 时，需要最大的占空比，所以：

$$
\frac{N_1}{N_2}
\le
\frac{D_{\max}V_{d,\min}}{V_o}
$$

代入：

$$
\frac{N_1}{N_2}
\le
\frac{0.5\times 2}{12}
=\frac{1}{12}
$$

所以：

$$
N_1:N_2\ \text{最大为}\ 1:12
$$

为什么要用最低输入电压 `2V` 来求？

因为：

$$
V_o=\frac{N_2}{N_1}DV_d
$$

当 `Vo` 固定为 12V 时，`Vd` 越低，就越需要更大的占空比 `D` 来补偿。正激又要求 `D <= 0.5`，所以最困难的工况一定是：

$$
V_d=V_{d,\min}=2\text{ V}
$$

题目问的是“最大 `N1:N2`”，也就是最大 `N1/N2`。由：

$$
\frac{N_1}{N_2}=\frac{DV_d}{V_o}
$$

可知在最低输入、最大允许占空比下得到上限：

$$
\frac{N_1}{N_2}\le \frac{1}{12}
$$

如果 `N1:N2` 比 `1:12` 更大，例如 `1:10`，则 `N2/N1` 变小，2V 输入时必须使用超过 0.5 的占空比才能输出 12V，这会破坏正激复位条件。

### (b) 占空比范围

由 `N1:N2 = 1:12` 得：

$$
\frac{N_2}{N_1}=12
$$

所以：

$$
\frac{V_o}{V_d}=12D
$$

$$
D=\frac{V_o}{12V_d}
$$

代入 `Vo = 12V`：

$$
D=\frac{12}{12V_d}
$$

也就是：

$$
D=\frac{1}{V_d}
$$

这里的 `Vd` 以伏特为数值代入，所以 `Vd = 10V` 时 `D = 0.1`，`Vd = 2V` 时 `D = 0.5`。

因此：

$$
V_d=2\text{ V}\Rightarrow D=0.5
$$

$$
V_d=44.4\text{ V}\Rightarrow D=0.0225
$$

所以占空比范围为：

$$
D=0.0225\sim 0.5
$$

PPT 中 (a)(b) 的原解截图：

![Example 10-B solution a b from PPT](assets/pe09/example_10b_solution_ab_ppt.png)

### (c) 保证 `iL` 连续的最小电感

输出电流为：

$$
I_L=I_o=\frac{V_o}{R}=\frac{12}{2}=6\text{ A}
$$

这里 `IL` 是输出电感电流的平均值。在连续导通模式下，`iL` 围绕平均值上下波动。若峰峰值纹波为 `Delta iL`，则最低电流为：

$$
i_{L,\min}=I_L-\frac{\Delta i_L}{2}
$$

为了保证连续，要求：

$$
i_{L,\min}>0
$$

所以：

$$
I_L>\frac{\Delta i_L}{2}
$$

PPT 中把：

$$
I_{\text{ripple}}=\frac{\Delta i_L}{2}
$$

所以连续条件写成：

$$
I_L>I_{\text{ripple}}
$$

输出电感在导通阶段的纹波峰峰值可写成：

$$
\Delta i_L
=\frac{\left(\frac{N_2}{N_1}V_d-V_o\right)DT_s}{L}
$$

PPT 中把半纹波记为：

$$
I_{\text{ripple}}=\frac{\Delta i_L}{2}
$$

连续导通条件：

$$
I_L>I_{\text{ripple}}
$$

代入 `N2/N1 = 12`、`Ts = 1/f = 10^-4 s`：

$$
I_{\text{ripple}}
=\frac{1}{2}\cdot\frac{12V_d-12}{L}\cdot D\cdot 10^{-4}
$$

又因为：

$$
D=\frac{1}{V_d}
$$

所以：

$$
I_{\text{ripple}}
=\frac{6\left(1-\frac{1}{V_d}\right)10^{-4}}{L}
$$

令 `IL > Iripple`：

$$
6>
\frac{6\left(1-\frac{1}{V_d}\right)10^{-4}}{L}
$$

化简得到：

$$
L>10^{-4}\left(1-\frac{1}{V_d}\right)
$$

最严格情况取最大输入电压 `Vd_max = 44.4V`：

$$
L_{\min}=10^{-4}\left(1-\frac{1}{44.4}\right)
$$

为什么取最大输入电压？

因为：

$$
L>10^{-4}\left(1-\frac{1}{V_d}\right)
$$

其中 `1 - 1/Vd` 随 `Vd` 增大而增大。输入电压越高，导通时输出电感电压：

$$
v_{L,on}=12V_d-12
$$

越大，电流上升斜率越大，纹波越大，因此为了仍保持连续，需要更大的电感。

所以：

$$
L_{\min}=97.75\ \mu\text{H}
$$

PPT 中 (c) 的原解截图：

![Example 10-B solution c from PPT](assets/pe09/example_10b_solution_c_ppt.png)

### (d) 开关状态与开关管电压 `vT`

这里按 PPT 的标准设计取：

$$
N_3=N_1
$$

因此：

$$
t_m=t_{on}
$$

$$
v_T(\text{reset})
=\left(1+\frac{N_1}{N_3}\right)V_d
=2V_d
$$

为什么 (d) 可以这样做？

题目没有另外给 `N3` 的匝数，所以按照 PPT 前面讲的标准单管正激设计：

$$
\text{Typically, }N_3=N_1
$$

这不是唯一选择，但它是课件默认假设。取这个值后，去磁时间和开通时间相等，波形就可以直接按：

$$
t_{on}\ \text{后立刻进入同样长度的 reset 区间}
$$

来画。

#### 情况 1：`Vd = 10V`

$$
D=\frac{V_o}{12V_d}
=\frac{12}{12\times 10}
=0.1
$$

$$
T_s=100\ \mu s
$$

$$
t_{on}=DT_s=10\ \mu s,\quad t_m=t_{on}=10\ \mu s
$$

于是：

| 时间区间 | 状态 | 开关管电压 |
| :--- | :--- | :--- |
| $0\sim 10\ \mu s$ | $T$ 导通 | $v_T=0$ |
| $10\sim 20\ \mu s$ | 去磁复位 | $v_T=2V_d=20\text{ V}$ |
| $20\sim 100\ \mu s$ | 关断但去磁结束 | $v_T=V_d=10\text{ V}$ |

第三段为什么是 `vT = Vd`？

因为去磁已经结束，`i3 = 0`，去磁绕组不再把额外的反射电压加到开关管上。开关仍然关断，所以它只承受输入电压：

$$
v_T=V_d=10\text{ V}
$$

#### 情况 2：`Vd = 2V`

$$
D=\frac{12}{12\times 2}=0.5
$$

$$
t_{on}=50\ \mu s,\quad t_m=50\ \mu s
$$

于是：

| 时间区间 | 状态 | 开关管电压 |
| :--- | :--- | :--- |
| $0\sim 50\ \mu s$ | $T$ 导通 | $v_T=0$ |
| $50\sim 100\ \mu s$ | 去磁复位 | $v_T=2V_d=4\text{ V}$ |

这里没有 `vT = Vd = 2V` 的平台，因为：

$$
t_{on}+t_m=50\ \mu s+50\ \mu s=100\ \mu s=T_s
$$

也就是去磁刚好占满整个关断时间。下一个周期一开始，开关又导通，`vT` 回到 0。

对应波形可参考：

![Example 10-B solution d from PPT](assets/pe09/example_10b_solution_d_ppt.png)

---

## 六、Flyback 与 Forward 对比速记

| 项目 | Flyback | Forward |
| :--- | :--- | :--- |
| 能量流向 | 先储能，后放能 | 导通时直接传能 |
| 关键电感 | 磁化电感储能 | 输出电感储能 |
| 电压增益 | `Vo/Vd = (N2/N1) D/(1-D)` | `Vo/Vd = (N2/N1) D` |
| 占空比限制 | 理想上无 0.5 限制 | 常见单管结构 `Dmax = 0.5` |
| 变压器本质 | 更像双绕组电感 | 主要是传能与隔离，磁化支路需复位 |

### 一句话总结

- Flyback：导通储能，关断放能；
- Forward：导通传能，关断复位。

---

## 七、最后记忆版

### Flyback

导通：

$$
v_1=V_d,\quad i_m\ \text{上升},\quad D\ \text{截止},\quad i_2=0
$$

关断：

$$
v_1=-\frac{N_1}{N_2}V_o,\quad i_m\ \text{下降},\quad D\ \text{导通},\quad i_1=0
$$

$$
\frac{V_o}{V_d}=\frac{N_2}{N_1}\frac{D}{1-D}
$$

### Forward

导通：

$$
D_1\ \text{导通},\quad D_2/D_3\ \text{关断},\quad i_L\ \text{上升},\quad i_m\ \text{上升}
$$

关断去磁：

$$
D_1\ \text{关断},\quad D_2/D_3\ \text{导通},\quad i_L\ \text{续流},\quad i_m\ \text{复位}
$$

$$
\frac{V_o}{V_d}=\frac{N_2}{N_1}D
$$

$$
N_3=N_1\ \text{时},\quad D_{\max}=0.5
$$
