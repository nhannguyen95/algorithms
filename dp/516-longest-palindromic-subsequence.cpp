// Solution 1: Top down DP + memoization
// O(N^2) in space and time complexity
class Solution {
public:
    int longestPalindrome(const string & s, int l, int r, vector<vector<int>> & memo) {
        if (l > r) return 0;
        if (memo[l][r] != -1) return memo[l][r];
        if (l == r) return memo[l][r] = 1;
        if (s[l] == s[r]) return memo[l][r] = 2 + longestPalindrome(s, l+1, r-1, memo);
        int left = longestPalindrome(s, l, r-1, memo);
        int right = longestPalindrome(s, l+1, r, memo);
        return memo[l][r] = max(left, right);
    }
    
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        return longestPalindrome(s, 0, s.size()-1, memo);
    }
};

// Solution 2: Bottom up DP
// O(N^2) in time and complexity
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int len = 1; len <= n; len++) {
            for(int l = 0; l <= n-len; l++) {
                int r = l + len - 1;
                if (len == 1) dp[l][r] = 1;
                else if (s[l] == s[r]) dp[l][r] = 2 + dp[l+1][r-1];
                else dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
            }
        }
        return dp[0][n-1];
    }
};

// Solution 3: Bottom up DP with brilliant O(N) idea!
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> dp(n, 1);  // 2D_dp[i][i] = 1
        for(int j = 1; j < n; j++) {
            // dp[i=0..j-1] = 2D_dp[i][j-1]
            // Now we update them so that after this iteration:
            // dp[i=0..j-1] = 2D_dp[i][j]
            int pre = dp[j];
            for(int i = j-1; i >= 0; i--) {
                int tmp = dp[i];
                if (s[i] == s[j]) dp[i] = (i+1 <= j-1) ? pre + 2 : 2;
                else dp[i] = max(dp[i+1], dp[i]); 
                pre = tmp;
            }
        }
        return dp[0];
    }
};
