## Problems
- [Minimum Swaps to Sort](https://practice.geeksforgeeks.org/problems/minimum-swaps/1)

## Theory

### Graph Types

**Sparse graph**: E << V<sup>2</sup>

**Dense graph**: E ≈  V<sup>2</sup>

A **complete graph** is an undirected graph in which every pair of vertices is adjacent.

A **bipartite graph** is an undirected graph G = (V, E) in which V can be partitioned into two sets V1 and V2 such that (u, v) ∈ E implies either u ∈ V1 and v ∈ V2 or u ∈ V2 and v ∈ V1.

A **biconnected graph**: if any vertex were to be removed, the graph will remain connected (no articulation point).

### Graph Representation
**Representations of graphs**:
- **Adjacency lists**: method of choice for sparse graph, memory required Θ(E + V).
- **Adjacency matrix**: may preferred when the graph is dense or we want to tell quickly if there is an edge connecting two given vertices, memory required Θ(V<sup>2</sup>).
- **Edge list**.

### Other Terms

The **degree** of a vertex = **in-degree** + **out-degree**.

The **diameter of a graph** is the maximum shortest path distance between any pair of vertices of that graph.
