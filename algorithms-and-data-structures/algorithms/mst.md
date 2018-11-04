There are 2 greedy algorithms to solve MST: Kruskal's algorithm and Prim's algorithm.

Given undirected graph G = (V, E), the common pattern of 2 algorithms is from a set of edge `A` that is a subset of some minimum spanning tree, we pick a *safe edge* for `A` (i.e. the edge that doesn't form a cycle in `A`, and `A ⋃ (u, v)` is a subset of some MST), repeat until `A` = some MST:

```
A = ∅
while A does not form a spanning tree
  find an edge (u, v) that is safe for A
  A = A ⋃ (u, v)
return A
```

The tricky part is how we find for A a safe edge at each step?

---

We define a **cut** (S, V - S) of G is a partition of V (into 2 parts of vertices).

An edge (u, v) **crosses** the cut (S, V - S) if one of its endpoints in S and the other is V - S.

We say a cut **respects** a set A if no edge in A crosses the cut.

A **light edge** is the edge that crosses the cut and has the minimum weight.

Theorem: G = (V, E) is an undirected, connected graph with real-valued weight function w defined on E. Let A be a subset of E that is included in some MST of G, let (S, V - S) be any cut of G that respects A, and let (u, v) be a light edge crossing the cut. Then (u, v) is safe for A.

Proof is simple: Let say the set A is a subset of some MST T, (u, v) is the light edge of some cut (G, V - S) of A ((u, v) is not in T, otherwise the proof is obvious). We need to prove (u, v) is a safe edge for A, that is, `A ⋃ (u, v)` is a subset of some MST T'.

We can use *cut and paste technique* (mentioned in analyzing greedy algorithms): If we add (u, v) to T, then `T ⋃ (u, v)` will form a cycle. Because (u, v) crosses the cut, then in the (unique) path from u to v in T, there must be some edge (x, y) that also crosses the cut. Because (u, v) is a light edge, we have `w(u, v) <= w(x, y)`, if we replace (x, y) by (u, v), we will obtain a tree T' such that:

```
w(T') = w(T) - w(x, y) + w(u, v) <= w(T)
```

Since T is MST, `w(T') = w(T)`, thus T' also a MST. Finally we have `A ⋃ (u, v) ⊆ T'` and (u, v) is a safe edge for A since (u, v) crosses the cut of A.
