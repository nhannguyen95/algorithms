# Content

- [Algorithms and Data Structures](#algorithms-and-data-structures)
- [System Design](#system-design)
- [Computer Architecture](#computer-architecture)
- [Database](#database)
- [Networking](#networking)
  - [HTTP](#http)
  - [TCP/IP](#tcpip)
- [Additional Learning](#additional-learning)
  - [Git](#git)
  - [Unix, Linux](#unix-linux)
  - [Design Patterns](#design-patterns)
  - [Clean Code](#clean-code)
  - [Web Dev](#web-dev)
  - [Web Security](#web-security)
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
    - [Longest common subsequence (LCS)](https://docs.google.com/document/d/10GzzyeoIHI21CbCfbZuIWZYFfyNUOMWjjlcuDmcvrdg/edit?usp=sharing)
    - [Longest increasing subsequence (LIC)](https://nhannguyen95.wordpress.com/2017/02/27/lis-day-con-tang-dai-nhat/)
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
    - [Radix sort](algorithms-and-data-structures/algorithms/radix-sort.cpp)
    - Bucket sort
  - Searching
    - Binary search
  - [String](algorithms-and-data-structures/algorithms/string.md):
    - String matching:
      - [Rabin-Karp](algorithms-and-data-structures/algorithms/rabin-karp.cpp)
      - [2D Rabin-Karp](algorithms-and-data-structures/algorithms/2d-rabin-karp.cpp)
      - [Finite automata](algorithms-and-data-structures/algorithms/finite-automata.cpp)
      - [KMP (Knuth-Morris-Pratt)](algorithms-and-data-structures/algorithms/kmp.cpp)
      - String matching with gap characters.
    - [Edit Distance](algorithms-and-data-structures/algorithms/edit-distance.cpp)
  - Probability
  - Math:
    - [Mathematical Background](algorithms-and-data-structures/mathematical-background.md)
    - [Counting and Probability](algorithms-and-data-structures/counting-and-probability.md)
    - [Number theory](algorithms-and-data-structures/algorithms/number-theory.md)
    - [Factorization in O(sqrt(N))](https://sites.google.com/site/indy256/algo/factorization)
    - [Sieve Eratosthenes](algorithms-and-data-structures/algorithms/sieve-eratosthenes.cpp)
    - [Euclid's algorithm for finding Greatest Common Divisor (GCD)](algorithms-and-data-structures/algorithms/euclid-gcd.cpp)
    - [Extended Euclid's algorithm for finding Modular Multiplicative Inverse](algorithms-and-data-structures/algorithms/euclid-mmi.cpp)
    - [Primality testing](algorithms-and-data-structures/algorithms/primality-testing.cpp)
    - [The Tortoise and Hare algorithm](https://nhannguyen95.github.io/the-tortoise-and-hare-algorithm/)
  - [Graph](algorithms-and-data-structures/algorithms/graph.md):
    - [BFS](algorithms-and-data-structures/algorithms/bfs.cpp)
    - [DFS](algorithms-and-data-structures/algorithms/dfs.cpp)
    - [Topological sort](algorithms-and-data-structures/algorithms/topo-sort.cpp)
    - [Strongly connected components](algorithms-and-data-structures/algorithms/strongly-connected-components.cpp)
    - [Minimum spanning tree (MST)](algorithms-and-data-structures/algorithms/mst.md)
      - [Kruskal's algorihtm](algorithms-and-data-structures/algorithms/mst-kruskal.cpp)
      - [Prim's algorithm](algorithms-and-data-structures/algorithms/mst-prim.cpp)
      - [Second-best minimum spanning tree](algorithms-and-data-structures/algorithms/2nd-mst.cpp)
    - [Shortest-paths](algorithms-and-data-structures/algorithms/shortest-paths.md)
      - [Single-source shortest-paths - Bellman Ford](algorithms-and-data-structures/algorithms/bellman-ford.cpp)
      - [Single-source shortest-paths on DAG](algorithms-and-data-structures/algorithms/sssp-dag.cpp)
      - [Single-source shortest-paths - Dijkstra](algorithms-and-data-structures/algorithms/dijkstra.cpp)
      - [All pairs shortest-paths - Floyd](algorithms-and-data-structures/algorithms/floyd.cpp)
      - All pairs shortest-paths - Johnson
      - [Transitive closure of a directed graph](algorithms-and-data-structures/algorithms/transitive-closure.cpp)
    - [Bridges and Articulation Points of a undirected graph](https://github.com/nhannguyen95/stuffs/blob/master/algorithms-and-data-structures/algorithms/bridges-articulation-points.cpp)
    - [Biconnected Components](algorithms-and-data-structures/algorithms/biconnected-components.cpp)
    - [Euler tour](algorithms-and-data-structures/algorithms/euler-tour.cpp)
    - [Graph coloring](algorithms-and-data-structures/algorithms/graph-coloring.cpp)
    - [Bipartite graph checking](algorithms-and-data-structures/algorithms/bipartite-checking.cpp)
  - Network flow
  - Medians and Order Statistics
    - [Randomized order statistic / Quickselect](algorithms-and-data-structures/algorithms/randomized-order-statistic.cpp)
      > There is a linear worst case running time for this problem.
  - [Computational Geometry](algorithms-and-data-structures/algorithms/computational-geometry.cpp):
    - Determine if there exists any 3 points in a set of n points that are colinear
    - Determine if a point lies inside a simple polygon (not neccessary convex)
    - Find area of a simple polygon (not neccessary convex)
    - [Determining whether any pair of segments intersects (Shamos–Hoey algorithm)](algorithms-and-data-structures/algorithms/pair-of-line-intersects.cpp)
    - Determining whether any pair of circles intersects
    - [Find all intersections of a set of segments (Bentley–Ottmann algorithm)](https://en.wikipedia.org/wiki/Bentley%E2%80%93Ottmann_algorithm)
    - Finding the convex hull:
      - [Graham's scan algorithm (nlogn)](algorithms-and-data-structures/algorithms/graham-scan.cpp)
      - [Javis's march (nh)](algorithms-and-data-structures/algorithms/jarvis-march.cpp)
    - Finding the farthest pair of points
    - Finding the closest pair of points (nlogn)
  - A*
  - Bloom Filter
  - K-way merge
  - [NP-Completeness](algorithms-and-data-structures/np-completeness.md)
  - NP-Completeness Approximation Algorithms
  - [Window Sliding](algorithms-and-data-structures/algorithms/window-sliding.cpp)
  - [Algebraic Expressions](algorithms-and-data-structures/algorithms/algebraic-expressions.cpp)
  - Matrix Power (Nhân ma trận)
  - Lowest Common Ancestor
  - [Partial Sum](algorithms-and-data-structures/algorithms/partial-sum.cpp)

## Data structures
  - Array
  - Vector (Dynamic Array)
  - Linked list:
    - [Singly Linked List](algorithms-and-data-structures/data-structures/singly-linked-list.cpp)
    - [Doubly Linked List](algorithms-and-data-structures/data-structures/doubly-linked-list.cpp)
  - [Hash Table](algorithms-and-data-structures/data-structures/hash-table.md)
  - [Heap](algorithms-and-data-structures/data-structures/heap.md) _Need to read this before reading any heap related stuffs_:
    - [Binary heap](algorithms-and-data-structures/data-structures/binary-heap.cpp)
    - [D-ary heap](algorithms-and-data-structures/data-structures/d-ary-heap.cpp)
    - [Young Tableau](algorithms-and-data-structures/data-structures/young-tableau.cpp)
    - [Mergeable heap](https://sites.google.com/site/indy256/algo/mergeable_heap)
    - Fibonacci Heap
  - String:
    - [Trie](algorithms-and-data-structures/data-structures/trie.cpp)
    - [Suffix Tree](algorithms-and-data-structures/data-structures/suffix-tree.md)
    - [Suffix Array](algorithms-and-data-structures/data-structures/suffix-array.cpp)
  - [Stack](algorithms-and-data-structures/data-structures/stack-array.cpp)
  - [Queue](algorithms-and-data-structures/data-structures/queue-array.cpp):
    - Priority Queue
    - Circular queue
  - [Deque](algorithms-and-data-structures/data-structures/deque-array.cpp)
  - [Tree](algorithms-and-data-structures/data-structures/tree.md):
    - [Binary Tree](algorithms-and-data-structures/data-structures/binary-tree.md)
    - [Binary Search Tree](algorithms-and-data-structures/data-structures/binary-search-tree.cpp)
    - [Segment Tree (IT - Interval Tree)](algorithms-and-data-structures/data-structures/segment-tree.cpp)
    - [Binary Indexed Tree (BIT - Fenwick Tree)](algorithms-and-data-structures/data-structures/fenwick-tree.cpp)
    - Radix Tree
    - Balanced Search Tree:
      - AVL Tree
      - Splay Tree
      - Red Black Tree
      - B-Trees
  - Set/Map
  - [Disjoint-Set Forest](algorithms-and-data-structures/data-structures/disjoint-set-forest.cpp)
  - [Treap](https://cp-algorithms.com/data_structures/treap.html) 

## Classic/Handy problems (compiled from [GFGs](https://www.geeksforgeeks.org/must-coding-questions-company-wise/))
  - Array
    - [Maximum subarray problem](algorithms-and-data-structures/classic-problems/maximum-subarray.cpp)
    - [Missing number in array](https://leetcode.com/problems/missing-number/)
    - [Dutch national flag algorithm](algorithms-and-data-structures/classic-problems/dutch-national-flag.md): [2-ways.cpp](algorithms-and-data-structures/handy-algorithms/dnf-2-ways.cpp), [3-ways.cpp](algorithms-and-data-structures/handy-algorithms/dnf-3-ways.cpp).
    
  - Merge k sorted lists of total n elements into 1 sorted list in O(nlgk)
  - [Knapsack problem](algorithms-and-data-structures/classic-problems/knapsack-problem.cpp)
  - Optimal binary search tree
  - Interval-graph coloring problem
  - Dijkstra - Finding shortest paths from a single source
  - Chvátal's greedy set-covering heuristic
  - Least Common Ancestors (LCA)
  - Scheduling with profits and deadlines
  - [Exponential search](https://en.wikipedia.org/wiki/Exponential_search).
  - Split string: [code](algorithms-and-data-structures/handy-algorithms/split-string.cpp).
  - [Morris Inorder Tree Traversal](https://nhannguyen95.github.io/morris-inorder-tree-traversal/)

## Others
  - [Big O Notation](algorithms-and-data-structures/big-o-notation.md)
  - [Master Theorem](algorithms-and-data-structures/master-theorem.md)
  - [Amortized Analysis](algorithms-and-data-structures/amortized-analysis.md)
  - Operating System - Threads, Processes and Locks using Mutex, Semaphores
  - Scalability Issues, RPCs, Rate limiter
  - Concurrency
  - API Design
  - OOP Concepts
  - Databases - SQL, NoSQL, Writing simple Queries, Transactions, ACID
  - (Scaleable) Distributed Systems and Cloud Computing
  - Design Pattern
  - [RSA public-key cryptosystem](algorithms-and-data-structures/rsa.md)

## Resources
  - Book: Cracking the coding interview - Gayle Laakmann McDowell.
  - Book: Introduction to Algorithms, 3rd - CLRS. (Chapter 5, 26, 27, 35; ~~Chapter 14, 17, 18, 19, 20, 28, 29, 30~~)
  - Book: Competitive Programming 3.
  - [Algorithms and Data Structures](https://sites.google.com/site/indy256/)
  - [Big O cheatsheet](http://bigocheatsheet.com/)
  - [E-Maxx Algorithms in English](https://cp-algorithms.com/)


# [System Design](system-design)

## Resources
- [System design primer](https://github.com/donnemartin/system-design-primer): should read as notes.
- [Online course: HiredInTech's system design](https://www.hiredintech.com/classrooms/system-design).
- [Online course: Grokking the System Design Interview](https://www.educative.io/collection/5668639101419520/5649050225344512).
- [Book: Designing Data-intensive Applications - Martin Kleppmann](system-design/designing-data-intensive-application)


# [Computer Architecture](computer-architecture)

- [Cache](computer-architecture/cache)

## Resources
- [Book: Computer Organization and Design MIPS Edition: The Hardware/Software Interface](https://www.amazon.com/Computer-Organization-Design-MIPS-Architecture/dp/0124077269/ref=sr_1_1?s=books&ie=UTF8&qid=1536553502&sr=1-1&keywords=Computer+Organization+and+Design+MIPS+Edition)
- [CSE378: Machine Organization & Assembly Language](https://courses.cs.washington.edu/courses/cse378/)

# [Database](database)

- [SQL](https://github.com/nhannguyen95/sql-in-10-mins-4th-edition)

## Resources
- [Book: Database System Concepts 6th Edition](https://www.amazon.com/Database-Concepts-Abraham-Silberschatz-Professor/dp/0073523321)


# Networking

## HTTP

- [HTTP: The definitive guide](additional-learning/http/http-the-definitive-guide)

## TCP/IP

- [TCP/IP](additional-learning/networking/tcpip)

# Additional Learning
  
## Git

- [Git Tutorial - Atlassian](additional-learning/git/git-tutorial-atlassian)
- [A successful Git branching model](https://nvie.com/posts/a-successful-git-branching-model/?fbclid=IwAR05eCUp9OO7BCwHbhfbbmuuEzlCJx5AxKuZUWPvWh6GsJFXv-JTM126K0U)

## Unix, [Linux](additional-learning/linux)

- [Introduction to Linux](additional-learning/linux/introduction-to-linux)

## Design Patterns

## Clean Code

## [Web Dev](additional-learning/webdev)

- [Django interview questions and answer](additional-learning/web-dev/django.md)

## [Web Security](additional-learning/web-security)

- [The Web Application Hacker's Handbook 2](additional-learning/web-security)


# Coding Practices

## [Leetcode](practices/leetcode)
  - Array.
  - Binary search.
  - Dynamic programming.
  - Heap.
  - Linked list.
  - Tree.
  - Database.
  - Bit manipulation.

## [Geeksforgeeks](practices/geeksforgeeks)
  - Tree.
  - Array.

## [Inteviewbit](practices/interview-bit)

## [Data structure](practices/data-structure-implementation)
  - Implement stack using array: [code](practices/data-structure-implementation/stack-using-array.cpp).
  - Implement 3 stacks using array, fixed size: [code](practices/data-structure-implementation/fixed-multistack-using-array.cpp).
  - Implement 3 stacks using array, flexible size: [code](practices/data-structure-implementation/flexible-multistack-using-array.cpp).
  - Implement queue using linked list: [code](practices/data-structure-implementation/queue-using-linked-list.cpp).
  - Stack with push, pop and min operate in O(1): [code](practices/data-structure-implementation/stack-min-o1.cpp)
  - Queue with push, pop and min operate in O(1)
  - Set of stacks with popAt(stackIndex) method: [code](practices/data-structure-implementation/set-of-stacks-with-popat.cpp)
  - Implement queue with 2 stacks: [code](practices/data-structure-implementation/queue-with-2-stacks.cpp)
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
  - [Book: Clean Code - Robert C Martin](notes/clean-code)


# [Interview strategies](https://github.com/nhannguyen95/interview-preparation/tree/master/strategies)

- [System design](interview-strategies/system-design.md).


# Advices

- _"The truth is that you are never going to feel fully prepared."_

- _"Majority candidates know what DFS/BFS is. What makes a difference is to have a deep understanding of those concepts."_

- _"You should be clear about the definition of those basic data structures/algorithms. Most people did a good job in this part, but not perfect. For instance, a lot of people are confused about dynamic programming and recursion."_

- _"Try to compare relevant data structures/algorithms and understand their pros and cons. A good example is BFS and DFS."_

- Which algorithm is better in what case?


# Miscellaneous

- [Vocabulary](miscellaneous/vocabulary.md)
- [C++ STD Containers](miscellaneous/c++-std-containers.md)
- [Limited memory interview questions](miscellaneous/limited-memory.md)

