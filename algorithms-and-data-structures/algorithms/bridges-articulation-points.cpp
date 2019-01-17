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

Consider the back edge C, A as follows:

   |
   |
 _ A (num=4; low=1)
|  |
|  |   
|  B (num=5; low=?)
|  |
|  |
 --C (num=6; low=4, not 1 like in Tarjan)
 
In this problem, you will only want to minimize C's low with the num of the other
vertice (in this case A) of its back edge (think about it). In other words, the
low array here is defined with a slight difference with the one used in Tarjan problem:
- In Tarjan: low[u] = the lowest visit_time of a vertex to which u can reach (since
we don't care how u (directly/indirectly) reaches that vertex, as long as u can reach it).
- In this: low[u] = the lowest visit_time of a vertex to which u can reach DIRECTLY
via its back edges.

*/

