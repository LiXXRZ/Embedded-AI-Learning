# 学习笔记：连续时间系统的复频域分析 (Laplace Transform)

## 零、 核心动机：为什么有了傅里叶，还要拉普拉斯？
傅里叶变换（FT）虽然好用，但有两个致命缺陷：
1. **只能求零状态响应**：它无法处理电容、电感带有初始状态（储能）的情况。
2. **要求信号绝对可积**：像 $e^{2t}u(t)$ 这种指数发散信号，或者 $u(t)$ 这种不绝对可积的信号，傅里叶变换要么不存在，要么包含冲激函数，极难处理。

**【拉普拉斯的救赎】**：
在傅里叶变换的 $e^{-j\omega t}$ 基础上，强行乘上一个**衰减因子 $e^{-\sigma t}$**。
把它俩合并，定义**复频率 $s = \sigma + j\omega$**。
$$ \mathscr{F}[x(t)e^{-\sigma t}] = \int_{-\infty}^{\infty} x(t)e^{-(\sigma + j\omega)t} dt = \int_{-\infty}^{\infty} x(t)e^{-st} dt = X(s) $$
*只要 $\sigma$ 取足够大，再野的信号也能被压制到收敛！这就引出了拉氏变换。*

---

## 一、 👑 绝对核心：单边拉普拉斯变换与收敛域 (ROC)

由于工程中大多数信号在 $t<0$ 时为 0（因果信号），我们最常用的是**单边拉普拉斯变换**。

### 1. 定义式
*   **正变换**：$X(s) = \mathscr{L}[x(t)] = \int_{0^-}^{\infty} x(t)e^{-st} dt$
    *(注意下限是 $0^-$，这使得它能完美包容 $t=0$ 时刻发生的冲激 $\delta(t)$)*
*   **反变换**：$x(t) = \frac{1}{2\pi j} \int_{\sigma-j\infty}^{\sigma+j\infty} X(s)e^{st} ds$

### 2. 收敛域 ROC (Region of Convergence)
拉普拉斯变换存在的充要条件是积分收敛。使得积分收敛的 $\sigma$（即 $Re(s)$，实部）的取值范围，称为**收敛域 (ROC)**。
*   **单边因果信号**（右边信号）：ROC 永远是一条垂直线**向右**的半平面（例如 $Re(s) > \sigma_0$）。

---

## 二、 🍎 必背：常见信号的拉氏变换对大全

就像背乘法口诀一样，以下变换对及其收敛域必须形成肌肉记忆：

| 时域信号 $x(t)$ | 复频域 $X(s)$ | 收敛域 (ROC) |
| :--- | :--- | :--- |
| **单位冲激 $\delta(t)$** | $\mathbf{1}$ | 全 $s$ 平面 |
| **单位阶跃 $u(t)$** | $\mathbf{\frac{1}{s}}$ | $Re(s) > 0$ |
| **单边指数 $e^{\lambda t}u(t)$** | $\mathbf{\frac{1}{s - \lambda}}$ | $Re(s) > Re(\lambda)$ |
| **余弦波 $\cos(\omega_0 t)u(t)$** | $\mathbf{\frac{s}{s^2 + \omega_0^2}}$ | $Re(s) > 0$ |
| **正弦波 $\sin(\omega_0 t)u(t)$** | $\mathbf{\frac{\omega_0}{s^2 + \omega_0^2}}$ | $Re(s) > 0$ |
| **斜坡信号 $t \cdot u(t)$** | $\mathbf{\frac{1}{s^2}}$ | $Re(s) > 0$ |
| **高阶指数衰减 $\frac{t^n}{n!}e^{\lambda t}u(t)$** | $\mathbf{\frac{1}{(s - \lambda)^{n+1}}}$ | $Re(s) > Re(\lambda)$ |

---

## 三、 🛠️ 单边拉氏变换的十大神级性质

### 1. 线性性质
$ax_1(t) + bx_2(t) \longleftrightarrow aX_1(s) + bX_2(s)$, ROC 取两者的**交集**。

### 2. 延时性质 (Time Shifting)
$$ x(t - t_0)u(t - t_0) \longleftrightarrow e^{-st_0}X(s) \quad (t_0 > 0) $$

### 3. 复频域平移 (指数加权 / S域平移)
**这是解题最常用的性质！** 时域乘上指数，S域发生平移。
$$ e^{\lambda t}x(t) \longleftrightarrow X(s - \lambda) $$
*(例：已知 $\cos(\omega_0 t) \leftrightarrow \frac{s}{s^2+\omega_0^2}$，则 $e^{-\alpha t}\cos(\omega_0 t) \leftrightarrow \frac{s+\alpha}{(s+\alpha)^2+\omega_0^2}$)*

### 4. 尺度变换
$$ x(at) \longleftrightarrow \frac{1}{a} X\left(\frac{s}{a}\right) \quad (a > 0) $$

### 5. 卷积定理 (时域卷积 = S域相乘)
$$ x_1(t) * x_2(t) \longleftrightarrow X_1(s) \cdot X_2(s) $$

### 6. S域求导 (时域乘 $t$)
$$ t \cdot x(t) \longleftrightarrow -\frac{d}{ds}X(s) $$

### 7. 🔥 时域微分性质 (求解微分方程、初始状态的核心！)
$$ \frac{dx(t)}{dt} \longleftrightarrow sX(s) - \mathbf{x(0^-)} $$
$$ \frac{d^2x(t)}{dt^2} \longleftrightarrow s^2X(s) - \mathbf{s \cdot x(0^-)} - \mathbf{x'(0^-)} $$
> **💡 电路分析神技 (Slide 42)**：
> *   **电感等效**：$v_L(t) = L\frac{di_L}{dt} \implies V_L(s) = sL \cdot I_L(s) - L \cdot i_L(0^-)$。相当于一个阻抗为 $sL$ 的电感，串联一个代表初始储能的电压源。

### 8. 时域积分性质
$$ \int_{-\infty}^t x(\tau)d\tau \longleftrightarrow \frac{X(s)}{s} + \frac{\int_{-\infty}^{0^-} x(\tau)d\tau}{s} $$
> **💡 电路分析神技 (Slide 45)**：
> *   **电容等效**：$v_C(t) = \frac{1}{C}\int i_C dt \implies V_C(s) = \frac{1}{sC} I_C(s) + \frac{v_C(0^-)}{s}$。相当于一个阻抗为 $\frac{1}{sC}$ 的电容，串联一个代表初始电压的电压源。

### 9. 💥 初值定理与终值定理 (极易出错的考点)
*   **初值定理**：$x(0^+) = \lim_{s \to \infty} sX(s)$
    *(避坑：如果 $X(s)$ 是假分式，即分子阶数 $\ge$ 分母阶数，说明时域在 $t=0$ 有冲激 $\delta(t)$，此时初值定理失效，必须先用长除法分离出多项式！)*
*   **终值定理**：$\lim_{t \to \infty} x(t) = \lim_{s \to 0} sX(s)$
    *(避坑：必须保证 $sX(s)$ 的所有极点都严格位于 S 平面的**左半平面**（即系统稳定），终值定理才可以使用！)*

---

## 四、 🔙 拉氏逆变换：部分分式展开法 (PFE)
由于直接用复变函数积分求逆变换极度反人类，我们通常采用**部分分式展开法 (Partial Fraction Expansion)**。

### 操作步骤：
1.  **判断真假分式**：如果 $X(s)$ 分子阶数 $m \ge$ 分母阶数 $n$，必须先做多项式长除法，化为：多项式 + 真分式。
    *(多项式部分直接反变换为冲激 $\delta(t)$ 及其各阶导数)*。
2.  **真分式求极点**：将分母因式分解为 $(s-p_1)(s-p_2)\dots$
3.  **求留数 (待定系数)**：
    *   **单极点情况**：$X(s) = \frac{k_1}{s-p_1} + \frac{k_2}{s-p_2}$
        **留数定理 (掩盖法)**：$k_1 = \left. (s-p_1)X(s) \right|_{s=p_1}$。
        反变换结果：$x(t) = (k_1 e^{p_1 t} + k_2 e^{p_2 t}) u(t)$。
    *   **重极点情况**：例如 $(s-p_1)^r$。
        展开为 $\frac{k_1}{(s-p_1)^r} + \frac{k_2}{(s-p_1)^{r-1}} + \dots + \frac{k_r}{(s-p_1)}$
        最高次项 $k_1$ 仍可用掩盖法直接求；其他低次项需用**求导法**或同分母对比法求得。
        反变换需用到公式：$\frac{1}{(s-p)^m} \leftrightarrow \frac{t^{m-1}}{(m-1)!}e^{pt}u(t)$。

---

## 五、 👑 终极压轴大题：双边拉氏变换与 ROC 匹配 (Slide 73)

这是整门课**最精华、最容易被考成压轴题**的部分。
因为积分下限变成了 $-\infty$，所以对于同一个 $X(s)$，**收敛域 (ROC) 的选择不同，反变换得到的波形完全不同！**

**【黄金法则】**
*   极点在 ROC 的 **左侧** $\implies$ 反变换为**右边信号**（形式为 $+ e^{pt}u(t)$）
*   极点在 ROC 的 **右侧** $\implies$ 反变换为**左边信号**（形式为 $- e^{pt}u(-t)$）

**【压轴神题实战】**
已知 $X(s) = \frac{2s+1}{(s+2)(s+3)}$。试根据不同的 ROC，求出其对应的时域信号 $x(t)$。

**第一步：部分分式展开**
$$ X(s) = \frac{k_1}{s+2} + \frac{k_2}{s+3} $$
掩盖法求系数：
$k_1 = \left. \frac{2s+1}{s+3} \right|_{s=-2} = \frac{-3}{1} = -3$
$k_2 = \left. \frac{2s+1}{s+2} \right|_{s=-3} = \frac{-5}{-1} = 5$
所以：$X(s) = \frac{-3}{s+2} + \frac{5}{s+3}$。极点在 $p_1 = -2$, $p_2 = -3$。

**第二步：根据三种 ROC 情况分类讨论**

*   **情况 1：$Re(s) > -2$**
    此时 ROC 在所有极点 ($-2, -3$) 的**右侧**。
    说明两个分式代表的都是**因果的右边信号**。
    $$ x(t) = \mathbf{-3e^{-2t}u(t) + 5e^{-3t}u(t)} $$

*   **情况 2：$-3 < Re(s) < -2$**
    此时 ROC 被夹在中间。
    对于极点 $p_1 = -2$，ROC 在它的**左侧** $\implies$ 它对应的是**左边信号**。
    对于极点 $p_2 = -3$，ROC 在它的**右侧** $\implies$ 它对应的是**右边信号**。
    *(注意左边信号的反变换要加一个负号！)*
    $$ x(t) = -3 \cdot [\mathbf{-e^{-2t}u(-t)}] + 5 \cdot[\mathbf{e^{-3t}u(t)}] = \mathbf{3e^{-2t}u(-t) + 5e^{-3t}u(t)} $$

*   **情况 3：$Re(s) < -3$**
    此时 ROC 在所有极点 ($-2, -3$) 的**左侧**。
    说明两个分式代表的都是**反因果的左边信号**。
    *(全部都要加负号！)*
    $$ x(t) = -3 \cdot [\mathbf{-e^{-2t}u(-t)}] + 5 \cdot [\mathbf{-e^{-3t}u(-t)}] = \mathbf{3e^{-2t}u(-t) - 5e^{-3t}u(-t)} $$

> **🔥 核心感悟**：拉普拉斯变换比傅里叶变换强大的根本原因，就在于**ROC 的存在**！傅里叶变换只能处理收敛域包含虚轴（$Re(s)=0$）的情况，而拉普拉斯变换通过移动 S 平面上的收敛域，完美地将发散的左边、右边和双边信号全部统一到了代数域中！