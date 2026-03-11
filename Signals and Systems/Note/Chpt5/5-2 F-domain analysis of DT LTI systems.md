# 学习笔记：离散时间 LTI 系统的频域分析

## 零、 核心思维转换：频域视角的系统
在时域中，离散系统的零状态响应是卷积和：$y_{zs}[k] = x[k] * h[k]$。
在频域中，由于 DTFT 的卷积定理，复杂的卷积变成了简单的**乘法**：
$$ Y_{zs}(e^{j\Omega}) = X(e^{j\Omega}) \cdot H(e^{j\Omega}) $$
> **💡 物理直觉**：
> 系统的频率响应 $H(e^{j\Omega})$ 就像一个“频率滤网”：输入信号 $X(e^{j\Omega})$ 中不同频率的成分经过系统时，会被这个滤网赋予不同的**幅度缩放**和**相位偏移**。

---

## 一、 👑 绝对核心：离散系统频率响应 $H(e^{j\Omega})$

### 1. 定义与本质
*   **数学定义**：系统单位脉冲响应 $h[k]$ 的 DTFT 变换。
    $$ H(e^{j\Omega}) = \text{DTFT}\{h[k]\} = \sum_{k=-\infty}^{\infty} h[k] e^{-j\Omega k} $$
*   **物理本质（特征函数特性）**：
    当系统输入为虚指数序列 $x[k] = e^{j\Omega k}$ 时，输出 $y[k] = H(e^{j\Omega}) \cdot e^{j\Omega k}$。
    即：**离散 LTI 系统不会改变复指数序列的频率，只会改变它的幅度和相位！**

### 2. 幅频响应与相频响应
复变函数 $H(e^{j\Omega})$ 可以表示为极坐标形式：
$$ H(e^{j\Omega}) = |H(e^{j\Omega})| e^{j\varphi(\Omega)} $$
*   **$|H(e^{j\Omega})|$**：**幅频响应 (Magnitude Response)**。对于实系统，它是 $\Omega$ 的**偶函数**。
*   **$\varphi(\Omega)$**：**相频响应 (Phase Response)**。对于实系统，它是 $\Omega$ 的**奇函数**。

### 3. 如何由差分方程直接求出 $H(e^{j\Omega})$？（必考重点）
**【万能公式】** 假设离散 LTI 系统由以下差分方程描述：
$\sum_{i=0}^n a_i y[k-i] = \sum_{m=0}^M b_m x[k-m]$ （默认 $a_0 = 1$）
两边取 DTFT，利用时移性质（$x[k-m] \leftrightarrow e^{-j\Omega m}X$），直接得出：
$$ H(e^{j\Omega}) = \frac{Y_{zs}(e^{j\Omega})}{X(e^{j\Omega})} = \frac{\sum_{m=0}^M b_m e^{-j\Omega m}}{\sum_{i=0}^n a_i e^{-j\Omega i}} $$
*(做题秒杀技巧：看到方程里的 $y[k-n]$ 或 $x[k-m]$，直接替换成对应的 $e^{-j\Omega n}$ 即可！)*

---

## 二、 🎯 实战应用：如何用频域法求系统响应？

### 1. 输入为“非周期信号”时 (求零状态响应)
1. 求输入的谱：$X(e^{j\Omega}) = \text{DTFT}\{x[k]\}$
2. 求系统的谱：$H(e^{j\Omega})$ (通过差分方程或 $h[k]$)
3. 频域相乘：$Y_{zs}(e^{j\Omega}) = X(e^{j\Omega}) \cdot H(e^{j\Omega})$
4. 反变换回时域：$y_{zs}[k] = \text{IDTFT}\{Y_{zs}(e^{j\Omega})\}$（通常用部分分式展开法）。

### 2. 输入为“正余弦稳态信号”时 (秒杀法)
输入 $x[k] = \cos(\Omega_0 k + \theta)$，千万别去算卷积，直接利用 $H$ 的物理意义！
输出永远是同频率的余弦波，**幅度乘上幅频响应，相位加上相频响应**：
$$ y[k] = |H(e^{j\Omega_0})| \cos(\Omega_0 k + \varphi(\Omega_0) + \theta) $$

### 3. 输入为“一般周期信号”时 (结合 DFS)
输入周期信号 $\tilde{x}[k]$ 展开为 DFS 级数：$\tilde{x}[k] = \frac{1}{N}\sum_{m=0}^{N-1} \tilde{X}[m] e^{j\frac{2\pi}{N}mk}$。
利用叠加定理，输出就是让每一个谐波成分分别通过系统：
$$ \tilde{y}[k] = \frac{1}{N} \sum_{m=0}^{N-1} \tilde{X}[m] \cdot \mathbf{H\left(e^{j\frac{2\pi}{N}m}\right)} e^{j\frac{2\pi}{N}mk} $$

---

## 三、 📻 线性相位系统与理想数字滤波器

### 1. 线性相位系统 (Linear Phase System)
如果相频响应满足 **$\varphi(\Omega) = -k_0 \Omega$**，这就叫线性相位。
> **💡 物理意义**：信号通过该系统后，波形形状**不会发生任何扭曲（无相位失真）**，仅仅在时间上产生了纯粹的延迟（向右平移了 $k_0$ 个采样点）。

### 2. 四大理想数字滤波器 (Ideal Digital Filters)
理想滤波器在通带内增益为 1，阻带内增益为 0。
注意：**离散系统的频谱周期永远是 $2\pi$**，所以我们只看主值区间 $[-\pi, \pi]$。

| 滤波器类型 | 频域特性 $H(e^{j\Omega})$ (仅看 $[-\pi, \pi]$) | 时域冲激响应 $h[k]$ |
| :--- | :--- | :--- |
| **低通 (LPF)** | $|\Omega| < \Omega_c$ 时为 $1$，其余为 $0$ | **$\frac{\Omega_c}{\pi} Sa(\Omega_c k)$** |
| **高通 (HPF)** | $\Omega_c < |\Omega| \le \pi$ 时为 $1$，其余为 $0$ | $\delta[k] - \frac{\Omega_c}{\pi} Sa(\Omega_c k)$ |
| **带通 (BPF)** | $\Omega_1 < |\Omega| < \Omega_2$ 时为 $1$ | $\frac{\Omega_2}{\pi} Sa(\Omega_2 k) - \frac{\Omega_1}{\pi} Sa(\Omega_1 k)$ |
| **带阻 (BSF)** | 通带在中间被挖空 | $\delta[k] + \frac{\Omega_1}{\pi} Sa(\Omega_1 k) - \frac{\Omega_2}{\pi} Sa(\Omega_2 k)$ |

**⚠️ 必考考点：物理不可实现性！**
由于这些理想滤波器的冲激响应 $h[k]$ 都包含 $Sa(\Omega_c k)$ 函数，它在 $k < 0$ 时也是有值的。这意味着系统是**非因果**的（还没输入信号，输出就已经产生了），因此在物理上无法完美实现。

---

## 四、 🏆 压轴大题全图鉴（含 PPT 勘误！）

### 🔥 大题 1：差分方程求零状态响应 (对应 Slide 12-13)
**【题目】** 差分方程：$y[k] - 0.75y[k-1] + 0.125y[k-2] = 4x[k] + 3x[k-1]$。
输入：$x[k] = (0.75)^k u[k]$，求零状态响应 $y_{zs}[k]$。

**【保姆级拆解步骤 & ⚠️ PPT 勘误】**
1.  **求系统函数 $H(e^{j\Omega})$**：
    方程左边：$Y(1 - 0.75 e^{-j\Omega} + 0.125 e^{-j2\Omega}) = Y(1 - 0.25e^{-j\Omega})(1 - 0.5e^{-j\Omega})$
    方程右边：$X(4 + 3e^{-j\Omega})$
    $$ H(e^{j\Omega}) = \frac{4 + 3e^{-j\Omega}}{(1 - 0.25e^{-j\Omega})(1 - 0.5e^{-j\Omega})} $$
2.  **求输入信号的频谱 $X(e^{j\Omega})$**：
    利用基本变换对 $\alpha^k u[k] \leftrightarrow \frac{1}{1-\alpha e^{-j\Omega}}$：
    $$ X(e^{j\Omega}) = \frac{1}{1 - 0.75e^{-j\Omega}} $$
3.  **求输出频谱 $Y_{zs}(e^{j\Omega})$** 并进行**部分分式展开**：
    $$ Y_{zs}(e^{j\Omega}) = H \cdot X = \frac{4 + 3e^{-j\Omega}}{(1 - 0.25e^{-j\Omega})(1 - 0.5e^{-j\Omega})(1 - 0.75e^{-j\Omega})} $$
    设 $v = e^{-j\Omega}$，展开为 $\frac{A}{1-0.25v} + \frac{B}{1-0.5v} + \frac{C}{1-0.75v}$。
    *   **求 A**：令 $v = 1/0.25 = 4$，代入遮挡项：$A = \frac{4 + 3(4)}{(1 - 0.5 \times 4)(1 - 0.75 \times 4)} = \frac{16}{(-1)(-2)} = \mathbf{8}$
    *   **求 B**：令 $v = 1/0.5 = 2$，代入遮挡项：$B = \frac{4 + 3(2)}{(1 - 0.25 \times 2)(1 - 0.75 \times 2)} = \frac{10}{(0.5)(-0.5)} = \mathbf{-40}$
    *   **求 C (🚨 修正 PPT 错误)**：令 $v = 1/0.75 = 4/3$，代入遮挡项：
        $$ C = \frac{4 + 3(4/3)}{(1 - 0.25 \times \frac{4}{3})(1 - 0.5 \times \frac{4}{3})} = \frac{4 + 4}{(1 - \frac{1}{3})(1 - \frac{2}{3})} = \frac{8}{(\frac{2}{3})(\frac{1}{3})} = \frac{8}{2/9} = \mathbf{36} $$
    *(⚠️ 注意：原 PPT Slide 13 第三个系数写成了 4.5 甚至是 32，这是错的，正确答案绝对是 **36**！)*
4.  **反变换回时域**：
    $$ y_{zs}[k] = 8(0.25)^k u[k] - 40(0.5)^k u[k] + \mathbf{36}(0.75)^k u[k] $$

---

### 🔥 大题 2：理想滤波器截取周期序列 (对应 Slide 28)
这是一道极其考验基本功的神仙好题！
**【题目】** 已知理想低通滤波器 $H(e^{j\Omega}) = e^{-j3\Omega}$（当 $|\Omega| < \frac{2\pi}{16} \times 2$ 时），其余为0。
输入是周期单位冲激序列：$\tilde{x}[k] = \tilde{\delta}_{16}[k]$。求系统输出 $y[k]$。

**【极限详细解法】**
1.  **明确输入信号的 DFS**：
    周期 $N=16$ 的冲激序列 $\tilde{\delta}_{16}[k]$，根据定义，它的 DFS 系数 $\tilde{X}[m] = \mathbf{1}$ (全频带为 1)。
    这意味着输入信号包含的谐波频率为 $\Omega_m = m \frac{2\pi}{16}$，其中 $m = 0, 1, 2... 15$。

2.  **筛选能通过滤波器的谐波**：
    滤波器的通带条件是：$|\Omega| < \frac{2\pi}{16} \times \mathbf{2}$。
    这意味着只有 $|m| < 2$ 的谐波能过去。
    因此，**只有 $m=0, m=1$ 以及 $m=-1$ 能通过！**
    *(注意：在周期 $N=16$ 中，$m=-1$ 等价于 $m=15$。)*

3.  **计算通过后的各路谐波输出**：
    利用公式 $\tilde{Y}[m] = \tilde{X}[m] \cdot H(e^{j\Omega_m})$。
    *   **当 $m=0$ ($\Omega=0$)**：$\tilde{Y}[0] = 1 \cdot e^{-j3(0)} = 1$
    *   **当 $m=1$ ($\Omega = \frac{2\pi}{16}$)**：$\tilde{Y}[1] = 1 \cdot e^{-j3(\frac{2\pi}{16})}$
    *   **当 $m=15$ ($\Omega = -\frac{2\pi}{16}$)**：$\tilde{Y}[15] = 1 \cdot e^{-j3(-\frac{2\pi}{16})} = e^{j3(\frac{2\pi}{16})}$

4.  **合成时域输出 (利用 IDFS)**：
    $$ y[k] = \frac{1}{N} \sum \tilde{Y}[m] e^{j\frac{2\pi}{N}mk} = \frac{1}{16} \left( \tilde{Y}[0]e^0 + \tilde{Y}[1]e^{j\frac{2\pi}{16} \cdot 1 \cdot k} + \tilde{Y}[15]e^{j\frac{2\pi}{16} \cdot (-1) \cdot k} \right) $$
    将上面算好的项代入：
    $$ y[k] = \frac{1}{16} \left[ 1 + e^{-j\frac{6\pi}{16}}e^{j\frac{2\pi}{16}k} + e^{j\frac{6\pi}{16}}e^{-j\frac{2\pi}{16}k} \right] $$
    整理指数，合并同类项：
    $$ y[k] = \frac{1}{16} \left[ 1 + e^{j\frac{2\pi}{16}(k - 3)} + e^{-j\frac{2\pi}{16}(k - 3)} \right] $$
    看到共轭指数相加，立刻使用**欧拉公式** ($e^{j\theta} + e^{-j\theta} = 2\cos\theta$)：
    $$ y[k] = \frac{1}{16} \left[ 1 + 2\cos\left(\frac{2\pi}{16}(k - 3)\right) \right] = \mathbf{\frac{1}{16} \left\{ 1 + 2\cos\left[\frac{\pi}{8}(k - 3)\right] \right\}} $$
    *(完美解出！这里面的滤波器不仅切除掉了高频，还利用 $e^{-j3\Omega}$ 这一项造成了 $k-3$ 的时间延迟！)*

---

## 🔮 总结预告：DTFT 的致命弱点与救星
正如连续时间中的傅里叶变换存在缺陷一样，DTFT 在这里也有不可忽视的**两大缺陷**：
1.  **只能求零状态响应**，无法处理带有初始状态的系统。
2.  **不满足绝对可和条件（如发散的信号 $\alpha^k u[k]$ 当 $|\alpha|>1$ 时）时，DTFT 根本不存在！**

为了解决这个痛点，我们需要引入一个更强大、能包容不稳定信号的究极数学工具——这也就是我们下一章要学习的：**Z 变换 (Z-Transform)**！