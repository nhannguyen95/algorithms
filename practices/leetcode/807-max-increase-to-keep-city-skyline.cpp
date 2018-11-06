// Solution 1
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int nRows = grid.size();
        assert(nRows > 0);
        int nCols = grid[0].size();
        assert(nCols > 0);
        
        vector<int> maxRows(nRows, 0);
        vector<int> maxCols(nCols, 0);
        for(int i = 0; i < nRows; i++)
            for(int j = 0; j < nCols; j++) {
                maxRows[i] = max(maxRows[i], grid[i][j]);
                maxCols[j] = max(maxCols[j], grid[i][j]);
            }
        
        int maxSum = 0;
        for(int i = 0; i < nRows; i++)
            for(int j = 0; j < nCols; j++)
                maxSum += min(maxRows[i], maxCols[j]) - grid[i][j];
        return maxSum;
    }
};
