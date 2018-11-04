# Solution 1: binary search
# Find the largest m so that m*(m+1)/2 <= n
# O(logN) in time, O(1) in space
# Important implementation points:
# + If you're trying to force/push the answer to the left
#   like in lower bound, upper bound (means right elements
#   are validate values); use (low + high) / 2 because this
#   biases to the left.
# + Otherwise, if you're trying to push the answer to the 
#   right (like this problem); use (low + high + 1) / 2 because
#   this biases to the right.
# This is neccessary for the correctness and avoid infinite loop.
    
class Solution(object):
    def arrangeCoins(self, n):
        # find largest m so that m*(m+1)/2 <= n
        low = 0
        high = n
        while low < high:
            mid = (low + high + 1) / 2
            if mid*(mid+1)//2 <= n:
                low = mid
            else:
                high = mid - 1
        return low
