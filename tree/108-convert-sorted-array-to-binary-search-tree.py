# Solution 1: iterative using bfs + queue
# N = number of nodes
# O(N) in time
# O(N) in space
class Solution:
    def levelOrderBottom(self, root):
        res = []
        if root is None: return res
        queue = [root]
        while queue:
            res.append([node.val for node in queue])
            queue = [kid for node in queue for kid in (node.left, node.right) if kid]
        return res[::-1]
