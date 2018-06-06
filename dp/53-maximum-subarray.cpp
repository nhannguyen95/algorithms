// Solution 1
// O(N) in time, O(1) in space
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, res = nums[0];
        for(int num : nums) {
            sum += num;
            res = max(res, sum);
            if (sum < 0) sum = 0;
        }
        return res;
    }
};
