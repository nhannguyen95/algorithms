// Solution 1: most optimal
// 0 ^ x = x
// 1 ^ x = ~x
// O(N) in time, O(1) in space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int & num : nums)
            res ^= num;
        return res;
    }
};
