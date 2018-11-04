# Solution 1: dynamic programming
# O(N) in time
# O(N) in space
class Solution:
    # @param arr: tuple of integers
    # @return an integer
    def trap(self, arr):
        n = len(arr)

        maxLeft = [0] * n
        maxLeft[0] = arr[0]
        for i in range(1, n):
            maxLeft[i] = max(maxLeft[i - 1], arr[i])

        maxRight = [0] * n
        maxRight[n - 1] = arr[n - 1]
        for i in range(n-2,-1,-1):
            maxRight[i] = max(maxRight[i + 1], arr[i])

        water = 0
        for i in range(0,n):
            water += min(maxLeft[i], maxRight[i]) - arr[i]
        return water

# Solution 1: dynamic programming
# O(N) in time
# O(N) in space
class Solution:
    def trap(self, arr):
        n = len(arr)

        left = 0
        right = n - 1

        maxLeft = 0
        maxRight = 0

        water = 0
        while left <= right:
            if arr[left] <= arr[right]:
                maxLeft = max(maxLeft, arr[left])
                water += maxLeft - arr[left]
                left += 1
            else:
                maxRight = max(maxRight, arr[right])
                water += maxRight - arr[right]
                right -= 1
        return water 
