// Solution 1: binary search
// N = len(letters)
// O(logN) in time, O(1) in space
class Solution:
    def nextGreatestLetter(self, letters, target):
        low = 0
        # Our answer is gonna be low, we don't set
        # high = n - 1 because if low < high, it misses
        # the last element.
        high = len(letters) 
        
        while low < high:
            mid = low + (high - low) // 2
            if letters[mid] <= target:
                low = mid + 1
            else: 
                high = mid
            
        return letters[low % len(letters)]
