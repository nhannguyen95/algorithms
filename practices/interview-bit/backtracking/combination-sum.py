class Solution:
    def combinationSum(self, A, B):
        A = sorted(set(A))

        n = len(A)
        acc = []

        def helper(target, i = 0):
            '''Complete solution with elements from A[i:]'''

            if target == 0:
                yield acc[:]
                return

            if i == n:
                return  # No Solution

            if A[i] <= target:
                # Start by picking smaller element
                acc.append(A[i])
                yield from helper(target - A[i], i)
                acc.pop()

                # Try with the next one
                yield from helper(target, i + 1)

        return list(helper(B))
