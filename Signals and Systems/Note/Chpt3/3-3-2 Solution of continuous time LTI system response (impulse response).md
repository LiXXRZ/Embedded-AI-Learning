# 连续 LTI 系统冲激响应 $h(t)$ 复习笔记

## 一、 冲激响应的定义 (Definition)

### 1. 物理定义
*   **条件**：系统初始状态为 **零** (Zero State)。
*   **激励**：输入信号为单位冲激信号 $\delta(t)$。
*   **响应**：此时系统的零状态响应即为冲激响应，记为 $h(t)$。
    $$ \delta(t) \longrightarrow \boxed{\text{连续LTI系统}} \longrightarrow h(t) $$

### 2. 特性
*   $h(t)$ 反映了连续 LTI 系统的时域特性。
*   它仅取决于系统本身的结构和参数（特征根），与输入信号无关。

### 3. 数学描述
若系统由线性常系数微分方程描述：
$$ y^{(n)}(t) + \dots + a_0 y(t) = b_m x^{(m)}(t) + \dots + b_0 x(t) $$
则 $h(t)$ 满足：
$$ h^{(n)}(t) + \dots + a_0 h(t) = b_m \delta^{(m)}(t) + \dots + b_0 \delta(t) $$
*   **注意**：当 $t > 0$ 时，$\delta(t)$ 及其导数均为 0，方程变为齐次方程。因此，$t > 0$ 时 $h(t)$ 的形式由齐次解（特征根）决定。

---

## 二、 冲激响应的求解：冲激平衡法 (Impulse Balancing Method)

这是求解 $h(t)$ 的核心方法，通过平衡方程两边的奇异函数项（$\delta(t)$ 及其导数）来确定系数。

### 1. 判别阶数
设微分方程左端（输出 $y$）最高阶数为 $n$，右端（输入 $x$）最高阶数为 $m$。

### 情况 A：$n > m$ (真分式系统)
*   **特点**：$h(t)$ 中不包含 $\delta(t)$ 及其导数项，仅由特征根决定的模态项组成。
*   **通解形式**（设为单实根）：
    $$ h(t) = \left( \sum_{i=1}^{n} K_i e^{s_i t} \right) u(t) $$
*   **解题步骤**：
    1.  求特征根 $s_i$。
    2.  设 $h(t) = A e^{s t} u(t)$。
    3.  代入微分方程，利用 $\delta(t)$ 平衡系数。

    > **【例题 1】** $y'(t) + 3y(t) = 2x(t)$
    > 1.  **特征根**：$s + 3 = 0 \Rightarrow s = -3$。
    > 2.  **设解**：$h(t) = A e^{-3t} u(t)$。
    > 3.  **求导**：$h'(t) = -3A e^{-3t} u(t) + A e^{-3t} \delta(t) = -3A e^{-3t} u(t) + A \delta(t)$。
    > 4.  **代入方程**：
    >     $[ -3A e^{-3t} u(t) + A \delta(t) ] + 3 [ A e^{-3t} u(t) ] = 2 \delta(t)$
    >     化简得：$A \delta(t) = 2 \delta(t) \Rightarrow A = 2$。
    > 5.  **结果**：$h(t) = 2 e^{-3t} u(t)$。

### 情况 B：$n \le m$ (假分式系统)
*   **特点**：方程右边出现了输入的高阶导数，导致 $h(t)$ 中不仅有指数项，还必须包含 $\delta(t)$ 及其导数项，才能平衡方程两边。
*   **通解形式**：
    $$ h(t) = \underbrace{\left( \sum_{i=1}^{n} K_i e^{s_i t} \right) u(t)}_{\text{固有分量}} + \underbrace{\sum_{j=0}^{m-n} A_j \delta^{(j)}(t)}_{\text{冲激项}} $$
*   **解题步骤**：需假设 $h(t)$ 包含 $B\delta(t)$ 等项，代入方程平衡系数。

    > **【例题 2】** $y'(t) + 3y(t) = 2x(t) + x'(t)$
    > *   这里 $n=1, m=1$，即 $n=m$，故 $h(t)$ 中包含 $\delta(t)$。
    > 1.  **特征根**：$s = -3$。
    > 2.  **设解**：$h(t) = A e^{-3t} u(t) + B \delta(t)$。
    > 3.  **求导 $h'(t)$**：
    >     利用公式 $[f(t)\delta(t)]' = f(0)\delta'(t) + \dots$，
    >     $h'(t) = (-3A e^{-3t} u(t) + A \delta(t)) + B \delta'(t)$。
    > 4.  **代入方程** $h' + 3h = 2\delta + \delta'$：
    >     $\left[ -3A e^{-3t} u(t) + A \delta(t) + B \delta'(t) \right] + 3 \left[ A e^{-3t} u(t) + B \delta(t) \right] = 2\delta(t) + \delta'(t)$
    > 5.  **合并同类项**：
    >     $\delta'(t)$ 项系数：$B = 1$
    >     $\delta(t)$ 项系数：$A + 3B = 2 \Rightarrow A + 3 = 2 \Rightarrow A = -1$
    > 6.  **结果**：$h(t) = -e^{-3t} u(t) + \delta(t)$。

---

## 三、 总结：通用公式 (General Formulas)

连续 LTI 系统的微分方程：
$$ \sum_{k=0}^{n} a_k y^{(k)}(t) = \sum_{k=0}^{m} b_k x^{(k)}(t) $$

1.  **当 $n > m$ (且特征根为单实根)**：
    $$ h(t) = \left( \sum_{i=1}^{n} K_i e^{s_i t} \right) u(t) $$
    *   系数 $K_i$ 通过冲激平衡法求得。

2.  **当 $n \le m$**：
    $$ h(t) = \left( \sum_{i=1}^{n} K_i e^{s_i t} \right) u(t) + \sum_{j=0}^{m-n} A_j \delta^{(j)}(t) $$
    *   $u(t)$ 前的指数形式由特征方程的根决定。
    *   $\delta(t)$ 及其导数项由方程两边最高阶导数的平衡决定。

## 四、 核心考点提示
1.  **不要忘记 $u(t)$**：$h(t)$ 是因果信号，必须写上 $u(t)$ 或注明 $t>0$。
2.  **求导细节**：在对 $A e^{st} u(t)$ 求导时，根据乘积法则，会产生 $A e^{st} \delta(t)$，即 $A \delta(t)$。这是冲激平衡法的关键来源。
3.  **判断是否有 $\delta(t)$**：观察微分方程右边 $x(t)$ 的最高阶导数阶数是否 $\ge$ 左边 $y(t)$ 的最高阶数。如果是，解中必含 $\delta$。