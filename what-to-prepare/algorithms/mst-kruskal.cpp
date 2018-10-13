/*  Kruskal's algorithm for finding Minimum Spanning Tree

This algorithm is tested by submitting into this site:
https://vn.spoj.com/problems/QBMST/

Property: A at each time is a forest.

The running time of the algorithm depends on the disjoint
-set data structure:

- Sort edges: O(ElgE)
- V makeSet, E findSet and unionSet
  => Amortized running time O((V + E)ɑ(V))
  We have V - 1 <= E <= V^2
        (G is connected)
     and ɑ(V) = O(lgV)
  So: O((V + E)ɑ(V))
    = O(ElgV)
    = O(ElgE)
    = O(ElgV^2)
    = O(2ElgV)
    = O(ElgV)

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
  int u;
  int v;
  int c;

  friend istream& operator>>(istream & is, Edge & edge) {
    is >> edge.u;
    is >> edge.v;
    is >> edge.c;
    return is;
  }
};

bool cmp(Edge & e1, Edge & e2) {
  return e1.c < e2.c;
}

const int N = 1e4 + 5;
int lab[N];

void makeSet(int u) {
  lab[u] = -1;
}

int findSet(int u) {
  return (lab[u] < 0) ? u : lab[u] = findSet(lab[u]);
}

void unionSet(int u, int v) {
  u = findSet(u);
  v = findSet(v);
  if (u == v) return;
  if (lab[u] > lab[v]) swap(u, v);
  lab[u] += lab[v];
  lab[v] = u;
}

int main() {
  int n, m;
  cin >> n >> m;  // |V|, |E|

  vector<Edge> edges;
  for(int i = 0; i < m; i++) {
    Edge e;
    cin >> e;
    edges.push_back(e);
  }

  // Sort edges in ascending order.
  sort(edges.begin(), edges.end(), cmp);

  // Init Disjoint-set Forest using Union by size
  // and Path Compression heuristics.
  for(int u = 1; u <= n; u++)
    makeSet(u);

  long long int mstWeight = 0;
  for(Edge & edge : edges) {
    int u = edge.u;
    int v = edge.v;
    // If (u, v) is light edge.
    if (findSet(u) != findSet(v)) {
      mstWeight += edge.c;
      unionSet(u, v);
    }
  }

  cout << mstWeight;

  return 0;
}