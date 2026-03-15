# 学习笔记：单边 Z 变换的神级性质

## 一、 线性性质 (Linearity)

最基础也是最常用的性质：系统的 Z 变换满足叠加原理。
$$ ax_1[k] + bx_2[k] \longleftrightarrow aX_1(z) + bX_2(z) $$
*   **收敛域 (ROC)**：取两者的**交集**。对于右边信号，即取两个半径中**较大**的一个：$|z| > \max(R_{x1}, R_{x2})$。
*   **应用场景**：将复杂的多项式或三角函数拆解为基本指数信号的线性组合。

---

## 二、 ⚠️ 极易错考点：时域移位性质 (Time Shifting)

在**单边** Z 变换中（求和下限是 $k=0$），信号的左移和右移会导致部分数据“越过” $k=0$ 的边界，从而产生多余的初始状态项。必须严格区分以下情况：

### 1. 右移 (Delay / 延迟)
信号向右平移（变晚发生）。
*   **理想因果右移**：如果信号本身就是因果的（带有 $u[k-n]$），直接乘 $z^{-n}$ 即可。
    $$ x[k-n]u[k-n] \longleftrightarrow z^{-n}X(z) $$
*   **带初始状态的右移**：如果只是 $x[k-n]u[k]$，意味着向右平移后，原先在 $k<0$ 处的值被“拉”到了 $k \ge 0$ 的可视范围内，必须把它们单独加进来！
    $$ x[k-n]u[k] \longleftrightarrow z^{-n}X(z) + z^{-n}\sum_{k=-n}^{-1} x[k]z^{-k} $$
    > **💡 常用速记公式 (Slide 5)**：
    > 延迟 1 位：$x[k-1]u[k] \longleftrightarrow z^{-1}X(z) + x[-1]$
    > 延迟 2 位：$x[k-2]u[k] \longleftrightarrow z^{-2}X(z) + z^{-1}x[-1] + x[-2]$

### 2. 左移 (Advance / 提前)
信号向左平移（变早发生）。原先在 $k \ge 0$ 的前几个点会被“挤”到负半轴，由于是单边变换，这些点**被无情地丢弃了**，必须在频域中减去它们！
$$ x[k+n]u[k] \longleftrightarrow z^n \left[ X(z) - \sum_{k=0}^{n-1} x[k]z^{-k} \right] $$
> **💡 常用速记公式 (Slide 5)**：
> 提前 1 位：$x[k+1]u[k] \longleftrightarrow zX(z) - zx[0]$
> 提前 2 位：$x[k+2]u[k] \longleftrightarrow z^2X(z) - z^2x[0] - zx[1]$

### 📝 【秒杀例题】 (Slide 6)
**【题目】** 求门函数 $x[k] = u[k] - u[k-N]$ 的 Z 变换。
**【解法】**
1. 已知 $u[k] \longleftrightarrow \frac{1}{1-z^{-1}}$。
2. 利用理想因果右移性质：$u[k-N] \longleftrightarrow \frac{z^{-N}}{1-z^{-1}}$。
3. 两者相减：$X(z) = \frac{1}{1-z^{-1}} - \frac{z^{-N}}{1-z^{-1}} = \mathbf{\frac{1 - z^{-N}}{1 - z^{-1}}}$。
4. **ROC 判断**：由于这是一个有限长信号，它的收敛域不仅包含 $|z|>1$，实际上因为分子分母可以约分，它的 ROC 扩大为了 $\mathbf{|z| > 0}$（全平面除原点外收敛）。

---

## 三、 👑 核心灵魂：卷积性质 (Convolution Property)

与连续系统的拉氏变换一模一样：**时域卷积 = Z 域相乘**。
$$ x_1[k] * x_2[k] \longleftrightarrow X_1(z) \cdot X_2(z) $$
*   **收敛域 (ROC)**：$|z| > \max(R_{x1}, R_{x2})$。

### 📝 【压轴考点：等比序列卷积】 (Slide 9)
**【题目】** 求 $x[k] = a^k u[k] * b^k u[k]$ （其中 $a \neq b$）。
**【终极解法】**
千万不要用时域公式硬卷！转到 Z 域降维打击：
1. **求各自 Z 变换**：
   $\mathscr{Z}\{a^k u[k]\} = \frac{z}{z-a}$， $\mathscr{Z}\{b^k u[k]\} = \frac{z}{z-b}$
2. **Z 域相乘**：
   $$ X(z) = \frac{z}{z-a} \cdot \frac{z}{z-b} = \frac{z^2}{(z-a)(z-b)} $$
3. **部分分式展开（逆 Z 变换标准套路）**：
   *(注意：逆 Z 变换时，一定要先求 $\frac{X(z)}{z}$，最后再把 $z$ 乘回去，这样才能凑出标准公式！)*
   $$ \frac{X(z)}{z} = \frac{z}{(z-a)(z-b)} = \frac{A}{z-a} + \frac{B}{z-b} $$
   利用掩盖法求留数：$A = \frac{a}{a-b}$， $B = \frac{b}{b-a} = \frac{-b}{a-b}$。
   再把 $z$ 乘回去：$$ X(z) = \frac{a}{a-b}\frac{z}{z-a} - \frac{b}{a-b}\frac{z}{z-b} $$
4. **反变换回时域**：
   $$ x[k] = \frac{a}{a-b} a^k u[k] - \frac{b}{a-b} b^k u[k] = \mathbf{\frac{1}{a-b}(a^{k+1} - b^{k+1})u[k]} $$
*(这道题是离散系统求响应最经典的一道代数题，务必亲手算一遍！)*

---

## 四、 ➕ 累加性质 (Summation Property)

在连续系统中，积分对应除以 $s$；在离散系统中，**累加**对应乘以 $\frac{1}{1-z^{-1}}$（或者 $\frac{z}{z-1}$）。
$$ \sum_{n=0}^{k} x[n] \longleftrightarrow \frac{1}{1 - z^{-1}} X(z) = \mathbf{\frac{z}{z-1} X(z)} $$
*   **收敛域 (ROC)**：$|z| > \max(R_x, 1)$。

> **💡 物理直觉与推导 (Slide 10)**：
> 为什么累加是乘 $\frac{1}{1-z^{-1}}$？
> 因为**“对信号进行累加”本质上就是“让信号与单位阶跃序列 $u[k]$ 做卷积”**！
> 即：$\sum_{n=0}^{k} x[n] = x[k] * u[k]$。
> 根据卷积定理：$X(z) \cdot \mathscr{Z}\{u[k]\} = X(z) \cdot \frac{1}{1-z^{-1}}$，一切都完美闭环了！

---

## 五、 🔄 拓展特性：自相关函数 (Autocorrelation)

课件在 Slide 7 顺带提到了自相关函数的双边 Z 变换特性：
$$ R_x[n] = \sum_{k=-\infty}^{+\infty} x[k]x[n+k] \longleftrightarrow \mathbf{X(z)X(z^{-1})} $$
*(注：如果原信号是因果的，其翻转信号 $x[-n]$ 就是反因果的，Z 变换中对应将 $z$ 替换为 $z^{-1}$。因此自相关等效于 $x[n] * x[-n] \leftrightarrow X(z)X(z^{-1})$)*。

---
**🎯 总结建议**：
在期末考试中，Z 变换的**单边移位性质**（处理含初始状态的差分方程）和**卷积性质**（求零状态响应）是绝对的重灾区。请务必牢记：**左移丢状态（减去初值），右移补状态（加上历史）！**