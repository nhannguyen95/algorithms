// https://leetcode.com/problems/flood-fill/

// Solution 1
class Solution {
public:
    bool valid(vector<vector<int>>& image, int r, int c) {
        int R = image.size();
        int C = image[0].size();
        return 0 <= r && r < R && 0 <= c && c < C;
    }
    
    void floodFill(vector<vector<int>>& image,
                   int r, int c,
                   int oldColor, int newColor) {
        if (!valid(image, r, c)) return;
        if (image[r][c] == newColor) return;
        if (image[r][c] == oldColor) {
            image[r][c] = newColor;
            int dr[4] = {0, 0, 1, -1};
            int dc[4] = {1, -1, 0, 0};
            for(int i = 0; i < 4; i++)
                floodFill(image, r+dr[i], c+dc[i], oldColor, newColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        floodFill(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};
