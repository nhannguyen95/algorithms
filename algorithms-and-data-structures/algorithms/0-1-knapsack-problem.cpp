/* 0-1 knapsack problem

Why we can't apply greedy algorithm to this problem?

Because when we make "the best" choice at some moment (based on
some knapsack criteria), we need to care about our next choice
for the subproblem (i.e. the current choice makes emerge
the constraint for the subproblem, that is the remaining weight
of the subproblem depends on the current choice). This isn't the
property of a greedy algorithm, in which the current choice neither
depend on nor affect choices of subproblems.

*/
