The running time of a dynamic programming algorithm is roughly equal the number of subproblems times the number of choice in solving each subproblems.

---

**Elements of DP**

**1. Optimal substructure**:
  - The optimal subproblems give the optimal problem.
  - Subproblems are independent.

To prove the **optimal substructure** of a problem: _cut-and-paste_ technique. Suppose that each of the subproblem solutions is not optimal and then deriving a contradiction.

**2. Overlapping subproblems:**
  - The space of subproblems must be _small_, so that it easier to have duplicated. Normally the total distinct subproblems is polynomial in the input size.

---

**row-major** order: The result table is filled row by row, from left to right, top to bottom.

---

Divide & conquer (D&C) and DP difference:
  - D&C divides the problem into _disjoint_ subproblems, solve the subproblems recursively, then combine their solutions to solve the original problem.
  - In contract, DP applies when subproblems share subproblems (i.e. when subproblems overlap), each subproblem is solved just once and the result is saved into a table for later use, therefore avoid the work of recomputing the answer every time it solves a subproblem.

---

It's easier to keep track of the solution during doing the dp than tracing back for the solution after computing dp. Trade off: memory complexity.