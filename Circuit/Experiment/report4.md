# Laboratory Report: Multisim Simulation & DC Circuit Analysis

**Lab Exercise:** No. 4
**Student Name:** 李鹏麒
**Student ID:** 24721015
**Date:** 25/12/5

---

## 1. Pre-Lab Work

Before conducting the simulation, it is essential to understand the software environment and the theoretical models of the circuits involved.

### 1.1 Introduction to Multisim
Multisim is a SPICE-based electronic design automation (EDA) tool that allows for schematic capture and circuit simulation. It enables engineers to analyze circuit behavior—such as DC operating points, transient responses, and frequency characteristics—before physical implementation.

### 1.2 Theoretical Background
1.  **Wheatstone Bridge & Differential Amplifier:**
    The Wheatstone bridge detects minute changes in resistance ($\Delta R$). The output voltage of the bridge is usually small and requires amplification. A differential amplifier (subtractor) is used to amplify the voltage difference between the two bridge legs.
    The theoretical gain ($G$) of the amplifier used in this lab is determined by the ratio of the feedback resistor ($R_f$) to the input resistor ($R_{in}$):
    $$G_{theoretical} = \frac{R_6}{R_5} = \frac{220 k\Omega}{47 k\Omega} \approx 4.6809$$

2.  **Reciprocity Theorem:**
    This theorem states that in any linear bilateral network having only one independent source, if the positions of the source (excitation) and the ammeter (response) are interchanged, the reading of the ammeter remains the same.

3.  **Thevenin’s Theorem via DC Sweep:**
    Any linear DC network can be represented by an equivalent voltage source ($V_{th}$) in series with an equivalent resistance ($R_{th}$). By performing a **DC Sweep** analysis (sweeping current $I$ and measuring voltage $V$), we can plot the $I-V$ characteristic curve.
    *   The Y-intercept (where $I=0$) represents the Open Circuit Voltage ($V_{OC} = V_{th}$).
    *   The slope of the curve ($\Delta V / \Delta I$) represents the Thevenin Resistance ($R_{th}$).

---

## 2. Introduction

The objective of this laboratory exercise is to utilize Multisim 14.0 to simulate and analyze DC circuits. The experiment is divided into three parts:
1.  **DC Operating Point:** Simulate a Wheatstone bridge instrumentation circuit and compare the performance of a general-purpose Op-Amp (LM324) versus a precision Op-Amp (OP37).
2.  **Reciprocity Theorem:** Verify the theorem by swapping excitation and response nodes in a resistive network.
3.  **DC Sweep:** Determine the Thevenin equivalent parameters of a circuit containing a dependent source by analyzing its $I-V$ transfer characteristic.

---

## 3. Experimental Section & Analysis

### Part 1: DC Operating Point (Wheatstone Bridge & Amplifier)

#### 3.1 Circuit Setup
The circuit consists of a DC bridge where $R_9$ acts as a variable resistor simulating a sensor. The output is fed into a differential amplifier.
*   **Resistors:** $R_1=R_2=R_4=390\Omega$, $R_3=380\Omega$, $R_{var}=20\Omega$.
*   **Amplifier:** $R_{in}=47k\Omega$, $R_{feedback}=220k\Omega$.

<center>
<img src="https://youke1.picui.cn/s1/2025/12/05/69325cff1134d.png" width="40%" alt="Figure 1">

<b>Figure 1: Material Information</b>
</center>


#### 3.2 Data Recording
We performed the simulation twice: first using the **LM324** (General Purpose) and second using the **OP37** (Precision). The value of $\Delta R$ was varied via the potentiometer key settings.

<center>
<img src="https://youke1.picui.cn/s1/2025/12/05/69325cff36dae.png" width="40%" alt="Figure 1">

<b>Figure 2: LM324</b>
</center>

**Table 1: Simulation Data for LM324**
| Measurement | $V_{bridge}$ (mV) | $V_{amp}$ (mV) | $\Delta R$ ($\Omega$) | $G_{Measured}$ | $G_{Theoretical}$ | Error % |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | 31.514 | 146.307 | 10 | 4.6426 | 4.6809 | 0.818 |
| 2 | 15.858 | 73.098 | 5 | 4.6095 | 4.6809 | 1.525 |
| 3 | 6.368 | 28.723 | 2 | 4.5105 | 4.6809 | 3.640 |
| 4 | 0.001 | 1.052 | 0 | / | 4.6809 | / |
| 5 | 3.195 | 15.997 | -1 | 5.0069 | 4.6809 | 6.964 |
| 6 | 9.612 | 46.003 | -3 | 4.7860 | 4.6809 | 2.245 |
| 7 | 22.545 | 106.481 | -7 | 4.7230 | 4.6809 | 0.899 |

<center>
<img src="https://youke1.picui.cn/s1/2025/12/05/69325cff56239.png" width="40%" alt="Figure 1">

<b>Figure 3: OP37</b>
</center>

**Table 2: Simulation Data for OP37**
| Measurement | $V_{bridge}$ (mV) | $V_{amp}$ (mV) | $\Delta R$ ($\Omega$) | $G_{Measured}$ | $G_{Theoretical}$ | Error % |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | 31.514 | 147.514 | 10 | 4.6809 | 4.6809 | 0.000 |
| 2 | 15.858 | 74.229 | 5 | 4.6809 | 4.6809 | 0.000 |
| 3 | 6.367 | 29.807 | 2 | 4.6815 | 4.6809 | 0.013 |
| 5 | 3.196 | 14.958 | -1 | 4.6802 | 4.6809 | 0.015 |
| 6 | 9.613 | 44.993 | -3 | 4.6804 | 4.6809 | 0.011 |
| 7 | 22.546 | 105.532 | -7 | 4.6807 | 4.6809 | 0.004 |

<center>
<img src="https://youke1.picui.cn/s1/2025/12/05/69325cfec1f2d.png" width="40%" alt="Figure 1">

<b>Figure 4: Oscilloscope output showing the DC voltage levels</b>
</center>

#### 3.3 Discussion on Part 1
The results demonstrate a significant difference between the two operational amplifiers.
*   **OP37:** The measured gain ($G_{Measured}$) matches the theoretical gain ($4.6809$) almost perfectly, with errors close to $0\%$.
*   **LM324:** Showed noticeable errors, particularly when the input signal was small (e.g., at $\Delta R = -1$, the error peaked at $6.964\%$).

**Reason for Discrepancy:** The LM324 is a general-purpose Op-Amp with a relatively high **Input Offset Voltage ($V_{OS}$)** (typically 2mV - 7mV). When the bridge output voltage is very small (e.g., 3mV), the offset voltage constitutes a significant percentage of the total signal, leading to amplification errors. The OP37 is a precision Op-Amp with extremely low offset voltage, making it suitable for accurate instrumentation applications.

---

### Part 2: Reciprocity Theorem Verification

#### 3.4 Simulation Setup & Results
Two circuits were built to verify the Reciprocity Theorem.
1.  **Circuit A:** A 12V source is placed in the left loop; current is measured in the right loop.
2.  **Circuit B:** The 12V source is moved to the right loop; current is measured in the left loop.

<center>
<img src="https://youke1.picui.cn/s1/2025/12/05/69325cfee0e39.png" width="40%" alt="Figure 1">

<b>Figure 5: Verification of Reciprocity Theorem showing current probes</b>
</center>

#### 3.5 Analysis
*   **Current in Circuit A:** $I = 800 \text{ mA}$.
*   **Current in Circuit B:** $I = 800 \text{ mA}$.

**Conclusion:** Since the current response remained exactly $800 \text{ mA}$ after swapping the voltage source and the measurement point, the Reciprocity Theorem is successfully verified for this linear resistive circuit.

---

### Part 3: DC Sweep (Thevenin Equivalent)

#### 3.6 Simulation Setup
A circuit containing a Current-Controlled Current Source (CCCS) was analyzed. To find the Thevenin equivalent at Port 2, a Current Source ($I_1$) was connected to the output. We performed a **DC Sweep** analysis:
*   **Parameter:** Current Source $I_1$
*   **Start/Stop:** -2A to 2A
*   **Increment:** 0.2A

<center>
<img src="https://youke1.picui.cn/s1/2025/12/05/69325d06e8523.png" width="40%" alt="Figure 1">

<b>Figure 6: Circuit schematic for DC Sweep analysis</b>
</center>

#### 3.7 Grapher View Analysis
The resulting $I-V$ characteristic curve is linear, confirming the circuit behaves as a linear network.

<center>
<img src="https://youke1.picui.cn/s1/2025/12/05/69325d0724449.png" width="40%" alt="Figure 1">

<b>Figure 7: DC Sweep results (Voltage vs. Current)</b>
</center>

From the data cursor window in the Grapher View:
1.  **Open Circuit Voltage ($V_{th}$):**
    When Current ($x1$) is $0.0000$, the Voltage ($y1$) is $8.0000$.
    $$V_{th} = 8 \text{ V}$$

2.  **Thevenin Resistance ($R_{th}$):**
    The slope of the line represents the resistance. Using the cursor data ($dx=1.0000, dy=8.0000$):
    $$R_{th} = \frac{dy}{dx} = \frac{8.0000 \text{ V}}{1.0000 \text{ A}} = 8 \Omega$$

**Comparison:** These values match the theoretical calculation provided in the lab manual (Fig 6b), which shows an equivalent circuit of 8V and $8\Omega$.

---

## 4. Reflection and Conclusion

### 4.1 Summary of Learning
This laboratory exercise provided practical experience in using Multisim for advanced circuit analysis.
1.  I learned how to set up **DC Operating Point** analysis to quickly view node voltages without attaching individual probes.
2.  I mastered the **DC Sweep** function, which proved to be a powerful method for deriving component characteristics (like $R_{th}$) graphically, rather than calculating them point-by-point.
3.  The experiment reinforced the theoretical concepts of the Wheatstone bridge, Reciprocity theorem, and Thevenin equivalency.

### 4.2 Challenges and Solutions
*   **Issue:** Initially, in Part 1, the output errors for the LM324 seemed surprisingly high. I suspected a wiring error.
*   **Solution:** After checking the connections and finding them correct, I researched the datasheet for the LM324. I realized the error was due to the component's non-ideal characteristics (Input Offset Voltage). Replacing it with the OP37 fixed the "error," confirming that the issue was physical device limitation, not simulation setup. This taught me the importance of selecting the right component for precision tasks.

*   **Issue:** In Part 3, the graph initially looked like a flat line.
*   **Solution:** I realized the vertical axis scale was too large. I used the "Auto Scale" feature in the Grapher View to properly visualize the slope and intercepts.

### 4.3 Application
The circuits analyzed here have real-world importance. The Wheatstone bridge combined with a precision differential amplifier (like the OP37 setup) is the fundamental architecture for reading **strain gauges** in civil engineering (measuring stress on bridges) and **RTD temperature sensors** in industrial control systems. Understanding how to simulate these accurately ensures better design reliability before actual hardware prototyping.

---