// Solution 1:
// O(nm) in time
// O(n + m) in space
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return true;
        int n = matrix[0].size();
        if (n == 0) return true;
        
        vector<int> diags(m + n + 1, -1);
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                int id = r - c + m + n + 1;
                if (diags[id] == -1) diags[id] = matrix[r][c];
                else if (diags[id] != matrix[r][c]) return false;
            }
        }
        return true;
    }
};

// Solution 2:
// O(nm) in time
// O(1) in space
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return true;
        int n = matrix[0].size();
        if (n == 0) return true;
        
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if (r > 0 && c > 0 && matrix[r][c] != matrix[r-1][c-1])
                    return false;
            }
        }
        return true;
    }
};

x x x
x x x

// Follow up 1: matrix is stored on disk, load at most 1 row at once
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        // Getting number of rows and columns should load
        // to the memory 1 element at a time.
        int m = matrix.size();
        if (m == 0) return true;
        int n = matrix[0].size();
        if (n == 0) return true;
        
        // Assume that the matrix is stored in a text file,
        // everytime the element matrix[r][c] is accessed,
        // consider it as readding by cin >> matrix[r][c].
        // So the order of reading is left to right, top to bottom.
        queue<int> q;
        for(int c = 0; c < n; c++) {
            q.push(matrix[0][c]);
        }
        for(int r = 1; r < m; r++) {
            q.push(matrix[r][0]);
            for(int c = 1; c < n; c++) {
                if (q.front() != matrix[r][c]) return false;
                else {
                    q.pop();
                    q.push(matrix[r][c]);
                }
            }
            q.pop();
        }
        return true;
    }
};

// Follow up 2: matrix is stored on disk, load at most a partial row at once
// Assume that we can load at most `step` elements of a row at once
// How to solve this?
