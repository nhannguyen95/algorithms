// Note: to understand this problem (and to also compute the complexity easily),
// you should think the recursion process as the tree.

// Solution 1: Brute force, TLE
class Solution {
public:
    
    int f(vector<int>& nums, int i, int target) {
        if (target == 0) return 1;
        
        int res = 0;
        for(int cnt = 1; cnt * nums[i] <= target; cnt++) {
            if (cnt * nums[i] == target) res++;
            else {
                for(int j = 0; j < nums.size(); j++) {
                    if (j != i) res += f(nums, j, target - cnt * nums[i]);
                }
            }
        }
        return res;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> memo;
            res += f(nums, i, target);
        }
        return res;
    }
};

// Solution 2: DP
// O(target) in space, O(target * nums.size()) in time
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++) 
            for(int & num : nums)
                if (i >= num) dp[i] += dp[i - num];
        return dp[target];
    }
};
