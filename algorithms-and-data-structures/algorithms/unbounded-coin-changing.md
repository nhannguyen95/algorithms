## Problem
Given a set of n coins (infinite ammount) and M cents, making change
for M cents using the fewest number of coins.

## Solutions

### Greedy

Making change in decreasing coin values.

However the greedy algorithm doesn't work in all cases.

Suppose that the denominations of the coins are c^0, c^1 .. , c^k
for some integers c > 1 and k >= 1. Greedy algorithm yields optimal
solution for this case.

### DP

DP works in general cases: dp[i][m] is the fewest coins used to
represent m cents if using the first 1 coins.
- dp[i][0] = 0: we need 0 coins to produce 0 cents.
- dp[0][j] = ∞ (j != 0).
- dp[m] = min(1 + dp[m - coins[i]]) ∀i in [0..n-1].

```
for i = 1 to n
    for m = 1 to M
        if j < coins[i]
            f[i][j] = f[i-1][j]
        else
            f[i][j] = min(f[i-1][j], f[i][j-coins[i]] + 1)
```
