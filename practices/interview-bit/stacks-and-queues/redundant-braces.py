class Solution:
    # @param A: string
    # @return an integer
    def braces(self, A):
        s = []
        ops = set(['+','-','*','/'])
        for c in A:
            if c == '(':
                s.append([c, 0])
            elif c == ')':
                if not s:
                    return 1  # Invalid braces
                if s[-1][1] == 0:
                    return 1
                s.pop()
            else:
                if s and (c in ops):
                    s[-1][1] = 1
        return 0
