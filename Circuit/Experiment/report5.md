# Transient Analysis for 1st-order RC Circuit

**Student Name:** 李鹏麒
**Student ID:** 24721015
**Date:** 25/12/12

---

## 1. Introduction
The primary objective of this laboratory exercise is to design, build, test, and characterize first-order RC circuits. The experiment is structured into three main sections:
1.  **Transient Analysis:** Observing the voltage response of a capacitor in a series RC circuit to a step input and measuring the time constant ($\tau$).
2.  **Integrator Design:** Designing an active Operational Amplifier (Op-Amp) circuit to perform mathematical integration, converting a square wave into a triangle wave.
3.  **Differentiator Design:** Designing an active Op-Amp circuit to perform differentiation, converting a triangle wave into a square wave.

A key focus of this lab is **"DESIGN"**. Rather than simply connecting components, appropriate resistor and capacitor values must be selected to ensure signal stability, avoid saturation, and maintain a measurable output amplitude. The experiment also emphasizes the importance of using measured component values for accurate theoretical modeling.

---

## 2. Pre-Lab Work

### 2.1 Theoretical Analysis
**A. RC Circuit (Pulse Response)**
The time constant $\tau$ is a measure of how quickly a capacitor charges or discharges. It is defined as:
$$ \tau = R \times C $$
Physically, $\tau$ represents the time required for the capacitor voltage $v_C(t)$ to reach approx. $63.2\%$ of its final value during charging. To observe the full transient process, the pulse width of the input signal must be at least $5\tau$.

**B. Integrator**
The input-output relationship for an ideal inverting integrator is:
$$ v_o(t) = -\frac{1}{RC} \int v_{in}(t) \, dt $$
For a square wave input with amplitude $V_{p}$, the output is a triangle wave. However, ideal integrators are unstable at DC (infinite gain). In practical design, a feedback resistor $R_f$ is placed in parallel with the capacitor to limit low-frequency gain and prevent the Op-Amp from drifting into saturation.

**C. Differentiator**
The input-output relationship for an ideal inverting differentiator is:
$$ v_o(t) = -RC \frac{d v_{in}(t)}{dt} $$
For a triangle wave input with a constant slope, the output is a square wave. Differentiators are inherently sensitive to high-frequency noise because their gain increases with frequency.

### 2.2 Simulation
Before the laboratory session, the circuits were simulated using Multisim to verify the design parameters.

<div style="display: flex; justify-content: center; align-items: center; gap: 10px;">
    <img src="https://img.remit.ee/api/file/BQACAgUAAyEGAASHRsPbAAEMhdNpO5jY53g-099a_ZFNwFqCEimi0wACaxwAAlAH2FVe5rv_-FY6XzYE.png" width="48%" alt="Left Image">
    <img src="https://img.remit.ee/api/file/BQACAgUAAyEGAASHRsPbAAEMhhZpO5utxEu5OVBvtPCt46bJ9bf5owACsBwAAlAH2FVLslLCsTlbRDYE.png" width="48%" alt="Right Image">
</div>
<center>
    <b>Figure 1: Multisim schematic and transient analysis of the 1st-order RC circuit</b>
</center>

<div style="display: flex; justify-content: center; align-items: center; gap: 10px;">
    <img src="https://img.remit.ee/api/file/BQACAgUAAyEGAASHRsPbAAEMhdFpO5jYpxeRJNSEMhBC7-4FdO2eZQACaRwAAlAH2FUya_MY8e1lYDYE.png" width="48%" alt="Left Image">
    <img src="https://img.remit.ee/api/file/BQACAgUAAyEGAASHRsPbAAEMhhdpO5uuRF8B3ifR1bX_zyrCAVOyOAACsRwAAlAH2FVA32TxY2oHhDYE.png" width="48%" alt="Right Image">
</div>
<center>
    <b>Figure 2: Design of the active integrator circuit using LM324 Op-amp</b>
</center>

<div style="display: flex; justify-content: center; align-items: center; gap: 10px;">
    <img src="https://img.remit.ee/api/file/BQACAgUAAyEGAASHRsPbAAEMhdJpO5jYuiblZ3Md15sfghkpYWZsNAACahwAAlAH2FX9q4kNCmz9dzYE.png" width="48%" alt="Left Image">
    <img src="https://img.remit.ee/api/file/BQACAgUAAyEGAASHRsPbAAEMhhVpO5utAUXXXSrULgitg6WhZkWi8AACrxwAAlAH2FW-R7xhDmWx1zYE.png" width="48%" alt="Right Image">
</div>
<center>
    <b>Figure 3: Design of the active differentiator circuit using LM324 Op-amp</b>
</center>

---

## 3. Experimental Procedure & Results

### 3.1 Part I: Pulse Response of 1st-order RC Circuit

**Procedure:**
1.  The actual resistance and capacitance were measured using a digital multimeter.
2.  A series RC circuit was constructed on the breadboard.
3.  The function generator was set to a Square Wave ($f=50Hz$, $V_{pp}=4V$, Offset=2V).
4.  The oscilloscope was used to capture the charging curve and measure the time to reach $63.2\%$ of the maximum voltage.

**Data & Calculation:**

| Parameter | Nominal Value | Measured Value |
| :--- | :--- | :--- |
| Resistor ($R$) | $5.1 k\Omega$ | **$5.114 k\Omega$** |
| Capacitor ($C$) | $0.22 \mu F$ | **$0.208 \mu F$** |

*   **Theoretical Time Constant ($\tau_{theo}$):**
    Using measured values:
    $$ \tau_{theo} = 5.114 \times 10^3 \Omega \times 0.208 \times 10^{-6} F = 1.0637 \, ms $$

*   **Measured Time Constant ($\tau_{meas}$):**
    Obtained from oscilloscope cursors (see Figure 4):
    $$ \tau_{meas} = 1.050 \, ms $$

*   **Error Analysis:**
    $$ Error = \left| \frac{1.050 - 1.0637}{1.0637} \right| \times 100\% \approx 1.29\% $$

**Waveform:**
The cursor measurement (ΔX) indicates a time constant of 1.050 ms, matching the theoretical prediction closely

<center>
<img src="https://img.remit.ee/api/file/BQACAgUAAyEGAASHRsPbAAEMhdZpO5jlF32xH3NnrnUWPGBwEv_oXQACbhwAAlAH2FW7l47IhPcXQTYE.jpg" width="50%" alt="Figure 4">

<b>Figure 4: Oscilloscope capture of the RC step response</b>
</center>

---

### 3.2 Part II: Design of a 1st-order Integrator

**Design Strategy:**
*   **Target:** Integrate a 100 Hz square wave.
*   **Stability:** A **$100 k\Omega$** resistor was added in parallel to the capacitor to provide negative feedback for DC signals, preventing the output from saturating to the power supply rails.

**Data & Calculation:**

| Parameter | Design Value | Measured Value |
| :--- | :--- | :--- |
| Input Resistor ($R_1$) | $10 k\Omega$ | **$9.8 k\Omega$** |
| Feedback Resistor ($R_2$) | $100 k\Omega$ | **$100.2 k\Omega$** |
| Capacitor ($C$) | $1 \mu F$ | **$0.967 \mu F$** |
| Input Signal | Square Wave | **100 Hz, 2 Vpp** |

*   **Theoretical Output Amplitude:**
    Input magnitude $V_{in} \approx 1V$ (half of 2Vpp). Integration interval $\Delta t = T/2 = 5ms$.
    $$ \Delta V_{out} = \frac{V_{in} \cdot \Delta t}{R_1 C} = \frac{1V \times 0.005s}{9800\Omega \times 0.967 \times 10^{-6}F} $$
    $$ \Delta V_{out} \approx 0.5276 \, V $$

*   **Measured Output Amplitude:**
    $$ V_{out\_meas} = 0.50 \, V $$

*   **Error Analysis:**
    $$ Error = \left| \frac{0.50 - 0.5276}{0.5276} \right| \times 100\% \approx 5.23\% $$

**Waveform:**
The yellow trace shows the square wave input, and the blue trace shows the resulting linear triangle wave output

<center>
<img src="https://img.remit.ee/api/file/BQACAgUAAyEGAASHRsPbAAEMhdVpO5jlaafGnE8htbCOnmoVnzO_xwACbRwAAlAH2FXBnD-ZrBp_5DYE.jpg" width="50%" alt="Figure 4">

<b>Figure 5: Integrator performance</b>
</center>

---

### 3.3 Part III: Design of a 1st-order Differentiator

**Design Strategy:**
*   **Target:** Differentiate a 50 Hz triangle wave.
*   **Parameter Selection:** A feedback resistor of $2.2 k\Omega$ was chosen to ensure the output voltage level was detectable (~200mV) while keeping the gain low enough to minimize high-frequency noise amplification.

**Data & Calculation:**

| Parameter | Design Value | Measured Value |
| :--- | :--- | :--- |
| Feedback Resistor ($R$) | $2.2 k\Omega$ | **$2.194 k\Omega$** |
| Capacitor ($C$) | $0.47 \mu F$ | **$0.469 \mu F$** |
| Input Signal | Triangle Wave | **50 Hz, 2 Vpp** |

*   **Theoretical Output Amplitude:**
    Step 1: Calculate Input Slope ($2 V_{pp}$ over half-period $10ms$):
    $$ Slope = \frac{dV_{in}}{dt} = \frac{2V}{10ms} = 200 \, V/s $$
    Step 2: Calculate Output Voltage:
    $$ |V_{out}| = R C \times Slope $$
    $$ |V_{out}| = (2194 \Omega) \times (0.469 \times 10^{-6} F) \times 200 $$
    $$ |V_{out}| = 1.0289 \times 10^{-3} \times 200 \approx 0.2058 \, V $$

*   **Measured Output Amplitude:**
    $$ V_{out\_meas} = 0.216 \, V $$

*   **Error Analysis:**
    $$ Error = \left| \frac{0.216 - 0.2058}{0.2058} \right| \times 100\% \approx 4.96\% $$

**Waveform:**
The circuit successfully converts the triangle wave input (Yellow) into a square wave output (Blue).

<center>
<img src="https://img.remit.ee/api/file/BQACAgUAAyEGAASHRsPbAAEMhddpO5jlXF7klc_4yUyrmMHhsqiwZAACbxwAAlAH2FVoS0TweW5LjzYE.jpg" width="50%" alt="Figure 4">

<b>Figure 6: Differentiator performance</b>
</center>

---

## 4. Discussion and Reflection

### 4.1 Analysis of Experimental Results
The experiment provided strong validation of transient circuit theory:
1.  **Precision through Measurement:** In Part I, the initial theoretical calculation using nominal values ($5.1k, 0.22\mu$) yielded $\tau=1.12ms$, which deviated from the experimental $1.05ms$. However, by using the **measured values** ($5.114k, 0.208\mu$), the theoretical $\tau$ became $1.06ms$, reducing the error to just **1.29%**. This proves that component tolerances are a significant source of discrepancy in circuit analysis.
2.  **Active Circuits:** Both the integrator and differentiator functioned as designed. The integrator error (~5%) and differentiator error (~5%) are well within acceptable limits for analog experiments, considering the parasitic effects of the breadboard and oscilloscope measurement resolution.

### 4.2 Design Challenges & Solutions
This lab required active design decisions to solve specific circuit problems:

*   **The DC Drift Problem (Integrator):**
    During the pre-lab design, we identified that a pure integrator has infinite gain at DC ($f=0$). Any tiny DC offset from the signal generator or the Op-Amp's input would be integrated over time, causing the output to "drift" until it hit the maximum voltage (saturation).
    *   **Solution:** We designed the circuit with a **$100 k\Omega$ parallel feedback resistor**. This resistor limits the DC gain to a finite value ($R_2/R_1$), effectively stabilizing the circuit while allowing the AC integration to proceed normally.

*   **The Noise Problem (Differentiator):**
    Differentiators are essentially high-pass filters, meaning they amplify high-frequency noise. During the initial test, the output square wave appeared "fuzzy" due to noise spikes.
    *   **Solution:**
        1.  Selected a lower input frequency (**50 Hz**) to keep the required signal bandwidth low.
        2.  Used the oscilloscope's **"Average" acquisition mode**. This technique averaged multiple waveform cycles to cancel out random noise, resulting in the clean square wave shown in Figure 5.

### 4.3 Conclusion
This laboratory exercise successfully demonstrated the time-domain behavior of RC circuits and the application of Operational Amplifiers in performing mathematical operations. By carefully characterizing components and implementing stability improvements (like the feedback resistor), we achieved high agreement between theoretical design and practical implementation. The skills developed here—specifically regarding component selection and noise management—are fundamental for designing advanced signal processing systems.