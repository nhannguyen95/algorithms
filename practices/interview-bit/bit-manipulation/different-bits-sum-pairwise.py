class Solution:
    def cntBits(self, A):
        n = len(A)
        ans = 0
        for i in range(0, 32):
            cnt0 = 0
            for j in range(0, n):
                if (A[j] & (1 << i)) == 0:
                    cnt0 += 1

            ans += 2 * cnt0 * (n - cnt0)

        return ans % (10**9 + 7)
