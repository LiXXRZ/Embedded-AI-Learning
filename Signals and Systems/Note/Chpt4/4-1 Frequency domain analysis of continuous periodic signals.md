# 🌟 学习笔记：连续周期信号的频域分析
**(Frequency Domain Analysis of Continuous Periodic Signals)**

## 零、 引入：为什么需要频域分析？
在时域中，信号表现为随时间变化的波形（如语音信号、带噪信号、电话拨号音DTMF）。
*   **时域分析的局限性**：在时域中很难直观地区分男女声的频率特征，也很难直接将噪声从信号中分离出来，或者识别具体的拨号按键（如按键'1'由697Hz和1209Hz叠加而成）。
*   **频域分析的优势**：将信号分解为不同频率的正弦波或复指数信号的叠加，可以清晰地看到信号的频率构成，便于滤波和特征提取。

## 一、 信号的正交分解基石
> **💡 核心思想**：如同 3D 空间中的向量可以分解为 x, y, z 三个正交坐标轴，任意信号也可以分解为一组**相互正交的函数集**。

1.  **正交的定义**：在区间 $[t_1, t_2]$ 内，两函数满足 $\int_{t_1}^{t_2} f_i(t)f_j^*(t) dt = 0 \ (i \neq j)$。
2.  **最佳逼近与最小均方误差 (MSE)**：
    使用有限项正交函数去逼近原信号时，若想让误差的能量（均方误差）最小，其展开系数 $c_n$ 必须按照正交投影公式计算。
3.  **复指数基函数**：傅里叶发现，复指数信号集 $\{e^{jn\omega_0 t}\}$ 在一个周期 $T_0$ 内是完美正交的。这就是傅里叶级数的数学根基。

---

## 二、 傅里叶级数 (Fourier Series) 的基础理论

### 1. 狄利克雷条件 (Dirichlet Conditions)
任何满足**狄利克雷条件 (Dirichlet conditions)** 的连续周期信号都可以展开为正交函数集的线性叠加。
一个周期信号 $\tilde{x}(t)$ 能够展开为傅里叶级数，必须满足以下三个条件：
1.  **绝对可积**：在一个周期内 $\int_{-T_0/2}^{T_0/2} |\tilde{x}(t)| dt < \infty$。
2.  在一个周期内只有**有限个第一类间断点**。
3.  在一个周期内只有**有限个极大值和极小值**。

### 2. 最小均方误差与正交分解
信号可以表示为一组**正交函数集**的线性组合。如果使用有限项来逼近原信号 $\hat{x}(t) = \sum_{n=1}^N c_n f_n(t)$，为了使**均方误差 (MSE)** 最小，系数 $c_n$ 的取值必须满足：
$$c_n = \frac{\int_{t_1}^{t_2} x(t)f_n^*(t) dt}{\int_{t_1}^{t_2} f_n(t)f_n^*(t) dt}$$

### 3. 傅里叶级数 (Fourier Series) 的两种形式
#### （1）复指数形式的傅里叶级数 
将正交函数集选为虚指数信号集 $\{e^{jn\omega_0 t}\}$，其周期为 $T_0/N$，该函数集在 $[0, T_0]$ 上是**正交的**。

*   **级数展开式**：
   信号被分解为无数个**虚指数信号** $e^{jn\omega_0 t}$ 的叠加：
    $$\tilde{x}(t) = \sum_{n=-\infty}^{\infty} C_n e^{jn\omega_0 t}$$
*   **频谱系数公式**：
    $$C_n = \frac{1}{T_0} \int_{0}^{T_0} \tilde{x}(t) e^{-jn\omega_0 t} dt$$
      *   **$T_0$**：信号的基波周期。
      *   **$\omega_0$**：基波角频率，$\omega_0 = \frac{2\pi}{T_0}$。
      *   **$C_0$**：直流分量 (DC component)。
      *   **$n\omega_0$**：第 $n$ 次谐波的频率。
      *   **$C_n$ 的物理意义**：它是一个复数 $C_n = |C_n|e^{j\phi_n}$。$|C_n|$ 代表第 $n$ 次谐波的**幅度**，$\phi_n$ 代表**相位**。
      *   **注意**：指数形式有 $n$ 为负数的部分（负频率）。**负频率没有实际物理意义，它只是数学上的构造**，用来和正频率共轭抵消，从而合成真实存在的实信号。

> **【补充推导：为什么 $C_n$ 是这个公式？（利用正交性）】**
> 我们已知 $\tilde{x}(t) = \sum_{m=-\infty}^{\infty} C_m e^{jm\omega_0 t}$。
> 等式两边同乘 $e^{-jn\omega_0 t}$，并在一个周期 $[0, T_0]$ 上积分：
> $$\int_{0}^{T_0} \tilde{x}(t) e^{-jn\omega_0 t} dt = \int_{0}^{T_0} \left( \sum_{m=-\infty}^{\infty} C_m e^{jm\omega_0 t} \right) e^{-jn\omega_0 t} dt$$
> 交换积分与求和顺序：
> $$= \sum_{m=-\infty}^{\infty} C_m \int_{0}^{T_0} e^{j(m-n)\omega_0 t} dt$$
> 根据正交性，只有当 $m=n$ 时，积分为 $T_0$；当 $m \neq n$ 时，积分为 $0$。
> 因此等式右侧变为：$C_n \cdot T_0$。
> 移项即可得到：$C_n = \frac{1}{T_0} \int_{0}^{T_0} \tilde{x}(t) e^{-jn\omega_0 t} dt$。

#### （2）傅里叶级数的三角形式与相互转换

*   **转换桥梁 (欧拉公式的体现)**：
    *   $a_n = C_n + C_{-n} = 2 \text{Re}[C_n]$
    *   $b_n = j(C_n - C_{-n}) = -2 \text{Im}[C_n]$
    *   $C_n = \frac{a_n - jb_n}{2}$

*   **两者的转换关系** (利用欧拉公式)：
    *   $C_n = \frac{a_n - jb_n}{2}, \quad C_{-n} = \frac{a_n + jb_n}{2} \implies C_n = C_{-n}^* \text{ (实信号的共轭偶对称性)}$
    *   $A_n = \sqrt{a_n^2 + b_n^2}, \quad \phi_n = \arctan(-\frac{b_n}{a_n})$

对于**实信号**，其复数频谱系数具有**共轭偶对称性**：$C_n = C_{-n}^*$。

##### 1. 三角形式展开
$$\tilde{x}(t) = \frac{a_0}{2} + \sum_{n=1}^{\infty} (a_n \cos n\omega_0 t + b_n \sin n\omega_0 t)$$
*   **直流分量 (DC component)**：$a_0/2 = C_0$
*   系数公式：
    *   $a_0 = \frac{2}{T_0} \int_{t_0}^{t_0+T_0} \tilde{x}(t) dt$
    *   $a_n = \frac{2}{T_0} \int_{t_0}^{t_0+T_0} \tilde{x}(t) \cos(n\omega_0 t) dt$
    *   $b_n = \frac{2}{T_0} \int_{t_0}^{t_0+T_0} \tilde{x}(t) \sin(n\omega_0 t) dt$

##### 2. 余弦/幅相形式展开
$$\tilde{x}(t) = \frac{a_0}{2} + \sum_{n=1}^{\infty} A_n \cos(n\omega_0 t + \phi_n)$$
其中：幅度 $A_n = \sqrt{a_n^2 + b_n^2}$，相位 $\phi_n = \arctan(-\frac{b_n}{a_n})$。

> **【补充推导：复指数形式与三角形式的关系】**
> 由欧拉公式 $e^{jn\omega_0 t} = \cos(n\omega_0 t) + j\sin(n\omega_0 t)$ 代入复指数级数，合并正负频率项（$n$ 与 $-n$）：
> $C_n e^{jn\omega_0 t} + C_{-n} e^{-jn\omega_0 t} = (C_n + C_{-n})\cos(n\omega_0 t) + j(C_n - C_{-n})\sin(n\omega_0 t)$
> 对比三角形式可知：
> $a_n = C_n + C_{-n}$
> $b_n = j(C_n - C_{-n})$
> 反之：**$C_n = \frac{a_n - jb_n}{2}$** 且 **$C_{-n} = \frac{a_n + jb_n}{2}$**

---

## 三、 典型信号的频谱推导

### 1. 周期矩形脉冲信号 (Periodic Rectangular Pulse)
幅度为 $A$，脉宽为 $\tau$，周期为 $T_0$。
> **【推导过程】**
> $$C_n = \frac{1}{T_0} \int_{-\tau/2}^{\tau/2} A e^{-jn\omega_0 t} dt = \frac{A}{-jn\omega_0 T_0}[e^{-jn\omega_0 \tau/2} - e^{jn\omega_0 \tau/2}]$$
> 利用欧拉公式 $\sin \theta = \frac{e^{j\theta} - e^{-j\theta}}{2j}$：
> $$C_n = \frac{2A}{n\omega_0 T_0} \sin(\frac{n\omega_0 \tau}{2}) = \frac{A\tau}{T_0} \frac{\sin(n\omega_0 \tau / 2)}{n\omega_0 \tau / 2}$$
> 定义采样函数 $Sa(x) = \frac{\sin x}{x}$，则最终结果为：
> **$C_n = \frac{A\tau}{T_0} Sa(\frac{n\omega_0 \tau}{2})$**

### 2. 周期三角波信号 (Periodic Triangular Pulse)
> **【推导关键点（分部积分）】**
> 三角波在 $[-1, 0]$ 和 $[0, 1]$ 上的表达式不同（含 $t$ 的一次方）。计算 $C_n$ 时需要计算形如 $\int t e^{-jn\omega_0 t} dt$ 的积分。
> 使用分部积分法计算后得到：
> $C_n = \frac{1}{(n\pi)^2}(\cos n\pi - 1)$
> 当 $n$ 为偶数时，$\cos n\pi = 1$，$C_n = 0$；
> 当 $n$ 为奇数时，$\cos n\pi = -1$，$C_n = \frac{-2}{(n\pi)^2}$。

---

## 四、 连续周期信号的频谱特性

以频率 $\omega$ 为横轴，以 $|C_n|$ 为纵轴画出的图称为**幅度谱**；以 $\phi_n$ 为纵轴画出的图称为**相位谱**。周期信号的频谱具有三大特征：
1.  **离散性 (Dispersion Characteristic)**：
    周期信号的频谱是由间隔为 $\omega_0$ 的离散谱线组成的，谱线只存在于 $\omega = 0, \pm\omega_0, \pm 2\omega_0 \dots$ 处。
2.  **收敛性/衰减性 (Decay Characteristic)**：
    *   随着谐波次数 $n$ 的增加，幅度谱 $|C_n|$ 逐渐衰减并趋向于零。
    *   **核心规律**：时域波形变化越平滑，高次谐波越少，幅度谱衰减越快（如三角波按 $1/n^2$ 衰减）；时域波形变化越剧烈（有跳变），高次谐波越多，衰减越慢（如方波按 $1/n$ 衰减）。
3.  **有效带宽 (Effective Bandwidth)**：
    *   包含主要谐波分量的频率范围称为有效频带。集中了信号绝大部分能量的低频频带范围。对于矩形脉冲，通常取到第一个零点处的频率。
    *   第一零点出现在 $\frac{n\omega_0 \tau}{2} = \pi \Rightarrow \omega = \frac{2\pi}{\tau}$。
    *   **测不准原理体现**：信号的有效频带 $\omega_B$ 与其在时域的持续时间 $\tau$ 成反比（脉冲越窄，频带越宽）。

---

## 五、 信号对称性对频谱的影响

利用对称性可以极大地简化傅里叶级数的计算：

| 对称性类型 | 时域条件 | 频谱包含的成分 (推导依据) |
| :--- | :--- | :--- |
| **偶对称 (Vertically Symmetric)** | $\tilde{x}(t) = \tilde{x}(-t)$ | **仅含直流和余弦分量** ($b_n=0$) |
| **奇对称 (Origin-Symmetric)** | $\tilde{x}(t) = -\tilde{x}(-t)$ | **仅含正弦分量** ($a_n=0, a_0=0$) |
| **半波偶对称 (Half-Wave Symmetry)** (注1) | $\tilde{x}(t) = \tilde{x}(t \pm T_0/2)$ | **仅含偶次谐波** (相当于周期变为了 $T_0/2$) |
| **半波奇对称 (Half-Wave Image)** | $\tilde{x}(t) = -\tilde{x}(t \pm T_0/2)$ | **仅含奇次谐波的正弦和余弦** (无直流分量) |

*(注1：某些波形在平移去除直流分量后，会展现出奇/偶对称性或半波对称性。)*
*(注2：详细推导总结见十。)*

---

## 六、 傅里叶级数的基本性质

设 $\tilde{x}_1(t) \leftrightarrow C_{1n}$， $\tilde{x}_2(t) \leftrightarrow C_{2n}$
1.  **线性性质 (Linearity)**: $a_1\tilde{x}_1(t) + a_2\tilde{x}_2(t) \leftrightarrow a_1C_{1n} + a_2C_{2n}$
2.  **共轭对称性 (Symmetry)**: 若 $x(t)$ 为实信号，则 $|C_n| = |C_{-n}|$， $\phi_n = -\phi_{-n}$
3.  **时移性质 (Time-shifting)**: 时域平移仅改变相位谱，不改变幅度谱
   $$\tilde{x}(t - t_0) \leftrightarrow C_n e^{-jn\omega_0 t_0}$$ 
4.  **频移性质 (Frequency-shifting)**: 频谱搬移
   $$\tilde{x}(t) e^{jM\omega_0 t} \leftrightarrow C_{n-M}$$ 
5.  **卷积性质 (Convolution)**: 时域卷积等于频域相乘再乘周期
   $$\tilde{x}_1(t) * \tilde{x}_2(t) \leftrightarrow T_0 C_{1n} \cdot C_{2n}$$ 
6.  **微分性质 (Differentiation)**: 时域求导，频域乘 $jn\omega_0$
   $$\tilde{x}'(t) \leftrightarrow jn\omega_0 C_n$$ 
---

## 七、 帕塞瓦尔定理与功率谱 (Parseval Power Conservation Theorem)

**物理意义**：周期信号的总平均功率，等于其包含的直流分量、基波和所有次谐波的平均功率之和。（时域计算的功率 = 频域计算的功率）。

*   **公式**：
    $$P = \frac{1}{T_0} \int_{-T_0/2}^{T_0/2} |\tilde{x}(t)|^2 dt = \sum_{n=-\infty}^{\infty} |C_n|^2$$
*   **功率谱 (Power Spectrum)**：$|C_n|^2$ 随频率 $n\omega_0$ 的分布规律称为功率谱。

> **【补充推导：帕塞瓦尔定理是怎么来的？】**
> $$P = \frac{1}{T_0} \int_{T_0} \tilde{x}(t) \tilde{x}^*(t) dt$$
> 将 $\tilde{x}(t) = \sum_{n} C_n e^{jn\omega_0 t}$ 和 $\tilde{x}^*(t) = \sum_{m} C_m^* e^{-jm\omega_0 t}$ 代入：
> $$P = \frac{1}{T_0} \int_{T_0} \left(\sum_n C_n e^{jn\omega_0 t}\right) \left(\sum_m C_m^* e^{-jm\omega_0 t}\right) dt$$
> 交换积分与求和：
> $$P = \sum_n \sum_m C_n C_m^* \left[ \frac{1}{T_0} \int_{T_0} e^{j(n-m)\omega_0 t} dt \right]$$
> 中括号内的积分由于正交性，仅当 $n=m$ 时等于 $1$，否则为 $0$。
> 因此双重求和坍缩为单重求和：
> $$P = \sum_n C_n C_n^* = \sum_{n=-\infty}^{\infty} |C_n|^2$$

---

## 八、 吉布斯现象 (Gibbs Phenomenon)

*   **现象描述**：用有限项傅里叶级数（谐波分量）去逼近带有**间断点**的原始信号时，在间断点附近会出现**过冲 (Overshoot)** 现象。
*   **核心特征**：无论取多少项谐波（$N \rightarrow \infty$），过冲的最大幅度都不会消失，始终约为跳变值的 **9%**。随着 $N$ 的增大，过冲的波纹会越来越窄，向间断点靠拢，但尖峰高度不变。
*   **产生原因**：时域信号间断点的存在破坏了信号的收敛性，导致傅里叶级数在间断点处呈现**非一致收敛 (non-uniform convergence)**。

---

## 九、 🏆 满分例题全图鉴（必考题型全覆盖）

### 📝 例题 1：周期矩形脉冲的频谱计算（最重要基础信号）
**【条件】** 幅度为 $A$，脉宽为 $\tau$，周期为 $T_0$ 的偶对称矩形脉冲。
**【推导结论】**
$$C_n = \frac{1}{T_0} \int_{-\tau/2}^{\tau/2} A \cdot e^{-jn\omega_0 t} dt = \frac{A}{-jn\omega_0 T_0}[e^{-jn\omega_0 \tau/2} - e^{jn\omega_0 \tau/2}]$$

利用欧拉公式 $\sin x = \frac{e^{jx} - e^{-jx}}{2j}$，且定义采样函数 $Sa(x) = \frac{\sin x}{x}$：
$$C_n = \frac{2A}{n\omega_0 T_0} \sin\left(\frac{n\omega_0 \tau}{2}\right) = \mathbf{\frac{A\tau}{T_0} Sa\left(\frac{n\omega_0\tau}{2}\right)}$$
*   *记住这个结论，考试经常直接用矩形脉冲的频谱公式！*
*   *引申：第一过零点带宽 $\omega_B = \frac{2\pi}{\tau}$。*

### 📝 例题 2：巧用分部积分求三角波频谱
**【题目】** 图示三角波，周期 $T_0=2$，幅度为1 (在 $t=0$ 处)，在 $[-1, 0]$ 是上升沿 $1+t$，在 $[0, 1]$ 是下降沿 $1-t$。求 $C_n$。
**【超详细解答】**
1. **参数提取**：$T_0 = 2 \implies \omega_0 = \frac{2\pi}{2} = \pi$。
2. **积分列式**：
   $$ C_n = \frac{1}{2} \int_{-1}^{1} \tilde{x}(t) e^{-jn\pi t} dt = \frac{1}{2} \left[ \int_{-1}^{0} (1+t)e^{-jn\pi t} dt + \int_{0}^{1} (1-t)e^{-jn\pi t} dt \right] $$

   *(由于三角波是偶对称，利用欧拉公式，虚部正弦项积分必然为0，我们可以直接化简为)*

   $$ C_n = \int_{0}^{1} (1-t)\cos(n\pi t) dt $$
3. **分部积分法 (极其关键)**：$\int u dv = uv - \int v du$
   令 $u = (1-t) \implies du = -dt$
   令 $dv = \cos(n\pi t) dt \implies v = \frac{1}{n\pi}\sin(n\pi t)$
   $$ C_n = \left. (1-t)\frac{1}{n\pi}\sin(n\pi t) \right|_0^1 - \int_{0}^{1} \frac{1}{n\pi}\sin(n\pi t) (-dt) $$
   *   第一项：代入 $1$ 时 $(1-1)=0$；代入 $0$ 时 $\sin(0)=0$。所以第一项全为0。
   *   第二项：$+ \frac{1}{n\pi} \int_{0}^{1} \sin(n\pi t) dt = \frac{1}{n\pi} \left[ -\frac{1}{n\pi}\cos(n\pi t) \right]_0^1$
   $$ C_n = -\frac{1}{(n\pi)^2} (\cos(n\pi) - \cos(0)) = \frac{1 - \cos(n\pi)}{(n\pi)^2} $$
4. **结果讨论**：
   已知 $\cos(n\pi) = (-1)^n$。
   *   当 $n=0$ 时：用洛必达法则求极限，或直接积分原式得 $C_0 = 1/2$。
   *   当 $n$ 为偶数时：$\cos(n\pi) = 1 \implies C_n = 0$。
   *   当 $n$ 为奇数时：$\cos(n\pi) = -1 \implies C_n = \frac{2}{(n\pi)^2}$。
5. **结论**：当 $n$ 为偶数时 $C_n = 0$；当 $n$ 为奇数时 $C_n = \frac{2}{(n\pi)^2}$。完全符合“奇半波对称且偶对称”的特性（无正弦，无偶次谐波）。

### 📝 例题 3：巧用分部积分求三角波频谱
#### 周期矩形脉冲信号的频谱分量推导
1. **信号定义**
周期矩形脉冲信号 $\widetilde{x}(t)$ 的参数：
- 周期：$T_0$，基波角频率 $\omega_0 = \frac{2\pi}{T_0}$
- 脉冲幅度：$A$
- 脉冲宽度：$\tau$（题目中取 $\tau = \frac{T_0}{2}$）
- 信号是**偶函数**（关于 $t=0$ 对称），因此傅里叶级数仅含直流分量和余弦分量，无正弦分量。

一个周期内（$t \in [-T_0/2, T_0/2]$）的信号表达式：
$$
x(t) =
\begin{cases}
A, & |t| < \tau/2 = T_0/4 \\
0, & T_0/4 < |t| < T_0/2
\end{cases}
$$

2. **周期信号的傅里叶级数（三角形式）**
对于实偶函数，三角形式傅里叶级数为：
$$
\widetilde{x}(t) = a_0/2 + \sum_{n=1}^{\infty} a_n \cos(n\omega_0 t)
$$
其中系数计算公式为：
$$
a_0 = \frac{2}{T_0} \int_{-T_0/2}^{T_0/2} x(t) dt
$$
$$
a_n = \frac{2}{T_0} \int_{-T_0/2}^{T_0/2} x(t) \cos(n\omega_0 t) dt \quad (n=1,2,3,\dots)
$$

3. **计算直流分量系数 $a_0$**
代入信号表达式：
$$
a_0 = \frac{2}{T_0} \int_{-T_0/4}^{T_0/4} A dt = \frac{2A}{T_0} \cdot \left. t \right|_{-T_0/4}^{T_0/4} = \frac{2A}{T_0} \cdot \frac{T_0}{2} = A
$$
因此直流分量为：
$$
\frac{a_0}{2} = \frac{A}{2}
$$
与展开式的第一项完全一致。

4. **计算余弦分量系数 $a_n$**
同样代入信号表达式（利用偶函数积分性质，简化为2倍正区间积分）：
$$
a_n = \frac{2}{T_0} \int_{-T_0/4}^{T_0/4} A \cos(n\omega_0 t) dt = \frac{4A}{T_0} \int_{0}^{T_0/4} \cos(n\omega_0 t) dt
$$
计算积分：
$$
\int_{0}^{T_0/4} \cos(n\omega_0 t) dt = \left. \frac{\sin(n\omega_0 t)}{n\omega_0} \right|_{0}^{T_0/4} = \frac{\sin\left(n\omega_0 \cdot \frac{T_0}{4}\right)}{n\omega_0}
$$
代入 $\omega_0 = \frac{2\pi}{T_0}$，得 $\omega_0 T_0 = 2\pi$，因此：
$$
n\omega_0 \cdot \frac{T_0}{4} = \frac{n \cdot 2\pi}{4} = \frac{n\pi}{2}
$$
同时 $\frac{1}{n\omega_0} = \frac{T_0}{2\pi n}$，代入 $a_n$：
$$
a_n = \frac{4A}{T_0} \cdot \frac{\sin\left(\frac{n\pi}{2}\right)}{\frac{2\pi n}{T_0}} = \frac{4A}{T_0} \cdot \frac{T_0 \cdot \sin\left(\frac{n\pi}{2}\right)}{2\pi n} = \frac{2A}{\pi n} \sin\left(\frac{n\pi}{2}\right)
$$

5. **分析 $a_n$ 的取值规律**
我们来计算不同 $n$ 对应的 $\sin\left(\frac{n\pi}{2}\right)$：
- $n=1$：$\sin(\pi/2) = 1$ → $a_1 = \frac{2A}{\pi \cdot 1} \cdot 1 = \frac{2A}{\pi}$
- $n=2$：$\sin(\pi) = 0$ → $a_2 = 0$
- $n=3$：$\sin(3\pi/2) = -1$ → $a_3 = \frac{2A}{\pi \cdot 3} \cdot (-1) = -\frac{2A}{3\pi}$
- $n=4$：$\sin(2\pi) = 0$ → $a_4 = 0$
- $n=5$：$\sin(5\pi/2) = 1$ → $a_5 = \frac{2A}{\pi \cdot 5} \cdot 1 = \frac{2A}{5\pi}$
- $n=6$：$\sin(3\pi) = 0$ → $a_6 = 0$
- ...

规律总结：
- **偶数次谐波（$n=2,4,6,\dots$）**：系数 $a_n=0$，无偶数次谐波分量
- **奇数次谐波（$n=1,3,5,\dots$）**：系数 $a_n = \frac{2A}{\pi n} \cdot (-1)^{\frac{n-1}{2}}$，即符号交替为 $+,-,+,-\dots$

6. **写出最终展开式**
将系数代入三角傅里叶级数：
$$
\widetilde{x}(t) = \frac{A}{2} + \sum_{k=0}^{\infty} a_{2k+1} \cos\left((2k+1)\omega_0 t\right)
$$
代入 $a_n$ 的值：
$$
\widetilde{x}(t) = \frac{A}{2} + \frac{2A}{\pi} \left( \cos\omega_0 t - \frac{1}{3}\cos3\omega_0 t + \frac{1}{5}\cos5\omega_0 t - \dots \right)
$$
与题目给出的展开式完全一致。

7. **结论验证（对应图中文字）**
   (1) **信号是偶对称**：$x(t)=x(-t)$，因此傅里叶级数仅含直流和余弦分量，无正弦分量。
   (2) **半波镜像（奇谐）信号**：去掉直流分量后，满足 $x(t+T_0/2) = -x(t)$（半波镜像特性），因此**仅含奇次谐波**，偶次谐波分量为0。
   (3) 最终频谱分量：**直流分量 + 奇次谐波的余弦分量**，与图中结论完全吻合。

8. **补充：指数形式傅里叶级数（拓展）**
若用指数形式展开，系数为：
$$
c_n = \frac{1}{T_0} \int_{-T_0/2}^{T_0/2} x(t) e^{-jn\omega_0 t} dt = \frac{A\tau}{T_0} \cdot \text{Sa}\left(\frac{n\omega_0 \tau}{2}\right)
$$
代入 $\tau=T_0/2$，$\omega_0=2\pi/T_0$：
$$
c_n = \frac{A}{2} \cdot \text{Sa}\left(\frac{n\pi}{2}\right)
$$
其中 $\text{Sa}(x)=\frac{\sin x}{x}$ 是抽样函数，同样满足：
- $n=0$：$c_0 = A/2$（直流分量）
- $n$ 为偶数：$\text{Sa}(n\pi/2)=0$，无分量
- $n$ 为奇数：$\text{Sa}(n\pi/2) = \frac{2(-1)^{\frac{n-1}{2}}}{n\pi}$，对应奇次谐波分量，与三角形式完全等价。

9. **关键知识点总结**

| 特性 | 结论 |
|------|------|
| 信号对称性 | 偶对称 → 仅含直流+余弦分量 |
| 半波镜像特性 | 仅含奇次谐波，偶次谐波为0 |
| 傅里叶系数规律 | 奇次谐波幅度按 $1/n$ 衰减，符号交替 |
| 展开式 | $\widetilde{x}(t) = \frac{A}{2} + \frac{2A}{\pi}\left(\cos\omega_0 t - \frac{1}{3}\cos3\omega_0 t + \frac{1}{5}\cos5\omega_0 t - \dots\right)$ |

#### 周期三角脉冲信号的频谱分量推导
1. **信号定义与参数**
从图中可确定信号参数：
- 周期：$T_0 = 2$，因此基波角频率 $\omega_0 = \frac{2\pi}{T_0} = \pi$（与图中一致）
- 幅度：峰值为 $1$，信号为**偶函数**（关于 $t=0$ 对称），因此傅里叶级数仅含直流分量和余弦分量，无正弦分量
- 一个周期内（$t \in [-1, 1]$）的信号表达式：
$$
x_\Delta(t) =
\begin{cases}
1 - |t|, & |t| < 1 \\
0, & \text{其他（周期内）}
\end{cases}
$$
（注：周期延拓后得到 $\widetilde{x}_\Delta(t)$）

2. **周期信号的三角形式傅里叶级数**
对于实偶函数，三角形式傅里叶级数为：
$$
\widetilde{x}_\Delta(t) = \frac{a_0}{2} + \sum_{n=1}^{\infty} a_n \cos(n\omega_0 t)
$$
其中系数计算公式为：
$$
a_0 = \frac{2}{T_0} \int_{-T_0/2}^{T_0/2} x(t) dt
$$
$$
a_n = \frac{2}{T_0} \int_{-T_0/2}^{T_0/2} x(t) \cos(n\omega_0 t) dt \quad (n=1,2,3,\dots)
$$

3. **计算直流分量系数 $a_0$**
代入 $T_0=2$ 和信号表达式：
$$
a_0 = \frac{2}{2} \int_{-1}^{1} (1-|t|) dt = \int_{-1}^{1} (1-|t|) dt
$$
利用偶函数积分性质，简化为2倍正区间积分：
$$
a_0 = 2\int_{0}^{1} (1-t) dt = 2 \cdot \left. \left(t - \frac{t^2}{2}\right) \right|_{0}^{1} = 2 \cdot \left(1 - \frac{1}{2}\right) = 1
$$
因此直流分量为：
$$
\frac{a_0}{2} = \frac{1}{2}
$$
与展开式的第一项完全一致。

4. **计算余弦分量系数 $a_n$**
同样利用偶函数积分性质，简化计算：
$$
a_n = \frac{2}{2} \int_{-1}^{1} (1-|t|) \cos(n\omega_0 t) dt = 2\int_{0}^{1} (1-t) \cos(n\pi t) dt
$$
对积分进行分部积分：
令 $u = 1-t$，$dv = \cos(n\pi t) dt$，则 $du = -dt$，$v = \frac{\sin(n\pi t)}{n\pi}$
$$
\int_{0}^{1} (1-t)\cos(n\pi t) dt = \left. (1-t)\frac{\sin(n\pi t)}{n\pi} \right|_{0}^{1} + \frac{1}{n\pi} \int_{0}^{1} \sin(n\pi t) dt
$$
第一项在 $t=0$ 和 $t=1$ 处均为0，因此：
$$
\int_{0}^{1} (1-t)\cos(n\pi t) dt = \frac{1}{n\pi} \int_{0}^{1} \sin(n\pi t) dt = \frac{1}{n\pi} \cdot \left. \left(-\frac{\cos(n\pi t)}{n\pi}\right) \right|_{0}^{1}
$$
代入上下限：
$$
= \frac{1}{n\pi} \cdot \left( -\frac{\cos(n\pi)}{n\pi} + \frac{\cos(0)}{n\pi} \right) = \frac{1 - \cos(n\pi)}{n^2\pi^2}
$$
因此：
$$
a_n = 2 \cdot \frac{1 - \cos(n\pi)}{n^2\pi^2}
$$

5. **分析 $a_n$ 的取值规律**
利用 $\cos(n\pi) = (-1)^n$，分情况讨论：
- **$n$ 为偶数**：$\cos(n\pi) = 1$ → $a_n = 2 \cdot \frac{1-1}{n^2\pi^2} = 0$（偶次谐波分量为0）
- **$n$ 为奇数**：$\cos(n\pi) = -1$ → $a_n = 2 \cdot \frac{1 - (-1)}{n^2\pi^2} = \frac{4}{n^2\pi^2}$？
  注意：图中展开式为负号，我们重新核对符号：
  分部积分第二步：
  $$
  \int_{0}^{1} \sin(n\pi t) dt = \left. -\frac{\cos(n\pi t)}{n\pi} \right|_{0}^{1} = -\frac{\cos(n\pi)}{n\pi} + \frac{\cos(0)}{n\pi} = \frac{1 - (-1)^n}{n\pi}
  $$
  因此：
  $$
  a_n = 2 \cdot \frac{1 - (-1)^n}{n^2\pi^2}
  $$
  当 $n$ 为奇数时，$1 - (-1)^n = 2$，故 $a_n = \frac{4}{n^2\pi^2}$，但图中为负号，原因是**信号的相位/定义差异**：
  图中信号在 $t=0$ 处为0，$t=\pm1$ 处为1，实际是**反相的三角波**，即 $x(t) = |t|$（$|t|<1$），重新计算：
  若 $x(t) = |t|$（$|t|<1$），则：
  $$
  a_0 = \int_{-1}^{1} |t| dt = 1 \implies \frac{a_0}{2} = \frac{1}{2}
  $$
  $$
  a_n = 2\int_{0}^{1} t \cos(n\pi t) dt = 2 \cdot \left[ \left. t\frac{\sin(n\pi t)}{n\pi} \right|_{0}^{1} - \frac{1}{n\pi}\int_{0}^{1} \sin(n\pi t) dt \right]
  $$
  $$
  = 2 \cdot \left[ 0 - \frac{1}{n\pi} \cdot \left(-\frac{\cos(n\pi t)}{n\pi}\right)\bigg|_{0}^{1} \right] = 2 \cdot \left[ -\frac{1 - (-1)^n}{n^2\pi^2} \right] = -\frac{2(1 - (-1)^n)}{n^2\pi^2}
  $$
  此时：
  - $n$ 为偶数：$a_n=0$
  - $n$ 为奇数：$a_n = -\frac{4}{n^2\pi^2}$，与图中展开式完全一致！

6. **写出最终展开式**
将系数代入三角傅里叶级数：
$$
\widetilde{x}_\Delta(t) = \frac{1}{2} + \sum_{k=0}^{\infty} a_{2k+1} \cos\left((2k+1)\omega_0 t\right)
$$
代入 $a_n$ 的值（$n=1,3,5,\dots$）：
$$
\widetilde{x}_\Delta(t) = \frac{1}{2} - \frac{4}{\pi^2} \cos\omega_0 t - \frac{4}{9\pi^2} \cos3\omega_0 t - \frac{4}{25\pi^2} \cos5\omega_0 t - \dots
$$
与题目给出的展开式完全一致。

7. **结论与特性分析**
   (1) **偶对称特性**：信号满足 $x(t)=x(-t)$，因此傅里叶级数仅含直流分量和余弦分量，无正弦分量。
   (2) **半波镜像（奇谐）特性**：去掉直流分量后，满足 $x(t+T_0/2) = -x(t)$，因此**仅含奇次谐波**，偶次谐波分量为0。
   (3) **幅度衰减特性**：三角波的谐波幅度按 $1/n^2$ 衰减，远快于矩形波的 $1/n$ 衰减，因此三角波的高频分量更少，波形更平滑。
   (4) **频谱分量**：最终频谱为**直流分量 + 奇次谐波的余弦分量**，与图中结论完全吻合。

8. **指数形式傅里叶级数（拓展）**
指数形式傅里叶系数为：
$$
c_n = \frac{1}{T_0} \int_{-T_0/2}^{T_0/2} x(t) e^{-jn\omega_0 t} dt
$$
代入 $x(t)=|t|$（$|t|<1$），$T_0=2$，$\omega_0=\pi$：
$$
c_n = \frac{1}{2} \int_{-1}^{1} |t| e^{-jn\pi t} dt = \int_{0}^{1} t \cos(n\pi t) dt = -\frac{1 - (-1)^n}{n^2\pi^2}
$$
- $n=0$：$c_0 = \frac{1}{2}$（直流分量）
- $n$ 为偶数：$c_n=0$
- $n$ 为奇数：$c_n = -\frac{2}{n^2\pi^2}$，与三角形式完全等价。

9. **关键知识点总结**

| 特性 | 结论 |
|------|------|
| 信号对称性 | 偶对称 → 仅含直流+余弦分量 |
| 半波镜像特性 | 仅含奇次谐波，偶次谐波为0 |
| 傅里叶系数规律 | 奇次谐波幅度按 $1/n^2$ 衰减，符号为负 |
| 展开式 | $\widetilde{x}_\Delta(t) = \frac{1}{2} - \frac{4}{\pi^2}\cos\omega_0 t - \frac{4}{9\pi^2}\cos3\omega_0 t - \frac{4}{25\pi^2}\cos5\omega_0 t - \dots$ |
| 基波角频率 | $\omega_0 = \pi$（$T_0=2$） |

### 📝 例题 4：由频域谱图反推时域表达式
**【条件】** 给出频谱图杆状图。$C_0=4, |C_{\pm 1}|=3, |C_{\pm 2}|=2$。
*   **情况 A (全为实数，相位为0)**：
    利用 $e^{j\theta} + e^{-j\theta} = 2\cos\theta$ 配对组合：
    $\tilde{x}_1(t) = 4 + 3(e^{j\omega_0 t} + e^{-j\omega_0 t}) + \dots = \mathbf{4 + 6\cos(\omega_0 t) + 4\cos(2\omega_0 t)}$
*   **情况 B (带有相位谱 $\phi_{\pm 1} = \pm \pi/2$)**：
    此时 $C_{\pm 1} = 3e^{\pm j\pi/2}$。
    代入后组合：$3(e^{j(\omega_0 t + \pi/2)} + e^{-j(\omega_0 t + \pi/2)}) = 6\cos(\omega_0 t + \pi/2) = \mathbf{-6\sin(\omega_0 t)}$。

### 📝 例题 5：巧妙利用“线性特性”组合信号
**【条件】** 偏置在上方且不跨越负半轴的方波（值在 1 和 2 之间跳变，占空比 50%）。
**【解法分析】**
不要去傻傻地积分！利用**线性性质 (Linearity)**。
1.  原信号 $\tilde{x}(t)$ 可以看作是：一个恒定直流 $y_1(t) = 1.5$ 加上（或减去）一个标准的奇半波对称方波 $\tilde{x}_2(t)$。
2.  通过观察，原图等于**常数直流 1.5** 减去一个**在 $\pm 0.5$ 之间跳变的奇半波对称标准矩形方波** 。
3.  直接利用标准方波的 $Sa$ 函数结论减去常数即可。

### 📝 例题 6：帕塞瓦尔功率计算
**【题目】** 若 $\tilde{x}(t) = 2e^{-j2\omega_0 t} + 3e^{-j\omega_0 t} + 4 + 3e^{j\omega_0 t} + 2e^{j2\omega_0 t}$，求总功率 $P$。
**【解法】**
从式子中直接提取出 $C_n$：
$C_0 = 4, \quad C_1 = 3, \quad C_{-1} = 3, \quad C_2 = 2, \quad C_{-2} = 2$
利用帕塞瓦尔定理：
$$P = \sum |C_n|^2 = 2^2 + 3^2 + 4^2 + 3^2 + 2^2 = 4 + 9 + 16 + 9 + 4 = \mathbf{42}$$

### 📝 例题 7：帕塞瓦尔定理与有效带宽能量计算（压轴计算题）

**帕塞瓦尔定理**：时域总能量 = 频域各次谐波能量之和。
$$ P = \frac{1}{T_0} \int_{T_0} |\tilde{x}(t)|^2 dt = \sum_{n=-\infty}^{\infty} |C_n|^2 = C_0^2 + 2\sum_{n=1}^{\infty} |C_n|^2 $$

**【题目】** 幅度 $A=1$, 周期 $T_0 = 1/4$, 脉宽 $\tau = 1/20$ 的矩形脉冲。求包含在**有效带宽**内的谐波功率占总功率的百分比。
**【超详细步骤】**
1. **求时域总功率 (P)**：
   $$ P = \frac{1}{T_0} \int_{-\tau/2}^{\tau/2} A^2 dt = 4 \times \int_{-1/40}^{1/40} 1^2 dt = 4 \times \left( \frac{1}{40} - (-\frac{1}{40}) \right) = \mathbf{0.2} $$

2. **定位有效带宽 (第一过零点)**：
   第一过零点出现在 $Sa(\frac{n\omega_0\tau}{2}) = 0$ 的地方。
   即 $\frac{n\omega_0\tau}{2} = \pi \implies n\omega_0 = \frac{2\pi}{\tau} = \frac{2\pi}{1/20} = 40\pi$。
   已知基频 $\omega_0 = \frac{2\pi}{1/4} = 8\pi$。
   所以截止谐波次数 $n = \frac{40\pi}{8\pi} = \mathbf{5}$。
   因为第 5 次谐波刚好为 0，所以**有效带宽内只包含 $n = 0, 1, 2, 3, 4$ 这 5 个分量**。

3. **计算有效带宽内的功率 ($P_1$)**：
   $$ C_n = \frac{A\tau}{T_0} Sa(\frac{n\pi}{5}) = 0.2 Sa(\frac{n\pi}{5}) $$

   $$ P_1 = C_0^2 + 2(C_1^2 + C_2^2 + C_3^2 + C_4^2) $$

   分别代入 $n=0,1,2,3,4$，利用计算器算出：
   $P_1 = (0.2)^2 + 2[ (0.2 Sa(\frac{\pi}{5}))^2 + \dots + (0.2 Sa(\frac{4\pi}{5}))^2 ] \approx \mathbf{0.1806}$

4. **求比例**：
   $$ \text{Ratio} = \frac{0.1806}{0.2} = \mathbf{90.3\%} $$
   *(结论：虽然有效带宽只占了无穷频域的很小一部分，但它汇聚了信号 90% 以上的能量！这就是为什么通信系统可以只传输有效带宽而忽略高频部分。)*


## 十、半波对称与半波镜像信号的傅里叶级数特性详解

### (1) 半波对称信号 (Half-Wave Symmetry Signal)
#### 1. 定义
半波对称信号满足：
$$\widetilde{x}(t) = \widetilde{x}\left(t \pm \frac{T_0}{2}\right)$$
其中 $T_0$ 是信号的**基波周期**。
- 含义：信号**平移半个周期后，和原信号完全重合**。
- 直观理解：信号的“前半周期”和“后半周期”完全一样，相当于周期被“压缩”了一半，实际有效周期是 $T_0/2$。

#### 2. 图像特征
图中的锯齿波就是典型例子：
- 从 $0$ 到 $T_0/2$ 的波形，和 $T_0/2$ 到 $T_0$ 的波形**完全相同**；
- 向左平移 $T_0/2$ 或向右平移 $T_0/2$，波形都和原信号重合。

#### 3. 傅里叶级数特性
**结论：半波对称周期信号的傅里叶级数，只包含偶次谐波（$n=2,4,6\cdots$），没有奇次谐波分量，也没有直流分量（$n=0$）。**

##### 原理推导（核心逻辑）
周期信号的傅里叶级数展开为：
$$\widetilde{x}(t) = \sum_{n=-\infty}^{\infty} F_n e^{jn\omega_0 t}, \quad \omega_0 = \frac{2\pi}{T_0}$$
其中傅里叶系数 $F_n = \frac{1}{T_0}\int_{T_0} \widetilde{x}(t) e^{-jn\omega_0 t} dt$。

根据半波对称条件 $\widetilde{x}(t) = \widetilde{x}(t+T_0/2)$，代入系数公式：
$$
\begin{align*}
F_n &= \frac{1}{T_0}\left[ \int_{0}^{T_0/2} \widetilde{x}(t) e^{-jn\omega_0 t} dt + \int_{T_0/2}^{T_0} \widetilde{x}(t) e^{-jn\omega_0 t} dt \right] \\
&= \frac{1}{T_0}\left[ \int_{0}^{T_0/2} \widetilde{x}(t) e^{-jn\omega_0 t} dt + \int_{0}^{T_0/2} \widetilde{x}(\tau+T_0/2) e^{-jn\omega_0 (\tau+T_0/2)} d\tau \right] \\
&= \frac{1}{T_0}\int_{0}^{T_0/2} \widetilde{x}(t) e^{-jn\omega_0 t} \left[ 1 + e^{-jn\pi} \right] dt
\end{align*}
$$

其中 $e^{-jn\pi} = (-1)^n$，因此：
- 当 $n$ 为**奇数**时：$1 + (-1)^n = 0$ → $F_n = 0$（奇次谐波系数为0）
- 当 $n$ 为**偶数**时：$1 + (-1)^n = 2$ → $F_n = \frac{2}{T_0}\int_{0}^{T_0/2} \widetilde{x}(t) e^{-jn\omega_0 t} dt$（偶次谐波保留）
- 直流分量 $n=0$：$F_0 = \frac{1}{T_0}\int_{T_0} \widetilde{x}(t)dt = \frac{2}{T_0}\int_{0}^{T_0/2} \widetilde{x}(t)dt$，但注意：半波对称信号的实际周期是 $T_0/2$，其基波频率为 $2\omega_0$，因此原展开式中 $n=0$ 对应新周期的直流，原 $n$ 为偶数对应新周期的整数次谐波，本质上是“原周期的偶次谐波 = 新周期的全谐波”。

### (2) 半波镜像信号 (Half-Wave Image Signal)
#### 1. 定义
半波镜像信号（也叫**半波反对称**、**奇谐对称**）满足：
$$\widetilde{x}(t) = -\widetilde{x}\left(t \pm \frac{T_0}{2}\right)$$
- 含义：信号**平移半个周期后，和原信号大小相等、符号相反（镜像翻转）**。
- 直观理解：信号的“前半周期”和“后半周期”互为相反数，上下对称。

#### 2. 图像特征
图中的三角波就是典型例子：
- 从 $0$ 到 $T_0/2$ 的波形，和 $T_0/2$ 到 $T_0$ 的波形**上下翻转、完全对称**；
- 向右平移 $T_0/2$ 后，波形和原信号关于时间轴对称（符号相反）。

#### 3. 傅里叶级数特性
**结论：半波镜像周期信号的傅里叶级数，只包含奇次谐波（$n=1,3,5\cdots$），没有直流分量（$n=0$），也没有偶次谐波分量。**

##### 原理推导（核心逻辑）
同样用傅里叶系数公式，代入半波镜像条件 $\widetilde{x}(t) = -\widetilde{x}(t+T_0/2)$：
$$
\begin{align*}
F_n &= \frac{1}{T_0}\left[ \int_{0}^{T_0/2} \widetilde{x}(t) e^{-jn\omega_0 t} dt + \int_{T_0/2}^{T_0} \widetilde{x}(t) e^{-jn\omega_0 t} dt \right] \\
&= \frac{1}{T_0}\left[ \int_{0}^{T_0/2} \widetilde{x}(t) e^{-jn\omega_0 t} dt - \int_{0}^{T_0/2} \widetilde{x}(\tau+T_0/2) e^{-jn\omega_0 (\tau+T_0/2)} d\tau \right] \\
&= \frac{1}{T_0}\int_{0}^{T_0/2} \widetilde{x}(t) e^{-jn\omega_0 t} \left[ 1 - e^{-jn\pi} \right] dt
\end{align*}
$$
其中 $e^{-jn\pi} = (-1)^n$，因此：
- 当 $n$ 为**偶数**时：$1 - (-1)^n = 0$ → $F_n = 0$（偶次谐波系数为0）
- 当 $n$ 为**奇数**时：$1 - (-1)^n = 2$ → $F_n = \frac{2}{T_0}\int_{0}^{T_0/2} \widetilde{x}(t) e^{-jn\omega_0 t} dt$（奇次谐波保留）
- 直流分量 $n=0$：$F_0 = \frac{1}{T_0}\int_{T_0} \widetilde{x}(t)dt = \frac{1}{T_0}\left[ \int_{0}^{T_0/2} \widetilde{x}(t)dt + \int_{T_0/2}^{T_0} \widetilde{x}(t)dt \right] = \frac{1}{T_0}\left[ \int_{0}^{T_0/2} \widetilde{x}(t)dt - \int_{0}^{T_0/2} \widetilde{x}(t)dt \right] = 0$（直流分量为0）

### (3) 两种对称性的核心对比表
| 特性                | 半波对称信号 (Half-Wave Symmetry) | 半波镜像信号 (Half-Wave Image / 奇谐对称) |
|---------------------|-----------------------------------|-------------------------------------------|
| 数学定义            | $\widetilde{x}(t) = \widetilde{x}(t\pm T_0/2)$ | $\widetilde{x}(t) = -\widetilde{x}(t\pm T_0/2)$ |
| 平移半个周期后      | 与原信号完全重合                  | 与原信号上下翻转（符号相反）              |
| 直流分量 ($n=0$)    | 无（实际周期为$T_0/2$）            | 无（前后半周期抵消）                      |
| 偶次谐波 ($n=2,4,6\cdots$) | 保留                              | 无（系数为0）                             |
| 奇次谐波 ($n=1,3,5\cdots$) | 无（系数为0）                     | 保留                                      |
| 典型波形            | 周期重复的锯齿波（前后半周期相同） | 上下对称的三角波（前后半周期相反）        |

### (4) 补充：与其他对称性的关联（拓展）
1. **半波镜像信号 ≠ 奇函数**
   - 奇函数满足 $\widetilde{x}(-t) = -\widetilde{x}(t)$，是关于原点对称；
   - 半波镜像信号是关于 $t=T_0/4$ 对称（平移半个周期后反号），二者是不同的对称性，可同时满足（如方波）。

2. **工程意义**
   - 半波镜像信号：常见于交流电力系统中的**奇次谐波**（如3次、5次谐波），是电网谐波分析的核心；
   - 半波对称信号：常见于倍频电路、分频电路，用于提取偶次谐波分量。

### (5) 快速记忆口诀
- 半波对称：**半周重合，只留偶次**
- 半波镜像：**半周反号，只留奇次**
- 二者共性：**都无直流分量**