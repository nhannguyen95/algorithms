class Solution:
    def mySqrt(self, x):
        # Find maximum y so that y*y <= x
        low = 0
        high = x
        while low < high:
            mid = low + (high - low + 1) // 2
            # mid = (low + high + 1) // 2 = low + (high - low) // 2 + (high - low % 2)
            if mid*mid <= x: low = mid
            else: high = mid - 1
        return low
