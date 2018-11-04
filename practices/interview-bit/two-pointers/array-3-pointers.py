class Solution:
    #@paramA: tuple of integers
    #@paramB: tuple of integers
    #@paramC: tuple of integers
    def minimize(self, A, B, C):
        sizeA = len(A)
        sizeB = len(B)
        sizeC = len(C)
        i = 0
        j = 0
        k = 0
        ans = float("inf")
        while(i < sizeA and j < sizeB and k < sizeC):
            mn = min(A[i], B[j], C[k])
            mx = max(A[i], B[j], C[k])
            ans = min(ans, mx - mn)

            if A[i] == mn:
                i += 1
            elif B[j] == mn:
                j += 1
            else:
                k += 1
        return ans
