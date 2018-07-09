// Solution 1: Top down DP
// dp[i][j] = maximum difference score IF player 1 picks first
// Time complexity:
// - N = length(nums)
// - T(1) = 1, T(N) = 2*T(N-1) + 1
// - So T(N) = 2^N
=> O(N) = 2^N
// Space complexity:
// - Deepest stack call: N
// - So O(N)
class Solution {
public:
    int getDiff(const vector<int>& nums, int l, int r, int turn) {
        if (l == r) return nums[l]*turn;
        int pickLeft = turn*nums[l] + getDiff(nums, l+1, r, -turn);
        int pickRight = turn*nums[r] + getDiff(nums, l, r-1, -turn);
        return turn * max(turn * pickLeft, turn * pickRight);
    }
        
    bool PredictTheWinner(vector<int>& nums) {
        return getDiff(nums, 0, nums.size()-1, 1) >= 0;
    }
};

// Solution 2: Top down DP with no `turn` variable
// This solution is extremely intelligent if you think about it:
// dp[i][j] represents the maximum difference score if player 1 picks first,
// so -dp[i][j] represents what?
// Time complexity: O(2^N)
// Space complexity: O(N)
class Solution {
public:
    int getDiff(const vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        int pickLeft = nums[l] - getDiff(nums, l+1, r);
        int pickRight = nums[r] - getDiff(nums, l, r-1);
        return max(pickLeft, pickRight);
    }
        
    bool PredictTheWinner(vector<int>& nums) {
        return getDiff(nums, 0, nums.size()-1) >= 0;
    }
};

// Solution 3: Bottom down DP, realised from Solution 2
// O(N^2) in time and space
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int len = 1; len <= n; len++) {
            for(int l = 0; l < n-len+1; l++) {
                int r = l + len - 1;
                if (l == r) dp[l][r] = nums[l];
                else {
                    int pickLeft = nums[l] - dp[l+1][r];
                    int pickRight = nums[r] - dp[l][r-1];
                    dp[l][r] = max(pickLeft, pickRight);
                }
            }
        }
        return dp[0][n-1] >= 0;
    }
};
