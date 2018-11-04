// Solution 1:
// O(rows * cols) in space and time
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int old_r = nums.size();     // original number of rows
        int old_c = nums[0].size();  // original number of columns
        
        if (r * c != old_r * old_c) return nums;
        
        vector<vector<int>> reshape(r, vector<int>(c));
        for(int i = 0; i < old_r; i++) {
            for(int j = 0; j < old_c; j++) {
                int order = i * old_c + j;
                reshape[order / c][order % c] = nums[i][j];
            }
        }
        return reshape;
    }
};

// Solution 2: one loop (I should have thought about this solution earlier)
// Same space and time complexity as 1's
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int old_r = nums.size();     // original number of rows
        int old_c = nums[0].size();  // original number of columns
        
        if (r * c != old_r * old_c) return nums;
        
        vector<vector<int>> reshape(r, vector<int>(c));
        for(int i = 0; i < r * c; i++) {
            reshape[i / c][i % c] = nums[i / old_c][i % old_c];
        }
        return reshape;
    }
};
