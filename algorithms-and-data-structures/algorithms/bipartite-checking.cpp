/* Checking Bipartie Graph using DFS or BFS

Time complexity: O(V + E)

- The following are equivalent:
    - G is bipartie
    - G is 2-colorable
    - G has no cycles of odd length
    
 => So to check if an undirected graph is bipartie or not, we check if
 it can be colored using 2 colors.

Algorithm: starting with some vertice u
- If u has no edge: color randomly for u.
- If u has edges, with each v in adj[u]:
  - If v is colored and color[v] = color[u] -> we can't color the graph with 2 colors
                                            -> the graph is not bipartie
  - If v is not colored, we color v such that color[v] != color[u].
 
*/

int color[N];  // Each vertice is colored 1 or 2
vector<int> vSet[2];

memset(color, 0, sizeof color);

// -------------------- DFS --------------------

// Returns true if the subtree rooted at u is Bipartie.
bool dfs(int u, int cl = 1) {
  color[u] = cl;
  vSet[2 - cl].push_back(u);
  
  bool isBipartie = true;
  for(int v : adj[u]) {
    if (!color[v] && !dfs(v, 3 - cl)) isBipartie = false;
    if (color[v] == cl) isBipartie = false;
  }
  
  return isBipartie;
}

// -------------------- BFS --------------------

// Returns true if the subtree rooted at u is Bipartie.
bool bfs(int src) {
  queue<int> q;
  
  q.push(src);
  color[src] = 1;
  vSet[2 - color[src]].push_back(src);
  
  bool isBipartie = true;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    
    for(int v : adj[u]) {
      if (color[v] == color[u]) isBipartie = false;
      else if (!color[v]) {
        q.push(v);
        color[v] = 3 - color[u];
        vSet[2 - color[v]].push_back(v);
      }
    }
  }
  
  return isBipartie;
}

// -------------------- MAIN --------------------

bool isBipartie = true;
for(int u = 0; u < N; u++) {
  if (color[u]) continue;
  if (!dfs(u)) isBipartie = false;
  // OR: if (!bfs(u)) isBipartie = false;
}

return isBipartie;

