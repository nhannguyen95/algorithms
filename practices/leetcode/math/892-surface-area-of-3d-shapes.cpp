// https://leetcode.com/problems/surface-area-of-3d-shapes/

// Solution 1
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int surfaceArea = 0;
        for(int r = 0; r < R; r++)
            for(int c = 0; c < C; c++) {
                if (grid[r][c] == 0) continue;
                
                // top
                if (r-1 < 0) surfaceArea += grid[r][c];
                else surfaceArea += max(0, grid[r][c]-grid[r-1][c]);
                
                // bot
                if (r+1 >= R) surfaceArea += grid[r][c];
                else surfaceArea += max(0, grid[r][c]-grid[r+1][c]);
                
                // left
                if (c-1 < 0) surfaceArea += grid[r][c];
                else surfaceArea += max(0, grid[r][c]-grid[r][c-1]);
                
                // right
                if (c+1 >= C) surfaceArea += grid[r][c];
                else surfaceArea += max(0, grid[r][c]-grid[r][c+1]);
                
                surfaceArea += 2;
            }
        return surfaceArea;
    }
};
