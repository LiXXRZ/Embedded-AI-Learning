# 学习笔记：离散周期信号的频域分析 (DFS)

## 零、 核心思想：离散时间的傅里叶级数
> **💡 物理直觉与核心区别**：
> 1.  **时间离散，频率也离散**：时域变成了第 $k$ 个采样点，频域变成了第 $m$ 根谱线。
> 2.  **周期的对偶性**：在连续世界里，周期信号的频谱是无限延伸的离散谱线；但在**离散世界**里，**“离散周期信号，其频谱必然也是周期且离散的！”**（时域周期 $N$，频域周期也是 $N$）。
> 3.  由于频谱是周期的，我们只需要算一个周期（$m=0$ 到 $N-1$）的值，就能知道整个频谱长什么样。

---

## 一、 👑 绝对核心：DFS 与 IDFS 公式对
对于周期为 $N$ 的离散周期信号 $\tilde{x}[k]$，其**离散傅里叶级数 (DFS)** 定义如下：

*   **DFS (正变换，求频谱 $\tilde{X}[m]$)**：
    $$\tilde{X}[m] = \sum_{k=0}^{N-1} \tilde{x}[k] e^{-j \frac{2\pi}{N} mk}$$
*   **IDFS (反变换，合成时域 $\tilde{x}[k]$)**：
    $$\tilde{x}[k] = \frac{1}{N} \sum_{m=0}^{N-1} \tilde{X}[m] e^{j \frac{2\pi}{N} mk}$$
*   **频率步长**：$\Omega_m = \frac{2\pi}{N}m$。

**⚠️ 核心特性 (Slide 6)**：
1. 频谱 $\tilde{X}[m]$ 是**离散**的。
2. 频谱 $\tilde{X}[m]$ 是**周期**为 $N$ 的序列！即 $\mathbf{\tilde{X}[m+N] = \tilde{X}[m]}$。（证明很简单：$e^{-j\frac{2\pi}{N}(m+N)k} = e^{-j\frac{2\pi}{N}mk} \cdot e^{-j2\pi k} = e^{-j\frac{2\pi}{N}mk} \cdot 1$）

---

## 二、 🛠️ 离散序列的 DFS 性质 (解题的魔法)

### 1. 线性性质 (Linearity)
$$a\tilde{x}_1[k] + b\tilde{x}_2[k] \longleftrightarrow a\tilde{X}_1[m] + b\tilde{X}_2[m]$$

### 2. 时域与频域移位性质 (Displacement)
*   **时域移位**：产生频域的线性相移。
    $$\tilde{x}[k-n] \longleftrightarrow \tilde{X}[m]e^{-j\frac{2\pi}{N}mn}$$
*   **频域移位**：相当于时域乘以复指数信号（调制）。
    $$\tilde{x}[k]e^{j\frac{2\pi}{N}lk} \longleftrightarrow \tilde{X}[m-l]$$

### 3. 对称性 (Symmetry)
与连续信号一脉相承！如果时域 $\tilde{x}[k]$ 是**实序列**（不带虚数 $j$）：
*   **共轭偶对称**：$\tilde{X}[m] = \tilde{X}^*[-m]$
*   **幅度谱** $|\tilde{X}[m]|$ 是**偶函数**（关于 $m=0, N/2$ 等对称）。
*   **相位谱** $\varphi[m]$ 是**奇函数**。
*   *(推论：如果 $\tilde{x}[k]$ 是实偶序列，则频谱也是实偶序列；如果是实奇序列，则频谱是纯虚奇序列)*。

### 4. 周期卷积特性 (Periodic Convolution) 💥 必考！
离散域的卷积定义：两个周期相同的序列，在**一个周期内**进行错位乘加。
$$\tilde{y}[k] = \tilde{x}_1[k] \circledast \tilde{x}_2[k] = \sum_{n=0}^{N-1} \tilde{x}_1[n]\tilde{x}_2[k-n]$$
*   **时域周期卷积 = 频域直接相乘**： $DFS\{\tilde{x}_1[k] \circledast \tilde{x}_2[k]\} = \tilde{X}_1[m] \cdot \tilde{X}_2[m]$
*   **时域相乘 = 频域周期卷积卷并除以 $N$**： $DFS\{\tilde{x}_1[k] \cdot \tilde{x}_2[k]\} = \frac{1}{N} \tilde{X}_1[m] \circledast \tilde{X}_2[m]$

---

## 三、 🏆 硬核例题深度拆解 (考前必刷)

### 📝 例题 1：周期单位脉冲序列 (Slide 7)
**【题目】** 周期 $N=3$，在一个周期内 $\tilde{x}[0]=1, \tilde{x}[1]=0, \tilde{x}[2]=0$。求频谱。
**【解法】**
直接套 DFS 定义式：
$$\tilde{X}[m] = \sum_{k=0}^{2} \tilde{x}[k] e^{-j\frac{2\pi}{3}mk}$$
因为只有 $k=0$ 时 $x[0]=1$，其余为 0，所以：
$$\tilde{X}[m] = 1 \cdot e^{-j\frac{2\pi}{3}m \cdot 0} = \mathbf{1}$$
> **结论**：周期单位冲激序列的频谱是全频带为 1 的均匀序列（白噪声特性）。

---

### 📝 例题 2：巧用欧拉公式“逆向匹配法”求余弦序列 (Slide 10) 🌟 极易考！
**【题目】** 周期序列 $\tilde{x}[k] = 2\cos(\frac{\pi k}{5})$，求频谱 $\tilde{X}[m]$。
**【极限拆解与防坑指南】**
*千万不要用求和符号去硬算！正余弦序列的标准解法是“逆向比较系数法”。*
1.  **确定周期 $N$**：$\Omega_0 = \frac{\pi}{5} = \frac{2\pi}{10} \implies N = 10$。
2.  **用欧拉公式拆开原信号**：
    $$\tilde{x}[k] = 2 \cdot \frac{e^{j\frac{2\pi}{10}k} + e^{-j\frac{2\pi}{10}k}}{2} = e^{j\frac{2\pi}{10}k} + e^{-j\frac{2\pi}{10}k}$$
3.  **填坑：处理负频率**！
    在离散周期信号中，DFS的 $m$ 取值是 $0 \to N-1$（即 $0 \to 9$）。不能有负数 $-1$！
    利用周期性 $e^{j2\pi k} = 1$，将负指数转换为正指数：
    $$e^{-j\frac{2\pi}{10}k} = e^{-j\frac{2\pi}{10}k} \cdot e^{j2\pi k} = e^{j\frac{2\pi}{10}(10-1)k} = e^{j\frac{2\pi}{10} \cdot 9k}$$
    所以：$\tilde{x}[k] = e^{j\frac{2\pi}{10} \cdot 1k} + e^{j\frac{2\pi}{10} \cdot 9k}$
4.  **对比 IDFS 公式**：
    标准 IDFS 为：$\tilde{x}[k] = \frac{1}{10} \sum_{m=0}^{9} \tilde{X}[m] e^{j\frac{2\pi}{10}mk}$
    将我们算出的式子也提出 $\frac{1}{10}$：
    $$\tilde{x}[k] = \frac{1}{10} \left[ \mathbf{10} \cdot e^{j\frac{2\pi}{10} \cdot 1k} + \mathbf{10} \cdot e^{j\frac{2\pi}{10} \cdot 9k} \right]$$
5.  **得出结论**：一对比就能看出，在 $m=1$ 和 $m=9$ 的地方，系数是 10。
    $$\tilde{X}[m] = \begin{cases} 10, & m=1, 9 \\ 0, & 0 \le m \le 9 \text{ 且 } m \neq 1,9 \end{cases}$$

---

### 📝 例题 3：等比数列求和计算方波频谱 (Slide 11)
**【题目】** 周期 $N=6$ 的矩形脉冲，在 $k \in [-2, 2]$ 之间值为 1，其余为 0。求频谱。
**【等比求和推导】**
$$\tilde{X}[m] = \sum_{k=-2}^{2} 1 \cdot e^{-j\frac{2\pi}{6}mk}$$
设公比 $q = e^{-j\frac{2\pi}{6}m}$，这是一个首项为 $e^{j\frac{4\pi}{6}m}$（$k=-2$ 代入），共 5 项的等比数列。
套用公式 $S = \frac{a_1 - a_1 q^n}{1 - q}$：
$$\tilde{X}[m] = \frac{e^{j\frac{4\pi}{6}m} - e^{-j\frac{6\pi}{6}m}}{1 - e^{-j\frac{2\pi}{6}m}}$$
**提取半角因子化简成正弦（核心技巧）**：分子分母各提出指数的一半！
分子提出 $e^{-j\frac{\pi}{6}m}$，分母提出 $e^{-j\frac{\pi}{6}m}$：
$$= \frac{e^{-j\frac{\pi}{6}m}(e^{j\frac{5\pi}{6}m} - e^{-j\frac{5\pi}{6}m})}{e^{-j\frac{\pi}{6}m}(e^{j\frac{\pi}{6}m} - e^{-j\frac{\pi}{6}m})} = \frac{2j \sin(\frac{5\pi}{6}m)}{2j \sin(\frac{\pi}{6}m)} = \mathbf{\frac{\sin(\frac{5\pi}{6}m)}{\sin(\frac{\pi}{6}m)}}$$
*(注：这就是离散信号中非常经典的 Dirichlet 核 / 离散 Sa 函数。)*

---

### 📝 例题 4：巧用性质求移位叠加序列 (Slide 13)
**【题目】** $\tilde{x}[k] = \{\dots, 0, 1, 1, \dots\}$（周期 $N=3$），求频谱。
**【解法】**
原序列可以看成两个基本序列组合：$\tilde{x}[k] = \tilde{x}_1[k] + 2\tilde{x}_2[k]$
*   其中 $\tilde{x}_1[k] = \{\dots, 2, -1, -1, \dots\}$ $\implies \tilde{X}_1[m]$ 已知。
*   其中 $\tilde{x}_2[k] = \{\dots, -1, 1, 1, \dots\}$ $\implies \tilde{X}_2[m]$ 已知。
直接利用**线性性质**，两个频谱按权重相加即可！

---

### 📝 例题 5：调制特性的应用 (Slide 18)
**【题目】** $\tilde{y}[k] = \tilde{x}[k]\cos(2\pi k / 3)$，已知周期为3，求 $\tilde{Y}[m]$。
**【解法】**
将余弦拆开为复指数形式：
$$\tilde{y}[k] = \tilde{x}[k] \cdot \frac{1}{2}\left( e^{j\frac{2\pi}{3}k} + e^{-j\frac{2\pi}{3}k} \right)$$
因为 $N=3$，指数部分正好对应 $l=1$ 和 $l=-1$ 的频移。
根据频移性质 $\tilde{x}[k]e^{j\frac{2\pi}{N}lk} \leftrightarrow \tilde{X}[m-l]$：
$$\tilde{Y}[m] = \mathbf{\frac{1}{2} \Big( \tilde{X}[m-1] + \tilde{X}[m+1] \Big)}$$
*（在频谱图上，这就相当于把原来的频谱分别向左、向右平移了 1 格，然后高度砍半相加）。*

---

### 📝 例题 6：超高能考点——用“矩阵法”秒杀周期卷积 (Slide 27)
周期卷积硬算极容易把下标搞错。课件提供了一种**“循环矩阵法 (Matrix representation)”**，这在考试中是拿分的神器！

**【题目】** $N=3$，已知 $\tilde{x}_1[k] = \{\underline{0}, 1, 2\}$，$\tilde{x}_2[k] = \{\underline{3}, 2, 1\}$ （下划线代表 $k=0$）。求 $\tilde{y}[k] = \tilde{x}_1[k] \circledast \tilde{x}_2[k]$。
**【极限详细解法】**
由于 $N=3$，卷积结果也只有 3 个值 $\tilde{y}[0], \tilde{y}[1], \tilde{y}[2]$。我们可以写成矩阵乘法 $Y = X_2 \cdot X_1$。

**核心步骤：构建循环矩阵 $X_2$**
1.  **第一列**：直接把 $\tilde{x}_2$ 在一个周期内的值**按顺序竖着写**下来：$\begin{bmatrix} 3 \\ 2 \\ 1 \end{bmatrix}$。
2.  **第二列**：把第一列的值**整体往下移一格**，最底下的数“循环”回到最上面：$\begin{bmatrix} 1 \\ 3 \\ 2 \end{bmatrix}$。
3.  **第三列**：把第二列的值再往下移一格，最底下的数回到最上面：$\begin{bmatrix} 2 \\ 1 \\ 3 \end{bmatrix}$。

将构造好的 $3 \times 3$ 矩阵，去乘以 $\tilde{x}_1$ 的列向量：
$$
\begin{bmatrix} \tilde{y}[0] \\ \tilde{y}[1] \\ \tilde{y}[2] \end{bmatrix} =
\begin{bmatrix}
3 & 1 & 2 \\
2 & 3 & 1 \\
1 & 2 & 3
\end{bmatrix}
\begin{bmatrix}
0 \\ 1 \\ 2
\end{bmatrix}
$$
**矩阵乘法计算**：
*   $\tilde{y}[0] = 3(0) + 1(1) + 2(2) = 1 + 4 = \mathbf{5}$
*   $\tilde{y}[1] = 2(0) + 3(1) + 1(2) = 3 + 2 = \mathbf{5}$
*   $\tilde{y}[2] = 1(0) + 2(1) + 3(2) = 2 + 6 = \mathbf{8}$

**最终结果**：$\tilde{y}[k] = \{\dots, \underline{5}, 5, 8, \dots\}$。
*(这种方法不仅绝对不会算错下标，而且极大节省了在草稿纸上画图翻转的时间，必考必会！)*