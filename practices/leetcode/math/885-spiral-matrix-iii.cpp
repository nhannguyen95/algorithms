// https://leetcode.com/problems/spiral-matrix-iii/

// Solution 1
class Solution {
public:
    bool valid(int R, int C, int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;    
    }
    
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int layers = max(max(r0 + 1, R - r0 - 1), max(c0, C - c0 - 1));
        int r = r0, c = c0;
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};
        int curDir = 0;
        vector<vector<int>> ans;
        int layer = 1;
        while(layer <= layers) {
            if (valid(R, C, r, c)) {
                ans.push_back(vector<int>({r, c}));
                if (ans.size() == R * C) return ans;  // A bit optimization
            }
            
            r += dr[curDir];
            c += dc[curDir];
            
            if (abs(r - r0) == layer + 1 || abs(c - c0) == layer + 1) {
                r -= dr[curDir];
                c -= dc[curDir];
                
                curDir = (curDir + 1) % 4;
                if (curDir == 0) layer++;
                
                r += dr[curDir];
                c += dc[curDir];
            }
            // if ((curDir % 2 == 1 && abs(r-r0) == layer) ||
            //     (curDir % 2 == 0 && abs(c-c0) == layer)) {
            //     curDir = (curDir + 1) % 4;
            //     if (curDir == 0) layer++;
            // }
        }
        return ans;
    }
};
