# Content

- [Algorithms and Data Structures](#algorithms-and-data-structures)
- [System Design](#system-design)
- [Computer Architecture](#computer-architecture)
- [Database](#database)
- [Networking](#networking)
  - [HTTP](#http)
- [Additional Learning](#additional-learning)
  - [Git](#git)
  - [Unix, Linux](#unix-linux)
  - [Design Patterns](#design-patterns)
  - [Clean Code](#clean-code)
  - [Web Dev](#web-dev)
- [Coding Practices](#coding-practices)
- [Other Useful Resources](#other-useful-resources)
- [Interview strategies](#interview-strategies)
- [Advices](#advices)
- [Miscellaneous](#miscellaneous)

# Algorithms and Data Structures

## Algorithms
  - [Bit manipulation](algorithms-and-data-structures/algorithms/bit-manipulation.md)
  - Recursion
  - Divide and Conquer
  - [Dynamic Programming](algorithms-and-data-structures/algorithms/dynamic-programming.md):
    - [Longest common subsequence (LCS)](https://nhannguyen95.wordpress.com/tag/lcs/)
    - [Longest increasing subsequence (LIC)](https://nhannguyen95.wordpress.com/2017/02/27/lis-day-con-tang-dai-nhat/)
    - [Edit distance](https://docs.google.com/document/d/1i8bT30KyQpTF7HLZnJkPpnjNmLu7Gj0VnoZ6gXuhRtI/edit?usp=sharing)
    - Optimal binary search tree
  - [Greedy](algorithms-and-data-structures/algorithms/greedy.md):
    - [Activity selection problem](algorithms-and-data-structures/algorithms/activity-selection.cpp)
    - [Huffman codes](algorithms-and-data-structures/algorithms/huffman-codes.cpp)
    - [Coin changing](algorithms-and-data-structures/algorithms/coin-changing.cpp)
  - [Sorting](algorithms-and-data-structures/algorithms/sorting.md):
    - [Bubble sort](algorithms-and-data-structures/algorithms/bubble-sort.cpp)
    - [Insertion sort](algorithms-and-data-structures/algorithms/insertion-sort.cpp)
    - [Selection sort](algorithms-and-data-structures/algorithms/selection-sort.cpp)
    - [Merge sort](algorithms-and-data-structures/algorithms/merge-sort.cpp)
    - [Quick sort](algorithms-and-data-structures/algorithms/quick-sort.cpp)
    - [Heap sort](algorithms-and-data-structures/algorithms/heap-sort.cpp)
    - [Counting sort](algorithms-and-data-structures/algorithms/counting-sort.cpp)
    - [Radix sort](what-to-prepare/algorithms/radix-sort.cpp)
    - Bucket sort
  - Searching
    - Binary search
  - [String](what-to-prepare/algorithms/string.md):
    - String matching:
      - Rabin-Karp(what-to-prepare/algorithms/rabin-karp.cpp)
      - 2D Rabin-Karp(what-to-prepare/algorithms/2d-rabin-karp.cpp)
      - Finite automata(what-to-prepare/algorithms/finite-automata.cpp)
      - KMP (Knuth-Morris-Pratt)(what-to-prepare/algorithms/kmp.cpp)
  - Probability
  - [Number Theory](what-to-prepare/algorithms/number-theory.md)
    - [Euclid's algorithm for finding Greatest Common Divisor (GCD)](what-to-prepare/algorithms/euclid-gcd.cpp)
    - [Extended Euclid's algorithm for finding Modular Multiplicative Inverse](what-to-prepare/algorithms/euclid-mmi.cpp)
    - [Primality testing](what-to-prepare/algorithms/primality-testing.cpp)
  - [Graph](algorithms-and-data-structures/algorithms/graph.md):
    - [BFS](what-to-prepare/algorithms/bfs.cpp)
    - [DFS](algorithms-and-data-structures/algorithms/dfs.cpp)
    - [Topological sort](what-to-prepare/algorithms/topo-sort.cpp)
    - [Strongly connected components](what-to-prepare/algorithms/strongly-connected-components.cpp)
    - [Minimum spanning tree (MST)](what-to-prepare/algorithms/mst.md)
      - [Kruskal's algorihtm](what-to-prepare/algorithms/mst-kruskal.cpp)
      - [Prim's algorithm](what-to-prepare/algorithms/mst-prim.cpp)
      - [Second-best minimum spanning tree](algorithms-and-data-structures/algorithms/2nd-mst.cpp)
    - [Shortest-paths](what-to-prepare/algorithms/shortest-paths.md)
      - [Single-source shortest-paths -  Bellman Ford](what-to-prepare/algorithms/bellman-ford.cpp)
      - [Single-source shortest-paths on DAG](what-to-prepare/algorithms/sssp-dag.cpp)
      - [Single-source shortest-paths -  Dijkstra](what-to-prepare/algorithms/dijkstra.cpp)
      - [All pairs shortest-paths - Floyd](what-to-prepare/algorithms/floyd.cpp)
      - All pairs shortest-paths - Johnson
      - [Transitive closure of a directed graph](what-to-prepare/algorithms/transitive-closure.cpp)
    - [Bridges and Articulation Points of a undirected graph](https://github.com/nhannguyen95/stuffs/blob/master/algorithms-and-data-structures/algorithms/bridges-articulation-points.cpp)
    - [Biconnected Components](what-to-prepare/algorithms/biconnected-components.cpp)
    - [Euler tour](what-to-prepare/algorithms/euler-tour.cpp)
    - [Graph coloring](algorithms-and-data-structures/algorithms/graph-coloring.cpp)
    - [Bipartite graph checking](algorithms-and-data-structures/algorithms/bipartite-checking.cpp)
  - Network flow
  - Medians and Order Statistics
    - [Randomized order statistic / Quickselect](what-to-prepare/algorithms/randomized-order-statistic.cpp)
    - [Order statistic] linear worst case running time
  - Computational Geometry:
    - Determine if vector _a_ is clockwise from vector _b_
    - Determine if we turn left or right at B if we go from AB then BC
    - Determine if 2 segments intersect
    - Sort a list of n points in polar angle increasing order
    - Determine if there exists any 3 points in a set of n points that are colinear
    - Determine if a given set of points forms a convex polygon
    - Determine if a point lies inside a simple polygon (not neccessary convex)
    - Find area of a simple polygon (not neccessary convex)
    - [Determining whether any pair of segments intersects (Shamos–Hoey algorithm)](/what-to-prepare/algorithms/pair-of-line-intersects.cpp)
    - Determining whether any pair of circles intersects
    - [Find all intersections of a set of segments (Bentley–Ottmann algorithm)](https://en.wikipedia.org/wiki/Bentley%E2%80%93Ottmann_algorithm)
    - Finding the convex hull:
      - [Graham's scan algorithm (nlogn)](what-to-prepare/algorithms/graham-scan.cpp)
      - [Javis's march (nh)](what-to-prepare/algorithms/javis-march.cpp)
    - Finding the farthest pair of points
    - Finding the closest pair of points (nlogn)
  - A*
  - Bloom Filter
  - K-way merge
  - [NP-Completeness](what-to-prepare/np-completeness.md)
  - NP-Completeness Approximation Algorithms

## Data structures
  - Array
  - Vector (Dynamic Array)
  - Strings
  - [Singly Linked List](what-to-prepare/data-structures/singly-linked-list.cpp)
  - [Doubly Linked List](what-to-prepare/data-structures/doubly-linked-list.cpp)
  - [Stack](what-to-prepare/data-structures/stack-array.cpp)
  - [Queue](what-to-prepare/data-structures/queue-array.cpp)
  - Priority Queue
  - Circular queue
  - [Deque](what-to-prepare/data-structures/deque-array.cpp)
  - [Heap](algorithms-and-data-structures/data-structures/heap.md) _Need to read this before reading any heap related stuffs_:
    - [Binary heap](what-to-prepare/data-structures/binary-heap.cpp)
    - [D-ary heap](what-to-prepare/data-structures/d-ary-heap.cpp)
    - [Young Tableau](what-to-prepare/data-structures/young-tableau.cpp)
    - Mergeable heap
  - [Binary Tree](what-to-prepare/data-structures/binary-tree.md)
  - [Binary Search Tree](what-to-prepare/data-structures/binary-search-tree.cpp)
  - Red-black Tree _Quite complicated to implement_
  - [Tree](what-to-prepare/data-structures/tree.md)
  - Radix Tree
  - [Hash Table](what-to-prepare/data-structures/hash-table.md)
  - Hash Map
  - Set
  - Tries
  - [Segment Tree (IT - Interval Tree)](algorithms-and-data-structures/data-structures/segment-tree.cpp)
  - [Binary Indexed Tree (BIT - Fenwick Tree)](algorithms-and-data-structures/data-structures/fenwick-tree.cpp)
  - Fibonacci Heap
  - [Disjoint-Set Forest](what-to-prepare/data-structures/disjoint-set-forest.cpp)
  - Blanced Search Tree:
    - AVL Tree
    - Splay Tree
    - Red Black Tree
    - B-Trees
  - [Treap](https://cp-algorithms.com/data_structures/treap.html) 

## Classic/Handy problems
  - [Maximum subarray problem](what-to-prepare/classic-problems/maximum-subarray.cpp)
  - Merge k sorted lists of total n elements into 1 sorted list in O(nlgk)
  - [Dutch national flag algorithm](classic-problems/dutch-national-flag.md): [2-ways.cpp](handy-algorithms/dnf-2-ways.cpp), [3-ways.cpp](https://github.com/nhannguyen95/interview-preparation/tree/master/handy-algorithms).
  - [Knapsack problem](what-to-prepare/classic-problems/knapsack-problem.cpp)
  - Edit distance problem
  - Optimal binary search tree
  - Interval-graph coloring problem
  - Dijkstra - Finding shortest paths from a single source
  - Chvátal's greedy set-covering heuristic
  - Least Common Ancestors (LCA)
  - Scheduling with profits and deadlines
  - [Exponential search](https://en.wikipedia.org/wiki/Exponential_search).
  - Split string: [code](handy-algorithms/split-string.cpp).

## Others
  - [Big O Notation](what-to-prepare/big-o-notation.md)
  - [Master Theorem](what-to-prepare/master-theorem.md)
  - [Amortized Analysis](what-to-prepare/amortized-analysis.md)
  - [Counting and Probability](what-to-prepare/counting-and-probability.md)
  - Operating System - Threads, Processes and Locks using Mutex, Semaphores
  - Scalability Issues, RPCs, Rate limiter
  - Concurrency
  - API Design
  - OOP Concepts
  - Databases - SQL, NoSQL, Writing simple Queries, Transactions, ACID
  - (Scaleable) Distributed Systems and Cloud Computing
  - Design Pattern
  - [RSA public-key cryptosystem](what-to-prepare/rsa.md)
  - [Mathematical Background](what-to-prepare/mathematical-background.md)

## Resources
  - Book: Cracking the coding interview - Gayle Laakmann McDowell.
  - Book: Introduction to Algorithms, 3rd - CLRS. (Chapter 5, 26, 27, 35; ~~Chapter 14, 17, 18, 19, 20, 28, 29, 30~~)
  - Book: Competitive Programming 3.
  - [Big O cheatsheet](http://bigocheatsheet.com/)
  - [E-Maxx Algorithms in English](https://cp-algorithms.com/)


# System Design

## Resources
- [Online course: HiredInTech's system design](https://www.hiredintech.com/classrooms/system-design).
- [Online course: Grokking the System Design Interview](https://www.educative.io/collection/5668639101419520/5649050225344512).
- [Book: Designing Data-intensive Applications - Martin Kleppmann](https://github.com/nhannguyen95/interview-preparation/tree/master/notes/system-design/designing-data-intensive-application)


# Computer Architecture

## Resources
- [Book: Computer Organization and Design MIPS Edition: The Hardware/Software Interface](https://www.amazon.com/Computer-Organization-Design-MIPS-Architecture/dp/0124077269/ref=sr_1_1?s=books&ie=UTF8&qid=1536553502&sr=1-1&keywords=Computer+Organization+and+Design+MIPS+Edition)


# Database


# Networking

## HTTP

- [HTTP: The definitive guide](additional-learning/http/http-the-definitive-guide)

# Additional Learning
  
## Git

- [Git Tutorial - Atlassian](additional-learning/git/git-tutorial-atlassian)
- [A successful Git branching model](https://nvie.com/posts/a-successful-git-branching-model/?fbclid=IwAR05eCUp9OO7BCwHbhfbbmuuEzlCJx5AxKuZUWPvWh6GsJFXv-JTM126K0U)

## Unix, [Linux](additional-learning/linux)

- [Introduction to Linux](additional-learning/linux/introduction-to-linux)

## Design Patterns

## Clean Code

## [Web Dev](additional-learning/webdev)

- [Django interview questions and answer](additional-learning/webdev/django.md)

# Coding Practices

## [Leetcode](https://github.com/nhannguyen95/interview-preparation/tree/master/leetcode)
  - Array.
  - Binary search.
  - Dynamic programming.
  - Heap.
  - Linked list.
  - Tree.
  - Database.
  - [Bit manipulation](https://github.com/nhannguyen95/interview-preparation/tree/master/leetcode/bit-manipulation).

## Geeksforgeeks
  - [Tree](https://github.com/nhannguyen95/interview-preparation/tree/master/geeksforgeeks/tree).
  - [Array](https://github.com/nhannguyen95/interview-preparation/tree/master/geeksforgeeks/array).

## [Inteviewbit](practices/interview-bit)

## [Data structure](https://github.com/nhannguyen95/interview-preparation/tree/master/data-structure-implementation)
  - Implement stack using array: [code](data-structure-implementation/stack-using-array.cpp).
  - Implement 3 stacks using array, fixed size: [code](data-structure-implementation/fixed-multistack-using-array.cpp).
  - Implement 3 stacks using array, flexible size: [code](data-structure-implementation/flexible-multistack-using-array.cpp).
  - Implement queue using linked list: [code](data-structure-implementation/queue-using-linked-list.cpp).
  - Stack with push, pop and min operate in O(1): [code](data-structure-implementation/stack-min-o1.cpp)
  - Set of stacks with popAt(stackIndex) method: [code](data-structure-implementation/set-of-stacks-with-popat.cpp)
  - Implement queue with 2 stacks: [code](data-structure-implementation/queue-with-2-stacks.cpp)
  - Implement stack with 2 queues


# Other Useful Resources

  - [Tech Dev Guide With Google](https://techdevguide.withgoogle.com/)
  - [The Complete Guide to Google Interview Preparation](http://blog.gainlo.co/index.php/category/google-interview-preparation/)
  - [Project Euler](https://projecteuler.net/)
  - [CareerCup](https://www.careercup.com/)
  - [Pramp](https://www.pramp.com/)
  - [InterviewCake](http://www.interviewcake.com/)
  - [Gainlo Blog](http://blog.gainlo.co/)
  - [Programming Interviews Exposed](https://www.amazon.in/Programming-Interviews-Exposed-Secrets-Landing/dp/8126539119)
  - [Elements of Programming Interview](https://www.amazon.in/Elements-Programming-Interviews-Adnan-Aziz/dp/9382359443/)
  - [Book: Clean Code - Robert C Martin](clean-code/)


# [Interview strategies](https://github.com/nhannguyen95/interview-preparation/tree/master/strategies)

- [System design](strategies/system-design.md).


# Advices

- _"The truth is that you are never going to feel fully prepared."_

- _"Majority candidates know what DFS/BFS is. What makes a difference is to have a deep understanding of those concepts."_

- _"You should be clear about the definition of those basic data structures/algorithms. Most people did a good job in this part, but not perfect. For instance, a lot of people are confused about dynamic programming and recursion."_

- _"Try to compare relevant data structures/algorithms and understand their pros and cons. A good example is BFS and DFS."_

- Which algorithm is better in what case?


# Miscellaneous

- [Vocabulary](miscellaneous/vocabulary.md)
- [C++ STD Containers](miscellaneous/c++-std-containers.md)

