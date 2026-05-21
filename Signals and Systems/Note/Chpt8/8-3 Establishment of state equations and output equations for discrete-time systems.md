# 学习笔记：离散时间系统状态方程与输出方程的建立

> 本节对应课件 Chpt8-3。连续系统看积分器，离散系统看延迟器。复习核心：选 **延迟器输出端** 作为状态变量，然后围绕延迟器输入写 $\mathbf q[k+1]$，围绕系统输出写 $\mathbf y[k]$。

---

## 一、离散系统状态空间模型

离散时间系统的标准形式是：
$$ \boxed{\mathbf q[k+1]=A\mathbf q[k]+B\mathbf x[k]} $$
$$ \boxed{\mathbf y[k]=C\mathbf q[k]+D\mathbf x[k]} $$

与连续系统相比：

| 连续系统 | 离散系统 |
| :--- | :--- |
| 积分器输出作状态 | 延迟器输出作状态 |
| $\dot{\mathbf q}(t)$ | $\mathbf q[k+1]$ |
| $\dot{\mathbf q}=A\mathbf q+B\mathbf x$ | $\mathbf q[k+1]=A\mathbf q[k]+B\mathbf x[k]$ |

---

## 二、由离散模拟框图建立状态方程

### 1. 基本步骤

1. 选每个 $z^{-1}$ 延迟器的输出端作为状态变量；
2. 延迟器输入端的信号，就是下一时刻状态 $q_i[k+1]$；
3. 围绕系统输出端列输出方程；
4. 整理成矩阵形式。

### 2. 课件例题：两个延迟器的 MIMO 框图

选延迟器输出：
$$ q_1[k],\quad q_2[k] $$

状态方程：
$$ q_1[k+1]=a_1q_1[k]+x_1[k] $$
$$ q_2[k+1]=a_2q_2[k]+x_2[k] $$

输出方程：
$$ y_1[k]=q_1[k]+q_2[k] $$
$$ y_2[k]=q_1[k]+x_2[k] $$

矩阵形式：
$$
\begin{bmatrix}
q_1[k+1]\\q_2[k+1]
\end{bmatrix} =
\begin{bmatrix}
a_1&0\\
0&a_2
\end{bmatrix}
\begin{bmatrix}
q_1[k]\\q_2[k]
\end{bmatrix} +
\begin{bmatrix}
1&0\\
0&1
\end{bmatrix}
\begin{bmatrix}
x_1[k]\\x_2[k]
\end{bmatrix}
$$

$$
\begin{bmatrix}
y_1[k]\\y_2[k]
\end{bmatrix}
=
\begin{bmatrix}
1&1\\
1&0
\end{bmatrix}
\begin{bmatrix}
q_1[k]\\q_2[k]
\end{bmatrix}
+
\begin{bmatrix}
0&0\\
0&1
\end{bmatrix}
\begin{bmatrix}
x_1[k]\\x_2[k]
\end{bmatrix}
$$

---

## 三、由系统函数建立状态方程

课件例题：
$$ H(z)=\frac{3+3.6z^{-1}+0.6z^{-2}}
{1+0.1z^{-1}-0.2z^{-2}} $$

同一个 $H(z)$ 可以画成直接型、级联型、并联型；对应的状态方程不同，但输入-输出关系相同。

---

## 四、直接型结构

直接型框图中选两个延迟器输出为状态变量 $q_1[k],q_2[k]$。

### 1. 状态方程

由延迟器输入端列式：
$$ q_1[k+1]=q_2[k] $$
$$ q_2[k+1]=0.2q_1[k]-0.1q_2[k]+x[k] $$

### 2. 输出方程

课件先从前馈支路写：
$$ y[k]=0.6q_1[k]+3.6q_2[k]+3q_2[k+1] $$

再把 $q_2[k+1]$ 代入：
$$ y[k]=0.6q_1[k]+3.6q_2[k]+3(0.2q_1[k]-0.1q_2[k]+x[k]) $$

整理：
$$ \boxed{y[k]=1.2q_1[k]+3.3q_2[k]+3x[k]} $$

### 3. 矩阵形式

$$
\begin{bmatrix}
q_1[k+1]\\q_2[k+1]
\end{bmatrix}
=
\begin{bmatrix}
0&1\\
0.2&-0.1
\end{bmatrix}
\begin{bmatrix}
q_1[k]\\q_2[k]
\end{bmatrix}
+
\begin{bmatrix}
0\\1
\end{bmatrix}x[k]
$$

$$
y[k]=
\begin{bmatrix}
1.2&3.3
\end{bmatrix}
\begin{bmatrix}
q_1[k]\\q_2[k]
\end{bmatrix}
+3x[k]
$$

因此：
$$ A=\begin{bmatrix}0&1\\0.2&-0.1\end{bmatrix},\quad
B=\begin{bmatrix}0\\1\end{bmatrix},\quad
C=\begin{bmatrix}1.2&3.3\end{bmatrix},\quad
D=3 $$

---

## 五、级联型结构

课件把系统函数分解为两个一阶子系统级联，并选两个延迟器输出作为状态变量。

### 1. 状态方程

课件整理后的状态方程为：
$$ q_1[k+1]=0.4q_1[k]-0.9q_2[k]+3x[k] $$
$$ q_2[k+1]=-0.5q_2[k]+x[k] $$

### 2. 输出方程

$$ y[k]=1.4q_1[k]-0.9q_2[k]+3x[k] $$

### 3. 矩阵形式

$$
\begin{bmatrix}
q_1[k+1]\\q_2[k+1]
\end{bmatrix}
=
\begin{bmatrix}
0.4&-0.9\\
0&-0.5
\end{bmatrix}
\begin{bmatrix}
q_1[k]\\q_2[k]
\end{bmatrix}
+
\begin{bmatrix}
3\\1
\end{bmatrix}x[k]
$$

$$
y[k]=
\begin{bmatrix}
1.4&-0.9
\end{bmatrix}
\begin{bmatrix}
q_1[k]\\q_2[k]
\end{bmatrix}
+3x[k]
$$

因此：
$$ A=\begin{bmatrix}0.4&-0.9\\0&-0.5\end{bmatrix},\quad
B=\begin{bmatrix}3\\1\end{bmatrix},\quad
C=\begin{bmatrix}1.4&-0.9\end{bmatrix},\quad
D=3 $$

---

## 六、并联型结构

课件的并联结构可理解为：
$$ H(z)=3+\frac{0.5z^{-1}}{1+0.5z^{-1}}
+\frac{2.8z^{-1}}{1-0.4z^{-1}} $$

选两个并联一阶支路的延迟器输出为状态变量。

### 1. 状态方程

$$ q_1[k+1]=-0.5q_1[k]+x[k] $$
$$ q_2[k+1]=0.4q_2[k]+x[k] $$

### 2. 输出方程

$$ y[k]=0.5q_1[k]+2.8q_2[k]+3x[k] $$

### 3. 矩阵形式

$$
\begin{bmatrix}
q_1[k+1]\\q_2[k+1]
\end{bmatrix}
=
\begin{bmatrix}
-0.5&0\\
0&0.4
\end{bmatrix}
\begin{bmatrix}
q_1[k]\\q_2[k]
\end{bmatrix}
+
\begin{bmatrix}
1\\1
\end{bmatrix}x[k]
$$

$$
y[k]=
\begin{bmatrix}
0.5&2.8
\end{bmatrix}
\begin{bmatrix}
q_1[k]\\q_2[k]
\end{bmatrix}
+3x[k]
$$

因此：
$$ A=\begin{bmatrix}-0.5&0\\0&0.4\end{bmatrix},\quad
B=\begin{bmatrix}1\\1\end{bmatrix},\quad
C=\begin{bmatrix}0.5&2.8\end{bmatrix},\quad
D=3 $$

---

## 七、三种实现的对比

| 结构 | 特点 | 状态变量选法 |
| :--- | :--- | :--- |
| 直接型 | 从 $H(z)$ 的分子分母直接搭延迟链 | 延迟器输出 |
| 级联型 | 把高阶系统拆成低阶环节相乘 | 每个子系统延迟器输出 |
| 并联型 | 对 $H(z)$ 做部分分式展开 | 每个并联支路延迟器输出 |

同一个系统函数可以有不同状态空间实现，因此 $A,B,C,D$ 不唯一。只要最终输入-输出关系仍是原来的 $H(z)$，这些实现就是等价的。

---

## 八、做题检查清单

1. 看到 $z^{-1}$，优先把延迟器输出设为状态变量。
2. 延迟器输入端 = 下一时刻状态 $q[k+1]$。
3. 输出端所有支路相加，得到 $y[k]$。
4. 若输出式里出现 $q[k+1]$，要代回状态方程，整理成 $q[k]$ 和 $x[k]$。
5. 最后写成 $A,B,C,D$，并检查维度。

