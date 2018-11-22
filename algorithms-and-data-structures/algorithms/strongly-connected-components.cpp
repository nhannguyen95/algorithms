/* Finding Strongly connected components of directed graph
(tested)

There are 2 algorithms to solve this problem:

---------------------------------------------

SOLUTION 1: Use 2 for loops

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

According to line 3 and 4: When we DFS on GT, we start
with the vertex u whose u.f is largest, this means we
start with the component C whose f(C) is largest.

Now if we look at the SCCs graph of G, C has no outgoing
edge:

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

By similar inference, we prove that C' has no outgoing edge
to the remaining component (other than the already disconnected
one C)

That's it!

---------------------------------------------

SOLUTION 2: Tarjan algorithm

Code: https://nhannguyen95.github.io/thuat-toan-tarjan-tim-thanh-phan-lien-thong-manh/

---------------------------------------------

Both solutions has time complexity O(V + E)

*/
