# 正弦稳态交流电路笔记

## 一、这一章到底在做什么

正弦稳态分析的核心，是把原本随时间变化的正弦量变成**相量**，再把电感、电容分别换成复阻抗。这样一来，交流电路就能像直流电路一样列 KCL、KVL、节点方程和网孔方程，只不过数值从实数变成了复数。

本章有四条主线：

1. 用相量法分析复杂交流电路；
2. 区分平均功率、无功功率、视在功率和复功率；
3. 理解功率因数校正；
4. 掌握交流条件下的最大功率传输。

---

## 二、正弦量与相量

### 1. 正弦量的标准写法

若

$$
i(t)=I_m\cos(\omega t+\varphi)
$$

则它对应的相量可以写成三种等价形式：

$$
\dot I_m=I_m e^{j\varphi}=I_m\angle\varphi=I_m\cos\varphi+jI_m\sin\varphi
$$

这里：

- $I_m$ 是峰值；
- $\omega$ 是角频率；
- $\varphi$ 是初相角。

### 2. 正弦形式要先改写成余弦形式

相量默认对应余弦形式。若题目给的是

$$
i(t)=I_m\sin(\omega t+\varphi)
$$

应先写成

$$
i(t)=I_m\cos(\omega t+\varphi-90^\circ)
$$

所以

$$
\dot I_m=I_m\angle(\varphi-90^\circ)
$$

这是最容易在第一步就丢分的地方。

### 3. 峰值相量与有效值相量

本课件有时用峰值，有时用有效值。要分清：

$$
V_{\mathrm{eff}}=\frac{V_m}{\sqrt2},\qquad I_{\mathrm{eff}}=\frac{I_m}{\sqrt2}
$$

功率计算中通常更偏爱有效值，因为公式更整洁：

$$
P=V_{\mathrm{eff}}I_{\mathrm{eff}}\cos\varphi
$$

### 4. 为什么相量法能把微分方程变成代数方程

若

$$
i(t)=\Re\{\dot I e^{j\omega t}\}
$$

则

$$
\frac{di}{dt}
=\Re\{j\omega \dot I e^{j\omega t}\}
$$

也就是说，在单一角频率 $\omega$ 下，时域里的“求导”到了相量域就等价于“乘 $j\omega$”。因此：

$$
v_L=L\frac{di}{dt}
\quad\Longrightarrow\quad
\dot V_L=j\omega L\dot I
$$

$$
i_C=C\frac{dv}{dt}
\quad\Longrightarrow\quad
\dot I_C=j\omega C\dot V
$$

这就是为什么电感、电容能被替换成阻抗，也解释了为什么正弦稳态电路会忽然变得像直流电路一样好算。

---

## 三、阻抗、导纳与相量域电路

### 1. 三种基本元件

| 元件 | 阻抗 $Z$ | 导纳 $Y$ | 相位关系 |
| :--- | :--- | :--- | :--- |
| 电阻 $R$ | $R$ | $1/R$ | 电压、电流同相 |
| 电感 $L$ | $j\omega L$ | $1/(j\omega L)$ | 电压超前电流 $90^\circ$ |
| 电容 $C$ | $1/(j\omega C)$ | $j\omega C$ | 电流超前电压 $90^\circ$ |

### 2. 交流相量分析三步走

1. **变换**：把时域电源改成相量，把 $L,C$ 改成阻抗；
2. **求解**：使用节点法、网孔法、叠加、戴维宁等熟悉的方法；
3. **还原**：把求出的相量再变回时域表达式。

只要电路由**单一频率**激励，直流电路中的大多数方法在相量域中都还能用。

### 3. 复数运算小表

| 操作 | 最顺手的形式 |
| :--- | :--- |
| 加减 | 直角坐标形式 $a+jb$ |
| 乘除 | 极坐标形式 $M\angle\theta$ |
| 求相角 | $\theta=\tan^{-1}(b/a)$，注意象限 |
| 共轭 | $a+jb \mapsto a-jb$ |

实际做题时，经常是：

1. 列方程时用直角坐标；
2. 做乘除、相位比较时改成极坐标；
3. 最后答案再按题目要求写回时域。

---

## 四、例题：用节点法求 $v(t)$

课件例题中，所有激励的角频率都是 $\omega=2\ \mathrm{rad/s}$，先把元件和电源都写成相量：

- $6\cos2t\ \mathrm{A}\rightarrow 6\angle0^\circ\ \mathrm{A}$；
- $3\cos2t\ \mathrm{A}\rightarrow 3\angle0^\circ\ \mathrm{A}$；
- $4\sin2t\ \mathrm{V}=4\cos(2t-90^\circ)\ \mathrm{V}\rightarrow -j4\ \mathrm{V}$；
- $\dfrac34\mathrm{H}$ 的电感阻抗：

$$
Z_L=j\omega L=j\cdot2\cdot\frac34=j1.5\ \Omega
$$

设左侧节点电压为 $\dot V_1$，待求节点电压为 $\dot V$。由图列节点方程：

$$
\left(\frac12+1\right)\dot V_1-\dot V=6+3
$$

$$
-\dot V_1+\left(\frac{1}{j1.5}+\frac13+1\right)\dot V=-3-\frac{j4}{3}
$$

解方程得：

$$
\dot V=3.25+j1.25=3.48\angle21^\circ\ \mathrm{V}
$$

因此

$$
v(t)=3.48\cos(2t+21^\circ)\ \mathrm{V}
$$

这个例题最重要的不是最后数值，而是三件事：

1. 正弦源先改余弦；
2. 电感先改成 $j\omega L$；
3. 方程中复数可以像普通代数一样处理。

### 例题复盘：每一项从哪里来

第一条节点方程

$$
\left(\frac12+1\right)\dot V_1-\dot V=6+3
$$

对应左节点 KCL：

- 通过 $2\Omega$ 电阻流向地的电流为 $\dot V_1/2$；
- 通过 $1\Omega$ 电阻流向右节点的电流为 $\dot V_1-\dot V$；
- 两个电流源向该节点注入 $6+3$ A。

第二条节点方程

$$
-\dot V_1+\left(\frac{1}{j1.5}+\frac13+1\right)\dot V=-3-\frac{j4}{3}
$$

对应右节点 KCL：

- 经 $1\Omega$ 电阻到左节点；
- 经电感到地；
- 经 $3\Omega$ 电阻到右侧已知电压节点；
- 顶部 $3$ A 电流源从右节点流出。

把“方程长什么样”和“电路中哪条支路贡献了它”对应起来，后面遇到复杂节点法题就不容易慌。

---

## 五、戴维宁与诺顿等效

交流电路同样可以做戴维宁、诺顿等效。

### 1. 戴维宁等效的两个量

- 开路电压：

$$
\dot V_{\mathrm{OC}}
$$

- 等效阻抗：

$$
Z_0
$$

### 2. 求 $Z_0$ 的两种方法

1. 开短路法：

$$
Z_0=\frac{\dot V_{\mathrm{OC}}}{\dot I_{\mathrm{SC}}}
$$

2. 外加测试源法：
   - 独立电压源短路；
   - 独立电流源开路；
   - 在端口外加测试源；
   - 用

$$
Z_0=\frac{\dot V_{\mathrm{test}}}{\dot I_{\mathrm{test}}}
$$

受控源不能随便关掉，这是另一处常见失分点。

### 3. 受控源存在时，为什么测试源法尤其好用

若网络里含有受控源，直接把独立源置零后，内部仍可能有电流和电压关系。此时：

1. 在端口外加一个已知测试电压 $\dot V_{\text{test}}$；
2. 计算它激发出的测试电流 $\dot I_{\text{test}}$；
3. 用

$$
Z_0=\frac{\dot V_{\text{test}}}{\dot I_{\text{test}}}
$$

即可得到端口等效阻抗。  
这种方法的好处是：不需要猜内部“还活着”的受控源会不会影响结果，直接让它在方程里自然发挥作用。

---

## 六、理想运放交流电路

理想运放仍满足：

$$
i^+=i^-=0,\qquad v^+=v^-
$$

课件中的移相器例题给定：

$$
v_s=15\cos2000t,\qquad v_o=2\cos(2000t-90^\circ)
$$

先转相量：

$$
\dot V_s=15,\qquad \dot V_o=2\angle-90^\circ=-j2
$$

反相结构有

$$
\frac{\dot V_o}{\dot V_s}=-\frac{Z_2}{Z_1}
$$

代入后：

$$
-j2=-\frac{Z_2}{Z_1}\cdot15
$$

得

$$
Z_1=-j7.5Z_2
$$

若取

$$
Z_2=R=10\ \mathrm{k}\Omega
$$

则

$$
Z_1=\frac1{j\omega C}=-j75\ \mathrm{k}\Omega
$$

所以

$$ 
C=\frac1{\omega\cdot75\ \mathrm{k}\Omega}
=\frac1{2000\cdot75000}
=6.67\ \mathrm{nF}
$$

### 例题的本质

这道题不是“背一个移相器答案”，而是在做两件事：

1. 先由期望输出与输入的幅值、相位关系，反推出所需传递函数；
2. 再把这个传递函数拆成电阻和电容能实现的阻抗比。

这也是交流运放设计题最常见的套路。

---

## 七、交流功率

### 1. 瞬时功率与平均功率

瞬时功率：

$$
p(t)=v(t)i(t)
$$

若

$$
v(t)=V_m\cos(\omega t+\theta_v),\qquad
i(t)=I_m\cos(\omega t+\theta_i)
$$

则平均功率为

$$
P=\frac12V_mI_m\cos(\theta_v-\theta_i)
=V_{\mathrm{eff}}I_{\mathrm{eff}}\cos\varphi_Z
$$

其中

$$
\varphi_Z=\theta_v-\theta_i
$$

把

$$
\cos A\cos B=\frac12[\cos(A-B)+\cos(A+B)]
$$

代入后，还可以看见：

$$
p(t)=\frac12V_mI_m\cos(\theta_v-\theta_i)
+\frac12V_mI_m\cos(2\omega t+\theta_v+\theta_i)
$$

第一项是常数，正是平均功率；第二项以 $2\omega$ 摆动，平均值为零。  
这就是为什么交流功率里会同时出现“真正消耗的部分”和“来回交换的部分”。

### 2. 三种功率

| 名称 | 符号 | 单位 | 含义 |
| :--- | :--- | :--- | :--- |
| 有功功率 | $P$ | W | 真正被消耗并转化为热、机械等能量 |
| 无功功率 | $Q$ | Var | 电感、电容与电源之间往返交换的能量规模 |
| 视在功率 | $S$ | VA | 电源和设备必须承受的总容量 |

对于感性、容性负载：

$$
Q_L=X_LI_{\mathrm{eff}}^2>0,\qquad
Q_C=X_CI_{\mathrm{eff}}^2<0
$$

### 3. 功率因数

$$
pf=\cos\varphi_Z=\frac{P}{S}
$$

- 感性负载：电流滞后，滞后功率因数；
- 容性负载：电流超前，超前功率因数；
- 纯阻性负载：$pf=1$。

### 4. 复功率

使用有效值相量时：

$$
\dot S=\dot V_{\mathrm{eff}}\dot I_{\mathrm{eff}}^*=P+jQ
$$

并且

$$
\lvert \dot S\rvert=S=\sqrt{P^2+Q^2}
$$

串联、并联电路中都满足复功率守恒：

$$
\dot S_{\mathrm{total}}=\sum \dot S_k
$$

### 5. 功率三角形

由

$$
\dot S=P+jQ
$$

可把 $P,Q,S$ 画成直角三角形：

- 横边：$P$；
- 竖边：$Q$；
- 斜边：$S$。

于是：

$$
\tan\varphi_Z=\frac{Q}{P}
$$

功率因数校正，本质上就是在不改变 $P$ 的前提下，把竖边 $Q$ 压短，让斜边 $S$ 也随之缩短。

---

## 八、例题：为什么不能把总电压直接套进电阻公式

若

$$
Z=4+j3\ \Omega,\qquad \dot V=10\angle0^\circ\ \mathrm{V}
$$

则

$$
\dot I=\frac{\dot V}{Z}
=\frac{10}{4+j3}
=2\angle-36.9^\circ\ \mathrm{A}
$$

平均功率可以这样算：

$$
P=\frac12V_mI_m\cos36.9^\circ
=\frac12\cdot10\cdot2\cdot\frac45
=8\ \mathrm{W}
$$

也可以这样算：

$$
P=\frac12I_m^2R
=\frac12\cdot2^2\cdot4
=8\ \mathrm{W}
$$

这里容易问：为什么是 $I^2R$，不是 $I^2Z$？

因为题目要求的是平均功率 $P$，也就是真正被负载消耗掉的有功功率。对

$$
Z=R+jX
$$

来说，只有实部 $R$ 会消耗平均功率；虚部 $jX$ 只表示电感、电容和电源之间来回交换能量，平均下来不消耗能量。

所以在使用峰值相量时：

$$
P=\frac12 I_m^2R
$$

如果把整个阻抗代进去，得到的不是单纯的平均功率，而是复功率：

$$
\dot S=\frac12\lvert\dot I_m\rvert^2Z
=\frac12\cdot2^2(4+j3)
=8+j6
$$

其中

$$
P=\operatorname{Re}(\dot S)=8\ \mathrm{W},\qquad Q=\operatorname{Im}(\dot S)=6\ \mathrm{var}
$$

也就是说，$I^2Z$ 里面同时包含有功功率和无功功率；如果只问平均功率，就只取电阻部分 $R$。

但不能写成

$$
P=\frac{V_{\mathrm{eff}}^2}{R}
$$

因为总电压并不是只落在电阻上，阻抗里还有电抗部分。

---

## 九、功率因数校正

工业负载多为感性，常见问题是：

- 电流滞后；
- $Q$ 较大；
- 视在功率和线路电流都偏大。

最常见的修正方法是在负载两端**并联电容**，用电容提供负无功去抵消感性负载的正无功。

### 例题思路

已知：

$$
V=220\ \mathrm{V},\quad I=0.4\ \mathrm{A},\quad P=40\ \mathrm{W}
$$

先算原来的：

$$
S=VI=88\ \mathrm{VA}
$$

$$
pf=\frac{P}{S}=\frac{40}{88}=0.455
$$

$$
\varphi=\cos^{-1}(0.455)\approx63^\circ
$$

$$
Q=S\sin\varphi\approx78.4\ \mathrm{Var}
$$

接入电容后，课件给出新的功率因数约为 $0.99$，于是

$$
\varphi'\approx8.75^\circ
$$

$$
S'=\frac{P}{\cos\varphi'}\approx40.5\ \mathrm{VA}
$$

$$
Q'=S'\sin\varphi'\approx6.18\ \mathrm{Var}
$$

所以电容需要补偿的无功大约为：

$$
Q_C=Q-Q'\approx72.2\ \mathrm{Var}
$$

结论：有功功率没变，但无功功率、视在功率和总电流都下降了。

若继续求电容值，则有：

$$
|Q_C|=\omega CV^2
$$

所以：

$$
C=\frac{|Q_C|}{\omega V^2}
$$

在本题中：

$$
\omega=2\pi f=2\pi\cdot50
$$

$$
C=\frac{72.2}{2\pi\cdot50\cdot220^2}
\approx4.75\ \mu\mathrm{F}
$$

这正对应课件给出的补偿电容。

---

## 十、最大功率传输

先把本节最容易混的量说清楚：如果课件在电源旁边标了 `(rms)`，或者功率公式写成

$$
P=I^2R,\qquad P=\frac{V^2}{R}
$$

而没有 $\dfrac12$，那么这里的 $I$ 和 $V$ 都是**有效值**。`rms` 就是 effective value，有效值，也叫均方根值。对正弦量：

$$
V_{\mathrm{eff}}=\frac{V_m}{\sqrt2},\qquad I_{\mathrm{eff}}=\frac{I_m}{\sqrt2}
$$

相量的模不一定是峰值，它取决于课件一开始采用的是峰值相量还是有效值相量。本节例题中电流源写着 $2\angle0^\circ\ \mathrm{A}\ (\mathrm{rms})$，所以后面由它算出的 $\dot V_{\mathrm{OC}}$、$\dot V_L$、$\dot I$ 都按有效值相量理解。

设源侧等效阻抗为

$$
Z_S=R_S+jX_S
$$

负载为

$$
Z_L=R_L+jX_L
$$

### 1. 共轭匹配

若 $R_L$ 和 $X_L$ 都可调，则最大功率条件为：

$$
Z_L=Z_S^*=R_S-jX_S
$$

这叫**共轭匹配**。

此时

$$
P_{\max}=\frac{V_{\mathrm{OC,eff}}^2}{4R_S}
$$

为什么虚部要取相反数？先从电流有效值推一遍。总阻抗为

$$
Z_{\mathrm{total}}=(R_S+R_L)+j(X_S+X_L)
$$

所以负载电流相量为

$$
\dot I=\frac{\dot V_S}{(R_S+R_L)+j(X_S+X_L)}
$$

由于本节使用有效值相量，电流有效值就是相量电流的模：

$$
I_{\mathrm{eff}}=|\dot I|
=\frac{|\dot V_S|}{\sqrt{(R_S+R_L)^2+(X_S+X_L)^2}}
$$

负载平均功率只由 $R_L$ 消耗，因此

$$
P_L=I_{\mathrm{eff}}^2R_L
=\frac{V_S^2R_L}{(R_S+R_L)^2+(X_S+X_L)^2}
$$

这里的 $V_S$ 是有效值。要想让分母尽可能小，第一步就应先令：

$$
X_S+X_L=0
$$

也就是：

$$
X_L=-X_S
$$

随后只剩纯电阻问题，再由求导或经典直流结论得到：

$$
R_L=R_S
$$

### 2. 模匹配

若负载相角固定，只能改变阻抗模值，则最大功率条件为：

$$
\lvert Z_L\rvert=\lvert Z_S\rvert
$$

这叫**模匹配**。它是在受限条件下的最好结果，但通常不如共轭匹配取得的最大功率大。

### 3. 课件例题

由电路可得：

$$
\dot V_{\mathrm{OC}}=200\angle0^\circ\ \mathrm{V}
$$

$$
Z_0=100-j100=100\sqrt2\angle-45^\circ\ \Omega
$$

#### 情况 1：负载可任意调

$$
Z_L=Z_0^*=100+j100\ \Omega
$$

$$
P_{\max}=\frac{V_{\mathrm{OC}}^2}{4R_0}
=\frac{200^2}{4\cdot100}
=100\ \mathrm{W}
$$

#### 情况 2：负载只能是纯电阻

此时按模匹配：

$$
R_L=\lvert Z_0\rvert=100\sqrt2\ \Omega
$$

负载电压由分压得到：

$$
\dot V_L=\dot V_{\mathrm{OC}}\frac{R_L}{Z_0+R_L}
$$

代入本题数据：

$$
\dot V_L
=200\angle0^\circ\cdot\frac{100\sqrt2}{100-j100+100\sqrt2}
\approx108.2\angle22.5^\circ\ \mathrm{V}
$$

这里的 $\dot V_L$ 也是**有效值相量**，不是峰值。因为整道题从 $2\angle0^\circ\ \mathrm{A}\ (\mathrm{rms})$ 开始，后面相量都沿用 rms 约定。

所以平均功率直接写：

$$
P'_{\max}=\frac{V_{L,\mathrm{eff}}^2}{R_L}
=\frac{108.2^2}{100\sqrt2}
\approx82.8\ \mathrm{W}
$$

课件写 $82.3\ \mathrm{W}$ 多半是中间取值或四舍五入造成的差异；按 $108.2\ \mathrm{V}$ 计算更接近 $82.8\ \mathrm{W}$。

这个结果比共轭匹配时的 $100\ \mathrm{W}$ 小，说明**模匹配是受限制条件下的最好，不是全局最好**。

---

## 十一、课件对齐补充：复习时最该补上的几块

### 1. 戴维宁/诺顿等效题的复习版流程

课件里的戴维宁例题本质仍然是三步，不要被交流符号吓住：

1. 先定频率，把电容、电感换成阻抗。例如本题角频率为 $\omega=3\ \mathrm{rad/s}$，若 $C=1/3\ \mathrm{F}$，则

$$
Z_C=\frac1{j\omega C}=\frac1{j\cdot3\cdot(1/3)}=-j\ \Omega
$$

2. 求输出端开路电压 $\dot V_{OC}$。开路时负载电流为零，但内部支路仍然可能有电流，不能直接把某个元件电压当作答案。
3. 求等效阻抗 $Z_0$。可以用开短路法

$$
Z_0=\frac{\dot V_{OC}}{\dot I_{SC}}
$$

也可以把独立源置零后外加测试源，用

$$
Z_0=\frac{\dot V_{test}}{\dot I_{test}}
$$

课件该题最后得到

$$
v(t)=2\sqrt{10}\cos(3t-26.6^\circ)\ \mathrm{V}
$$

复习时重点记住：相量域里求到的是有效值还是峰值要前后一致。如果中间一直用有效值相量，最后写回时域峰值时要乘 $\sqrt2$。

### 2. 输入阻抗题遇到受控源时怎么做

课件里有一道“从电源端看进去求输入阻抗”的题，电路里含有受控源。处理这类题时不要把受控源关掉，正确套路是：

1. 保留受控源；
2. 在输入端写

$$
Z_{in}=\frac{\dot V_s}{\dot I}
$$

或外加测试源；
3. 用节点法、网孔法把受控量和测试量联系起来；
4. 最后只保留端口电压与端口电流之比。

一句话：独立源可以按规则置零，受控源必须随方程一起活着。

### 3. 功率题的峰值/有效值警戒线

功率公式最容易错在“峰值”和“有效值”混用。复习时按下面这张表检查：

| 使用的相量 | 复功率公式 | 平均功率公式 |
| :--- | :--- | :--- |
| 有效值相量 | $\dot S=\dot V_{eff}\dot I_{eff}^{*}$ | $P=V_{eff}I_{eff}\cos\varphi$ |
| 峰值相量 | $\dot S=\dfrac12\dot V_m\dot I_m^{*}$ | $P=\dfrac12V_mI_m\cos\varphi$ |

最大功率传输也一样：

$$
P_{max}=\frac{V_{OC,eff}^2}{4R_0}
$$

如果题目给的是峰值开路电压，则写成

$$
P_{max}=\frac{V_{OC,m}^2}{8R_0}
$$

### 4. 共轭匹配和模匹配的区别再压实一次

| 条件 | 最优规则 | 适用场景 |
| :--- | :--- | :--- |
| 负载复阻抗实部、虚部都可调 | $Z_L=Z_S^*$ | 全局最大功率 |
| 负载相角固定，只能调模值 | $\lvert Z_L \rvert = \lvert Z_S \rvert$ | 受限条件下最大功率 |

所以课件例题中：

- 可任意调负载时，$Z_L=100+j100\ \Omega$，$P_{max}=100\ \mathrm{W}$；
- 负载只能是纯电阻时，$R_L=|Z_0|=100\sqrt2\ \Omega$，按 $108.2\ \mathrm{V}$ 计算 $P'_{max}\approx82.8\ \mathrm{W}$，课件的 $82.3\ \mathrm{W}$ 可看作取值差异。

模匹配不是“和共轭匹配一样好”，它只是限制条件下的最优。

## 十二、考前速记

1. 相量默认以余弦为基准；
2. 电感写 $j\omega L$，电容写 $1/(j\omega C)$；
3. 功率题先判断题目给的是峰值还是有效值；
4. $P$ 看实部，$Q$ 看虚部，$S$ 看模长；
5. 感性负载用并联电容校正功率因数；
6. 最大功率传输：
   - 可调复阻抗：共轭匹配；
   - 只能调模值：模匹配。
