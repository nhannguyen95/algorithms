# Solution 1: same as solution 1 in C++ version
class Solution:
    def maxDepth(self, root):
        if root is None:
            return 0
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1

# Solution 2: same as solution 2 in C++ version
class Solution:
    def maxDepth(self, root):
        # Base case
        if root is None:
            return 0
        levels = [root]
        depth = 0
        while levels:
            depth += 1
            levels = [kid for node in levels for kid in (node.left, node.right) if kid]
        return depth
        
