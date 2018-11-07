// https://leetcode.com/problems/score-after-flipping-matrix/

// Solution 1: Greedy, lengthy
class Solution {
public:
    void flipRow(vector<vector<int>>& A, int r) {
        for(int c = 0; c < A[0].size(); c++)
            A[r][c] = 1 - A[r][c];
    }
    
    void flipCol(vector<vector<int>>& A, int c) {
        for(int r = 0; r < A.size(); r++)
            A[r][c] = 1 - A[r][c];
    }
    
    int count0InColumn(vector<vector<int>>& A, int c) {
        int cnt0s = 0;
        for(int r = 0; r < A.size(); r++)
            cnt0s += (A[r][c] == 0);
        return cnt0s;
    }
    
    int matrixScore(vector<vector<int>>& A) {
        int nRows = A.size();
        assert(nRows > 0);
        int nCols = A[0].size();
        assert(nCols > 0);
        
        // Flip rows first.
        for(int r = 0; r < nRows; r++)
            if (A[r][0] == 0) flipRow(A, r);
            
        // Flip cols after that.
        for(int c = 0; c < nCols; c++)
            if (2*count0InColumn(A, c) > nRows)
                flipCol(A, c);
        
        // Compute the sum.
        int sum = 0;
        for(int r = 0; r < nRows; r++) {
            int sumRow = 0;
            for(int c = 0; c < nCols; c++)
                sumRow = 2 * sumRow + A[r][c];
            sum += sumRow;
        }
        return sum;
        
    }
};

// Solution 2: Greedy, shorter
// TODO
