class Solution:
    # @param A: list of integers
    # @return a list of integers
    def threeSum(self, A):
        A.sort()
        ans = set()
        for i, ai in enumerate(A[:-2]):
            j = i + 1
            k = len(A) - 1

            while j < k:
                sum = ai + A[j] + A[k]
                if sum == 0:
                    ans.add((ai, A[j], A[k]))
                    j += 1
                    k -= 1
                elif sum > 0:
                    k -= 1
                else:
                    j += 1
        return list(ans)
