// 283 Move Zeros
// https://leetcode.com/problems/move-zeroes/description/
// Dutch National Flag algorithm

// Solution 1: for style
// O(1) in space, O(N) in time
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lo = 0;
        for(int hi = 0; hi < nums.size(); hi++) {
            // nums[0..lo] = {non-0}
            // nums[lo+1..hi] = {0}
            if (nums[hi] != 0) swap(nums[lo], nums[hi--]);
        }
    }
};
