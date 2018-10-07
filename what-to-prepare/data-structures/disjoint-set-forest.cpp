/* Disjoint-set Forest (DSF)

3 supported operations for a disjoint-set data structure:
  - MAKE-SET(x)
  - UNION(x, y)
  - FIND-SET(x)

What makes DSF have an asymptotical running time are 2
"heuristics" - "union by rank" and "path compression".

The "union by rank heuristic" is implemented in CLRS,
3rd edition using the 'rank' property for each set.
However, I personally prefer using the 'number of
elements' in each set - "union by size".

By defining the 'lab' property for each element, we can
utilize it in "union by rank" and "path compression"
as follow:
  - Initially, x.lab = -1 for all x (MAKE-SET)
  - Consider a set S and x is an element in S
    x.lab = -|S|           if x = root(S)
    x.lab = parent(x) in S if x # root(S)
    We maintain these properties during union and find-set

------------ PSEUDO CODE ------------

MAKE-SET(x)
  x.lab = -1

UNION(x, y)
  x = FIND-SET(x)
  y = FIND-SET(y)
  if (x == y) return
  if (x.lab > y.lab) swap(x, y)
  x.lab += y.lab
  y.lab = x

FIND-SET(x)
                        // Path compression
  return (x.lab < 0) ? x : x.lab = FIND-SET(x.lab)

---------- TIME COMPLEXITY ----------

N = number of elements OR the total number of disjoint sets
from beginning.

MAKE-SET - O(1)

UNION - roughly O(lgN)

FIND-SET - roughly O(lgN)

Amortized analysis:

Suppose there is a sequence of M operations:
  - N MAKE-SET operations
  - (And therefore) At most (N - 1) UNION operations
  - Remaining is FIND-SET

Then the armotized time per operation is only O(ɑ(N)),
where ɑ(N) is the inverse Ackermann function.

In practice, ɑ(N) <= 5 => so nearly linear time for
each operation.

*/
