/* Finding Bridges and Articulation Points of a undirected graph
(tested)

Code at:
https://nhannguyen95.wordpress.com/2017/04/10/tim-khop-va-cau-tren-do-thi-vo-huong/

Note aside:
The key point is to understand how to compute low[u], we consider 2 lines 26 and 28.
Line 26 should be obvious to understand
Line 28, why isn’t it low[u] = min(low[u], low[v])

Answer: G is undirected graph (there is no forward and cross edge), so line 28 happen
only when (u, v) is a back edge.

It means that we visit u when we haven’t finished traversing the DFS tree of v yet,
meaning that low[v] hasn’t fully computed (low[v] is fully computed only when we finish
traverse DFS tree of v) => can’t use low[v] here, should be low[u] = min(low[u], num[v])


*/

