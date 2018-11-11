// https://leetcode.com/problems/minimum-falling-path-sum

// Solution 1: DP
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int R = A.size();
        assert(R > 0);
        int C = A[0].size();
        assert(C > 0);
        
        vector<int> pre(A[0]);
        for(int r = 1; r < R; r++) {
            vector<int> cur(C, 100*100);
            for(int c = 0; c < C; c++) {
                for(int i = -1; i <= 1; i++)
                    if (0 <= c+i && c+i < R)
                        cur[c] = min(cur[c], A[r][c] + pre[c+i]);
            }
            pre = cur;
        }
        return *min_element(pre.begin(), pre.end());
    }
};
