# Solution 1: recursive solution + hash table
# Same as solution 4 in C++ version
class Solution:
    def findTarget(self, root, k):
        seens = set()
        return self._findTarget(root, k, seens)

    def _findTarget(self, root, k, seens):
        if root is None:
            return False

        if (k - root.val) in seens:
            return True
        seens.add(root.val)

        return self._findTarget(root.left, k, seens) or \
               self._findTarget(root.right, k, seens)

# Solution 2: iterative solution (using stack)
# Same as solution 5 in C++ version
class Solution:
    def findTarget(self, root, k):
        if not root: return False
        stack, seens = [root], set()
        while stack:
            node = stack.pop()
            if (k - node.val) in seens: return True
            seens.add(node.val)
            if node.left: stack.append(node.left)
            if node.right: stack.append(node.right)
        return False
