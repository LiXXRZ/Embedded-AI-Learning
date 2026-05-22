# 磁耦合电路笔记

## 一、本章主线

这一章研究的是：两个电感线圈靠得足够近时，一个线圈中的时变电流会通过磁通影响另一个线圈，从而在另一个线圈中感应电压。

主线可以分成三层：

1. 从自感推广到互感，理解互感电压的大小和极性；
2. 用同名端法、网孔法、互感消去法和反映阻抗法分析含互感电路；
3. 把强耦合、无损的极限情况抽象成理想变压器，并用变比做阻抗折算和功率匹配。

这一章最容易错的不是公式本身，而是互感项前面的正负号。

---

## 二、自感回顾

### 1. 法拉第电磁感应

线圈匝数为 $N$，穿过线圈的磁通为 $\phi$ 时，感应电压满足

$$
v(t)=N\frac{d\phi}{dt}
$$

电流产生磁场，磁场形成磁通；在线性磁介质中，磁通与电流成正比。

### 2. 自感

若线圈自身电流 $i$ 产生的磁链为

$$
\psi=N\phi
$$

则自感定义为

$$
L=\frac{\psi}{i}=N\frac{d\phi}{di}
$$

因此

$$
v(t)=L\frac{di}{dt}
$$

自感大小与磁导率 $\mu$、匝数 $N$、线圈尺寸等有关。课件中长直螺线管的结论可以理解为：匝数越多、磁路越容易导磁，自感越大。

---

## 三、互感

### 1. 互感是怎么来的

设两个线圈 $L_1,L_2$ 靠得很近。线圈 1 中电流 $i_1$ 产生的磁通，一部分只穿过线圈 1，一部分同时穿过线圈 2。

- 只与线圈 1 自身交链的磁通，对应自感 $L_1$；
- 与线圈 2 交链的磁通，对应互感 $M_{21}$。

同理，线圈 2 中电流 $i_2$ 也会在线圈 1 中产生互感作用。在线性互易磁路中：

$$
M_{12}=M_{21}=M
$$

互感 $M$ 的单位也是亨利 H。

### 2. 互感电压

若 $i_1$ 变化，会在线圈 2 中产生互感电压：

$$
v_{2M}=M\frac{di_1}{dt}
$$

若 $i_2$ 变化，会在线圈 1 中产生互感电压：

$$
v_{1M}=M\frac{di_2}{dt}
$$

注意：$M$ 本身总取正值，真正需要判断正负的是互感电压在所选参考方向下是加号还是减号。

---

## 四、同名端法

### 1. 同名端的规则

课件给出的同名端规则是：

若一个线圈的电流从同名端流入，则它在另一个线圈中感应出的互感电压，在另一个线圈的同名端为正。

等价地说：

- 电流从同名端进入，会让另一个线圈的同名端感应为正；
- 电流从非同名端进入，会让另一个线圈的非同名端感应为正。

这条规则比直接想右手定则、楞次定律更适合做电路题。

### 2. 写互感项正负号的快速判断

在常用被动参考方向下：

- 两个参考电流都进入同名端，互感项取正；
- 两个参考电流都离开同名端，互感项也取正；
- 一个进入同名端、另一个离开同名端，互感项取负。

所以一组常见方程为

$$
v_1=L_1\frac{di_1}{dt}+M\frac{di_2}{dt}
$$

$$
v_2=M\frac{di_1}{dt}+L_2\frac{di_2}{dt}
$$

另一种同名端或电流参考方向下，也可能写成

$$
v_1=L_1\frac{di_1}{dt}-M\frac{di_2}{dt}
$$

$$
v_2=L_2\frac{di_2}{dt}-M\frac{di_1}{dt}
$$

不要死背某一种符号，先看同名端和电流方向。

### 3. 例题：由同名端判断互感电压

课件例题中给出

$$
M=2\ \mathrm{H}
$$

若 $i_2=5\sin45t\ \mathrm{A}$，且 $i_1=0$，由同名端方向判断：

$$
v_1(t)=-M\frac{di_2}{dt}
$$

于是

$$
v_1(t)=-2\cdot 5\cdot45\cos45t
=-450\cos45t\ \mathrm{V}
$$

若 $i_1=-8e^{-t}\ \mathrm{A}$，且 $i_2=0$，则

$$
v_2(t)=-M\frac{di_1}{dt}
$$

因为

$$
\frac{di_1}{dt}=8e^{-t}
$$

所以

$$
v_2(t)=-16e^{-t}\ \mathrm{V}
$$

这题最重要的是：先由同名端定符号，再求导。

---

## 五、相量域中的互感

在正弦稳态下，

$$
\frac{d}{dt}\longrightarrow j\omega
$$

因此自感阻抗为

$$
j\omega L
$$

互感项则变成

$$
j\omega M
$$

若互感项为正，则可写为

$$
\dot V_1=j\omega L_1\dot I_1+j\omega M\dot I_2
$$

$$
\dot V_2=j\omega M\dot I_1+j\omega L_2\dot I_2
$$

若互感项为负，只需要把相应的 $+j\omega M$ 改成 $-j\omega M$。

复习时可以把互感看成一个受控电压源：

$$
\dot V_{1M}=\pm j\omega M\dot I_2,\qquad
\dot V_{2M}=\pm j\omega M\dot I_1
$$

这样做网孔法时会更直观。

---

## 六、耦合电感的串联、并联与耦合系数

### 1. 串联同向与反向

两个耦合电感串联时，等效电感取决于磁通是相助还是相消。

串联相助：

$$
L_{eq}=L_1+L_2+2M
$$

串联相消：

$$
L_{eq}=L_1+L_2-2M
$$

判断时看两个电流产生的磁通是否同向。若都从同名端流入，通常是相助；若一个从同名端流入、一个从非同名端流入，通常是相消。

#### 串联公式推导

串联时两个线圈中流过同一个电流。若为串联相助，按被动参考方向可写成

$$
\dot V_1=j\omega L_1\dot I+j\omega M\dot I
$$

$$
\dot V_2=j\omega M\dot I+j\omega L_2\dot I
$$

总电压为

$$
\dot V=\dot V_1+\dot V_2
$$

因此

$$
\dot V
=j\omega(L_1+L_2+2M)\dot I
$$

所以

$$
\boxed{
L_{eq}=L_1+L_2+2M
}
$$

若为串联相消，互感项为负：

$$
\dot V_1=j\omega L_1\dot I-j\omega M\dot I
$$

$$
\dot V_2=-j\omega M\dot I+j\omega L_2\dot I
$$

于是

$$
\dot V
=j\omega(L_1+L_2-2M)\dot I
$$

所以

$$
\boxed{
L_{eq}=L_1+L_2-2M
}
$$

### 2. 并联等效

课件给出的并联等效为：

同向并联：

$$
L_{eq}=\frac{L_1L_2-M^2}{L_1+L_2-2M}
$$

反向并联：

$$
L_{eq}=\frac{L_1L_2-M^2}{L_1+L_2+2M}
$$

这一组公式不如串联公式常用，复习时更重要的是知道：并联时同名端连接方式会改变分母里的互感项符号。

#### 并联公式推导

并联时两个线圈端电压相同：

$$
\dot V_1=\dot V_2=\dot V
$$

总电流为

$$
\dot I=\dot I_1+\dot I_2
$$

同向并联时，两个支路电流相对于同名端方向相同，互感项取正：

$$
\dot V=j\omega L_1\dot I_1+j\omega M\dot I_2
$$

$$
\dot V=j\omega M\dot I_1+j\omega L_2\dot I_2
$$

两式相减并约去 \(j\omega\)：

$$
(L_1-M)\dot I_1=(L_2-M)\dot I_2
$$

由这个关系配合

$$
\dot I=\dot I_1+\dot I_2
$$

可解出等效输入关系

$$
\dot V=j\omega
\frac{L_1L_2-M^2}{L_1+L_2-2M}\dot I
$$

因此

$$
\boxed{
L_{eq}=\frac{L_1L_2-M^2}{L_1+L_2-2M}
}
$$

反向并联时，互感项取负：

$$
\dot V=j\omega L_1\dot I_1-j\omega M\dot I_2
$$

$$
\dot V=-j\omega M\dot I_1+j\omega L_2\dot I_2
$$

同理可得

$$
\boxed{
L_{eq}=\frac{L_1L_2-M^2}{L_1+L_2+2M}
}
$$

#### 带串联元件的并联耦合支路

如果某一支路除了电感外还串联电阻、电容或负载，就不能直接套纯电感并联公式。此时仍从方程法出发。

并联网络也可以先用导纳来算。导纳是阻抗的倒数：

$$
Y=\frac{1}{Z}
$$

并联时导纳相加：

$$
Y_{\text{total}}=Y_1+Y_2+\cdots
$$

最后如果需要总阻抗，再取倒数：

$$
\boxed{
Z_{\text{total}}=\frac{1}{Y_{\text{total}}}
}
$$

这个思路在“多个支路并联，其中有电容、电感和复阻抗负载”的题里很方便。例如若电容支路阻抗为

$$
Z_C=-jX_C
$$

则电容支路导纳为

$$
Y_C=\frac{1}{-jX_C}=\frac{j}{X_C}
$$

注意：这里是电容这一条支路的导纳等于 \(j/X_C\)，不是整个并联网络的总导纳都等于 \(1/X_C\)。总导纳必须把所有并联支路都加起来。

令

$$
Z_1=j\omega L_1
$$

$$
Z_2=j\omega L_2+Z_{\text{series}}
$$

$$
Z_m=j\omega M
$$

若两支路电流相对于同名端方向相同，则

$$
\dot V=Z_1\dot I_1+Z_m\dot I_2
$$

$$
\dot V=Z_m\dot I_1+Z_2\dot I_2
$$

且

$$
\dot I=\dot I_1+\dot I_2
$$

解得通用输入阻抗

$$
\boxed{
Z_{in}
=\frac{Z_1Z_2-Z_m^2}{Z_1+Z_2-2Z_m}
}
$$

若两支路电流相对于同名端方向相反，只需把 \(Z_m\) 换成 \(-Z_m\)，分母中的 \(-2Z_m\) 会相应变成 \(+2Z_m\)。

### 3. 耦合系数

耦合系数定义为

$$
k=\frac{M}{M_{\max}}=\frac{M}{\sqrt{L_1L_2}}
$$

满足

$$
0\le k\le1
$$

因此

$$
M\le\sqrt{L_1L_2}
$$

常见判断：

- $k=1$：完全耦合；
- $k>0.5$：强耦合；
- $k<0.5$：弱耦合。

---

## 七、耦合电感中的储能

耦合电感的储能不仅包含两个线圈自身的能量，还包含互感项。

若两个电流产生的磁通相助：

$$
w(t)=\frac12L_1i_1^2+\frac12L_2i_2^2+Mi_1i_2
$$

若两个电流产生的磁通相消：

$$
w(t)=\frac12L_1i_1^2+\frac12L_2i_2^2-Mi_1i_2
$$

#### 储能公式推导

以磁通相助为例：

$$
v_1=L_1\frac{di_1}{dt}+M\frac{di_2}{dt}
$$

$$
v_2=M\frac{di_1}{dt}+L_2\frac{di_2}{dt}
$$

耦合电感吸收的瞬时功率为

$$
p=v_1i_1+v_2i_2
$$

代入：

$$
p
=L_1i_1\frac{di_1}{dt}
+L_2i_2\frac{di_2}{dt}
+M\left(i_1\frac{di_2}{dt}+i_2\frac{di_1}{dt}\right)
$$

注意到

$$
\frac{d}{dt}\left(\frac12L_1i_1^2\right)
=L_1i_1\frac{di_1}{dt}
$$

$$
\frac{d}{dt}\left(\frac12L_2i_2^2\right)
=L_2i_2\frac{di_2}{dt}
$$

$$
\frac{d}{dt}(Mi_1i_2)
=M\left(i_1\frac{di_2}{dt}+i_2\frac{di_1}{dt}\right)
$$

所以

$$
p=\frac{dw}{dt}
$$

积分得到

$$
\boxed{
w(t)=\frac12L_1i_1^2+\frac12L_2i_2^2+Mi_1i_2
}
$$

若互感项为负，推导完全相同，只是最后一项变为

$$
-Mi_1i_2
$$

因为储能必须满足

$$
w(t)\ge0
$$

所以可以推出

$$
M\le\sqrt{L_1L_2}
$$

也就是前面耦合系数 $k\le1$ 的物理来源。

---

## 八、含互感电路的分析方法

### 1. 方程法：通用模板

方程法是分析互感电路的底层方法。后面的串联公式、并联公式、反映阻抗法，本质上都是在方程法基础上加入特定连接条件后化简得到的。

做题流程：

1. 先给每个耦合线圈选电流参考方向，例如 \(\dot I_1,\dot I_2\)；
2. 给每个线圈按被动参考方向标电压 \(\dot V_1,\dot V_2\)，即电流流入的一端取为电压正端；
3. 判断每个电流是进入同名端还是离开同名端；
4. 写耦合电感方程；
5. 再根据外部连接补上 KVL、KCL、开路、短路或负载关系；
6. 解出目标量，例如 \(Z_{in}\)、电流、电压或功率。

若两个参考电流相对于同名端方向相同，即都进入同名端或都离开同名端，则互感项取正：

$$
\boxed{
\begin{aligned}
\dot V_1&=j\omega L_1\dot I_1+j\omega M\dot I_2\\
\dot V_2&=j\omega M\dot I_1+j\omega L_2\dot I_2
\end{aligned}}
$$

若一个电流进入同名端、另一个电流离开同名端，则互感项取负：

$$
\boxed{
\begin{aligned}
\dot V_1&=j\omega L_1\dot I_1-j\omega M\dot I_2\\
\dot V_2&=-j\omega M\dot I_1+j\omega L_2\dot I_2
\end{aligned}}
$$

常见连接条件可以直接套在这两式上：

- 副边开路：

$$
\dot I_2=0
$$

- 副边短路：

$$
\dot V_2=0
$$

- 副边接负载：

$$
\dot V_2=-Z_L\dot I_2
$$

上式的负号来自二端口常用约定：\(\dot I_2\) 常取流入线圈端口，而负载电流自然方向常取从线圈流向负载。若自己重新定义负载电流方向，只要前后一致即可。

- 并联连接：

$$
\dot V_1=\dot V_2=\dot V,\qquad
\dot I=\dot I_1+\dot I_2
$$

- 串联连接：

$$
\dot I_1=\dot I_2=\dot I
$$

或根据绕组方向写成 \(\dot I_1=-\dot I_2\)。关键不是死背正负，而是回到同名端判断互感项。

一句话总结：

$$
\boxed{\text{先写耦合电感方程，再写外部连接条件。}}
$$

### 2. 系统网孔法

最直接的方法是：保留互感项，按网孔电流写 KVL。

课件例题中有

$$
\dot V_1=10\angle0^\circ\ \mathrm{V}
$$

网孔方程为

$$
(1+j10)\dot I_1-j90\dot I_2=10
$$

$$
(400+j1000)\dot I_2-j90\dot I_1=0
$$

解得

$$
\dot I_2=0.172\angle-16.7^\circ\ \mathrm{A}
$$

于是

$$
\frac{\dot V_2}{\dot V_1}
=\frac{400(0.172\angle-16.7^\circ)}{10\angle0^\circ}
=6.88\angle-16.7^\circ
$$

这类题的核心是：互感项进入每个网孔方程时，符号要由同名端决定。

### 3. 例题：两个网孔电流

课件另一道网孔法例题中，整理后得到

$$
(4+j3)\dot I_1-j8\dot I_2=100
$$

$$
-j8\dot I_1+(5+j18)\dot I_2=0
$$

解得

$$
\dot I_1=20.3\angle3.5^\circ\ \mathrm{A}
$$

$$
\dot I_2=8.69\angle19^\circ\ \mathrm{A}
$$

这个例题提醒：互感项可能来自两个地方，一个是线圈之间的互感，一个是共享支路的普通阻抗项。列方程时要把两类项分清。

### 4. 例题对照：串联耦合电感

设两个耦合电感串联，要求等效电感。

#### 公式法

先判断磁通相助还是相消：

- 相助：

$$
L_{eq}=L_1+L_2+2M
$$

- 相消：

$$
L_{eq}=L_1+L_2-2M
$$

#### 方程法

若为相助，两线圈电流同为 \(\dot I\)，且互感项为正：

$$
\dot V_1=j\omega L_1\dot I+j\omega M\dot I
$$

$$
\dot V_2=j\omega M\dot I+j\omega L_2\dot I
$$

总电压：

$$
\dot V=\dot V_1+\dot V_2
=j\omega(L_1+L_2+2M)\dot I
$$

所以

$$
L_{eq}=L_1+L_2+2M
$$

若互感项为负，同理得到

$$
L_{eq}=L_1+L_2-2M
$$

### 5. 例题对照：并联耦合支路带电容，对应 Figure 4(b)

这类题不能直接套纯电感并联公式，因为其中一条支路串了电容。

#### 公式法

把每条支路先写成阻抗：

$$
Z_1=j\omega L_1
$$

$$
Z_2=j\omega L_2+\frac{1}{j\omega C}
$$

互感阻抗为

$$
Z_m=j\omega M
$$

若两支路电流相对于同名端方向相同，则可直接用带串联元件的并联耦合支路公式：

$$
\boxed{
Z_{ab}
=\frac{Z_1Z_2-Z_m^2}{Z_1+Z_2-2Z_m}
}
$$

代入：

$$
\boxed{
Z_{ab}
=
\frac{
(j\omega L_1)\left(j\omega L_2+\frac{1}{j\omega C}\right)
-(j\omega M)^2
}{
j\omega L_1+j\omega L_2+\frac{1}{j\omega C}-2j\omega M
}
}
$$

#### 方程法

设输入端电压为 \(\dot V\)，两支路电流为 \(\dot I_1,\dot I_2\)，总输入电流为

$$
\dot I=\dot I_1+\dot I_2
$$

两支路电压相同：

$$
\dot V=Z_1\dot I_1+Z_m\dot I_2
$$

$$
\dot V=Z_m\dot I_1+Z_2\dot I_2
$$

写成矩阵形式：

$$
\begin{bmatrix}
Z_1 & Z_m\\
Z_m & Z_2
\end{bmatrix}
\begin{bmatrix}
\dot I_1\\
\dot I_2
\end{bmatrix}
=
\begin{bmatrix}
\dot V\\
\dot V
\end{bmatrix}
$$

行列式为

$$
\Delta=Z_1Z_2-Z_m^2
$$

解得

$$
\dot I_1=\dot V\frac{Z_2-Z_m}{\Delta}
$$

$$
\dot I_2=\dot V\frac{Z_1-Z_m}{\Delta}
$$

所以总电流

$$
\dot I
=\dot V\frac{Z_1+Z_2-2Z_m}{\Delta}
$$

因此

$$
Z_{ab}
=\frac{\dot V}{\dot I}
=\frac{\Delta}{Z_1+Z_2-2Z_m}
$$

即

$$
\boxed{
Z_{ab}
=\frac{Z_1Z_2-Z_m^2}{Z_1+Z_2-2Z_m}
}
$$

这说明公式法只是把方程法的解提前记成了一个模板。

### 6. 例题对照：副边短路，对应 Figure 4(c)

这类题的特征是：一次侧接输入，二次侧线圈被导线短接。

#### 公式法

副边短路时：

$$
Z_{22}=j\omega L_2
$$

反映阻抗为

$$
Z_{1r}=\frac{(\omega M)^2}{j\omega L_2}
=-j\omega\frac{M^2}{L_2}
$$

所以输入阻抗

$$
\boxed{
Z_{ab}=j\omega L_1-j\omega\frac{M^2}{L_2}
=j\omega\left(L_1-\frac{M^2}{L_2}\right)
}
$$

#### 方程法

副边短路意味着

$$
\dot V_2=0
$$

按图中参考方向，二次侧线圈方程为

$$
0=j\omega M\dot I_1+j\omega L_2\dot I_2
$$

所以

$$
\dot I_2=-\frac{M}{L_2}\dot I_1
$$

一次侧电压为

$$
\dot V_1=j\omega L_1\dot I_1+j\omega M\dot I_2
$$

代入：

$$
\dot V_1
=j\omega L_1\dot I_1
-j\omega\frac{M^2}{L_2}\dot I_1
$$

因此

$$
\boxed{
Z_{ab}
=\frac{\dot V_1}{\dot I_1}
=j\omega\left(L_1-\frac{M^2}{L_2}\right)
}
$$

公式法和方程法完全一致。方程法更稳，公式法更快。

---

## 九、互感消去法

互感消去法的目标是：把含互感的两个电感换成一个不含互感的 T 型等效电路。

### 1. 同名端相连

若两个同名端相连，课件给出的等效为：

$$
L_3=M
$$

$$
L_1'=L_1-M
$$

$$
L_2'=L_2-M
$$

### 2. 同名端不相连

若两个同名端没有相连，等效为：

$$
L_3=-M
$$

$$
L_1'=L_1+M
$$

$$
L_2'=L_2+M
$$

等效电路里可能出现负电感，这只是数学等效，不代表真的放了一个负电感元件。

### 3. 互感消去公式推导

互感消去法的思路是：用一个不含互感的 T 型电感网络，匹配原耦合电感的端口方程。

若两个电流都按流入同名端的方向取参考，原耦合电感方程为

$$
\dot V_1=j\omega L_1\dot I_1+j\omega M\dot I_2
$$

$$
\dot V_2=j\omega M\dot I_1+j\omega L_2\dot I_2
$$

设 T 型等效中，左臂为 \(L_1'\)，右臂为 \(L_2'\)，公共臂为 \(L_3\)。对于 T 型网络，有

$$
\dot V_1=j\omega(L_1'+L_3)\dot I_1+j\omega L_3\dot I_2
$$

$$
\dot V_2=j\omega L_3\dot I_1+j\omega(L_2'+L_3)\dot I_2
$$

为了让 T 型网络与原耦合电感等效，需要对应系数相同：

$$
L_1'+L_3=L_1
$$

$$
L_2'+L_3=L_2
$$

$$
L_3=M
$$

所以

$$
\boxed{
L_3=M,\qquad L_1'=L_1-M,\qquad L_2'=L_2-M
}
$$

如果两个电流相对于同名端方向相反，原方程互感项为负：

$$
\dot V_1=j\omega L_1\dot I_1-j\omega M\dot I_2
$$

$$
\dot V_2=-j\omega M\dot I_1+j\omega L_2\dot I_2
$$

此时等效 T 型网络的公共臂为

$$
L_3=-M
$$

于是

$$
\boxed{
L_3=-M,\qquad L_1'=L_1+M,\qquad L_2'=L_2+M
}
$$

所以互感消去法并不是新定律，而是用普通电感网络去匹配耦合电感的端口方程。

### 4. 例题：用互感消去法求 $i_1,i_2$

课件例题给出

$$
R_1=R_2=1\ \Omega,\quad L_1=2\ \mathrm{H},\quad L_2=1\ \mathrm{H}
$$

$$
k=\frac1{\sqrt2},\quad C=0.5\ \mathrm{F},\quad
v_s(t)=2\sqrt2\cos t\ \mathrm{V}
$$

先求互感：

$$
M=k\sqrt{L_1L_2}=1\ \mathrm{H}
$$

在 $\omega=1\ \mathrm{rad/s}$ 下作等效后，网孔方程为

$$
\dot I_{1eff}-(j-j2)\dot I_{2eff}=2\angle0^\circ
$$

$$
j\dot I_{1eff}+(1-j)\dot I_{2eff}=0
$$

解得

$$
\dot I_{1eff}=\frac{6-j2}{5}=1.26\angle-18.4^\circ\ \mathrm{A}
$$

$$
\dot I_{2eff}=\frac{2-j4}{5}=0.89\angle-63.4^\circ\ \mathrm{A}
$$

因此时域结果为

$$
i_1(t)=1.26\sqrt2\cos(t-18.4^\circ)\ \mathrm{A}
$$

$$
i_2(t)=0.89\sqrt2\cos(t-63.4^\circ)\ \mathrm{A}
$$

这道题很适合复习“有效值相量”和“峰值时域表达式”的转换。

---

## 十、反映阻抗法

反映阻抗法适合线性变压器类电路，尤其是只想求输入阻抗、一次侧电流或二次侧负载功率时。

### 1. 基本方程

设

$$
Z_{11}=R_1+j\omega L_1
$$

$$
Z_{22}=R_2+j\omega L_2+Z_L
$$

对于课件中的符号约定，网孔方程可写为

$$
Z_{11}\dot I_1-j\omega M\dot I_2=\dot V_s
$$

$$
-j\omega M\dot I_1+Z_{22}\dot I_2=0
$$

由第二式可得

$$
\dot I_2=\frac{j\omega M}{Z_{22}}\dot I_1
$$

代回一次侧，输入阻抗为

$$
Z_{in}=\frac{\dot V_s}{\dot I_1}
=Z_{11}+\frac{(\omega M)^2}{Z_{22}}
$$

其中

$$
Z_{1r}=\frac{(\omega M)^2}{Z_{22}}
$$

称为二次侧反映到一次侧的阻抗。

#### 补充：副边短路时的等效输入电感

题目中经常出现一种特例：一次侧线圈接输入端，二次侧线圈被导线短路。此时二次侧没有外接负载和电阻，可令

$$
Z_{22}=j\omega L_2
$$

##### 方法一：用反映阻抗法

代入反映阻抗公式：

$$
Z_{in}
=j\omega L_1+\frac{(\omega M)^2}{j\omega L_2}
$$

因为

$$
\frac{1}{j}=-j
$$

所以

$$
Z_{in}
=j\omega L_1-j\omega\frac{M^2}{L_2}
$$

即

$$
\boxed{
Z_{in}=j\omega\left(L_1-\frac{M^2}{L_2}\right)
}
$$

因此副边短路时，输入端看到的等效电感为

$$
\boxed{
L_{eq}=L_1-\frac{M^2}{L_2}
}
$$

##### 方法二：直接列耦合电感方程

也可以不用反映阻抗法，而是直接列两个耦合线圈的电压方程。这种写法和题目解析里常见的步骤更接近。

二次侧被短接，所以二次线圈两端电压为 0：

$$
\dot V_2=0
$$

若按图中点端和电流参考方向，耦合电感方程可写成

$$
\dot V_2=j\omega M\dot I_1+j\omega L_2\dot I_2
$$

由于 \(\dot V_2=0\)，所以

$$
0=j\omega M\dot I_1+j\omega L_2\dot I_2
$$

两边除以 \(j\omega\)：

$$
0=M\dot I_1+L_2\dot I_2
$$

因此

$$
\dot I_2=-\frac{M}{L_2}\dot I_1
$$

一次侧电压为

$$
\dot V_1=j\omega L_1\dot I_1+j\omega M\dot I_2
$$

代入 \(\dot I_2\)：

$$
\dot V_1
=j\omega L_1\dot I_1
+j\omega M\left(-\frac{M}{L_2}\dot I_1\right)
$$

即

$$
\dot V_1
=j\omega\left(L_1-\frac{M^2}{L_2}\right)\dot I_1
$$

所以

$$
\boxed{
Z_{in}
=\frac{\dot V_1}{\dot I_1}
=j\omega\left(L_1-\frac{M^2}{L_2}\right)
}
$$

这说明“直接列方程法”和“反映阻抗法”得到的是同一个结果。反映阻抗法只是把二次侧短路产生的反作用提前写成了一个等效项。

物理含义：二次侧短路后，变化磁通会在二次线圈中感应出短路电流。根据楞次定律，这个电流产生的磁通会反抗一次侧磁通变化，所以从一次侧看进去，等效电感会变小。

这类题可以记成：

- 副边开路：副边电流为 0，不反映阻抗；
- 副边短路：产生反向作用，输入等效电感减小；
- 常用结果：

$$
L_{eq}=L_1-\frac{M^2}{L_2}
$$

### 2. 反映电阻和反映电抗

若

$$
Z_{22}=R_{22}+jX_{22}
$$

则

$$
Z_{1r}
=\frac{(\omega M)^2}{R_{22}+jX_{22}}
=\frac{(\omega M)^2R_{22}}{R_{22}^2+X_{22}^2}
-j\frac{(\omega M)^2X_{22}}{R_{22}^2+X_{22}^2}
$$

所以

$$
R_{1r}=\frac{(\omega M)^2R_{22}}{R_{22}^2+X_{22}^2}
$$

$$
X_{1r}=-\frac{(\omega M)^2X_{22}}{R_{22}^2+X_{22}^2}
$$

结论：

- 反映电阻为正，表示二次侧负载消耗的功率；
- 反映电抗符号与二次侧总电抗 $X_{22}$ 相反。

并且有

$$
P_{1r}=I_1^2R_{1r}=P_2
$$

也就是说，二次侧消耗的功率可以等效看成一次侧反映电阻消耗的功率。

### 3. 例题：反映阻抗与功率

课件例题中

$$
X_M=\omega M=1\ \Omega,\quad
\dot V_s=10\angle0^\circ\ \mathrm{V_{rms}}
$$

二次侧总阻抗为

$$
Z_{22}=1+j1
$$

所以

$$
Z_{1r}=\frac{\omega^2M^2}{Z_{22}}
=\frac1{1+j}
=\frac12-j\frac12\ \Omega
$$

一次侧总阻抗为

$$
j2+\frac12-j\frac12
$$

于是

$$
\dot I_1=\frac{10}{j2+\frac12-j\frac12}
=2-j6\ \mathrm{A}
$$

电源供给的平均功率为

$$
P_s=\operatorname{Re}[\dot V_s\dot I_1^*]
=\operatorname{Re}[10(2+j6)]
=20\ \mathrm{W}
$$

二次侧电流

$$
\dot I_2=\frac{j\omega M\dot I_1}{Z_{22}}
=\frac{j(2-j6)}{1+j}
=4-j2\ \mathrm{A}
$$

二次侧电阻吸收功率

$$
P_R=|\dot I_2|^2R_{22}=(4^2+2^2)\cdot1=20\ \mathrm{W}
$$

也可以用反映电阻计算：

$$
P_R=|\dot I_1|^2R_{1r}=(2^2+6^2)\cdot\frac12=20\ \mathrm{W}
$$

两边结果相同，说明反映电阻确实代表二次侧的实际耗能。

### 4. 例题：输入阻抗、一次电流与负载功率

课件给出

$$
Z_1=60-j100\ \Omega
$$

$$
Z_2=30+j40\ \Omega
$$

$$
Z_L=80+j60\ \Omega
$$

且线圈自感部分为 $j20\ \Omega$、$j40\ \Omega$，互感电抗为

$$
jX_M=j5\ \Omega
$$

输入阻抗为

$$
Z_{in}=Z_1+j20+Z_{1r}
$$

其中

$$
Z_{1r}=\frac{5^2}{30+j40+j40+80+j60}
$$

代入后

$$
Z_{in}=100\angle-53.1^\circ\ \Omega
$$

若源电压为

$$
\dot V_s=50\angle60^\circ\ \mathrm{V}
$$

则

$$
\dot I_1=\frac{\dot V_s}{Z_{in}}
=0.5\angle113.1^\circ\ \mathrm{A}
$$

二次侧电流为

$$
\dot I_2=\frac{j5\dot I_1}{j40+Z_2+Z_L}
=0.014\angle151.3^\circ\ \mathrm{A}
$$

因为这里的电源电压采用峰值写法，负载平均功率用

$$
P_L=\frac12 I_2^2\operatorname{Re}[Z_L]
$$

所以

$$
P_L=\frac12(0.014)^2(80)=7.84\ \mathrm{mW}
$$

若题目明确给的是有效值相量，则功率公式里没有 $\frac12$。

---

## 十一、线性变压器与理想变压器

### 1. 线性变压器

线性变压器由两个或多个磁耦合线圈组成，绕在近似线性的磁介质上，例如空气、塑料、木材等，因此有时也称为空心变压器。

特点：

- 耦合通常不强，常有 $k\ll1$；
- 常用于射频电路；
- 分析时通常仍保留 $L_1,L_2,M$，用网孔法或反映阻抗法。

### 2. 理想变压器

理想变压器是课件中的极限模型：

- 耦合系数 $k=1$；
- 线圈电阻为零，$R_1=R_2=0$；
- 线圈电抗非常大，$L_1,L_2,M\to\infty$；
- 没有损耗。

实际铁心变压器若设计良好，耦合紧、线圈电抗大、绕线电阻小，就可以近似看作理想变压器。

### 3. 匝比

自感与匝数平方成正比：

$$
L\propto N^2
$$

若理想变压器标为 $1:n$，课件采用

$$
n=\frac{N_2}{N_1}=\sqrt{\frac{L_2}{L_1}}
$$

若 $n>1$，则为升压变压器；若 $n<1$，则为降压变压器。

### 4. 电压、电流关系

理想变压器的电压关系为

$$
\frac{\dot V_2}{\dot V_1}=n
$$

即

$$
\dot V_2=n\dot V_1
$$

在两端电流都按流入同名端的方向取参考时，电流关系为

$$
\dot I_1=-n\dot I_2
$$

若参考方向改成另一种，课件也会写成

$$
\dot I_1=n\dot I_2
$$

本质不变：理想变压器无损，瞬时功率满足

$$
p(t)=v_1i_1+v_2i_2=0
$$

因此电压升高多少倍，电流就按相反方向缩小相应倍数。

---

## 十二、理想变压器的阻抗折算

### 1. 负载折算到一次侧

对 $1:n$ 理想变压器，二次侧负载 $Z_L$ 折算到一次侧为

$$
Z_{in}=\frac{Z_L}{n^2}
$$

这是最常用的变压器阻抗折算公式。

使用这个公式时要分清“等效阻抗”的范围：

- \(Z_{in}=Z_L/n^2\) 只表示从变压器一次侧端口往右看，二次侧负载折算回来后的等效阻抗；
- 它不会自动包含一次侧电源旁边、变压器左边已经存在的串联电阻或源内阻；
- 如果电源与变压器之间还有串联阻抗 \(Z_s\)，那么从电源看进去的总阻抗是

$$
\boxed{
Z_{\text{total}}=Z_s+Z_{in}
}
$$

例如左侧有 \(1\Omega\) 串联电阻，二次侧负载通过 \(1:10\) 变压器折算成

$$
Z_{in}=10+j10\Omega
$$

则电源看到的总阻抗是

$$
Z_{\text{total}}=1+(10+j10)=11+j10\Omega
$$

一句话：折算阻抗只替代变压器右边的负载网络，不会“吞掉”变压器左边本来就串联的元件。

#### 阻抗折算公式推导

理想变压器 \(1:n\) 满足

$$
\dot V_2=n\dot V_1
$$

若两端口电流都按流入同名端方向取参考，则

$$
\dot I_1=-n\dot I_2
$$

二次侧接负载 \(Z_L\) 时，由于 \(\dot I_2\) 是流入二端口的电流，而负载电流方向通常与它相反，因此

$$
\dot V_2=-Z_L\dot I_2
$$

由

$$
\dot V_2=n\dot V_1
$$

可得

$$
n\dot V_1=-Z_L\dot I_2
$$

又因为

$$
\dot I_2=-\frac{\dot I_1}{n}
$$

代入：

$$
n\dot V_1
=Z_L\frac{\dot I_1}{n}
$$

所以

$$
\frac{\dot V_1}{\dot I_1}
=\frac{Z_L}{n^2}
$$

即

$$
\boxed{
Z_{in}=\frac{Z_L}{n^2}
}
$$

这个推导说明：阻抗折算来自电压按 \(n\) 倍变换、电流按 \(1/n\) 倍反向变换，所以阻抗按 \(n^2\) 缩放。

### 2. 源阻抗折算到二次侧

若把一次侧源和源阻抗折算到二次侧，则

$$
\dot V_{OC}=n\dot V_s
$$

$$
Z_0=n^2Z_s
$$

反过来，从二次侧折算回一次侧时，就是除以 $n^2$。

### 3. 例题：匹配变压器

课件例题中：

$$
Z_s=1\ \mathrm{k}\Omega,\qquad
Z_L=6-j8\ \Omega
$$

负载模值为

$$
|Z_L|=10\ \Omega
$$

为了让负载得到最大平均功率，课件采用模匹配：

$$
Z_s=\frac{|Z_L|}{n^2}
$$

所以

$$
n=\sqrt{\frac{|Z_L|}{R_s}}
=\sqrt{\frac{10}{1000}}
=0.1
$$

负载折算到一次侧为

$$
Z_{in}=\frac{Z_L}{n^2}
=100(6-j8)
=600-j800\ \Omega
$$

若

$$
\dot V_s=2\angle0^\circ\ \mathrm{V_{rms}}
$$

则

$$
\dot I_1=\frac{\dot V_s}{R_s+Z_{in}}
=\frac{2\angle0^\circ}{1600-j800}
=1.1\angle26.6^\circ\ \mathrm{mA}
$$

负载最大功率为

$$
P_{L\max}=I_1^2\operatorname{Re}[Z_{in}]
=1.1^2\times10^{-6}\times600
=0.726\ \mathrm{mW}
$$

这里变压器只能改变阻抗大小比例，不能改变负载阻抗角，所以对应的是受限条件下的模匹配思想。

### 4. 例题：理想变压器中求电阻功率

课件例题给出 $120\ \mathrm{V}$ 是电压源的最大幅值，变压器匝比为 $2:1$，要求 $10\Omega$ 电阻吸收功率。

由变压器关系可得

$$
\dot V_2=-\frac12\dot V_1
$$

$$
\dot I_2=-2\dot I_1
$$

代入网孔方程后，课件解得

$$
\dot I_2=-0.727\ \mathrm{A}
$$

因为这是峰值相量，所以平均功率为

$$
P=\frac12 I_2^2R
=\frac12(0.727)^2(10)
=2.65\ \mathrm{W}
$$

这道题的坑点是：题目说 $120\ \mathrm{V}$ 是最大幅值，不是有效值，所以功率要乘 $\frac12$。

---

## 十三、自耦变压器

自耦变压器的一部分绕组被一次侧和二次侧共用。课件中按完全耦合处理：

$$
k=1
$$

### 例题：求输入阻抗

已知

$$
L_1=0.574\ \mathrm{H},\qquad
R_L=40\ \Omega
$$

$$
N_2=\frac N3,\qquad
\omega=314\ \mathrm{rad/s}
$$

匝比为

$$
n=\frac{N_2}{N_1}=\frac13
$$

负载折算为

$$
\frac{R_L}{n^2}=360\ \Omega
$$

自感电抗为

$$
j\omega L_1\approx j180\ \Omega
$$

因此输入阻抗

$$
Z_i=j\omega L_1\parallel\frac{R_L}{n^2}
$$

即

$$
Z_i=\frac{j180\cdot360}{j180+360}
=161\angle63.4^\circ\ \Omega
$$

---

## 十四、完全耦合电感与理想变压器等效

若两个电感满足

$$
k=1
$$

则

$$
M=\sqrt{L_1L_2}
$$

可以把它看成“励磁电感 + 理想变压器”的组合。

课件例题中有

$$
\omega M=2,\qquad X_{L1}=4,\qquad X_{L2}=1
$$

所以

$$
k=\frac{\omega M}{\sqrt{X_{L1}X_{L2}}}
=\frac2{\sqrt4}
=1
$$

匝比为

$$
n=\sqrt{\frac{L_2}{L_1}}
=\sqrt{\frac{X_{L2}}{X_{L1}}}
=\sqrt{\frac14}
=\frac12
$$

若二次侧负载为

$$
R_L=1\ \Omega
$$

折算到一次侧为

$$
\frac{R_L}{n^2}=4\ \Omega
$$

课件由一次侧等效电路得到

$$
\dot I_1=\dot I_s=2\angle0^\circ\ \mathrm{A}
$$

分流关系给出

$$
n\dot I_2
=\dot I_1\frac{j4}{4+j4}
=\sqrt2\angle45^\circ\ \mathrm{A}
$$

所以

$$
\dot I_2=2\sqrt2\angle45^\circ\ \mathrm{A}
$$

一次侧端电压

$$
\dot V_1=n\dot I_2\frac{R_L}{n^2}
=4\sqrt2\angle45^\circ\ \mathrm{V}
$$

二次侧端电压

$$
\dot V_2=n\dot V_1
=2\sqrt2\angle45^\circ\ \mathrm{V}
$$

---

## 十五、含互感网络的最大功率传输

课件最后的例题是把互感网络先化成二次侧看到的戴维宁等效，再做最大功率传输。

已知源为

$$
2\angle0^\circ\ \mathrm{V_{rms}}
$$

先对一次侧网络求等效：

$$
\dot V'_{OC}
=\frac{-j8}{2-j8}\cdot2
=1.94\angle-14^\circ\ \mathrm{V}
$$

$$
Z'_0
=\frac{2(-j8)}{2-j8}
=1.9\angle-14^\circ\ \Omega
$$

再通过互感折算到二次侧，得到

$$
\dot V_{OC}
=j6\cdot\frac{\dot V'_{OC}}{Z'_0+j16}
=0.75\angle-7.1^\circ\ \mathrm{V}
$$

等效阻抗为

$$
Z_0=j4+\frac{6^2}{Z'_0+j16}
=0.277+j1.71\ \Omega
$$

为了使负载获得最大平均功率，应取共轭匹配：

$$
Z_L=Z_0^*=0.277-j1.71\ \Omega
$$

最大功率为

$$
P_{L\max}
=\frac{V_{OC}^2}{4R_0}
=\frac{0.75^2}{4\cdot0.277}
\approx0.5\ \mathrm{W}
$$

这道题的思路不是直接在原图上硬算负载，而是：

1. 先把左侧网络对耦合线圈端口做戴维宁等效；
2. 再用互感关系折算到负载侧；
3. 最后对负载侧戴维宁等效做共轭匹配。

---

## 十六、真实变压器的提醒

真实变压器不是理想元件。课件最后提醒：

- 若损耗不为零，需要考虑绕组电阻 $R$；
- 高频工作时，还会出现分布电容 $C$；
- 实际模型中可能还需要考虑漏感、励磁支路、铁损等。

所以理想变压器适合做主干分析，但在高频、大功率或精密场景里，真实寄生参数会影响结果。

---

## 十七、考前速记

1. 互感 $M$ 本身取正，互感电压正负号看同名端。
2. 电流进入一个线圈同名端，会使另一个线圈同名端感应为正。
3. 两个电流都进入同名端，互感项通常为 $+M$；一个进同名端、一个出同名端，互感项通常为 $-M$。
4. 方程法是所有快捷公式的源头：

$$
\dot V_1=j\omega L_1\dot I_1\pm j\omega M\dot I_2
$$

$$
\dot V_2=\pm j\omega M\dot I_1+j\omega L_2\dot I_2
$$

先写这两式，再加开路、短路、串联、并联或负载条件。

5. 相量域中：

$$
M\frac{di}{dt}\longrightarrow j\omega M\dot I
$$

6. 串联相助：

$$
L_{eq}=L_1+L_2+2M
$$

串联相消：

$$
L_{eq}=L_1+L_2-2M
$$

7. 并联同向：

$$
L_{eq}=\frac{L_1L_2-M^2}{L_1+L_2-2M}
$$

并联反向：

$$
L_{eq}=\frac{L_1L_2-M^2}{L_1+L_2+2M}
$$

8. 副边短路：

$$
Z_{in}=j\omega\left(L_1-\frac{M^2}{L_2}\right)
$$

9. 耦合系数：

$$
k=\frac{M}{\sqrt{L_1L_2}},\qquad 0\le k\le1
$$

10. 耦合电感储能：

$$
w=\frac12L_1i_1^2+\frac12L_2i_2^2\pm Mi_1i_2
$$

11. 反映阻抗：

$$
Z_{1r}=\frac{(\omega M)^2}{Z_{22}}
$$

12. 理想变压器 $1:n$：

$$
\frac{\dot V_2}{\dot V_1}=n,\qquad
Z_{in}=\frac{Z_L}{n^2}
$$

13. 题目若给峰值相量，平均功率要用

$$
P=\frac12I_m^2R
$$

若给有效值相量，则用

$$
P=I_{\mathrm{eff}}^2R
$$
