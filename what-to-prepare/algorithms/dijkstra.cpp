/*  Dijkstra's algorithm for finding single-source
    shortest path
(untested)

Dijkstra algorithm works with graphs whose edges weight
is non-negative.

Idea: the min queue Q maintains a set of vertices
to extract the vertex u whose d is minimum, then
relax all outgoing edge of v. All relaxed edges are
then push into Q for later update.

Illustration: CLRS, 3rd, p.659, Figure 24.6
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define inf LONG_LONG_MAX

typedef long long int lli;
typedef pair<int, int> Edge;
typedef pair<lli, int> Relaxable;
typedef priority_queue<
  Relaxable,
  vector<Relaxable>,
  greater<Relaxable>
  > MinHeap;


class Graph {
public:
  int n;  // u = 1..(n-1)
  vector< vector<Edge> > adj;
  vector<lli> d;
  vector<int> parent;
  Graph(int n) : n(n) {
    adj.assign(n, vector<Edge>());
    d.assign(n, inf);
    parent.assign(n, -1);
  }
};

void relax(
  Graph & g, int u, int v, int w, MinHeap & Q) {
  auto & d = g.d;
  auto & parent = g.parent;
  if (d[v] > d[u] + w) {
    d[v] = d[u] + w;
    parent[v] = u;
    Q.push(make_pair(d[v], v));
  }

}

void dijkstra(Graph & g, int src) {
  auto & d = g.d;
  
  // Init single-source.
  d[src] = 0;
  MinHeap Q;
  Q.push(make_pair(d[src], src));

  // Relaxing..
  while(!Q.empty()) {
    lli du = Q.top().first;
    int u = Q.top().second;
    Q.pop();

    // Remove old versions.
    if (du > d[u]) continue;

    // Relax all outgoing edge of u (u, v).
    for(auto & e : g.adj[u]) {
      int v = e.first;
      int w = e.second;
      relax(g, u, v, w, Q);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  Graph g(n + 1);
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g.adj[u].push_back(make_pair(v, w));
    g.adj[v].push_back(make_pair(u, w));
  }

  // Dijkstra with source = 1
  dijkstra(g, 1);

  if (g.d[n] == inf) cout << -1;
  else { /* Print path */ }

  return 0;
}
