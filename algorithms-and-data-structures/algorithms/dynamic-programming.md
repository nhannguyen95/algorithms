## Problems
- 0-1 subset sum.
  - https://leetcode.com/problems/partition-equal-subset-sum/
- 0-1 subset sum ways.
  - https://leetcode.com/problems/target-sum/
- [0-1 knapsack](/algorithms-and-data-structures/algorithms/0-1-knapsack.md).
  - https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
- [0-b knapsack](https://blog.mitrichev.ch/2011/07/integral-bounded-knapsack-problem.html).
- [0-∞ knapsack](/algorithms-and-data-structures/algorithms/unbounded-knapsack.md).
- [0-∞ coin changing](/algorithms-and-data-structures/algorithms/unbounded-coin-changing.md).
  - https://leetcode.com/problems/coin-change/
- [0-∞ coin changing ways](/algorithms-and-data-structures/algorithms/unbounded-coin-changing-ways.md)
  - https://leetcode.com/problems/coin-change-ii/
- [Longest common subsequence (LCS) *](https://docs.google.com/document/d/10GzzyeoIHI21CbCfbZuIWZYFfyNUOMWjjlcuDmcvrdg/edit?usp=sharing)
- [Edit Distance *](/algorithms-and-data-structures/algorithms/edit-distance.cpp)
- [Partial Sum *](/algorithms-and-data-structures/algorithms/partial-sum.cpp)
- DP with Bitmask.

## Theory

### Elements of a DP problem

**1. Optimal substructure**:
  - The optimal subproblems give the optimal problem.
  - Subproblems are independent.

To prove the **optimal substructure** of a problem: _cut-and-paste_ technique. Suppose that each of the subproblem solutions is not optimal and then deriving a contradiction.

**2. Overlapping subproblems:**
  - The space of subproblems must be _small_, so that it's easier to have duplicated. Normally the total distinct subproblems is polynomial in the input size.


### Running time

The running time of a dynamic programming algorithm is roughly equal the number of subproblems times the number of choice in solving each subproblems (haven't applied memoization).

### Comparing with Divide & Conquer

Divide & conquer (D&C) and DP difference:
  - D&C divides the problem into _disjoint_ subproblems, solve the subproblems recursively, then combine their solutions to solve the original problem.
  - In contract, DP applies when subproblems share subproblems (i.e. when subproblems overlap), each subproblem is solved just once and the result is saved into a table for later use, therefore avoid the work of recomputing the answer every time it solves a subproblem.

### Tracing the solution

It's easier to keep track of the solution during doing the dp than tracing back for the solution after computing dp. Trade off: memory complexity.

### DP Parameters

#### Common DP Parameters

```
1.
Parameter: Index i in an array.
Transition: Extend subarray [0..i] (or [i..n-1]), process i, take item i or not, etc.
Example: 1D Max Sum, LIS, part of 0-1 Knapsack, TSP, etc.

2.
Parameter: Indices (i, j) in 2 arrays.
Transition: Extend i, j or both, etc.
Example: Edit Distance, LCS, etc.

3.
Parameter: Subarray (i, j) of an array.
Transition: Split (i, j) into (i, k) + (k + 1, j) or (i, i + k) + (i + k + 1, j), etc.
Example: Matrix Chain Multiplication, etc.

4.
Parameter: A vertex (position) in a (usually implicit) DAG.
Transition: Process the neighbors of this vertex, etc.
Example: Shortest/Longest/Counting Paths in/on DAG, etc.

5.
Parameter: Knapsack-style parameter.
Transition: Decrease (or increase) current value until zero/threshold, etc.
Example: 0-1 Knapsack, Subset Sum, Coin Change variants, etc.
Note: this parameter is not DP friendly if its range is high.

6.
Parameter: Small set (usually using bitmask technique).
Transition: Flag one (or more) item(s) in the set to on/off, etc.
Example: DP-TSP, DP with bitmask, etc.
```

Harder DP problems usually combine two or more parameters to represent distinct states.

#### Negative Parameters with Offset

This issue can be dealt easily by using offset technique to make all indices become non negative again.
