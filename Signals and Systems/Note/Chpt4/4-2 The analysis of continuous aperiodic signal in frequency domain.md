# 🚀 连续非周期信号的傅里叶变换 (CTFT)

## 零、 核心思想：周期信号如何演变为非周期信号？
> **💡 物理直觉**：
> 想象一个周期为 $T_0$ 的矩形脉冲列。当它的周期 $T_0$ 变得越来越大，直至 $T_0 \to \infty$ 时，相邻的脉冲退到了无穷远处，我们在有限的时间窗口内，只能看到一个孤立的矩形脉冲。这就是**非周期信号**。
>
> 在频域上发生了什么？
> 1. 谱线间隔 $\omega_0 = \frac{2\pi}{T_0}$。当 $T_0 \to \infty$ 时，$\omega_0 \to 0$。这意味着离散的谱线变得无限密集，连成了一片**连续的曲线**。
> 2. 原本的傅里叶系数 $C_n \propto \frac{1}{T_0}$，所以 $C_n \to 0$。为了描述频谱的相对大小，我们不再研究单一谱线的幅度，而是引入了**频谱密度函数 $X(j\omega)$**。

### 📌 傅里叶变换的定义 (CTFT)
*   **正变换 (从时域到频域)**：
    $$X(j\omega) = \int_{-\infty}^{\infty} x(t)e^{-j\omega t} dt$$
    *(物理意义：把信号 $x(t)$ 投影到频率为 $\omega$ 的复指数基底上，计算其在这 个频率上的分量大小)*
*   **反变换 (从频域回到时域)**：
    $$x(t) = \frac{1}{2\pi} \int_{-\infty}^{\infty} X(j\omega)e^{j\omega t} d\omega$$
    *(物理意义：将无数个连续频率 $\omega$ 的微小复指数分量积分叠加，还原出原信号)*
*   **狄利克雷条件**：信号绝对可积 $\int_{-\infty}^{\infty} |x(t)| dt < \infty$、极值点有限、间断点有限。

---

## 一、 👑 常见变换对
背熟这些，就相当于背熟了微积分里的导数基本公式。所有的复杂题目都是这八个基本信号的组合。

| 时域信号 $x(t)$ | 频域频谱密度 $X(j\omega)$ | 深度解析与记忆法 |
| :--- | :--- | :--- |
| **单位冲激** $\delta(t)$ | $1$ | 冲激信号只发生在瞬间，但它包含了**所有频率，且能量均匀分布**（白噪声特性）。 |
| **常数直流** $1$ | $2\pi \delta(\omega)$ | 永远不变的信号，频率只有 0，所以能量全部集中在 $\omega=0$ 的无穷大冲激上。 |
| **符号函数** $sgn(t)$ | $\frac{2}{j\omega}$ | 奇函数，所以频谱是**纯虚奇函数**。 |
| **单位阶跃** $u(t)$ | $\pi \delta(\omega) + \frac{1}{j\omega}$ | $u(t) = \frac{1}{2} + \frac{1}{2}sgn(t)$。频谱等于 直流的一半 + 符号函数的一半。**必须记住中间有个 $\pi\delta(\omega)$！** |
| **单边指数** $e^{-\alpha t}u(t)$ | $\frac{1}{\alpha + j\omega} \ (\alpha>0)$ | 这是积分算出来的：$\int_0^\infty e^{-\alpha t}e^{-j\omega t}dt = \frac{-1}{\alpha+j\omega}[e^{-(\alpha+j\omega)\infty} - 1]$。 |
| **矩形脉冲** $p_\tau(t)$ | $\tau Sa(\frac{\omega\tau}{2})$ | **最重要的公式**！脉宽 $\tau$，高为 1 的对称矩形。它的第一过零点带宽在 $\omega = \frac{2\pi}{\tau}$。 |
| **虚指数** $e^{j\omega_0 t}$ | $2\pi \delta(\omega - \omega_0)$ | 本身就是一个单一频率的信号，所以频谱在 $\omega_0$ 处有一个冲激。 |
| **余弦波** $\cos(\omega_0 t)$ | $\pi[\delta(\omega - \omega_0) + \delta(\omega + \omega_0)]$| 由欧拉公式 $\frac{e^{j\omega_0 t} + e^{-j\omega_0 t}}{2}$ 结合虚指数性质得到。 |
| **正弦波** $\sin(\omega_0 t)$ | $\frac{\pi}{j}[\delta(\omega - \omega_0) - \delta(\omega + \omega_0)]$| 注意：课件写成了 $j\pi[\delta(\omega+\omega_0) - \delta(\omega-\omega_0)]$，本质一样（提出分母的 $j$ 变符号）。 |
| **三角脉冲** $\Lambda_\tau(t)$ | $\frac{\tau}{2} Sa^2\left(\frac{\omega\tau}{4}\right)$ | 中心在 0、底宽 $\tau$、幅度 A。三角脉冲 = 矩形脉冲 * 矩形脉冲（时域卷积）。|

---

## 二、 🛠️ 降维打击：傅里叶变换的十大神级性质
遇到复杂的波形，千万不要直接套用定义去积分！利用这十大性质，所有的微积分都能转化为代数运算。

### 1. 线性性质 (Linearity)
$$ax_1(t) + bx_2(t) \longleftrightarrow aX_1(j\omega) + bX_2(j\omega)$$

**使用场景**：可以把复杂图形拆成两个简单图形的加减。

### 2. 共轭对称性 (Conjugate Symmetry)
若 $x(t)$ 是**实信号**，则其频谱具有共轭对称性：$X(j\omega) = X^*(-j\omega)$。
*   幅度谱 $|X(j\omega)|$ 是**偶函数**。
*   相位谱 $\varphi(\omega)$ 是**奇函数**。
*   **推论**：实偶信号 $\to$ 纯实偶频谱； 实奇信号 $\to$ 纯虚奇频谱。

### 3. 尺度变换性质 (Scaling)
$$x(at) \longleftrightarrow \frac{1}{|a|} X\left(j\frac{\omega}{a}\right)$$
*   **物理意义**：时域压缩 ($a>1$)，频域展宽且幅度降低；**时域越短，频带越宽**（这就是为什么短脉冲需要高带宽传输）。
> **💡 物理直觉**：
> 播放录音时，如果 2 倍速快进 ($a=2$)，时间变短了（时域压缩），你会听到声音变尖锐了，因为所有频率都被拉高了 2 倍（频域展宽），并且总能量不变所以幅度下降一半。
> **核心结论：时宽与频宽成反比。**（测不准原理的体现）

### 4. 时移性质 (Time Shift)
$$x(t - t_0) \longleftrightarrow X(j\omega)e^{-j\omega t_0}$$
**考点提示**：时域的平移，**不会改变幅度谱 $|X(j\omega)|$**，只会给相位谱增加一个与 $\omega$ 成正比的线性相移。

### 5. 频移性质 (Frequency Shift) —— 现代通信的基石
$$x(t) e^{j\omega_0 t} \longleftrightarrow X(j(\omega - \omega_0))$$
*   这就是通信中**调幅 (AM)** 的原理，把基带信号搬移到高频 $\omega_0$ 处！
> **💡 物理直觉**：
> 我们的声音频率很低（几百赫兹），无法直接通过天线发射。怎么发射？我们把声音 $x(t)$ 乘上一个极高频率的载波（比如 $\cos(\omega_0 t)$），根据频移性质，声音的频谱就被“搬运”到了高频 $\omega_0$ 附近发射出去！这就是**调幅 (AM)**。
> **推论公式**：$x(t)\cos(\omega_0 t) \longleftrightarrow \frac{1}{2}[X(j(\omega - \omega_0)) + X(j(\omega + \omega_0))]$

### 6. 频域/时域对称性 (对偶性 Reciprocal/Duality)
$$x(t) \longleftrightarrow X(j\omega) \implies X(jt) \longleftrightarrow 2\pi x(-\omega)$$
**超神用法**：
遇到求 $Sa(t)$ 函数的频谱时直接用！矩形波对应 $Sa(\omega)$，反过来 $Sa(t)$ 对应频域的矩形波！
考题中经常出现求 $x(t) = \frac{\sin t}{t} = Sa(t)$ 的频谱。你不可能积分积出来！
怎么办？利用对偶性！
已知：时域矩形脉冲 $p_2(t) \longleftrightarrow 2Sa(\omega)$ （这里 $\tau=2, A=1$）
对偶一下：时域换成 $2Sa(t)$，频域就变成了 $2\pi p_2(-\omega)$ （因为矩形是偶函数，所以 $p_2(-\omega)=p_2(\omega)$）。
所以 $Sa(t) \longleftrightarrow \pi p_2(\omega)$。这就是频域上的一个低通滤波器！

### 7. 时域微积分性质 (Time Differentiation & Integration)
*   **微分**：$\frac{dx(t)}{dt} \longleftrightarrow (j\omega)X(j\omega)$
       *(如果存在跳变点，使用微积分非常有效，导数会变成冲激 $\delta(t)$)*
    **做题利器**：如果波形有**直上直下的跳变点**，求一次导就会变成一系列的冲激函数 $\delta(t)$。如果波形是**折线**，求两次导就会变成冲激！然后利用 $\delta(t) \leftrightarrow 1$ 及平移性质瞬间解题。
*   **积分**：$\int_{-\infty}^{t} x(\tau) d\tau \longleftrightarrow \frac{1}{j\omega}X(j\omega) + \pi X(0)\delta(\omega)$
    **避坑**：千万别忘了加上 $\pi X(0)\delta(\omega)$！这是因为积分可能会产生一个直流分量，必须在 $\omega=0$ 处补上一个冲激。

### 8. 频域微分性质 (Frequency Differentiation)
$$t \cdot x(t) \longleftrightarrow j\frac{dX(j\omega)}{d\omega}$$

**使用场景**：用来求 $te^{-at}u(t)$ 这类信号的变换，直接对 $\frac{1}{a+j\omega}$ 频域求导即可。

### 9. 卷积定理 (Convolution)
*   **时域卷积定理**：$x_1(t) * x_2(t) \longleftrightarrow X_1(j\omega) \cdot X_2(j\omega)$
*   **频域卷积定理**：$x_1(t) \cdot x_2(t) \longleftrightarrow \frac{1}{2\pi} X_1(j\omega) * X_2(j\omega)$
**重要口诀：时域卷积，频域相乘；时域相乘，频域卷积卷并除以 $2\pi$。**

### 10. 帕塞瓦尔定理 (Parseval's Theorem) —— 能量守恒
对于非周期能量信号，时域算出的总能量，等于频域能量谱 $|X(j\omega)|^2$ 在频域的积分。
$$ W = \int_{-\infty}^{\infty} |x(t)|^2 dt = \frac{1}{2\pi} \int_{-\infty}^{\infty} |X(j\omega)|^2 d\omega $$

**考法**：考卷上经常会让你求一个极其复杂的时域积分（比如 $\int (\frac{\sin t}{t})^2 dt$），这其实是在暗示你：**转换到频域去求矩形面积！**
*   利用帕塞瓦尔定理反向求解复杂的反常积分。
    例：求 $\int_{-\infty}^{\infty} (\frac{\sin t}{t})^2 dt$。
    已知 $p_2(t) \leftrightarrow 2 Sa(\omega)$ 即 $\frac{\sin t}{t} \leftrightarrow \pi p_2(\omega)$（利用对偶性），带入公式立马秒杀，结果为 $\pi$。

---

## 三、 👑 镇课之宝：极限压轴大题详细拆解

### 🔥 压轴题 1：利用时域微分法求梯形脉冲频谱 (Slide 52)
**【题目】** $x(t)$ 在 $t=0\to1$ 为斜坡 $t$；$t=1\to3$ 为平顶 1；$t=3\to4$ 为下降斜坡 $4-t$。求 $X(j\omega)$。

**【极限详细解法：时域微分法】**
1.  **第一次求导 $x'(t)$**：
    *   在 $[0,1]$，斜率为 1。这相当于一个高度为 1，中心在 $0.5$ 的矩形脉冲 $p_1(t-0.5)$。
    *   在 $[3,4]$，斜率为 -1。相当于高度为 -1，中心在 $3.5$ 的矩形脉冲 $-p_1(t-3.5)$。
    *   式子表示：$x'(t) = p_1(t-0.5) - p_1(t-3.5)$。

2.  **对 $x'(t)$ 求傅里叶变换**：
    *   基本矩形脉冲 $p_1(t) \longleftrightarrow 1 \cdot Sa(\frac{\omega}{2})$
    *   利用**时移性质**：$p_1(t-0.5) \longleftrightarrow Sa(\frac{\omega}{2})e^{-j0.5\omega}$
    *   得到：$F[x'(t)] = Sa(\frac{\omega}{2})e^{-j0.5\omega} - Sa(\frac{\omega}{2})e^{-j3.5\omega}$

3.  **利用时域微分性质还原 $X(j\omega)$**：
    *   公式：$F[x'(t)] = j\omega X(j\omega)$
    *   所以：$X(j\omega) = \frac{1}{j\omega} Sa(\frac{\omega}{2}) \left( e^{-j0.5\omega} - e^{-j3.5\omega} \right)$

4.  **最终化简 (极其容易在此处丢分)**：
    *   提出中间的相位因子 $e^{-j2\omega}$（因为 $(0.5+3.5)/2 = 2$）：
        $e^{-j0.5\omega} - e^{-j3.5\omega} = e^{-j2\omega}(e^{j1.5\omega} - e^{-j1.5\omega})$
    *   利用欧拉公式：$e^{j1.5\omega} - e^{-j1.5\omega} = 2j \sin(1.5\omega) = 2j \sin(\frac{3\omega}{2})$
    *   代入原式：
        $$X(j\omega) = \frac{1}{j\omega} Sa\left(\frac{\omega}{2}\right) e^{-j2\omega} \cdot 2j \sin\left(\frac{3\omega}{2}\right)$$
    *   消去 $j$，并故意拼凑出 $Sa$ 形式：
        $= Sa\left(\frac{\omega}{2}\right) e^{-j2\omega} \cdot \frac{2\sin(3\omega/2)}{\omega}$
        $= Sa\left(\frac{\omega}{2}\right) e^{-j2\omega} \cdot 3 \frac{\sin(3\omega/2)}{3\omega/2}$
        $= \mathbf{3 Sa\left(\frac{\omega}{2}\right) Sa\left(\frac{3\omega}{2}\right) e^{-j2\omega}}$

**【拓展解法：利用卷积性质 (图形化思维)】**

观察梯形，它其实是**两个矩形波卷积的结果**！
令 $x_1(t)$ 是宽度为 1 的矩形 $p_1(t-0.5)$；$x_2(t)$ 是宽度为 3 的矩形 $p_3(t-1.5)$。
$$x(t) = x_1(t) * x_2(t)$$

根据时域卷积定理：
$$X(j\omega) = X_1(j\omega) \cdot X_2(j\omega) = \left[ Sa\left(\frac{\omega}{2}\right)e^{-j0.5\omega} \right] \cdot \left[ 3Sa\left(\frac{3\omega}{2}\right)e^{-j1.5\omega} \right]$$

$$X(j\omega) = 3 Sa\left(\frac{\omega}{2}\right) Sa\left(\frac{3\omega}{2}\right) e^{-j2\omega}$$

**【拓展解法：利用线性性质】**

观察梯形，它可以看作一个**大三角波减去一个小三角波**。
$$x(t) = x_{\text{大三角}}(t) - x_{\text{小三角}}(t)$$

分别套用三角波的频谱公式并进行时移，最后相减即可。

---

### 🔥 压轴题 2：频域卷积 / 频移性质求半波余弦 (Slide 55)
**【题目】** $x(t) = \cos(t) \cdot p_{\pi}(t)$，即在 $[-\pi/2, \pi/2]$ 之间有半个余弦波，其余为 0。求 $X(j\omega)$。

**【极限详细解法 1：频移性质】**
1.  **分解信号**：这是**矩形窗函数**乘上**高频载波**。
2.  **写出基本频谱**：$p_\pi(t) \longleftrightarrow \pi Sa(\frac{\pi\omega}{2})$。
3.  **利用频移公式**：乘以 $\cos(1 \cdot t)$，频谱分裂并左右平移。
    $$X(j\omega) = \frac{1}{2}[P_\pi(j(\omega - 1)) + P_\pi(j(\omega + 1))]$$
4.  **代入得出答案**：
    $$X(j\omega) = \frac{\pi}{2} \left[ Sa\left(\frac{\pi}{2}(\omega - 1)\right) + Sa\left(\frac{\pi}{2}(\omega + 1)\right) \right]$$

**【极限详细解法 2：二次微分构建方程法 (神仙思路)】**
1.  **求一阶导**：
    $$x'(t) = -\sin(t) \cdot p_{\pi}(t)$$
    *(注意：虽然在 $\pm\pi/2$ 处原函数变为0，没有突变，所以一阶导没有冲激 $\delta$)*
2.  **求二阶导**：
    $$x''(t) = -\cos(t) \cdot p_{\pi}(t) + \text{端点跳变产生的冲激}$$
    观察 $x'(t)$ 的图象（Slide 57），在 $t=-\pi/2$ 处从 0 跳变到 1；在 $t=\pi/2$ 处从 -1 跳变到 0。
    所以：$x''(t) = -x(t) + \delta(t + \frac{\pi}{2}) + \delta(t - \frac{\pi}{2})$
3.  **方程两边同时取傅里叶变换**：
    $$(j\omega)^2 X(j\omega) = -X(j\omega) + e^{j\frac{\pi}{2}\omega} + e^{-j\frac{\pi}{2}\omega}$$
4.  **化简求解 $X(j\omega)$**：
    $$-\omega^2 X(j\omega) + X(j\omega) = 2\cos\left(\frac{\pi}{2}\omega\right)$$
    $$X(j\omega)(1 - \omega^2) = 2\cos\left(\frac{\pi}{2}\omega\right)$$
    $$X(j\omega) = \mathbf{\frac{2\cos(\frac{\pi}{2}\omega)}{1 - \omega^2}}$$
*(这两种解法得到的结果在数学上是完全等价的，你可以用和差化积公式互相推导证明。但解法2不需要背 $Sa$ 函数移位，显得非常高级！)*

---

### 🔥 压轴题 3：帕塞瓦尔定理反向求定积分 (Slide 51)
**【题目】** 求积分 $I = \int_{-\infty}^{\infty} \left( \frac{\sin t}{t} \right)^2 dt$
**【解题步骤】**
1.  **识别目标**：看到无穷积分和平方，立刻想到帕塞瓦尔定理 $\int |x(t)|^2 dt = \frac{1}{2\pi}\int |X(j\omega)|^2 d\omega$。
2.  **找对偶信号**：
    设 $x(t) = \frac{\sin t}{t} = Sa(t)$。
    根据对偶性我们知道：$Sa(t) \longleftrightarrow \pi p_2(\omega)$ （一个在 $[ -1, 1 ]$ 之间幅度为 $\pi$ 的频域矩形窗）。
3.  **套用定理**：
    时域能量 = 频域能量。
    $$I = \int_{-\infty}^{\infty} |x(t)|^2 dt = \frac{1}{2\pi} \int_{-\infty}^{\infty} |X(j\omega)|^2 d\omega$$
    由于 $X(j\omega) = \pi p_2(\omega)$ 只有在 $-1 \to 1$ 之间有值 $\pi$，其余为0，所以频域积分就变成了一个简单的矩形面积计算：
    $$I = \frac{1}{2\pi} \int_{-1}^{1} (\pi)^2 d\omega = \frac{1}{2\pi} \cdot \pi^2 \cdot[1 - (-1)] = \frac{1}{2\pi} \cdot 2\pi^2 = \mathbf{\pi}$$