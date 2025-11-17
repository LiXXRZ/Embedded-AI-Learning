# **Pre-lab 3**

##### 通信2401 24721015 李鹏麒

### **Part I: Wheatstone Bridge**

#### **2. Pre-Lab Questions**

**a) Analyze the Wheatstone bridge shown in Figure 1 and show that the voltage between point A and B can take the following form:**

Vout = Vin * [R₂ / (R₁ + R₂) - R₃ / (R₃ + R₄)] (1)

**Derivation:**

The Wheatstone bridge consists of two voltage dividers connected in parallel.

*   **Voltage at Point A (Vₐ):**
    The voltage at point A is determined by the voltage divider formed by resistors R₁ and R₂.
    Vₐ = Vin * [R₂ / (R₁ + R₂)]

*   **Voltage at Point B (Vᵦ):**
    The voltage at point B is determined by the voltage divider formed by resistors R₄ and R₃.
    Vᵦ = Vin * [R₃ / (R₄ + R₃)]

*   **Output Voltage (Vout):**
    The output voltage Vout is the potential difference between points A and B.
    Vout = Vₐ - Vᵦ
    Substituting the expressions for Vₐ and Vᵦ gives:
    **Vout = Vin * [R₂ / (R₁ + R₂) - R₃ / (R₃ + R₄)]**

**b) Determine the relationship among the resistors when the Wheatstone bridge shown in Figure 1 is balanced, i.e. Vout = 0.**

**Derivation:**

When the bridge is balanced, Vout = 0. Using the formula derived in part (a):

0 = Vin * [R₂ / (R₁ + R₂) - R₃ / (R₃ + R₄)]

Since the input voltage Vin is non-zero, the expression in the brackets must be equal to zero:

R₂ / (R₁ + R₂) = R₃ / (R₃ + R₄)

By cross-multiplying, we get:

R₂(R₃ + R₄) = R₃(R₁ + R₂)
R₂R₃ + R₂R₄ = R₁R₃ + R₂R₃

Canceling the R₂R₃ term from both sides leaves the balance condition:

**R₂R₄ = R₁R₃**

This can also be expressed as a ratio:

**R₂ / R₁ = R₄ / R₃**

**c) When there is a change (ΔR) in one of the four resistors, the quarter-bridge becomes unbalanced. Assuming R₁ = R₂ = R₃ = R and R₄ = R + ΔR in Figure 1, show that the voltage between point A and B can take the following form:**

Vout ≈ (Vin * ΔR) / (4R) (2)

**Derivation:**

Start with the general formula for Vout from part (a):
Vout = Vin * [R₂ / (R₁ + R₂) - R₃ / (R₃ + R₄)]

Substitute the given conditions: R₁ = R, R₂ = R, R₃ = R, and R₄ = R + ΔR.

Vout = Vin * [R / (R + R) - R / (R + (R + ΔR))]
Vout = Vin * [R / (2R) - R / (2R + ΔR)]
Vout = Vin * [1/2 - R / (2R + ΔR)]

To combine the terms, find a common denominator, which is 2(2R + ΔR):

Vout = Vin * [(2R + ΔR) / (2(2R + ΔR)) - (2R) / (2(2R + ΔR))]
Vout = Vin * [(2R + ΔR - 2R) / (2(2R + ΔR))]
Vout = Vin * [ΔR / (4R + 2ΔR)]

For most sensor applications, the change in resistance (ΔR) is very small compared to the base resistance (R), so ΔR << R. This allows us to approximate the denominator:

4R + 2ΔR ≈ 4R

Substituting this approximation back into the equation gives:

**Vout ≈ Vin * (ΔR / 4R)**

---

### **Part II: Differential Amplifier**

#### **2. Pre-Lab Questions**

**a) Analyze the differential amplifier shown in Figure 3 and determine that if R₇/R₆ = R₉/R₈, the output voltage Vout can be written as:**

Vout = G(V₂ - V₁) (3)
Where G is the voltage gain of the Op-Amp, given by:
G = R₇ / R₆ (4)

**Derivation:**

We assume an ideal operational amplifier with two properties:
1.  The currents into the inverting (-) and non-inverting (+) inputs are zero.
2.  The voltages at the inverting (-) and non-inverting (+) inputs are equal (V₊ = V₋).

*   **Analysis of the non-inverting input (+):**
    The voltage V₊ is determined by the voltage divider formed by R₈ and R₉ from the input V₂.
    V₊ = V₂ * [R₉ / (R₈ + R₉)]

*   **Analysis of the inverting input (-):**
    The voltage V₋ is a result of the superposition of V₁ and Vout.
    V₋ = [V₁ * R₇ / (R₆ + R₇)] + [Vout * R₆ / (R₆ + R₇)]
    V₋ = (V₁R₇ + VoutR₆) / (R₆ + R₇)

*   **Equating the inputs (V₊ = V₋):**
    V₂ * [R₉ / (R₈ + R₉)] = (V₁R₇ + VoutR₆) / (R₆ + R₇)

    Now, apply the given condition **R₇/R₆ = R₉/R₈**. This ratio equality implies that R₉/(R₈ + R₉) = R₇/(R₆ + R₇). Let's substitute this into the equation above:
    V₂ * [R₇ / (R₆ + R₇)] = (V₁R₇ + VoutR₆) / (R₆ + R₇)

    Multiply both sides by (R₆ + R₇):
    V₂R₇ = V₁R₇ + VoutR₆

    Rearrange the equation to solve for Vout:
    VoutR₆ = V₂R₇ - V₁R₇
    VoutR₆ = R₇(V₂ - V₁)
    **Vout = (R₇ / R₆) * (V₂ - V₁)**

    By defining the gain **G = R₇ / R₆**, the expression becomes:
    **Vout = G(V₂ - V₁)**

**b) Using equations (2)~(4), determine the resistance change ΔR shown in Figure 4.**

**Solution:**

First, we relate the output of the Wheatstone bridge to the input of the differential amplifier.
1.  From Equation (2), the output voltage of the quarter-bridge (the voltage difference between the test points) is:
    Vout_bridge = (V₂ - V₁) ≈ Vin * (ΔR / 4R)

2.  From Equation (3), the output of the differential amplifier is:
    Vout_amp = G * (V₂ - V₁)

Now, substitute the expression for the bridge's output (V₂ - V₁) into the amplifier's equation:
Vout_amp ≈ G * [Vin * (ΔR / 4R)]

We need to solve for the resistance change, ΔR. Rearrange the formula:
ΔR ≈ (Vout_amp * 4R) / (G * Vin)

Finally, substitute the expression for the gain G from Equation (4), where G = R₇ / R₆:
**ΔR ≈ (Vout_amp * 4R) / ((R₇ / R₆) * Vin)**

Where:
*   **Vout_amp** is the measured output voltage from the amplifier.
*   **R** is the base resistance of the resistors in the bridge.
*   **R₆** and **R₇** are the resistors in the amplifier circuit.
*   **Vin** is the excitation voltage applied to the bridge (5V in Figure 4).