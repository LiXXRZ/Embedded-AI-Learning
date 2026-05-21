# 频率响应、滤波器与谐振笔记

## 一、本章主线

这一章把电路从“某一个固定频率下怎么求解”推进到“频率变化时电路会怎样变化”。

主线可以分成三层：

1. 用传递函数描述输入与输出的关系；
2. 用幅频、相频特性判断滤波行为；
3. 用谐振、品质因数和带宽描述选频能力。

---

## 二、传递函数与频率响应

### 1. 传递函数

传递函数是输出相量和输入相量之比：

$$
H(j\omega)=\frac{Y(j\omega)}{X(j\omega)}
$$

若输入输出在同一端口，得到的是驱动点函数，例如：

$$
Z(j\omega)=\frac{\dot V}{\dot I}
$$

若输入输出位于不同端口，则可以得到：

- 电压增益；
- 电流增益；
- 转移阻抗；
- 转移导纳。

### 2. 一个最基本的传递函数例子

若某串联 RLC 电路中，输出取电容两端电压，则：

$$
H(j\omega)=\frac{\dot V_C}{\dot V_S}
=\frac{1/(j\omega C)}{R+j\omega L+1/(j\omega C)}
$$

分子分母同乘 $j\omega C$：

$$
H(j\omega)
=\frac1{1+j\omega RC-\omega^2LC}
$$

这说明传递函数通常会变成关于 $j\omega$ 的有理式。后面判断滤波、谐振，本质上都在看这个有理式如何随 $\omega$ 改变。

### 3. 频率响应

把

$$
H(j\omega)
$$

写成极坐标形式：

$$
H(j\omega)=a(\omega)e^{j\theta(\omega)}
$$

其中：

$$
a(\omega)=\lvert H(j\omega)\rvert
$$

$$
\theta(\omega)=\arg H(j\omega)
$$

它们分别对应：

- 幅频响应；
- 相频响应。

### 4. 为什么幅值和相位都要看

若一个网络对某个频率的输出幅值不变，但相位发生了明显偏移，它仍然改变了信号。  
因此只看“放大了多少”是不够的，还要看“相位被改了多少”。这也是 Bode 图通常总要成对画出幅频和相频两张图的原因。

---

## 三、分贝与 Bode 图

### 1. 功率比的分贝

$$
G_{\mathrm{dB}}=10\log_{10}\frac{P_2}{P_1}
$$

### 2. 电压比或电流比的分贝

在同一电阻上比较时：

$$
G_{\mathrm{dB}}=20\log_{10}\frac{V_2}{V_1}
$$

也可写成电流比形式。

常见数值：

- 幅值不变：$0\ \mathrm{dB}$；
- 功率加倍：$+3\ \mathrm{dB}$；
- 功率减半：$-3\ \mathrm{dB}$。

### 3. Bode 图

Bode 图通常采用：

- 横轴：对数频率；
- 纵轴：幅值或相位。

它的好处是能把很宽的频率范围压缩在一张图里，同时让乘法关系在分贝域里转成加法。

---

## 四、滤波器

### 1. 四种基本类型

| 类型 | 低频 | 高频 |
| :--- | :--- | :--- |
| 低通 | 通过 | 衰减 |
| 高通 | 衰减 | 通过 |
| 带通 | 中间一段通过 | 两端衰减 |
| 带阻 | 中间一段衰减 | 两端通过 |

### 2. 截止频率

截止频率定义为幅值下降到最大值的：

$$
\frac1{\sqrt2}=0.707
$$

处，也就是功率降到一半的位置，又称半功率点。

### 3. 判断滤波器类型的最快方法

先算两个端点：

$$
H(0),\qquad H(\infty)
$$

再看中间频率是否有峰或谷：

| 类型 | $H(0)$ | $H(\infty)$ |
| :--- | :--- | :--- |
| 低通 | 非零 | 0 |
| 高通 | 0 | 非零 |
| 带通 | 0 | 0 |
| 带阻 | 非零 | 非零 |

这是课件总结页里最适合先手判断的一条规则。

---

## 五、一阶低通与一阶高通

### 1. 一阶低通

典型形式：

$$
H(j\omega)=\frac{k\omega_c}{j\omega+\omega_c}
=\frac{k}{1+j\omega/\omega_c}
$$

幅频特性：

$$
a(\omega)=\frac{k}{\sqrt{1+(\omega/\omega_c)^2}}
$$

相频特性：

$$
\theta(\omega)=-\tan^{-1}\frac{\omega}{\omega_c}
$$

典型电路：

- RC 输出取电容；
- RL 输出取电阻。

### 2. 一阶高通

典型形式：

$$
H(j\omega)
=\frac{kj\omega}{j\omega+\omega_c}
$$

幅频特性：

$$
a(\omega)=\frac{k}{\sqrt{1+(\omega_c/\omega)^2}}
$$

相频特性：

$$
\theta(\omega)=\tan^{-1}\frac{\omega_c}{\omega}
$$

典型电路：

- RC 输出取电阻；
- RL 输出取电感。

### 3. 一阶低通与一阶高通对照

| 项目 | 一阶低通 | 一阶高通 |
| :--- | :--- | :--- |
| $\omega\to0$ | $H\to k$ | $H\to0$ |
| $\omega\to\infty$ | $H\to0$ | $H\to k$ |
| 截止点相位 | $-45^\circ$ | $+45^\circ$ |
| 物理直觉 | 放过慢变化 | 放过快变化 |

---

## 六、例题：设计有源一阶低通

目标：

$$
\lvert k\rvert=4,\qquad \omega_c=100\ \mathrm{rad/s}
$$

课件给出的反相有源低通满足：

$$
H(j\omega)
=-\frac{R_2}{R_1}\cdot\frac1{1+j\omega C R_2}
$$

因此：

$$
k=-\frac{R_2}{R_1}
$$

$$
\omega_c=\frac1{R_2C}
$$

取

$$
R_1=10\ \mathrm{k}\Omega
$$

为了得到幅值增益 4：

$$
R_2=40\ \mathrm{k}\Omega
$$

再由截止频率求电容：

$$
C=\frac1{R_2\omega_c}
=\frac1{40\times10^3\times100}
=250\ \mathrm{nF}
$$

---

## 七、二阶带通与带阻

### 1. 二阶带通

标准形式：

$$
H(j\omega)
=\frac{k\omega_0j\omega/Q}{(j\omega)^2+\omega_0j\omega/Q+\omega_0^2}
$$

其中：

- $k$：通带增益；
- $\omega_0$：中心角频率；
- $Q$：品质因数。

幅频函数：

$$
a(\omega)=
\frac{k}{\sqrt{1+Q^2\left(\frac{\omega}{\omega_0}-\frac{\omega_0}{\omega}\right)^2}}
$$

### 2. 带宽与品质因数

$$
B=\omega_{c2}-\omega_{c1}
$$

$$
Q=\frac{\omega_0}{B}
$$

并且：

$$
\omega_{c1}\omega_{c2}=\omega_0^2
$$

若 $Q>10$，可近似：

$$
\omega_{c1}\approx\omega_0-\frac B2,\qquad
\omega_{c2}\approx\omega_0+\frac B2
$$

### 3. 二阶带阻

带阻的本质是：

- 低频通过；
- 高频通过；
- 中心附近被抑制。

课件给出了一种通过低通和高通并联得到带阻的方法。

### 4. 课件中的二阶标准形式总表

| 类型 | 标准形式 |
| :--- | :--- |
| 二阶低通 | $\displaystyle H(j\omega)=\frac{k\omega_0^2}{(j\omega)^2+\frac{\omega_0}{Q}j\omega+\omega_0^2}$ |
| 二阶高通 | $\displaystyle H(j\omega)=\frac{k(j\omega)^2}{(j\omega)^2+\frac{\omega_0}{Q}j\omega+\omega_0^2}$ |
| 二阶带通 | $\displaystyle H(j\omega)=\frac{k\frac{\omega_0}{Q}j\omega}{(j\omega)^2+\frac{\omega_0}{Q}j\omega+\omega_0^2}$ |
| 二阶带阻 | $\displaystyle H(j\omega)=k\frac{(j\omega)^2+2\beta j\omega+\omega_0^2}{(j\omega)^2+\frac{\omega_0}{Q}j\omega+\omega_0^2}$ |

看到这些式子时，先观察分子会很有帮助：

- 常数项主导低频；
- $(j\omega)^2$ 主导高频；
- 单独的 $j\omega$ 只在中间频段占优势；
- 常数项和二次项都保留时，往往会出现带阻。

---

## 八、例题：两级电路组成带通

已知：

$$
C_1=100\ \mathrm{nF},\quad
C_2=400\ \mathrm{nF},\quad
R=1\ \mathrm{k}\Omega
$$

第一段是低通：

$$
H_1(j\omega)
=-\frac{1/RC_1}{j\omega+1/RC_1}
$$

第二段是高通：

$$
H_2(j\omega)
=-\frac{j\omega}{j\omega+1/RC_2}
$$

两级串联，总传函：

$$
H(j\omega)=H_1H_2
=\frac{j\omega/RC_1}{(j\omega+1/RC_1)(j\omega+1/RC_2)}
$$

数值代入：

$$
\frac1{RC_1}=10^4,\qquad
\frac1{RC_2}=2500
$$

所以：

$$
H(j\omega)
=\frac{j\omega\cdot10^4}{(j\omega+10^4)(j\omega+2500)}
$$

整理成标准带通形式后可读出：

$$
\omega_0=\sqrt{10^4\cdot2500}=5000\ \mathrm{rad/s}
$$

$$
B=10^4+2500=12500\ \mathrm{rad/s}
$$

$$
Q=\frac{\omega_0}{B}=0.4
$$

再由公式得到：

$$
\omega_{c1}\approx1754\ \mathrm{rad/s}
$$

$$
\omega_{c2}\approx14254\ \mathrm{rad/s}
$$

这个例题提醒我们：带通不一定非得由一个“天然带通”电路实现，也可以由低通和高通级联得到。

### 例题再拆一步：为什么它一定是带通

第一段低通会压掉高频，第二段高通会压掉低频。  
两段串联后：

- 低频被高通段挡住；
- 高频被低通段挡住；
- 中间频率两段都不太压制，于是留下一个通带。

这就是“低通 + 高通 = 带通”的电路直觉。

---

## 九、RLC 串联谐振

### 1. 谐振条件

串联 RLC 阻抗：

$$
Z(\omega)=r+j\left(\omega L-\frac1{\omega C}\right)
$$

谐振时虚部为零：

$$
\omega_0L=\frac1{\omega_0C}
$$

所以：

$$
\omega_0=\frac1{\sqrt{LC}}
$$

### 2. 谐振特性

在串联谐振时：

1. 总阻抗最小，且纯电阻：

$$
Z=r
$$

2. 电压与电流同相；
3. 功率因数为 1；
4. 电感、电容两端电压可能远大于电源电压。

### 3. 特性阻抗与品质因数

$$
\rho=\sqrt{\frac LC}
$$

$$
Q=\frac{\rho}{r}
=\frac{\omega_0L}{r}
=\frac1{\omega_0Cr}
$$

### 4. 带宽

$$
B=\frac{\omega_0}{Q}=\frac rL
$$

### 5. 串联谐振为什么会出现“电压放大”

在谐振点：

$$
I=\frac{V_S}{r}
$$

而

$$
V_L=I\omega_0L,\qquad
V_C=\frac{I}{\omega_0C}
$$

由于

$$
\omega_0L=\frac1{\omega_0C}=\rho
$$

所以：

$$
V_L=V_C=\frac{\rho}{r}V_S=QV_S
$$

这说明电感、电容上的电压都可能远大于电源电压，但它们彼此反相，在总电压中互相抵消。

---

## 十、例题：串联谐振中 $Q$ 与带宽

已知：

$$
L=1\ \mathrm{H},\qquad C=1\ \mu\mathrm{F}
$$

先求：

$$
\omega_0=\frac1{\sqrt{LC}}=1000\ \mathrm{rad/s}
$$

$$
\rho=\sqrt{\frac LC}=1000\ \Omega
$$

### 情况 1：$r=10\ \Omega$

$$
Q=\frac{\rho}{r}=100
$$

$$
B=\frac{\omega_0}{Q}=10\ \mathrm{rad/s}
$$

高 $Q$ 下：

$$
\omega_1\approx\omega_0-\frac B2=995\ \mathrm{rad/s}
$$

$$
\omega_2\approx\omega_0+\frac B2=1005\ \mathrm{rad/s}
$$

### 情况 2：$r=100\ \Omega$

$$
Q=10,\qquad B=100\ \mathrm{rad/s}
$$

$$
\omega_1\approx950\ \mathrm{rad/s},\qquad
\omega_2\approx1050\ \mathrm{rad/s}
$$

结论：损耗越大，$Q$ 越小，带宽越宽，选频越差。

---

## 十一、实际电感、电容的损耗模型

### 1. 实际电感

串联模型：

$$
L \text{ 与 } r_L
$$

高 $Q$ 时可近似换成并联模型：

$$
R_L\approx Q_L^2r_L
$$

### 2. 实际电容

类似地，也可在高 $Q$ 下进行串并联等效。

### 3. 高频下的常用近似

在高 $Q$ 情况下：

$$
r=\frac{X}{Q}
$$

$$
R=QX
$$

### 4. 串并联损耗模型的实用近似

对于实际电感：

$$
Q_L=\frac{\omega L}{r_L}
$$

若把串联损耗模型换成并联模型，高 $Q$ 时：

$$
R_L\approx Q_L^2r_L
$$

对于实际电容也可作类似处理。这个换算很有用，因为：

- 串联谐振更习惯把损耗看成串联电阻；
- 并联谐振更习惯把损耗看成并联电阻。

---

## 十二、负载与信号源对 $Q$ 的影响

源内阻、负载电阻都会引入额外损耗。分析时常把它们折算进总等效损耗中。

课件中的例题表明：

- 不带负载时，$Q$ 较高；
- 接上负载后，总损耗增大；
- $Q$ 下降，带宽增大。

### 例题：负载怎样把 $Q$ 拉低

课件中：

$$
Q_L=200,\qquad
L=1\ \mathrm{mH},\qquad
C=160\ \mathrm{pF}
$$

先求：

$$
\omega_0=\frac1{\sqrt{LC}}
=2.5\times10^6\ \mathrm{rad/s}
$$

$$
\rho=\sqrt{\frac LC}=2.5\times10^3\ \Omega
$$

电感自身损耗：

$$
r_L=\frac{\rho}{Q_L}
=\frac{2500}{200}
=12.5\ \Omega
$$

暂不接负载时：

$$
Q_1=\frac{\rho}{r_S+r_L}
=\frac{2500}{12.5+12.5}
=100
$$

接入负载后，经并联到串联等效又带来额外损耗：

$$
r_C=25\ \Omega
$$

于是：

$$
Q_2=\frac{2500}{12.5+12.5+25}
=50
$$

负载没有改变“这是一个谐振回路”的事实，却明显削弱了它的选频能力。

---

## 十三、RLC 并联谐振

### 1. 谐振条件

并联 RLC 的导纳：

$$
Y(\omega)=\frac1R+j\left(\omega C-\frac1{\omega L}\right)
$$

谐振时：

$$
\operatorname{Im}[Y]=0
$$

所以仍有：

$$
\omega_0=\frac1{\sqrt{LC}}
$$

### 2. 并联谐振特点

1. 输入阻抗最大；
2. 电源电流最小；
3. 电压与电流同相；
4. 电感、电容支路电流可能远大于源电流。

品质因数：

$$
Q=R\omega_0C=\frac{R}{\omega_0L}=\frac{R}{\rho}
$$

带宽：

$$
B=\frac{\omega_0}{Q}=\frac1{RC}
$$

### 3. 串联谐振与并联谐振对照

| 项目 | 串联谐振 | 并联谐振 |
| :--- | :--- | :--- |
| 判断条件 | $\operatorname{Im}[Z]=0$ | $\operatorname{Im}[Y]=0$ |
| 谐振时 | 阻抗最小 | 阻抗最大 |
| 电源电流 | 最大 | 最小 |
| 放大对象 | 支路电压 | 支路电流 |
| $Q$ | $\rho/r$ | $R/\rho$ |
| 带宽 | $r/L$ | $1/(RC)$ |

### 4. 实际并联谐振的频率会略微偏移

若实际电感含串联损耗 $r$，并联谐振频率不再严格等于理想值，而是：

$$
\omega_p
=\omega_0\sqrt{1-\frac1{Q_L^2}}
$$

当 $Q_L$ 很高时，

$$
\omega_p\approx\omega_0
$$

所以高 $Q$ 近似下，理想公式仍然很好用。

---

## 十四、例题：并联谐振设计

已知：

$$
\omega_0=10^5\ \mathrm{rad/s},\qquad
L=1\ \mathrm{mH}
$$

要求：

$$
B\le10^4\ \mathrm{rad/s}
$$

先由谐振频率求电容：

$$
C=\frac1{\omega_0^2L}
=\frac1{(10^5)^2\cdot10^{-3}}
=100\ \mathrm{nF}
$$

因为

$$
Q=\frac{\omega_0}{B}
$$

所以要满足带宽条件，必须有：

$$
Q\ge10
$$

并联谐振中：

$$
Q=\frac{R_{\mathrm{eq}}}{\omega_0L}
$$

于是：

$$
R_{\mathrm{eq}}\ge Q\omega_0L
=10\cdot10^5\cdot10^{-3}
=1000\ \Omega
$$

结合课件中 $R_s=2\ \mathrm{k}\Omega$ 的并联关系，最终得到：

$$
R\ge2\ \mathrm{k}\Omega
$$

---

## 十五、例题：并联谐振中的空载与带载

课件另一题给出：

$$
L=0.244\ \mathrm{H},\quad
C=0.5\ \mu\mathrm{F},\quad
r=32\ \Omega
$$

先求固有谐振频率：

$$
f_0=\frac1{2\pi\sqrt{LC}}
\approx456\ \mathrm{Hz}
$$

电感本身的品质因数：

$$
Q_L=\frac{\sqrt{L/C}}{r}
\approx21.8
$$

把串联损耗换成并联电阻：

$$
R=\frac{L}{Cr}
=15.3\ \mathrm{k}\Omega
$$

### 1. 空载

课件算得：

$$
Q_{\text{no-load}}\approx16.4
$$

于是：

$$
B_{\text{no-load}}
=\frac{f_0}{Q}
\approx27.8\ \mathrm{Hz}
$$

### 2. 带载

接上 $30\ \mathrm{k}\Omega$ 负载后：

$$
Q_{\text{load}}\approx11.8
$$

$$
B_{\text{load}}
\approx38.6\ \mathrm{Hz}
$$

负载越重，等效并联电阻越小，$Q$ 越低，带宽越宽。

---

## 十六、课件对齐补充：例题和易错边界

### 1. 课件中的 RL 低通例题

课件给出的串联 $RL$ 电路，输出取电阻两端电压，已知

$$
R=100\ \Omega,\qquad L=0.01\ \mathrm{H}
$$

传递函数为

$$
H(j\omega)=\frac{\dot V_o}{\dot V_s}
=\frac{R}{R+j\omega L}
=\frac{10^4}{j\omega+10^4}
$$

因此它是一阶低通，截止角频率为

$$
\omega_c=\frac RL=10^4\ \mathrm{rad/s}
$$

幅频和相频为

$$
a(\omega)=\frac1{\sqrt{1+(\omega/10^4)^2}}
$$

$$
\theta(\omega)=-\tan^{-1}\frac{\omega}{10^4}
$$

复习时可以用这个例题快速判断：输出取电阻，低频时电感近似短路，输出接近输入；高频时电感阻抗变大，输出被压低，所以是低通。

### 2. 分贝公式不要跨场景乱用

| 比较对象 | 分贝公式 | 前提 |
| :--- | :--- | :--- |
| 功率比 | $10\log_{10}(P_2/P_1)$ | 直接比较功率 |
| 电压比 | $20\log_{10}(V_2/V_1)$ | 两个电压作用在同一电阻或等效条件一致 |
| 电流比 | $20\log_{10}(I_2/I_1)$ | 两个电流流过同一电阻或等效条件一致 |

常用记忆：功率加倍是 $+3\ \mathrm{dB}$，功率减半是 $-3\ \mathrm{dB}$，幅值降到最大值的 $1/\sqrt2$ 也是 $-3\ \mathrm{dB}$。

### 3. 两级带通例题中漏掉的通带增益

在两级低通、高通级联例题中，最后有

$$
H(j\omega)=\frac{j\omega\cdot10^4}{(j\omega+10^4)(j\omega+2500)}
$$

整理成标准二阶带通形式：

$$
\omega_0=5000\ \mathrm{rad/s},\qquad B=12500\ \mathrm{rad/s},\qquad Q=0.4
$$

还可以读出通带增益

$$
k=\frac{10^4}{B}=\frac{10^4}{12500}=0.8
$$

这里 $Q=0.4$，明显不是高 $Q$。所以截止频率应使用课件给出的精确式，而不是直接套

$$
\omega_{c1}\approx\omega_0-\frac B2,
\qquad
\omega_{c2}\approx\omega_0+\frac B2
$$

高 $Q$ 近似只适合 $Q>10$ 且 $B\ll\omega_0$ 的窄带情况。

### 4. 实际电感、电容损耗模型的速查

高 $Q$ 近似下，串联损耗和并联损耗可以用下面关系快速互换：

$$
r\approx\frac{X}{Q},\qquad R\approx QX,
\qquad R\approx Q^2r
$$

其中 $X$ 是该频率下的电抗幅值。这个换算在谐振题里很常见：

- 串联谐振常把损耗折算成串联电阻；
- 并联谐振常把损耗折算成并联电阻；
- 源内阻和负载都会增加等效损耗，使 $Q$ 降低、带宽变宽。

## 十七、考前速记

1. 截止点就是 $0.707$ 最大幅值点，也是 $-3\ \mathrm{dB}$ 点；
2. 低通：

$$
\omega\to0 \Rightarrow H\to k,\qquad
\omega\to\infty \Rightarrow H\to0
$$

3. 高通刚好相反；
4. 带通：

$$
Q=\frac{\omega_0}{B}
$$

5. 串联谐振看阻抗最小；并联谐振看导纳最小；
6. $Q$ 越高，带宽越窄，选频越强；
7. 源内阻和负载都会降低 $Q$。
