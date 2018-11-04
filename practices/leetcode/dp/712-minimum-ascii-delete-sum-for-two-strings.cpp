// Solution 1: DP
// O(N*M) in time & space complexity
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++) {
                if (i == 0) dp[i][j] = dp[i][j-1] + s2[j-1];
                else if (j == 0) dp[i][j] = dp[i-1][j] + s1[i-1];
                else if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1]);
            }
        return dp[n][m];
    }
};

// Solution 2: 1D DP
// O(N*M) in time & O(M) in space (or O(N) in space depending on the implementation)
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> pre(m+1, 0);
        for(int i = 0; i <= n; i++) {
            vector<int> cur(m+1, 0);
            for(int j = 0; j <= m; j++) {
                if (i == 0 && j == 0) cur[j] = 0;
                else if (i == 0) cur[j] = cur[j-1] + s2[j-1];
                else if (j == 0) cur[j] = pre[j] + s1[i-1];
                else if (s1[i-1] == s2[j-1]) cur[j] = pre[j-1];
                else cur[j] = min(pre[j]+s1[i-1], cur[j-1]+s2[j-1]);
            }
            pre = cur;
        }
        return pre[m];
    }
};
