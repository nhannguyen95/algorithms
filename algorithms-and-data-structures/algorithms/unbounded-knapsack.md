## Problem
Problem: Given n items, ith item is worth v[i] dollars and weights
w[i] pounds. There's a snapsack that has capacity W pounds. Which
items should be taken in the snapsack to maximize the total money?

In this problem, we assume that the weight is integer. If it's
decimal number, we can convert them to integer by multiplication.

0-∞ knapsack: number of each item is infinitive.

## Solution

DP:
- f[i][j]: the maximum money that can be obtained by considering
the first i items and putting them into a knapsack with capacity j.
This definition is same as 0/1 knapsack.
    ```
    for i = 1 to n
        for j = 1 to W
            if w[i] > W
                f[i][j] = f[i-1][j]
            else
                f[i][j] = max(f[i-1][j], v[i] + f[i][j-w[i]])
    ```
- f[i] only depends on f[i-1], so we can optimize space complexity
by using a 1-d memoization table:
    ```
    for i = 1 to n
        for j = w[i] to W
            f[j] = max(f[j], v[i] + f[j-w[i]])
    ```