# **Pre-lab Report**

**Course Name:** [High-Voltage Alternating Current]
**Laboratory Exercise No:** 1
**Experiment Title:** Sinusoidal Steady-State AC Circuit Characteristics
**Date:** 26/3/28

---

## **1. Objectives**
1. To build, test, and characterize sinusoidal steady-state AC circuits.
2. To apply phasor circuit analysis and the superposition principle.
3. To design RC filters and understand their frequency responses.
4. To learn how to measure phase differences using a digital oscilloscope (Double traces method & Lissajous-Figure method).
5. To understand the operational characteristics of the TL084 Op-Amp.

---

## **2. Theory Analysis (Pre-Lab Work - Part a)**

### **2.1 Circuit Transfer Function Derivation**
Based on the schematic provided in Figure 1, the circuit can be divided into four operational amplifier stages (OP1 to OP4). Using ideal Op-Amp assumptions, we analyze each stage:

*   **OP1 & OP2 (Voltage Followers):**
    The inputs $v_{s1}$ and $v_{s2}$ are fed into the non-inverting terminals of OP1 and OP2, respectively. Since their outputs are directly fed back to their inverting terminals, they act as voltage followers with unity gain:
    $$v_1 = v_{s1}$$

    $$v_2 = v_{s2}$$

*   **OP3 (Differential Amplifier Stage):**
    The non-inverting input voltage $v_3$ is determined by the voltage divider formed by $R_1$ and $R_3$:
    $$v_3 = v_1 \frac{R_3}{R_1 + R_3} = v_1 \frac{1k\Omega}{2k\Omega + 1k\Omega} = \frac{1}{3}v_1$$

    Due to the virtual short concept, the inverting input voltage $v_4 = v_3 = \frac{1}{3}v_1$.
    Applying Kirchhoff's Current Law (KCL) at node $v_4$:
    $$\frac{v_4 - v_2}{R_2} + \frac{v_4}{R_4} + \frac{v_4 - v_5}{R_5} = 0$$

    Substitute the resistor values ($R_2 = 2k\Omega, R_4 = 1k\Omega, R_5 = 1k\Omega$):
    $$\frac{v_4 - v_2}{2} + \frac{v_4}{1} + \frac{v_4 - v_5}{1} = 0$$

    Multiplying the entire equation by 2 yields:
    $$v_4 - v_2 + 2v_4 + 2v_4 - 2v_5 = 0 \implies 2v_5 = 5v_4 - v_2$$

    Substitute $v_4 = \frac{1}{3}v_1$ into the equation:
    $$v_5 = \frac{5}{2}\left(\frac{1}{3}v_1\right) - \frac{1}{2}v_2 = \frac{5}{6}v_1 - \frac{1}{2}v_2$$

*   **RC Low-Pass Filter Stage:**
    Resistor $R_6$ ($10\text{ k}\Omega$) and Capacitor $C$ ($10\text{ nF}$) form a passive first-order low-pass filter.
    $$v_6(\omega) = v_5(\omega) \cdot \frac{1}{1 + j\omega R_6 C}$$
    
    The characteristic cut-off frequency is:
    $$f_c = \frac{1}{2\pi R_6 C} = \frac{1}{2\pi \times 10\times 10^3 \times 10\times 10^{-9}} \approx 1591.55 \text{ Hz}$$

*   **OP4 (Non-inverting Amplifier):**
    $$v_8 = \left(1 + \frac{R_8}{R_7}\right) v_6 = \left(1 + \frac{1k\Omega}{1k\Omega}\right) v_6 = 2v_6$$

*   **Overall Transfer Function:**
    $$v_8(\omega) = \frac{2}{1 + j(f/f_c)} \left(\frac{5}{6}v_1 - \frac{1}{2}v_2\right) = \frac{5/3}{1 + j(f/f_c)}v_1 - \frac{1}{1 + j(f/f_c)}v_2$$

### **2.2 Determination of $f_{max}$ and Phase Difference $\phi_1$**
Set $v_{s2} = 0$, which yields $v_2 = 0$. The transfer function becomes:
$$v_8(\omega) = \frac{5/3}{1 + j(f/f_c)} \cdot v_1(\omega)$$

The DC gain from $v_1$ to $v_8$ is $5/3$. According to the intended meaning of the lab manual, $f_{max}$ refers to the filter's own -3dB cut-off frequency, which occurs when the output amplitude falls to $70.7\%$ ($1/\sqrt{2}$) of its **DC steady-state maximum value**.
$$|v_8| = \frac{5/3}{\sqrt{1 + (f/f_c)^2}} |v_1| = \frac{5/3}{\sqrt{2}} |v_1|$$

This naturally occurs when $f_{max} = f_c$:
$$f_{max} = \frac{1}{2\pi R_6 C} \approx \mathbf{1591.5 \text{ Hz} \ (1.59 \text{ kHz})}$$

The phase difference $\phi_1$ between $v_8$ and $v_1$ at the cut-off frequency is calculated as:
$$\phi_1 = \angle v_8 - \angle v_1 = 0^\circ - \arctan\left(\frac{f_{max}}{f_c}\right) = -\arctan(1) = \mathbf{-45^\circ}$$

### **2.3 Determination of $f_{min}$ and Phase Difference $\phi_2$**
Set $v_{s1} = 0$, which yields $v_1 = 0$. The transfer function becomes:
$$v_8(\omega) = \frac{-1}{1 + j(f/f_c)} \cdot v_2(\omega)$$
*(Note: The negative sign indicates a $180^\circ$ phase shift introduced by the inverting nature of the combined OP3 and OP4 circuitry relative to $v_2$).*

The magnitude relationship is:
$$|v_8| = \frac{1}{\sqrt{1 + (f/f_c)^2}} |v_2|$$

According to the manual, $f_{min}$ occurs when $v_{8pp}$ falls to $5\%$ of $v_{2pp}$:
$$\frac{1}{\sqrt{1 + (f_{min}/f_c)^2}} = 0.05$$

$$\sqrt{1 + (f_{min}/f_c)^2} = 20 \implies 1 + \left(\frac{f_{min}}{f_c}\right)^2 = 400 \implies \frac{f_{min}}{f_c} = \sqrt{399}$$

$$f_{min} = \sqrt{399} \times 1591.55 \text{ Hz} \approx \mathbf{31791.1 \text{ Hz} \ (31.79 \text{ kHz})}$$

The phase difference $\phi_2$ between $v_8$ and $v_2$ is calculated as:
$$\phi_2 = \angle v_8 - \angle v_2 = 180^\circ - \arctan\left(\frac{f_{min}}{f_c}\right) = 180^\circ - \arctan(\sqrt{399}) \approx 180^\circ - 87.1^\circ = \mathbf{92.9^\circ}$$

---

## **3. Op-Amp TL084 Characteristics (Pre-Lab Work - Part b)**

Based on the Texas Instruments/STMicroelectronics datasheet, the TL084 is a high-speed JFET-input quad operational amplifier. 
*   **Key Features:** High slew rate ($13 \text{ V}/\mu\text{s}$), low input bias and offset currents, and wide common-mode voltage range.
*   **Pin Configuration:** It is a 14-pin IC containing four independent op-amps. 
    *   Pin 4: $V_{CC+}$ (Positive Power Supply, typically $+12\text{V}$ or $+15\text{V}$)
    *   Pin 11: $V_{CC-}$ (Negative Power Supply, typically $-12\text{V}$ or $-15\text{V}$)
*   **Usage Note:** Appropriate bypass capacitors (e.g., $0.1\mu\text{F}$) should be placed close to the power supply pins to prevent high-frequency oscillation during the physical lab.

<center>
    <img src = "https://picui.ogmua.cn/s1/2026/03/28/69c736167d343.webp"
        width = 50%>
</center>
<center>
    <em>Figure 1: TL084 Pinout Diagram from Datasheet</em>
</center>

---

## **4. Simulation Practice (Pre-Lab Work - Part c)**

### **4.1 Simulation Circuit Schematic**

<center>
    <img src = "https://picui.ogmua.cn/s1/2026/03/28/69c7462e3df68.webp"
        width = 50%>
</center>
<center>
    <em>Figure 2: Complete Multisim Schematic of Figure 1</em>
</center>

### **4.2 Step 1: $v_{s1pp} = 5\text{V}$, $v_{s2pp} = 0\text{V}$**
*   **Measurement Target:** Observe waveforms of $v_1$ and $v_8$; measure $f_{max}$ and $\phi_1$.

<center>
    <img src = "https://picui.ogmua.cn/s1/2026/03/28/69c7462e216b6.webp"
        width = 50%>
</center>
<center>
    <em>Figure 3: Multisim Oscilloscope Screenshot showing v1 and v8</em>
</center>

*   **Simulation Result Data:**
    *   Measured $f_{max}$: `[~1.59 kHz]`
    *   Measured $\phi_1$: `[-45.0°]`

### **4.3 Step 2: $v_{s2pp} = 5\text{V}$, $v_{s1pp} = 0\text{V}$**
*   **Measurement Target:** Observe waveforms of $v_2$ and $v_8$; measure $f_{min}$ and $\phi_2$.

<center>
    <img src = "https://picui.ogmua.cn/s1/2026/03/28/69c7462e31bd4.webp"
        width = 50%>
</center>
<center>
    <em>Figure 4: Multisim Oscilloscope Screenshot showing v2 and v8</em>
</center>

*   **Simulation Result Data:**
    *   Measured $f_{min}$: `[~31.79 kHz]`
    *   Measured $\phi_2$: `[92.9°]`

### **4.4 Step 3: Combined Frequencies Analysis**
*   **Settings:** $v_{s1pp} = 5\text{V}, f_1 = f_{max}$; $v_{s2pp} = 5\text{V}, f_2 = f_{min}$.
*   **Measurement Target:** Observe waveforms of $v_5$ and $v_8$; measure amplitudes of $f_{max}$ signal and $f_{min}$ signal from $v_8$.

<center>
    <img src = "https://picui.ogmua.cn/s1/2026/03/28/69c7462e23702.webp"
        width = 50%>
</center>
<center>
    <em>Figure 5: Multisim Oscilloscope Screenshot showing combined waveforms v5 and v8</em>
</center>

*   **Conclusion / Observations:** 
    $v_5$ is a superimposed complex wave containing both low-frequency ($f_{max}$) and high-frequency ($f_{min}$) components. However, after passing through the RC filter, the waveform of $v_8$ is predominantly dominated by the lower frequency component ($f_{max}$). The high-frequency component ($f_{min}$) is significantly attenuated (filtered out), which aligns perfectly with the characteristics of a Low-Pass Filter (LPF) and the Superposition Principle in the time domain.

---
**END OF PRE-LAB REPORT**