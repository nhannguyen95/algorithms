**Sparse graph**: E << V<sup>2</sup>

**Dense graph**: E ≈  V<sup>2</sup>

---

**Representations of graphs**

- **Adjacency lists**: method of choice for sparse graph, memory required Θ(E + V).

- **Adjacency matrix**: may preferred when the graph is dense or we want to tell quickly if there is an edge connecting two given vertices, memory required Θ(V<sup>2</sup>).

---

The **degree** of a vertex = **in-degree** + **out-degree**.

---

A **complete graph** is an undirected graph in which every pair of vertices is adjacent.

---

A **bipartite graph** is an undirected graph G = (V, E) in which V can be partitioned into two sets V1 and V2 such that (u, v) ∈ E implies either u ∈ V1 and v ∈ V2 or u ∈ V2 and v ∈ V1.
