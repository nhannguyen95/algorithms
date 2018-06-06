// Solution 1: dp
// O(N) in time & space complexity
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);        
        for(int i = 1; i <= num; i++)
            dp[i] = 1 + dp[i&(i-1)];
        return dp;
    }
};
