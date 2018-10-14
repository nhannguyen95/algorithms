/*  Bellman Ford's algorithm for finding shortest paths
from a single source.
(untested)

Bellman Ford algorithm allows negative-weight edge.

Bellman Ford returns a boolean value indicate if there
is a negative-weight cycle that is reachable from the
source. If there is no such cycle, it returns the
shortest paths and their weights.

Bellman Ford algorithm relaxes each edge |V| - 1 times.

Look at the code to know what the algorithm does.

To understand why the algorithm works, notice 2 properties:
- Shortest path is a single path, i.e. number of edge
  <= |V| - 1
- Path-relaxation property (shortest-paths.md)

After the |V| - 1 loop, if there's no negative-weight
cycle, we have d.v = 𝛿(s, v) <= 𝛿(s, u) + w(u, v)
= d.u + w(u, v) for all v in V and (u, v) in E.

So now we prove if there exists some edge (u, v) such
that d.u > d.v + w(u, v) => graph has negative-weight
cycle that reachable from the source.
(Proof: CLRS, 3rd, p.653, 654)

Analyzing running time is simple: O(VE)

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

