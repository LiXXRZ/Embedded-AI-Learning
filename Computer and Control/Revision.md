### **幻灯片 2 & 3: 问题 1, 第1部分 (Example Question 1, Part 1)**

#### **问题 (Question)**

| English (英文) | Chinese (中文) |
| :--- | :--- |
| By making a number of assumptions concerning friction etc., the movement of a motor vehicle can be represented by the following standard 1st order Transfer Function, **X = [G / (Ts + 1)] \* U** where X is the vehicle speed (mph) and U is the engine force. In this model, the engine force is represented as a scaled value between 0 and 1.0, where 1.0 implies maximum force, 0.5 half of this and so on. | 通过对摩擦力等因素进行一系列假设，机动车的运动可以用以下标准一阶传递函数表示： **X = [G / (Ts + 1)] \* U**。其中 X 是车辆速度（英里/小时），U 是发动机作用力。在此模型中，发动机作用力以 0 到 1.0 之间的比例值表示，其中 1.0 代表最大作用力，0.5 代表其一半，依此类推。 |
| Using the Transfer Function model above, and **T = 5.2 seconds** and **G = 87**, sketch the response of vehicle speed to a step in engine force from zero to 0.5 units. Label your sketch to define the steady state speed and time constant (stating all the relevant numerical values and units). Suggest two limitations of this model. | 使用上述传递函数模型，且 **T = 5.2 秒**，**G = 87**，绘制车辆速度对发动机作用力从 0 到 0.5 单位阶跃变化的响应曲线。在草图上标注稳态速度和时间常数（说明所有相关的数值和单位）。提出此模型的两个局限性。 |

#### **解答 (Solution)**

1.  **计算稳态速度 (Calculate Steady-State Speed):**
    *   稳态速度 (Xss) 是指当时间趋于无穷大 (t → ∞) 或在拉普拉斯域中 s → 0 时的系统响应。
    *   Xss = G * U = 87 * 0.5 = **43.5 mph**

2.  **确定时间常数 (Identify Time Constant):**
    *   时间常数 (T) 已在题目中给出，T = **5.2 秒**。
    *   时间常数代表系统响应达到其最终稳态值 63.2% 所需的时间。
    *   在 T = 5.2 秒时，车速应为: 0.632 * 43.5 mph ≈ 27.5 mph。

3.  **绘制响应曲线 (Sketch the Response):**
    *   该图应显示车辆速度 (X) 随时间 (t) 的变化。
    *   Y轴代表速度，从 0 开始，最终趋近于 43.5 mph 的水平渐近线。
    *   X轴代表时间。
    *   曲线应从原点 (0,0) 开始，呈指数形式上升。
    *   **标注:**
        *   稳态速度: 在 43.5 mph 处画一条水平虚线，并标注 “Steady-state speed = 43.5 mph”。
        *   时间常数: 在时间轴上标记 5.2 秒。在曲线上找到对应的点（速度约为 27.5 mph），并标注 “Time constant T = 5.2 s”。

    

4.  **模型的局限性 (Limitations of the Model):**
    *   **线性假设 (Linearity Assumption):** 该模型是线性的，但现实世界中的车辆动力学是非线性的。例如，空气阻力（风阻）与速度的平方大致成正比，而不是线性关系。
    *   **忽略了其他动态因素 (Ignores Other Dynamics):** 该模型忽略了许多重要因素，如换挡、道路坡度、发动机扭矩曲线、轮胎打滑和延迟（例如涡轮迟滞）等。

***

### **幻灯片 4: 问题 1, 第2部分 (Example Question 1, Part 2)**

#### **问题 (Question)**

| English (英文) | Chinese (中文) |
| :--- | :--- |
| Draw a block diagram of an integral controller applied to the 1st order Transfer Function stated above. Add the following labels: vehicle speed, control input, control model and set point. Use the rules of block diagram analysis to find the closed-loop Transfer Function. Find the steady state gain of the closed-loop Transfer Function and comment on the significance of your answer. The control algorithm is **U = (KI / s) \* (D - X)** where KI is the gain and D the set point. | 绘制一个积分控制器应用于上述一阶传递函数的方框图。添加以下标签：车辆速度、控制输入、控制模型和设定点。使用方框图分析法则求出闭环传递函数。求出闭环传递函数的稳态增益，并评论其意义。控制算法为 **U = (KI / s) \* (D - X)**，其中 KI 是增益，D 是设定点。 |

#### **解答 (Solution)**

1.  **方框图 (Block Diagram):**

    

2.  **求闭环传递函数 (Find Closed-Loop Transfer Function):**
    *   控制器 (Controller): C(s) = KI / s
    *   控制模型/过程 (Process): P(s) = G / (Ts + 1)
    *   闭环传递函数 M(s) 的公式为: M(s) = X(s)/D(s) = C(s)P(s) / [1 + C(s)P(s)]
    *   首先计算 C(s)P(s): (KI / s) * [G / (Ts + 1)] = G\*KI / [s(Ts + 1)]
    *   代入 M(s) 公式:
        M(s) = { G\*KI / [s(Ts + 1)] } / { 1 + G\*KI / [s(Ts + 1)] }
        M(s) = { G\*KI / [s(Ts + 1)] } / { [s(Ts + 1) + G\*KI] / [s(Ts + 1)] }
    *   化简得到: **M(s) = G\*KI / [Ts² + s + G\*KI]**

3.  **求稳态增益及评论 (Find Steady-State Gain and Comment):**
    *   稳态增益是闭环传递函数在 s → 0 时的值。
    *   稳态增益 = lim (s→0) M(s) = G\*KI / [T(0)² + 0 + G\*KI] = G\*KI / G\*KI = **1**
    *   **意义 (Significance):** 稳态增益为 1 意味着在稳态下，系统输出（车辆速度 X）将精确地等于系统输入（设定点 D）。这表明积分控制器成功地消除了稳态误差。对于一个阶跃输入（例如设定一个恒定的巡航速度），该系统可以实现无误差的精确跟踪。

***

### **幻灯片 5: 问题 2, 第1部分 (Example Question 2, Part 1)**

#### **问题 (Question)**

| English (英文) | Chinese (中文) |
| :--- | :--- |
| Consider the following differential equation, where x is the output, u(t) the input and a2, b1, b2 are parameters. **d²x/dt² + a2\*x = b1\*du(t)/dt + b2\*u(t)**. Develop the Transfer Function of the above differential equation. | 考虑以下微分方程，其中 x 是输出，u(t) 是输入，a2、b1、b2 是参数。**d²x/dt² + a2\*x = b1\*du(t)/dt + b2\*u(t)**。推导上述微分方程的传递函数。 |

#### **解答 (Solution)**

1.  对微分方程两边进行拉普拉斯变换 (Take the Laplace Transform)，并假设初始条件为零。
    *   L{d²x/dt²} = s²X(s)
    *   L{a2\*x} = a2\*X(s)
    *   L{b1\*du(t)/dt} = b1\*sU(s)
    *   L{b2\*u(t)} = b2\*U(s)

2.  变换后的方程为:
    s²X(s) + a2\*X(s) = b1\*sU(s) + b2\*U(s)

3.  分别提出 X(s) 和 U(s):
    X(s) \* (s² + a2) = U(s) \* (b1\*s + b2)

4.  传递函数 H(s) 等于输出 X(s) 除以输入 U(s):
    H(s) = X(s) / U(s) = **(b1\*s + b2) / (s² + a2)**

***

### **幻灯片 6: 问题 2, 第2部分 (Example Question 2, Part 2)**

#### **问题 (Question)**

| English (英文) | Chinese (中文) |
| :--- | :--- |
| An engineer proposes to design the following control algorithm, where D is the set point, and Kp, Kv are control gains: **U = Kp(D – X) + KvX**. Draw a block diagram of the control system stated above, as applied to the model found in the first part of this question. | 一位工程师提议设计以下控制算法，其中 D 是设定点，Kp、Kv 是控制增益：**U = Kp(D – X) + KvX**。绘制将上述控制系统应用于本问题第一部分中得到的模型的方框图。 |

#### **解答 (Solution)**

1.  **分析控制算法 (Analyze the Control Algorithm):**
    *   U = Kp(D - X) + KvX 可以展开为 U = Kp\*D - Kp\*X + Kv\*X。
    *   这表示控制输入 U 由三部分组成：一部分与设定点 D 成正比 (Kp\*D)，另外两部分与输出 X 相关 (-Kp\*X 和 +Kv\*X)。

2.  **绘制方框图 (Draw the Block Diagram):**
    *   该系统包含一个从设定点 D 到求和点的前馈路径，以及两条从输出 X 返回的反馈路径。

    

***

### **幻灯片 7: 问题 3 (Example Question 3)**

#### **问题 (Question)**

| English (英文) | Chinese (中文) |
| :--- | :--- |
| Know your control objectives and how they relate to a particular control situation. | 了解你的控制目标以及它们如何与特定的控制情况相关联。 |
| – Stability | – 稳定性 |
| – Tracking | – 跟踪性 |
| – Transient behaviour | – 瞬态行为 |
| – Disturbances | – 扰动 |

#### **解答 (Explanation)**

这是一个概念性问题，要求理解控制系统的核心目标。以车辆巡航控制系统为例：

*   **稳定性 (Stability):** 这是最基本的要求。系统必须是稳定的，意味着当设定一个速度后，车辆的速度会收敛到该设定值，而不是无限制地增加（失控）或持续振荡。不稳定的巡航控制是极其危险的。
*   **跟踪性 (Tracking):** 指的是系统输出（实际车速）跟随输入（期望设定速度）的能力。好的跟踪性意味着当设定速度为 60 mph 时，汽车能快速达到并精确地保持在 60 mph，稳态误差很小或为零。
*   **瞬态行为 (Transient Behaviour):** 描述系统在从一个状态变为另一个状态（例如，将设定速度从 50 mph 提高到 60 mph）时的响应特性。关键指标包括：
    *   **上升时间 (Rise Time):** 响应速度要快。
    *   **超调量 (Overshoot):** 加速时不要过度超过设定速度，否则会带来不舒适的乘坐体验。
    *   **稳定时间 (Settling Time):** 快速进入并保持在新设定速度的允许误差范围内。
*   **扰动抑制 (Disturbance Rejection):** 指的是系统抵抗外部干扰的能力。对于巡航控制，主要的扰动包括：
    *   **道路坡度变化 (Hills):** 在上坡时，系统应能自动增加油门以保持速度；下坡时则应减少油门。
    *   **风阻 (Wind):** 顶风或侧风会影响车速，系统需要能补偿这种影响。
    一个好的控制系统应能在这些扰动存在的情况下，仍能很好地维持设定的速度。