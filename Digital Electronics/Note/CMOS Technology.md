### **Fundamentals of Digital Electronics - COMS Technology**

---

#### **1. Digital Logic Families (数字逻辑系列)**

*   **Hierarchy of Digital Systems (数字系统的层级结构)**
    *   Digital systems (like a laptop) are built from digital integrated circuits (ICs on a motherboard). These ICs are composed of digital building blocks (logic gates). The fundamental components of these logic gates are analog devices, primarily transistors.
    *   数字系统（如笔记本电脑）由数字集成电路（主板上的IC）构成。这些IC由数字构建模块（逻辑门）组成。而这些逻辑门最基本的组件是模拟器件，主要是晶体管。

*   **Definition of Digital Logic Family (数字逻辑系列的定义)**
    *   The specific circuit technology used for the design of digital integrated circuits is referred to as a digital logic family.
    *   用于设计数字集成电路的特定电路技术，被称为一个数字逻辑系列。

*   **Major Logic Families (主要逻辑系列)**
    *   **TTL (Transistor-Transistor Logic):** Uses Bipolar Junction Transistors (BJTs). It was historically significant but is now largely replaced by CMOS.
    *   **TTL (晶体管-晶体管逻辑):** 使用双极结型晶体管 (BJT)。它在历史上非常重要，但现在大部分已被CMOS取代。
    *   **CMOS (Complementary Metal-Oxide Semiconductor):** Uses MOSFETs (Metal-Oxide-Semiconductor Field-Effect Transistors). It is the dominant technology for modern digital electronics due to its low power consumption.
    *   **CMOS (互补金属氧化物半导体):** 使用MOSFET（金属氧化物半导体场效应晶体管）。由于其极低的功耗，它已成为现代数字电子学的主导技术。

*   **Comparison of Logic Families (逻辑系列比较)**
    | Technology (Device Type) 技术 (器件类型) | Power Consumption 功耗 | Speed 速度 | Packaging 集成度 |
    | :--- | :--- | :--- | :--- |
    | RTL (Bipolar junction) | High (高) | Low (低) | Discrete (分立) |
    | DTL (Bipolar junction) | High (高) | Low (低) | Discrete, SSI (小规模) |
    | TTL (Bipolar junction) | Medium (中) | Medium (中) | SSI, MSI (中小规模) |
    | ECL (Bipolar junction) | High (高) | High (高) | SSI, MSI, LSI (中小大规模) |
    | pMOS (MOSFET) | Medium (中) | Low (低) | MSI, LSI (中大规模) |
    | nMOS (MOSFET) | Medium (中) | Medium (中) | MSI, LSI, VLSI (中大/超大规模) |
    | **CMOS (MOSFET)** | **Low (低)** | **Medium (中)** | **SSI, MSI, LSI, VLSI (全范围)** |
    | GaAs (MOSFET) | High (高) | High (高) | SSI, MSI, LSI (中小大规模) |

---

#### **2. In-depth on CMOS Technology (深入理解CMOS技术)**

*   **MOSFET: The Building Block (MOSFET: 基本构建单元)**
    *   CMOS logic is built using two types of MOSFETs: n-channel (nMOS) and p-channel (pMOS).
    *   CMOS逻辑由两种类型的MOSFET构成：n沟道 (nMOS) 和 p沟道 (pMOS)。

*   **nMOS Transistor Operation (nMOS 晶体管工作原理)**
    *   **Structure:** Has N-type source and drain regions in a P-type substrate.
    *   **结构:** 在P型衬底上构建N型的源极和漏极。
    *   **Activation:** When a **positive voltage (Logic '1')** is applied to the gate, it attracts electrons to the region under the gate, forming a conductive channel between the source and drain. The transistor turns **ON**.
    *   **激活:** 当一个**正电压（逻辑'1'）**施加到栅极时，它会吸引电子到栅极下方的区域，在源极和漏极之间形成一个导电沟道。晶体管**导通 (ON)**。
    *   **Analogy:** It acts like a switch that is **closed** when the input is '1'.
    *   **类比:** 像一个当输入为'1'时**闭合**的开关。

*   **pMOS Transistor Operation (pMOS 晶体管工作原理)**
    *   **Structure:** Has P-type source and drain regions in an N-type substrate.
    *   **结构:** 在N型衬底上构建P型的源极和漏极。
    *   **Activation:** When a **zero or ground voltage (Logic '0')** is applied to the gate, it attracts holes to the region under the gate, forming a conductive channel. The transistor turns **ON**.
    *   **激活:** 当一个**零电压或接地（逻辑'0'）**施加到栅极时，它会吸引空穴到栅极下方的区域，形成导电沟道。晶体管**导通 (ON)**。
    *   **Analogy:** It acts like a switch that is **closed** when the input is '0'.
    *   **类比:** 像一个当输入为'0'时**闭合**的开关。

*   **The "Complementary" Nature (“互补”的特性)**
    *   CMOS technology pairs one nMOS and one pMOS transistor in a complementary fashion. For any given input, one transistor is ON while the other is OFF. This is the key to its low power consumption.
    *   CMOS技术将一个nMOS和一个pMOS晶体管以互补的方式配对。对于任何给定的输入，总是一个晶体管导通，而另一个则截止。这是其低功耗的关键。

---

#### **3. Logic Gates from Transistors: The NOT Gate Example (用晶体管构建逻辑门：以反相器为例)**

A CMOS NOT gate (inverter) consists of one pMOS and one nMOS transistor.
一个CMOS反相器由一个pMOS和一个nMOS晶体管组成。

*   **Case 1: Input (X) is 0 (LOW)**
    *   The low voltage on the gate turns the **pMOS transistor ON**.
    *   The low voltage on the gate turns the **nMOS transistor OFF**.
    *   The output (F) is connected to the high voltage supply (VDD) through the conducting pMOS.
    *   **Result: Output (F) is 1 (HIGH).**
*   **情况1：输入 (X) 为 0 (低电平)**
    *   栅极上的低电压使 **pMOS 晶体管导通**。
    *   栅极上的低电压使 **nMOS 晶体管截止**。
    *   输出 (F) 通过导通的pMOS连接到高电压源 (VDD)。
    *   **结果：输出 (F) 为 1 (高电平)。**

*   **Case 2: Input (X) is 1 (HIGH)**
    *   The high voltage on the gate turns the **pMOS transistor OFF**.
    *   The high voltage on the gate turns the **nMOS transistor ON**.
    *   The output (F) is connected to Ground (GND) through the conducting nMOS.
    *   **Result: Output (F) is 0 (LOW).**
*   **情况2：输入 (X) 为 1 (高电平)**
    *   栅极上的高电压使 **pMOS 晶体管截止**。
    *   栅极上的高电压使 **nMOS 晶体管导通**。
    *   输出 (F) 通过导通的nMOS连接到地 (GND)。
    *   **结果：输出 (F) 为 0 (低电平)。**

---

#### **4. Electrical Aspects of Logic Gates (逻辑门的电气特性)**

##### **4.1 Electrical Compatibility (电气兼容性)**

*   **Logic Abstraction (逻辑抽象):** In physical circuits, logic '0' and '1' are represented by voltage ranges.
    *   **LOW Range:** A range of low voltages interpreted as logic 0.
    *   **HIGH Range:** A range of high voltages interpreted as logic 1.
    *   **Forbidden Zone:** An intermediate voltage range that is not guaranteed to be interpreted correctly. Circuits should transition through this zone quickly.
*   **逻辑抽象:** 在物理电路中，逻辑'0'和'1'由电压范围表示。
    *   **低电平范围:** 被解释为逻辑0的一段低电压范围。
    *   **高电平范围:** 被解释为逻辑1的一段高电压范围。
    *   **禁用区:** 介于两者之间的电压范围，不保证能被正确识别。电路应快速通过此区域。

*   **Noise Margin (噪声容限):** A measure of a circuit's immunity to voltage noise. To ensure a signal from one gate is correctly read by the next, the output voltage ranges must be more stringent than the required input ranges.
    *   `VOH`: Minimum output voltage when the output is HIGH.
    *   `VOL`: Maximum output voltage when the output is LOW.
    *   `VIH`: Minimum input voltage to be recognized as HIGH.
    *   `VIL`: Maximum input voltage to be recognized as LOW.
*   **噪声容限:** 衡量电路抵抗电压噪声能力的指标。为确保一个门的输出能被下一个门正确读取，输出电压范围必须比要求的输入电压范围更严格。
    *   `VOH`: 输出为高电平时，保证的最低输出电压。
    *   `VOL`: 输出为低电平时，保证的最高输出电压。
    *   `VIH`: 输入被识别为高电平时，要求的最低输入电压。
    *   `VIL`: 输入被识别为低电平时，要求的最高输入电压。

    *   **Compatibility Requirement:** `VOH > VIH` and `VOL < VIL`.
    *   **兼容性要求:** `VOH > VIH` 且 `VOL < VIL`。
    *   **High Noise Margin (高电平噪声容限):** `NMH = VOH - VIH`
    *   **Low Noise Margin (低电平噪声容限):** `NML = VIL - VOL`

##### **4.2 Speed Characteristics (速度特性)**

*   **Transition Time (`tr`, `tf`):** The time a signal takes to switch between logic levels, typically measured from 10% to 90% of its final value for a rising edge (`tr`) or 90% to 10% for a falling edge (`tf`).
*   **转换时间 (`tr`, `tf`):** 信号在逻辑电平间切换所需的时间，通常上升沿 (`tr`) 从最终值的10%测量到90%，下降沿 (`tf`) 从90%测量到10%。

*   **Propagation Delay (`t_p`):** The time it takes for a change at the input of a gate to cause a change at its output.
    *   `t_PLH`: Propagation delay for the output to go from Low to High.
    *   `t_PHL`: Propagation delay for the output to go from High to Low.
*   **传播延迟 (`t_p`):** 门的输入变化到其输出产生相应变化所需的时间。
    *   `t_PLH`: 输出从低电平变为高电平的传播延迟。
    *   `t_PHL`: 输出从高电平变为低电平的传播延迟。

*   **Critical Path and Circuit Delay (关键路径与电路延迟)**
    *   **Critical Path:** The path through a combinatorial circuit with the longest total propagation delay.
    *   **关键路径:** 组合逻辑电路中，具有最长总传播延迟的路径。
    *   **Circuit Delay:** The delay of the critical path. This determines the maximum operational frequency of the circuit (`f_max ≈ 1 / t_critical_path`).
    *   **电路延迟:** 关键路径的延迟。它决定了电路的最高工作频率 (`f_max ≈ 1 / t_critical_path`)。

##### **4.3 Power Consumption (功耗)**

*   **Static Power Dissipation (静态功耗)**
    *   Power consumed when the output is not changing.
    *   In CMOS, this is extremely low because in any steady state, either the pMOS or nMOS network is off, preventing a direct path from VDD to GND. Power is only consumed by tiny leakage currents (`I_DD`).
    *   Formula: `P_static = I_DD * V_DD`
*   **静态功耗**
    *   电路输出不变化时消耗的功率。
    *   在CMOS中，此功耗极低，因为在任何稳定状态下，pMOS或nMOS网络总有一个是关闭的，避免了从VDD到GND的直接通路。功耗仅由微小的泄漏电流 (`I_DD`) 引起。
    *   公式: `P_static = I_DD * V_DD`

*   **Dynamic Power Dissipation (动态功耗)**
    *   Power consumed during state transitions (when the circuit is switching). This is the dominant component of power consumption in CMOS.
    *   It arises from the charging and discharging of the load capacitance (C) of transistors and wires.
    *   Formula: `P_dynamic = α * C * V_DD² * f`
        *   `α`: Activity factor (how often, on average, the output switches).
        *   `C`: Average load capacitance.
        *   `V_DD`: Power supply voltage.
        *   `f`: Switching frequency.
    *   Note the quadratic dependence on `V_DD`, making voltage scaling a very effective power reduction technique.
*   **动态功耗**
    *   电路在状态转换（开关）期间消耗的功率。这是CMOS功耗的主要来源。
    *   它源于对晶体管和导线的负载电容(C)进行充放电。
    *   公式: `P_dynamic = α * C * V_DD² * f`
        *   `α`: 活动因子 (输出平均开关的频繁程度)。
        *   `C`: 平均负载电容。
        *   `V_DD`: 电源电压。
        *   `f`: 开关频率。
    *   注意功耗与 `V_DD` 的平方成正比，这使得降低电压成为一种非常有效的节能技术。

---

#### **5. Summary (总结)**

This lecture introduced:
*   **Logic families and CMOS technology:** Understanding the foundation of modern digital circuits.
*   **How to build logic gates from transistors:** The fundamental principle of digital circuit design.
*   **Electrical aspects of logic gates:** Key metrics for performance and reliability, including **electrical compatibility (noise margin)**, **speed (delay)**, and **power consumption**.

本讲介绍了：
*   **逻辑系列与CMOS技术:** 理解现代数字电路的基础。
*   **如何用晶体管构建逻辑门:** 数字电路设计的基本原理。
*   **逻辑门的电气特性:** 衡量性能与可靠性的关键指标，包括**电气兼容性 (噪声容限)**、**速度 (延迟)** 和 **功耗**。