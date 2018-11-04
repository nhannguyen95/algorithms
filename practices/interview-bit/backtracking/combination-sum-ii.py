class Solution:
    def combinationSum(self, C, T):
        C.sort()
        ans = set()

        def combinationSumHelper(arr, sumSoFar, index):
            if sumSoFar == T:
                ans.add(tuple(arr))
            elif sumSoFar > B:
                return
            else:
                for i in range(index, len(A)):
                    combinationSumHelper(arr + [A[i]], sumSoFar + A[i], i + 1)


        combinationSumHelper([], 0, 0)

        return list(ans)
