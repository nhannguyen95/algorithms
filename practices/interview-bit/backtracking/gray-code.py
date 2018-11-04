class Solution:
    def grayCode(self, A):
        res = [0]
        for i in range(A):
            t = 1 << i
            temp = [j+t for j in reversed(res)]
            res = res + temp
        return res
