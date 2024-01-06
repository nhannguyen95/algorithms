## Theory

Finding Strongly connected components of directed graph (tested).

Strongly connected components (SCCs): if we pick any 2 vertices u
and v in a SCC, we can find a path from u to v and vice versa.

Note that if SCCs in a (directed) graph are replaced by larger
vertices, they form a DAG.

### Solution

There are 2 algorithms to solve this problem:
- Kosaraju's
- Tarjan's

Both utilize DFS and have the same time complexity O(V + E).

#### Kosaraju: use 2 for loops

G = (V, E)
GT = (V, invert(E))

SCC(G)
1. Call DFS(G) to compute u.f for each u
2. Compute GT
3. Call DFS(GT) in order of decreasing u.f
4. Output the vertices in each tree in the depth-first forest
   formed in (3) as a separate SCC

To understand all of this, firstly, it's easy to see that
SCCs form a DAG (Directed Acyclic Graph). Let's consider
2 SCCs C and C' in G such that:

C(has u) ------> C'(has v), (u, v) in E

Let denote f(C) = max{u.f | u in C}, the important key
to understand why this solution works is the following Lemma:

Let C and C' be distinct SCCs in directed graph G = (V, E).
Suppose that there is an edge (u, v) in E, where u in C
and v in C'. Then:
f(C) > f(C')

According to step 3 and 4: When we DFS on GT, we start
with the vertex u whose u.f is largest, this means we
start with the component C whose f(C) is largest.

Now if we look at the SCCs graph of G, C has no incoming edges:

 C ----> C'
 \
  -----> C''

So how we obtain C by DFS? We will work on the reversed
version of G, that is GT (this is safe since SCCs of G
is same as SCCs of GT):

C <----- C'
  <----- C''

After disjointing C (thus obtain the first SCC), we continue
searching second one starting with the component C' whose
f(C') is largest among the remaining component.

By similar inference, we prove that C' has no incoming edge
to the remaining component (other than the already disconnected
one C)

That's it!

#### Tarjan

Code: https://nhannguyen95.github.io/thuat-toan-tarjan-tim-thanh-phan-lien-thong-manh/

Similar to [Finding Bridges and Articulation Points of an undirected graph](/algorithms-and-data-structures/algorithms/bridges-articulation-points.md) solution, we
also maintain 2 numbers when running DFS:
- `num[u]`: same definition.
- `low[u]`: slightly different, it is now the lowest `num[v]` such
  that v is any vertex reachable from R (the depth-first tree rooted
  at u) and still being connected (see below).

On top of num and low, we also maintain a stack S to keep track of
vertices being explored by DFS calls. Now after finishing the DFS
for a vertex u, if `low[u]` = `num[u]`, we can conclude that u is
the root of an SCC and the members of that SCC is identified by
popping the current stack until we reach vertex u again. While
popping, we "disconnect" those vertices in the SCC from the whole
graph so they don't affect the calculation of other vertices' low.



