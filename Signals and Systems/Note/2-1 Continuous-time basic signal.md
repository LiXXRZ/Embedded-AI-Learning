# 课程笔记：连续时间信号 (Continuous Time Signals)

## 信号分类概览
*   **常规信号 (Regular signals)**: 信号 $x(t)$ 及其各阶导数本身无间断点（无跳变）。
*   **奇异信号 (Singularity signals)**: 信号本身或其导数存在间断点（跳变点）。

---

## 第一部分：常规信号 (Regular Signals)

**定义**：信号函数 $x(t)$ 及其导数在定义域内连续，无间断点（无跳变）。

### 1. 核心：复指数信号 (Complex Exponential Signals)
这是信号与系统中最基本的“积木”信号，其他信号（直流、正弦、实指数）都是它的特例。

**通式**：

$$x(t) = A e^{st}$$

其中复频率 $s = \sigma + j\omega_0$。

#### 四种形态演变（重点）
根据 $s$ 的实部 $\sigma$ 和虚部 $\omega_0$ 的取值不同，信号表现出不同形态：

1.  **实指数信号** ($\omega_0 = 0, s = \sigma$)：
    *   $x(t) = A e^{\sigma t}$
    *   $\sigma > 0$：**发散**（单调增长，如雪崩）。
    *   $\sigma < 0$：**衰减**（单调趋零，如RC电路放电）。
    *   $\sigma = 0$：**直流信号** (DC)，$x(t) = A$, 频谱表现为零频分量。

2.  **虚指数信号** ($\sigma = 0, s = j\omega_0$)：
    *   $x(t) = e^{j\omega_0 t}$
    *   **欧拉公式 (Euler Formula)**：连接正余弦与虚指数信号的桥梁

        $$e^{j\omega_0 t} = \cos(\omega_0 t) + j\sin(\omega_0 t)$$

        $$\cos(\omega_0 t) = \frac{1}{2}(e^{j\omega_0 t} + e^{-j\omega_0 t})$$

    *   **物理意义**：在复平面上，这是一个模为1、以角速度 $\omega_0$ 旋转的向量。
    *   **周期性**：$T_0 = \frac{2\pi}{|\omega_0|}$。

3.  **复指数信号** ($\sigma \neq 0, \omega_0 \neq 0$)：
    *   $x(t) = A e^{\sigma t} e^{j\omega_0 t} = A e^{\sigma t} [\cos(\omega_0 t) + j\sin(\omega_0 t)]$
    *   **物理意义**：振幅随 $e^{\sigma t}$ 变化的振荡信号。
        *   $\sigma < 0$：**阻尼振荡**（如弹簧阻尼系统，振幅越来越小）。
        *   $\sigma > 0$：**增幅振荡**。

### 2. 抽样信号 (Sampling Signals, Sa函数)
**定义**：
$$Sa(t) = \frac{\sin t}{t}$$

**三大关键性质**：
1.  **0时刻的值**：$Sa(0) = \lim_{t \to 0} \frac{\sin t}{t} = 1$（洛必达法则）。
2.  **过零点**：当 $\sin t = 0$ 且 $t \neq 0$ 时，即 $t = k\pi (k = \pm 1, \pm 2, \dots)$。
3.  **积分特性**：$\int_{-\infty}^{+\infty} Sa(t) dt = \pi$（这是一个能量有限的信号）。

---

## 第二部分：奇异信号 (Singularity Signals)
**定义**：信号本身或其导数存在间断点（跳变点）。

### 1. 单位阶跃信号 (Unit Step Signal) $u(t)$
**数学定义**：
$$u(t) = \begin{cases} 1, & t > 0 \\ 0, & t < 0 \end{cases}$$
*(注意：$t=0$ 处的定义通常无物理意义，视具体问题而定)*

**两大功能应用**：
1.  **表示分段信号/矩形脉冲** (截取)：
    *   利用 $u(t)$ 表示分段信号，矩形窗函数 $G_T(t)$ 可以表示为两个阶跃之差：
        $$x(t) = u(t - T_1) - u(t - T_2)$$
    *   这表示从 $T_1$ 开启，到 $T_2$ 关闭。
2.  **表示信号的单边性** (选通/开关)：
    *   $\sin(\omega_0 t) \cdot u(t)$：表示正弦波仅在 $t>0$ 时存在（如开关闭合瞬间开启的交流电）。
    *   $\sin(\omega_0 (t-t_0)) \cdot u(t-t_0)$：表示整个波形延迟了 $t_0$ 开启。

### 2. 单位冲激信号 (Unit Impulse Signal) $\delta(t)$ —— **全章核心**

#### A. 理解模型
*   **物理模型**：瞬间发生的巨大作用，如雷击、击球。作用时间 $\Delta t \to 0$，幅值 $\to \infty$，但**积分面积（冲量/强度）保持为1**。
*   **狄拉克 (Dirac) 定义**：
    1.  $\delta(t) = 0, \quad t \neq 0$
    2.  $\int_{-\infty}^{+\infty} \delta(t) dt = 1$ (单位面积/强度)

#### B. 三大关键性质 (必须熟练掌握)

**性质1：筛选性 (Screening Property) —— 乘法运算**
$$x(t)\delta(t - t_0) = x(t_0)\delta(t - t_0)$$
*   **含义**：任意函数与冲激函数相乘，结果**仍然是一个冲激函数**，只是这个冲激函数的强度（面积）变成了 $x(t_0)$。

**性质2：抽样性 (Sampling Property) —— 积分运算**
$$\int_{-\infty}^{+\infty} x(t)\delta(t - t_0) dt = x(t_0)$$
*   **含义**：利用积分“筛”出了函数在 $t_0$ 处的数值。
*   **重要陷阱**：**积分区间必须包含 $t_0$ ，否则结果为 0**。
    *   若 $t_0 \in (a, b)$，则 $\int_a^b x(t)\delta(t-t_0)dt = x(t_0)$
    *   若 $t_0 \notin (a, b)$，则积分结果为 **0**。

**性质3：尺度变换 (Shrinkage/Scaling Property)**
$$\delta(at) = \frac{1}{|a|}\delta(t)$$
*   **推论1** ：
    $$\delta(at + b) = \delta\left[a\left(t + \frac{b}{a}\right)\right] = \frac{1}{|a|}\delta\left(t + \frac{b}{a}\right)$$
    *   步骤：先提公因式 $a$，再将系数变倒数取绝对值提出来。

*   **推论2** ：
    $$a = -1$$

    $$\delta(t) = \delta(-t)$$
    
    *   偶函数 (Even Function)


#### C. 计算例题精选 (Example Calculations)

> **技巧总结**:
> 1. 先将 $\delta(...)$ 变换为标准的 $\delta(t-t_0)$ 形式（利用尺度变换性质）。
> 2. 检查冲激点 $t_0$ 是否在积分区间内。
> 3. 若是积分，结果是数值；若是相乘，结果是含 $\delta$ 的函数。

*   **例 (1)**: $\int_{-\infty}^{+\infty} \sin(t) \cdot \delta(t - \frac{\pi}{4}) dt$
    *   **分析**: 积分区间 $(-\infty, +\infty)$ 包含 $t_0 = \pi/4$。
    *   **解**: 直接代入 $t = \pi/4$。结果 $= \sin(\pi/4) = \frac{\sqrt{2}}{2}$。

*   **例 (2)**: $\int_{-2}^{+3} e^{-5t} \cdot \delta(t - 1) dt$
    *   **分析**: 冲激点在 $t=1$。检查区间 $[-2, 3]$，**包含** 1。
    *   **解**: 代入 $t=1$。结果 $= e^{-5(1)} = e^{-5}$。

*   **例 (3)**: $\int_{-4}^{+6} e^{-2t} \cdot \delta(t + 8) dt$
    *   **分析**: 冲激点在 $t = -8$。检查区间 $[-4, 6]$，**不包含** -8。
    *   **解**: 结果 $= 0$。

*   **例 (4)**: $\int_{-\infty}^{+\infty} e^{-t} \cdot \delta(2 - 2t) dt$
    *   **难点**: $\delta$ 内部复杂，需先利用尺度变换性质。
    *   **变换**: $\delta(2 - 2t) = \delta[-2(t - 1)]$。根据 $\delta(at) = \frac{1}{|a|}\delta(t)$，这里 $a=-2$。
        $\Rightarrow \delta(2-2t) = \frac{1}{|-2|}\delta(t-1) = \frac{1}{2}\delta(t-1)$。
    *   **解**: 原式 $= \int e^{-t} \cdot \frac{1}{2}\delta(t-1) dt = \frac{1}{2} e^{-1}$。

*   **例 (5)**: $\int_{-2}^{+2} (t^2 + 3t) \cdot \delta(\frac{t}{3} - 1) dt$
    *   **变换**: $\delta(\frac{1}{3}t - 1) = \delta[\frac{1}{3}(t - 3)]$。这里 $a=1/3$。
        $\Rightarrow$ 系数变为 $\frac{1}{|1/3|} = 3$。新冲激函数为 $3\delta(t-3)$。
    *   **分析**: 新的冲激点 $t=3$。检查区间 $[-2, 2]$，**不包含** 3。
    *   **解**: 结果 $= 0$。

*   **例 (6)**: $e^{-4t} \cdot \delta(2 + 2t)$
    *   **注意**: 这是一个**没有积分符号**的题目，求的是表达式，利用的是**性质1（筛选性）**。
    *   **变换**: $\delta(2+2t) = \delta[2(t+1)] = \frac{1}{2}\delta(t+1)$。
    *   **解**: $e^{-4t} \cdot \frac{1}{2}\delta(t+1)$。
        令 $t = -1$ 代入前面的函数部分：$e^{-4(-1)} = e^4$。
        结果 $= \frac{1}{2} e^4 \delta(t+1)$。
    *   *(注：结果仍然是一个冲激信号)*

### 3. 单位斜变信号 (Unit Ramp Signal) $r(t)$
*   **定义**:
    $$r(t) = \begin{cases} t, & t \ge 0 \\ 0, & t < 0 \end{cases} \quad \text{或} \quad r(t) = t \cdot u(t)$$
*   **关系**: $r(t) = \int_{-\infty}^{t} u(\tau) d\tau$ （阶跃的积分）

### 4. 单位冲激偶信号 (Unit Impulse Pair Signal) $\delta'(t)$
*   **定义**：$\delta'(t) = \frac{d\delta(t)}{dt}$
*   **性质**：
    1.  **奇函数**：$\delta'(t) = -\delta'(-t)$。
    2.  **高阶抽样性 (关键)** (Slide 37)：
        $$\int_{-\infty}^{+\infty} x(t)\delta'(t - t_0) dt = -x'(t_0)$$
        *   **推导逻辑**：分部积分法。
        *   **记忆口诀**：遇到冲激偶 $\delta'$ 的积分，结果是对原函数求导、代值，前面加**负号**。
    3.  **积分**: $\int_{-\infty}^{\infty} \delta'(t)dt = 0$

---

## 第三部分：四种奇异信号的关系链
**记忆链条：积分 $\leftrightarrow$ 导数**
$$斜变 r(t) \xrightarrow[\text{求导}]{\frac{d}{dt}} 阶跃 u(t) \xrightarrow[\text{求导}]{\frac{d}{dt}} 冲激 \delta(t) \xrightarrow[\text{求导}]{\frac{d}{dt}} 冲激偶 \delta'(t)$$

**反之即为积分关系**：
*   $u(t) = \int_{-\infty}^t \delta(\tau) d\tau$
*   $r(t) = \int_{-\infty}^t u(\tau) d\tau$

$$r(t) \xrightarrow{\frac{d}{dt}} u(t) \xrightarrow{\frac{d}{dt}} \delta(t) \xrightarrow{\frac{d}{dt}} \delta'(t)$$

$$\delta'(t) \xrightarrow{\int} \delta(t) \xrightarrow{\int} u(t) \xrightarrow{\int} r(t)$$

*   斜变是阶跃的积分。
*   阶跃是冲激的积分。
*   冲激是阶跃的导数。

**应用场景**：
*   如果遇到一个分段常数信号（像楼梯一样的波形），求它的导数，就会得到一串冲激函数。冲激函数的强度等于台阶的跳变高度。
*   跳变向上（$+A$），导数就是正冲激 $+A\delta(t-t_0)$。
*   跳变向下（$-A$），导数就是负冲激 $-A\delta(t-t_0)$。