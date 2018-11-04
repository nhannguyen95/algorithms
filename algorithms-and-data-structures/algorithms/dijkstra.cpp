/*  Dijkstra's algorithm for finding single-source
    shortest path
(untested)

Dijkstra algorithm works with graphs whose edges weight
is non-negative.

Idea: the min queue Q maintains a set of vertices
to extract the vertex u whose d is minimum, then
relax all outgoing edge of v. All relaxed edges are
then push into Q for later update:

INIT-SINGLE-SOURCE(G, s)
  s.d = 0
  u.d = oo if u != s

DIJKSTRA(G, w, s)
  INIT-SINGLE-SOURCE(G, s)
  Q = G.V
  S = ø
  while Q != ø
    u = EXTRACT-MIN(Q)
    S += u
    for v in G.adj[u]
      RELAX(u, v, w)

The key to show the correctness of Disjktra's algorithm
is that when a vertex u is added to S (or is removed from
Q), we have u.d = 𝛿(s, u).

RELAX(u, v, w) is performed on u in S and v in V \ S.
Greedily the next vertex we add to S is some vertex
v in V \ S with minimum v.d.

There is some problem with the current pseudo code:
- There 2 information in the queue Q, u and its u.d
- To extract u whose u.d is minimum, we want the key is u.d
- To RELAX(u, v, w), we need to call DECREASE-KEY(v, new v.d)
on Q. But since the 'd' is the k, we cannot find v
efficiently (log|V|). Otherwise, if we let vertex index
'v' be the key, we cannot EXTRACT-MIN and DECREASE-KEY
efficiently (since the key for those 2 operations is 'd').

Regardless of the above analysis, this pseudo code is still
used in CLRS, 3rd book; which is something I haven't been
able to explain yet and that might be the reason why most
implementations on internet adopt an other implementation
like the one below.

The idea is that we use 'd' as the key for the min priority
queue Q, but instead of pushing all vertices in Q in the first
place and then cannot DECREASE-KEY(new v.d) efficiently
since the only way to alter u.d value is to iterate through
Q in O(|V|), we only push (v.d, v) into Q only when v
is relaxed.

When u is first popped out of the Q, just the same as before,
u is now in S and u.d = 𝛿(s, u). However, notice that there
are still some old version (u.d, u) still in Q. Fortunately
we can remove them by checking that previous value of u.d
in the Q with the current value of u[d]. If u.d > u[d],
that is an old version and needs to be removed.

Time complexity: O((V+E)logV) = O(ElogV)

Notice that if the weight of outgoing edge of the source
s is negative, the algorithm still correct.

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
