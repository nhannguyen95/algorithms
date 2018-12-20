// Solution 1: Brute force

class Solution {
public:
    int computeOverlap(vector<vector<int>>& A,
                       vector<vector<int>>& B,
                       int dr, int dc) {
        int n = A.size();
        int overlap = 0;
        for(int i = max(0, -dr); i < min(n, n-dr); i++)
            for(int j = max(0, -dc); j < min(n, n-dc); j++) {
                overlap += (A[i][j] & B[i+dr][j+dc]);        
            }
        return overlap;
    }
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int maxOverlap = INT_MIN;
        for(int dr = -(n-1); dr <= (n-1); dr++) {
            for(int dc = -(n-1); dc <= (n-1); dc++) {
                int overlap = computeOverlap(A, B, dr, dc);
                maxOverlap = max(maxOverlap, overlap);
            }
        }
        return maxOverlap;
    }
};
