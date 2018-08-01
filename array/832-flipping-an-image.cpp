// Solution 1:
// O(1) in space, O(N*M) in time
class Solution {
public:
    void flipAndInvert(int & x, int & y) {
        if (x^y == 1) return;
        x = !x;
        y = x;
    }
    
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size();
        if (m == 0) return A;
        int n = A[0].size();
        if (n == 0) return A;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < (n+1)/2; j++) {
                flipAndInvert(A[i][j], A[i][n-j-1]);
            }
        }
        return A;
    }
};
