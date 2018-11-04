/* Topological sort on a Directed Acyclic Graph (DAG)

Lemma: A direct graph G is acyclic if and only if a
depth-first search of G yields no back edges.
Proof: If there’s back edge, a cycle is formed.

Pseudo code:
TOPO-SORT(G)
	call DFS(G) to compute v.f for each vertex v
	as each vertex is finished, insert it in the front of a list
	return the list



*/
