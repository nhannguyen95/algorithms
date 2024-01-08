## Theory

Finding Bridges and Articulation Points of an undirected graph
(tested).

In an undirected graph G:
- An Articulation Point is a vertex whose removal disconnects G.
- A Bridge is an edge whose removal diconnects G.

### Solution

Maintaining 2 numbers when running DFS:
- `num[u]`: iteration counter (starting from 0) when the vertex u is
  visited for the first time.
- `low[u]`: the lowest `num[v]` such that if R is the set of
  vertices in the depth-first tree rooted at u (including u), then:
  - v is in R (v's state is WHITE while discovering u), OR:
  - v is not in R but is reachable by a back edge from a vertex in
  R (v's state is GRAY while discovering u).

  This means `low[u]` can only be made smaller if DFS encounters a
  back edge that connects a vertex in R to another vertex v not in R
  that has lower `num[v]`.

  Note that we do not update `low[u]` if (u, v) is a bidirectional
  edge.

Determining articulation points and bridges from num and low:
- Consider (u, v) edge: if `low[v]` >= `num[u]` then u is an
  articulation point. This is because there is no back edge from a
  vertex in the depth-first tree rooted at v can reach another
  vertex w with a lower `num[w]` than `num[u]`.

  **Special case**: the root of the depth-first tree (the vertex
  chosen as the start of DFS call) is an articulation point only if
  it has more than one children in its depth-first tree (a trivial
  case that is not detected by this algorithm).
- Consider (u, v) edge: when `low[v]` > `num[u]`, then (u, v) is a
  bridge

### Source code

https://nhannguyen95.wordpress.com/2017/04/10/tim-khop-va-cau-tren-do-thi-vo-huong/

Note aside:
The key point is to understand how to compute low[u], we consider 2 lines 26 and 28.
Line 26 should be obvious to understand
Line 28, why isn’t it low[u] = min(low[u], low[v])

Answer: G is undirected graph (there is no forward and cross edge), so line 28 happen
only when (u, v) is a back edge.

Consider the back edge C, A as follows:

```
   |
   |
 _ A (num=4; low=1)
|  |
|  |   
|  B (num=5; low=?)
|  |
|  |
 --C (num=6; low=4, not 1 like in Tarjan)
```
 
In this problem, you will only want to minimize C's low with the num of the other
vertice (in this case A) of its back edge (think about it). In other words, the
low array here is defined slightly differently from the one used in Tarjan problem:
- In Tarjan: low[u] = the lowest visit_time of a vertex to which u can reach (since
we don't care how u (directly/indirectly) reaches that vertex, as long as u can reach it).
- In this: low[u] = the lowest visit_time of a vertex to which u can reach DIRECTLY
via its back edges. Or, more correctly: low[u] stores the lowest num reachable from
the current DFS spanning subtree of u.

