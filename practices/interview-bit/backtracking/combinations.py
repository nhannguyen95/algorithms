class Solution:
	# @param A : integer
	# @param B : integer
	# @return a list of list of integers
	def combine(self, n, k):
	    ans = []

	    def combineHelper(index, comb):
	        if len(comb) == k:
	            ans.append(comb)
	        else:
	            for i in range(index, n+1):
	                combineHelper(i+1, comb + [i])

	    combineHelper(1, [])
	    return ans
