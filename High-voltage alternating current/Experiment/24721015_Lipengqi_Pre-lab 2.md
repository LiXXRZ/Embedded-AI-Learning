# Advanced AC Circuit - Pre-Lab Report
**Laboratory Exercise No:** 2 - Diode Rectifier Circuits
**Student Name:** Li Pengqi
**Student ID:** 24721015

## 1. Objectives of Pre-Lab
To simulate half-wave and bridge rectifier circuits using Multisim software, observe the output voltage waveforms, measure the DC output voltages and ripple ranges under different filter capacitors ($100\mu F$, $1000\mu F$) and load resistors ($1k\Omega$, $10k\Omega$), and analyze the essential effects of diode rectification and capacitor filtering.

---

## 2. Simulation Measurements (Table 1)

*Note: The Input AC power is set to 13.7 Vrms, 50 Hz. Multimeter is set to DC mode to measure the output average voltage.*

| Circuit Type | Filter Capacitor | Input AC Voltage (Vrms) | Output Average Voltage (V DC) <br> $R_L=1k\Omega$ / $R_L=10k\Omega$ | Output Waveform Characteristics (Description) | Ripple Condition (Large/Medium/Small) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Half-wave rectification** | **None** | 13.7 | 5.85 V / 5.90 V | **Pulsating DC:** Only positive half-cycles are retained; flat zero voltage during negative half-cycles. | **Large** (drops to 0V) |
| **Half-wave rectification** | **$100\mu F$** | 13.7 | 17.16 V / 18.54 V | **Sawtooth ripple:** Rapid charge to peak during positive cycle, slow exponential discharge through the load. | **Medium** ($1k\Omega$) / **Small** ($10k\Omega$) |
| **Half-wave rectification** | **$1000\mu F$** | 13.7 | 18.41 V / 18.60 V | **Nearly flat DC line:** Very slow discharge due to large RC time constant, almost tracking the peak voltage. | **Small** |
| **Bridge rectification** | **None** | 13.7 | 11.04 V / 11.28 V | **Full-wave pulsating DC:** Continuous consecutive positive half-sines, negative halves are flipped positive. Frequency is 100Hz. | **Large** (drops to 0V) |
| **Bridge rectification** | **$100\mu F$** | 13.7 | 17.27 V / 17.95 V | **Sawtooth ripple:** Discharges for only half the time compared to half-wave before recharging. | **Small** (vs. half-wave) |
| **Bridge rectification** | **$1000\mu F$** | 13.7 | 17.69 V / 17.96 V | **Flat DC line:** Ripple is negligible; voltage stays constantly near the peak value minus two diode drops. | **Very Small** |

---

## 3. Pre-Lab Analysis and Conclusions

Based on the Multisim simulation results from steps (1) to (3), the following conclusions are obtained regarding the rectifier circuits:

**1. Half-Wave vs. Bridge Rectification Efficiency:**
The bridge rectifier provides much higher efficiency and output voltage. Without a filter capacitor, the average DC output voltage of the bridge rectifier ($\sim 11.4V$) is almost twice that of the half-wave rectifier ($\sim 5.9V$). Furthermore, the bridge rectifier doubles the ripple frequency from 50Hz to 100Hz. This reduces the time interval between charging peaks, making it significantly easier to filter.

**2. The Role of the Filter Capacitor:**
The addition of a parallel capacitor effectively converts the highly pulsating DC output into a relatively smooth DC voltage. The capacitor charges to the maximum peak voltage and supplies current to the load during the intervals when the AC voltage drops. This prevents the output voltage from dropping to zero and drastically increases the overall average DC voltage.

**3. Effect of Capacitor Size ($100\mu F$ vs. $1000\mu F$):**
The smoothing effect depends on the RC time constant ($\tau = R \times C$). A larger capacitance ($1000\mu F$) stores more charge and discharges much slower compared to a smaller one ($100\mu F$). Therefore, increasing the capacitor size results in a visually flatter waveform, a **smaller ripple voltage**, and a **higher average DC output voltage**.

**4. Effect of Load Resistance ($1k\Omega$ vs. $10k\Omega$):**
When the load resistance is increased from $1k\Omega$ to $10k\Omega$, the load current decreases. According to $\tau = R \times C$, a larger resistance increases the discharge time constant. Consequently, for the exact same filter capacitor, a lighter load ($10k\Omega$) will drain the capacitor slower, leading to reduced ripple and a higher average output voltage compared to a heavier load ($1k\Omega$).

---

## 4. Multisim Simulation Waveforms

*Note: In the following oscillograms, **Channel A (Red)** represents the AC input waveform, and **Channel B (Blue)** represents the DC output waveform across the load resistor ($R_L=1k\Omega$).*

### 4.1 Half-Wave Rectifier Waveforms

<center>
    <img src = "https://img.cdn1.vip/i/69d72dd4ae037_1775709652.webp"
        width = 50%>
</center>
<center>
    <em>Figure 1: Half-wave rectifier output without filter capacitor.</em>
</center>

<center>
    <img src = "https://img.cdn1.vip/i/69d72dd48aee4_1775709652.webp"
        width = 50%>
</center>
<center>
    <em>Figure 2: Half-wave rectifier output with 100μF filter capacitor. Notice the noticeable sawtooth ripple.</em>
</center>

<center>
    <img src = "https://img.cdn1.vip/i/69d72dd4b0ff7_1775709652.webp"
        width = 50%>
</center>
<center>
    <em>Figure 3: Half-wave rectifier output with 1000μF filter capacitor. The ripple is heavily reduced.</em>
</center>

### 4.2 Bridge Rectifier Waveforms

<center>
    <img src = "https://img.cdn1.vip/i/69d72dd516a38_1775709653.webp"
        width = 50%>
</center>
<center>
    <em>Figure 4: Bridge rectifier output without filter capacitor.</em>
</center>

<center>
    <img src = "https://img.cdn1.vip/i/69d72e270d465_1775709735.webp"
        width = 50%>
</center>
<center>
    <em>Figure 5: Bridge rectifier output with 100μF filter capacitor.</em>
</center>

<center>
    <img src = "https://img.cdn1.vip/i/69d72dd4b5e92_1775709652.webp"
        width = 50%>
</center>
<center>
    <em>Figure 6: Bridge rectifier output with 1000μF filter capacitor.</em>
</center>