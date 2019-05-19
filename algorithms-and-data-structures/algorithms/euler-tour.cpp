/* Find Euler Tour in a directed graph

An Euler path visits each edge of the graph exactly once.

An Euler tour of a strongly connected, directed/undirected
graph G = (V, E) is a CYCLE that traverses each edge of G
exactly once (a vertex may be visited more than once).

A graph which has either an Euler path or an Euler tour is caled
an Eulerian graph.

If G is UNDIRECTED
- G has Euler tour if all vertices have even degrees.
- G has Euler path if all except for 2 vertices have even degrees.

If G is DIRECTED
- G has an Euler tour if and only if in-degree(v) = out-degree(v)
for each vertex v in V
Proof: Without loss of generality, we can assume that there is
some vertex v such that in-degree(v) - out-degree(v) > 0, and v
is not the starting point of the Euler cycle. During traversing,
we necessarily visit v some times. After passing through v
‘out-degree(v)’ times, we ran out of unused out-going edges, and
there are still some in-coming edges we need to use. However we
cannot use these edges since when we visit v one more time, we
can never escape from it to go back to the starting point of the cycle.
- G has Euler path if in-degree(v) = out-degree(v), at most
one vertex with in - out = 1 and at most one vertex with out - in = 1.

To find Euler tour: we can just arbitrarily walk any way that
we want so long as we don’t repeat an edge, we will necessarily
end up with a valid Euler tour.

*/
