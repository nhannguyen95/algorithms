# Solution 1: recursive
# Same as solution 2 in C++ version
class Solution:
    def invertTree(self, root):
        if root:
            root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)
        return root

# Solution 2: iterative
# Same as solution 4 in C++ version
class Solution:
    def invertTree(self, root):
        stack = [root]
        while stack:
            node = stack.pop()
            if node:
                node.left, node.right = node.right, node.left
                stack += node.right, node.left
        return root
        
