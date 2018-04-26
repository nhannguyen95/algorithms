# Solution 1: 2 pointers
# O(1) in space 
# O(N) in time, N = len(numbers)
class Solution:
    def twoSum(self, numbers, target):
        i, j = 0, len(numbers) - 1
        while i < j:
            sum_ = numbers[i] + numbers[j]
            if sum_ == target: return [i+1, j+1]
            elif sum_ > target: j -= 1
            else: i += 1
        return [0, 0]  # should never reach
        
        
# Solution 2: binary search
# O(1) in space
# O(NlogN) in time
class Solution:
    def twoSum(self, numbers, target):
        def binary_search(x, low, high):
            while low <= high:
                mid = low + (high - low) // 2
                if numbers[mid] == x: return mid
                elif numbers[mid] > x: high = mid - 1
                else: low = mid + 1
            return -1
        
        for j in range(1, len(numbers)):
            i = binary_search(target-numbers[j], 0, j-1)
            if i != -1: return [i+1, j+1]
        return [0, 0]  # should never happen


# Solution 3: hash table
# O(N) in space
# O(N) in time
class Solution:
    def twoSum(self, numbers, target):
        prevs = {numbers[0]: 0}
        for j in range(1, len(numbers)):
            if (target-numbers[j]) in prevs:
                return [prevs[target-numbers[j]]+1, j+1]
            prevs[numbers[j]] = j
        return [0, 0]  # should never happen
        
        
        
        
