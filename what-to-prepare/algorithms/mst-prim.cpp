/* Prim's algorithm for finding Minimum Spanning Tree

This algorithm is tested by submitting into this site:
https://vn.spoj.com/problems/QBMST/

Property: A at each time is a single tree.

The running time of this algorithm depends on how we
implement the min queue Q. Assume we implement it using
a complete binary tree.

The total running time is O(ElgE), you can figure it out.

This implementation stores edges in Q, can be improved
if we store vertices instead => O(ElgV).
(CLRS, 3rd, p.634, MST-Prim)

And it can be improved further using Fibonacci Heap.

*/

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

struct Edge { int u, w; };
bool operator > (const Edge & a, const Edge & b) {
  return a.w > b.w;
}

typedef vector< vector<Edge> > Graph;
typedef priority_queue<Edge, vector<Edge>, greater<Edge> > MinHeap;

long long int prim(const Graph & g) {
  // key[u]: minimum cost to connect A with u
  // Initially, key[u] = oo
  vector<int> key(g.size(), INT_MAX);

  // inMST[u]: u in A
  vector<bool> inMST(g.size(), false);

  // Initially, we add an arbitrary vertex into Q
  MinHeap Q;
  int src = 1;
  key[src] = 0;
  Q.push({src, 0});

  long long int mstWeight = 0;
  while(!Q.empty()) {
    int u = Q.top().u;
    int w = Q.top().w;
    Q.pop();

    if (inMST[u]) continue;

    // Add u to A
    inMST[u] = true;
    mstWeight += w;

    // Now that u in A, keys of vertices v that connect
    // to u will be affected, we should update them.
    for(auto & edge : g[u]) {
      int v = edge.u;
      int k = edge.w;
      if (!inMST[v] && key[v] > k) {
        key[v] = k;
        Q.push({v, key[v]});
        // We can memorize parent[v] = u here
        // to construct the mst later.
      }
    }
  }
  return mstWeight;
}

int main() {
  int n, m;
  cin >> n >> m;

  Graph g(n + 1);
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  
  cout << prim(g);

  return 0;
}
