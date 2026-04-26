# PRE-LABORATORY REPORT

**Experiment:** Laboratory Exercise No: 3 – Measurement for Transfer Function
**Course:** Advanced AC Circuit
**Name:** Li Pengqi 
**Student ID:** 24721015

## 1. Objectives
1. To deeply understand the concepts of driving point impedance and transfer function (voltage gain) in the phasor domain.
2. To apply phasor analysis methods to calculate amplitude and phase responses at various frequencies theoretically.
3. To learn how to simulate AC frequency responses and utilize the Bode Plotter in Multisim to observe magnitude and phase shifts.
4. To prepare the theoretical framework for practical oscilloscope measurements (using double traces and ellipse methods) of voltage, current, and phase differences.

## 2. Theory Analysis and Calculations

### Part A: Driving Point Impedance

#### 1. Circuit in Fig. 1(a) - Parallel/Series Combination
**Given Parameters:** $R = 1.2\text{ k}\Omega$, $C_1 = 0.47\mu\text{F}$, $C_2 = 0.047\mu\text{F}$.
The driving point impedance $Z_{in}$ is the series combination of $C_1$ and the parallel pair of $R$ and $C_2$. The analytical expression is:
$$Z_{in} = Z_{C1} + \left( R \parallel Z_{C2} \right) = \frac{1}{j\omega C_1} + \frac{R \cdot \frac{1}{j\omega C_2}}{R + \frac{1}{j\omega C_2}} = -j\frac{1}{\omega C_1} + \frac{R - j\omega R^2 C_2}{1 + (\omega R C_2)^2}$$

Using angular frequency $\omega = 2\pi f$, we determine the magnitude $|Z_{in}|$ and phase $\angle Z_{in}$:

*   **At f = 500 Hz** ($\omega = 3141.6$ rad/s):
    $Z_{in} = 1163.5 - j883.4\,\Omega$ $\Rightarrow$ **$|Z_{in}| = 1460.8\,\Omega$ , $\angle Z_{in} = -37.2^\circ$**
*   **At f = 2 kHz** ($\omega = 12566.4$ rad/s):
    $Z_{in} = 798.9 - j735.5\,\Omega$ $\Rightarrow$ **$|Z_{in}| = 1086.0\,\Omega$ , $\angle Z_{in} = -42.6^\circ$**
*   **At f = 4 kHz** ($\omega = 25132.7$ rad/s):
    $Z_{in} = 398.7 - j650.0\,\Omega$ $\Rightarrow$ **$|Z_{in}| = 762.5\,\Omega$ , $\angle Z_{in} = -58.5^\circ$**
*   **At f = 10 kHz** ($\omega = 62831.9$ rad/s):
    $Z_{in} = 88.5 - j347.5\,\Omega$ $\Rightarrow$ **$|Z_{in}| = 358.6\,\Omega$ , $\angle Z_{in} = -75.7^\circ$**

#### 2. Circuit in Fig. 1(b) - Series Combination
**Given Parameters:** $R = 510\,\Omega$, $C = 0.1\mu\text{F}$.
The driving point impedance is the simple series combination of $R$ and $C$:
$$Z_{in} = R + \frac{1}{j\omega C} = R - j\frac{1}{\omega C}$$

*   **At f = 200 Hz** ($\omega = 1256.6$ rad/s):
    $Z_{in} = 510 - j7957.7\,\Omega$ $\Rightarrow$ **$|Z_{in}| = 7974.0\,\Omega$ , $\angle Z_{in} = -86.3^\circ$**
*   **At f = 2 kHz** ($\omega = 12566.4$ rad/s):
    $Z_{in} = 510 - j795.8\,\Omega$ $\Rightarrow$ **$|Z_{in}| = 945.2\,\Omega$ , $\angle Z_{in} = -57.3^\circ$**
*   **At f = 5 kHz** ($\omega = 31415.9$ rad/s):
    $Z_{in} = 510 - j318.3\,\Omega$ $\Rightarrow$ **$|Z_{in}| = 601.2\,\Omega$ , $\angle Z_{in} = -32.0^\circ$**
*   **At f = 10 kHz** ($\omega = 62831.9$ rad/s):
    $Z_{in} = 510 - j159.2\,\Omega$ $\Rightarrow$ **$|Z_{in}| = 534.3\,\Omega$ , $\angle Z_{in} = -17.3^\circ$**

### Part B: Transfer Function (Voltage Gain)

**Given Parameters for Fig. 2 circuits:** $R = 5.1\text{ k}\Omega$, $C = 0.047\mu\text{F}$.
The time constant is $\tau = RC = (5100)(0.047 \times 10^{-6}) = 2.397 \times 10^{-4}\text{ s}$.
The theoretical **-3dB cutoff frequency** is:
$$f_c = \frac{1}{2\pi RC} = \frac{1}{2\pi(2.397 \times 10^{-4})} \approx \mathbf{664.1 \text{ Hz}}$$

#### 1. Circuit in Fig. 2(a) - First-Order RC Low-Pass Filter
The transfer function $H(j\omega)$ across the capacitor is $H(j\omega) = \frac{1}{1 + j\omega RC}$.
*   **Amplitude (dB):** $20 \log_{10}|H(j\omega)| = -10 \log_{10}(1 + (\omega RC)^2) \text{ dB}$
*   **Phase:** $\angle H(j\omega) = -\arctan(\omega RC)$
*(At theoretical $f_c = 664.1$ Hz, Amplitude is $-3\text{ dB}$, Phase is $-45^\circ$)*

#### 2. Circuit in Fig. 2(b) - First-Order RC High-Pass Filter
The transfer function $H(j\omega)$ across the resistor is $H(j\omega) = \frac{j\omega RC}{1 + j\omega RC}$.
*   **Amplitude (dB):** $20 \log_{10}(\omega RC) - 10 \log_{10}(1 + (\omega RC)^2) \text{ dB}$
*   **Phase:** $\angle H(j\omega) = 90^\circ - \arctan(\omega RC)$
*(At theoretical $f_c = 664.1$ Hz, Amplitude is $-3\text{ dB}$, Phase is $+45^\circ$)*

## 3. Simulation Practice (Multisim)

In this section, Multisim 14.0 was utilized to simulate the AC frequency response of the circuits. A **Bode Plotter** was employed to observe the magnitude and phase shifts.

### 3.1 Simulation Methodology
1.  **Transfer Function (Fig. 2):** An AC voltage source was applied. The Bode Plotter was connected with its 'IN' ports across the source and 'OUT' ports across the output component. The vertical axis for magnitude was set to logarithmic (dB) to easily identify the -3dB cutoff frequency.
2.  **Driving Point Impedance (Fig. 1):** To plot impedance using a Bode Plotter, a special technique was used where the AC voltage source was replaced with a **1A AC Current Source**. Because $Z = V / I$, setting $I = 1\text{A}$ makes the measured input voltage numerically equal to the driving point impedance ($Z = V$). The Bode Plotter’s vertical axis was set to 'Linear' to read the resistance directly in Ohms ($\Omega$).

### 3.2 Simulation Results vs. Theoretical Values

The simulations perfectly align with the theoretical calculations:

*   **Fig. 2(a) Low-Pass Filter:** Simulated $f_c$ at -3dB is **662.401 Hz** with a phase of **-45.001°** (Theory: 664.1 Hz, -45°).
*   **Fig. 2(b) High-Pass Filter:** Simulated $f_c$ at -3dB is **665.631 Hz** with a phase of **44.999°** (Theory: 664.1 Hz, +45°).
*   **Fig. 1(a) Impedance at 2 kHz:** Simulated magnitude is **1.086 k$\Omega$**, phase is **-42.637°** (Theory: 1086.0 $\Omega$, -42.6°).
*   **Fig. 1(b) Impedance at 2 kHz:** Simulated magnitude is **945.197 $\Omega$**, phase is **-57.345°** (Theory: 945.2 $\Omega$, -57.3°).

### 3.3 Simulation Plots and Screenshots

#### A. Transfer Function Simulations (Voltage Gain)

<center>
    <img src = "https://free.picui.cn/free/2026/04/26/69edb0b3d88f1.png"
        width = 50%>
</center>
<center>
    <em>Figure S1: Bode magnitude plot for the 1st order RC low-pass filter (Fig. 2a), identifying the -3dB cutoff frequency.</em>
</center>

<center>
    <img src = "https://free.picui.cn/free/2026/04/26/69edb0b3ed436.png"
        width = 50%>
</center>
<center>
    <em>Figure S2: Bode phase plot for the 1st order RC low-pass filter (Fig. 2a).</em>
</center>

<center>
    <img src = "https://free.picui.cn/free/2026/04/26/69edb0b42e537.png"
        width = 50%>
</center>
<center>
    <em>Figure S3: Bode magnitude plot for the 1st order RC high-pass filter (Fig. 2b), identifying the -3dB cutoff frequency.</em>
</center>

<center>
    <img src = "https://free.picui.cn/free/2026/04/26/69edb0b42c335.png"
        width = 50%>
</center>
<center>
    <em>Figure S4: Bode phase plot for the 1st order RC high-pass filter (Fig. 2b).</em>
</center>

#### B. Driving Point Impedance Simulations

<center>
    <img src = "https://free.picui.cn/free/2026/04/26/69edb0b42c335.png"
        width = 50%>
</center>
<center>
    <em>Figure S5: Simulated magnitude response of driving point impedance for Fig. 1(a) at 2kHz.</em>
</center>

<center>
    <img src = "https://free.picui.cn/free/2026/04/26/69edb0b42c335.png"
        width = 50%>
</center>
<center>
    <em>Figure S6: Simulated phase response of driving point impedance for Fig. 1(a) at 2kHz.</em>
</center>

<center>
    <img src = "https://free.picui.cn/free/2026/04/26/69edb1b72c21e.png"
        width = 50%>
</center>
<center>
    <em>Figure S7: Simulated magnitude response of driving point impedance for Fig. 1(b) at 2kHz.</em>
</center>

<center>
    <img src = "https://free.picui.cn/free/2026/04/26/69edb1b72ca15.png"
        width = 50%>
</center>
<center>
    <em>Figure S8: Simulated phase response of driving point impedance for Fig. 1(b) at 2kHz.</em>
</center>

## 4. Answers to Pre-Lab Questions

**Q1) While measuring the driving point impedance in Fig.1(b), is a small resistor needed to measure the current? Why?**
**Answer:** No, an additional small sensing resistor is not needed. In the series circuit of Fig. 1(b), the resistor $R$ ($510\Omega$) is already in series with the capacitor, and its bottom terminal is connected to the common ground. Since the current is the same throughout a series circuit, the total current can be determined directly by measuring the voltage drop across this existing resistor $R$ using the oscilloscope ($I = V_R / R$). Introducing an extra small resistor would be redundant and would unnecessarily increase the total impedance, causing measurement error.

**Q2) In the measurement, how to determine the -3dB frequency?**
**Answer:** The -3dB frequency (cutoff frequency) is the frequency at which the output voltage amplitude drops to $1/\sqrt{2}$ (approximately **$0.707$**) of its maximum passband value. 
To determine this experimentally:
1. Ensure the input voltage $V_s$ from the Function Generator is strictly maintained at a constant amplitude (e.g., $1\text{V}$).
2. Find the maximum output voltage in the passband (for low-pass, at a very low frequency).
3. Gradually sweep the frequency on the Function Generator while monitoring the output voltage on the oscilloscope.
4. Stop adjusting when the output voltage drops to exactly $0.707 \times V_{max}$. The frequency displayed on the generator at this moment is the practical -3dB cutoff frequency.

**Q3) While measuring the driving point impedances, use the Digital Multi-meter to replace the Digital Oscilloscope in Fig.1(a) and (b). Are there any differences in the use of two instruments?**
**Answer:** Yes, there are two significant differences:
1. **Phase Measurement Capability:** A Digital Oscilloscope can display both the voltage and current waveforms simultaneously, allowing us to measure the time delay ($\Delta t$) or use the Lissajous figure (ellipse method) to calculate the phase difference ($\theta$). A standard Digital Multi-meter (DMM) only measures scalar magnitudes (RMS voltage/current) and cannot measure phase.
2. **Frequency Bandwidth Limitation:** Most standard DMMs are calibrated to provide accurate True RMS readings only at lower frequencies (typically 50 Hz to 400 Hz). At higher frequencies (e.g., the 5 kHz and 10 kHz required in this lab), the DMM's internal circuitry attenuates the signal, leading to highly inaccurate readings. An oscilloscope, however, has a high bandwidth (usually $\ge 50$ MHz) and maintains high accuracy across the entire frequency range used in this experiment.