# Solution 1: same as solution 1 in C++ version
class Solution:
    def tree2str(self, t):
        if not t:
            return ''
        ans = str(t.val)
        if t.left or t.right:
            ans += '(' + self.tree2str(t.left) + ')'
            if t.right:
                ans += '(' + self.tree2str(t.right) + ')'
        return ans

# Solution 2: same as solution 2 in C++ version
class Solution:
    def tree2str(self, t):
        if not t:
            return ''
        stack = [t]
        visited = set()
        ans = ''
        while stack:
            node = stack[-1]
            if node in visited:
                ans += ')'
                stack.pop()
            else:
                ans += '(' + str(node.val)
                visited.add(node)
                if not node.left and node.right:
                    ans += '()'
                if node.right:
                    stack.append(node.right)
                if node.left:
                    stack.append(node.left)
        return ans[1:-1]
