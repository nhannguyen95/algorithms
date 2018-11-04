For many optimization problems, DP is overkill.

We can use **greedy algorithm**: always makes the choice that looks best at the moment (no need to examine/consider all choices and then decide which one is best like DP).

Greedy algorithms do not always yield optimal solution, but for many problems they do.

Greedy algorithms typically have top-down design: make a choice then solve subproblems, rather than bottom-up - solve subproblem then pick a choice. This is different from DP: a DP algorithm typically proceeds bottom-up. And regardless of implementing a DP algorithm either in top-down or bottom-up fashion, we still have to solve subproblem before making a choice.

---

**Strategy for developing a greedy algorithm:**

- Show that if we make the greedy choice, then only **1** subproblem remain.
- Prove that it is always safe to make the greedy choice (i.e. there is always an optimal solution to the original problem that makes/
  "contains" the greedy choice).
- Develop a recursive algorithm that implements the greedy strategy.
- Convert the recursive algorithm to an iterative algorithm.

---

_Beneath every greedy algorithm, there is almost always a more cumbersome DP solution._

---

**Elements of a Greedy algorithm**:
- **Greedy-choice property**: The choice made by a greedy algorithm may depend on choices so far, _but it cannot depend on any future choices or on the solutions to subproblems_ (i.e. we make the choice that looks best atm, _without considering results from subproblems._). We must prove that a greedy choice at each step yields a globally optimal solution (this means in order to prove greedy-choice property, we prove the greedy choice is a part of a/some optimal solution; typically, we start by an optimal solution, and we prove that it is still an optimal solution if we replace the greedy choice into the solution).
- **Optimal structure**: an optimal solution to the problem contains within it optimal solutions to subproblems (also proved by "cut-and-paste" technique).
