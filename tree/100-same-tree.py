# Solution 1: iteration + 1 stack
# Time and Complexity same as solution 2
# in C++ file.
class Solution:
    def isSameTree(self, p, q):
        stack = [(p, q)]
        while stack:
            x,y = stack.pop()
            if not x and not y:
                continue
            if not x or not y:
                return False
            if x.val != y.val:
                return False
            stack.append((x.left, y.left))
            stack.append((x.right, y.right))
        return True
