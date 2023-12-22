## Definitions
An **Eulerian path** traverse each edge in the graph exactly once (each vertex can be visited multiple times).

An **Eulerian tour** (cycle/circuit) is a closed Eulerian path (starts and ends at the same vertex).

An **Eulerian graph** is a graph that has an Eulerian tour.

## Checking Eulerian properties

### Undirected graph

If G is UNDIRECTED:
- G has Euler path if:
  - Either every vertex has an even degree or exactly 2 vertices have an odd degree.
  - Connectivity requirement: all of its vertices with nonzero degree belong to a single connected component.
- G has Euler tour:
  - If it is connected and all vertices have even degrees.
  - Connectivity requirement: all of its vertices with nonzero degree belong to a single connected component.

### Directed graph

If G is DIRECTED
- G has an Euler tour if and only if:
  - In-degree(v) = out-degree(v) for every vertex.
  - Connectivity requirement: all of its vertices with nonzero degree belong to a single strongly connected component.
  > Proof: Without loss of generality, we can assume that there is
  > some vertex v such that in-degree(v) - out-degree(v) > 0, and v
  > is not the starting point of the Euler cycle. During traversing,
  > we necessarily visit v some times. After passing through v
  > ‘out-degree(v)’ times, we ran out of unused out-going edges, and
  > there are still some in-coming edges we need to use. However we
  > cannot use these edges since when we visit v one more time, we
  > can never escape from it to go back to the starting point of the cycle.
- G has Euler path if:
  - It has at most one vertex with in - out = 1, at most one vertex with out - in = 1, and all other vertices have equal in and out degrees.
  - Connectivity requirement: all of its vertices with nonzero degree belong to a single connected component of the underlying undirected graph.

## Finding Eulerian path

### Undirected graph

TODO.

### Directed graph

We use a modified version of Hierholzer's algorithm:
- Step 1: [Check if graph G has an Euler path](#checking-eulerian-properties).
- Step 2: Choose the Euler path's start vertex u:
  - If there's exist a vertex with out - in = 1, choose that vertex (greedily, this is the vertex with the highest number of outgoing edges thus its reachability to other parts of the graph is largest).
  - Otherwise, choose any vertex (with out > 0).
- Step 3: From the start vertex u, we perform the modified Hierholzer's algorithm:
  - From u, take any path through the graph. At each step, we marked the edge we take as already used. We stop until we are at some vertex v with no more unused outgoing edge.
  - The path from u to v might not contain all the edges of the graph yet, thus we need to keep exploring finding another path and merge it with the u to v path.
  - We do this by taking some vertex k in the path from u to v which still has unused outgoing edges (any vertex that satisfies this condition will do, highly depends on the implementation), add the explored edges from k to v (on the u to v path) to the output Eulerian path, the repeat the edge exploration for vertex k like we did for vertex u.
  - It is like we decompose the graph into edge-disjoint subgraphs.

In the implementations below, the vertex k will be chosen as the last satisfied vertex on the path from u to v.

```
// Recursive solution with DFS.
// Result = reverse(path).
void dfs(int u) {
    while(out[u] > 0) {
        int v = adj[u][--out[u]];
        dfs(v);
    }
    path.add(u);
}

// Iterative solution with stack.
// Result = reverse(path).
void hierholzer() {
    stack.push(u);
    while(!stack.empty()) {
        int u = stack.peek();
        if (out[u] > 0) {
            int v = adj[u][--out[u]];
            stack.push(v);
        } else {
            path.add(u);
            stack.pop();
        }
    }
}
```

## Finding Eulerian tour

### Undirected graph

Hierholzer's algorithm.

### Directed graph

Hierholzer's algorithm

