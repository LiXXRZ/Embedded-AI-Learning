### **Lecture Notes: Integral Action**
### **讲义：积分作用**

---

### **1. Recap: The Limitation of Proportional Control**
### **1. 回顾：比例控制的局限性**

Proportional-only control results in a faster system response by increasing the gain (Kp).
单纯的比例控制通过增加增益 (Kp) 来加快系统的响应速度。

However, for a first-order system with a constant disturbance or setpoint, proportional control always results in a **steady-state error**.
然而，对于存在恒定扰动或设定点的一阶系统，比例控制总会导致**稳态误差**。

The steady-state gain is less than unity, meaning the actual output never reaches the desired setpoint.
其稳态增益小于 1，意味着实际输出永远无法达到期望的设定点。

The steady-state error can be reduced by increasing the proportional gain (Kp), but it can never be eliminated completely.
通过增加比例增益 (Kp) 可以减小稳态误差，但永远无法完全消除。

---

### **2. The Integral Control Law**
### **2. 积分控制律**

Integral control is designed to eliminate steady-state error.
积分控制旨在消除稳态误差。

The control input (u) is proportional to the **integral of the error** over time.
控制输入 (u) 与**误差**随时间的**积分**成正比。

This means that as long as there is an error (even a very small one), the integral term will continue to grow, forcing the controller output to change until the error becomes zero.
这意味着只要存在误差（即使是非常小的误差），积分项就会持续增长，迫使控制器输出改变，直到误差变为零。

The integral control law in the time domain is: `u(t) = k_I * ∫e(t) dt`, where e(t) = D - X.
积分控制律在时域中的表达式为：`u(t) = k_I * ∫e(t) dt`，其中 e(t) = D - X。

In the Laplace (s-domain), this is represented as: U(s) = (k_I / s) * E(s) = (k_I / s) * (D - X).
在拉普拉斯（s 域）中，这表示为：U(s) = (k_I / s) * E(s) = (k_I / s) * (D - X)。

The term `k_I` is the integral gain, and `1/s` is the Laplace operator for integration.
术语 `k_I` 是积分增益，`1/s` 是积分的拉普拉斯算子。

---

### **3. Analysis of Integral Control (Ventilation Rate Example)**
### **3. 积分控制分析（通风率示例）**

#### **3.1 Closed-Loop Transfer Function**
#### **3.1 闭环传递函数**

When an integral controller `Gc(s) = k_I / s` is applied to the first-order plant `Gp(s) = 1.5 / (10s + 1)`, the system changes.
当将积分控制器 `Gc(s) = k_I / s` 应用于一阶被控对象 `Gp(s) = 1.5 / (10s + 1)` 时，系统会发生变化。

The open-loop transfer function becomes `G(s) = Gc(s) * Gp(s) = (1.5 * k_I) / (s * (10s + 1))`.
开环传递函数变为 `G(s) = Gc(s) * Gp(s) = (1.5 * k_I) / (s * (10s + 1))`。

Using the standard formula for a unity negative feedback loop, `T(s) = G(s) / (1 + G(s))`, the closed-loop transfer function is:
使用单位负反馈回路的标准公式 `T(s) = G(s) / (1 + G(s))`，闭环传递函数为：
**X(s) / D(s) = 1.5k_I / (10s² + s + 1.5k_I)**
**X(s) / D(s) = 1.5k_I / (10s² + s + 1.5k_I)**

**Important Note:** The introduction of the integral controller has increased the order of the system from first-order to **second-order**.
**重要提示：** 积分控制器的引入将系统的阶数从一阶提升到了**二阶**。

#### **3.2 Steady-State Gain and Error**
#### **3.2 稳态增益与误差**

To find the steady-state response to a step input, we use the Final Value Theorem by setting s = 0 in the transfer function.
为了求得对阶跃输入的稳态响应，我们使用终值定理，在传递函数中令 s = 0。

Steady-State Value: `x(t→∞) = [ 1.5k_I / (10(0)² + (0) + 1.5k_I) ] * D = [ 1.5k_I / 1.5k_I ] * D = D`.
稳态值：`x(t→∞) = [ 1.5k_I / (10(0)² + (0) + 1.5k_I) ] * D = [ 1.5k_I / 1.5k_I ] * D = D`。

The **steady-state gain is unity (1)**.
**稳态增益为 1**。

This means the actual output `x` will perfectly match the desired setpoint `D` at steady state.
这意味着在稳态时，实际输出 `x` 将完美匹配期望的设定点 `D`。

Therefore, **integral control yields zero steady-state error**. This is its primary advantage.
因此，**积分控制产生零稳态误差**。这是它的主要优点。

This property holds true even in the presence of modelling errors and constant disturbances.
即使在存在模型误差和恒定扰动的情况下，这个特性也成立。

#### **3.3 Stability Warning**
#### **3.3 稳定性警告**

While integral control eliminates steady-state error, it can negatively impact system stability.
虽然积分控制消除了稳态误差，但它可能对系统稳定性产生负面影响。

By increasing the system order, integral control can introduce oscillations and, if the gain `k_I` is not chosen carefully, can make the closed-loop system **unstable**.
通过提高系统阶数，积分控制会引入振荡，如果增益 `k_I` 选择不当，可能会使闭环系统**不稳定**。

The benefit of zero steady-state error is only achieved **as long as the closed-loop system is stable**.
只有**在闭环系统稳定的前提下**，才能实现零稳态误差的优点。

---

### **4. Real-World Application: Ramp Metering on Motorways**
### **4. 现实世界应用：高速公路的匝道控制**

Ramp metering is a form of motorway access control that uses traffic lights on entrance ramps.
匝道控制是一种高速公路入口控制形式，它在入口匝道上使用交通信号灯。

The goal is to temporarily delay vehicles entering the motorway to prevent traffic flow breakdown (congestion) on the main carriageway.
其目标是暂时延迟进入高速公路的车辆，以防止主干道上的交通流崩溃（拥堵）。

The industry standard algorithm, ALINEA, is based on integral control. It adjusts the traffic light timing to ensure the traffic density on the motorway tracks a desired setpoint, thus eliminating steady-state error and optimizing flow.
行业标准算法 ALINEA 是基于积分控制的。它通过调整信号灯时序，确保高速公路上的交通密度追踪一个期望的设定点，从而消除稳态误差并优化交通流量。