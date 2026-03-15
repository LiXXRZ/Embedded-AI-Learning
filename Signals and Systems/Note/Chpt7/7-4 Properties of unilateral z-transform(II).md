# 学习笔记：单边 Z 变换的神级性质

## 一、 线性性质 (Linearity)
最基础的性质：信号的时域线性组合，等于频域的线性组合。
$$ ax_1[k] + bx_2[k] \longleftrightarrow aX_1(z) + bX_2(z) $$
*   **收敛域 (ROC)**：取两者的**交集**，即 $|z| > \max(R_{x1}, R_{x2})$。

---

## 二、 ⚠️ 极易错考点：时域移位性质 (Time Shifting)
在**单边** Z 变换中（求和从 $k=0$ 开始），信号的左移和右移会导致部分数据“越过” $k=0$ 的边界。必须严格区分以下情况：

### 1. 右移 (Delay / 延迟)
信号向右平移（变晚发生）。
*   **理想因果右移**：如果信号本身就是因果的（带有 $u[k-n]$，即原本 $k<n$ 时全为0），直接乘 $z^{-n}$ 即可。
    $$ x[k-n]u[k-n] \longleftrightarrow z^{-n}X(z) $$
*   **【考研/期末必考】带初始状态的右移**：如果只是 $x[k-n]u[k]$，意味着向右平移后，原先在负半轴 ($k<0$) 的值被“拉”到了 $k \ge 0$ 的可视范围内，**必须把它们单独加进来！**
    $$ \mathscr{Z}\{x[k-n]u[k]\} = z^{-n}\left[ X(z) + \sum_{k=-n}^{-1} x[k]z^{-k} \right] $$
    > **💡 常用速记公式**：
    > 延迟 1 位：$x[k-1]u[k] \longleftrightarrow z^{-1}X(z) + x[-1]$
    > 延迟 2 位：$x[k-2]u[k] \longleftrightarrow z^{-2}X(z) + z^{-1}x[-1] + x[-2]$
    > *(提示：解带有初始状态的差分方程时，全靠这个公式！)*

### 2. 左移 (Advance / 提前)
信号向左平移（变早发生）。原先在 $k \ge 0$ 的前几个点会被“挤”到负半轴，由于是单边变换，**这些点被无情地丢弃了**，必须在频域中减去它们！
$$ \mathscr{Z}\{x[k+n]u[k]\} = z^n \left[ X(z) - \sum_{k=0}^{n-1} x[k]z^{-k} \right] $$
> **💡 常用速记公式**：
> 提前 1 位：$x[k+1]u[k] \longleftrightarrow zX(z) - zx[0]$
> 提前 2 位：$x[k+2]u[k] \longleftrightarrow z^2X(z) - z^2x[0] - zx[1]$

### 📝 【秒杀例题】 (Slide 6)
**【题目】** 求有限长脉冲 $x[k] = u[k] - u[k-N]$ 的 Z 变换及 ROC。
**【解法】**
1. 已知 $u[k] \longleftrightarrow \frac{1}{1-z^{-1}}$。
2. 利用因果右移性质：$u[k-N] \longleftrightarrow z^{-N} \cdot \frac{1}{1-z^{-1}}$。
3. 两者相减：$X(z) = \frac{1}{1-z^{-1}} - \frac{z^{-N}}{1-z^{-1}} = \mathbf{\frac{1 - z^{-N}}{1 - z^{-1}}}$。
4. **ROC 陷阱**：虽然看起来有分母 $1-z^{-1}$，但因为这是一个有限长信号，极点 $z=1$ 会被分子的零点抵消！因此它的 ROC 扩大为了 $\mathbf{|z| > 0}$。

---

## 三、 🌟 指数加权性质 (Z 域尺度变换 / Scaling)
如果在时域信号上乘上一个指数序列 $a^k$，相当于在 Z 域将变量 $z$ 除以 $a$。
$$ a^k x[k]u[k] \longleftrightarrow X\left(\frac{z}{a}\right) $$
*   **ROC 变化**：边界也会跟着缩放，变为 $\mathbf{|z| > |a|R_x}$。
*   **【超强应用】 (Slide 4)**：
    我们背过 $\cos(\Omega_0 k)u[k] \longleftrightarrow \frac{1 - z^{-1}\cos\Omega_0}{1 - 2z^{-1}\cos\Omega_0 + z^{-2}}$。
    如果要求**衰减余弦信号** $a^k \cos(\Omega_0 k)u[k]$ 的 Z 变换，不需要重新推导，直接把上式所有的 $z$ 换成 $z/a$（即 $z^{-1}$ 换成 $a z^{-1}$）即可：
    $$ \mathbf{X(z) = \frac{1 - a z^{-1}\cos\Omega_0}{1 - 2a z^{-1}\cos\Omega_0 + a^2 z^{-2}}} \quad (|z| > |a|) $$

---

## 四、 🌟 Z 域微分性质 (时域乘 $k$)
如果在时域信号上乘上变量 $k$，在 Z 域等效于求导并乘以 $-z$。
$$ k \cdot x[k]u[k] \longleftrightarrow -z \frac{d X(z)}{dz} $$
*   **【经典例题】 (Slide 6)**：
    已知 $a^k u[k] \longleftrightarrow \frac{1}{1-az^{-1}} = \frac{z}{z-a}$。
    求 $k a^k u[k]$ 的 Z 变换。
    解：$-z \frac{d}{dz} \left(\frac{z}{z-a}\right) = -z \left[ \frac{1(z-a) - z(1)}{(z-a)^2} \right] = -z \left[ \frac{-a}{(z-a)^2} \right] = \mathbf{\frac{az}{(z-a)^2}}$ 
    *(化为负幂次就是 $\frac{a z^{-1}}{(1 - az^{-1})^2}$)*。

---

## 五、 👑 卷积性质 (Convolution Property)
与连续系统的拉氏变换一模一样：**时域卷积 = Z 域相乘**。
$$ x_1[k] * x_2[k] \longleftrightarrow X_1(z) \cdot X_2(z) $$

### 📝 【压轴考点：等比序列卷积】 (Slide 9)
**【题目】** 求 $x[k] = a^k u[k] * b^k u[k]$ （其中 $a \neq b$）。
**【终极解法】** 千万不要用时域公式硬卷！转到 Z 域降维打击：
1. **求各自 Z 变换**：
   $\mathscr{Z}\{a^k u[k]\} = \frac{z}{z-a}$， $\mathscr{Z}\{b^k u[k]\} = \frac{z}{z-b}$
2. **Z 域相乘**：
   $X(z) = \frac{z}{z-a} \cdot \frac{z}{z-b} = \frac{z^2}{(z-a)(z-b)}$
3. **部分分式展开（逆 Z 变换标准套路）**：
   *(注意：必须先求 $\frac{X(z)}{z}$，最后再把 $z$ 乘回去，这样才能凑出 $\frac{z}{z-a}$ 的标准形式！)*
   $$ \frac{X(z)}{z} = \frac{z}{(z-a)(z-b)} = \frac{A}{z-a} + \frac{B}{z-b} $$
   掩盖法求留数：$A = \frac{a}{a-b}$， $B = \frac{b}{b-a} = \frac{-b}{a-b}$。
   把 $z$ 乘回去：$X(z) = \frac{a}{a-b}\frac{z}{z-a} - \frac{b}{a-b}\frac{z}{z-b}$
4. **反变换回时域**：
   $$ x[k] = \frac{a}{a-b} a^k u[k] - \frac{b}{a-b} b^k u[k] = \mathbf{\frac{1}{a-b}(a^{k+1} - b^{k+1})u[k]} $$

---

## 六、 ➕ 累加性质 (Summation Property)
在连续系统中，积分对应除以 $s$；在离散系统中，**从 $0$ 累加到 $k$** 对应乘以 $\frac{1}{1-z^{-1}}$（或者写成 $\frac{z}{z-1}$）。
$$ \sum_{n=0}^{k} x[n] \longleftrightarrow \frac{1}{1 - z^{-1}} X(z) = \mathbf{\frac{z}{z-1} X(z)} $$
> **💡 物理直觉推导**：
> 为什么是乘 $\frac{1}{1-z^{-1}}$？因为**“对信号进行累加”本质上就是“让信号与单位阶跃序列 $u[k]$ 做卷积”**！
> $\sum_{n=0}^{k} x[n] = x[k] * u[k]$。根据卷积定理，就是 $X(z)$ 乘以 $\mathscr{Z}\{u[k]\}$，完美闭环！

---

## 七、 🕰️ 初值定理与终值定理 (Initial & Final Value)

在不知道时域表达式的情况下，直接通过 $X(z)$ 求时域的起点和终点值。

### 1. 初值定理 (Initial Value Theorem)
对于因果序列（$k<0$ 时为 0）：
$$ \mathbf{x[0] = \lim_{z \to \infty} X(z)} $$
*(证明极其直观：$X(z) = x[0] + x[1]z^{-1} + x[2]z^{-2} + \dots$。当 $z \to \infty$ 时，后面所有带 $z^{-k}$ 的项全部趋于 0，只剩下干干净净的 $x[0]$！)*

### 2. 终值定理 (Final Value Theorem)
求信号经过无限长的时间后稳定在什么值：
$$ \mathbf{x[+\infty] = \lim_{z \to 1} (z-1)X(z)} $$
**🚨 绝对致命的限制条件**：
使用终值定理前，**必须确保 $(z-1)X(z)$ 的所有极点都严格位于单位圆内部（即 $|z| < 1$）**！如果极点在单位圆外或虚轴上（比如正弦震荡信号），信号根本不收敛，终值不存在，强行套公式会得到荒谬的错误答案！