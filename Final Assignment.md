## Final Assignment
**通信2401 李鹏麒 24721015**

### Problem 1: Application of Expectation (Chapter 4)
**Scenario: The "Gacha" Lucky Draw**
In a popular mobile game, a "Mystery Chest" costs **50 diamonds** to open. The rewards inside are random:
*   A **Common Item** worth 10 diamonds (Probability = 0.6)
*   A **Rare Item** worth 100 diamonds (Probability = 0.3)
*   An **Epic Item** worth 500 diamonds (Probability = 0.1)

Let $X$ be the **net profit** (Reward Value minus Cost) for a single draw.
1.  Determine the Probability Function (PF) of $X$.
2.  Calculate the expected net profit $E(X)$. Is this game "fair" to the player in the long run?

**Solution:**
1.  **Define the Random Variable $X$ (Net Profit):**
    *   If Common: $x_1 = 10 - 50 = -40$
    *   If Rare: $x_2 = 100 - 50 = 50$
    *   If Epic: $x_3 = 500 - 50 = 450$
    
    The PF is:
    | $X$ | -40 | 50 | 450 |
    | :--- | :--- | :--- | :--- |
    | $P(X=x)$ | 0.6 | 0.3 | 0.1 |

    **(Scoring: 3 points for correctly defining $X$ and its PF)**

2.  **Calculate $E(X)$:**
    Using the definition $E(X) = \sum x_k p_k$:
    $$E(X) = (-40 \times 0.6) + (50 \times 0.3) + (450 \times 0.1)$$

    $$E(X) = -24 + 15 + 45$$

    $$E(X) = 36 \text{ diamonds}$$
    
    **(Scoring: 5 points for the calculation steps)**

3.  **Conclusion:**
    Since $E(X) = 36 > 0$, the player expects to gain 36 diamonds per draw on average. The game is highly favorable to the player. 
    **(Scoring: 2 points for the interpretation)**

---

### Problem 2: Central Limit Theorem (Chapter 5)
**Scenario: The Coffee Shop Rush**
A trendy coffee shop finds that the amount of caffeine in its "Mega-Espresso" follows a distribution with a mean $\mu = 200\text{ mg}$ and a standard deviation $\sigma = 40\text{ mg}$. During a morning rush, the shop sells **$n = 64$** cups. 

Calculate the probability that the **total amount** of caffeine sold exceeds **13,120 mg**. (Assume the caffeine amounts in each cup are independent).

**Solution:**
1.  **Identify the Distribution of the Sum:**
    Let $X_i$ be the caffeine in the $i$-th cup. $n=64$. 
    By the Central Limit Theorem (CLT), the sum $S_n = \sum_{i=1}^{64} X_i$ approximately follows a Normal Distribution:
    $$S_n \sim N(n\mu, n\sigma^2)$$

    **(Scoring: 2 points for stating the CLT application)**

2.  **Calculate Parameters for $S_n$:**
    *   Mean $E(S_n) = n\mu = 64 \times 200 = 12,800$
    *   Variance $V(S_n) = n\sigma^2 = 64 \times 40^2 = 64 \times 1600 = 102,400$
    *   Standard Deviation $\sigma_{S_n} = \sqrt{102,400} = 320$
    **(Scoring: 3 points for correct mean and standard deviation)**

3.  **Standardize and Solve:**
    We want to find $P(S_n > 13,120)$. Standardize to $Z$:
    $$Z = \frac{13,120 - 12,800}{320} = \frac{320}{320} = 1$$

    **(Scoring: 3 points for the "clever" standardization result $Z=1$)**

4.  **Final Probability:**
    $$P(S_n > 13,120) = P(Z > 1) = 1 - \Phi(1)$$

    From the Z-table, $\Phi(1) \approx 0.8413$.
    $$P(Z > 1) = 1 - 0.8413 = 0.1587$$

    **(Scoring: 2 points for the final lookup and result)**

---

### Problem 3: Moment and MLE Estimation (Chapter 6)
**Scenario: Estimating the "Luck Parameter"**
Suppose the "Luck Score" $X$ of players in a game follows a continuous distribution with PDF:
$$f(x; \theta) = (\theta+1)x^{\theta}, \quad 0 \le x \le 1, \quad \theta > -1$$
Given a random sample $X_1, X_2, \dots, X_n$:
1.  Find the Moment Estimator (ME) of $\theta$.
2.  Find the Maximum Likelihood Estimator (MLE) of $\theta$.

**Solution:**
1.  **Moment Estimator (ME):**
    First, find the first population moment $E(X)$:
    $$E(X) = \int_0^1 x \cdot (\theta+1)x^{\theta} dx = (\theta+1) \int_0^1 x^{\theta+1} dx = \frac{\theta+1}{\theta+2}$$

    Set $E(X) = \bar{X}$:
    $$\bar{X} = \frac{\theta+1}{\theta+2} \implies \bar{X}\theta + 2\bar{X} = \theta + 1 \implies \theta(\bar{X}-1) = 1-2\bar{X}$$

    $$\hat{\theta}_{ME} = \frac{1-2\bar{X}}{\bar{X}-1} = \frac{2\bar{X}-1}{1-\bar{X}}$$

    **(Scoring: 5 points: 2 for $E(X)$, 3 for solving $\theta$)**

2.  **Maximum Likelihood Estimator (MLE):**
    The Likelihood function is:
    $$L(\theta) = \prod_{i=1}^n (\theta+1)X_i^{\theta} = (\theta+1)^n (\prod_{i=1}^n X_i)^{\theta}$$

    Take the natural log:
    $$\ln L(\theta) = n \ln(\theta+1) + \theta \sum_{i=1}^n \ln X_i$$

    Take the derivative with respect to $\theta$ and set to 0:
    $$\frac{d \ln L}{d \theta} = \frac{n}{\theta+1} + \sum_{i=1}^n \ln X_i = 0$$

    $$\frac{n}{\theta+1} = -\sum_{i=1}^n \ln X_i \implies \theta+1 = \frac{-n}{\sum \ln X_i}$$

    $$\hat{\theta}_{MLE} = -\frac{n}{\sum_{i=1}^n \ln X_i} - 1$$

    **(Scoring: 5 points: 1 for $L(\theta)$, 2 for $\ln L$, 2 for solving $d/d\theta=0$)**