/*  Bellman Ford's algorithm for finding shortest paths
from a single source (directed and undirected).
(untested)

Idea:
- Assume that the shortest path from src to des contains M edges,
according to the path-relaxation property, if we can just relax all
edges M times, eventually d.des = 𝛿(src, des):
  Relax all edges 1 time  => find the shortest path from src to all nodes,
    containing 1 edge.
  Relax all edges 2 times => find the shortest path from src to all nodes,
    containing 2 edges.
  ...
  Relax all edges M times => find the shortest path from src to all nodes,
    containing M edges.
- Since we don't know M in advance, we can just relax al edges |V| - 1 times
(because shortest path is a single path => number of edge <= |V| - 1).

INIT-SINGLE-SOURCE(G, s)
  for v in G.V
    v.d = (v == s) ? 0 : ∞

RELAX(u, v, w, temp_d)
  if u.d + w < temp_d[v]
    temp_d[v] = u.d + w

BELLMAN-FORD(G, w, s)
  INIT-SINGLE-SOURCE(G, s)

  // Relax all edges |V| - 1 times.
  for i = 1 to |G.V| - 1
    temp_d = copy(G.d)

    for edge=(u, v) in G.E
      RELAX(u, v, w, temp_d)

    G.d = temp_d

Bellman Ford algorithm relaxes each edge |V| - 1 times.

After the |V| - 1 loop, if there's no negative-weight
cycle, we have d.v = 𝛿(s, v) <= 𝛿(s, u) + w(u, v)
= d.u + w(u, v) for all v in V and (u, v) in E.

Improvement 1: We don't necessarily iterate up to |V| - 1 times. At the inner
for loop we can detect if RELAX makes a change in temp_d. If it doesn't change,
it won't never change in the next iterations. We can stop there.

Improvement 2: if we are not interested in relaxing the shortest path in
strictly number of edges increasing order (after each loop), we can remove
temp_d and perform the relaxation directly on G.d. But note that after x loops,
the values in G.d no longer indicates the shortest cost from src to all nodes
containing x edges (but maybe more).

Bellman Ford algorithm allows negative-weight edge.

In case graph has negative-weight cycle, Bellman Ford can detect its presence
by returning a boolean value indicate if there is a negative-weight cycle that
is reachable from the src. If there is no such cycle, it returns the shortest
paths and their weights.

So now we prove if there exists some edge (u, v) such
that d.v > d.u + w(u, v) => graph has negative-weight
cycle that reachable from the source.
(Proof: CLRS, 3rd, p.653, 654)

Analyzing running time is simple: O(VE)

Pseudo code:

BELLMAN-FORD(G, w, s)
  INIT-SINGLE-SOURCE(G, s)

  // Relax all edges |V| - 1 times.
  for i = 1 to |G.V| - 1
    for edge=(u, v) in G.E
      RELAX(u, v, w)
  
  // If we can still relax an edge, there must be a negative
  // cycle in our graph.
  for edge=(u, v) in G.E
    if v.d > u.d + w(u, v) (**)
      return FALSE  // Negative-weight cycle present that
                    // reachable from source vertex s.
  return TRUE  // No negative-weight cycle, and v.d = 𝛿(s, v)

From (**), we can know the vertices v such that there is
negative-weight cycle from the unique path from s to v.
To find all vertices on this cycle, we can DFS from one
of such those vertices, until we reach a back edge(u, v)
such that d.u + w(u, v) - d.v < 0, this is the weight of
the cycle. To print out the vertices on this cycle.

Highly recommend checking modified version of this algo:
https://tinyurl.com/y5s5ngn5

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define inf LONG_LONG_MAX
typedef long long int lli;

struct Edge {
  int u, v, w;
  friend istream& operator>>(
    istream& is,
    Edge & e
  ) {
    is >> e.u >> e.v >> e.w;
    return is;
  }
};

class Graph {
public:
  vector<Edge> edges;
  int n;  // |V|
  vector<lli> d;
  vector<int> parent;
  Graph(int n) : n(n) {
    d.assign(n, inf);
    parent.assign(n, -1);
  }
};

void relax(Graph & g, const Edge & e) {
  int u = e.u;
  int v = e.v;
  int w = e.w;
  auto & d = g.d;
  auto & parent = g.parent;
  if (d[u] != inf && d[v] > d[u] + w) {
    d[v] = d[u] + w;
    parent[v] = u;
  }
}

bool bellmanFord(Graph & g, int src) {
  // Init.
  g.d[src] = 0;

  // Relax all edges |V| - 1 times.
  for(int i = 0; i < g.n; i++)
    for(Edge & e : g.edges)
      relax(g, e);

  // Detect cycle.
  for(Edge & e : g.edges) {
    int u = e.u;
    int v = e.v;
    int w = e.w;
    if (g.d[v] > g.d[u] + w)
      return false;  // There's negative-weight cycle
                     // that reachable from source.
  }
  return true;
}

int main() {
  /* Input
  5 10
  0 1 6
  0 4 7
  1 2 5
  1 3 -4
  1 4 8
  2 1 -2
  3 0 2
  3 2 7
  4 2 -3
  4 3 9
  */
  int n, m;
  cin >> n >> m;

  Graph g(n);
  for(int i = 0; i < m; i++) {
    Edge edge;
    cin >> edge;
    g.edges.push_back(edge);
  }

  // Find shortest paths from source = 0.
  int src = 0;
  bool hasCycle = !bellmanFord(g, src);

  cout << "Negative-weight cycle or not? " << hasCycle << '\n';
  for(int u = 0; u < g.n; u++)
    cout << src << "->" << u << ' ' << g.d[u] << '\n';
  
  return 0;
}

