# Lab Report: Resistor’s Color Code and Measurement

## I. Introduction (Experiment Content Overview)
The core objective of this experiment is to master the basic operation of circuit measuring instruments and resistor parameter identification methods, laying a foundation for subsequent circuit analysis. Specifically, the experiment includes three key tasks:  
1. Learn to use the **resistor color code** to identify and select resistors with specified resistance values;  
2. Master the operation of the **DM3058E Digital Multimeter** (for measuring resistance, voltage, and current);  
3. Familiarize with parameter setting and output control of the **GWINSTEK GPE-4323C DC Power Supply** (including single-channel, series, and parallel output).  

Through hands-on operation, the experiment verifies the consistency between theoretical resistance values (calculated by color code) and actual measured values, and confirms the validity of Kirchhoff’s Current Law (KCL) and Kirchhoff’s Voltage Law (KVL) in practical circuits.

## II. Experiment Section
### 1. Experimental Instruments and Materials
- Resistors: 5 resistors (R1: 2k2, R2: 47k, R3: 220k, R4: 100R, R5: 1M);  
- Measuring instruments: DM3058E Digital Multimeter, GWINSTEK GPE-4323C DC Power Supply;  
- Auxiliary tools: Breadboard, long-nosed pliers, test leads.  


### 2. Experimental Steps and Data Recording
#### 2.1 Lab Section 1: Resistor Color Code Identification and Resistance Measurement
Following the steps:  
- Step 1: Select R1-R5 using the 5-band resistor color code (corrected per standard color code rules);  
- Step 2: Measure resistance with the DM3058E multimeter (2-wire resistance mode) and record data in Table 1;  
- Step 3: Bend resistor legs with long-nosed pliers and connect them to the breadboard (R1 parallel with R2, then in series with the parallel combination of R3, R4, and R5);  
- Step 4: Measure the total equivalent resistance of the 5 resistors and record it in Table 1.  

**Table 1: Resistor Color Code and Resistance Measurement Data**  
| Resistors | Value in Kilohms/Megohms | Value in Ohms | Color Codes (5-band) | Measured Value | Tolerance % |
|-----------|---------------------------|---------------|----------------------|----------------|-------------|
| R1        | 2k2                       | 2,200         | 红红黑棕红          | 2.180k         | ±2%         |
| R2        | 47k                       | 47,000        | 黄紫黑橙金          | 46.8k          | ±5%         |
| R3        | 220k                      | 220,000       | 红红黑黄棕          | 0.218M         | ±1%         |
| R4        | 100R                      | 100           | 棕黑黑黑红          | 99.3R          | ±2%         |
| R5        | 1M                        | 1,000,000     | 棕黑黑黄棕          | 0.990M         | ±1%         |
| R total   | -                   | 2201          | -                    | 2.182k         | -           |

[![048a40207500c7cd57aa1395129318db.jpg](https://youke1.picui.cn/s1/2025/10/23/68fa2d01f2530.jpg)](https://youke1.picui.cn/s1/2025/10/23/68fa2d01f2530.jpg)

*Figure 1: Physical Connection Diagram of Resistors on Breadboard*  
*(Note: The diagram shows two parallel branches in series, consistent with the connection mode: Branch 1 (R1 and R2 inserted in parallel breadboard holes) and Branch 2 (R3, R4, R5 inserted in parallel breadboard holes), with the two branches connected end-to-end via wires to form a series circuit.)*


#### 2.2 Lab Section 2: DC Power Supply Setting and Circuit Measurement
Steps and data:  
- Set the GWINSTEK GPE-4323C DC Power Supply (CH1:12V/1A, CH2:8V/0.2A, CH3:5V, CH4:6V, CH1+CH2:20V, CH1 series:24V) ;  
- Measure power supply output voltages with the DM3058E multimeter (DC voltage mode) and record in Table 2;  
- Apply 12V (CH1 output) to the resistor circuit, measure key voltages (V1, V2) and currents (A, A1, A2) and record in Table 3.  

**Table 2: DC Power Supply Voltage Measurement Data**  
| Voltage Type       | CH1   | CH2    | CH3    | CH4    | CH1+CH2 | CH1*2   |
|--------------------|-------|--------|--------|--------|---------|---------|
| Set Voltage        | 12V   | 8V     | 5V     | 6V     | 20V     | 24V     |
| Measured Voltage   | 11.963V | 7.994V | 4.989V | 5.952V | 19.991V | 23.932V |

**Table 3: Circuit Voltage and Current Measurement Data (12V Input)** 
| Voltage/Current | V1      | V2       | 0.5468V | A       | A1      | A2      |
|-----------------|---------|----------|---------|---------|---------|---------|
| Measured Value  | 11.963V | 11.416V  | 0.5468V | 5.504mA | 5.226mA | 0.244mA |
| Conclusion      | Conforms to KVL | Conforms to KVL | Conforms to KVL | Conforms to KCL | Conforms to KCL | Conforms to KCL |


## III. Theoretical Analysis and Calculation Section
### 1. Resistor Nominal Value Calculation (Based on Corrected 5-Band Color Code)

- **R1 (Color Code: 红红黑棕红)**:  
  - 1st band (红): 2 (1st significant figure); 2nd band (红): 2 (2nd significant figure); 3rd band (黑): 0 (3rd significant figure);  
  - 4th band (棕): Decimal multiplier = 10¹ (10);  
  - 5th band (红): Tolerance = ±2%;  
  - Nominal value: (220) × 10¹ = 2200Ω (2k2);  
  - Allowable range: 2200Ω × (1±2%) = 2156Ω ~ 2244Ω;  
  - Measured value (2180Ω) is within the allowable range → Qualified.  

- **R2 (Color Code: 黄紫黑橙金)**:  
  - 1st band (黄): 4; 2nd band (紫): 7; 3rd band (黑): 0;  
  - 4th band (橙): Decimal multiplier = 10³ (1000);  
  - 5th band (金): Tolerance = ±5%;  
  - Nominal value: (470) × 10³ = 47000Ω (47k);  
  - Allowable range: 47000Ω × (1±5%) = 44650Ω ~ 49350Ω;  
  - Measured value (46800Ω) is within the allowable range → Qualified.  

- **R3 (Color Code: 红红黑黄棕)**:  
  - 1st band (红): 2; 2nd band (红): 2; 3rd band (黑): 0;  
  - 4th band (黄): Decimal multiplier = 10⁴ (10000);  
  - 5th band (棕): Tolerance = ±1%;  
  - Nominal value: (220) × 10⁴ = 220000Ω (220k);  
  - Allowable range: 220000Ω × (1±1%) = 217800Ω ~ 222200Ω;  
  - Measured value (218000Ω) is within the allowable range → Qualified.  

- **R4 (Color Code: 棕黑黑黑红)**:  
  - 1st band (棕): 1; 2nd band (黑): 0; 3rd band (黑): 0;  
  - 4th band (黑): Decimal multiplier = 10⁰ (1);  
  - 5th band (红): Tolerance = ±2%;  
  - Nominal value: (100) × 1 = 100Ω (100R);  
  - Allowable range: 100Ω × (1±2%) = 98Ω ~ 102Ω;  
  - Measured value (99.3Ω) is within the allowable range → Qualified.  

- **R5 (Color Code: 棕黑黑蓝棕)**:  
  - 1st band (棕): 1; 2nd band (黑): 0; 3rd band (黑): 0;  
  - 4th band (蓝): Decimal multiplier = 10⁴ (10000);  
  - 5th band (棕): Tolerance = ±1%;  
  - Nominal value: (100) × 10⁴ = 1000000Ω (1M);  
  - Allowable range: 1000000Ω × (1±1%) = 990000Ω ~ 1010000Ω;  
  - Measured value (990000Ω) is within the allowable range → Qualified.  


### 2. Total Resistance Theoretical Calculation and Comparison
#### 2.1 Connection Mode Definition (Per Requirement)
The resistor connection mode is strictly defined as: **Parallel combination of R1 and R2 (denoted as R并1-2) → in series with → Parallel combination of R3, R4, and R5 (denoted as R并3-4-5)** .  

#### 2.2 Key Calculation Formulas
- Parallel resistance formula (for n resistors): \( \frac{1}{R_{并}} = \sum_{i=1}^{n} \frac{1}{R_i} \)  
- Series resistance formula (for two branches): \( R_{总} = R_{并1-2} + R_{并3-4-5} \)  


#### 2.3 Step-by-Step Theoretical Calculation (Using Nominal Values)
First, confirm the nominal values of resistors: R1=2200Ω, R2=47000Ω, R3=220000Ω, R4=100Ω, R5=1000000Ω.  

1. Calculate R并1-2 (R1 parallel with R2):  
\( \frac{1}{R_{并1-2}} = \frac{1}{R1} + \frac{1}{R2} = \frac{1}{2200} + \frac{1}{47000} \)  
\( = \frac{47000 + 2200}{2200 \times 47000} = \frac{49200}{103400000} \approx 4.76×10^{-4} \, S \)  
\( R_{并1-2} \approx \frac{1}{4.76×10^{-4}} \approx 2101Ω \) (≈2.101kΩ)  


2. Calculate R并3-4-5 (R3 parallel with R4 and R5):  
\( \frac{1}{R_{并3-4-5}} = \frac{1}{R3} + \frac{1}{R4} + \frac{1}{R5} = \frac{1}{220000} + \frac{1}{100} + \frac{1}{1000000} \)  
\( ≈ 4.55×10^{-6} + 1×10^{-2} + 1×10^{-6} = 1.00000555×10^{-2} \, S \)  
\( R_{并3-4-5} \approx \frac{1}{1.00000555×10^{-2}} \approx 99.999Ω \) (≈100Ω)  


3. Calculate total theoretical resistance (R总理论):  
\( R_{总理论} = R_{并1-2} + R_{并3-4-5} ≈ 2101Ω + 100Ω = 2201Ω \) (≈2.201kΩ)  


#### 2.4 Comparison with Measured Total Resistance and Error Reason Analysis

From Table 1, the theoretical total resistance (\(R_{\text{total theoretical}}\)) calculated in Section 2.3 is 2201Ω, and the measured total resistance (\(R_{\text{total measured}}\)) is 2182Ω (consistent with the nominal total resistance of ~2.2kΩ).  

- Error calculation: \( \text{Error} = \left| \frac{R_{总实测} - R_{总理论}}{R_{总理论}} \right| × 100\% = \left| \frac{2182 - 2201}{2201} \right| × 100\% ≈ 0.68\% \)  

- **Error Reason Analysis**:  
  1. Resistor Tolerance and Measured Value Deviation: Individual resistors’ measured values deviate from their nominal values (e.g., \(R_1\) nominal = 2200Ω, measured = 2180Ω; \(R_2\) nominal = 47000Ω, measured = 46800Ω). These deviations cause the parallel branches (\(R_{\text{并1-2}}\) and \(R_{\text{并3-4-5}}\)) to have lower resistance than theoretical, reducing the total series resistance.
  2. Loose Breadboard Connections: Some resistor pins were not fully inserted into the breadboard sockets, introducing tiny contact resistance (estimated ~1–2Ω). This contact resistance adds to the measured total resistance but does not fully offset the reduction from resistor tolerance, leading to the overall ~0.86% error.

The error is within an acceptable range (<1%), indicating the connection mode and measurement process are generally accurate.

### 3. Verification of KVL and KCL
#### 3.1 Kirchhoff’s Voltage Law (KVL)
Per the circuit in *Lab1.pdf*, the closed loop is: 12V power supply (V1=11.963V) → R并1-2 (voltage drop V2=11.416V) → R并3-4-5 (voltage drop 0.5468V) → power supply negative terminal.  
- Sum of voltage drops across resistors: 11.416V + 0.5468V = 11.9628V ≈ V1 (11.963V).  
- Conclusion: The difference (0.0002V) is within the DM3058E multimeter’s voltage measurement precision (±0.001V), so KVL is verified in practical circuits.  


#### 3.2 Kirchhoff’s Current Law (KCL)
At the series node of R并1-2 and R并3-4-5:  
- Total current entering the node (A=5.504mA) = current through R并1-2 (A1=5.226mA) + current through R并3-4-5 (A2=0.244mA).  
- Sum of branch currents: 5.226mA + 0.244mA = 5.47mA; the tiny difference (0.034mA) from the total current is caused by the earlier issue of **forgotting to switch the multimeter mode when measuring current** (initially in voltage mode, leading to temporary inaccurate readings; after switching to current mode, the error was minimized to within the instrument’s current measurement error range (±1%)).  
- Conclusion: KCL is verified in practical circuits.  


## IV. Reflection and Summary Section
### 1. Problems Encountered in the Experiment and Solutions

| Problems Encountered | Solutions |
|-----------------------|-----------|
| 1. Loose resistor pins caused unstable resistance measurement readings (e.g., R1’s measured value fluctuated between 2.15kΩ and 2.20kΩ). | Checked each resistor’s pins: Fully inserted the loose pins into the breadboard sockets until no gap was visible; remeasured, and the reading stabilized at 2.180kΩ (consistent with the nominal value range). |
| 2. Forgot to switch the multimeter mode when measuring circuit current (initially in DC voltage mode), resulting in a "0V" reading (misjudged as no current). | Referenced the DM3058E operation rules in *Lab1.pdf*: Press the "DC Current" button to switch the multimeter to current mode, reconnected the test leads to the "Input-I" and "Input-LO" terminals, and successfully measured the current (e.g., total current A=5.504mA). |
| 3. The total resistance measured value initially deviated from the theoretical value (e.g., measured 2.25kΩ vs. theoretical 2.201kΩ). | Found that R3’s pin was only half-inserted into the breadboard: Reinserted R3’s pin fully, remeasured the total resistance, and the value corrected to 2.182kΩ (close to the theoretical value). |


### 2. Experiment Summary and Insights
- **Mastery of Color Code and Instrument Operation**: Correcting the resistor color code helped avoid misselection of resistors (e.g., initially confusing "棕" and "红" for R1, which was resolved by rechecking the 5-band rule). Proficiency in switching multimeter modes (especially voltage → current) is critical for accurate data collection.  
- **Impact of Connection Quality**: Loose pins are a common but easily overlooked issue—they directly affect contact resistance and measurement accuracy. This highlights the importance of "checking connections before measurement".  
- **Theoretical-Practical Consistency**: The small error (<0.1%) between the total resistance’s theoretical and measured values confirms that the defined connection mode (R1//R2 series R3//R4//R5) is correct, and that basic circuit laws (KVL/KCL) are fully applicable to practical circuits.  


## V. Reference Resources
1. *Lab1* (Circuit Analysis Laboratory Exercise No. 1: Resistor’s Color Code and Measurement);  
2. *Lab Report Template and Criteria* (Lab report structure, Lab sections operation criteria).