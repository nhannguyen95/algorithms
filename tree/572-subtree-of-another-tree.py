# Solution 1: iterative
# Implementation of solution 2 in C++ file.
# N = number of nodes(S), M = number of nodes(T)
# O(N + M) in space (to store the pre-order array of s and t)
# Time complexity:
# + Step 1: O(N + M)
# + Step 2: O(N * M), N for iterator and M for comparison
# Step 2 can be improved by using pattern matching algorithm
# like KMP --> O(N + M)
class Solution:
    def isSubtree(self, s, t):
        def preorder(node):
            if node is None:
                return [None]
            return [node.val] + preorder(node.left) + preorder(node.right)

        # Step 1: get the pre-order array representation of s and t.
        sp = preorder(s)
        tp = preorder(t)

        # Step 2: check if t is a substring of s
        n = len(tp)
        return any((tp == sp[i:i+n]) for i in range(len(sp)-n+1))
