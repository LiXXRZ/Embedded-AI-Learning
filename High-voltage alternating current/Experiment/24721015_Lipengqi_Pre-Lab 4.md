# **Pre-lab Report**

**Course Name:** [High-Voltage Alternating Current]
**Laboratory Exercise No:** 4
**Experiment Title:** Measurement for Active RC Filter
**Name:** Li Pengqi
**Student ID:** 24721015

## **1. Introduction**

Active filters, utilizing combinations of resistors, capacitors, and operational amplifiers, offer significant advantages over passive RLC filters, such as eliminating the need for bulky inductors and providing voltage gain. The primary objective of this pre-lab is to theoretically analyze and computationally simulate the frequency response (magnitude and phase) of 2nd-order Sallen-Key active low-pass, high-pass, and cascaded band-pass filters. Phasor analysis is employed to deduce the transfer functions, and NI Multisim 14.0 is utilized to simulate the circuits and construct Bode plots.

## **2. Theoretical Analysis & Equation Deductions**

### **2.1 Active RC Low-pass Filter (Fig. 1a)**

The circuit is a 2nd-order Sallen-Key low-pass filter with unity-gain voltage-follower configuration ($V_o = V_2$).

#### **2.1.1 Circuit Topology & Node Analysis**

- Input voltage source: $V_s$
- Series resistors: $R_1 = 10\ \text{k}\Omega$ (two identical, from $V_s\to V_1$ and $V_1\to V_2$)
- Feedback capacitor: $2C_1 = 2\ \text{nF}$ (from node $V_1$ to output $V_o$)
- Ground capacitor: $C_1 = 1\ \text{nF}$ (from node $V_2$ to ground)

Applying KCL at node $V_2$:
$$\frac{V_1 - V_2}{R_1} = V_2 \cdot (C_1 s) \quad\Longrightarrow\quad V_1 = V_2(1 + R_1 C_1 s) \tag{1}$$

Applying KCL at node $V_1$:
$$\frac{V_1 - V_s}{R_1} + \frac{V_1 - V_2}{R_1} + (V_1 - V_o)(2C_1 s) = 0 \tag{2}$$

Substituting $V_o = V_2$ and equation (1) into (2):
$$V_2(1 + R_1 C_1 s)/R_1 - V_s/R_1 + V_2 C_1 s + 2R_1 C_1^2 s^2 V_2 = 0$$

Multiplying by $R_1$ and collecting terms:
$$V_2(1 + 2R_1 C_1 s + 2R_1^2 C_1^2 s^2) = V_s$$

#### **2.1.2 Transfer Function**

$$\boxed{H_{LP}(s) = \frac{V_o}{V_s} = \frac{1}{1 + 2R_1 C_1 s + 2R_1^2 C_1^2 s^2}} \tag{3}$$

#### **2.1.3 Standard Form & Key Parameters**

Writing in the standard second-order form $H(s) = \dfrac{1}{1 + s/(Q\omega_0) + s^2/\omega_0^2}$:

$$\frac{1}{\omega_0^2} = 2R_1^2 C_1^2 \quad\Longrightarrow\quad \omega_0 = \frac{1}{R_1 C_1 \sqrt{2}}$$

$$\frac{2\zeta}{\omega_0} = 2R_1 C_1 \quad\Longrightarrow\quad \zeta = R_1 C_1 \omega_0 = \frac{1}{\sqrt{2}} \approx 0.7071$$

$$Q = \frac{1}{2\zeta} = \frac{1}{\sqrt{2}} \approx 0.7071$$

With $\zeta = 1/\sqrt{2}$, the filter exhibits a **Butterworth (maximally flat)** response. The magnitude squared simplifies to:

$$|H_{LP}(j\omega)|^2 = \frac{1}{1 + 4\omega^4 R_1^4 C_1^4}$$

#### **2.1.4 Cutoff Frequency Calculation**

With $R_1 = 10\ \text{k}\Omega$ and $C_1 = 1\ \text{nF}$:

$$R_1 C_1 = 10^4 \times 10^{-9} = 10^{-5}\ \text{s}$$

$$f_{c,LP} = \frac{\omega_0}{2\pi} = \frac{1}{2\pi R_1 C_1 \sqrt{2}} = \frac{1}{2\pi \times 10^{-5} \times \sqrt{2}} \approx \mathbf{11.25\ \text{kHz}}$$

For a Butterworth second-order filter, the $-3\ \text{dB}$ cutoff frequency equals $f_0$, and the phase at cutoff is:

$$H_{LP}(j\omega_0) = \frac{1}{1 + j\sqrt{2}} = \frac{1}{\sqrt{2}} \angle -90^\circ$$

$$\boxed{\phi_{LP}(f_c) = -90^\circ}$$

### **2.2 Active RC High-pass Filter (Fig. 1b)**

The circuit is the dual of the low-pass filter, with resistors and capacitors interchanged.

#### **2.2.1 Circuit Topology & Node Analysis**

- Input voltage source: $V_s$
- Series capacitors: $C_2 = 10\ \text{nF}$ (two identical, from $V_s\to V_1$ and $V_1\to V_2$)
- Feedback resistor: $R_2 = 10\ \text{k}\Omega$ (from node $V_1$ to output $V_o$)
- Ground resistor: $2R_2 = 20\ \text{k}\Omega$ (from node $V_2$ to ground)

Applying KCL at node $V_2$:
$$(V_1 - V_2)C_2 s = \frac{V_2}{2R_2} \quad\Longrightarrow\quad V_1 = V_2\left(1 + \frac{1}{2R_2 C_2 s}\right) \tag{4}$$

Applying KCL at node $V_1$:
$$(V_1 - V_s)C_2 s + (V_1 - V_2)C_2 s + \frac{V_1 - V_o}{R_2} = 0 \tag{5}$$

Substituting $V_o = V_2$ and equation (4) into (5):
$$V_2\left(C_2 s + \frac{1}{R_2} + \frac{1}{2R_2^2 C_2 s}\right) = V_s C_2 s$$

#### **2.2.2 Transfer Function**

$$H_{HP}(s) = \frac{V_o}{V_s} = \frac{C_2 s}{C_2 s + \dfrac{1}{R_2} + \dfrac{1}{2R_2^2 C_2 s}}$$

Multiplying numerator and denominator by $s$:

$$\boxed{H_{HP}(s) = \frac{s^2}{s^2 + \dfrac{s}{R_2 C_2} + \dfrac{1}{2R_2^2 C_2^2}}} \tag{6}$$

Equivalently, in rational polynomial form:

$$\boxed{H_{HP}(s) = \frac{2R_2^2 C_2^2 s^2}{1 + 2R_2 C_2 s + 2R_2^2 C_2^2 s^2}}$$

#### **2.2.3 Standard Form & Key Parameters**

Writing in standard high-pass form $H(s) = \dfrac{s^2}{s^2 + 2\zeta\omega_0 s + \omega_0^2}$:

$$\omega_0^2 = \frac{1}{2R_2^2 C_2^2} \quad\Longrightarrow\quad \omega_0 = \frac{1}{R_2 C_2 \sqrt{2}}$$

$$2\zeta\omega_0 = \frac{1}{R_2 C_2} \quad\Longrightarrow\quad \zeta = \frac{1}{2R_2 C_2 \omega_0} = \frac{1}{\sqrt{2}} \approx 0.7071$$

$$Q = \frac{1}{2\zeta} = \frac{1}{\sqrt{2}} \approx 0.7071$$

The damping ratio is identical to the low-pass case — both are **Butterworth** filters.

#### **2.2.4 Cutoff Frequency Calculation**

With $R_2 = 10\ \text{k}\Omega$ and $C_2 = 10\ \text{nF}$:

$$R_2 C_2 = 10^4 \times 10^{-8} = 10^{-4}\ \text{s}$$

$$f_{c,HP} = \frac{\omega_0}{2\pi} = \frac{1}{2\pi R_2 C_2 \sqrt{2}} = \frac{1}{2\pi \times 10^{-4} \times \sqrt{2}} \approx \mathbf{1.125\ \text{kHz}}$$

The phase at cutoff is:

$$H_{HP}(j\omega_0) = \frac{1}{1 - j\sqrt{2}} = \frac{1}{\sqrt{2}} \angle +90^\circ$$

$$\boxed{\phi_{HP}(f_c) = +90^\circ}$$

### **2.3 Active RC Band-pass Filter**

By cascading the low-pass and high-pass filters, the overall transfer function is the product of the individual stages due to the isolation provided by the op-amp buffers:

$$H_{BP}(j\omega) = H_{LP}(j\omega) \times H_{HP}(j\omega)$$

The magnitude response in dB is calculated as $20\log_{10}|H_{BP}(j\omega)|$, and the total phase shift is the sum:

$$\angle H_{BP} = \angle H_{LP} + \angle H_{HP}$$

Since the two cutoff frequencies are separated by a decade ($f_{c,LP} = 10 \times f_{c,HP}$), the cascaded band-pass filter will have a passband spanning approximately $1.125\ \text{kHz}$ to $11.25\ \text{kHz}$.

### **2.4 Summary of Filter Parameters**

| Parameter | Low-Pass Filter (a) | High-Pass Filter (b) |
|---|---|---|
| Topology | Sallen-Key Unity-Gain | Sallen-Key Unity-Gain |
| Series elements | $R_1 = 10\ \text{k}\Omega$ (×2) | $C_2 = 10\ \text{nF}$ (×2) |
| Feedback element | $2C_1 = 2\ \text{nF}$ | $R_2 = 10\ \text{k}\Omega$ |
| Ground element | $C_1 = 1\ \text{nF}$ | $2R_2 = 20\ \text{k}\Omega$ |
| Cutoff freq. $f_c$ | $11.25\ \text{kHz}$ | $1.125\ \text{kHz}$ |
| Damping ratio $\zeta$ | $1/\sqrt{2} \approx 0.707$ | $1/\sqrt{2} \approx 0.707$ |
| Quality factor $Q$ | $1/\sqrt{2} \approx 0.707$ | $1/\sqrt{2} \approx 0.707$ |
| Response type | Butterworth (max. flat) | Butterworth (max. flat) |
| Roll-off rate | $-40\ \text{dB/decade}$ | $+40\ \text{dB/decade}$ |
| Phase at $f_c$ | $-90^\circ$ | $+90^\circ$ |

## **3. Simulation Practice**

The circuits were constructed in Multisim 14.0 using `OPAMP_3T_VIRTUAL`. A Bode Plotter was connected to measure the amplitude and phase across different frequencies. The time delay ($\Delta t$) was measured directly from the oscilloscope using cursor readouts, and the phase was subsequently calculated via the standard relationship:

$$\varphi = 360^\circ \times f \times \Delta t \qquad \Longleftrightarrow \qquad \Delta t = \frac{\varphi}{360^\circ \times f}$$

*Note: In the data tables below, $\Delta t$ values are the **directly measured** oscilloscope readings, and $\varphi$ values are **computed** from the measured $\Delta t$ using the formula above.*

### **3.1 Low-pass Filter Simulation Data**

<center>
    <img src = "https://free.picui.cn/free/2026/05/09/69ff1ab461ef3.png"
        width = 50%>
</center>
<center>
    <em>Figure 1: Multisim Schematic for Low-pass Filter</em>
</center>

<table style="border-collapse: collapse; margin: 0 auto; width: 100%;">
    <tr>
        <td style="text-align: center; padding: 10px; width: 33.33%;">
            <img src="https://free.picui.cn/free/2026/05/09/69ff1d4ed6f7c.png" alt="[Insert Multisim Schematic Here]" width="100%">
            <br>
            <em>Figure 2.1: Bode Plot (Magnitude)</em>
        </td>
        <td style="text-align: center; padding: 10px; width: 33.33%;">
            <img src="https://free.picui.cn/free/2026/05/09/69ff1d4ed6c04.png" alt="[Insert Bode Plot Magnitude Here]" width="100%">
            <br>
            <em>Figure 2.2: Bode Plot (Phase)</em>
        </td>
        <td style="text-align: center; padding: 10px; width: 33.33%;">
            <img src="https://free.picui.cn/free/2026/05/09/69ff1d4f36aa0.png" alt="[Insert Bode Plot Phase Here]" width="100%">
            <br>
            <em>Figure 2.3: Bode Plot (Delay)</em>
        </td>
    </tr>
</table>

**Table 1. Data for low-pass filter**

| Source frequency/kHz | 0.1 | 1 | 10 | 50 | 100 | 150 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **$\vert \dot{V}_o / \dot{V}_s \vert$ / dB** | 0 | 0 | -2.104 | -25.919 | -37.950 | -44.993 |
| **$\Delta t$ / $\mu$s (measured)** | -19.94 | -20.14 | -22.48 | -9.05 | -4.80 | -3.18 |
| **$\varphi$ / Deg (measured)** | -0.720 | -7.219 | -80.505 | -161.495 | -170.906 | -174.011 |

### **3.2 High-pass Filter Simulation Data**

<center>
    <img src = "https://free.picui.cn/free/2026/05/09/69ff1ab449563.png"
        width = 50%>
</center>
<center>
    <em>Figure 3: Multisim Schematic for High-pass Filter</em>
</center>

<table style="border-collapse: collapse; margin: 0 auto; width: 100%;">
    <tr>
        <td style="text-align: center; padding: 10px; width: 33.33%;">
            <img src="https://free.picui.cn/free/2026/05/09/69ff1d94de456.png" alt="[Insert Multisim Schematic Here]" width="100%">
            <br>
            <em>Figure 4.1: Bode Plot (Magnitude)</em>
        </td>
        <td style="text-align: center; padding: 10px; width: 33.33%;">
            <img src="https://free.picui.cn/free/2026/05/09/69ff1d94de7e9.png" alt="[Insert Bode Plot Magnitude Here]" width="100%">
            <br>
            <em>Figure 4.2: Bode Plot (Phase)</em>
        </td>
        <td style="text-align: center; padding: 10px; width: 33.33%;">
            <img src="https://free.picui.cn/free/2026/05/09/69ff1d94e9cc4.png" alt="[Insert Bode Plot Phase Here]" width="100%">
            <br>
            <em>Figure 4.3: Bode Plot (Delay)</em>
        </td>
    </tr>
</table>

**Table 2. Data for high-pass filter**

| Source frequency/kHz | 0.1 | 0.5 | 1 | 10 | 100 | 150 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **$\vert \dot{V}_o / \dot{V}_s \vert$ / dB** | -42.053 | -14.260 | -4.157 | -0.001 | 0 | 0 |
| **$\Delta t$ / $\mu$s (measured)** | 4806.34 | 791.05 | 277.56 | 2.58 | 0.025 | 0.011 |
| **$\varphi$ / Deg (measured)** | 172.781 | 141.943 | 99.505 | 9.151 | 0.855 | 0.522 |

### **3.3 Band-pass Filter Simulation Data**

<center>
    <img src = "https://free.picui.cn/free/2026/05/09/69ff1df8904fc.png"
        width = 50%>
</center>
<center>
    <em>Figure 5: Multisim Schematic for Cascaded Band-pass Filter</em>
</center>

<table style="border-collapse: collapse; margin: 0 auto; width: 100%;">
    <tr>
        <td style="text-align: center; padding: 10px; width: 33.33%;">
            <img src="https://free.picui.cn/free/2026/05/09/69ff1e2833488.png" alt="[Insert Multisim Schematic Here]" width="100%">
            <br>
            <em>Figure 6.1: Bode Plot (Magnitude)</em>
        </td>
        <td style="text-align: center; padding: 10px; width: 33.33%;">
            <img src="https://free.picui.cn/free/2026/05/09/69ff1e2838de5.png" alt="[Insert Bode Plot Magnitude Here]" width="100%">
            <br>
            <em>Figure 6.2: Bode Plot (Phase)</em>
        </td>
        <td style="text-align: center; padding: 10px; width: 33.33%;">
            <img src="https://free.picui.cn/free/2026/05/09/69ff1e28bbe2c.png" alt="[Insert Bode Plot Phase Here]" width="100%">
            <br>
            <em>Figure 6.3: Bode Plot (Delay)</em>
        </td>
    </tr>
</table>

**Table 3. Data for band-pass filter**

| Source frequency/kHz | 0.1 | 0.5 | 1 | 4 | 7 | 10 | 50 | 100 | 150 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **$\vert \dot{V}_o / \dot{V}_s \vert$ / dB** | -42.053 | -14.260 | -4.157 | -0.096 | -0.609 | -2.105 | -25.919 | -37.950 | -44.993 |
| **$\Delta t$ / $\mu$s (measured)** | 4787.82 | 770.21 | 257.44 | -4.61 | -16.75 | -19.93 | -8.93 | -4.77 | -3.17 |
| **$\varphi$ / Deg (measured)** | 172.061 | 138.340 | 92.286 | -6.551 | -42.000 | -71.354 | -159.700 | -170.052 | -173.489 |

### **3.4 Cutoff Frequencies Data**

The $-3\ \text{dB}$ frequencies were located using the Bode Plotter cursor function. The simulated values closely align with the theoretical calculations ($1.125\ \text{kHz}$ and $11.25\ \text{kHz}$ derived in Section 2).

<table style="border-collapse: collapse; margin: 0 auto;">
    <tr>
        <td style="text-align: center; padding: 10px;">
            <img src="https://free.picui.cn/free/2026/05/09/69ff1ec862dbb.png" alt="[Insert Multisim Schematic for LP Here]" width="100%">
            <br>
            <em>Figure 7.1: Bode Plot for frequency</em>
        </td>
        <td style="text-align: center; padding: 10px;">
            <img src="https://free.picui.cn/free/2026/05/09/69ff1ec880d1c.png" alt="[Insert Bode Plot for LP Here]" width="100%">
            <br>
            <em>Figure 7.2: Bode Plot for degree</em>
        </td>
    </tr>
</table>

**Table 4. Data for $-3\ \text{dB}$ frequencies**

| $f_{LP-3dB}$ | $\varphi_{LP-3dB}$ | $f_{HP-3dB}$ | $\varphi_{HP-3dB}$ | $f_{L-3dB}$ | $\varphi_{L-3dB}$ | $f_{H-3dB}$ | $\varphi_{H-3dB}$ |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **11.24 kHz** | **-89.912$^{\circ}$** | **1.127 kHz** | **89.883$^{\circ}$** | **1.127 kHz** | **81.741$^{\circ}$** | **11.239 kHz** | **-81.771$^{\circ}$** |

The measured $-3\ \text{dB}$ frequencies ($11.24\ \text{kHz}$ for LPF, $1.127\ \text{kHz}$ for HPF) deviate from the theoretical values by less than $0.2\%$, confirming that both filters exhibit the designed Butterworth response with $\zeta = 1/\sqrt{2}$ and a roll-off rate of $\pm 40\ \text{dB/decade}$. The BPF passband spans from approximately $1.127\ \text{kHz}$ to $11.239\ \text{kHz}$, consistent with the cascaded response.

## **4. Conclusion**

This pre-lab report systematically analyzed the frequency response of 2nd-order Sallen-Key active RC filters. The key conclusions are:

1. **Theoretical Analysis:** The transfer functions for the low-pass filter ($H_{LP}(s) = 1/(1 + 2R_1C_1s + 2R_1^2C_1^2s^2)$) and high-pass filter ($H_{HP}(s) = 2R_2^2C_2^2s^2/(1 + 2R_2C_2s + 2R_2^2C_2^2s^2)$) were derived via nodal analysis. Both filters exhibit a Butterworth response with damping ratio $\zeta = 1/\sqrt{2}$ and quality factor $Q = 1/\sqrt{2}$.

2. **Cutoff Frequencies:** The theoretical $-3\ \text{dB}$ cutoff frequencies were calculated as $f_{c,LP} = 11.25\ \text{kHz}$ and $f_{c,HP} = 1.125\ \text{kHz}$. The simulated values ($11.24\ \text{kHz}$ and $1.127\ \text{kHz}$) agree within $0.2\%$, validating the design.

3. **Phase Characteristics:** At the cutoff frequency, the LPF introduces a phase lag of $-90^\circ$, while the HPF introduces a phase lead of $+90^\circ$. For the cascaded BPF, the total phase shift transitions from $+90^\circ$ (below passband) to $-90^\circ$ (above passband), passing through $0^\circ$ at the center of the passband.

4. **Comparison of $\Delta t$ and $\varphi$:** The time delay ($\Delta t$) was measured directly from the oscilloscope, while the phase ($\varphi$) was read from the Bode plotter. Small discrepancies exist between the measured $\Delta t$ values and the values calculated from $\varphi = 360^\circ \times f \times \Delta t$, which are attributed to:
   - Cursor reading precision limitations on the oscilloscope
   - Different measurement principles between the oscilloscope and Bode plotter
   - Slight triggering and synchronization errors at extreme frequencies

Despite these minor measurement variations, all results are consistent with the theoretical Butterworth filter characteristics, confirming the correct operation of the designed circuits.

**END OF PRE-LAB REPORT**