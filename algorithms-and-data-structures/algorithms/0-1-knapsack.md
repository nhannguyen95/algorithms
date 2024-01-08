## Problem
Given n items, ith item is worth v[i] dollars and weights
w[i] pounds. There's a snapsack that has capacity W pounds. Which
items should be taken in the snapsack to maximize the total money?

In this problem, we assume that the weight is integer. If it's
decimal number, we can convert them to integer by multiplication.

0-1 knapsack: for each item, either we pick it or not.

## Solution

Solution: DP
- f[i][j]: the maximum money that can be obtained by considering
the first i items and putting them into a knapsack with capacity j.
- Optimal structure property: When we put i-th item into the
knapsack, the problem is reduced to picking (n - 1) remaining items
(0..i-1) into W - w[i] capacity knapsack.
    ```
    for i = 1 to n
        for j = 1 to W
            if w[i] > j
                f[i][j] = f[i-1][j]
            else 
                f[i][j] = max(f[i-1][j], v[i] + f[i-1][j-w[i]])
    ```
- f[i] only depends on f[i-1], so we can optimize space complexity
by using a 1-d memoization table:
    ```
    for i = 1 to n
        // Traverse from bigger to small, since f[small] is the
        // old/previous value.
        for j = W downto w[i]
            f[j] = max(f[j], v[i] + f[j-w[i]])
    ```

Why can't we apply greedy algorithm to this problem?
- Because when we make "the best" choice at some moment (based on
some knapsack criteria), we need to care about our next choice
for the subproblem (i.e. the current choice creates the constraint
for the subproblem, that is the remaining weight of the subproblem
depends on the current choice). This isn't the property of a greedy
algorithm, in which the current choice neither depend on nor affect
choices of subproblems.
