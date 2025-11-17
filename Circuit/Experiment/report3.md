### **Laboratory Report**

**Course:** Circuit Analysis
**Experiment No:** 3
**Experiment Title:** Wheatstone Bridge Analysis and Differential Amplifier

**Name:** `李鹏麒`
**Student ID:** `24721015`
**Lab Partner(s):** `郭庆杰`
**Date of Experiment:** `25/11/14`

---

### **Abstract**

This experiment was designed to build, test, and characterize a Wheatstone bridge circuit and understand its application in precision measurements. The experiment was divided into two main parts. In Part I, a basic Wheatstone bridge was constructed to verify its balancing principles and output characteristics. In Part II, a differential amplifier, built using an LM324 operational amplifier, was integrated with the bridge to amplify the small voltage signal resulting from a slight resistance change. This report presents a comprehensive analysis comparing theoretical calculations with practical measurements, validating the underlying principles and discussing the sources of error between theoretical and experimental results.

---

### **1. Introduction and Objectives**

#### **1.1 Background**
The Wheatstone bridge is a fundamental electrical circuit used for the precise measurement of an unknown electrical resistance by balancing two legs of a bridge circuit. It is highly effective at converting small changes in resistance, capacitance, or inductance into a measurable voltage output. This capability makes it indispensable in sensor applications, such as strain gauges, thermistors, and photoresistors, for measuring physical quantities like force, pressure, and temperature. However, the output voltage from a slightly unbalanced bridge is often in the millivolt or microvolt range, which is too small for direct processing. Therefore, a high-gain differential amplifier is typically required to amplify this signal to a usable level.

#### **1.2 Objectives**
1.  To understand the operating principles of a Wheatstone bridge and experimentally verify its balance condition.
2.  To learn how to use a differential amplifier to amplify the weak output signal from a Wheatstone bridge.
3.  To characterize a complete resistance-sensing measurement system by integrating theoretical derivation, circuit simulation, and physical circuit measurement.
4.  To analyze experimental data, identify sources of error between theoretical and measured values, and evaluate the performance of the amplifier circuit.

---

### **2. Pre-Lab: Theoretical Analysis**

#### **2.1 Wheatstone Bridge Principle**

**a) General Formula for Output Voltage**
The Wheatstone bridge (Figure 1) consists of two parallel voltage dividers. The voltages at nodes A ($V_A$) and B ($V_B$) are given by:
$V_A = V_{in} \cdot \frac{R_2}{R_1 + R_2}$
$V_B = V_{in} \cdot \frac{R_3}{R_3 + R_4}$

The output voltage $V_{out}$ is the potential difference between A and B:
$V_{out} = V_A - V_B = V_{in} \left( \frac{R_2}{R_1 + R_2} - \frac{R_3}{R_3 + R_4} \right) \quad (1)$

<center>
<img src="https://youke1.picui.cn/s1/2025/11/17/691a97cf0314f.png" width="40%" alt="Figure 1">

<b>Figure 1: Typical Wheatstone Bridge Circuit</b>
</center>

**b) Bridge Balance Condition**
When the bridge is balanced, $V_{out} = 0$. Since $V_{in} \neq 0$, the condition must be:
$\frac{R_2}{R_1 + R_2} = \frac{R_3}{R_3 + R_4}$
Cross-multiplying and simplifying yields the balance condition:
$R_1 R_3 = R_2 R_4 \quad (2)$

**c) Quarter-Bridge Unbalanced Analysis**
Assuming $R_1 = R_2 = R_3 = R$ and a small change in $R_4$ such that $R_4 = R + \Delta R$. Substituting into Equation (1) and simplifying gives:
$V_{out} = V_{in} \left( \frac{\Delta R}{4R + 2\Delta R} \right)$
For precision sensing, the change $\Delta R$ is much smaller than $R$ ($\Delta R \ll R$), so the $2\Delta R$ term in the denominator can be neglected. This simplifies to:
$V_{out} \approx \frac{V_{in}}{4} \frac{\Delta R}{R} \quad (3)$

#### **2.2 Differential Amplifier Principle**

For the ideal differential amplifier shown in Figure 2, the "virtual short" and "virtual open" properties of the op-amp ($V_+ = V_-$, input current is zero) are used.

<center>
<img src="https://youke1.picui.cn/s1/2025/11/17/691a97cf0448b.png" width="50%" alt="Figure 2">

<b>Figure 2: Typical Differential Amplifier Circuit</b>
</center>

With the resistor ratio condition $R_7/R_6 = R_9/R_8$, the output voltage can be derived as:
$V_{out} = \frac{R_7}{R_6} (V_2 - V_1) \quad (4)$
The voltage gain, $G$, is defined as:
$G = \frac{R_7}{R_6} \quad (5)$

---

### **3. Experimental Procedure**

#### **3.1 Equipment and Components**
*   DC Power Supply
*   Digital Multimeter (DMM)
*   Breadboard
*   Resistors: 390Ω (5), 47kΩ (2), 220kΩ (2), and one unknown small resistor for simulating $\Delta R$.
*   Operational Amplifier: LM324
*   Connecting Wires

#### **3.2 Circuit Construction**

**Part 1: Wheatstone Bridge**
1.  **Component Measurement:** The actual resistance of all 390Ω resistors was precisely measured using a DMM. Four resistors with the closest values were selected for the bridge arms.
2.  **Circuit Assembly:** The Wheatstone bridge was constructed on a breadboard as per the lab manual's schematic. The fifth 390Ω resistor ($R_5$) was placed between the output terminals A and B.
3.  **Measurement:** A 5V DC supply was connected. The DMM, in ammeter mode, was connected in series with each branch to measure the currents $I_1$ through $I_5$.

<center>
<img src="https://youke1.picui.cn/s1/2025/11/17/691a98d906282.jpg" width="30%" alt="Figure 3">

<b>Figure 3: Photograph of the Physical Wheatstone Bridge Circuit</b>
</center>

**Part 2: Sensing Circuit with Differential Amplifier**
1.  **Component Measurement:** The actual resistances of $R_6, R_7, R_8, R_9$ (47kΩ and 220kΩ) were measured.
2.  **Circuit Assembly:** The full sensing circuit was constructed according to the lab manual's Figure 4, connecting the output of the Wheatstone bridge to the inputs of the differential amplifier.
3.  **Power & Measurement:** The circuit was powered with +5V for the bridge and ±12V for the LM324 op-amp.
    *   The DMM was used to measure the bridge's output voltage $V_{out(bridge)}$ (pre-amplification).
    *   The DMM was then used to measure the final output voltage of the differential amplifier, $V_{out(amp)}$ (post-amplification).

<center>
<img src="https://youke1.picui.cn/s1/2025/11/17/691a98d8ee2dc.jpg" width="30%" alt="Figure 4">

<b>Figure 4: The Complete Sensing Circuit with Differential Amplifier</b>
</center>

---

### **4. Results and Analysis**

#### **4.1 Part 1: Wheatstone Bridge Analysis**

The measured resistances were used to theoretically calculate the expected currents, which were then compared to the measured currents.

**Table 1: Resistor Measurement and Current Comparison**
| Resistor | Measured Resistance (Ω) | Measured Current (mA) | Calculated Current (mA) | Error (%) |
|:---:|:---:|:---:|:---:|:---:|
| $R_1$ | 387 | 6.468 | 6.41 | 0.905 |
| $R_2$ | 383 | 6.50 | 6.41 | 1.404 |
| $R_3$ | 387 | 6.47 | 6.41 | 0.936 |
| $R_4$ | 385 | 6.48 | 6.41 | 1.092 |
| $R_5$ | 385 | 0.0127 | 0 | Undefined |

**Analysis:**
As shown in Table 1, the measured currents in the bridge arms ($I_1$ to $I_4$) are in excellent agreement with the calculated values, with all errors below 1.5%. This small discrepancy can be attributed to the tolerance of the resistors and the precision limits of the DMM.

The current through the central resistor, $I_5$, was measured to be 0.0127 mA. The theoretical value for a perfectly balanced bridge is 0 mA. The non-zero measured current indicates a slight imbalance in the bridge. This is expected, as the resistors, despite their nominal values, have manufacturing tolerances ($R_1R_3 = 387 \cdot 387 \neq R_2R_4 = 383 \cdot 385$). The percentage error is marked as undefined because calculating a percentage error with a theoretical value of zero is mathematically impossible. The extremely small magnitude of $I_5$ confirms that the bridge was very close to balance.

#### **4.2 Part 2: Sensing Circuit with Differential Amplifier Analysis**

The performance of the amplifier and the calculation of the resistance change are summarized below.

**Table 2: Amplifier Performance and Resistance Change Measurement**
| Parameter | Symbol | Measured Value | Theoretical Value | Error (%) |
|:---:|:---:|:---:|:---:|:---:|
| Pre-amplification Voltage | $V_{out(bridge)}$ | 24.24 mV | - | - |
| Post-amplification Voltage | $V_{out(amp)}$ | 113.46 mV | - | - |
| Theoretical Gain | $G_{theory}$ | - | 4.68085 | **0.0034** |
| Measured Gain | $G_{measured}$ | 4.68069 | - |
| Fractional Resistance Change | $\Delta R/R$ | 0.0263 | - | - |
| Resistance Change | $\Delta R$ | 10.125 Ω | - | - |

**Analysis and Calculations:**
1.  **Measured Gain Calculation:**
    $G_{measured} = |V_{out(amp)} / V_{out(bridge)}| = |113.46 \text{ mV} / 24.24 \text{ mV}| = 4.68069$

2.  **Gain Error Calculation:**
    Error (%) = $\frac{|G_{measured} - G_{theory}|}{G_{theory}} \times 100 = \frac{|4.68069 - 4.68085|}{4.68085} \times 100 = 0.0034\%$

The differential amplifier successfully amplified the weak 24.24 mV signal from the bridge by a factor of approximately 4.68, resulting in a much more usable output of 113.46 mV.

The measured gain ($G_{measured}$) is remarkably close to the theoretical gain ($G_{theory}$), with a calculated error of only 0.0034%. This extremely low error validates the performance of the amplifier circuit and the accuracy of the theoretical model. The minor difference can be attributed to:
1.  **Resistor Tolerances:** The gain accuracy is dependent on the precise ratio of the feedback resistors.
2.  **Non-Ideal Op-Amp:** The LM324 has non-ideal characteristics such as finite open-loop gain, input offset voltage, and input bias currents that can slightly affect the output.
3.  **Measurement Precision:** The inherent precision limits of the digital multimeter.

Using the measured pre-amplification voltage, the change in resistance ($\Delta R$) that caused the bridge imbalance was calculated to be approximately 10.125 Ω.

---

### **5. Reflection and Conclusion**

#### **5.1 Conclusion**
This experiment successfully demonstrated the principles and applications of the Wheatstone bridge and the differential amplifier. We confirmed that the bridge is a highly sensitive circuit for detecting small resistance changes and that a differential amplifier is an effective tool for amplifying its low-level output. The experimental results closely matched the theoretical predictions, confirming the validity of the circuit models. The hands-on process provided a clear understanding of how these fundamental components are combined to create a practical sensing system.

#### **5.2 Problems Encountered and Solutions**
1.  **Problem:** Initial measurements in Part 1 showed a significant current through $R_5$, indicating a poorly balanced bridge.
    **Solution:** We addressed this by not using random resistors. Instead, we measured all available 390Ω resistors and carefully selected the four with the most closely matched resistance values for the bridge arms. This significantly reduced the imbalance and brought the measured current $I_5$ very close to zero.

2.  **Problem:** When first powering the differential amplifier circuit in Part 2, the output was saturated (stuck near +12V).
    **Solution:** We re-examined the pinout diagram for the LM324 op-amp. It was discovered that the power supply connections were incorrect. We had confused the VCC+ and VEE- pins. After consulting the datasheet and correcting the wiring (Pin 4 to +12V, Pin 11 to -12V) and ensuring a common ground for all power supplies, the circuit functioned as expected. This experience highlighted the critical importance of carefully reading component datasheets before and during circuit construction.

#### **5.3 Applications and Further Thoughts**
The principles learned in this lab are foundational to countless real-world applications. The combination of a Wheatstone bridge and a differential amplifier is the core of modern sensor signal conditioning. For example, in a digital bathroom scale, strain gauges arranged in a Wheatstone bridge measure the microscopic bending of a metal beam under load. The resulting tiny voltage is amplified, digitized, and converted into a weight reading. This same technology is used in aerospace for structural health monitoring, in automotive systems for pressure sensing, and in medical devices for precision measurements. This lab provided valuable practical insight into the design of such systems.

---

### **6. References**
*   Sedra, A. S., & Smith, K. C. (2015). *Microelectronic Circuits*. Oxford University Press.
*   Texas Instruments. (2017). *LM324 Quadruple Op Amp* [Data sheet]. Retrieved from https://www.ti.com/lit/ds/symlink/lm324.pdf