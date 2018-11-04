# Solution 1: recursive with dfs
# N = number of nodes
# O(N) in time (each node is visited once)
# O(N) in space (for storing the result)
class Solution:
    def binaryTreePaths(self, root):
        def dfs(node, path):
            if not node.left and not node.right:
                ans.append(path + '->' + str(node.val))
                return
            if node.left: dfs(node.left, path + '->' + str(node.val))
            if node.right: dfs(node.right, path + '->' + str(node.val))

        ans = []
        if root is None: return ans
        dfs(root, '')
        return [path[2:] for path in ans]

# Solution 2: recursive, good code
# pattern: post-order
# same complexity as solution 1
class Solution:
    def binaryTreePaths(self, root):
        def findPath(node):
            if node is None:
                return []
            if not node.left and not node.right:
                return [str(node.val)]
            l = findPath(node.left)
            r = findPath(node.right)
            return [str(node.val) + '->' + x for x in l+r]

        return findPath(root)

# Solution 3: iterative
# Please refer to C++ file
