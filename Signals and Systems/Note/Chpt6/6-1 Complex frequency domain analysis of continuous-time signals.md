# 连续时间信号与系统的复频域分析 详细笔记

## 一、 为什么要引入复频域分析？
在使用传统的时域和频域分析时，会遇到以下局限性：
1. **时域分析**：需要分别求解齐次解（零输入响应）和特解（零状态响应）$x(t)*h(t)$，过程繁琐。
2. **频域分析 (傅里叶变换)**：
   * 只能求解**零状态响应**。
   * 要求输入信号必须是**绝对可积**的（例如 $e^{2t}u(t)$ 傅里叶变换不存在）。
   * 只能分析**稳定系统**的系统频率响应 $H(j\omega)$。

**结论**：复频域（拉普拉斯变换）分析能有效解决上述问题，将系统分析扩展到不稳定系统及更广泛的信号，并能同时求解全响应。

---

## 二、 连续时间信号的拉普拉斯变换
### 1. 从傅里叶变换到拉普拉斯变换
定义复频率 $s = \sigma + j\omega$。
对于某些不满足绝对可积条件的信号（例如 $x(t) = e^{at}u(t), a>0$），其傅里叶变换不存在。为了使其收敛，乘以一个衰减因子 $e^{-\sigma t}$，然后再进行傅里叶变换：
$$ \mathscr{F}\{x(t)e^{-\sigma t}\} = \int_{-\infty}^{\infty} x(t)e^{-\sigma t}e^{-j\omega t}dt = \int_{-\infty}^{\infty} x(t)e^{-(\sigma+j\omega)t}dt = \int_{-\infty}^{\infty} x(t)e^{-st}dt $$
**物理意义**：信号 $x(t)$ 的拉普拉斯变换，本质上是信号 $x(t)e^{-\sigma t}$ 的傅里叶变换。

> **【例题推导】求 $x(t) = e^{at}u(t), a>0$ 的拉普拉斯变换**
> 它的傅里叶变换不存在。乘以衰减因子 $e^{-\sigma t}$ 后：
> $$ \mathscr{F}\{e^{at}u(t)e^{-\sigma t}\} = \int_{0}^{\infty} e^{at}e^{-st}dt = \int_{0}^{\infty} e^{-(s-a)t}dt = \left. \frac{-1}{s-a} e^{-(s-a)t} \right|_0^\infty $$
> 当且仅当 $\sigma > a$（即 $Re(s) > a$）时，积分上限处 $e^{-(s-a)\infty} \to 0$，积分收敛，结果为 $\frac{1}{s-a}$。

### 2. 单边拉普拉斯变换的定义
为了方便描述因果系统和全响应，工程上常用**单边拉普拉斯变换**（积分下限从 $0^-$ 开始，包含了 $t=0$ 处的冲激特性）：
*   **正变换**： $X(s) = \int_{0^-}^{\infty} x(t)e^{-st}dt$ ，记为 $x(t) \stackrel{\mathscr{L}}{\longleftrightarrow} X(s)$
*   **逆变换**： $x(t) = \frac{1}{2\pi j} \int_{\sigma-j\infty}^{\sigma+j\infty} X(s)e^{st}ds$ ，记为 $x(t) = \mathscr{L}^{-1}[X(s)]$

### 3. 单边拉普拉斯变换的收敛域 (ROC)
存在条件（充要条件）：积分 $\int_{0^-}^{\infty} |x(t)e^{-\sigma t}|dt = C < \infty$ 必须收敛。
使得该公式成立的 $\sigma$ 的取值范围称为**收敛域 (Region Of Convergence, ROC)**，通常表示为 $Re(s) > \sigma_0$（在复平面上表现为一条垂直线 $\sigma=\sigma_0$ 右侧的右半平面）。

> **【例题】求信号 $x(t) = u(t) - u(t-\tau)$ 的单边拉普拉斯变换及收敛域。**
> **【解析】**：
> $$ X(s) = \int_{0^-}^{\infty} [u(t)-u(t-\tau)]e^{-st}dt = \int_{0^-}^{\tau} e^{-st}dt = \left. -\frac{1}{s}e^{-st} \right|_{0^-}^{\tau} = \frac{1}{s}(1 - e^{-s\tau}) $$
> 收敛域：由于是有限长时间内的积分，对任何 $s$ 都收敛，即全s平面，$Re(s) > -\infty$。

> **【例题】求信号 $e^{2t}u(t)$ 的单边拉普拉斯变换及收敛域。**
> **【解析】**：
> $$ X(s) = \int_{0^-}^{\infty} e^{2t}u(t)e^{-st}dt = \left. \frac{1}{2-s}e^{(2-s)t} \right|_{0^-}^\infty $$
> 只有当 $Re(s) > 2$ 时，$e^{(2-s)\infty} \to 0$。因此 $X(s) = \frac{1}{s-2}$，ROC: $Re(s) > 2$。

---

## 三、 常见信号的单边拉普拉斯变换
1. **冲激信号**： $\delta(t) \leftrightarrow 1 \quad (Re(s) > -\infty)$
   同理，n阶导数： $\delta^{(n)}(t) \leftrightarrow s^n \quad (Re(s) > -\infty)$
2. **阶跃信号**： $u(t) \leftrightarrow \frac{1}{s} \quad (Re(s) > 0)$
3. **指数信号**： $e^{\lambda t}u(t) \leftrightarrow \frac{1}{s-\lambda} \quad (Re(s) > Re(\lambda))$
   * 若 $\lambda = \alpha$ (实数)：$e^{\alpha t}u(t) \leftrightarrow \frac{1}{s-\alpha}$
   * 若 $\lambda = j\omega_0$ (虚指数)：$e^{j\omega_0 t}u(t) \leftrightarrow \frac{1}{s-j\omega_0}$
   * 若 $\lambda = \alpha+j\omega_0$ (复指数)：$e^{(\alpha+j\omega_0)t}u(t) \leftrightarrow \frac{1}{s-(\alpha+j\omega_0)}$
4. **正弦/余弦信号**（由欧拉公式展开）：
   * $\cos(\omega_0 t)u(t) = \frac{e^{j\omega_0 t} + e^{-j\omega_0 t}}{2}u(t) \leftrightarrow \frac{s}{s^2+\omega_0^2} \quad (Re(s)>0)$
   * $\sin(\omega_0 t)u(t) = \frac{e^{j\omega_0 t} - e^{-j\omega_0 t}}{2j}u(t) \leftrightarrow \frac{\omega_0}{s^2+\omega_0^2} \quad (Re(s)>0)$
5. **斜坡信号**：
   $$ \mathscr{L}[tu(t)] = \int_{0^-}^{\infty} t e^{-st}dt = \left. -\frac{t}{s}e^{-st} \right|_{0^-}^\infty + \frac{1}{s}\int_{0^-}^{\infty} e^{-st}dt = \frac{1}{s^2} \quad (Re(s)>0) $$

---

## 四、 单边拉普拉斯变换的性质 (包含全部推导与例题)

### 1. 线性性质 (Linearity)
$a x_1(t) + b x_2(t) \leftrightarrow a X_1(s) + b X_2(s)$，ROC为两者的交集：$Re(s) > \max(\sigma_1, \sigma_2)$
> **【例题】利用线性性质求 $u(t) - u(t-1)$ 的拉普拉斯变换。**
> $u(t) \leftrightarrow \frac{1}{s}$, $u(t-1) \leftrightarrow \frac{1}{s}e^{-s}$
> 结果：$\frac{1}{s} - \frac{1}{s}e^{-s} = \frac{1-e^{-s}}{s}, Re(s) > -\infty$。

### 2. 时移性质 (Time-shifting)
若 $x(t) \leftrightarrow X(s)$，则对于 $t_0 > 0$，有 $x(t-t_0)u(t-t_0) \leftrightarrow e^{-st_0}X(s)$
> **【例题】求三角脉冲信号 $x(t) = r(t) - 2r(t-1) + r(t-2)$ 的拉普拉斯变换。**
> 已知斜坡 $r(t) = tu(t) \leftrightarrow \frac{1}{s^2}$。利用时移和线性性质：
> $X(s) = \frac{1}{s^2} - \frac{2}{s^2}e^{-s} + \frac{1}{s^2}e^{-2s} = \frac{1 - 2e^{-s} + e^{-2s}}{s^2}, Re(s) > -\infty$。

> **【例题】周期信号扩展：求一串周期为2的方波序列（脉宽为1，高度为2）的拉普拉斯变换。**
> 解析：单周期信号 $x_1(t) = 2[u(t)-u(t-1)] \leftrightarrow X_1(s) = \frac{2}{s}(1-e^{-s})$。
> 整个周期信号 $x(t) = \sum_{n=0}^{\infty} x_1(t-nT)$，周期 $T=2$。
> 根据时移特性：$X(s) = \sum_{n=0}^{\infty} X_1(s)e^{-snT} = \frac{X_1(s)}{1-e^{-sT}}$ (等比数列求和)
> 代入得：$X(s) = \frac{\frac{2}{s}(1-e^{-s})}{1-e^{-2s}}, Re(s) > 0$。

### 3. 尺度变换性质 (Scaling)
$x(at) \leftrightarrow \frac{1}{a} X(\frac{s}{a}), (a>0)$，ROC变为 $Re(s) > a\sigma_0$。

### 4. 卷积性质 (Convolution)
$x_1(t) * x_2(t) \leftrightarrow X_1(s) X_2(s)$，ROC为 $Re(s) > \max(\sigma_1, \sigma_2)$
> **【例题】利用卷积性质求以 $t=1$ 为顶点的等腰三角形脉冲信号（底边宽度为2，顶点高度为1）的拉普拉斯变换。**
> 解析：该三角波可以表示为两个方波的卷积 $x(t) = x_1(t) * x_1(t)$，其中 $x_1(t) = u(t)-u(t-1) \leftrightarrow X_1(s) = \frac{1-e^{-s}}{s}$。
> $X(s) = X_1(s) \cdot X_1(s) = \left( \frac{1-e^{-s}}{s} \right)^2, Re(s) > -\infty$。

### 5. 相乘性质 (Product)
$x_1(t)x_2(t) \leftrightarrow \frac{1}{2\pi j}[X_1(s) * X_2(s)]$

### 6. 指数加权性质 (s域平移)
$e^{-\lambda t}x(t) \leftrightarrow X(s+\lambda)$，ROC变为 $Re(s) > \sigma_0 - Re(\lambda)$
> **【例题】求 $e^{-at}\cos(\omega_0 t)u(t)$ 的拉普拉斯变换。**
> 解析：已知 $\cos(\omega_0 t)u(t) \leftrightarrow \frac{s}{s^2+\omega_0^2}$。
> 根据指数加权性质，将 $s$ 替换为 $s+a$：
> $X(s) = \frac{s+a}{(s+a)^2 + \omega_0^2}, Re(s) > -a$。

### 7. 线性加权性质 (s域微分)
$t x(t) \leftrightarrow -\frac{d}{ds}X(s)$
> **【例题】求 $tu(t)$, $t^n u(t)$, $t^n e^{-\lambda t}u(t)$ 的拉普拉斯变换。**
> $\mathscr{L}\{tu(t)\} = -\frac{d}{ds}(\frac{1}{s}) = \frac{1}{s^2}$
> 反复应用此性质：$\mathscr{L}\{t^n u(t)\} = \frac{n!}{s^{n+1}}, Re(s)>0$。
> 结合指数加权性质：$\mathscr{L}\{t^n e^{-\lambda t}u(t)\} = \frac{n!}{(s+\lambda)^{n+1}}, Re(s)>-Re(\lambda)$。

### 8. 微分性质 (Differentiation)
$\frac{dx(t)}{dt} \leftrightarrow sX(s) - x(0^-)$
> **【定理推导】**
> $\mathscr{L}[\frac{dx(t)}{dt}] = \int_{0^-}^{\infty} \frac{dx(t)}{dt}e^{-st}dt = \left. x(t)e^{-st} \right|_{0^-}^{\infty} - \int_{0^-}^{\infty} x(t)(-se^{-st})dt$
> $= -x(0^-) + s\int_{0^-}^{\infty} x(t)e^{-st}dt = sX(s) - x(0^-)$
> 反复使用可得二阶及高阶导数：
> $\frac{d^2 x(t)}{dt^2} \leftrightarrow s^2 X(s) - sx(0^-) - x'(0^-)$
> $\frac{d^n x(t)}{dt^n} \leftrightarrow s^n X(s) - s^{n-1}x(0^-) - \cdots - x^{(n-1)}(0^-)$

> **【例题】利用微分性质求前面提到的等腰三角脉冲信号的 $X(s)$。**
> 解析：对原三角波连续求导两次。
> 第一阶导数 $x'(t)$ 是一个门函数 $1 (0<t<1)$ 和一个负门函数 $-1 (1<t<2)$。
> 第二阶导数 $x''(t) = \delta(t) - 2\delta(t-1) + \delta(t-2)$。
> $\mathscr{L}\{x''(t)\} = 1 - 2e^{-s} + e^{-2s}$。
> 由于 $x(0^-)=0, x'(0^-)=0$，根据微分性质 $\mathscr{L}\{x''(t)\} = s^2 X(s)$。
> 因此 $X(s) = \frac{1 - 2e^{-s} + e^{-2s}}{s^2}$。

*实际电路系统中的应用：电感的s域模型为 $V_L(s) = sL I_L(s) - L i_L(0^-)$，这正是微分性质的体现。*

### 9. 积分性质 (Integration)
$\int_{-\infty}^{t} x(\tau)d\tau \leftrightarrow \frac{X(s)}{s} + \frac{x^{(-1)}(0^-)}{s}$ （若初始状态为0，则为 $\frac{X(s)}{s}$）
> **【例题】利用积分性质求信号 $x(t)$ (从 0 到 1 线性上升，之后保持 1) 的拉普拉斯变换。**
> 解析：该信号可以看作是方波脉冲 $y(t) = u(t)-u(t-1)$ 的积分 $x(t) = \int_{-\infty}^{t} y(\tau)d\tau$。
> $Y(s) = \frac{1-e^{-s}}{s}$，因初始积分值为 0，故 $X(s) = \frac{Y(s)}{s} = \frac{1-e^{-s}}{s^2}$。

*实际电路系统中的应用：电容的s域模型为 $V_C(s) = \frac{1}{sC} I_C(s) + \frac{1}{s} v_C(0^-)$。*

### 10. 初值定理与终值定理 (IVT & FVT)
*   **初值定理**：若 $x(t)$ 在 $t=0$ 时不包含冲激及其导数，$\lim_{t\to 0^+} x(t) = \lim_{s\to\infty} sX(s)$
*   **终值定理**：若 $sX(s)$ 的收敛域包含 $j\omega$ 轴（即极点在左半平面），$\lim_{t\to \infty} x(t) = \lim_{s\to 0} sX(s)$

> **【例题】已知 $X(s) = \frac{1}{s+1}, Re(s)>-1$，求初值和终值。**
> 初值：$x(0^+) = \lim_{s\to\infty} s \cdot \frac{1}{s+1} = 1$。
> 终值：极点在 -1（左半平面），适用终值定理：$x(+\infty) = \lim_{s\to 0} s \cdot \frac{1}{s+1} = 0$。

> **【例题】已知 $X(s) = \frac{s}{s+1}, Re(s)>-1$，求初值和终值。**
> 解析：因为分子分母同阶（假分式），$x(t)$ 在 $t=0$ 处包含冲激信号，不能直接用初值定理。
> 改写为 $X(s) = 1 - \frac{1}{s+1} = 1 - X_1(s)$。对真分式 $X_1(s)$ 运用初值定理：$x(0^+) = \lim_{s\to\infty} s \cdot \frac{1}{s+1} = 1$。
> 终值：直接用 $\lim_{s\to 0} s \frac{s}{s+1} = 0$。

---

## 五、 单边拉普拉斯逆变换
求逆变换常用**部分分式展开法 (Partial Fraction Expansion)**，适用于有理分式形式的 $X(s)$。（留数法较为复杂但适用广）

### 1. 留数法 (Residue Method)
$x(t) = \sum_{k=0}^{n} \text{Res}[X(s)e^{st}]_{s=p_k}$
> **【例题】利用留数法求 $X(s) = \frac{1}{s^2+3s+2}$ 的逆变换。**
> 极点为单极点 $s_1 = -1, s_2 = -2$。
> $\text{Res}_{s=-1} = \left. (s+1)X(s)e^{st} \right|_{s=-1} = \left. \frac{1}{s+2}e^{st} \right|_{s=-1} = e^{-t}$
> $\text{Res}_{s=-2} = \left. (s+2)X(s)e^{st} \right|_{s=-2} = \left. \frac{1}{s+1}e^{st} \right|_{s=-2} = -e^{-2t}$
> $x(t) = (e^{-t} - e^{-2t})u(t)$

### 2. 部分分式展开法 (核心方法)

#### 情形 1：有理真分式，分母只有单根
> **【例题】 $X(s) = \frac{2}{s^2+3s}$**
> 展开：$X(s) = \frac{2}{s(s+3)} = \frac{k_1}{s} + \frac{k_2}{s+3}$
> $k_1 = \left. s X(s) \right|_{s=0} = \left. \frac{2}{s+3} \right|_{s=0} = \frac{2}{3}$
> $k_2 = \left. (s+3) X(s) \right|_{s=-3} = \left. \frac{2}{s} \right|_{s=-3} = -\frac{2}{3}$
> $X(s) = \frac{2/3}{s} - \frac{2/3}{s+3} \implies x(t) = \left(\frac{2}{3} - \frac{2}{3}e^{-3t}\right)u(t)$

#### 情形 2：有理真分式，分母有多重根
> **【例题】 $X(s) = \frac{s-1}{s(s+1)^2}$**
> 展开：$X(s) = \frac{k_1}{s} + \frac{k_2}{(s+1)^2} + \frac{k_3}{s+1}$
> 求单根 $k_1$：$k_1 = \left. s X(s) \right|_{s=0} = \left. \frac{s-1}{(s+1)^2} \right|_{s=0} = -1$
> 求重根最高阶系数 $k_2$：$k_2 = \left. (s+1)^2 X(s) \right|_{s=-1} = \left. \frac{s-1}{s} \right|_{s=-1} = 2$
> 求次阶系数 $k_3$：$k_3 = \left. \frac{d}{ds}[(s+1)^2 X(s)] \right|_{s=-1} = \left. \frac{d}{ds}(\frac{s-1}{s}) \right|_{s=-1} = \left. \frac{1}{s^2} \right|_{s=-1} = 1$
> $X(s) = \frac{-1}{s} + \frac{2}{(s+1)^2} + \frac{1}{s+1} \implies x(t) = (-1 + 2te^{-t} + e^{-t})u(t)$

#### 情形 3：假分式 (分子阶数 $m \ge$ 分母阶数 $n$)
将假分式化为多项式 + 真分式的形式。
> **【例题】 $X(s) = \frac{s^3-s^2-12s+2}{s^2+3s}$**
> 长除法分离：$X(s) = s - 4 + \frac{2}{s^2+3s}$
> 多项式部分求逆：$\mathscr{L}^{-1}\{s\} = \delta'(t)$, $\mathscr{L}^{-1}\{-4\} = -4\delta(t)$
> 真分式部分借用上面例题结论：$\frac{2}{s^2+3s} \to \frac{2}{3}u(t) - \frac{2}{3}e^{-3t}u(t)$
> $x(t) = \delta'(t) - 4\delta(t) + \frac{2}{3}u(t) - \frac{2}{3}e^{-3t}u(t)$

---

## 六、 双边拉普拉斯变换 (Bilateral Laplace Transform)
**定义**：积分上下限从 $-\infty$ 到 $+\infty$。
$$ X(s) = \int_{-\infty}^{\infty} x(t)e^{-st}dt $$
收敛域：必须同时保证 $t \to -\infty$ 和 $t \to +\infty$ 时的积分都收敛，通常是复平面上两条垂线之间的带状区域 $\sigma_1 < Re(s) < \sigma_2$。

### 1. 不同类型信号的收敛域与举例
> **【例题 1：有限长信号】 $x(t) = u(t+2) - u(t-2)$**
> $X(s) = \int_{-2}^{2} e^{-st}dt = \frac{1}{s}(e^{2s} - e^{-2s})$。
> 有限长积分处处收敛，ROC为整个 $s$ 平面，$Re(s) > -\infty$。

> **【例题 2：右边信号】 $x(t) = e^{-2t}u(t)$**
> $X(s) = \int_{0}^{\infty} e^{-2t}e^{-st}dt = \frac{1}{s+2}$。
> ROC表现为某一极点的右侧：$Re(s) > -2$。

> **【例题 3：左边信号】 $x(t) = e^{-t}u(-t)$**
> $X(s) = \int_{-\infty}^{0} e^{-t}e^{-st}dt = \left. -\frac{1}{s+1}e^{-(s+1)t} \right|_{-\infty}^0 = \frac{-1}{s+1}$。
> ROC表现为某一极点的左侧：$Re(s) < -1$。

> **【例题 4：双边信号】 $x(t) = e^{-t}u(-t) + e^{-2t}u(t)$**
> $X(s) = \int_{-\infty}^{0} e^{-t}e^{-st}dt + \int_{0}^{\infty} e^{-2t}e^{-st}dt = \frac{-1}{s+1} + \frac{1}{s+2}$。
> ROC为两部分的交集（带状区域）：$-2 < Re(s) < -1$。

### 2. 双边拉普拉斯逆变换
由于同一个解析表达式 $X(s)$ 根据不同的收敛域可以对应不同的时域信号，因此求解时**必须指明收敛域**，根据收敛域相对于极点的位置来决定逆变换是左边信号还是右边信号。

> **【综合例题】 已知 $X(s) = \frac{2s+1}{(s+2)(s+3)}$，分别在以下三个收敛域下求解对应的时域信号 $x(t)$。**
> **【解析】** 部分分式展开：$X(s) = \frac{-3}{s+2} + \frac{5}{s+3}$。极点为 $s=-2$ 和 $s=-3$。
> 
> **(1) 当 $Re(s) > -2$ 时**：
> 收敛域在两个极点的右侧，说明两个分式均对应**右边信号（因果信号）**。
> $x(t) = -3e^{-2t}u(t) + 5e^{-3t}u(t)$
> 
> **(2) 当 $-3 < Re(s) < -2$ 时**：
> 收敛域在 $s=-3$ 的右侧，在 $s=-2$ 的左侧。因此对应 $s=-3$ 的项是右边信号，对应 $s=-2$ 的项是**左边信号（反因果信号）**。
> 注意公式：$\frac{1}{s-\lambda} (Re(s)<\lambda) \leftrightarrow -e^{\lambda t}u(-t)$
> $x(t) = 3e^{-2t}u(-t) + 5e^{-3t}u(t)$
> 
> **(3) 当 $Re(s) < -3$ 时**：
> 收敛域在两个极点的左侧，说明两个分式均对应**左边信号**。
> $x(t) = 3e^{-2t}u(-t) - 5e^{-3t}u(-t)$