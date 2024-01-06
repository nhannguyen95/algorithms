## Theory

### Problem

Given a graph and some fixed edges, these edges may form a non-tree
in the first place.

The task is to continue selecting the remaining edges (if necessary)
to make the graph connected in the least cost way.

The resulting spanning subgraph may not be a tree and even if it is
a tree, it may not be the MST.

### Solution

Modify the Kruskal algorithm:
- First we take into account all fixed edges and their costs.
- Then, continue running Kruskal algorithm on the remaining edges
until we have a spanning subgraph (or spanning tree).

Modify the Prim algorithm:
- We give higher priorities to the fixed edges so that we will
always take them and their costs.