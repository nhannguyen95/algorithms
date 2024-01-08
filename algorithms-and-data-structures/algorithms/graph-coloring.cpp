/* Graph Coloring

Given an undirected graph G = (V, E), a k-coloring of G is
a function c: V -> {0,1,..,k} such that c(u) # c(v) for
every edge (u, v) in E.

This is a NP-complete problem when k > 2.

Some properties:
- Any tree is 2-colorable
- The following are equivalent:
    - G is bipartie
    - G is 2-colorable
    - G has no cycles of odd length
    (https://nhannguyen95.wordpress.com/2016/08/10/kiem-tra-do-thi-2-phia/)

*/