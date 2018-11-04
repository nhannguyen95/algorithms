// Solution 1: Simulation
// O(N*M*3*3) in time, O(N*M) in space
class Solution {
public:
    bool isBetween(int x, int mn, int mx) {
        return mn <= x && x <= mx;
    }
    
    int applyFilter(vector<vector<int>>& M, int i, int j) {
        int sum = 0, validPoints = 0;
        for(int id = -1; id <= 1; id++) {
            for(int jd = -1; jd <= 1; jd++) {
                bool isValid = isBetween(i + id, 0, M.size() - 1) &&
                               isBetween(j + jd, 0, M[0].size() - 1);
                if (isValid) {
                    sum += M[i+id][j+jd];
                    validPoints++;
                }
            }
        }
        return sum / validPoints;
    }
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int n = M.size();
        if (n == 0) return M;
        int m = M[0].size();
        if (m == 0) return M;
        vector<vector<int>> smoothed(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int avg = applyFilter(M, i, j);
                smoothed[i][j] = avg;
            }
        }
        return smoothed;
    }
};
