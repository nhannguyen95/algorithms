# Solution 1: binary search, finding lower bound
# N = len(nums)
# O(logN) in time, O(1) in space
class Solution:
    def searchInsert(self, nums, target):
        low = 0
        high = len(nums)
        while low < high:
            mid = low + (high - low) // 2
            if nums[mid] < target:
                low = mid + 1
            else:
                high = mid
        return low
