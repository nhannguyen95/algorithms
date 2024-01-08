/* Finding Biconnected Components of undirected graph

Biconnected Component: thành phần song liên thông

A biconnected component of G is a maximal set of edges such that
any two edges in the set lie on a common simple cycle

Some properties:
An edge of G is a bridge if and only if it does not lie on any
simple cycle of G.
Biconnected components of G partition (partition can be a verb)
the nonbridge edges of G. (*)

From (*), to find biconnected component of G, we can use DFS in O(V+E)
to find bridges of E, then remove all bridges from G.

*/
