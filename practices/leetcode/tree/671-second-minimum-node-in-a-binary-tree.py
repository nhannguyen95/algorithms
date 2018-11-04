# Solution 1: iterative
# Implementation of solution 2 in C++ file.
# O(N) in space and time
class Solution:
    def findSecondMinimumValue(self, root):
        if root is None: return -1
        stack = [root]
        visited = {None: -1}
        while stack:
            node = stack[-1]

            if node.val > root.val:
                visited[node] = node.val
                stack.pop()
            elif (not node.left or node.left in visited) and \
                 (not node.right or node.right in visited):
                if visited[node.left] == -1:
                    visited[node] = visited[node.right]
                elif visited[node.right] == -1:
                    visited[node] = visited[node.left]
                else:
                    visited[node] = min(visited[node.left], visited[node.right])
                stack.pop()
            else:
                if node.left: stack.append(node.left)
                if node.right: stack.append(node.right)
        return visited[root]
