/* Breadth-first search (BFS)

BFS works in both directed and undirected graphs.

Vertices during BFS have 3 states:
  - WHITE: undiscovered (have not been pushed into queue)
  - GRAY: being discovered (currently in queue)
  - BLACK: discovered (popped out of queue)

Time complexity:
(Time complexity is computed if use adjacency list)
  - Each vertex is discovered once => O(V)
  - All neighbors of a vertex is examined when it is about
    to be popped out => O(E) on all vertices
  => O(V + E)
  
  This takes O(V^2) if use adjacency matrix.

*/
