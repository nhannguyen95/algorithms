// Solution 1: DP
// O(N*N) in time, O(N) in space
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](const vector<int> & v1, const vector<int> & v2) { return v1[0] < v2[0]; });
        vector<int> dp(n, 1);
        int res = 1;
        for(int i = 0; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

