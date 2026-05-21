# 学习笔记：连续时间系统状态方程与输出方程的建立

> 本节对应课件 Chpt8-2。核心问题：系统可能以电路、微分方程、模拟框图、系统函数四种形式给出，如何写成统一的状态空间模型
> $$ \dot{\mathbf q}(t)=A\mathbf q(t)+B\mathbf x(t),\quad \mathbf y(t)=C\mathbf q(t)+D\mathbf x(t) $$

---

## 一、总流程：连续系统怎么建模？

连续系统常见给法：

1. 电路图；
2. 微分方程；
3. 模拟框图；
4. 系统函数 $H(s)$。

不管从哪里开始，目标都是写出：
$$ \boxed{\dot{\mathbf q}(t)=A\mathbf q(t)+B\mathbf x(t)} $$
$$ \boxed{\mathbf y(t)=C\mathbf q(t)+D\mathbf x(t)} $$

复习时最稳的做法是先选状态变量，再围绕状态变量列方程。

---

## 二、由电路建立状态方程

### 1. 电路题的选变量规则

电路中一般选：

* 电容电压 $v_C(t)$；
* 电感电流 $i_L(t)$。

原因很简单：电容和电感是储能元件，系统的“记忆”就在这里。

### 2. 课件例题：RLC 电路

电路中有两个独立动态元件 $C$ 和 $L$，所以需要两个状态变量：
$$ q_1(t)=v_C(t),\quad q_2(t)=i_L(t) $$

根据电容电流关系：
$$ C\dot q_1(t)=i_1(t)-i_2(t) $$

根据回路电压方程：
$$ x(t)=R_1i_1(t)+q_1(t) $$
$$ L\dot q_2(t)+R_2q_2(t)-q_1(t)=0 $$

整理得到状态方程：
$$ \dot q_1(t)
=-\frac{1}{R_1C}q_1(t)-\frac{1}{C}q_2(t)
+\frac{1}{R_1C}x(t) $$

$$ \dot q_2(t)
=\frac{1}{L}q_1(t)-\frac{R_2}{L}q_2(t) $$

输出为电阻 $R_2$ 上的电压：
$$ y(t)=R_2q_2(t) $$

矩阵形式：
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
\frac{1}{R_1C}\\0
\end{bmatrix}x(t)
$$

$$
y(t)=
\begin{bmatrix}
0&R_2
\end{bmatrix}
\begin{bmatrix}
q_1(t)\\q_2(t)
\end{bmatrix}
$$

### 3. 电路题步骤卡

1. 数独立储能元件，确定状态变量个数；
2. 一般选 $v_C(t)$ 与 $i_L(t)$；
3. 围绕电感列 KVL，得到 $\dot i_L(t)$；
4. 围绕电容列 KCL，得到 $\dot v_C(t)$；
5. 最后用状态变量和输入表示输出。

---

## 三、由微分方程建立状态方程

### 1. 标准选法

若系统由 $n$ 阶微分方程描述，最直接的状态变量选法是：
$$ q_1(t)=y(t),\quad q_2(t)=\dot y(t),\quad q_3(t)=\ddot y(t),\dots $$

也就是把输出及其低阶导数作为状态变量。

### 2. 课件例题

给定：
$$ y''(t)+3y'(t)+2y(t)=x(t) $$

选：
$$ q_1(t)=y(t),\quad q_2(t)=y'(t) $$

于是：
$$ \dot q_1(t)=q_2(t) $$

由原方程：
$$ y''(t)=x(t)-3y'(t)-2y(t) $$

所以：
$$ \dot q_2(t)=-2q_1(t)-3q_2(t)+x(t) $$

输出方程：
$$ y(t)=q_1(t) $$

矩阵形式：
$$
\begin{bmatrix}
\dot q_1(t)\\
\dot q_2(t)
\end{bmatrix} =
\begin{bmatrix}
0&1\\
-2&-3
\end{bmatrix}
\begin{bmatrix}
q_1(t)\\q_2(t)
\end{bmatrix} +
\begin{bmatrix}
0\\1
\end{bmatrix}x(t)
$$

$$
y(t)=
\begin{bmatrix}
1&0
\end{bmatrix}
\begin{bmatrix}
q_1(t)\\q_2(t)
\end{bmatrix}
$$

复习提醒：这种写法是“相变量形式”。它很直观，但不是唯一状态空间实现。

---

## 四、由模拟框图建立状态方程

### 1. 选变量规则

连续模拟框图中，优先选**积分器输出端**作为状态变量。

原因：积分器输出就是系统记忆，积分器输入就是对应状态变量的导数。

### 2. 课件例题：两个积分器的 MIMO 框图

选积分器输出：
$$ q_1(t),\quad q_2(t) $$

围绕积分器输入列状态方程：
$$ \dot q_1(t)=a_1q_1(t)+x_1(t) $$
$$ \dot q_2(t)=a_2q_2(t)+x_2(t) $$

围绕输出端列输出方程：
$$ y_1(t)=q_1(t)+x_2(t) $$
$$ y_2(t)=q_1(t)+q_2(t) $$

矩阵形式：
$$
\begin{bmatrix}
\dot q_1(t)\\
\dot q_2(t)
\end{bmatrix} =
\begin{bmatrix}
a_1&0\\
0&a_2
\end{bmatrix}
\begin{bmatrix}
q_1(t)\\q_2(t)
\end{bmatrix} +
\begin{bmatrix}
1&0\\
0&1
\end{bmatrix}
\begin{bmatrix}
x_1(t)\\x_2(t)
\end{bmatrix}
$$

$$
\begin{bmatrix}
y_1(t)\\y_2(t)
\end{bmatrix} =
\begin{bmatrix}
1&0\\
1&1
\end{bmatrix}
\begin{bmatrix}
q_1(t)\\q_2(t)
\end{bmatrix} +
\begin{bmatrix}
0&1\\
0&0
\end{bmatrix}
\begin{bmatrix}
x_1(t)\\x_2(t)
\end{bmatrix}
$$

---

## 五、由系统函数建立状态方程

已知系统函数时，课件强调先画模拟框图，再从框图写状态方程。不同结构会得到不同的 $A,B,C,D$，但输入-输出系统函数相同。

课件例题：
$$ H(s)=\frac{2s+5}{s^3+9s^2+26s+24} $$

### 1. 直接型结构

直接型对应：
$$ \dot q_1(t)=q_2(t) $$
$$ \dot q_2(t)=q_3(t) $$
$$ \dot q_3(t)=-24q_1(t)-26q_2(t)-9q_3(t)+x(t) $$
$$ y(t)=5q_1(t)+2q_2(t) $$

矩阵形式：
$$
\dot{\mathbf q}(t)=
\begin{bmatrix}
0&1&0\\
0&0&1\\
-24&-26&-9
\end{bmatrix}\mathbf q(t)
+
\begin{bmatrix}
0\\0\\1
\end{bmatrix}x(t)
$$

$$
y(t)=
\begin{bmatrix}
5&2&0
\end{bmatrix}\mathbf q(t)
$$

### 2. 级联型结构

课件将系统分解为若干一阶环节级联。选各积分器输出为状态变量，得到：
$$ \dot q_1(t)=-2q_1(t)+x(t) $$
$$ \dot q_2(t)=2q_1(t)-3q_2(t) $$
$$ \dot q_3(t)=2q_1(t)-0.5q_2(t)-4q_3(t) $$
$$ y(t)=q_3(t) $$

矩阵形式：
$$
\dot{\mathbf q}(t)=
\begin{bmatrix}
-2&0&0\\
2&-3&0\\
2&-0.5&-4
\end{bmatrix}\mathbf q(t)
+
\begin{bmatrix}
1\\0\\0
\end{bmatrix}x(t)
$$

$$
y(t)=
\begin{bmatrix}
0&0&1
\end{bmatrix}\mathbf q(t)
$$

### 3. 并联型结构

系统函数可拆成：
$$ H(s)=\frac{0.5}{s+2}+\frac{1}{s+3}-\frac{1.5}{s+4} $$

选三个并联一阶环节的积分器输出：
$$ \dot q_1(t)=-2q_1(t)+x(t) $$
$$ \dot q_2(t)=-3q_2(t)+x(t) $$
$$ \dot q_3(t)=-4q_3(t)+x(t) $$
$$ y(t)=0.5q_1(t)+q_2(t)-1.5q_3(t) $$

矩阵形式：
$$
\dot{\mathbf q}(t)=
\begin{bmatrix}
-2&0&0\\
0&-3&0\\
0&0&-4
\end{bmatrix}\mathbf q(t)
+
\begin{bmatrix}
1\\1\\1
\end{bmatrix}x(t)
$$

$$
y(t)=
\begin{bmatrix}
0.5&1&-1.5
\end{bmatrix}\mathbf q(t)
$$

---

## 六、重要理解：状态空间实现不唯一

同一个 $H(s)$ 可以有：

* 直接型；
* 级联型；
* 并联型；
* 其他等价状态变量选择。

它们的 $A,B,C,D$ 可能完全不同，但只要从 $x(t)$ 到 $y(t)$ 的系统函数一样，它们就是输入-输出等价实现。

复习时不要以为只有一种标准答案。考试更关注你是否能从给定结构稳定地列出状态方程和输出方程。

---

## 七、做题检查清单

1. 电路题：先选 $v_C$、$i_L$，再列 KCL/KVL。
2. 微分方程题：常选 $y,\dot y,\dots,y^{(n-1)}$。
3. 模拟框图题：状态变量选积分器输出。
4. 系统函数题：先画直接/级联/并联结构，再选积分器输出。
5. 最后检查维度：连续系统必须是 $\dot{\mathbf q}=A\mathbf q+B\mathbf x$。

