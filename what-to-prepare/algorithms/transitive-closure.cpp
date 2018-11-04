/* Finding Transitive closure of a directed graph

Given directed graph G = (V, E), the transitive closure of
G is the graph G* = (V, E*), E = {(i, j): there is a path 
from i to j in G}.

We wish to construct the Adjency Matrix T of G*, that is:
T[i, j] = 1 if there is a path from i to j in G
T[i, j] = 0 otherwise

We can use Floyd algorithm to solve this problem by assigning
each edge in G with weight 1, then:
T[i, j] = C[i, j] < n
(Otherwise we get C[i, j] = oo).

By changing the definition of the DP formula, we can compute T
directly withouing computing C:
t_ij(k) = 1 if the intermediate vertices on the path from i
to j are drawn from k.

We develop the formula to compute t_ij(k) similarly to what we
did in Floyd algorithm:

Case 1: i --> k not in intermediate vertices --> j
t_ij(k) = t_ij(k - 1) (1)

Case 2: i --> k in intermediate vertices --> j
t_ij(k) = t_ik(k - 1) ∧ t_kj(k - 1) (2)

From (1) and (2):
t_ij(k) = t_ij(k - 1) ∨ (t_ik(k - 1) ∧ t_kj(k - 1))

Initialization is obvious:
T[i, j] = 1 if (i, j) in G
T[i, j] = 0 otherwise

Pseudo code:

TRANSITIVE-CLOSURE(G)
    n = |G.V|

    // Init
    for i = 1 to n
        for j = 1 to n
            if (i, j) in G
                T[i, j] = 1
            else
                T[i, j] = 0
    
    // Floyd
    for k = 1 to n
        for i = 1 to n
            for j = 1 to n
                T[i, j] = T[i, j] ∨ (T[i, k] ∧ T[k, j])

    return T

Follow up: Transitive closure of a dynamic graph
(CLRS, 3rd, Problem 25-1)


*/
