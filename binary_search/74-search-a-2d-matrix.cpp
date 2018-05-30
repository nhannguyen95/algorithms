// Solution 1: binary search
// O(logN + logM) in time, O(1) in space
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nRows = matrix.size();
        if (nRows == 0) return false;
        int nCols = matrix[0].size();
        if (nCols == 0) return false;
        
        // Search in rows
        int low = 0;
        int high = nRows-1;
        while(low < high) {
            int mid = (low + high) / 2;
            if (matrix[mid].back() < target) low = mid + 1;
            else high = mid;
        }
        int r = low;
        
        // Search in columns
        low = 0;
        high = nCols-1;
        while(low < high) {
            int mid = (low + high) / 2;
            if (matrix[r][mid] < target) low = mid + 1;
            else high = mid;
        }
        return matrix[r][low] == target;
    }
};
