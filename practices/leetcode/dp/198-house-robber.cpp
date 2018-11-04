// Solution 1: dp
// O(N) in time & space
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for(int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};

// Solution 2: improved dp
// O(N) in time, O(1) in space
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int robPrev = nums[0];
	    int noRobPrev = 0;
	    for(int i = 1; i < n; i++) {
            int robCur = noRobPrev + nums[i];
            int noRobCur = max(robPrev, noRobPrev);

            robPrev = robCur;
            noRobPrev = noRobCur;
	    }
	    return max(robPrev, noRobPrev);	
    }
};
