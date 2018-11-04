# Solution 1: iterative solution using
# stack and hash table
# O(N) in time because we visit each node once
# space complexity of sum_ dictionary: O(N)
# space complexity of stack:
# - O(logN) in average because the size of the stack
#   is the depth of current node.
# - O(N) in worst case when the tree is skewed
# => space complexity overall: O(N)
class Solution:
    def findTilt(self, root):
        # Base case
        if not root:
            return 0

        stack = [root]
        sum_ = {}
        sum_[None] = 0
        tilt = 0
        while stack:
            node = stack[-1]
            if (not node.left or node.left in sum_) and \
               (not node.right or node.right in sum_):
                # if node's children are already visited
                tilt += abs(sum_[node.left] - sum_[node.right])
                sum_[node] = node.val + sum_[node.left] + sum_[node.right]
                stack.pop()
            else:
                if node.left:
                    stack.append(node.left)
                if node.right:
                    stack.append(node.right)
        return tilt
