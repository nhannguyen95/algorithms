/*  Single-source shortest path on DAG
(Directed Acyclic Graph)

If the graph is acyclic, we can just apply Bellman Ford
to the vertices in Topo order:

DAG-SHORTEST-PATHS(G, source)
1. Topo sort on G, O(V + E) time
2. INIT-SINGLE-SOURCE(G, s)  // d, parent
3. for each vertex u, taking in topo order
4.   for each vertex v in G.adj[u] (the edge (u, v))
5.      relax(u, v, w)

Running time O(V + E):
    1. O(V + E)
    3-5. Each vertex and edge is refered to once
         => O(V + E)

Illustration: CLRS, 3rd, p.656, Figure 24.5

*/