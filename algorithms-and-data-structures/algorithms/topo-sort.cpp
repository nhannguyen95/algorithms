/* Topological sort on a Directed Acyclic Graph (DAG)

Lemma: A direct graph G is acyclic if and only if a
depth-first search of G yields no back edges.
Proof: If there’s back edge, a cycle is formed.

Pseudo code:
TOPO-SORT(G)
  call DFS(G) to compute v.f for each vertex v
  as each vertex is finished, insert it in the front of a list
  return the list

Another algorithm for finding topological sort: Kahn's algorithm.
It looks like a "modified BFS":

TOPO-SORT:
enqueue vertices with 0 incoming degree into a min priority queue Q
while Q is not empty:
  u = Q.dequeue()
  put u in a topo sort list
  remove u and all outgoing edges from u
  if such removal causes vertex v to have 0 incoming edge
    enqueue v

We can use Kahn's algorithm to find all topo orders
(source code below)

OR we can use the idea of backtracking:
https://nhannguyen95.wordpress.com/2017/04/06/uva-124-following-orders/

*/

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <utility>
using namespace std;

void print1D(const vector<int> arr) {
  for(int x : arr) {
    cout << x << ' ';
  }
  cout << '\n';
}

void print2D(const vector<vector<int> > arr2D) {
  for(auto arr1D : arr2D) {
    print1D(arr1D);
  }
}
vector<int> concat(vector<int> & a, vector<int> & b) {
  vector<int> res(a);
  res.insert(res.end(), b.begin(), b.end());
  return res;
}

// res = a * b
vector<vector<int> > multiply(
  vector<vector<int> > & a,
  vector<vector<int> > & b) {
  if (a.size() == 0) return b;
  if (b.size() == 0) return a;

  vector<vector<int> > res;
  for(int i = 0; i < a.size(); i++) {
    for(int j = 0; j < b.size(); j++) {
      res.push_back(concat(a[i], b[j]));
    }
  }
  return res;
}

void generatePermutations(
  vector<int> & elements, int k,
  vector<vector<int> > & res) {
  if (k == elements.size()) {
    res.push_back(elements);
  }

  for(int i = k; i < elements.size(); i++) {
    swap(elements[k], elements[i]);

    generatePermutations(elements, k + 1, res);

    swap(elements[k], elements[i]);
  }
}

vector<vector<int> > generatePermutations(
  vector<int> elements) {
  vector<vector<int> > res;
  generatePermutations(elements, 0, res);
  return res;
}

class Graph {
private:
   int size;
   vector<vector<int> > edges;
   vector<int> incomingDegree;

public:
  Graph(int _size) {
    size = _size;
    edges.assign(size, vector<int>());
    incomingDegree.assign(size, 0);
  }

  void addEdge(int u, int v) {
    assert(0 <= u && u < size);
    assert(0 <= v && v < size);
    edges[u].push_back(v);
    incomingDegree[v]++;
  }

  vector<vector<int> > findAllTopoOrders() {
    vector<int> currLayer;
    for(int u = 0; u < size; u++) {
      if (incomingDegree[u] == 0) {
        currLayer.push_back(u);
      }
    }

    vector<vector<int> > topoOrders;
    auto temp = generatePermutations(currLayer);
    topoOrders = multiply(topoOrders, temp);

    while(currLayer.size()) {
      vector<int> nextLayer;
      for(int u : currLayer) {
        for(int v : edges[u]) {
          if (--incomingDegree[v] == 0) {
            nextLayer.push_back(v);
          }
        }
      }
      if (nextLayer.size()) {
        auto temp = generatePermutations(nextLayer);
        topoOrders = multiply(topoOrders, temp);
      }
      currLayer = nextLayer;
    }

    return topoOrders;
  }
};

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 3);

  auto orders = g.findAllTopoOrders();
  print2D(orders);
  cout << "End";
  return 0;
}
