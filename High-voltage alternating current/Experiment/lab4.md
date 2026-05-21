

## 1. Introduction

Active filters consist of combinations of resistors, capacitors, and operational amplifiers. Compared to traditional passive RLC filters, active filters offer the following significant advantages:

1. **No inductors required**: Eliminating bulky and expensive inductors makes it feasible to realize filters in integrated circuits, reducing both overall size and cost.
2. **Signal gain**: In addition to achieving specific frequency responses, operational amplifiers can provide voltage or power gain.
3. **Excellent impedance isolation**: Active filters can be easily combined with buffer amplifiers (voltage followers) to isolate each filter stage from source and load impedance effects. This isolation allows designers to construct each stage independently and then cascade them to realize the desired transfer function.

**Objective:**
This experiment aims to build second-order Sallen-Key active low-pass and high-pass filters on a breadboard, and cascade them to form a band-pass filter. By using a function waveform generator, digital oscilloscope, and digital multi-meter, we will practically measure and characterize the magnitude and phase responses of each filter, thereby deepening our understanding of frequency selectivity and phase shift characteristics in high-order active filters.

**Core Components & Instruments:**

* Integrated Operational Amplifier: TL084 (Quad op-amp)
* Component nominal values: Resistors $R = 10\text{ k}\Omega$, Capacitors $C = 1\text{ nF}$ and $10\text{ nF}$
* Measuring Instruments: Function waveform generator, digital oscilloscope, digital multi-meter, DC power supply.

---

## 2. Experimental Section

### 2.1 Circuit Setup Instructions

On the breadboard, independently build the second-order low-pass filter (Fig. 1a) and the second-order high-pass filter (Fig. 1b). The operational amplifiers are uniformly configured as voltage followers to provide inter-stage buffering. After completing the independent measurements, cascade the circuits by connecting the output of the low-pass filter directly to the input of the high-pass filter to form the band-pass filter system. During testing, a DC power supply provides a constant $\pm 12\text{V}$ to the op-amp chip.

<div style="display: flex; justify-content: space-between; width: 100%; margin-bottom: 20px;">
  
  <div style="width: 48%; display: flex; flex-direction: column; align-items: center; text-align: center;">
    <img src="https://free.boltp.com/2026/05/21/6a0eacd961b5b.webp" style="height: 250px; max-width: 100%; object-fit: contain; margin-bottom: 8px; display: block;" />
    <span style="font-size: 14px; line-height: 1.5;"><b>Figure 1:</b> Circuit construction of high-pass filter.</span>
  </div>

  <div style="width: 48%; display: flex; flex-direction: column; align-items: center; text-align: center;">
    <img src="https://i.cetsteam.com/imgs/2026/05/21/2922cccf8ee568d8.jpg" style="height: 250px; max-width: 100%; object-fit: contain; margin-bottom: 8px; display: block;" />
    <span style="font-size: 14px; line-height: 1.5;"><b>Figure 2:</b> Circuit construction of band-pass filter. (Right below is low-pass filter)</span>
  </div>

</div>

### 2.2 Measured Data Tables

The input voltage rms $v_s$ is uniformly set to a $0\text{ dB}$ reference (monitored and kept constant via oscilloscope CH1 during actual measurements). The output voltage rms $v_o$ is measured using the AC voltage mode of the digital multi-meter and converted to decibels (dB). The phase difference $\varphi$ is measured using the double traces method on the oscilloscope. The time delay $\Delta t$ is calculated based on the measured data.



#### Table 1. Data for low-pass filter

| Source frequency $f$ (kHz) | 0.1 | 1 | 10 | 50 | 100 | 150 |
| --- | --- | --- | --- | --- | --- | --- |
| **Voltage Gain $\vert V_o / V_s \vert$ (dB)** | 0 | 0 | -2.16 | -25.2 | -37.6 | -45.0 |
| **Time Delay $\Delta t$** | 0 | 20 $\mu$s | 21.6 $\mu$s | 9 $\mu$s | 4.84 $\mu$s | 3.38 $\mu$s |
| **Phase Difference $\varphi$ (Deg)** | 0 | -7.2 | -77.8 | -162 | -174.2 | -182.5 |

#### Table 2. Data for high-pass filter

| Source frequency $f$ (kHz) | 0.1 | 0.5 | 1 | 10 | 100 | 150 |
| --- | --- | --- | --- | --- | --- | --- |
| **Voltage Gain $\vert V_o / V_s \vert$ (dB)** | -40.90 | -13.28 | -3.57 | -0.058 | 0 | 0 |
| **Time Delay $\Delta t$** | 4.78 $\mu$s | 0.78 $\mu$s | 0.268 $\mu$s | 2.4 $\mu$s | 20 ns | 0 |
| **Phase Difference $\varphi$ (Deg)** | 172.1 | 140.4 | 96.48 | 8.64 | 0.72 | 0 |

#### Table 3. Data for band-pass filter

| Source frequency $f$ (kHz) | 0.1 | 0.5 | 1 | 4 | 7 | 10 | 50 | 100 | 150 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| **Voltage Gain $\vert V_o / V_s \vert$ (dB)** | -40.80 | -13.12 | -3.44 | 0.09 | -0.82 | -2.66 | -28.73 | -40.21 | -45.06 |
| **Time Delay $\Delta t$ (Calculated)** | **4.82 ms** | **759.4 $\mu$s** | **241.4 $\mu$s** | **6.11 $\mu$s** | **17.74 $\mu$s** | **20.94 $\mu$s** | **9.04 $\mu$s** | **4.79 $\mu$s** | **3.25 $\mu$s** |
| **Phase Difference $\varphi$ (Deg)** | 173.6 | 136.7 | 86.9 | -8.8 | -44.7 | -75.4 | -162.8 | -172.6 | -175.5 |

<div style="display: flex; justify-content: space-between; width: 100%; margin-bottom: 20px;">
  
  <div style="width: 48%; display: flex; flex-direction: column; align-items: center; text-align: center;">
    <img src="https://free.boltp.com/2026/05/21/6a0eacd86913d.webp" style="height: 250px; max-width: 100%; object-fit: contain; margin-bottom: 8px; display: block;" />
    <span style="font-size: 14px; line-height: 1.5;"><b>Figure 3:</b> Obtain waveform graph</span>
  </div>

  <div style="width: 48%; display: flex; flex-direction: column; align-items: center; text-align: center;">
    <img src="https://free.boltp.com/2026/05/21/6a0eacd80d9b9.webp" style="height: 250px; max-width: 100%; object-fit: contain; margin-bottom: 8px; display: block;" />
    <span style="font-size: 14px; line-height: 1.5;"><b>Figure 4:</b> Measurement of phase difference</span>
  </div>

</div>

#### Table 4. Data for $-3\text{ dB}$ frequencies

| Filter Type | Cutoff Frequency $f_{-3\text{dB}}$ | Characteristic Phase $\varphi_{-3\text{dB}}$ (Deg) |
| --- | --- | --- |
| **Low-pass $f_{LP-3dB}$** | 11.3 kHz | -84.6 |
| **High-pass $f_{HP-3dB}$** | 1.1 kHz | 87.12 |
| **Band-pass Lower $f_{L-3dB}$** | 1.01 kHz | 84.2 |
| **Band-pass Upper $f_{H-3dB}$** | 10.8 kHz | -82.1 |



---

## 3. Theory Analysis & Calculation

### 3.1 Transfer Function Derivation

This experiment utilizes a second-order voltage-controlled voltage source (VCVS) active RC filter topology. Because the operational amplifier is configured as an ideal voltage follower, the non-inverting input voltage equals the output voltage ($V_+ = V_o$), and the input impedance is assumed infinite. Using phasor analysis, Kirchhoff's Current Law (KCL) equations are written at the key nodes:

1. **Low-pass transfer function $H_{LP}(j\omega)$:**
By applying KCL at the intermediate node $V_1$ and the non-inverting input $V_+$, and eliminating $V_1$, we derive:

$$H_{LP}(j\omega) = \frac{V_o}{V_s} = \frac{1}{1 - 2\omega^2 R_1^2 C_1^2 + j(2\omega R_1 C_1)}$$



Let the time constant be $\tau_1 = R_1 C_1$:
* Magnitude: $|H_{LP}(j\omega)| = \frac{1}{\sqrt{(1 - 2\omega^2 \tau_1^2)^2 + (2\omega \tau_1)^2}} = \frac{1}{\sqrt{1 + 4\omega^4 \tau_1^4}}$
* Phase difference: $\phi_{LP} = -\arctan\left(\frac{2\omega \tau_1}{1 - 2\omega^2 \tau_1^2}\right)$


2. **High-pass transfer function $H_{HP}(j\omega)$:**
Similarly, by swapping the positions of the resistors and capacitors in the low-pass circuit, we derive the following via KCL:

$$H_{HP}(j\omega) = \frac{V_o}{V_s} = \frac{-2\omega^2 R_2^2 C_2^2}{1 - 2\omega^2 R_2^2 C_2^2 + j(2\omega R_2 C_2)}$$



Let the time constant be $\tau_2 = R_2 C_2$:
* Magnitude: $|H_{HP}(j\omega)| = \frac{2\omega^2 \tau_2^2}{\sqrt{1 + 4\omega^4 \tau_2^4}}$
* Phase difference: $\phi_{HP} = 180^{\circ} - \arctan\left(\frac{2\omega \tau_2}{1 - 2\omega^2 \tau_2^2}\right)$


3. **Cascaded band-pass transfer function $H_{BP}(j\omega)$:**
Because the cascaded op-amps provide perfect impedance isolation, the total transfer function of the system is the product of the two stages:

$$H_{BP}(j\omega) = H_{LP}(j\omega) \cdot H_{HP}(j\omega)$$


* Gain (dB): $Gain_{BP}(dB) = Gain_{LP}(dB) + Gain_{HP}(dB)$
* Phase difference: $\phi_{BP} = \phi_{LP} + \phi_{HP}$



### 3.2 Cutoff Frequency Theoretical Calculation

Based on the nominal design parameters $R_1 = R_2 = 10\text{ k}\Omega$, $C_1 = 1\text{ nF}$, and $C_2 = 10\text{ nF}$, the half-power (-3dB) cutoff frequencies for the second-order filters are calculated as follows:

* **Low-pass theoretical cutoff:** 
$$f_{LP-3dB} = \frac{1}{2\pi \sqrt{2} R_1 C_1} = \frac{1}{2\pi \times \sqrt{2} \times 10^4 \times 10^{-9}} \approx 11.25\text{ kHz}$$


* **High-pass theoretical cutoff:** 
$$f_{HP-3dB} = \frac{1}{2\pi \sqrt{2} R_2 C_2} = \frac{1}{2\pi \times \sqrt{2} \times 10^4 \times 10^{-8}} \approx 1.125\text{ kHz}$$



### 3.3 Time Delay and Phase Conversion Formula

In a sinusoidal AC steady-state circuit, the time delay $\Delta t$ represents the absolute translation of the output waveform relative to the input waveform on the time axis. It has a precise linear relationship with the frequency $f$ and the phase difference $\varphi$:


$$\Delta t = \frac{|\varphi|}{360^{\circ} \times f}$$


*Calculation example (using the $1\text{ kHz}$ test point in Table 3):*
Given $f = 1000\text{ Hz}$, and measured phase difference $\varphi = 86.9^{\circ}$:


$$\Delta t = \frac{86.9^{\circ}}{360^{\circ} \times 1000\text{ Hz}} \approx 2.414 \times 10^{-4}\text{ s} = 241.4\text{ }\mu\text{s}$$

---

## 4. Reflection & Summary

### 4.1 Frequency Selectivity Analysis

The measured data perfectly demonstrates the frequency selectivity behaviors of these three filter networks.

1. The **low-pass filter** exhibits a flat passband of 0dB in the low-frequency range (0.1k - 1kHz), attenuates slowly to -2.16dB near its cutoff frequency of 11.3kHz, and plummets sharply to -45.0dB in the high-frequency stopband (150kHz). This proves the circuit's ability to precisely eliminate high-frequency noise.
2. Conversely, the **high-pass filter** shows a deep suppression of -40.90dB at the extremely low frequency of 0.1kHz. It rises rapidly after crossing the 1.1kHz cutoff frequency and stably maintains 0dB with no phase shift in the high-frequency passband (100k - 150kHz).
3. The **cascaded band-pass filter** successfully synthesizes the frequency boundaries of both, displaying a distinct "peak-shaped" frequency selection characteristic. The measured upper cutoff limit is 10.8kHz and the lower limit is 1.01kHz, resulting in an effective bandwidth of $BW = 10.8 - 1.01 = 9.79\text{ kHz}$. Signals pass almost losslessly (gain 0.09dB) near the center frequency of 4kHz, while experiencing over 40dB of attenuation at both stopband extremes.

### 4.2 Differences Between 1st-order and 2nd-order Filters

Compared to basic 1st-order filters, the 2nd-order filters constructed in this experiment reveal unique higher-order physical characteristics in their magnitude and phase curves:

* **Steeper Roll-off Rate:** A 1st-order filter has a theoretical stopband roll-off of -20dB/dec. As seen in the measured data for the low-pass filter (Table 1), the gain drops from -2.16dB at 10kHz to -37.6dB at 100kHz (spanning one decade). This attenuation slope approaches **-40dB/dec**, strongly proving that 2nd-order active filters possess a narrower transition band and sharper attenuation of out-of-band interference.
* **Characteristic Phase Shift at Cutoff:** A 1st-order filter has a theoretical phase shift of $\pm 45^{\circ}$ at the cutoff frequency. In this experiment, based on Table 4, the measured phase shift is **-84.6°** at the low-pass cutoff and **87.12°** at the high-pass cutoff. Both values closely approximate the theoretical **$\pm 90^{\circ}$**, clearly demonstrating the 2nd-order nature of the circuits on an experimental level.


---

### 4.3 Global Frequency Response Curves (Bode Plots)

To visually evaluate the global performance and transition trends of the constructed circuits, the semilogarithmic magnitude and phase response curves were plotted based on the practical data measured in the laboratory. These Bode plots provide a clear, continuous view of the frequency selectivity across the entire tested spectrum.
<div align="center">
  <img src="https://free.boltp.com/2026/05/21/6a0eacd5721c5.webp" alt="Figure_1" width="60%" />
  <p><b>Figure 4.3.1:</b> The semilogarithmic magnitude and phase response curves of low-pass filter</p>
</div>
<div align="center">
  <img src="https://free.boltp.com/2026/05/21/6a0eacd54a1a2.webp" alt="Figure_2" width="60%" />
  <p><b>Figure 4.3.2:</b> The semilogarithmic magnitude and phase response curves of high-pass filter</p>
</div>
<div align="center">
  <img src="https://free.boltp.com/2026/05/21/6a0eacd833842.webp" alt="Figure_3" width="60%" />
  <p><b>Figure 4.3.3:</b> The semilogarithmic magnitude and phase response curves of band-pass filter</p>
</div>


### 4.4 Extension and Reflection: Band-pass Filter Autonomous Design

After completing the measurement with the given parameters, our group conducted an extended thought experiment on the reverse design of the Sallen-Key active filter topology shown in Figure 1. Our objective was to design a band-pass filter with a lower cutoff frequency of $3\text{ kHz}$ and an upper cutoff frequency of $30\text{ kHz}$ by re-selecting the resistor and capacitor values.

**1. Theoretical Calculation and Component Selection:**
According to the half-power point formula for second-order active RC filters, $f_{-3dB} = \frac{1}{2\pi \sqrt{2} RC}$, we can derive the required RC time constants.

* **High-pass Design (Target $f_L = 3\text{ kHz}$):**

$$R_2 C_2 = \frac{1}{2\pi \sqrt{2} \times 3000} \approx 3.751 \times 10^{-5}\text{ s}$$



To ensure high-frequency coupling, a capacitor $C_2 = 10\text{ nF}$ was selected. The theoretically required resistance is $R_2 \approx 3.75\text{ k}\Omega$.
* **Low-pass Design (Target $f_H = 30\text{ kHz}$):**

$$R_1 C_1 = \frac{1}{2\pi \sqrt{2} \times 30000} \approx 3.751 \times 10^{-6}\text{ s}$$



To filter out high-frequency noise, a smaller capacitor $C_1 = 1\text{ nF}$ was selected. The theoretically required resistance is $R_1 \approx 3.75\text{ k}\Omega$.

**2. Practical Engineering Implementation:**
Considering that $3.75\text{ k}\Omega$ is not a standard fixed resistance value in the E12 series, we proposed the following two alternative solutions for actual hardware construction to approximate the theoretical value:

* Solution 1: Use two $10\text{ k}\Omega$ precision adjustable potentiometers and adjust them accurately to $3.75\text{ k}\Omega$ using a digital multimeter before connecting them to the circuit.
* Solution 2: Connect standard $3.3\text{ k}\Omega$ and $470\text{ }\Omega$ resistors in series (total resistance $3.77\text{ k}\Omega$). The error of this solution is minimal and fully meets the engineering requirements for a $3\text{ kHz} \sim 30\text{ kHz}$ band-pass characteristic.

**3. Verification and Summary:**
The design scheme above demonstrates that the voltage follower-based Sallen-Key topology possesses strong modular design capabilities. Because the operational amplifiers isolate inter-stage impedance, we can independently calculate and debug the high-pass and low-pass sections, and finally achieve the desired band-pass frequency response range easily through cascading. This fully reflects the flexibility and superiority of active filters in modern signal processing circuit design.

### 4.5 Data-Driven Error Analysis and Experimental Reflection

While the overall trajectories in the Bode plots closely align with the theoretical mathematical models, a deep examination of the specific data points in Tables 1 through 4 reveals subtle, highly authentic physical deviations. These specific deviations and their root causes are analyzed below:

**1. The "Bandwidth Shrinkage" Phenomenon in Cascading (Tables 1, 2 vs. 4)**
A critical observation lies in the cutoff frequencies before and after cascading. In isolated measurements, the high-pass cutoff is $f_{HP} = 1.1\text{ kHz}$ and the low-pass cutoff is $f_{LP} = 11.3\text{ kHz}$. However, when cascaded to form the band-pass filter (Table 4), the cutoffs shifted *inward* to $f_L = 1.01\text{ kHz}$ and $f_H = 10.8\text{ kHz}$.

* **Cause:** This ~4% bandwidth shrinkage is a classic hardware signature of stage-loading and overlapping transfer functions. Even though the TL084 op-amp is configured as a voltage follower to provide isolation, the input parasitic capacitance of the second stage still presents a marginal load to the first stage. Furthermore, the transfer functions multiply ($H_{BP} = H_{LP} \times H_{HP}$); since the high-pass filter is not perfectly $0\text{ dB}$ at $10.8\text{ kHz}$ (it has a slight insertion loss), it drags the overall cascaded gain down to $-3\text{ dB}$ slightly earlier than the isolated low-pass filter would.

**2. Passband Gain Peaking (Table 3 at $4\text{ kHz}$)**
Theoretically, a Sallen-Key filter with a unity-gain follower ($K=1$) and perfectly matched RC components is critically damped ($Q = 0.5$), meaning the passband gain should never exceed $0\text{ dB}$. However, in Table 3, the band-pass filter exhibits a positive gain of **$+0.09\text{ dB}$** at $4\text{ kHz}$.

* **Cause:** This is not a measurement error, but a real manifestation of component tolerance. The $10\text{ k}\Omega$ resistors and ceramic capacitors have real-world manufacturing tolerances ($\pm 5\%$ or $\pm 10\%$). A slight mismatch in these values naturally alters the Q-factor of the filter, pushing it slightly above $0.5$. This results in a microscopic under-damped response, producing the tiny $+0.09\text{ dB}$ resonance peak observed right in the center of the passband.

**3. Systematic Phase Deviation and Oscilloscope Resolution Limits (Table 4)**
For a second-order filter, the theoretical phase shift at the $-3\text{ dB}$ cutoff is precisely $\pm 90^{\circ}$. Our measured phases were **$-84.6^{\circ}$** (Low-pass) and **$87.12^{\circ}$** (High-pass).

* **Cause:** While parasitic capacitance accounts for some phase lag, the primary source of this specific deviation is the visual resolution limit of the oscilloscope during the double traces measurement. Taking the low-pass filter as an example: at $11.3\text{ kHz}$, the signal period is $T \approx 88.5\text{ }\mu\text{s}$. A phase error of $5.4^{\circ}$ (the difference between $90^{\circ}$ and $84.6^{\circ}$) corresponds to a $\Delta t$ reading error of merely **$1.3\text{ }\mu\text{s}$**. On a standard digital oscilloscope screen, $1.3\text{ }\mu\text{s}$ represents just 1 to 2 pixels on the horizontal axis. Therefore, this phase deviation is bounded by the hardware's sampling rate and the limits of manual cursor alignment on the zero-crossing points.
* **Improvement:** In future practices, utilizing the oscilloscope's automated `Measure -> Phase` digital calculation function, rather than manually aligning cursors over waveforms, would easily eliminate this pixel-level human error.
