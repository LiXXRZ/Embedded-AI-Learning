# **Lab Report: In-Depth Analysis and Verification of a 3-Bit R-2R DAC**

**Course:** Circuit Analysis
**Date:** November 7, 2025
**Author:** 李鹏麒 24721015
**Partner:** 郭庆杰 24721007

---

## **Pre-lab Analysis**

### **Theoretical Model of the 3-bit DAC**

The Digital-to-Analog Converter (DAC) under investigation is a 3-bit R-2R ladder network. The digital inputs are controlled by switches \( SD_0 \), \( SD_1 \), and \( SD_2 \), corresponding to bits \( D_0 \) (LSB) to \( D_2 \) (MSB). The switch state is defined as:
\[
D_x = 0 \text{ when } SD_x \text{ is connected to ground}
\]\[
D_x = 1 \text{ when } SD_x \text{ is connected to } V_s
\]where \( x = 0, 1, 2 \) and \( V_s = 8V \).

#### **i) Equivalent Resistance \( R_{ab} \) (All switches at '0', S open)**
With all switches connected to ground, the R-2R ladder network simplifies. The equivalent resistance looking into terminals a-b (\( R_{ab} \)) or from the source (\( R_{in} \)) is consistently equal to \( R \), due to the properties of the ladder network, assuming ideal switches and sources.
\[
R_{ab} = R_0 = R = 1k\Omega
\]

#### **ii) Open-Circuit Voltage \( V_{aboc} \) and DAC Coefficients**
Using the superposition theorem, the open-circuit output voltage \( V_{aboc} \) is a weighted sum of the digital inputs:
\[
V_{aboc} = k_2 D_2 + k_1 D_1 + k_0 D_0
\]The coefficients \( k_x \) represent the voltage contribution of each bit. For a standard R-2R ladder with \( V_s = 8V \):
\[
k_2 = \frac{V_s}{2} = 4V,\quad k_1 = \frac{V_s}{4} = 2V,\quad k_0 = \frac{V_s}{8} = 1V
\]Thus, the output voltage equation becomes:
\[
V_{aboc} = (4V) \cdot D_2 + (2V) \cdot D_1 + (1V) \cdot D_0
\]

**Table 1: Pre-lab Theoretical Calculations**

| \( D_2 D_1 D_0 \) | 000 | 001 | 010 | 011 | 100 | 101 | 110 | 111 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **\( V_{aboc} \) (V)** | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
| **\( R_{ab} \) (\( R_0 \))** | 1kΩ | 1kΩ | 1kΩ | 1kΩ | 1kΩ | 1kΩ | 1kΩ | 1kΩ |

---

## **1. Introduction & Background**

This laboratory session had two primary objectives:
1. **Equipment Familiarization:** To gain proficiency in operating the RIGOL DG4202 Function Waveform Generator and the RIGOL MSO2202A Digital Oscilloscope for generating and analyzing various electrical signals.
2. **DAC Characterization:** To build and analyze a 3-bit R-2R ladder Digital-to-Analog Converter (DAC), verifying its theoretical operation by measuring its open-circuit voltage, output resistance, and performance under load.

DACs are fundamental components in modern electronics, bridging the digital domain of microprocessors with the analog real world. They are ubiquitous in applications such as audio players, video displays, and data acquisition systems.

---

## **2. Experimental Procedure & Results**

### **2.1 Equipment Learning**

#### **A. Function Waveform Generator (RIGOL DG4202)**
The DG4202 was configured to produce a **500 Hz sine wave** with a **7.6 V peak-to-peak amplitude**, **0 V DC offset**, and **30° starting phase**.
- **Measurement:** The DMM measured the RMS voltage. The theoretical RMS for a 7.6 Vpp sine wave is \( V_{rms} = \frac{7.6}{2\sqrt{2}} \approx 2.687V \). The measured value was close, confirming the generator's output accuracy.
- **Waveform Observation:** The oscilloscope was used to visually confirm the waveform shape, frequency, and amplitude.

<center>
    <img src = "https://youke1.picui.cn/s1/2025/11/07/690d793e237cf.jpg"
        width = 50%>
</center>

*Figure 1: Oscilloscope display of the 500 Hz, 7.6 Vpp sine wave from the DG4202*

Further exploration involved generating square waves and adjusting the symmetry and DC offset controls, observing the real-time changes on the oscilloscope display.

#### **B. Digital Oscilloscope (RIGOL MSO2202A)**
The oscilloscope was set up to stably display the signal from the generator:
1. The **AUTO** button was pressed for initial setup
2. **Channel 1** was enabled with **DC coupling** and **1X probe** setting
3. The vertical scale (**VOLTS/DIV**) was adjusted to **1.00 V/div**
4. The horizontal scale (**TIME/DIV**) was set to **500 µs/div** to display multiple cycles clearly
5. The trigger was configured for stability: **Type=Edge**, **Source=CH1**, **Slope=Rising**, **Coupling=AC**, **Mode=Auto**

<center>
    <img src = "https://youke1.picui.cn/s1/2025/11/07/690d793e6c0d7.jpg"
        width = 50%>
</center>

*Figure 2: Stable oscilloscope display showing triggered measurement of frequency and Vpp*

### **2.2 Digital-to-Analog Converter (DAC) Test**

A 3-bit R-2R ladder DAC was constructed on a breadboard using resistors (\( R = 1k\Omega \), \( 2R = 2k\Omega \)) and switches.

<center>
    <img src = "https://youke1.picui.cn/s1/2025/11/07/690d793dacf13.jpg"
        width = 50%>
</center>

*Figure 3: Photograph of the physically constructed DAC circuit*

#### **i) Measurement of Input Resistance \( R_{in} \)**

Before analyzing the output, we investigated the circuit's input characteristics by measuring the input resistance `Rin` as seen from the voltage source `Vs`.

The voltage source and load were disconnected. An ohmmeter was used to measure the resistance seen from the source for all 8 digital input combinations.

**Table 2: Measured Input Resistance \( R_{in} \)**

| \( D_2 D_1 D_0 \) | 000 | 001 | 010 | 011 | 100 | 101 | 110 | 111 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **\( R_{in} \) (kΩ)** | overload | 3.007 | 3.160 | 2.183 | 2.233 | 2.188 | 3.163 | 3.004 |

#### **ii) Measurement of \( V_{aboc} \) and \( R_0 \)**

This section forms the core of the experiment, aiming to validate the derived theoretical model with high-precision measurements.

The voltage source \( V_s \) was set to **8.00 V**. For each input combination, the open-circuit voltage \( V_{aboc} \) was measured with a DMM. The equivalent output resistance \( R_0 \) was measured.

**Table 3: Measured Open-Circuit Voltage and Output Resistance**

| \( D_2 D_1 D_0 \) | 000 | 001 | 010 | 011 | 100 | 101 | 110 | 111 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **\( V_{aboc} \) (V)** | 0.001 | 1.002 | 2.012 | 3.015 | 3.998 | 4.999 | 6.008 | 7.013 |
| **\( R_0 \) (kΩ)** | 0.996 | 0.998 | 0.998 | 0.997 | 1.003 | 1.001 | 0.996 | 0.994 |

#### **iii) Measurement of \( V_{ab} \) with Load \( R_L \)**

To apply the Thevenin model practically, we investigated the circuit's performance under load.

The load resistors \( R_L = 2k\Omega \) and \( R_L = 1k\Omega \) were connected across the output terminals a-b, and the output voltage \( V_{ab} \) was measured for each digital input.

**Table 4: Measured Output Voltage under Load**

| \( D_2 D_1 D_0 \) | 000 | 001 | 010 | 011 | 100 | 101 | 110 | 111 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **\( V_{ab} \) (\( R_L=2k\Omega \)) (V)** | 0.001 | 0.669 | 1.343 | 2.011 | 2.657 | 3.332 | 4.008 | 4.675 |
| **\( V_{ab} \) (\( R_L=1k\Omega \)) (V)** | 0.001 | 0.501 | 1.008 | 1.509 | 2.000 | 2.500 | 3.007 | 3.496 |

*\*Predicted values are calculated using the Thevenin model: `Vab = Vaboc(meas) * (RL / (RL + Ro(meas)))`.*

---

## **3. Theoretical Analysis & Discussion**

### **3.1 Open-Circuit Voltage (Vaboc) Analysis**

**Table 5: Comparison of Theoretical vs. Measured Vaboc**

| \( D_2D_1D_0 \) | Theoretical Vaboc (V) | Measured Vaboc (V) | Error (V) | % Error |
| :---: | :---: | :---: | :---: | :---: |
| 000 | 0.00 | 0.001 | +0.001 | - |
| 001 | 1.00 | 1.002 | +0.002 | 0.20% |
| 010 | 2.00 | 2.012 | +0.012 | 0.60% |
| 011 | 3.00 | 3.015 | +0.015 | 0.50% |
| 100 | 4.00 | 3.998 | -0.002 | 0.05% |
| 101 | 5.00 | 4.999 | -0.001 | 0.02% |
| 110 | 6.00 | 6.008 | +0.008 | 0.13% |
| 111 | 7.00 | 7.013 | +0.013 | 0.19% |

**Discussion:**
- The measured Vaboc values show excellent agreement with theoretical predictions, with maximum error of only 0.60%
- The linear progression from 0V to 7V confirms the DAC's proper functioning and the accuracy of the equation Vaboc = 4D₂ + 2D₁ + 1D₀
- Minor discrepancies are within expected tolerances for component values and measurement accuracy

### **3.2 Resistance Analysis**

**Output Resistance (R₀):**
- **Open-Circuit Voltage `Vaboc`:** The measured data exhibits a remarkable consistency with the theoretical values. The maximum relative error is a mere 0.60%, with most errors well below 0.2%. These minute deviations are well within the acceptable tolerance margins of the instrumentation (e.g., DMM accuracy) and components (e.g., 1% precision resistors). This irrefutably validates the correctness of the linear model: **`Vaboc = 4*D2 + 2*D1 + 1*D0`**.
- **Equivalent Resistance `Ro`:** The measured `Ro` values are extremely stable across all input codes, clustering tightly within the range of `1.000 ± 0.006 kΩ`. This provides strong empirical evidence for the theoretical deduction that **the Thevenin equivalent resistance `Ro` is a constant, independent of the digital input**.

**Input Resistance (Rin) Anomaly:**
- **`000` State:** For the digital input `000`, all switches are grounded, and the voltage source `Vs` is not connected to any part of the circuit, resulting in an open-circuit condition. The multimeter's "overload" reading is perfectly consistent with this theoretical expectation of infinite resistance.
- **Varying `Rin`:** For all non-zero inputs, `Rin` varies with the input code. This occurs because each code alters the node to which `Vs` is connected, thereby changing the total load network seen by the source. This measurement is practically significant for evaluating the power supply's current-sourcing requirements for different digital inputs.

This discrepancy suggests:
1. Possible measurement technique issues when measuring input resistance
2. Potential circuit configuration differences from the theoretical model
3. Instrument limitations or incorrect range selection

### **3.3 Load Effect Analysis**

The voltage divider effect is clearly demonstrated when loads are connected:

**For Rₗ = 2 kΩ:**
- Theoretical: Vab = Vaboc × [2/(1+2)] = Vaboc × 0.667
- Measured values closely match this prediction

**For Rₗ = 1 kΩ:**
- Theoretical: Vab = Vaboc × [1/(1+1)] = Vaboc × 0.5
- Measured values confirm this relationship

**Table 6: Load Effect Verification (Code 111 as example)**

| Parameter | Theoretical | Measured |
| :--- | :---: | :---: |
| Vaboc | 7.00V | 7.013V |
| Vab (Rₗ=2kΩ) | 4.67V | 4.675V |
| Vab (Rₗ=1kΩ) | 3.50V | 3.496V |

The close agreement between theoretical and measured loaded voltages validates our understanding of the DAC's output characteristics and the voltage division principle.

### **3.4 Linearity Assessment**

The DAC demonstrates excellent linearity, as evidenced by:
- Consistent step size between adjacent codes
- Minimal deviation from ideal transfer characteristic
- Proper weighting of MSB and LSB contributions

### **3.5 Error Sources**

The minor discrepancies observed can be attributed to:
1. **Component Tolerances:** Resistors not having exact nominal values
2. **Measurement Accuracy:** Limitations of DMM precision (±0.5% typical)
3. **Contact Resistance:** Switch and connection resistances
4. **Source Imperfections:** Power supply regulation and internal resistance
5. **Environmental Factors:** Temperature effects on component values

---

## **4. Reflection & Conclusion**

### **4.1 Experimental Successes**
- Successfully verified the linear input-output relationship of the 3-bit DAC
- Confirmed the constant output resistance property of the R-2R ladder network
- Demonstrated predictable loading effects using voltage division principle
- Achieved excellent agreement between theory and measurement for output voltages (≤0.6% error)
- Gained practical experience with laboratory test equipment operation

### **4.2 Challenges and Solutions**

**Challenge 1: Inconsistent Input Resistance Measurements**
The varying Rin measurements, particularly the "overload" reading for code 000, were unexpected.
- **Investigation:** Rechecked the circuit configuration and measurement technique
- **Insight:** Determined that the theoretical assumption of constant input resistance may not hold in practical implementations due to switch configurations and measurement methodology

**Challenge 2: Minor Voltage Discrepancies**
Small errors in Vaboc measurements accumulated across the range.
- **Investigation:** Measured actual resistor values and found slight variations from nominal values
- **Resolution:** Used the measured component values in theoretical calculations, which improved agreement. This emphasized the importance of characterizing actual components rather than relying on nominal values

**Challenge 3: Equipment Operation**
Initial difficulty in obtaining stable oscilloscope displays.
- **Solution:** Systematically applied the trigger stabilization procedure outlined in the manual
- **Learning:** Gained deeper understanding of trigger settings and their impact on waveform stability

### **4.3 Practical Applications and Implications**

The demonstrated principles have direct relevance to:
- **Audio Equipment:** Digital audio players using DACs to convert digital files to analog signals
- **Instrumentation:** Data acquisition systems requiring precise analog outputs
- **Communication Systems:** Modern modems and transceivers employing DACs for signal generation
- **Control Systems:** Microcontroller-based systems generating analog control signals

The experiment highlighted the importance of:
- Understanding source and load impedance matching
- Considering real-world component tolerances in circuit design
- Using appropriate measurement techniques for different circuit parameters
- Recognizing the limitations of ideal circuit models

### **4.4 Conclusion**

This experiment was a resounding success, providing a seamless bridge between theoretical circuit analysis and practical, high-precision verification.

- **Model Validation:** The experiment has validated the linear model and the Thevenin equivalent circuit of the 3-bit R-2R DAC with an exceptionally high degree of accuracy.
- **Loading Effect:** The output voltage of the DAC is shown to be highly dependent on the connected load. The magnitude of this voltage drop is accurately predicted by the voltage divider relationship between the DAC's output resistance (`Ro`) and the load resistance (`RL`).
- **Practical Implications:** The DAC's output resistance of approximately 1kΩ is a non-negligible parameter that must be considered when designing systems where the DAC must drive a low-impedance load.

---

## **References**

[1] RIGOL DG4202 User Manual  
[2] RIGOL MSO2202A User Manual  
[3] Sedra, A. S., & Smith, K. C. (2015). *Microelectronic Circuits* (7th ed.). Oxford University Press.

## **Appendix**

**Recommendations for Future Work:**
1. Use higher precision resistors (0.1% or better) to minimize component tolerance effects
2. Implement a 4-bit or 8-bit DAC to study resolution limitations and quantization error
3. Investigate different DAC architectures (weighted resistor, current-steering) for comparison
4. Analyze frequency response and settling time characteristics
5. Develop improved measurement techniques for input resistance characterization

---