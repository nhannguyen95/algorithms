## Problems
- [Construct BST from preorder traversal](https://practice.geeksforgeeks.org/problems/preorder-to-postorder/0): [solution](https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversal-set-2/)
- [Serialize and Deserialize a BT](https://leetcode.com/problems/serialize-and-deserialize-binary-tree).
  - Preorder, post order that contain null values; given 1, we can reconstruct a Binary Tree from it.
  - We can construct from level-order traversal or preorder traversal, both require n+1 null nodes.
- [Construct binary tree from inorder and preorder](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/): [iterative solution](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34555/The-iterative-solution-is-easier-than-you-think!/117721)
  - Preorder, inorder, postorder that don't contain null values; given 2, we can reconstruct a Binary Tree from them. Given 1, we can't (there's an infinite number of trees).

## Theory

### Types of binary tree:

**Depth, Height, Level in binary tree**: https://www.youtube.com/watch?v=TKQe_mvLRaI

**Balanced Tree**: cây cân bằng là cây mà tại mọi nút, chiều cao cây con phải và chiều cao cây con trái khác nhau không quá 1.

**Complete Binary Tree**: Every level of the tree is fully filled, except perhaps for the last level, it is filled from left to right.

**Full Binary Tree**: Every node has either 0 or 2 children.

**Perfect Binary Tree**: both complete and full.

### Operations on a binary tree

- PREDECESSOR, O(h)

- SUCCESSOR, O(h)

### Properties

Notations:
  - h: height
  - n: total number of nodes

**Full Binary Tree**:
  - c leaf nodes, c - 1 internal node => 2c - 1 = n
  - n-th [Catalan number](https://en.wikipedia.org/wiki/Catalan_number) = number of full binary tree with (n+1) leaf nodes.

**Complete Binary Tree**:
  - h = floor(lgn)
  - Maximum number of nodes of height h' = n / 2<sup>h'</sup>
  - Internal nodes 2<sup>h</sup> - 1

**Perfect Binary Tree**:

  - n = 2<sup>h+1</sup> - 1 nodes

A **free tree** is a connected, acyclic, undirected graph.

If an undirected graph is acyclic but possibly disconnected, it is a **forest**.

A **rooted tree** (T) is a free tree in which one of the vertices is distinguished from the others. We call the distinguished vertex the root (r) of the tree. We often refer to a vertex of a rooted tree as a node (x) of the tree.

We call any node y on the unique simple path from r to x an **ancestor** of x. If y is an ancestor of x, then x is a **descendant** of y. Every node is both an ancestor and a descendant of itself.

If y is an ancestor of x and x != y, then y is a **proper ancestor** of x and x is a **proper descendant** of y.

If the last edge on the simple path from the root r of a tree T to a node x is (y, x), then y is the **parent** of x, and x is a **child** of y. The root is the only node in T with no parent. If two nodes have the same parent, they are **siblings**. A node with no children is a **leaf** or **external node**. A nonleaf node is an **internal node**.

An **ordered tree** is a rooted tree in which the children of each node are ordered
