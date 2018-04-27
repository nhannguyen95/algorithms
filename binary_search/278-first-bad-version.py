# Solution 1: binary search
# O(logN) in time, O(1) in space
class Solution(object):
    def firstBadVersion(self, n):
        low = 1
        high = n+1
        while low < high:
            mid = low + (high - low) // 2
            if not isBadVersion(mid): low = mid + 1
            else: high = mid
        return low
