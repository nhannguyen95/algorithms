/* Depth-first search (DFS)

DFS works in both directed and undirected graphs.

Vertices during DFS have 3 states:
  - WHITE: undiscovered
  - GRAY: being discovered (its subtree is being traversed)
  - BLACK: finshish discovering (out of its subtree)

Each vertex u during DFS has 2 important attributes:
  - discovery time u.d: when the vertex is first discovered
  - finishing time u.f: when DFS finishes traversing u's subtree
  => u is WHITE during time < u.d
     u is GRAY during time in [u.d, u.f]
     u is BLACK during time > u.f

Time complexity:
(Time complexity is computed if use adjacency list)
  - Each vertex is visited once, so O(V)
  - Before finishing u, all edge of u is examined, so O(E)
    in total
  => O(V + E)

  In case of adjacency matrix, it takes O(V^2)

-----

Parenthesis theorem: In any DFS of a (directed or undirected)
graph G = (V, E), for any 2 vertices u and v, exactly 1 of the
following 3 conditions hold:
  - [u.d, u.f] and [v.d, v.f] are entirely disjoint, thus neither
    u nor v is a descendent of the other in the depth-first forest.
  - [u.d, u.f] is contained entirely within [v.d, v.f], thus u
    is descendant of v in a depth-first tree.
  - [v.d, v.f] is contained entirely within [u.d, u.f], thus v
    is descendant of u in a depth-first tree.

-----

White path theorem: In a depth-first forest of a (directed or
undirected) graph G = (V, e), vertex v is a descendant of
vertex u if and only if at the time u.d that the search discovers
u, there is a path from u to v consisting entirely of white
vertices.

-----

Classification of edges: (CLRS, 3rd edition, Figure 22.5 p.607
best illustrates this)
  - Tree edge (u, v): v is first discovered by exploring edge (u,v).
  - Back edge (u, v): this edge connects u to an ancestor v in a
    depth-first tree (DFT).
  - Forward edges (u, v) are thoses nontree edges connecting a
    vertex u to a descendent v in a DFT.
  - Cross edges: all other edges.

When we first explore an edge (u, v) (u = GRAY), the color of v tells us
something about the edge:
  - WHITE indicates a tree edge
  - GRAY indicates a back edge
  - BLACK indicates a F or C edge

Notice: Forward and Cross edges never occur in a depth-first
search of an undirected graph.

*/
