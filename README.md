# Updates

- March 10, 2019: _no longer update solved problems for online judges._

# Content

- [Languages](#languages)
  - C++
  - Python
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
  - [Object-oriented design](#object-oriented-design)
  - [Clean Code](#clean-code)
  - [Web Dev](#web-dev)
  - [Web Security](#web-security)
- [Coding Practices](#coding-practices)
- [Other Useful Resources](#other-useful-resources)
- [Interview strategies](#interview-strategies)
- [Advices](#advices)
- [Miscellaneous](#miscellaneous)

# Languages
- [C++](languages/c++)
- [Python](languages/python)

# Algorithms and Data Structures

## Algorithms
  - [Bit manipulation *](algorithms-and-data-structures/algorithms/bit-manipulation.md)
  - Recursion
  - Divide and Conquer
  - [Dynamic Programming *](algorithms-and-data-structures/algorithms/dynamic-programming.md):
    - [Longest common subsequence (LCS) *](https://docs.google.com/document/d/10GzzyeoIHI21CbCfbZuIWZYFfyNUOMWjjlcuDmcvrdg/edit?usp=sharing)
    - [Longest increasing subsequence (LIC) *](https://nhannguyen95.wordpress.com/2017/02/27/lis-day-con-tang-dai-nhat/)
    - Optimal binary search tree
  - [Greedy](algorithms-and-data-structures/algorithms/greedy.md):
    - [Activity selection problem](algorithms-and-data-structures/algorithms/activity-selection.cpp)
    - [Huffman codes *](algorithms-and-data-structures/algorithms/huffman-codes.cpp)
    - [Coin changing *](algorithms-and-data-structures/algorithms/coin-changing.cpp)
  - [Sorting *](algorithms-and-data-structures/algorithms/sorting.md):
    - [Bubble sort *](algorithms-and-data-structures/algorithms/bubble-sort.cpp)
    - [Insertion sort *](algorithms-and-data-structures/algorithms/insertion-sort.cpp)
    - [Selection sort *](algorithms-and-data-structures/algorithms/selection-sort.cpp)
    - [Merge sort *](algorithms-and-data-structures/algorithms/merge-sort.cpp)
    - [Quick sort *](algorithms-and-data-structures/algorithms/quick-sort.cpp)
    - [Heap sort *](algorithms-and-data-structures/algorithms/heap-sort.cpp)
    - [Counting sort *](algorithms-and-data-structures/algorithms/counting-sort.cpp)
    - [Radix sort *](algorithms-and-data-structures/algorithms/radix-sort.cpp)
    - Bucket sort
    - [External sort *](https://en.wikipedia.org/wiki/External_sorting)
  - Searching
    - [Binary search](algorithms-and-data-structures/binary-search.md)
  - [String *](algorithms-and-data-structures/algorithms/string.md):
    - String matching:
      - [Rabin-Karp *](algorithms-and-data-structures/algorithms/rabin-karp.cpp)
      - [2D Rabin-Karp](algorithms-and-data-structures/algorithms/2d-rabin-karp.cpp)
      - [Finite automata](algorithms-and-data-structures/algorithms/finite-automata.cpp)
      - [KMP (Knuth-Morris-Pratt) *](algorithms-and-data-structures/algorithms/kmp.cpp)
      - String matching with gap characters.
    - [Edit Distance *](algorithms-and-data-structures/algorithms/edit-distance.cpp)
  - Probability
  - Math:
    - [Mathematical Background *](algorithms-and-data-structures/mathematical-background.md)
    - [Counting and Probability *](algorithms-and-data-structures/counting-and-probability.md)
    - [Number theory *](algorithms-and-data-structures/algorithms/number-theory.md)
    - [Factorization in O(sqrt(N)) *](https://sites.google.com/site/indy256/algo/factorization)
    - [Sieve Eratosthenes *](algorithms-and-data-structures/algorithms/sieve-eratosthenes.cpp)
    - [Euclid's algorithm for finding Greatest Common Divisor (GCD) *](algorithms-and-data-structures/algorithms/euclid-gcd.cpp)
    - [Extended Euclid's algorithm for finding Modular Multiplicative Inverse](algorithms-and-data-structures/algorithms/euclid-mmi.cpp)
    - [Primality testing](algorithms-and-data-structures/algorithms/primality-testing.cpp)
    - [The Tortoise and Hare algorithm *](https://nhannguyen95.github.io/the-tortoise-and-hare-algorithm/)
  - Tree:
    - [Minimum spanning tree (MST) *](algorithms-and-data-structures/algorithms/mst.md)
      - [Kruskal's algorihtm *](algorithms-and-data-structures/algorithms/mst-kruskal.cpp)
      - [Prim's algorithm *](algorithms-and-data-structures/algorithms/mst-prim.cpp)
      - [Second-best minimum spanning tree](algorithms-and-data-structures/algorithms/2nd-mst.cpp)
  - Binary Tree:
    - [Preorder traversal, recursive and iterative *](https://nhannguyen95.github.io/preorder-traversal-binary-tree/)
    - [Inorder traversal, recursive and iterative *](https://nhannguyen95.github.io/inorder-traversal-binary-tree/)
    - [Postorder traversal, recursive and iterative *](https://nhannguyen95.github.io/postorder-traversal-binary-tree/)
    - [Morris Inorder Tree Traversal *](https://nhannguyen95.github.io/morris-inorder-tree-traversal/)
    - [Morris Preorder Tree Traversal *](https://leetcode.com/submissions/detail/226117766/)
    - [Morris Postorder Tree Traversal *](http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html)
    - [Binary Tree Iterator *](https://nhannguyen95.github.io/bt-iterator/)
  - [Graph *](algorithms-and-data-structures/algorithms/graph.md):
    - [BFS *](algorithms-and-data-structures/algorithms/bfs.cpp)
    - Bidirectional BFS: [1](https://leetcode.com/problems/word-ladder-ii/), [2](https://leetcode.com/problems/word-ladder/solution/)
    - [DFS *](algorithms-and-data-structures/algorithms/dfs.cpp)
    - [Flood fill *](https://docs.google.com/document/d/1IPRsAb1OnCercO2_O2A-Z2m0eI5I7yykQD2urKdrNIc/edit)
    - [Topological sort *](algorithms-and-data-structures/algorithms/topo-sort.cpp)
    - [Strongly connected components *](algorithms-and-data-structures/algorithms/strongly-connected-components.cpp)
    - [Shortest-paths *](algorithms-and-data-structures/algorithms/shortest-paths.md)
      - [Single-source shortest-paths - Bellman Ford *](algorithms-and-data-structures/algorithms/bellman-ford.cpp)
      - [Single-source shortest-paths on DAG *](algorithms-and-data-structures/algorithms/sssp-dag.cpp)
      - [Single-source shortest-paths - Dijkstra *](algorithms-and-data-structures/algorithms/dijkstra.cpp)
      - [All pairs shortest-paths - Floyd *](algorithms-and-data-structures/algorithms/floyd.cpp)
      - All pairs shortest-paths - Johnson
      - [Transitive closure of a directed graph *](algorithms-and-data-structures/algorithms/transitive-closure.cpp)
    - [Bridges and Articulation Points of a undirected graph *](https://github.com/nhannguyen95/stuffs/blob/master/algorithms-and-data-structures/algorithms/bridges-articulation-points.cpp)
    - [Biconnected Components *](algorithms-and-data-structures/algorithms/biconnected-components.cpp)
    - [Euler tour *](algorithms-and-data-structures/algorithms/euler-tour.cpp)
    - [Graph coloring *](algorithms-and-data-structures/algorithms/graph-coloring.cpp)
    - [Bipartite graph checking *](algorithms-and-data-structures/algorithms/bipartite-checking.cpp)
  - Network flow
  - Medians and Order Statistics
    - [Randomized order statistic / Quickselect *](algorithms-and-data-structures/algorithms/randomized-order-statistic.cpp)
      > There is a linear worst case running time for this problem.
  - [Computational Geometry *](algorithms-and-data-structures/algorithms/computational-geometry.cpp):
    - Determine if there exists any 3 points in a set of n points that are colinear
    - Determine if a point lies inside a simple polygon (not neccessary convex)
    - Find area of a simple polygon (not neccessary convex)
    - [Determining whether any pair of segments intersects (Shamos–Hoey algorithm)](algorithms-and-data-structures/algorithms/pair-of-line-intersects.cpp)
    - Determining whether any pair of circles intersects
    - [Find all intersections of a set of segments (Bentley–Ottmann algorithm)](https://en.wikipedia.org/wiki/Bentley%E2%80%93Ottmann_algorithm)
    - Finding the convex hull:
      - [Graham's scan algorithm (nlogn) *](algorithms-and-data-structures/algorithms/graham-scan.cpp)
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
  - Matrix Power (Nhân ma trận) *
  - Lowest Common Ancestor
  - [Partial Sum *](algorithms-and-data-structures/algorithms/partial-sum.cpp)
  - [Infix, Prefix, Postfix Expressions](http://interactivepython.org/lpomz/courselib/static/pythonds/BasicDS/InfixPrefixandPostfixExpressions.html#tbl-parexample):
    - [Infix to Postfix](https://practice.geeksforgeeks.org/problems/infix-to-postfix/0)
    - Postfix Evalucation: [1](https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression/0/?ref=self), [2](https://leetcode.com/problems/evaluate-reverse-polish-notation/).
    - [Evaluate Expression](https://www.hackerrank.com/contests/cs1300-odd-2014/challenges/evaluate-expression)

## Data structures
  - Array
  - Vector (Dynamic Array)
  - Linked list:
    - [Singly Linked List *](algorithms-and-data-structures/data-structures/singly-linked-list.cpp)
    - [Doubly Linked List *](algorithms-and-data-structures/data-structures/doubly-linked-list.cpp)
  - [Hash Table *](algorithms-and-data-structures/data-structures/hash-table.md)
  - [Heap *](algorithms-and-data-structures/data-structures/heap.md) _Need to read this before reading any heap related stuffs_:
    - [Binary heap *](algorithms-and-data-structures/data-structures/binary-heap.cpp)
    - [D-ary heap *](algorithms-and-data-structures/data-structures/d-ary-heap.cpp)
    - [Young Tableau](algorithms-and-data-structures/data-structures/young-tableau.cpp)
    - [Mergeable heap](https://sites.google.com/site/indy256/algo/mergeable_heap)
    - Fibonacci Heap
  - String:
    - [Trie *](algorithms-and-data-structures/data-structures/trie.cpp)
    - [Suffix Tree *](algorithms-and-data-structures/data-structures/suffix-tree.md)
    - [Suffix Array](algorithms-and-data-structures/data-structures/suffix-array.cpp)
  - [Stack *](algorithms-and-data-structures/data-structures/stack-array.cpp)
  - [Queue *](algorithms-and-data-structures/data-structures/queue-array.cpp):
    - Priority Queue
    - Circular queue
  - [Deque *](algorithms-and-data-structures/data-structures/deque-array.cpp)
  - [Tree *](algorithms-and-data-structures/data-structures/tree.md):
    - [Binary Tree *](algorithms-and-data-structures/data-structures/binary-tree.md)
    - [Binary Search Tree *](algorithms-and-data-structures/data-structures/binary-search-tree.cpp)
    - [Segment Tree (IT - Interval Tree) *](algorithms-and-data-structures/data-structures/segment-tree.cpp)
    - [Binary Indexed Tree (BIT - Fenwick Tree) *](algorithms-and-data-structures/data-structures/fenwick-tree.cpp)
    - Radix Tree
    - Balanced Search Tree:
      - AVL Tree
      - Splay Tree
      - Red Black Tree
      - B-Trees
  - Set/Map
  - [Disjoint-Set Forest *](algorithms-and-data-structures/data-structures/disjoint-set-forest.cpp)
  - [Treap](https://cp-algorithms.com/data_structures/treap.html) 

## Classic/Handy problems (compiled from [GFGs](https://www.geeksforgeeks.org/must-coding-questions-company-wise/)) and Leetcode
  - Array
    - [Maximum subarray problem *](algorithms-and-data-structures/classic-problems/maximum-subarray.cpp)
    - [Missing number in array](https://leetcode.com/problems/missing-number/)
    - [Dutch national flag algorithm *](algorithms-and-data-structures/classic-problems/dutch-national-flag.md): [2-ways.cpp](algorithms-and-data-structures/handy-algorithms/dnf-2-ways.cpp), [3-ways.cpp](algorithms-and-data-structures/handy-algorithms/dnf-3-ways.cpp).
    - [Maximum sum increasing subsequence](https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0): [solution](https://e2718281828459045.wordpress.com/2013/09/06/maximum-sum-increasing-subsequence/).
    - [Spirally traversing a matrix](https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0)
    - [Search in rotated sorted array](https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/), [with duplicates](https://leetcode.com/problems/search-in-rotated-sorted-array-ii)
    - [Next lexicographical permutation](https://leetcode.com/problems/next-permutation/): [solution](https://nhannguyen95.wordpress.com/2016/03/07/thuat-toan-liet-ke-hoan-vi-theo-thu-tu-tu-dien/)
    - [Longest valid parentheses](https://leetcode.com/problems/longest-valid-parentheses/): O(N) in time, O(1) in space.
    - [k-th permutation of n numbers](https://leetcode.com/problems/permutation-sequence/): O(N<sup>2</sup>) in time, O(N) in space.
    - [Search in 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/): O(log(N * M)) in time, O(1) in space.
  - Math:
    - Compute (n, k) in O(k) time, O(1) space
  - Big Numbers:
    - [Multiplication](https://leetcode.com/problems/multiply-strings/) in O(N * M) time and O(N + M) in space.
  - Stack:
    - [Valid parenthesis, multiple types](https://leetcode.com/problems/valid-parentheses/): O(N) in time and space.
  - Linked list:
    - [Reverse a linked list in O(N) time, O(1) space *](https://leetcode.com/problems/reverse-linked-list/)
    - [Middle element of linked list in O(N) time, O(1) space](https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1): see the use of `next` function there.
    - [N-th element from end of linked list if O(N) time, O(1) space](https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1): using 2 pointers.
    - [Check palindrome linked-list in O(N) time and O(1) space](https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1): there's a cool recursive solution.
    - [Merge K sorted linked list of N elements in total](https://leetcode.com/problems/merge-k-sorted-lists/): O(NlogK) in time, O(1) in space.
  - Sorting:
    - [Count number of smaller elements after self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/445769/merge-sort-CLEAR-simple-EXPLANATION-with-EXAMPLES-O(n-lg-n)): O(NlogN) time, O(N) space.
  - String:
    - [Longest Common Substring](https://practice.geeksforgeeks.org/problems/longest-common-substring/0): this can be solved using DP, Trie or Suffix Array.
    - [Implement Atoi *](https://www.interviewbit.com/problems/atoi/)
  - Heap:
    - [Find median in a stream](https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0)
    - k-way merge *: merge k sorted lists of total n elements into 1 sorted list in O(nlgk)
  - Binary tree:
    - [Construct BST from preorder traversal *](https://practice.geeksforgeeks.org/problems/preorder-to-postorder/0): [solution](https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversal-set-2/)
    - [Serialize and Deserialize a BT *](https://leetcode.com/problems/serialize-and-deserialize-binary-tree): We can construct from level-order traversal or preorder traversal, both require n+1 null nodes.
    - [Construct binary tree from inorder and preorder](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/): [iterative solution](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34555/The-iterative-solution-is-easier-than-you-think!/117721)
  - Recursion:
    - [Generate permutations (no duplications) *](https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0)
    - [Generate permutations (duplications possible) *](https://leetcode.com/problems/permutations-ii)
  - Dynamic Programming:
    - [Knapsack problem *](algorithms-and-data-structures/classic-problems/knapsack-problem.cpp)
  - Graph:
    - [Minimum Swaps to Sort](https://practice.geeksforgeeks.org/problems/minimum-swaps/1)
  - Optimal binary search tree
  - Interval-graph coloring problem
  - Chvátal's greedy set-covering heuristic
  - Least Common Ancestors (LCA)
  - Scheduling with profits and deadlines
  - [Exponential search *](https://en.wikipedia.org/wiki/Exponential_search).
  - Split string *: [code](algorithms-and-data-structures/handy-algorithms/split-string.cpp).

## Others
  - [Big O Notation *](algorithms-and-data-structures/big-o-notation.md)
  - [Master Theorem](algorithms-and-data-structures/master-theorem.md)
  - [Amortized Analysis](algorithms-and-data-structures/amortized-analysis.md)
  - Operating System - Threads, Processes and Locks using Mutex, Semaphores
  - Scalability Issues, RPCs, Rate limiter
  - Concurrency
  - API Design
  - OOP Concepts
  - Writing simple Queries.
  - (Scaleable) Distributed Systems and Cloud Computing
  - [RSA public-key cryptosystem](algorithms-and-data-structures/rsa.md)
  - [Encoding vs. Encryption vs. Hashing vs. Obfuscation](https://danielmiessler.com/study/encoding-encryption-hashing-obfuscation/)

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
- [SQL and NoSQL Database](database/sql-and-nosql-database.md)
- [Visual Guide to NoSQL Systems](http://blog.nahurst.com/visual-guide-to-nosql-systems)

## Resources
- [Book: Database System Concepts 6th Edition](https://www.amazon.com/Database-Concepts-Abraham-Silberschatz-Professor/dp/0073523321)


# Networking

- [Networking interview questions and answers](additional-learning/networking/networking.md)

## HTTP

- [HTTP: The definitive guide](additional-learning/http/http-the-definitive-guide)

## TCP/IP

- [TCP/IP](additional-learning/networking/tcpip)

# Additional Learning
  
## Git

- [Git Tutorial - Atlassian](additional-learning/git/git-tutorial-atlassian)
- [A successful Git branching model](https://nvie.com/posts/a-successful-git-branching-model/?fbclid=IwAR05eCUp9OO7BCwHbhfbbmuuEzlCJx5AxKuZUWPvWh6GsJFXv-JTM126K0U)
- https://learngitbranching.js.org/

## Unix, [Linux](additional-learning/linux)

- [Introduction to Linux](additional-learning/linux/introduction-to-linux)
- [The Linux programming interface](additional-learning/linux/the-linux-programming-interface)

## Design Patterns

- [Design patterns](additional-learning/design-patterns)

## Object-oriented Design

- [Object-oriented Design](additional-learning/ood.md)

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
- [Questions](miscellaneous/questions.md)
- [Common complexity pattern](miscellaneous/common-complexity-pattern.md)
- [Online vs Offline algorithm](https://en.wikipedia.org/wiki/Online_algorithm)

