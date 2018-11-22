/* Finding second best spanning tree in O(VE), the graph is represented in edge list

Observation: MST and MST2 only differ in 2 edges, we take away 1 edge in MST and edge
another edge to it to form MST2.

Algorithm: first find the MST like normal, then for each edge in the MST (V-1 edge),
we find the MST again but now exclusing that edge. The MST2 is the minimum tree among
those V-1 trees.

Code: https://nhannguyen95.wordpress.com/2017/04/15/thuat-toan-kruskal-tim-cay-khung-nho-nhi-minimum-spanning-tree/

*/
