class Solution:
    # @param A: list of integers
    # @return a list of integers
    def prevSmaller(self, A):
        s = []
        ans = []
        for x in A:
            while s and s[-1] >= x:
                s.pop()

            ans.append(-1 if not s else s[-1])
            s.append(x)

        return ans
