## Theory

### Problem

We want to form a forest of K connected components (K subtrees) in
the least cost way where K is given beforehand in the problem
description.

### Solution

Modify the Kruskal algorithm:
- We run the algorithm as per normal.
- As soon as the number of connected components equals K, we
terminate the algorithm.

Modify the Prim algorithm:
- We run it as per normal to get the MST.
- The delete the K-1 longest edges of the MST.