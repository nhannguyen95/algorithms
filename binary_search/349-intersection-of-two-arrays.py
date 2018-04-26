class Solution:
    def intersection(self, nums1, nums2):
        set1 = set(nums1)  # O(N1)
        res = [x for x in nums2 if x in set1]  # O(N2)
        return list(set(res)) # O(min(N1, N2))
