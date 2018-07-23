// Solution 1: Bottom Up DP
// O(N^2) in time and space complexity
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        
        vector<vector<int>> f(n+1, vector<int>(m+1, INT_MAX));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) f[i][j] = grid[i-1][j-1];
                else f[i][j] = grid[i-1][j-1] + min(f[i-1][j], f[i][j-1]);
            }
        }
        return f[n][m];
    }
};

// Solution 2: Bottom Up DP O(N) space complexity
// O(N^2) time complexity
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        
        vector<int> pre(m+1, INT_MAX);
        for(int i = 1; i <= n; i++) {
            vector<int> cur(m+1, INT_MAX);
            for(int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) cur[j] = grid[i-1][j-1];
                else cur[j] = grid[i-1][j-1] + min(cur[j-1], pre[j]);
            }
            pre = cur;
        }
        return pre[m];
    }
};
