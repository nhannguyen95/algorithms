**`F(N) = F(N / 2) + N, F(0) = 1**`

Answer: `F(N) = O(N)`

Proof: `F(N) = N(1/2^0 + 1/2^1 + .. 1/2^logN) = N[((1/2)^(logN + 1) - 1) / (1/2 - 1)] = O(2N) = O(N)`

--

**`F(N, M) = F(N - 1, M) + F(N, M - 1)`**

Answer: `F(N) = O(2^(N + M) / sqrt(N + M))`

[Proof](https://stackoverflow.com/questions/25671967/whats-time-complexity-of-this-algorithm-for-wildcard-matching):
- Substituing `N = n - k`, `M = k`, `F(N, M) = 2C(n, k) - 1`.
- Then we have `C` is binomial coefficients, and `F(N, M) = 2C(n, k) - 1`.
- `F(N, M) = 2C(N + M, M) - 1`, and according to weak Stirling's the best big-O bound w.r.t `N + M` is `O(2^(N + M) / sqrt(N + M)` _[1]_.

---

[[1]](https://math.stackexchange.com/questions/1442899/stirling-s-approximation-and-big-o): The weak Stirling's approximation for `C(2n, n)` is `O(2^2n / sqrt(pin))` 
