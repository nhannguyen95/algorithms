Shortest paths algorithms typically rely on the property that a shortest path between 2 vertices contains other shortests path within it:

**Lemma**: Let p = <v<sub>0</sub>,..,v<sub>k</sub>> be the shortest path from v<sub>0</sub> to v<sub>k</sub>. For any i, j such that 0 <= i <= j <= k, let p<sub>ij</sub>=<v<sub>i</sub>,..,v<sub>j</sub>> be the subpath of p from v<sub>i</sub> to v<sub>j</sub>. Then p<sub>ij</sub> is the shortest path from v<sub>i</sub> to v<sub>j</sub>.

This optimal substructure is one of the key indicators that Dynamic Programming (Floyd) and Greedy (Dijkstra) method might apply.

---

**Negative-weight edges**

Let 𝛿(u, v) be the minimum weight of the path from u to v.

If there is no negative-weight *cycle* on the path from u to v, then 𝛿(u, v) is well defined (it's ok if some edge has negative weight).

If there's negative-weight *cycle* on the path from u to v, then 𝛿(u, v) is not well defined, 𝛿(u, v) = -∞.

If u is not reachable from v (or vice-versa), 𝛿(u, v) = ∞.

Dijsktra algorithm assumes that edge weights are non negative.

Other algorithms like Bellman Ford's allow negative-weight edges and produce correct answer as long as no negative-weight cycles are reachable from source. Typically, if there is such a negative-weight cycle, the algorithm can detect and reports its existence.

---

Simple path is a path that has no repeated vertices, thus no cycle.

A shortest path is a simple path.

Thus, **a shortest path contains at most V distince vertices, or V - 1 edges**.

---

**Relaxation**

Say we're finding the shortest-paths from the source vertex s.

For each vertex v, we maintain an atrribute v.d, the upper bound on the weight of a shortest path from s to v.

Initially, s.d = 0, v.d = ∞.

The process of *relax* an edge (u, v): testing whether we can improve the shortest path to v so far by going through u and, if so, update v.d and v.parent:

```
RELAX(u, v, w)
    if v.d > u.d + w(u, v)
        v.d = u.d + w(u, v)
        v.parent = u
```

Dijkstra and Bellman Ford algorithms differ in how many times they relax each edge and the order in which they relax edges. *Dijkstra and the shortest-paths algorithm for directed acyclic graphs relax each edge exactly once. The Bellman Ford algorithm relaxes each edge V - 1 times.*

Suppose we're finding the shortest path from source s to all remaining vertices. If there is a negative-weight cycle on some path from s to v such that u immediately preceeds v on the path, then v.d strictly decrease every time RELAX(u, v, w) is called. If there is no negative-weight cycle, then v.d never decreases once v.d = 𝛿(s, v).

---

**Properties of shortest paths and relaxation**

**Triangle inequality**:
𝛿(s, v) ≤ 𝛿(s, u) + w(u, v) ∀ (u, v) ∈ E.

**Upper-bound property**: v.d ≥ 𝛿(s, v) ∀ u ∈ V, and once v.d achieves the value 𝛿(s, v), it never changes.

**No-path property**: If there's no path from s to v, then v.d = 𝛿(s, v) = ∞.

**Convergence property**: If s ~> u -> v is the shortest path in G, when we call RELAX(u, v, w), if u.d = 𝛿(s, u) at any time prior to the call, then v.d = 𝛿(s, v) at all times after the call.

**Path-relaxation property** *(This can be derived from convergence property)*: If p = <v<sub>0</sub>,..,v<sub>k</sub>> is the shortest path from v<sub>0</sub> to v<sub>k</sub>, and we relax the edges of p in the order (v<sub>0</sub>, v<sub>1</sub>), (v<sub>1</sub>, v<sub>2</sub>), then v<sub>k</sub>.d = 𝛿(s, v). This holds true regardless of any other relaxation steps that occur, even if they are intermixed with relaxations of the edges of p.

**Predecessor-subgraph property**: After initializing single-source on the source vertex s, and executing a sequence of relaxation steps that produces v.d = 𝛿(s, v). Then the predecessor subgraph of s is the shortest-paths tree rooted at s.
