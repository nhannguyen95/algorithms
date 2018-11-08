// https://leetcode.com/problems/projection-area-of-3d-shapes/

// Solution 1: O(1) in space, O(n^2) in time
class Solution {
public:
    int projectionArea(vector<vector<int>>& A) {
        int n = A.size();
        
        int areaX(0), areaY(0), areaZ(0);
        for(int i = 0; i < n; i++) {
            int maxRow = 0;
            int maxCol = 0;
            for(int j = 0; j < n; j++) {
                areaZ += A[i][j] != 0;
                maxRow = max(maxRow, A[i][j]);
                maxCol = max(maxCol, A[j][i]);
            }
            areaX += maxRow;
            areaY += maxCol;
        }
        
        return areaX + areaY + areaZ;
    }
};
