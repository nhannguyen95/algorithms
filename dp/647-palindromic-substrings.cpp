// Solution 1: dp
// O(N^2) in time and space
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int res = 0;
        for(int len = 1; len <= n; len++) {
            for(int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (len == 1) dp[i][j] = true;
                else if (len == 2) dp[i][j] = (s[i] == s[j]);
                else dp[i][j] = (s[i] == s[j]) & dp[i+1][j-1];
                
                res += dp[i][j];
            }
        }
        return res;
    }
};

// Solution 2: brute force
// O(N^2) in time, O(1) in space
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            // Count odd-length substring
            int left = i;
            int right = i;
            while(left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
                res++;
            }
            
            // Count even-length substring
            left = i;
            right = i+1;
            while(left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
                res++;
            }
        }
        return res;
    }
};
