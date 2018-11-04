// Solution 1: DFS
// O(area) in space (because of the stack trace)
// O(area) in time
class Solution {
public:
    bool inside(vector<vector<int>>& grid, int r, int c) {
        return (0 <= r && r < grid.size()) && 
               (0 <= c && c < grid[0].size());
    }
    
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (!inside(grid, r, c) || grid[r][c] == 0) return 0;
        
        grid[r][c] = 0;
        
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};
        int area = 1;
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            area += dfs(grid, nr, nc);
        }
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        
        int maxArea = 0;
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                maxArea = max(maxArea, dfs(grid, r, c));
            }
        }
        return maxArea;
    }
};
