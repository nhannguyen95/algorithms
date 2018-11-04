class Solution:
    # @param A: list of integers
    # @return an integer
    def findMinXor(self, A):
        A.sort()
        ans = A[0] ^ A[1]
        for i in range(2, len(A)):
            ans = min(ans, A[i] ^ A[i - 1])
        return ans
