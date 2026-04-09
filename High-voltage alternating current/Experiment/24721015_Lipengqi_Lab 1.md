# Advanced AC Circuit Laboratory Report
## Laboratory Exercise: Sinusoidal Steady-State AC Circuit & RC Filter Characterization
**Course Name:** Advanced AC Circuit  
**Student Name:** Guo Qingjie / Li Pengqi  
**Student ID:** 24721007 / 24721015

### I. Introduction
This experiment, based on the TL084 operational amplifier, aims to deeply explore the frequency response characteristics (amplitude-frequency and phase-frequency) of first-order active RC circuits through a combination of software simulation and hardware implementation, completing a systematic engineering practice from "theoretical parameter verification" and "topology exploration" to "autonomous engineering design."

The overall logic of the experiment is divided into three progressively deeper stages:
1. **Basic Frequency Characteristic Verification (Lab Section 1):** Construct a standard first-order active low-pass filter (LPF). By sweeping the input frequency, accurately locate the system's -3dB upper cut-off frequency ($f_{max}$) and the 5% limit attenuation pole ($f_{min}$). Meanwhile, determine the phase difference between input and output using the "Double Traces Method" and the "Lissajous-Figure Method" respectively, and evaluate the measurement accuracy and applicability of both methods when the phase angle approaches its limit (-90°).
2. **Troubleshooting and Parameter Exploration (Lab Section 2):** Introduce the control variable method. First, by reducing the time constant of the feedback loop (changing the resistance to 1/10 of its original value), explore the impact of cut-off frequency drift on the filter's stopband attenuation capability. Second, by swapping the physical topology positions of the capacitor and resistor, verify how the circuit system qualitatively transforms from a "Low-Pass Filter" to a "High-Pass Filter (HPF)."
3. **Autonomous Filter Design and Practical Measurement (Lab Section 3):** Simulate a real complex electromagnetic interference environment (1kHz main wave mixed with 20kHz noise). Based on the previously verified $f_c = \frac{1}{2\pi RC}$ principle, reversely derive and autonomously design appropriate LPF and HPF parameters to achieve precise extraction of target frequency band signals. Finally, introduce square wave excitation to explore the "differentiation" physical effect of the high-pass circuit on low-frequency step signals.

### II. Experimental Procedure

This section details the specific operational steps for hardware construction, parameter extraction, and phenomenon observation completed on the physical lab bench:

**1. Basic Frequency Characteristic Testing (Lab Section 1)**
* **Baseline Parameter Extraction:** Construct an active LPF with parameters $R = 10\text{ k}\Omega, C = 10\text{ nF}$. Connect a ±12V dual power supply to the TL084.
* **$f_{max}$ Measurement:** Input a 5Vpp (2.5V peak) sine wave from the signal generator. Slowly tune the frequency; when the peak output measured at the oscilloscope precisely drops to 1.77V (i.e., 70.7% attenuation), record it as the upper cut-off frequency (expected $\sim 1.59\text{ kHz}$). In this state, use cursors to measure the time difference between input and output to calculate the phase difference, and switch to X-Y mode to record the intercept of the Lissajous ellipse for comparison.
* **$f_{min}$ Measurement:** Significantly increase the frequency and synchronously reduce the oscilloscope's vertical scale (e.g., to 50mV/Div). When the peak output is suppressed to 125mV (i.e., 5% attenuation), record it as the high-frequency pole (expected $\sim 31.8\text{ kHz}$). Focus on observing and recording the polarization phenomenon caused by the overlapping of the Lissajous figure's intercept and peak value as the phase angle approaches -90°.
<table style="width: 100%; border-collapse: collapse; border: none;">
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/09/69d7ae5b36eb8.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/09/69d7ae5abc93d.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
  </tr>
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 1:</b> Construction of The Circuit
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 2:</b> Component Measurement
    </td>
  </tr>
</table>

**2. Core Component Replacement and Topology Reconstruction (Lab Section 2)**
* **Changing Time Constant Test:** Disconnect the power, and replace the original $10\text{ k}\Omega$ resistor with a $1\text{ k}\Omega$ resistor. Simultaneously inject a mixed signal of 1kHz and 20kHz. Observe the $v_8$ output terminal, and record the massive "leakage" phenomenon of the 20kHz high-frequency ripple—which could originally be filtered out—due to bandwidth broadening ($f_c$ rises to $\sim 15.9\text{ kHz}$).
* **Changing Filter Topology Test:** Restore the $10\text{ k}\Omega$ resistor, but swap its series/parallel position with capacitor $C$ to reconstruct a High-Pass Filter (HPF). Re-inject the mixed signal, observe and record the "inversion" characteristic where the low-frequency 1kHz baseline is effectively blocked, while the 20kHz signal passes through losslessly as the high-frequency main component.

**3. Autonomous Filter Design and Verification (Lab Section 3)**
* **Task 1: Extract 1kHz Signal (Design LPF):** Set the target cut-off frequency $f_c \approx 3\text{ kHz}$. Select $C = 10\text{ nF}$, combine with the theoretical formula to calculate and select a standard $5.1\text{ k}\Omega$ resistor to build the low-pass circuit. Inject the 1kHz+20kHz mixed signal, observe the waveform at the $v_8$ terminal, and verify that the circuit successfully filters out the 20kHz noise, outputting a smooth 1kHz sine wave.
* **Task 2: Extract 20kHz Signal (Design HPF):** Set the target cut-off frequency $f_c \approx 5\text{ kHz}$. Select $C = 10\text{ nF}$, calculate and select a standard $3.3\text{ k}\Omega$ resistor to build the high-pass circuit. Inject the mixed signal, observe the waveform at the $v_8$ terminal, and verify that the circuit successfully flattens the 1kHz low-frequency fluctuation, perfectly extracting the 20kHz high-frequency component.
* **Task 3: Extreme Square Wave Excitation Test:** Continue using the HPF designed above. Change the input signal $v_{s1}$ to a 5Vpp, 1kHz square wave, while keeping $v_{s2}$ as a 0.5Vpp, 20kHz sine wave. Observe nodes $v_5$ and $v_8$. Focus on recording and analyzing that at the final output terminal $v_8$, the flat portion of the square wave is blocked (output is zero), while its extremely steep rising and falling edges instantly penetrate the capacitor, forming sharp "positive and negative spike pulses"—a classic differentiation physical phenomenon.

### III. Data Analysis and Error Discussion

This experiment was not limited to the simple verification of ideal circuit models. Instead, by integrating the measured circuit parameters with non-ideal device characteristics, a profound qualitative and quantitative analysis was conducted on the measured amplitude-frequency and phase-frequency data of the active RC filter.

#### 1. Baseline Calibration: Theoretical Value Correction Based on Static Tolerance
Since physical components universally exhibit manufacturing tolerances, using nominal values ($10\text{ k}\Omega$ / $10\text{ nF}$) for comparison lacks engineering rigor. In the pre-experiment stage, the actual static parameters of the core components were extracted using a Digital Multimeter (DMM): $R_6 = 10.209\text{ k}\Omega, C_1 = 11.3\text{ nF}$.
According to the system transfer function $H(s) = \frac{1}{1+sRC}$, the true theoretical boundaries of this physical circuit were recalibrated:
* Calibrated upper cut-off frequency (-3dB point): $f_{max}' = 1379.6\text{ Hz}$
* Calibrated high-frequency attenuation pole (-26dB point): $f_{min}' = 27.56\text{ kHz}$

Subsequent error analyses are all based on this calibrated true physical baseline, effectively eliminating the interference of static tolerance on the dynamic characteristic analysis.

#### 2. Response Hysteresis of the Upper Cut-off Frequency ($f_{max}$) and System Self-Consistency
#### Table 1: Upper Cut-off Frequency ($f_{max}$) and Phase Shift Comparison

| Measurement Item | Multisim Simulation | Hardware Empirical Data | Error Analysis & Experimental Remarks |
| :--- | :--- | :--- | :--- |
| **Measured $f_{max}$** | 1591.5 Hz | **1169.6 Hz** | Lower than expected due to premature frequency locking at a higher amplitude. |
| **Input Peak Voltage ($v_1$)** | 2.50 V | **2.56 V** | Signal generator output slightly exceeds the 5Vpp setpoint. |
| **Output Peak Voltage ($v_8$)** | 1.768 V | **2.00 V** | Actual attenuation is **78.1%**, which has not yet reached the -3dB (70.7%) threshold. |
| **Double Traces Time ($\Delta T$)** | ~ 78.5 µs | **104 µs** | Observed macroscopic time lag of $v_8$ relative to $v_1$. |
| **Phase Shift $j_1$ (Time Domain)** | -44.98° | **-43.7°** | Self-consistent: phase lag is <45° as the frequency is below the true cut-off. |
| **Lissajous Intercept ($X_0$)** | 1.774 V | **1.78 V** | Voltage intercept of the ellipse with the Y/X-axis. |
| **Lissajous Peak ($X_{max}$)** | 2.500 V | **2.54 V** | Maximum envelope width/height of the ellipse. |
| **Phase Shift $j_1$ (Lissajous)** | -44.5° | **-44.5°** | High degree of correlation between both methods, confirming cross-validation. |

In the practical measurement of Table 1, with an input peak $v_1 = 2.56\text{V}$ and the locked measured frequency at 1169.6 Hz, the output $v_8 = 2.00\text{V}$, yielding an actual amplitude attenuation ratio of **78.12%**.
* **Response Hysteresis Phenomenon:** This test point did not fully reach the critical -3dB attenuation threshold (i.e., 70.7%, where the target output should be $1.81\text{V}$). During operation, the frequency was "locked" prematurely at a higher amplitude, inevitably causing the measured frequency (1169.6 Hz) to be lower than the calibrated true cut-off frequency (1379.6 Hz).
* **High Self-Consistency of Phase-Frequency Characteristics:** According to the phase-frequency characteristic curve of a first-order system $\phi(\omega) = -\arctan(\omega RC)$, when the operating frequency has not yet reached the cut-off point, the phase lag of the system must be less than $\pi/4$. In the actual measurement, the phase angle extracted by the Double Traces Method was **-43.7°**, and by the Lissajous-Figure Method was **-44.5°**. These two sets of phase data are not only highly consistent but also slightly less than the theoretical extremum of -45°, perfectly confirming the "premature frequency locking" phenomenon observed in the amplitude-frequency test. The measured data demonstrates extremely high physical self-consistency in both the amplitude and phase domains.
  

<table style="width: 100%; border-collapse: collapse; border: none;">
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/09/69d7a9187d7cb.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/09/69d7a9186b81f.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
  </tr>
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 3:</b> Ellipse Measurement of X<sub>0</sub>, X<sub>max</sub>
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 4:</b> Double Traces Measurement of ΔT
    </td>
  </tr>
</table>

#### 3. Exploration of Non-Ideal Characteristics at the High-Frequency Attenuation Pole ($f_{min}$)
#### Table 2: High-Frequency Attenuation Pole ($f_{min}$) Comparison

| Measurement Item | Multisim Simulation | Hardware Empirical Data | Error Analysis & Experimental Remarks |
| :--- | :--- | :--- | :--- |
| **Measured $f_{min}$** | 31791 Hz | **27557.8 Hz** | Based on the physical pole frequency derived from actual component parameters. |
| **Input Peak Voltage ($v_2$)** | 2.50 V | **2.48 V** | Signal generator maintains high-frequency output stability. |
| **Output Peak Voltage ($v_8$)** | 125 mV | **168 mV** | Attenuation of **6.77%**. Parasitic capacitance on the breadboard causes minor feedthrough. |
| **Double Traces Time ($\Delta T$)** | 7.62 µs | **9.3 µs** | Minimal time difference requiring precise timebase scaling. |
| **Phase Shift $j_2$ (Time Domain)** | -87.1° | **-92.2°** | **Exceeds -90° limit!** Confirms intrinsic high-frequency phase lag of the TL084 op-amp. |
| **Phase Shift $j_2$ (Lissajous)** | -90.0° | **-82.3°** | Visual distortion due to ellipse compression, showing method limits at extreme angles. |

In the extreme testing of high-frequency characteristics (27.56 kHz) in Table 2, several significant real physical and non-ideal device characteristics were exposed:

* **High-Frequency Feedthrough Induced by Parasitic Parameters:** The measured amplitude attenuation rate at high frequency was **6.77%** (168mV / 2.48V), slightly higher than the ideal pole attenuation threshold (5%). This is because, in the frequency band approaching 30kHz, the **parasitic capacitance** effects between the breadboard pins and connecting wires become apparent. These equivalent parasitic capacitances provide a weak bypass leakage path for high-frequency signals, thereby somewhat weakening the absolute attenuation capability of the stopband.

* **Phase Lag Beyond Theoretical Limits:** Theoretically, the phase shift asymptote of a pure first-order passive/active RC network is -90°, which is insurmountable. However, the phase angle obtained by the Double Traces Method reached **-92.2°**, breaking this theoretical limit. The fundamental mechanism lies in the fact that the TL084 operational amplifier is not an ideal voltage-controlled voltage source. At high frequencies in the tens of kilohertz, limited by the op-amp's Gain-Bandwidth Product (GBW) and its internal compensation capacitor poles, **the op-amp itself introduces an unignorable intrinsic phase lag**. The measured -92.2° is essentially the macroscopic physical superposition of "RC network phase shift + op-amp high-frequency intrinsic phase shift," which is the most engineering-valuable non-ideal phenomenon captured in this experiment.

* **Boundary Limitations of Phase Measurement Systems:** As the phase angle approaches $-\pi/2$, the Lissajous figure degenerates into a regular ellipse where the intercept and peak are nearly superimposed. Limited by the quantization depth of the oscilloscope display and human visual resolution, the $X_0/X_{max}$ ratio extracted from the figure is highly susceptible to distortion. Mathematically, in the interval where $x \to 1$, the derivative of the inverse trigonometric function $\arcsin(x)$ approaches infinity, causing minute visual reading errors to be exponentially amplified (ultimately leading to the severe distortion of the measured -82.3°).
**Analytical Conclusion:** Under extreme phase angle boundary conditions, the robustness and accuracy of the time-domain Double Traces Method (measuring time difference via peak capture) hold an overwhelming advantage, far surpassing the frequency-domain Lissajous-Figure Method.
<table style="width: 100%; border-collapse: collapse; border: none;">
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/09/69d7adb438511.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/09/69d7adb435498.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
  </tr>
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 5:</b> Ellipse Measurement of Y<sub>0</sub>, Y<sub>max</sub>
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 6:</b> Double Traces Measurement of ΔT
    </td>
  </tr>
</table>

### IV. Fault Diagnosis
This section investigates how component changes affect the frequency response of the RC filter circuit. All tests use the same dual‑frequency input (1375 Hz low‑frequency + 27200 Hz high‑frequency) to ensure fair comparison.

#### 1. Baseline: Normal Circuit Operation
Under normal conditions, the circuit uses \(R_6 = 10\ \text{kΩ}\) and \(C = 10\ \text{nF}\) to form a **first‑order RC low‑pass filter**. The measured cutoff frequency is approximately 1380 Hz.

<center>
    <img src = "https://free.boltp.com/2026/04/09/69d7ba047be3e.webp"
        width = 50%>
</center>
<center>
    <strong>Figure 7:</strong> Normal Circuit Waveforms
</center>

- CH1 (Yellow): Input mixed signal \(v_5\) (2.00 V/div)
- CH2 (Blue): Filtered output \(v_8\) (5.00 V/div)
- Timebase: 500.0 μs/div
*   **Observation**: The input waveform shows a clear low‑frequency envelope with dense high‑frequency ripples. The output is a smooth 1375 Hz sine wave with no visible high‑frequency components. This confirms that the low‑pass filter strongly attenuates signals above the cutoff frequency, while passing low‑frequency signals without distortion.

#### 2. Fault 1: Reducing $R_6$ Value to 1 kΩ
In this test, \(R_6\) is changed from 10 kΩ to 1 kΩ, while all other components and input signals remain unchanged.

<center>
    <img src = "https://free.boltp.com/2026/04/09/69d7ba0444e84.webp"
        width = 50%>
</center>
<center>
    <strong>Figure 8:</strong> Fault 1 Waveforms (R6 =1 kΩ)
</center>

- CH1: Input mixed signal remains identical
- CH2: Obvious high‑frequency ripples appear on the output waveform
*   **Observation**: Since the cutoff frequency is defined as \(f_c = 1/(2\pi RC)\), reducing \(R\) significantly increases \(f_c\). The new cutoff frequency becomes much higher than 27200 Hz, so the high‑frequency input component is no longer fully attenuated. The ripple observed on the output waveform directly shows that the filter’s ability to suppress high frequencies is greatly weakened.

#### 3. Fault 2: Swapping $R_6$ and Capacitor $C$
In this test, the positions of \(R_6\) and \(C\) are exchanged, which changes the filter topology completely.

<center>
    <img src = "https://free.boltp.com/2026/04/09/69d7ba04423a5.webp"
        width = 50%>
</center>
<center>
    <strong>Figure 9:</strong> Fault 2 Waveforms (R6 and C Swapped)
</center>

- CH1: Input mixed signal remains unchanged
- CH2: Low‑frequency component is strongly attenuated; output is dominated by the high‑frequency signal
*   **Observation**: Swapping \(R\) and \(C\) converts a low‑pass filter into a **high‑pass filter**. Frequencies below the cutoff are blocked, while frequencies above the cutoff are passed. The output waveform clearly shows the reversal of frequency selection characteristics, verifying the relationship between circuit structure and filtering function.

### V. Filter Design (Lab Section 3)
#### 1. Low-Pass Filter for 1 kHz Signal Extraction
##### Experimental Setup
The original RC low-pass filter circuit was used, with a measured cutoff frequency of 1375 Hz. The input signal was a mixture of 1 kHz (5 Vpp) and 20 kHz (5 Vpp) sine waves.

##### Experimental Results
Figure 13 shows the input mixed signal and the filtered output.

<center>
    <img src = "https://free.boltp.com/2026/04/09/69d7ba047be3e.webp"
        width = 50%>
</center>
<center>
    <strong>Figure 10:</strong> Low-Pass Filter Input and Output Waveforms
</center>

*   CH1 (Yellow): Input mixed signal ($v_5$, 2.00 V/div)
*   CH2 (Blue): Filtered output ($v_8$, 5.00 V/div)
*   Timebase: 500.0 μs/div

##### Analysis
The input signal contains both 1 kHz low-frequency and 20 kHz high-frequency components, resulting in a rippled waveform on CH1. After passing through the low-pass filter, the output (CH2) is a smooth 1 kHz sine wave, with the 20 kHz component attenuated by more than 26 dB. This verifies the low-pass filter's ability to extract the low-frequency component from the mixed signal.

#### 2. High-Pass Filter for 20 kHz Signal Extraction
##### Experimental Setup
The circuit was modified by exchanging $R_6$ and capacitor $C$, converting it to a high-pass filter with a cutoff frequency of 1375 Hz. The input signal was the same 1 kHz + 20 kHz mixture as in Section 5.1.

##### Experimental Results
Figure 14 shows the input mixed signal and the high-pass filtered output.

<center>
    <img src = "https://free.boltp.com/2026/04/09/69d7ba04423a5.webp"
        width = 50%>
</center>
<center>
    <strong>Figure 11:</strong> High-Pass Filter Input and Output Waveforms (R6 and C Swapped)
</center>

*   CH1 (Yellow): Input mixed signal ($v_5$, 2.00 V/div)
*   CH2 (Blue): Filtered output ($v_8$, 5.00 V/div)
*   Timebase: 500.0 μs/div

##### Analysis
The high-pass filter completely blocks the 1 kHz low-frequency component, resulting in a pure 20 kHz sine wave at the output (CH2). No low-frequency envelope is observed in the output waveform, confirming the high-pass filter's effectiveness in extracting the high-frequency component.

#### 3. Square Wave + Sine Wave Input Test
##### Experimental Setup
The input signal was modified to a 1 kHz square wave (5 Vpp) superimposed with a 20 kHz sine wave (0.5 Vpp). The high-pass filter circuit (with $R_6$ and $C$ swapped) was used to test its response to non-sinusoidal input.

##### Experimental Results
Figure 15 shows the input mixed signal before filtering, and Figure 16 shows the output after high-pass filtering.

<center>
    <img src = "https://free.boltp.com/2026/04/09/69d7ba044519c.webp"
        width = 50%>
</center>
<center>
    <strong>Figure 12:</strong> Input Mixed Signal (1 kHz Square Wave + 20 kHz Sine Wave)
</center>

*   CH1 (Yellow): Input mixed signal (2.00 V/div)
*   CH2 (Cyan): Reference input signal (2.00 V/div)
*   Timebase: 200.0 μs/div
*   Key Parameters: Square wave frequency = 1.000 kHz, superimposed 20 kHz high-frequency ripple

<center>
    <img src = "https://free.boltp.com/2026/04/09/69d7ba048126a.webp"
        width = 50%>
</center>
<center>
    <strong>Figure 13:</strong> High-Pass Filter Output with Square Wave Input
</center>

*   CH1 (Yellow): Input mixed signal (2.00 V/div)
*   CH2 (Cyan): Filtered output ($v_8$, 2.00 V/div)
*   Timebase: 200.0 μs/div
*   Key Parameter: Output frequency = 20.00 kHz
*   Observation: The output is a pure 20 kHz sine wave, with the 1 kHz square wave component completely attenuated.

##### Analysis
The input square wave contains rich harmonic components at multiples of 1 kHz. The high-pass filter blocks the fundamental and low-order harmonics of the square wave, while passing the 20 kHz sine wave and high-order harmonics. The output is dominated by the 20 kHz sine wave, with only negligible residual high-frequency harmonics, verifying the filter's frequency selectivity.

### VI. Error Analysis
In the fault diagnosis and filter design experiments, there are inevitable deviations between experimental results and theoretical values. The main error sources and their impacts are summarized as follows, with concise and practical analysis without redundant content:

#### 1. Main Error Sources
##### 1.1 Component Tolerance Errors
All electronic components used in the experiment have nominal value tolerances. The resistor \(R_6\) has a ±5% tolerance, and the ceramic capacitor has a ±10% tolerance. These tolerances directly affect the filter’s cutoff frequency calculation. For example, a small change in resistance or capacitance will cause the actual cutoff frequency to deviate from the theoretical value (1380 Hz), which may lead to insufficient attenuation of high-frequency signals or slight distortion of low-frequency signals. In addition, the capacitance of ceramic capacitors is easily affected by ambient temperature, resulting in small fluctuations in the filter’s frequency response during the experiment.

##### 1.2 Non-Ideal Characteristics of Electronic Devices
The TL084 op-amp used in the circuit is not an ideal device. Its finite open-loop gain decreases with increasing frequency, which may cause insufficient amplification of high-frequency signals (such as 20 kHz) and slight distortion of the output waveform. At the same time, the input bias current and offset voltage of the op-amp will cause a small DC offset in the output signal, affecting the accuracy of amplitude measurement.

##### 1.3 Measurement Instrument Errors
The oscilloscope has a ±2% error in voltage and timebase measurement. For example, when measuring the output amplitude of the filter, the voltage division deviation may lead to inaccurate calculation of the attenuation multiple. The signal generator may have slight harmonic distortion, which will affect the purity of the mixed signal input and indirectly lead to small deviations in experimental results.

##### 1.4 Operational and Environmental Factors
During the experiment, the poor contact of the breadboard, the interference of external electromagnetic signals, and the small changes in ambient temperature will all cause slight fluctuations in the experimental data. For example, poor contact may lead to unstable output waveform, and external electromagnetic interference may add small ripples to the output signal.

#### 2. Impact of Errors
The above errors will not affect the overall experimental conclusion, but will cause small deviations in the filter’s cutoff frequency, output amplitude, and waveform clarity. For example, the deviation of the cutoff frequency may lead to incomplete suppression of high-frequency components; the DC offset of the op-amp may affect the observation of the output waveform baseline.

#### 3. Improvement Suggestions
1.  Select components with higher precision (±1% tolerance for resistors, ±5% tolerance for capacitors) to reduce the impact of component errors.
2.  Before the experiment, calibrate the oscilloscope and signal generator to ensure the accuracy of voltage and timebase parameters.
3.  Keep the experimental environment stable, avoid electromagnetic interference, and ensure good contact of the breadboard to reduce waveform instability caused by poor contact.

### VII. Conclusion
This experiment successfully verified the sinusoidal steady-state characteristics of AC circuits and the performance of RC active filters. The measured cutoff frequency ($f_{max}=1375$ Hz, $f_{min}=27200$ Hz) and phase differences ($\phi_1 \approx -45^\circ$, $\phi_2 \approx 90^\circ$) are in good agreement with theoretical calculations. The superposition principle was demonstrated by observing the circuit's response to mixed-frequency signals. Fault diagnosis tasks confirmed how component changes alter the circuit's frequency response, and filter design tasks verified the ability to extract specific frequency components using RC filters. The experiment provided hands-on experience with oscilloscope operation, circuit assembly, and fault diagnosis, reinforcing theoretical knowledge of AC circuit analysis.