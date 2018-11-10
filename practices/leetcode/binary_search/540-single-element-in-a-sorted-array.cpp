// https://leetcode.com/problems/single-element-in-a-sorted-array
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        while(lo < hi) {
            
            int mi = (lo + hi) / 2;
            if (mi % 2 == 1) mi--;
            if (nums[mi] != nums[mi+1]) hi = mi;
            else lo = mi + 2;
        }
        return nums[lo];
    }
};
