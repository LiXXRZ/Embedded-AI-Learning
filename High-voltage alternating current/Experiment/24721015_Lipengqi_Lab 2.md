
<div style="page-break-before: always; display: block;"></div>

<div align="center" style="width: 100%; height: 280mm; display: flex; align-items: center; justify-content: center; overflow: hidden; page-break-inside: avoid;">
  <img src="https://free.boltp.com/2026/04/15/69df8fa59c8fb.webp" style="max-width: 100%; max-height: 100%; object-fit: contain;" alt="Image 2">
</div>

<div style="page-break-after: always; display: block;"></div>

#### **I. Introduction**
The main objectives of this laboratory exercise include:
* Consolidating the principle of the unidirectional conductivity of diodes and mastering their role in rectifier circuits.
* Understanding and mastering the composition, working principles, and waveform characteristics of three typical rectifier circuits: half-wave rectification, full-wave rectification (center-tapped), and bridge rectification.
* Exploring the influence of filter capacitors on the output waveform of rectifier circuits and understanding the basic design concept of "rectification + filtering" in power supply circuits.

---

#### **II. Principles**
The core of a rectifier circuit is to utilize the "unidirectional conductivity" of diodes to convert alternating current (AC), which alternates between positive and negative, into a unidirectional pulsating direct current (DC) voltage. In this experiment, low-voltage AC power is obtained from the 220V 50Hz AC mains supply via a step-down transformer to serve as the input. 

* **Half-Wave Rectifier Circuit**: Consists of one diode and a load resistor. During the positive half-cycle, the diode is forward-biased and conducts; during the negative half-cycle, it is reverse-biased and cuts off. The output waveform retains only one half-cycle, resulting in large pulsation and low efficiency (approx. 40.6%).
* **Full-Wave Rectifier Circuit (Center-Tapped)**: Consists of two diodes, a center-tapped transformer, and a load resistor. The output retains both the positive and negative half-cycles of the AC signal, with a pulsation frequency twice that of half-wave rectification and higher efficiency (approx. 81.2%).
* **Bridge Rectifier Circuit**: Consists of four diodes (or an integrated rectifier bridge) and a load resistor. Diagonal diodes conduct alternately during the positive and negative half-cycles. It achieves the same output waveform as full-wave rectification but does not require a special transformer, making it the most commonly used method in practical circuits.
* **Role of Filter Capacitor**: The output after rectification is "unidirectional pulsating DC" with significant ripple. When an electrolytic capacitor is connected in parallel across the load, it charges at the voltage peak and discharges at the valley. This supplements the load current, smoothing the output waveform and bringing the effective DC output voltage closer to the peak value of the input AC signal.

---

#### **III. Experimental Procedure**
**3.1 Verification of Diode Unidirectional Conductivity**
* **Step 1:** Turn on the digital multimeter and set the dial to the "Diode Test" mode ($\rightarrow\vdash$).
* **Step 2 (Forward Bias Test):** Connect the red test probe to the anode (the longer lead, or the side without the silver band) of the 1N4007 diode, and the black test probe to the cathode (the shorter lead, or the side with the silver band). Record the forward voltage drop ($V_F$) displayed on the screen. A normal silicon diode reading is between **0.6V and 0.7V**.
* **Step 3 (Reverse Bias Test):** Reverse the connections (red probe to cathode, black probe to anode). The multimeter displays "OL" (Overload/Open Loop) or infinity, indicating that no current is flowing, verifying the diode's reverse-blocking capability.

**3.2 Setup and Measurement of the AC Power Source**
* **Step 1:** Connect the step-down transformer to the 220V/50Hz AC mains supply.
* **Step 2:** Set the multimeter to the **AC Voltage (ACV)** range. Measure the secondary coil output terminals of the transformer. Record the effective RMS voltage ($V_{rms}$) and calculate the theoretical peak voltage using the formula $V_p = V_{rms} \times \sqrt{2}$.
* **Step 3:** Connect the CH1 probe of the oscilloscope to the transformer's output terminals. Set CH1 to **AC Coupling**. Adjust the horizontal time base and vertical scale to observe a clear, continuous sinusoidal waveform. Verify that the period is approximately 20ms (corresponding to a 50Hz frequency).

<table style="width: 100%; border-collapse: collapse; border: none;">
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/15/69df80d452bba.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/15/69df80d35277c.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
  </tr>
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 1:</b> Circuit Construction
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 2:</b> Power Signal Image
    </td>
  </tr>
</table>

**3.3 Construction and Testing of the Half-Wave Rectifier Circuit**
* **Step 1 (Circuit Assembly):** Connect one end of the transformer's secondary coil to the anode of a 1N4007 diode. Connect the cathode of the diode to one end of the load resistor ($R_L$). Connect the other end of $R_L$ back to the transformer's common ground terminal to form a complete closed loop.
* **Step 2 (Unfiltered Waveform Observation):** Keep the CH1 probe connected to the AC input. Connect the CH2 probe across the load resistor ($R_L$). Set CH2 to **DC Coupling**. Observe the waveform on CH2: the waveform consists only of positive half-sine pulses, with the voltage remaining at 0V during the negative half-cycles.
* **Step 3 (Unfiltered Voltage Measurement):** Set the multimeter to the **DC Voltage (DCV)** range. Measure the voltage across $R_L$ and record the average DC output. Compare the measured result with the theoretical expectation ($V_0 \approx 0.45 \times V_s - V_F$).
* **Step 4 (Adding the Filter Capacitor):** Connect a 100μF electrolytic capacitor in parallel with $R_L$. Follow the polarity connection rules for electrolytic capacitors: connect the positive lead of the capacitor to the diode's cathode, and the negative lead to the system ground.
* **Step 5 (Filtered Measurement):** Observe the CH2 waveform on the oscilloscope; due to the capacitor's charge and discharge process, the pulse waveform presents a "sawtooth" shape. Use the multimeter to measure the new DC voltage across $R_L$, observing and recording the boosted voltage value.
* **Step 6:** Repeat Step 4 and Step 5 by replacing the load resistor ($1\text{k}\Omega$ and $10\text{k}\Omega$) and the filter capacitor (100μF and 1000μF) respectively. Record the voltage readings and waveform changes (record the ripple amplitude) for all combinations.
<table style="width: 100%; border-collapse: collapse; border: none;">
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/15/69df873fcf032.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/15/69df873fe99c7.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
  </tr>
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 3:</b> Input signal
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 4:</b> Output without the involvement of capacitors
    </td>
  </tr>
</table>

<table style="width: 100%; border-collapse: collapse; border: none;">
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/15/69df874001d95.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/15/69df873fe7e7e.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
  </tr>
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 5:</b> Output signal when C = 100 μF and R = 1 kΩ
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 6:</b> Output signal when C = 100 μF and R = 10 kΩ
    </td>
  </tr>
</table>

<table style="width: 100%; border-collapse: collapse; border: none;">
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/15/69df88adbe174.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/15/69df88adb616f.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
  </tr>
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 7:</b> Output signal when C = 1000 μF and R = 1 kΩ
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 8:</b> Output signal when C = 1000 μF and R = 10 kΩ
    </td>
  </tr>
</table>

**3.4 Construction and Testing of the Bridge Rectifier Circuit**
* **Step 1 (Bridge Assembly):** Construct a bridge rectifier using four 1N4007 diodes. Connect the cathodes of two diodes together to form the positive output terminal. Connect the anodes of the other two diodes together to form the negative (ground) return terminal. Connect the remaining anode-cathode junctions to the two output terminals of the AC transformer.
* **Step 2 (Unfiltered Testing):** Connect the load resistor ($R_L$) across the positive output and ground terminals of the bridge circuit. Use the CH2 probe (DC Coupling) to observe the output waveform. Observe continuous, adjacent half-sine pulses with no zero-voltage gaps (the ripple frequency increases to 100Hz). Use the multimeter (DCV range) to measure and record the average output voltage.
* **Step 3 (Filtered Testing - Light vs. Heavy Load):** Connect the 100μF electrolytic capacitor in parallel with $R_L$ (maintain correct polarity connection). Observe the smoothed waveform on the oscilloscope, confirming that its ripple frequency is twice that of the half-wave circuit.
* **Step 4 (Data Collection):** Systematically use the multimeter to measure and record the DC output voltages for the following four combinations: $R_L = 1\text{k}\Omega$ / $10\text{k}\Omega$ paired with $C = 100\mu\text{F}$ / $1000\mu\text{F}$ respectively. Observe and record the voltage drop phenomenon that occurs when switching the load from light ($10\text{k}\Omega$) to heavy ($1\text{k}\Omega$) while the 1000μF large capacitor is connected.
<div align="center">
  <img src="https://free.boltp.com/2026/04/15/69df892a12b2a.webp" alt="4，1" style="width: 60%;" />
  <p>Figure 9: Input signal of the bridge circuit</p>
</div>

<table style="width: 100%; border-collapse: collapse; border: none;">
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/15/69df8b70234bb.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/15/69df892aa7607.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
  </tr>
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 10:</b> Output signal without C and R = 1 kΩ
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 11:</b> Output signal without C and R = 10 kΩ
    </td>
  </tr>
</table>

<table style="width: 100%; border-collapse: collapse; border: none;">
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/15/69df892a2fe00.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/15/69df892a34d37.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
  </tr>
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 12:</b> Output signal with C = 100 μF and R = 1 kΩ
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 13:</b> Output signal with C = 100 μF and R = 10 kΩ
    </td>
  </tr>
</table>

<table style="width: 100%; border-collapse: collapse; border: none;">
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/15/69df8aaf51365.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: bottom; padding-bottom: 8px;">
      <img src="https://free.boltp.com/2026/04/15/69df8aaf50c42.webp" height="250" style="max-width: 100%; object-fit: contain;" />
    </td>
  </tr>
  <tr style="border: none;">
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 14:</b> Output signal with C = 1000 μF and R = 1 kΩ
    </td>
    <td style="width: 50%; text-align: center; border: none; vertical-align: top;">
      <b>Figure 15:</b> Output signal with C = 1000 μF and R = 10 kΩ
    </td>
  </tr>
</table>


#### **IV. Data & Measurements**

**Table 1: Simulation Measurement**

| Circuit Type | Filter Capacitor | Input AC Voltage (V AC, rms) | Output Average Voltage (V DC) RL=1k / 10k | Output Waveform Characteristics | Ripple Condition |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Half-wave | None | 13.7 | 18.1 / 5.91 | Pulsating DC consisting only of positive half-sine pulses, with zero voltage during the negative half-cycles. | Large |
| Half-wave | 100μF | 13.7 | 18.153 / 18.332 | Sawtooth waveform. The capacitor exhibits a distinct charge and discharge process. | Medium |
| Half-wave | 1000μF | 13.7 | 18.281 / 18.591 | A nearly flat line with minor charge-discharge ripples. | Small |
| Bridge | None | 13.7 | 17.17 / 17.78 | Continuous half-sine pulses; pulsating DC with no zero-voltage gaps. | Large |
| Bridge | 100μF | 13.7 | 17.28 / 17.97 | Sawtooth waveform, but the ripple frequency is twice that of the half-wave rectifier. | Relatively small |
| Bridge | 1000μF | 13.7 | 17.78 / 17.91 | A very smooth straight line with almost no visible fluctuations. | Smallest |

**Table 2: Practical Measurement**

| Circuit Type | Filter Capacitor | Input AC Voltage (V AC, rms) | Output Voltage (V DC) RL=1k / 10k | Output Waveform Characteristics | Ripple Condition |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Half-wave | None | 13.64 | 5.653 / 5.799 | Pulsating DC consisting only of positive half-sine pulses, with zero voltage during the negative half-cycles. | Large |
| Half-wave | 100μF | 13.64 | 15.535 / 17.933 | Sawtooth waveform. The capacitor exhibits a distinct charge and discharge process. (1kΩ) | Medium |
| Half-wave | 1000μF | 13.64 | 15.593 / 17.855 | A nearly flat line with minor charge-discharge ripples. | Small |
| Bridge | None | 13.7 | 11.280 / 11.011 | Continuous half-sine pulses; pulsating DC with no zero-voltage gaps. | Large |
| Bridge | 100μF | 13.7 | 15.788 / 17.401 | Sawtooth waveform, but the ripple frequency is twice that of the half-wave rectifier. (1kΩ) | Small |
| Bridge | 1000μF | 13.7 | 15.803 / 17.421 | A very smooth straight line with almost no visible fluctuations. | Smallest |

---

#### **V. Discussion and Reflection**

**1. Thinking Questions**
* **Q1: In a half-wave rectifier circuit, if the positive and negative poles of the diode are reversed, what will happen to the output waveform? If the diode is damaged (short-circuited or open-circuited), what phenomenon will occur?**
  * *Reversed polarity*: The diode will conduct during the negative half-cycle instead of the positive. The output will become a negative unidirectional pulsating DC.
  * *Short-circuited*: The diode loses its unidirectional property and acts as a wire. Pure AC voltage will be applied directly to the load.
  * *Open-circuited*: The circuit path is broken, resulting in 0V output across the load.
* **Q2: Is it true that the larger the capacity of the filter capacitor, the better the filtering effect? Why can't the capacitor be infinitely large in practical circuits?**
  * Theoretically, a larger capacitor provides a longer discharge time constant, which reduces ripple. However, in practice, an infinitely large capacitor will draw a massive *surge current* upon startup or at the voltage peaks. This huge charging current can permanently damage the rectifier diodes or the transformer. Additionally, constraints regarding physical volume and cost make overly large capacitors impractical.
* **Q3: If the input AC voltage is 220V AC (mains supply), what parameters should be considered when selecting a rectifier diode?**
  * The most critical parameters are the **Reverse Withstand Voltage** and the **Maximum Forward Current**. The peak voltage of a 220V AC supply is approximately $220 \times \sqrt{2} \approx 311\text{V}$. Therefore, the diode must have a reverse breakdown voltage well above this threshold (typically 400V or 1000V components like the 1N4007 are chosen) to ensure a safe operating margin.

**2. Error Analysis: Simulation vs. Practical Hardware**
When comparing the simulation (Table 1) and practical data (Table 2), a significant discrepancy was observed. The practical measurement of the bridge rectifier with a 1000μF capacitor dropped notably from 17.421V (light load, 10kΩ) to 15.803V (heavy load, 1kΩ). The simulation did not reflect this severe voltage drop. 
This occurs because the simulation utilizes an ideal AC power source with zero internal resistance. In reality, the physical step-down transformer has copper loss (internal resistance) and leakage inductance. When a large 1000μF capacitor charges under a heavier 1kΩ load, it draws a massive instantaneous current. This current creates a voltage drop across the transformer's internal resistance, effectively pulling down the supply voltage. Furthermore, the dynamic forward voltage drop ($V_F$) of the physical 1N4007 diode increases significantly under heavy surge currents, a non-linear characteristic often overlooked by default simulation models. Consequently, Table 2 represents a more accurate reflection of real-world circuit behavior.

**3. Degradation of Load Capacity Due to Transformer Internal Resistance (Primary Error Source)**
In theoretical calculations and ideal simulations (such as the default AC source in Multisim), the power supply is typically assumed to be an ideal voltage source with zero internal resistance. However, the physical step-down transformer used in this experiment inherently possesses non-negligible DC winding resistance (copper loss) and leakage inductance. When the rectifier circuit is connected to a large-capacity filter capacitor (e.g., $1000\mu\text{F}$) under a heavy load condition (e.g., $R_L=1\text{k}\Omega$), the capacitor demands a massive transient surge current to charge at the AC voltage peaks. This heavy current flowing through the transformer's internal resistance creates a significant voltage drop, effectively pulling down the actual output voltage of the transformer. This phenomenon directly explains the practical data where the bridge rectifier with a $1000\mu\text{F}$ capacitor experienced a severe voltage drop from 17.421V to 15.803V when the load transitioned from $10\text{k}\Omega$ to $1\text{k}\Omega$. This highlights the crucial engineering discrepancy between physical components and ideal theoretical models.

**4. Safety Considerations Regarding the "Common Ground" Trap in Oscilloscope Measurements**
When testing waveforms in a bridge rectifier circuit, the grounding method of the measuring instrument presents a critical engineering safety concern. The ground clip of a standard desktop digital oscilloscope probe is typically connected internally to the mains Earth Ground. If the input power source in the experiment is not galvanically isolated (via an isolation transformer), indiscriminately attaching the oscilloscope's ground clip to the negative output or other nodes of the bridge rectifier can easily create a low-impedance short-circuit loop through the Earth ground. This not only directly shorts out one or more diodes in the bridge topology—destroying the rectification mechanism—but also risks instantaneous catastrophic failure of the components or damage to the expensive measuring equipment. Therefore, reflecting on and avoiding this "common ground" trap by ensuring the use of an isolated power supply or utilizing differential probes for floating measurements is an indispensable safety principle in hardware experiments.