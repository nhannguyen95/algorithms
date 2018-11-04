# Solution 1: iterative
class Solution:
    def diameterOfBinaryTree(self, root):
        if root is None: return 0
        stack = [root]
        height = {None: 0}
        diameter = 0
        while stack:
            node = stack[-1]
            if (not node.left or node.left in height) and \
               (not node.right or node.right in height):
                # Two children of this node are visited,
                # we can compute the diameter.
                diameter = max(diameter,
                               height[node.left] + height[node.right] \
                             + (node.left != None) + (node.right != None))
                height[node] = max(height[node.left] + (node.left != None),
                                   height[node.right] + (node.right != None))
                stack.pop()
            else:
                if node.left:
                    stack.append(node.left)
                if node.right:
                    stack.append(node.right)
        return diameter

# Solution 2: optimal iterative
# O(N) in space & time
class Solution:
    def diameterOfBinaryTree(self, root):
        if root is None: return 0
        stack = [root]
        height = {None: -1}
        diameter = 0
        while stack:
            node = stack[-1]
            if (not node.left or node.left in height) and \
               (not node.right or node.right in height):
               diameter = max(diameter, 2 + height[node.left] + height[node.right])
               height[node] = max(height[node.left], height[node.right]) + 1
               stack.pop()
           else:
               if node.left: stack.append(node.left)
               if node.right: stack.append(node.right)
        return diameter
