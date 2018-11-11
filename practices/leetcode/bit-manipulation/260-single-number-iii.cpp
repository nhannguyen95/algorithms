// https://leetcode.com/problems/single-number-iii

// Solution 1
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for(int num : nums) diff ^= num;
        diff &= -diff;
        
        vector<int> rets = {0, 0};
        for(int num : nums) {
            if ((num & diff) == 0)
                rets[0] ^= num;
            else
                rets[1] ^= num;
        }
        return rets;
    }
};
