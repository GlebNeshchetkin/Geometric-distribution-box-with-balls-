# Box with N balls (geometric distribution)

## Function F(N) Estimation
$X_i$ is the number of operations required to select the $i_{th}$ color after selecting $i−1$ colors.
For $X_i$, the probability of selecting a new color $$p_i=\frac{N-(i-1)}{N}$$

$$
F(N) = E(\sum_{i=1}^{N} X_i)=\sum_{i=1}^{N} E(X_i) = \sum_{i=1}^{N} \frac{1}{p_i}
$$

The function F(N) [expected number of operations required to take each of N balls in the box at least once] for N<=100 is defined as follows:

$$
F(N) = N\sum_{i=1}^{N} \frac{1}{i}
$$

For N>100:

$$
F(N) = \gamma N + N \ln(N) + 0.5
$$

where γ is the Euler-Mascheroni constant.

### Precision
For N from 1000 to $5*10^{7}$ with step 1000 average precision is 0.122.

## Confidence Interval Calculation
To calculate the confidence interval for F(100) with a 99% confidence level, the following steps are taken:

1. The mean of F(100) is estimated using the formula provided.
2. Standard deviation is obtained by taking the square root of the variance.
3. Using the Z-score for a 99% confidence level (approximately 2.58), the length of the confidence interval is computed.
4. The confidence interval is determined by adding and subtracting the interval length from the mean.

$$
\text{Var}[F(N)] = \sum_{i=1}^{N} \text{Var}[X_i] + 2 \sum_{i < j} \text{Cov}[X_i, X_j]
$$

$X_i$ and $X_j$ are independent since the sequence of colors is not important.

$$
\text{Var}[F(N)] = \sum_{i=1}^{N} \text{Var}[X_i] = \sum_{i=1}^{N} \frac{1-p_i}{p_i^2}
$$

### Result
Interval [L, R] for F(100) 99% confidence: [486.277, 551.201]

## Usage
To run the program, compile `main.cpp` using a C++ compiler and execute the generated binary. The only argument is N.
> g++ ./main.cpp -o main \
> ./main 100
