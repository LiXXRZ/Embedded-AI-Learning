# 学习笔记：连续时间 LTI 系统的频域分析

## 一、 为什么要进行频域分析？
在时域中，系统对信号的处理表现为输入信号 $x(t)$ 与系统冲激响应 $h(t)$ 的**卷积积分**：
$$y(t) = x(t) * h(t)$$

卷积积分计算复杂，且很难直观看出系统对信号到底做了什么改变（比如滤除了噪声还是保留了基波）。
转到频域后：**$Y_{zs}(j\omega) = X(j\omega) \cdot H(j\omega)$**。

**频域分析的优势**：在时域中，由于卷积运算的复杂性，很难直观看出系统（如三种不同的滤波器）对干扰信号的去噪效果。当利用傅里叶变换将信号转移到频域后，时域卷积变成了**频域乘法**，使得系统改变输入信号频谱各频率成分的具体过程（传输特性）变得非常直观。

**物理直觉**：系统函数 $H(j\omega)$ 就像一个**滤网（权重系数）**，直接乘在输入信号的各个频率分量 $X(j\omega)$ 上。通过看 $H(j\omega)$ 的图像，我们能一秒判断出系统保留了哪些频率（通带），切除了哪些频率（阻带）。

---

## 二、 连续时间LTI系统的频域描述
### 1. 频率响应 $H(j\omega)$ 的定义与推导
考察虚指数信号 $x(t) = e^{j\omega t}$ 通过LTI系统时的零状态响应 $y_{zs}(t)$：
$$y_{zs}(t) = e^{j\omega t} * h(t) = \int_{-\infty}^{\infty} e^{j\omega(t-\tau)}h(\tau)d\tau$$
将 $e^{j\omega t}$ 提取到积分号外：
$$y_{zs}(t) = e^{j\omega t} \int_{-\infty}^{\infty} h(\tau)e^{-j\omega \tau}d\tau$$
其中，积分部分定义为**系统的频率响应 $H(j\omega)$**，它本质上就是**系统冲激响应 $h(t)$ 的傅里叶变换**：
$$H(j\omega) = \mathscr{F}[h(t)] = \int_{-\infty}^{\infty} h(t)e^{-j\omega t}dt$$
最终结论：$y_{zs}(t) = H(j\omega)e^{j\omega t}$。
*   **物理意义**：
    $H(j\omega)$ 反映了连续系统对不同频率的虚指数信号的传输特性。
    当输入一个纯虚指数信号 $x(t) = e^{j\omega t}$ 时，系统的输出为 $y(t) = H(j\omega)e^{j\omega t}$。
    这意味着：**LTI 系统不会改变复指数信号的频率，只会改变它的幅度和相位。** 改变的规律完全由 $H(j\omega)$ 决定。

### 2. 幅频响应与相频响应
频率响应 $H(j\omega)$ 是个复数函数，可表示为极坐标形式：
$$H(j\omega) = |H(j\omega)| e^{j\varphi(\omega)}$$
*   **幅频响应 $|H(j\omega)|$**：当 $h(t)$ 为实函数时，它是 $\omega$ 的**偶函数**。
*   **相频响应 $\varphi(\omega)$**：当 $h(t)$ 为实函数时，它是 $\omega$ 的**奇函数**。

### 3. $H(j\omega)$ 的另一种定义与通用表达式
根据傅里叶变换的时域卷积定理，$y_{zs}(t) = x(t) * h(t)$ 可转换为：
$$Y_{zs}(j\omega) = X(j\omega)H(j\omega) \implies H(j\omega) = \frac{Y_{zs}(j\omega)}{X(j\omega)}$$
**由微分方程推导一般形式**：
若连续LTI系统由如下微分方程描述：
$$\sum_{k=0}^{n} a_k y^{(k)}(t) = \sum_{m=0}^{m} b_m x^{(m)}(t)$$
利用傅里叶变换的微分特性 $\mathscr{F}[f^{(n)}(t)] = (j\omega)^n F(j\omega)$，等式两边取傅里叶变换：
$$\left[\sum_{k=0}^{n} a_k (j\omega)^k \right] Y_{zs}(j\omega) = \left[\sum_{m=0}^{m} b_m (j\omega)^m \right] X(j\omega)$$
可以得到**频率响应的通用表达式**：
$$H(j\omega) = \frac{\sum_{m=0}^{m} b_m (j\omega)^m}{\sum_{k=0}^{n} a_k (j\omega)^k}$$

---

## 三、 系统频率响应 $H(j\omega)$ 的三种计算方法及例题

系统频率响应可以通过三种方式计算：
1. 从系统的冲激响应 $h(t)$ 进行傅里叶变换求得。
2. 从描述系统的微分方程求得。
3. 从实际电路的频域等效模型（将元件换成复阻抗）求得。

### 计算方法 1：利用冲激响应 $h(t)$
> **【例题 1】** 已知连续LTI系统的冲激响应为 $h(t) = (e^{-t} - e^{-2t})u(t)$，求系统的频率响应 $H(j\omega)$。
> **【解析】** 
> $H(j\omega) = \mathscr{F}\{h(t)\} = \mathscr{F}\{e^{-t}u(t)\} - \mathscr{F}\{e^{-2t}u(t)\}$
> $H(j\omega) = \frac{1}{j\omega + 1} - \frac{1}{j\omega + 2}$
> 通分化简得：$H(j\omega) = \frac{1}{(j\omega)^2 + 3(j\omega) + 2}$

### 计算方法 2：利用微分方程
> **【例题 2】** 已知描述连续LTI系统的微分方程为：$y''(t) + (2\pi f_w)y'(t) + (2\pi f_0)^2 y(t) = x''(t) + (2\pi f_0)^2 x(t)$，求该系统的频率响应 $H(j\omega)$。
> **【解析】** 
> 两边做傅里叶变换：
> $[(j\omega)^2 + 2\pi f_w(j\omega) + (2\pi f_0)^2]Y_{zs}(j\omega) =[(j\omega)^2 + (2\pi f_0)^2]X(j\omega)$
> $H(j\omega) = \frac{Y_{zs}(j\omega)}{X(j\omega)} = \frac{(j\omega)^2 + (2\pi f_0)^2}{(j\omega)^2 + 2\pi f_w(j\omega) + (2\pi f_0)^2}$
> *（注：这是一个中心频率为 $f_0$、3dB带宽为 $f_w$ 的二阶带阻滤波器）*

### 计算方法 3：利用频域等效电路模型
*   电容等效阻抗：$\frac{V_C(j\omega)}{I_C(j\omega)} = \frac{1}{j\omega C}$
*   电感等效阻抗：$\frac{V_L(j\omega)}{I_L(j\omega)} = j\omega L$

> **【例题 3】** 如图 RC 电路系统，激励电压源为 $x(t)$，输出 $y(t)$ 为电容两端电压 $v_C(t)$，初始状态为零。求频率响应 $H(j\omega)$ 和冲激响应 $h(t)$。
> **【解析】** 
> 利用复阻抗进行分压定律计算：
> $H(j\omega) = \frac{Y(j\omega)}{X(j\omega)} = \frac{\frac{1}{j\omega C}}{R + \frac{1}{j\omega C}} = \frac{1/RC}{j\omega + 1/RC}$
> 求逆傅里叶变换得到冲激响应：
> $h(t) = \mathscr{F}^{-1}\{H(j\omega)\} = \frac{1}{RC} e^{-(1/RC)t} u(t)$
> *（分析：当 $|H(j(1/RC))| \approx 0.707$ 即 $\frac{1}{\sqrt{2}}$ 时，对应系统的 3dB 截止频率 $\omega_c = 1/RC$）*

---

## 四、 信号通过连续LTI系统的频域分析

### 1. 非周期信号的分析
核心公式：$Y_{zs}(j\omega) = H(j\omega)X(j\omega) \implies y_{zs}(t) = \mathscr{F}^{-1}[Y_{zs}(j\omega)]$

> **【例题 4】** 已知 LTI 系统的微分方程为 $y''(t) + 3y'(t) + 2y(t) = 3x'(t) + 4x(t)$。输入激励为 $x(t) = e^{-3t}u(t)$，求系统的零状态响应 $y_{zs}(t)$。
> **【解析】** 
> 1) 激励的频谱：$X(j\omega) = \frac{1}{j\omega + 3}$
> 2) 系统频率响应：$H(j\omega) = \frac{3(j\omega) + 4}{(j\omega)^2 + 3(j\omega) + 2} = \frac{3(j\omega) + 4}{(j\omega + 1)(j\omega + 2)}$
> 3) 输出频谱：$Y_{zs}(j\omega) = X(j\omega)H(j\omega) = \frac{3(j\omega) + 4}{(j\omega + 1)(j\omega + 2)(j\omega + 3)}$
> 4) 部分分式展开：$Y_{zs}(j\omega) = \frac{1/2}{j\omega + 1} + \frac{2}{j\omega + 2} - \frac{5/2}{j\omega + 3}$
> 5) 求逆变换：$y_{zs}(t) = \left[ \frac{1}{2}e^{-t} + 2e^{-2t} - \frac{5}{2}e^{-3t} \right] u(t)$

**无解情况：** **傅里叶变换根本不存在** 此时频域法彻底失效，必须使用“拉普拉斯变换 (Laplace Transform)”才能解决（这也是后续章节引入拉普拉斯变换的根本原因）。

> **【例题 5】** 仍是例题4的方程，若激励改为：(1) $x_1(t) = \cos(2t)u(t)$；(2) $x_2(t) = e^{2t}u(t)$，尝试用频域法求解。
> **【解析】** 
> 对 (1)：由于 $X_1(j\omega) = \frac{\pi}{2}[\delta(\omega-2) + \delta(\omega+2)] + \frac{j\omega}{4-\omega^2}$，在求 $Y_{zs}$ 后需要对含有 $\frac{j\omega H(j\omega)}{4-\omega^2}$ 的项求傅里叶逆变换，极其困难。
> 对 (2)：因为 $x_2(t) = e^{2t}u(t)$ 不满足绝对可积，**不存在傅里叶变换**，故无法用频域法求解。

### 2. 周期信号的响应
**正弦信号的频域响应推导**：
输入 $x(t) = \sin(\omega_0 t + \theta)$，由欧拉公式展开：
$x(t) = \frac{e^{j(\omega_0 t + \theta)} - e^{-j(\omega_0 t + \theta)}}{2j}$
利用虚指数信号的响应特性叠加：
$y_{zs}(t) = \frac{H(j\omega_0)e^{j(\omega_0 t + \theta)} - H(-j\omega_0)e^{-j(\omega_0 t + \theta)}}{2j}$
代入 $H(j\omega_0) = |H(j\omega_0)|e^{j\varphi(\omega_0)}$，化简得：
$y_{zs}(t) = |H(j\omega_0)| \sin(\omega_0 t + \varphi(\omega_0) + \theta)$
**结论**：正弦/余弦信号通过 LTI 系统后，**仍是同频率的弦波，只是幅度乘了 $|H(j\omega_0)|$，相位叠加了 $\varphi(\omega_0)$**。

**一般周期信号的响应**：
通过傅里叶级数展开 $x(t) = \sum C_n e^{jn\omega_0 t}$，可得 $\tilde{y}_{zs}(t) = \sum C_n H(jn\omega_0) e^{jn\omega_0 t}$。

> **【例题 6】** 已知连续时间系统的频率响应为底边从 $-3$ 到 $3$、顶点在 $(0,1)$ 的三角形（即 $\omega=0$ 时幅度为1，$\pm3$ 处为0）。输入信号 $x(t) = 5 + 3\cos(2t) + \cos(4t)$，求稳态响应 $y(t)$。
> **【解析】**
> $y(t) = 5H(j0) + 3|H(j2)|\cos(2t) + |H(j4)|\cos(4t)$
> 由图可读出：$H(j0) = 1$，$H(j2) = 1 - 2/3 = 1/3$，$H(j4) = 0$（超出频带）。
> 故 $y(t) = 5(1) + 3(1/3)\cos(2t) + 0 = 5 + \cos(2t)$。

> **【例题 7】** 试求周期为 4 的方波通过例题3中的 RC 低通滤波电路的响应。
> **【解析】**
> 周期方波的傅里叶系数为 $C_n = 0.5 Sa(0.5\pi n)$，系统 $H(j\omega) = \frac{1}{1 + j\omega RC}$
> 系统的稳态输出为：
> $\tilde{y}(t) = \sum_{n=-\infty}^{\infty} C_n \cdot H(jn\omega_0) e^{jn\omega_0 t} = \sum_{n=-\infty}^{\infty} \frac{Sa(0.5\pi n)}{1 + j0.5n\pi RC} e^{jn\pi t/2}$

---

## 五、 无失真传输系统

**物理概念**：信号通过系统后，波形形状**完全没有变化**，只允许有幅度的缩放（变大变小）和时间的延迟（晚一点到达）。
*   **时域数学条件**：$y(t) = K \cdot x(t - t_d)$ （$K$ 为幅度增益，$t_d$ 为延迟时间）
*   **时域冲激响应**：$h(t) = K \delta(t - t_d)$

**无失真的概念**：指信号传输过程中不发生**非线性失真**（不产生新频率成分），且**线性失真**仅表现为波形的等比例放缩和时间延迟。
时域表达式：
$$y(t) = K \cdot x(t - t_d)$$ （$K$为增益常数，$t_d$为延迟时间）。
频域要求（对时域表达式做傅里叶变换得出）：
$$H(j\omega) = K e^{-j\omega t_d}$$

对 $h(t)$ 傅里叶变换，**无失真系统必须同时满足**：
1.  **幅频响应恒定**：$|H(j\omega)| = K$。这意味着系统对所有频率的放缩是一致的，有无限大的带宽。（如果不满足，叫**幅度失真**）。
2.  **相频响应成线性**：$\varphi(\omega) = -\omega t_d$。相位必须是频率 $\omega$ 的正比例函数，且过原点。（如果不满足，叫**相位失真**）。
    *(理解：频率越高的信号波动越快，为了让所有频率在时间上都只延迟 $t_d$ 秒，高频信号必须偏移更多的“相位角”，因此相移必须与频率成正比。)*

> **【例题 8】** 已知系统频率响应 $H(j\omega) = \frac{1 - j\omega}{1 + j\omega}$。
> (1) 求 $|H(j\omega)|$ 和 $\varphi(\omega)$，并判断是否是无失真传输系统。
> (2) 当输入为 $x(t) = \sin(t) + \sin(3t)$ 时，求稳态响应。
> **【解析】**
> (1) 因为 $H(j\omega) = 1 \cdot e^{-j 2\arctan(\omega)}$，故幅频响应 $|H(j\omega)| = 1$，相频响应 $\varphi(\omega) = -2\arctan(\omega)$。
> 尽管幅度响应恒定，但**相频响应不是 $\omega$ 的线性函数**，因此**不是**无失真系统。
> (2) $y(t) = |H(j1)|\sin[t + \varphi(1)] + |H(j3)|\sin[3t + \varphi(3)]$
> 代入 $\omega=1$ 和 $\omega=3$ 对应的相位：
> $y(t) = \sin(t - \pi/2) + \sin(3t - 0.7952\pi)$
> 输出波形产生了严重畸变（原因：非线性相位造成的延迟时间不一致）。

---

## 六、 理想模拟滤波器 (Ideal Analog Filter)
### 1. 线性相位理想低通滤波器
*   **频域定义**：
    $$ H(j\omega) = \begin{cases} e^{-j\omega t_d}, & |\omega| < \omega_c \\ 0, & |\omega| > \omega_c \end{cases} $$
    (在 $\omega_c$ 范围内幅值为1，相位线性；外部全部切除)。
*   **频域特性**：
    幅频特性：在通带 $-\omega_c < \omega < \omega_c$ 恒为 $1$，阻带为 $0$。
    相频特性：$\varphi(\omega) = -\omega t_d$（线性）。

### 2. 理想低通滤波器的冲激响应与阶跃响应
**冲激响应 $h(t)$ 的推导**：
$$h(t) = \frac{1}{2\pi} \int_{-\omega_c}^{\omega_c} 1 \cdot e^{-j\omega t_d} e^{j\omega t} d\omega = \frac{\omega_c}{\pi} Sa[\omega_c(t - t_d)]$$
*   **非因果与物理不可实现性**：$h(t)$ 是一个无限延伸的 Sa 抽样函数，在 $t < 0$ 时也有输出，说明系统在激励加入之前就有响应，这是物理上无法实现的。
*   主峰出现在 $t = t_d$，即延迟时间，由相频曲线的斜率决定。

**阶跃响应 $g(t)$ 与吉布斯现象**：
阶跃响应是 $h(t)$ 的积分。
$$g(t) = \int_{-\infty}^t h(\tau)d\tau = \frac{1}{2} + \frac{1}{\pi} \int_0^{\omega_c(t-t_d)} Sa(\lambda)d\lambda$$
*   **上升时间 $t_r$**：$g(t)$ 的上升时间反比于滤波器的截止频率 $\omega_c$（带宽越宽，响应越快）。
*   **吉布斯现象 (Gibbs phenomenon)**：阶跃响应在突变点附近会有上下振荡现象，最大过冲峰值约占突变值的 **9%**。这个比例**不随**滤波器带宽的增加而减小。

---

## 七、 综合应用例题：连续LTI系统频域分析

> **【例题 9】** 已知理想模拟低通滤波器的频率响应为：$|\omega| < 2\pi$ 时 $H(j\omega) = e^{-j 2\omega}$，其余为 $0$。（注意这里的截止频率 $\omega_c = 2\pi$）
> **(1) 输入信号 $x_1(t) = Sa(\pi t)$，求系统输出 $y_1(t)$。**
> **【解析】** 由基础傅里叶变换知 $Sa(\pi t) \leftrightarrow p_{2\pi}(\omega)$。
> 因为输入信号的带宽为 $(-\pi, \pi)$，完全落入滤波器的通带 $(-2\pi, 2\pi)$ 内部，因此通过时不被截断，仅附加相位。
> $Y_1(j\omega) = p_{2\pi}(\omega)e^{-j 2\omega}$
> 逆傅里叶变换，利用时移特性：$y_1(t) = Sa[\pi(t - 2)]$。
> 
> **(2) 输入信号 $x_2(t) = Sa(3\pi t)$，求系统输出 $y_2(t)$。**
> **【解析】** $x_2$ 的频谱为 $X_2(j\omega) = \frac{1}{3} p_{6\pi}(\omega)$，其带宽超出了低通滤波器的截止频率。
> 经过滤波器截断后：$Y_2(j\omega) = \frac{1}{3} p_{4\pi}(\omega)e^{-j 2\omega}$（被截止于 $\pm 2\pi$，故门宽变为 $4\pi$）。
> 由 $\mathscr{F}^{-1}\{p_{4\pi}(\omega)\} = \frac{2\pi}{\pi} Sa(2\pi t) = 2 Sa(2\pi t)$。
> 再考虑到时移 $-j 2\omega$ 以及前面的系数 $\frac{1}{3}$：
> $y_2(t) = \frac{1}{3} \cdot 2 Sa[2\pi(t-2)] = \frac{2}{3} Sa[2\pi(t - 2)]$。
> 
> **(3) 输入信号 $x_3(t)$ 为周期矩形波（波形为从 $0$到$1$ 为$1$，从 $1$到$2$ 为$-1$），求输出 $y_3(t)$。**
> **【解析】** 
> 信号基频 $\omega_0 = 2\pi / T_0 = 2\pi / 2 = \pi$。
> 滤波器截频为 $2\pi$，因此只有直流分量（$n=0$）和基波分量（$n=\pm 1$）能通过。
> 由于波形的奇对称性，直流分量 $C_0 = 0$。
> 计算一次谐波系数 $C_1 = \frac{1}{2} \int_0^2 x_3(t) e^{-j\pi t} dt = \frac{2}{j\pi}$。
> $C_{-1} = C_1^* = -\frac{2}{j\pi}$。
> 输出表达式为：$y_3(t) = C_{-1} H(-j\pi) e^{-j\pi t} + C_1 H(j\pi) e^{j\pi t}$
> 代入 $H(j\pi) = e^{-j 2\pi} = 1$、$H(-j\pi) = e^{j 2\pi} = 1$：
> $y_3(t) = -\frac{2}{j\pi} e^{-j\pi t} + \frac{2}{j\pi} e^{j\pi t} = \frac{4}{\pi} \frac{e^{j\pi t} - e^{-j\pi t}}{2j} = \frac{4}{\pi}\sin(\pi t)$
> *(注：由于 $e^{-j\pi (t-2)} = e^{-j\pi t} \cdot e^{j 2\pi} = e^{-j\pi t}$，时移经过周期函数的整数倍周期后正好重合)*

---

## 八、 总结：频域分析的优缺点评价

*   **优点**：在求解系统的零状态响应时，能够直观地反映信号通过系统后频谱的变化。物理概念清晰，能很好地解释时域波形产生差异的原因（例如信号为何被平滑、为何产生失真）。
*   **不足之处**：
    1.  只能求解**零状态响应**。无法求解零输入响应（零输入响应仍需用时域方法求解）。
    2.  当激励信号或系统的冲激响应**不满足绝对可积条件**，导致**傅里叶变换不存在**时（如 $e^{2t}u(t)$），频域分析法完全失效。
*   **解决方案**：为了克服傅里叶变换的局限性并统一处理初始状态，引入**拉普拉斯变换 (Laplace Transform)** 是一种自然且必要的进阶手段。