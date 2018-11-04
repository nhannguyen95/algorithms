class Solution:
    # @param A : list of integers
    # @return an integer
    def nTriang(self, A):
        n = len(A)
        A.sort(reverse = True)
        count = 0
        for i in range(0, n - 2):
            j = i + 1
            k = n - 1
            while j < k:
                sum = A[j] + A[k]
                if sum <= A[i]:
                    k -= 1
                else:
                    count += (k - j)
                    j += 1
        return count % 1000000007
