# 学习笔记：单边 Z 变换性质（一）

> 本节对应课件 ssch7_3：线性、移位、相关、卷积、累加。复习核心是：**单边 Z 变换的移位会暴露或丢弃边界样本**，这一点和双边 Z 变换最不一样。

---

## 一、线性性质 (Linearity)

若
$$ x_1[k]u[k] \longleftrightarrow X_1(z), \quad |z|>R_1 $$
$$ x_2[k]u[k] \longleftrightarrow X_2(z), \quad |z|>R_2 $$
则
$$ ax_1[k]u[k]+bx_2[k]u[k] \longleftrightarrow aX_1(z)+bX_2(z) $$

右边序列常见 ROC：
$$ |z|>\max(R_1,R_2) $$

考试提醒：线性组合后的 ROC 至少是各 ROC 的交集；如果发生零极点抵消，ROC 可能扩大，有限长序列题尤其容易出现这种情况。

---

## 二、单边移位性质：最容易丢分的一组公式

单边 Z 变换从 $k=0$ 开始求和：
$$ X(z)=\sum_{k=0}^{\infty}x[k]z^{-k} $$
所以信号一旦平移穿过 $k=0$ 边界，就会出现额外项。

### 1. 因果右移：整体推迟

如果信号写成 $x[k-n]u[k-n]$，说明 $k<n$ 的部分本来就被阶跃截掉，直接乘 $z^{-n}$：
$$ x[k-n]u[k-n]\longleftrightarrow z^{-n}X(z) $$

这是最像双边 Z 变换的情况。

### 2. 带历史状态的右移：差分方程常用

若题目写的是 $x[k-n]u[k]$，求和范围仍从 $k=0$ 开始，历史样本 $x[-1],x[-2],\dots,x[-n]$ 会被带入：
$$ \mathscr{Z}\{x[k-n]u[k]\}
=z^{-n}X(z)+\sum_{i=1}^{n}x[-i]z^{-(n-i)} $$

最常用两条：
$$ \mathscr{Z}\{x[k-1]u[k]\}=z^{-1}X(z)+x[-1] $$
$$ \mathscr{Z}\{x[k-2]u[k]\}=z^{-2}X(z)+z^{-1}x[-1]+x[-2] $$

记忆法：延迟 $n$ 位，就会露出 $n$ 个历史状态；离现在越近的历史值，前面带的 $z^{-1}$ 次数越多。

### 3. 左移：提前导致初始样本被丢掉

若信号提前 $n$ 位：
$$ \mathscr{Z}\{x[k+n]u[k]\}
=z^n\left[X(z)-\sum_{k=0}^{n-1}x[k]z^{-k}\right] $$

最常用两条：
$$ \mathscr{Z}\{x[k+1]u[k]\}=zX(z)-zx[0] $$
$$ \mathscr{Z}\{x[k+2]u[k]\}=z^2X(z)-z^2x[0]-zx[1] $$

---

## 三、例题：有限长门函数 $u[k]-u[k-N]$

题目：求
$$ x[k]=u[k]-u[k-N] $$
的 Z 变换和 ROC。

解题步骤：

1. 已知
   $$ u[k]\longleftrightarrow \frac{1}{1-z^{-1}},\quad |z|>1 $$
2. 因果右移：
   $$ u[k-N]\longleftrightarrow \frac{z^{-N}}{1-z^{-1}} $$
3. 相减：
   $$ X(z)=\frac{1}{1-z^{-1}}-\frac{z^{-N}}{1-z^{-1}}
   =\frac{1-z^{-N}}{1-z^{-1}} $$
4. 因为
   $$ \frac{1-z^{-N}}{1-z^{-1}}=1+z^{-1}+\cdots+z^{-(N-1)} $$
   它本质是有限项多项式，不是真有 $z=1$ 极点。

最终：
$$ \boxed{X(z)=1+z^{-1}+\cdots+z^{-(N-1)},\quad \text{ROC: } |z|>0} $$

复习提醒：有限长右边序列通常只排除 $z=0$，不要被未约分前的分母 $1-z^{-1}$ 误导。

---

## 四、自相关函数的 Z 域形式

课件给出的自相关定义为
$$ R_x[n]=\sum_{k=-\infty}^{\infty}x[k]x[n+k] $$

可看成
$$ R_x[n]=x[n]*x[-n] $$
因此双边 Z 变换下有
$$ \boxed{\mathscr{Z}\{R_x[n]\}=X(z)X(z^{-1})} $$

注意：这一条本质更接近**双边 Z 变换**性质。因为 $x[-n]$ 往往是左边序列，不能机械套单边右边序列的 ROC 结论。

---

## 五、卷积性质 (Convolution)

时域卷积等于 Z 域乘法：
$$ x_1[k]u[k]*x_2[k]u[k]\longleftrightarrow X_1(z)X_2(z) $$

右边序列常见 ROC：
$$ |z|>\max(R_1,R_2) $$

### 例题：两个指数右边序列卷积

题目：
$$ x[k]=a^ku[k]*b^ku[k],\quad a\ne b $$

1. 先变到 Z 域：
   $$ X(z)=\frac{z}{z-a}\cdot\frac{z}{z-b}
   =\frac{z^2}{(z-a)(z-b)} $$
2. 为了凑标准形式，先展开 $\frac{X(z)}{z}$：
   $$ \frac{X(z)}{z}=\frac{z}{(z-a)(z-b)}
   =\frac{A}{z-a}+\frac{B}{z-b} $$
3. 掩盖法：
   $$ A=\frac{a}{a-b},\quad B=\frac{b}{b-a}=-\frac{b}{a-b} $$
4. 乘回 $z$ 并反变换：
   $$ X(z)=\frac{a}{a-b}\frac{z}{z-a}
   -\frac{b}{a-b}\frac{z}{z-b} $$

最终：
$$ \boxed{x[k]=\frac{a^{k+1}-b^{k+1}}{a-b}u[k]} $$

复习提醒：这题用时域卷积也能算，但 Z 域方法更稳，后面求零状态响应会反复用到。

---

## 六、累加性质 (Summation)

从 $0$ 累加到 $k$：
$$ s[k]=\sum_{n=0}^{k}x[n] $$

本质是与单位阶跃卷积：
$$ s[k]=x[k]*u[k] $$

所以
$$ \boxed{\mathscr{Z}\left\{\sum_{n=0}^{k}x[n]\right\}
=\frac{X(z)}{1-z^{-1}}} $$

ROC 通常为
$$ |z|>\max(R_x,1) $$

---

## 七、本节速查表

| 性质 | 时域 | Z 域 |
| :--- | :--- | :--- |
| 线性 | $ax_1[k]+bx_2[k]$ | $aX_1(z)+bX_2(z)$ |
| 因果右移 | $x[k-n]u[k-n]$ | $z^{-n}X(z)$ |
| 带历史右移 | $x[k-1]u[k]$ | $z^{-1}X(z)+x[-1]$ |
| 左移 | $x[k+1]u[k]$ | $zX(z)-zx[0]$ |
| 卷积 | $x_1[k]*x_2[k]$ | $X_1(z)X_2(z)$ |
| 累加 | $\sum_{n=0}^{k}x[n]$ | $\frac{X(z)}{1-z^{-1}}$ |
