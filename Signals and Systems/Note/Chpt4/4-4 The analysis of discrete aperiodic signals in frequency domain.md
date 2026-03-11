# 学习笔记：离散非周期信号的频域分析 (DTFT)

## 零、 核心直觉：从“离散周期 (DFS)”到“离散非周期 (DTFT)”
在上一章 DFS 中，信号在时域是周期的，频谱在频域是离散且周期的。
当离散信号的**周期 $N \to \infty$** 时，它就退化成了一个**离散非周期信号**。
> **💡 发生了什么物理变化？**
> 频域的谱线间隔 $\Omega_0 = \frac{2\pi}{N} \to 0$，这意味着离散的谱线无限靠近，最终连成了一片**连续的曲线**。但由于离散信号本身的特性，这个连续的频谱**仍然是周期的（周期为 $2\pi$）**！

---

## 一、 👑 绝对核心：DTFT 与 IDTFT 公式对
对于满足绝对可和条件（$\sum |x[k]| < \infty$）的离散非周期信号 $x[k]$：

*   **DTFT (正变换，求频谱)**：
    $$X(e^{j\Omega}) = \sum_{k=-\infty}^{\infty} x[k] e^{-j\Omega k}$$
*   **IDTFT (反变换，合成时域)**：
    $$x[k] = \frac{1}{2\pi} \int_{<2\pi>} X(e^{j\Omega}) e^{j\Omega k} d\Omega$$
    *(注：积分号 $<2\pi>$ 表示在任意一个 $2\pi$ 区间内积分，通常选 $[-\pi, \pi]$)*

### 📌 离散频谱 $X(e^{j\Omega})$ 的两大独有特征（必考判断题）：
1.  **连续性 (Continuous)**：由于时域非周期，频谱是一个关于数字频率 $\Omega$ 的连续函数。
2.  **周期性 (Periodic)**：周期固定为 $\mathbf{2\pi}$。即 $X(e^{j(\Omega+2\pi)}) = X(e^{j\Omega})$。
    *(证明极简：因为 $e^{-j(\Omega+2\pi)k} = e^{-j\Omega k} \cdot e^{-j2\pi k}$，而 $e^{-j2\pi k} \equiv 1$)*

---

## 二、 🍎 三大基础信号的 DTFT 变换对 (一定要熟记)

### 1. 单位冲激序列 $\delta[k]$
代入定义：$X(e^{j\Omega}) = \sum \delta[k] e^{-j\Omega k} = e^0 = 1$
$$ \delta[k] \longleftrightarrow 1 $$
*(时域仅在 $0$ 处有值，频域包含所有频率成分，且等幅分布)*

### 2. 单边指数序列 $\alpha^k u[k]$ (系统最常见的响应)
代入定义进行等比数列求和：$X(e^{j\Omega}) = \sum_{k=0}^{\infty} (\alpha e^{-j\Omega})^k$
*   **收敛条件**：必须 $|\alpha| < 1$。
*   **结果**：
    $$ \alpha^k u[k] \longleftrightarrow \frac{1}{1 - \alpha e^{-j\Omega}} $$

### 3. 离散矩形序列 (宽度为 $2M+1$)
在 $k \in [-M, M]$ 时值为 1，其余为 0。
代入定义求和：$X(e^{j\Omega}) = \sum_{k=-M}^{M} e^{-j\Omega k}$。利用等比求和及提取半角公式（同 DFS 那章的技巧）：
$$ \text{离散矩形脉冲} \longleftrightarrow \frac{\sin[(M + 1/2)\Omega]}{\sin(\Omega/2)} $$
*(注：这称为离散的 Dirichlet 核，长得像连续信号的 $Sa$ 函数，但分母是 $\sin$)*

---

## 三、 🛠️ DTFT 的七大神级性质 (解题武器库)

### 1. 线性性质 (Linearity)
$$ax_1[k] + bx_2[k] \longleftrightarrow aX_1(e^{j\Omega}) + bX_2(e^{j\Omega})$$

### 2. 共轭对称性 (Symmetry)
若 $x[k]$ 为**实序列**：
*   $X(e^{j\Omega}) = X^*(e^{-j\Omega})$
*   **幅度谱** $|X(e^{j\Omega})|$ 必为**偶函数**。
*   **相位谱** $\varphi(\Omega)$ 必为**奇函数**。

### 3. 时域移位性质 (Time Shift)
$$x[k-n] \longleftrightarrow X(e^{j\Omega})e^{-j\Omega n}$$
> **💡 应用 (Slide 15 vs 17)**：
> 序列 $x_{centered}[k] = \{1, \underline{2}, 1\}$，它的谱是 $2(1+\cos\Omega)$，没有虚部，相位为0。
> 如果把它向右平移 1 位，变成因果序列 $y[k] = \{\underline{1}, 2, 1\}$，即 $y[k] = x[k-1]$。
> 那么 $Y(e^{j\Omega}) = 2(1+\cos\Omega)e^{-j\Omega}$，幅度谱不变，但**多了一个线性相移 $-\Omega$**。

### 4. 频域移位性质 (Frequency Shift)
$$x[k]e^{j\Omega_0 k} \longleftrightarrow X(e^{j(\Omega-\Omega_0)})$$
> **💡 应用 (Slide 19 核心例题)**：
> $y[k] = x[k]\cos(\pi k)$，求频谱？
> 拆开 $\cos$ 为欧拉形式：$\frac{1}{2}(e^{j\pi k} + e^{-j\pi k})$。
> 结果：$Y(e^{j\Omega}) = \frac{1}{2} \Big( X(e^{j(\Omega-\pi)}) + X(e^{j(\Omega+\pi)}) \Big)$
> 物理意义：将原频谱劈成两半，分别向左和向右平移 $\pi$（数字频率的最高频处）。

### 5. 卷积特性 (Convolution)
*   **时域卷积 = 频域相乘**： $x[k] * h[k] \longleftrightarrow X(e^{j\Omega})H(e^{j\Omega})$
*   **时域相乘 = 频域周期卷积**： $x[k] \cdot h[k] \longleftrightarrow \frac{1}{2\pi} \int_{-\pi}^{\pi} X(e^{j\theta})H(e^{j(\Omega-\theta)}) d\theta$

### 6. 频域微分 (Frequency Differentiation)
用来求前面带 $k$ 的序列：
$$k \cdot x[k] \longleftrightarrow j\frac{dX(e^{j\Omega})}{d\Omega}$$

### 7. 帕塞瓦尔定理 (Parseval's Theorem) —— 能量守恒
时域的总能量 = 频域的能量密度在一个周期 ($2\pi$) 内的积分：
$$ \sum_{k=-\infty}^{\infty} |x[k]|^2 = \frac{1}{2\pi} \int_{<2\pi>} |X(e^{j\Omega})|^2 d\Omega $$

---

## 四、 💥 期末压轴必考神题：不求谱，直接求积分！

**(对应课件 Slide 25，含金量极高！必须掌握！)**

**【题目】** 已知一个有限长序列 $x[k] = \{\underline{1}, 2, 3, 4\}$ （即 $x[0]=1, x[1]=2...$），它的 DTFT 为 $X(e^{j\Omega})$。在**不计算出 $X(e^{j\Omega})$ 具体表达式**的情况下，直接求下列四项的值：

**1) 求 $X(e^{j0})$**
*   **解密思路**：直接代入正变换公式 $X(e^{j\Omega}) = \sum x[k] e^{-j\Omega k}$。
*   令 $\Omega = 0$，则 $e^0 = 1$。
*   $X(e^{j0}) = \sum_{k=0}^3 x[k] \cdot 1 = 1 + 2 + 3 + 4 = \mathbf{10}$

**2) 求 $X(e^{j\pi})$**
*   **解密思路**：同上，令 $\Omega = \pi$。
*   此时 $e^{-j\pi k} = (\cos(-\pi) + j\sin(-\pi))^k = (-1)^k$。
*   $X(e^{j\pi}) = \sum x[k] \cdot (-1)^k = 1(-1)^0 + 2(-1)^1 + 3(-1)^2 + 4(-1)^3 = 1 - 2 + 3 - 4 = \mathbf{-2}$

**3) 求 $\int_{-\pi}^{\pi} X(e^{j\Omega}) d\Omega$**
*   **解密思路**：看到带 $X(e^{j\Omega})$ 的频域积分，**立刻想到 IDTFT 反变换公式！**
*   IDTFT 告诉你：$x[k] = \frac{1}{2\pi} \int_{-\pi}^{\pi} X(e^{j\Omega}) e^{j\Omega k} d\Omega$
*   对比目标式子，发现它正好等于令 $k=0$ 时的情况！
*   所以：$\int_{-\pi}^{\pi} X(e^{j\Omega}) \cdot e^0 d\Omega = 2\pi \cdot x[0] = 2\pi \times 1 = \mathbf{2\pi}$

**4) 求 $\int_{-\pi}^{\pi} |X(e^{j\Omega})|^2 d\Omega$**
*   **解密思路**：看到频域绝对值的平方积分，**立刻想到帕塞瓦尔定理！**
*   帕塞瓦尔定理告诉你：$\frac{1}{2\pi} \int_{-\pi}^{\pi} |X(e^{j\Omega})|^2 d\Omega = \sum |x[k]|^2$
*   所以：$\int_{-\pi}^{\pi} |X(e^{j\Omega})|^2 d\Omega = 2\pi \sum_{k=0}^3 |x[k]|^2 = 2\pi(1^2 + 2^2 + 3^2 + 4^2) = 2\pi(1+4+9+16) = \mathbf{60\pi}$

---

## 五、 🗺️ 全课灵魂：四大傅里叶变换大一统图谱
在《信号与系统》课程过半的时刻，课件给出了最伟大的大一统总结（Slide 26-28）。请把这两句**黄金口诀**刻在脑子里：
*   **“时域的离散，必然导致频域的周期”**
*   **“时域的周期，必然导致频域的离散”**

| 变换名称 | 时域特征 $t/k$ | 频域特征 $\omega/\Omega$ | 数学工具 | 备注 |
| :--- | :--- | :--- | :--- | :--- |
| **CTFS** (连续傅里叶级数) | **连续、周期** | **离散、非周期** | 积分与级数求和 | 算 $C_n$ |
| **CTFT** (连续傅里叶变换) | **连续、非周期** | **连续、非周期** | 无穷反常积分 | 算 $X(j\omega)$ |
| **DFS** (离散傅里叶级数) | **离散、周期** | **离散、周期** | 有限项循环求和 | 算 $\tilde{X}[m]$ |
| **DTFT** (离散傅里叶变换) | **离散、非周期** | **连续、周期** | 求和与有限积分 | 算 $X(e^{j\Omega})$ |

> **🌟 终极心法**：
> 现实世界（物理世界）的信号都是**连续且非周期的 (CTFT)**。
> 但是计算机内存是有限的，不能处理连续时间，所以我们要进行**采样（离散化）**；
> 计算机也不能存无穷长的信号，所以我们要把信号当做**周期循环（周期化）**。
> 当我们在计算机里同时做到了“离散化+周期化”，我们就走到了 **DFS**（工程上通常利用其主值区间，也就是大名鼎鼎的 **DFT / FFT 快速傅里叶变换**，这是下一门课《数字信号处理》的核心起点！）。