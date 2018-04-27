# Solution 1: hash table (dictionary in Python)
# N = len(nums1), M = len(nums2)
# O(N + M) in time
# O(N + min(N, M)) in space
class Solution:
    def intersect(self, nums1, nums2):
        freq = collections.defaultdict(int)
        for num in nums1: freq[num] += 1
        
        res = []
        for num in nums2:
            if freq[num] > 0:
                res.append(num)
                freq[num] -= 1
        
        return res
        
# Solution 2: sorted array + two pointers
# O(NlogN + MlogM + min(N, M)) in time
# O(1) in space
class Solution:
    def intersect(self, nums1, nums2):
        # Incase arrays are sorted
        nums1.sort()
        nums2.sort()
        
        # 2 pointers
        res = []
        i = 0
        j = 0
        while(i < len(nums1) and j < len(nums2)):
            if nums1[i] == nums2[j]:
                res.append(nums1[i])
                i += 1
                j += 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
                
        return res
