# Rooted tree representation

## Binary tree

```
p
p.left
p.right
```

## Unbounded branching tree

Number of children of each node is at most `k`.

```
p
(p.parent)
p.child[1]
p.child[2]
..
p.child[k]
```

This scheme no longer works if k is unbounded, i.e. we do not know how many children of each node to allocate in advanced. More over, if some node has many children, some node has small number of chilren => waste a lot of memory.

Fortunately, there is a clever scheme to represent trees with arbitrary numbers of children: **left child, right sibling (and parent)**. It has the advantage of using only O(n) space for any n-node rooted tree (Figure 10.10, CLRS 3rd, p.247)

```
p
(p.parent)
p.left_child
p.right_sibling
```

## Represent by array

```
A[i]
A[2*i] = left child
A[2*i + 1] = right child
```

