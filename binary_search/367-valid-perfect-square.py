# Solution 1: binary search
# O(log(num)) in time, O(1) in space
class Solution:
    def isPerfectSquare(self, num):
        low = 1
        high = num
        while low <= high:
            mid = low + (high - low) // 2
            mid2 = mid * mid
            if mid2 == num: return True
            elif mid2 < num: low = mid + 1
            else: high = mid - 1
        return False
