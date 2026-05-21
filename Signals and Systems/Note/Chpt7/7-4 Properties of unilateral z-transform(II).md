# 学习笔记：单边 Z 变换性质（二）

> 本节对应课件 ssch7_4：指数加权、Z 域微分、时间反转、初值定理与终值定理。和 7-3 相比，这一节更偏“快速变形”和“由 $X(z)$ 直接读信息”。

---

## 一、指数加权性质：时域乘 $a^k$，Z 域缩放

若
$$ x[k]u[k]\longleftrightarrow X(z),\quad |z|>R_x $$
则
$$ \boxed{a^kx[k]u[k]\longleftrightarrow X\left(\frac{z}{a}\right)} $$

ROC 随半径一起缩放：
$$ \boxed{|z|>|a|R_x} $$

直觉：原式中每一项是 $x[k]z^{-k}$，乘上 $a^k$ 后变成 $x[k](z/a)^{-k}$，所以就是把 $z$ 换成 $z/a$。

### 例题：衰减余弦信号

已知
$$ \cos(\Omega_0k)u[k]\longleftrightarrow
\frac{1-z^{-1}\cos\Omega_0}{1-2z^{-1}\cos\Omega_0+z^{-2}},
\quad |z|>1 $$

求
$$ \alpha^k\cos(\Omega_0k)u[k] $$

直接把 $z$ 换成 $z/\alpha$，也就是把 $z^{-1}$ 换成 $\alpha z^{-1}$：
$$ \boxed{
X(z)=
\frac{1-\alpha z^{-1}\cos\Omega_0}
{1-2\alpha z^{-1}\cos\Omega_0+\alpha^2z^{-2}},
\quad |z|>|\alpha|
} $$

复习提醒：这题不要重新用欧拉公式推一遍，指数加权就是为它准备的。

---

## 二、Z 域微分性质：时域乘 $k$

若
$$ x[k]u[k]\longleftrightarrow X(z) $$
则
$$ \boxed{kx[k]u[k]\longleftrightarrow -z\frac{dX(z)}{dz}} $$

推导只需对定义式求导：
$$ X(z)=\sum_{k=0}^{\infty}x[k]z^{-k} $$
$$ \frac{dX(z)}{dz}=\sum_{k=0}^{\infty}(-k)x[k]z^{-k-1} $$
两边乘 $-z$，就得到
$$ -z\frac{dX(z)}{dz}=\sum_{k=0}^{\infty}kx[k]z^{-k} $$

### 例题：求 $ka^ku[k]$ 的 Z 变换

已知
$$ a^ku[k]\longleftrightarrow \frac{z}{z-a},\quad |z|>|a| $$

所以
$$ \mathscr{Z}\{ka^ku[k]\}
=-z\frac{d}{dz}\left(\frac{z}{z-a}\right) $$

计算导数：
$$ \frac{d}{dz}\left(\frac{z}{z-a}\right)
=\frac{(z-a)-z}{(z-a)^2}
=-\frac{a}{(z-a)^2} $$

于是
$$ \boxed{\mathscr{Z}\{ka^ku[k]\}=\frac{az}{(z-a)^2}
=\frac{az^{-1}}{(1-az^{-1})^2},\quad |z|>|a|} $$

---

## 三、时间反转性质

双边 Z 变换中，时间反转最自然：
$$ x[-k]\longleftrightarrow X(z^{-1}) $$

若原 ROC 为
$$ R_-<|z|<R_+ $$
则反转后 ROC 为
$$ \boxed{\frac{1}{R_+}<|z|<\frac{1}{R_-}} $$

复习提醒：课件把它放在“单边 Z 变换性质”中，但实际做题时要先判断信号是否变成左边序列。因果右边序列反转后通常不是单边右边序列，不能机械套 $u[k]$ 的表。

---

## 四、初值定理 (Initial Value Theorem)

对于因果序列
$$ X(z)=x[0]+x[1]z^{-1}+x[2]z^{-2}+\cdots $$

令 $z\to\infty$，后面的负幂项全部消失：
$$ \boxed{x[0]=\lim_{z\to\infty}X(z)} $$

如果还要读 $x[1]$，可以先减掉 $x[0]$：
$$ \boxed{x[1]=\lim_{z\to\infty}z\bigl[X(z)-x[0]\bigr]} $$

更一般地，可以把 $X(z)$ 展成 $z^{-1}$ 幂级数，系数就是 $x[0],x[1],x[2],\dots$。

---

## 五、终值定理 (Final Value Theorem)

如果序列最终收敛，则
$$ \boxed{x[\infty]=\lim_{z\to1}(1-z^{-1})X(z)} $$

因为 $z\to1$ 时 $z$ 本身趋近 1，也常写作
$$ \boxed{x[\infty]=\lim_{z\to1}(z-1)X(z)} $$

### 使用前必须检查的条件

终值定理不能无脑套。必须保证 $(1-z^{-1})X(z)$ 的 ROC 包含单位圆；对常见因果有理序列，等价说法是：

* 除了可能被 $(1-z^{-1})$ 抵消的 $z=1$ 极点以外；
* 其余极点都必须严格在单位圆内。

如果有极点在单位圆上造成振荡，或者在单位圆外造成发散，终值不存在。

### 例题：$X(z)=\frac{1}{1-az^{-1}}$

已知
$$ X(z)=\frac{1}{1-az^{-1}},\quad |z|>|a| $$
对应
$$ x[k]=a^ku[k] $$

初值：
$$ x[0]=\lim_{z\to\infty}\frac{1}{1-az^{-1}}=1 $$

第二个样本：
$$ x[1]=\lim_{z\to\infty}z\left(\frac{1}{1-az^{-1}}-1\right)=a $$

终值：
$$ x[\infty]=\lim_{z\to1}(1-z^{-1})\frac{1}{1-az^{-1}} $$

只有当 $|a|<1$ 时，序列才收敛，此时
$$ \boxed{x[\infty]=0} $$

若 $a=1$，序列是 $u[k]$，终值为 1；若 $|a|>1$ 或 $a=-1$，不能直接套“趋于 0”的结论。

---

## 六、本节速查表

| 性质 | 时域 | Z 域 / 结论 |
| :--- | :--- | :--- |
| 指数加权 | $a^kx[k]u[k]$ | $X(z/a)$ |
| Z 域微分 | $kx[k]u[k]$ | $-z\dfrac{dX(z)}{dz}$ |
| 时间反转 | $x[-k]$ | $X(z^{-1})$ |
| 初值定理 | $x[0]$ | $\lim_{z\to\infty}X(z)$ |
| 终值定理 | $x[\infty]$ | $\lim_{z\to1}(1-z^{-1})X(z)$ |

