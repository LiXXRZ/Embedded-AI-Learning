# 课程笔记：离散时间基本信号

## 一、 实指数序列 (Real Exponential Signals)
**定义**: $x[k] = A r^k, \quad k \in Z$

根据底数 $r$ 的取值，信号表现出不同的形态（单调/交替，发散/衰减）：

| $r$ 的范围 | 信号形态 | 描述 |
| :--- | :--- | :--- |
| **$r > 1$** | **单调发散** | 信号值随 $k$ 增加而正向增大。 |
| **$0 < r < 1$** | **单调衰减** | 信号值随 $k$ 增加而趋向于0。 |
| **$r = 1$** | **常数 (DC)** | 直流信号，值始终为 $A$。 |
| **$-1 < r < 0$**| **交替衰减** | 符号正负交替，幅度逐渐减小。 |
| **$r < -1$** | **交替发散** | 符号正负交替，幅度逐渐增大。 |
| **$r = -1$** | **等幅交替** | 在 $+A$ 和 $-A$ 之间跳变。 |

---

## 二、 虚指数与正弦序列 (Imaginary & Sinusoidal Signals)
**重点难点：周期性判断**

### 1. 定义
*   虚指数: $x[k] = e^{j\Omega_0 k}$
*   正弦序列: $x[k] = A \cos(\Omega_0 k + \varphi)$
*   **欧拉公式联系**: 
    $$e^{j\Omega_0 k} = \cos(\Omega_0 k) + j\sin(\Omega_0 k)$$

    $$\begin{aligned} \cos\Omega_0 k &= \frac{1}{2}\left(\mathrm{e}^{\mathrm{j}\Omega_0 k} + \mathrm{e}^{-\mathrm{j}\Omega_0 k}\right) \end{aligned}$$
    
    $$\begin{aligned} \sin\Omega_0 k &= \frac{1}{2\mathrm{j}}\left(\mathrm{e}^{\mathrm{j}\Omega_0 k} - \mathrm{e}^{-\mathrm{j}\Omega_0 k}\right) \end{aligned}$$

### 2. 离散信号周期性的**核心判据**
连续信号 $e^{j\omega_0 t}$ 总是周期的，但离散信号 $e^{j\Omega_0 k}$ **不一定**是周期的。

*   **周期条件**: 数字频率 $\Omega_0$ 与 $2\pi$ 的比值必须是**有理数**。
    $$ \frac{\Omega_0}{2\pi} = \frac{m}{N} \quad (\text{m, N 为互质整数}) $$
*   **周期 $N$**: 如果上述条件满足，则基本周期为 **$N$**。
    *   *物理意义*: $m$ 代表在 $N$ 个采样点中，包含的原连续信号的周期数。

### 3. 频率特性的差异
*   连续信号：频率 $\omega_0$ 越高，振荡越快。
*   离散信号：
    *   频率 $\Omega_0$ 与 $\Omega_0 + 2\pi$ 是完全相同的信号（**频率混叠**现象）。
    *   振荡最快发生在 $\Omega_0 = \pi$ (或 $3\pi, 5\pi...$) 附近。
    *   $\Omega_0 = 0$ 或 $2\pi$ 时不振荡（直流）。

### 4. 典型例题
*   $x_1[k] = \cos(k\pi/6)$: $\Omega_0 = \pi/6 \rightarrow \frac{\pi/6}{2\pi} = \frac{1}{12}$ (有理数)。**周期 $N=12$**。
*   $x_2[k] = \cos(k/6)$: $\Omega_0 = 1/6 \rightarrow \frac{1/6}{2\pi} = \frac{1}{12\pi}$ (无理数)。**非周期信号**。

---

## 三、 复指数序列 (Complex Exponential Signals)
**定义**: $x[k] = A r^k e^{j\Omega_0 k} = A z^k \quad (z = r e^{j\Omega_0})$

**物理意义**: 结合了振幅变化与振荡特性。
*   $0 < r < 1$: **阻尼振荡** (Attenuate)，幅度随时间衰减的螺旋/正弦。
*   $r > 1$: **增幅振荡** (Amplified)，幅度随时间增长。

---

## 四、 奇异信号 (Singularity Signals) - **重点**

### 1. 单位脉冲序列 (Unit Impulse Signal, $\delta[k]$)
**定义**:
$$ \delta[k] = \begin{cases} 1, & k=0 \\ 0, & k \neq 0 \end{cases} $$

**重要性质**:
*   **筛分/采样性质**: 任意序列 $x[k]$ 可表示为移位脉冲的加权和：
    $$ x[k] = \sum_{n=-\infty}^{\infty} x[n]\delta[k-n] $$
*   **与连续冲激 $\delta(t)$ 的区别**:
    *   $\delta(t)$ (连续): 宽度趋于0，高度趋于 $\infty$，**面积**为1。有缩放性质 $\delta(at) = \frac{1}{|a|}\delta(t)$。
    *   $\delta[k]$ (离散): 仅代表 $k=0$ 处数值为1，**幅度**为1。
    *   **缩放差异**: $\delta[3k]$ 依然等于 $\delta[k]$ (因为仅在 $3k=0 \Rightarrow k=0$ 时有值且为1，无幅度变化)。

### 2. 单位阶跃序列 (Unit Step Signal, $u[k]$)
**定义**:
$$ u[k] = \begin{cases} 1, & k \ge 0 \\ 0, & k < 0 \end{cases} $$

**与 $\delta[k]$ 的关系**:
1.  **差分**: $\delta[k] = u[k] - u[k-1]$
2.  **求和**: $u[k] = \sum_{n=-\infty}^{k} \delta[n]$

---

## 五、 其他常用信号

### 1. 矩形序列 (Rectangular Signal, $R_N[k]$)
**定义**: 长度为 $N$ 的矩形窗。
$$ R_N[k] = \begin{cases} 1, & 0 \le k \le N-1 \\ 0, & \text{其他} \end{cases} $$
**阶跃表示法**: $R_N[k] = u[k] - u[k-N]$

### 2. 斜变序列 (Ramp Signal, $r[k]$)
**定义**: $r[k] = k \cdot u[k]$
即 $k < 0$ 时为0，$k \ge 0$ 时值为 $0, 1, 2, 3...$