# Solution 1: dynamic programming
# O(nA*nB) in time and space
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int nA = A.size(), nB = B.size();
        vector<vector<int>> d(nA, vector<int>(nB, 0));
        int maxLen = 0;
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < B.size(); j++) {
                if (A[i] == B[j]) {
                    d[i][j] = 1;
                    if (i > 0 && j > 0) d[i][j] += d[i-1][j-1];
                }
                maxLen = max(maxLen, d[i][j]);
            }
        }
        return maxLen;
    }
};
