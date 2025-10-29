### **Part 1: Proportional (P), Integral (I), and Proportional-Integral (PI) Control Actions**
### **第一部分：比例 (P)、积分 (I) 和比例积分 (PI) 控制作用**

#### **1. Proportional (P) Control of Ventilation Rate**
#### **1. 通风率的比例 (P) 控制**

*   **Concept**: In proportional control, the controller output (U, volts) is directly proportional to the error signal (E).
    *   **概念**：在比例控制中，控制器输出（U，电压）与误差信号（E）成正比。
*   **Block Diagram**:
    *   **框图**：
    
    *   *D* is the Desired Airflow (set point).
        *   *D* 是期望气流（设定点）。
    *   *X* is the actual Airflow.
        *   *X* 是实际气流。
    *   *E* is the error, calculated as *E = D - X*.
        *   *E* 是误差，计算公式为 *E = D - X*。
    *   *k<sub>p</sub>* is the Proportional Gain.
        *   *k<sub>p</sub>* 是比例增益。
    *   *U* is the control signal (Volts) sent to the system.
        *   *U* 是发送给系统的控制信号（电压）。
    *   The Control Model (plant) has a transfer function of `1.5 / (10s + 1)`.
        *   控制模型（被控对象）的传递函数为 `1.5 / (10s + 1)`。
*   **Key Characteristic**: The steady-state gain of the closed-loop system with P control is less than unity.
    *   **主要特点**：使用P控制的闭环系统的稳态增益小于1。
*   **Major Disadvantage**: This results in a **steady-state error**, meaning the actual ventilation rate will always be less than the desired rate at steady state.
    *   **主要缺点**：这会导致**稳态误差**，意味着在稳态下，实际通风率将始终低于期望速率。
    
    *   As shown in the graph, the 'actual ventilation' curve never reaches the 'desired ventilation' line.
        *   如图所示，“实际通风”曲线永远不会达到“期望通风”线。

#### **2. Integral (I) Control of Ventilation Rate**
#### **2. 通风率的积分 (I) 控制**

*   **Concept**: In integral control, the controller's output is proportional to the integral of the error signal over time. The transfer function for the integral controller is *k<sub>I</sub> / s*.
    *   **概念**：在积分控制中，控制器的输出与误差信号随时间的积分成正比。积分控制器的传递函数是 *k<sub>I</sub> / s*。
*   **Block Diagram**:
    *   **框图**：
    
*   **Key Characteristic**: The steady-state gain of the closed-loop system is unity.
    *   **主要特点**：闭环系统的稳态增益为1。
*   **Major Advantage**: The output tracks the set point, resulting in **zero steady-state error**, as long as the system remains stable.
    *   **主要优点**：只要系统保持稳定，输出就会跟踪设定点，从而实现**零稳态误差**。
    
    *   The graph shows the 'actual ventilation' eventually reaches the 'desired' set point.
        *   该图显示“实际通风”最终达到了“期望”设定点。

#### **3. Proportional + Integral (PI) Control of Ventilation Rate**
#### **3. 通风率的比例积分 (PI) 控制**

*   **Goal**: To combine the advantages of both P and I control actions.
    *   **目标**：结合P控制和I控制的优点。
*   **Advantages Combined**: It aims for a **fast** response (from P control) and **steady-state tracking** (zero steady-state error from I control).
    *   **结合的优点**：它旨在实现**快速**响应（来自P控制）和**稳态跟踪**（来自I控制的零稳态误差）。
*   **Control Structure**: The P and I blocks are arranged in 'parallel'.
    *   **控制结构**：P和I模块是“并联”排列的。
    
*   **Control Law**: The control signal *U* is the sum of the proportional and integral actions.
    *   **控制律**：控制信号 *U* 是比例作用和积分作用的总和。
    `U = (k_p + k_I / s) * (D - X)` or `U = ((k_p * s + k_I) / s) * (D - X)`
*   **Tuning**: The control engineer must choose suitable values for both control gains (*k<sub>I</sub>* and *k<sub>p</sub>*) to achieve the desired performance.
    *   **整定**：控制工程师必须为两个控制增益（*k<sub>I</sub>* 和 *k<sub>p</sub>*）选择合适的值，以达到预期的性能。
*   **Closed-Loop Transfer Function Derivation**:
    *   **闭环传递函数推导**：
    1.  Combine the PI controller and the plant model into a single block, G<sub>1</sub>.
        *   将PI控制器和被控对象模型合并成一个单独的模块 G<sub>1</sub>。
        G<sub>1</sub> = `((1.5 * k_I + 1.5 * k_p * s) / (10s^2 + s))`
    2.  Use the standard feedback rule to find the closed-loop transfer function.
        *   使用标准反馈法则来找到闭环传递函数。
        `X/D = G_1 / (1 + G_1)`

---

### **Part 2: Control Applications and Examples**
### **第二部分：控制应用与实例**

#### **1. Proportional Control of a DC Motor**
#### **1. 直流电机的比例控制**

*   **Problem**: Standard P control results in a significant steady-state error.
    *   **问题**：标准的P控制会导致显著的稳态误差。
    
*   **Solution: Proportional Control with Command Gain (K<sub>d</sub>)**
    *   **解决方案：带指令增益 (K<sub>d</sub>) 的比例控制**
    *   An 'open-loop' design element is added to scale the desired speed *D* before it's compared with the actual speed *X*.
        *   在期望速度 *D* 与实际速度 *X* 进行比较之前，增加了一个“开环”设计元素来对其进行缩放。
    *   This design depends on having an accurate model of the plant.
        *   这种设计依赖于拥有一个精确的被控对象模型。
    
*   **Exercise**: Derive a value for K<sub>d</sub> that ensures steady-state tracking.
    *   **练习**：推导出一个能确保稳态跟踪的 K<sub>d</sub> 值。
    *   **Solution**: If the steady-state gain of the plant is G, the value for K<sub>d</sub> is:
        *   **解**：如果被控对象的稳态增益为 G，则 K<sub>d</sub> 的值为：
        `K_d = (1 + K_p * G) / (K_p * G)`
*   **Result**: With the command gain, the system achieves zero steady-state error.
    *   **结果**：通过指令增益，系统实现了零稳态误差。
    
*   **Limitation**: This method is not robust to disturbances. A load disturbance will still cause an error.
    *   **局限性**：这种方法对扰动不具有鲁棒性。负载扰动仍然会导致误差。
    

#### **2. Integral (I) and PI Control of a DC Motor**
#### **2. 直流电机的积分 (I) 和比例积分 (PI) 控制**

*   **Integral Control**: Eliminates steady-state error and is robust to disturbances, but can be sluggish or oscillatory.
    *   **积分控制**：消除稳态误差并且对扰动具有鲁棒性，但响应可能迟缓或产生振荡。
*   **PI Control**: Provides a better balance, achieving zero steady-state error, good disturbance rejection, and a faster response compared to I-only control.
    *   **PI 控制**：提供了更好的平衡，实现了零稳态误差、良好的扰动抑制，并且与纯积分控制相比响应更快。

#### **3. PI Control of a Hydraulic Piling Rig (Model-Based Control)**
#### **3. 液压打桩机的 PI 控制（基于模型的控制）**

This example demonstrates how to mathematically determine controller gains instead of using trial-and-error.
这个例子展示了如何通过数学方法确定控制器增益，而不是使用试错法。

1.  **Define the System Model**: The rig is modeled with a first-order transfer function.
    *   **定义系统模型**：该打桩机被建模为一阶传递函数。
    `X/U = b_0 / (s + a_1)`
2.  **Define the Desired Behavior**: A desired closed-loop differential equation (and its corresponding transfer function) is specified.
    *   **定义期望行为**：指定一个期望的闭环微分方程（及其对应的传递函数）。
    `X/D = p_3 / (s^2 + p_1*s + p_2)`
3.  **Calculate the Actual Closed-Loop Transfer Function**: For the system with a PI controller, this is:
    *   **计算实际闭环传递函数**：对于带PI控制器的系统，其传递函数为：
    `X/D = (k_I*b_0 + k_p*b_0*s) / (s^2 + (a_1 + k_p*b_0)*s + k_I*b_0)`
4.  **Match Coefficients**: By comparing the denominators of the desired and actual transfer functions, we can solve for the gains *k<sub>p</sub>* and *k<sub>I</sub>*.
    *   **系数匹配**：通过比较期望和实际传递函数的分母，我们可以求解增益 *k<sub>p</sub>* 和 *k<sub>I</sub>*。
    *   `k_I * b_0 = p_2`  =>  `k_I = p_2 / b_0`
    *   `a_1 + k_p * b_0 = p_1`  =>  `k_p = (p_1 - a_1) / b_0`

---

### **Part 3: Summary and Future Topics**
### **第三部分：总结与未来主题**

#### **Control System Design Summary**
#### **控制系统设计总结**

| Design Stage | Description | Details |
| :--- | :--- | :--- |
| **阶段** | **描述** | **详情** |
| 1. Choose Control Structure | Select the appropriate algorithm. | P, I, PI, PD, PID, or Advanced Methods. |
| 1. 选择控制结构 | 选择合适的算法。 | P, I, PI, PD, PID, 或高级方法。 |
| 2. Tune Control Gains | Tune gains (*k<sub>p</sub>*, *k<sub>I</sub>*, etc.) to meet objectives. | Can be done via: Trial & Error (on real system or simulation), Frequency domain methods, or Model-based methods. |
| 2. 整定控制增益 | 整定增益 (*k<sub>p</sub>*, *k<sub>I</sub>* 等) 以满足目标。 | 可通过以下方式完成：试错法（在真实系统或仿真中）、频域法、或基于模型的方法。 |

#### **Future Topics in Control**
#### **控制领域的未来主题**

*   **Adaptive Control**: Control characteristics (gains) are adjusted on-line (adaptively) to respond to changes in the system, like fuel consumption in an aircraft. It's more complex than fixed-gain control.
    *   **自适应控制**：控制特性（增益）在线进行调整（自适应），以响应系统中的变化，例如飞机的燃油消耗。它比固定增益控制更复杂。
*   **Robust Control**: A design method focused on the reliability (robustness) of the controller. It is typically based on a worst-case scenario to ensure the system works in a practical situation, though it may not be optimal under normal conditions. There is a trade-off between **Performance** and **Robustness**.
    *   **鲁棒控制**：一种专注于控制器可靠性（鲁棒性）的设计方法。它通常基于最坏情况场景，以确保系统在实际情况下能够工作，尽管在正常条件下可能不是最优的。在**性能**和**鲁棒性**之间存在权衡。
*   **Predictive Control**: Uses a model to predict the future output of a system. The controller then generates optimal input signals for the future. This optimization is repeated at each sampling instant (this is called a receding horizon).
    *   **预测控制**：使用一个模型来预测系统的未来输出。然后控制器为未来生成最优的输入信号。这种优化在每个采样时刻重复进行（这被称为滚动时域）。