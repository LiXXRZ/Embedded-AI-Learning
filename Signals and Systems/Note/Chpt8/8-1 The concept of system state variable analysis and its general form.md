# 学习笔记：系统状态变量分析的基本概念与一般形式

> 第八章开始从“输入-输出描述”转向“内部状态描述”。复习主线：为什么需要状态变量，什么是状态方程/输出方程，以及连续系统和离散系统的矩阵标准形式。

---

## 一、为什么要引入状态变量分析？

前面章节常用的是输入-输出方法：

* 连续系统：用微分方程描述输入 $x(t)$ 与输出 $y(t)$；
* 离散系统：用差分方程描述输入 $x[k]$ 与输出 $y[k]$；
* 重点关注“输入进去后输出是什么”。

典型形式：
$$ y^{(n)}(t)+a_1y^{(n-1)}(t)+\cdots+a_ny(t)
=b_0x^{(m)}(t)+b_1x^{(m-1)}(t)+\cdots+b_mx(t) $$

离散系统：
$$ \sum_{i=0}^{n}a_i y[k-i]=\sum_{j=0}^{m}b_jx[k-j] $$

这种方法对 SISO（单输入单输出）很顺手，但遇到 MIMO（多输入多输出）系统会变笨重：输入、输出很多，内部储能变量之间又相互耦合，只用一个输入-输出方程不容易看清系统内部。

---

## 二、状态变量分析的核心思想

状态变量法不是只盯着输入和输出，而是选一组能描述系统内部状态的变量：

$$ q_1(t),q_2(t),\dots,q_n(t) $$

或离散系统中的
$$ q_1[k],q_2[k],\dots,q_n[k] $$

只要知道当前状态和当前输入，就能决定系统下一步如何变化。

### 1. 状态变量

状态变量 $q_i(t)$：描述系统内部状态的一组**相互独立、数量尽量少**的变量。

电路中最常见的选法：

* 电容电压 $v_C(t)$；
* 电感电流 $i_L(t)$。

复习提醒：状态变量个数通常等于系统的独立储能元件个数，但要注意“独立”二字。等效电路或受约束的储能元件不一定增加状态维数。

### 2. 状态向量、输入向量、输出向量

状态向量：
$$ \mathbf q(t)=
\begin{bmatrix}
q_1(t)\\q_2(t)\\ \vdots\\ q_n(t)
\end{bmatrix} $$

输入向量：
$$ \mathbf x(t)=
\begin{bmatrix}
x_1(t)\\x_2(t)\\ \vdots\\ x_m(t)
\end{bmatrix} $$

输出向量：
$$ \mathbf y(t)=
\begin{bmatrix}
y_1(t)\\y_2(t)\\ \vdots\\ y_p(t)
\end{bmatrix} $$

其中：

* $n$：状态变量个数；
* $m$：输入个数；
* $p$：输出个数。

---

## 三、状态方程与输出方程

### 1. 状态方程

状态方程描述“状态如何随输入演化”。

连续时间系统：一阶微分方程组
$$ \dot{\mathbf q}(t)=A\mathbf q(t)+B\mathbf x(t) $$

离散时间系统：一阶差分方程组
$$ \mathbf q[k+1]=A\mathbf q[k]+B\mathbf x[k] $$

### 2. 输出方程

输出方程描述“输出如何由当前状态和当前输入得到”。

连续时间系统：
$$ \mathbf y(t)=C\mathbf q(t)+D\mathbf x(t) $$

离散时间系统：
$$ \mathbf y[k]=C\mathbf q[k]+D\mathbf x[k] $$

### 3. 四个矩阵的意义和维度

| 矩阵 | 维度 | 含义 |
| :--- | :--- | :--- |
| $A$ | $n\times n$ | 状态之间如何相互影响 |
| $B$ | $n\times m$ | 输入如何影响状态 |
| $C$ | $p\times n$ | 状态如何影响输出 |
| $D$ | $p\times m$ | 输入如何直接影响输出 |

复习时先查维度。只要矩阵维度不对，方程一定写错。

---

## 四、连续时间系统的一般形式

若系统有 $n$ 个状态变量、$m$ 个输入、$p$ 个输出，则：

$$
\dot{\mathbf q}(t)=
\begin{bmatrix}
a_{11}&a_{12}&\cdots&a_{1n}\\
a_{21}&a_{22}&\cdots&a_{2n}\\
\vdots&\vdots&\ddots&\vdots\\
a_{n1}&a_{n2}&\cdots&a_{nn}
\end{bmatrix}
\mathbf q(t)
+
\begin{bmatrix}
b_{11}&b_{12}&\cdots&b_{1m}\\
b_{21}&b_{22}&\cdots&b_{2m}\\
\vdots&\vdots&\ddots&\vdots\\
b_{n1}&b_{n2}&\cdots&b_{nm}
\end{bmatrix}
\mathbf x(t)
$$

简写为
$$ \boxed{\dot{\mathbf q}(t)=A\mathbf q(t)+B\mathbf x(t)} $$

输出方程：
$$ \boxed{\mathbf y(t)=C\mathbf q(t)+D\mathbf x(t)} $$

其中 $C$ 是 $p\times n$，$D$ 是 $p\times m$。

---

## 五、离散时间系统的一般形式

离散系统把“导数”换成“下一时刻状态”：

$$ \boxed{\mathbf q[k+1]=A\mathbf q[k]+B\mathbf x[k]} $$
$$ \boxed{\mathbf y[k]=C\mathbf q[k]+D\mathbf x[k]} $$

和连续系统的区别只有状态演化方式：

| 类型 | 状态方程 |
| :--- | :--- |
| 连续时间 | $\dot{\mathbf q}(t)=A\mathbf q(t)+B\mathbf x(t)$ |
| 离散时间 | $\mathbf q[k+1]=A\mathbf q[k]+B\mathbf x[k]$ |

输出方程形式完全平行：
$$ \mathbf y=C\mathbf q+D\mathbf x $$

---

## 六、课件例题：双输入双输出 RLC 电路

课件用一个含电容、电感、两个输入和两个输出的 RLC 电路说明状态变量方法。

### 1. 选状态变量

选电容电压和电感电流：
$$ q_1(t)=v_C(t),\quad q_2(t)=i_L(t) $$

状态向量：
$$ \mathbf q(t)=
\begin{bmatrix}
q_1(t)\\q_2(t)
\end{bmatrix} $$

输入向量：
$$ \mathbf x(t)=
\begin{bmatrix}
x_1(t)\\x_2(t)
\end{bmatrix} $$

输出向量：
$$ \mathbf y(t)=
\begin{bmatrix}
y_1(t)\\y_2(t)
\end{bmatrix} $$

### 2. 写状态方程

由电路方程整理得到：
$$ \dot q_1(t)
=-\frac{1}{R_1C}q_1(t)-\frac{1}{C}q_2(t)
+\frac{1}{R_1C}x_1(t)+\frac{1}{C}x_2(t) $$

$$ \dot q_2(t)
=\frac{1}{L}q_1(t)-\frac{R_2}{L}q_2(t) $$

写成矩阵：
$$
\begin{bmatrix}
\dot q_1(t)\\
\dot q_2(t)
\end{bmatrix} =
\begin{bmatrix}
-\frac{1}{R_1C} & -\frac{1}{C}\\
\frac{1}{L} & -\frac{R_2}{L}
\end{bmatrix}
\begin{bmatrix}
q_1(t)\\q_2(t)
\end{bmatrix} +
\begin{bmatrix}
\frac{1}{R_1C} & \frac{1}{C}\\
0 & 0
\end{bmatrix}
\begin{bmatrix}
x_1(t)\\x_2(t)
\end{bmatrix}
$$

### 3. 写输出方程

课件整理得到：
$$ y_1(t)=x_1(t)-q_1(t) $$
$$ y_2(t)=R_2q_2(t) $$

矩阵形式：
$$
\begin{bmatrix}
y_1(t)\\y_2(t)
\end{bmatrix} =
\begin{bmatrix}
-1&0\\
0&R_2
\end{bmatrix}
\begin{bmatrix}
q_1(t)\\q_2(t)
\end{bmatrix} +
\begin{bmatrix}
1&0\\
0&0
\end{bmatrix}
\begin{bmatrix}
x_1(t)\\x_2(t)
\end{bmatrix}
$$

---

## 七、复习抓手

1. 状态变量法适合 MIMO，也适合看内部储能与动态演化。
2. 连续系统状态方程是 $\dot{\mathbf q}=A\mathbf q+B\mathbf x$。
3. 离散系统状态方程是 $\mathbf q[k+1]=A\mathbf q[k]+B\mathbf x[k]$。
4. 输出方程都是 $\mathbf y=C\mathbf q+D\mathbf x$。
5. 检查答案时先看矩阵维度：$A(n\times n)$、$B(n\times m)$、$C(p\times n)$、$D(p\times m)$。

