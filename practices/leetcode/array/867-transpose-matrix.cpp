// Solution 1
// O(n*m) in space, O(n*m) in time
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m = A.size();
        if (m == 0) return A;
        int n = A[0].size();
        if (n == 0) return A;
        
        vector<vector<int>> B(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                B[i][j] = A[j][i];
            }
        }
        return B;
    }
};
