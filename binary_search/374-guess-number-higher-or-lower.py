class Solution(object):
    def guessNumber(self, n):
        low = 1
        high = n+1
        # If you assign either (low, high) = 1,
        # the while condition should be low < high
        # to avoid infinite loop
        while low < high:
            mid = low + (high - low) // 2
            if guess(mid) > 0: low = mid + 1
            else: high = mid
        return low
