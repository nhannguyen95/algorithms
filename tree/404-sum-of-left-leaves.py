# Soluton 1: solution 3 in C++ file.
# Time & Space complexity same as solution 1
# in C++ file.
class Solution:
    def sumOfLeftLeaves(self, root):
        if not root: return 0
        if root.left \
           and not root.left.left \
           and not root.left.right:
            return root.left.val + self.sumOfLeftLeaves(root.right)
        return self.sumOfLeftLeaves(root.left) + \
               self.sumOfLeftLeaves(root.right)
