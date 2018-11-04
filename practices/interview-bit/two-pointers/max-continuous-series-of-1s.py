class Solution:
    def maxone(self, A, M):
        n = len(A)
        i = 0
        j = 0
        maxi = 0
        maxj = 0
        cnt0 = 0
        while j < n:
            if A[j] == 0:
                cnt0 += 1

            if cnt0 <= M:
                if j - i > maxj - maxi:
                    maxi = i
                    maxj = j
            else:
                while cnt0 > M:
                    if A[i] == 0:
                        cnt0 -= 1
                    i += 1

            j += 1

        return [k for k in range(maxi, maxj + 1)]
