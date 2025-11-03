### a. Prelab

**i) Switch Position Definition**

The digital inputs '0' and '1' are defined by the position of the switches SD₀, SD₁, and SD₂ as follows:
*   **Dₓ = 0** when switch SDₓ connects the corresponding resistor to the ground.
*   **Dₓ = 1** when switch SDₓ connects the corresponding resistor to the voltage source, Vₛ (8V).

**ii) Calculation of Equivalent Resistance (Rₐᵦ)**

To calculate the equivalent resistance Rₐᵦ (which is the Thévenin resistance R₀) seen from terminals a-b, the voltage source Vₛ is deactivated (shorted to ground). The switch S is open.

1.  When Vₛ is shorted to ground, both the '0' and '1' positions of the switches (SD₀, SD₁, SD₂) are connected to ground.
2.  Looking into terminal 'a', the resistance is R₆ in series with the parallel combination of all resistors connected to the central node (let's call it N).
3.  The resistors connected between node N and ground are R₁, R₂, R₃, R₄, and R₅.
4.  The equivalent resistance of these parallel resistors (Rₚ) is calculated as:
    1/Rₚ = 1/R₁ + 1/R₂ + 1/R₃ + 1/R₄ + 1/R₅
    1/Rₚ = 1/2kΩ + 1/2kΩ + 1/2kΩ + 1/2kΩ + 1/1kΩ
    1/Rₚ = 4/(2kΩ) + 1/(1kΩ) = 2/1kΩ + 1/1kΩ = 3/1kΩ
    Rₚ = 1kΩ / 3 ≈ 333.33 Ω
5.  The total equivalent resistance Rₐᵦ (R₀) is R₆ in series with Rₚ:
    Rₐᵦ = R₀ = R₆ + Rₚ = 1kΩ + (1/3)kΩ = 4/3 kΩ
    **Rₐᵦ = R₀ ≈ 1.33 kΩ**

This resistance is constant regardless of the switch positions.

**iii) Calculation of Open Circuit Voltage (Vₐᵦₒ꜀) and D/A Relation**

The open-circuit voltage Vₐᵦₒ꜀ is calculated with switch S open. With no load connected, no current flows through R₆, so the voltage at terminal 'a' is equal to the voltage at the central node N (Vₐᵦₒ꜀ = Vₙ).

1.  We can find Vₙ using nodal analysis at node N. The sum of currents leaving the node is zero. The voltage at the end of the input resistors (R₂, R₃, R₄) is determined by the digital inputs: Vₓ = Dₓ * Vₛ.
    (Vₙ/R₁) + (Vₙ/R₅) + (Vₙ - V₀)/R₂ + (Vₙ - V₁)/R₃ + (Vₙ - V₂)/R₄ = 0
2.  Rearranging for Vₙ:
    Vₙ * (1/R₁ + 1/R₅ + 1/R₂ + 1/R₃ + 1/R₄) = (D₀*Vₛ)/R₂ + (D₁*Vₛ)/R₃ + (D₂*Vₛ)/R₄
3.  Substituting the resistor values:
    Vₙ * (1/2k + 1/1k + 1/2k + 1/2k + 1/2k) = (D₀*8V)/2k + (D₁*8V)/2k + (D₂*8V)/2k
    Vₙ * (3/1k) = (8V/2k) * (D₀ + D₁ + D₂)
    Vₙ = (1k/3) * (4V/1k) * (D₀ + D₁ + D₂)
    **Vₐᵦₒ꜀ = Vₙ = (4/3) * (D₀ + D₁ + D₂)**
4.  From this D/A relation, we can find the constants k₀, k₁, and k₂:
    Vₐᵦₒ꜀ = k₂D₂ + k₁D₁ + k₀D₀
    Therefore, **k₀ = 4/3 V**, **k₁ = 4/3 V**, and **k₂ = 4/3 V**.

Using this formula, we can complete Table 1.

**Table 1: Pre-lab Calculation Results**

| **D₂ D₁ D₀** | **000** | **001** | **011** | **010** | **011** | **100** | **101** | **111** |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Vₐᵦₒ꜀** | 0.00 V | 1.33 V | 2.67 V | 1.33 V | 2.67 V | 1.33 V | 2.67 V | 4.00 V |
| **Rₐᵦ(R₀)** | 1.33 kΩ | 1.33 kΩ | 1.33 kΩ | 1.33 kΩ | 1.33 kΩ | 1.33 kΩ | 1.33 kΩ | 1.33 kΩ |