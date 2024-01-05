## Problems

Given a set of n coins (infinite ammount) count the number of
possible (canonical, i.e. `{1, 5}` is same as `{5, 1}` and thus only
counted once) ways to get M cents.

## Solutions

DP: f[i][m] is the number of ways to get m cents from first i coins
- f[i][0] = 1.

```
for i = 1 to n
    for j = 1 to M
        if j < coins[i]
            f[i][j] = f[i-1][j]
        else
            f[i][j] = f[i-1][j] + f[i][j-coins[i]]
```