// https://leetcode.com/problems/monotonic-array/

// Solution 1:
// O(N) in time, O(1) in space
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int status = -1;  // 0/1 = monotone increasing/decreasing
        for(int i = 0; i < A.size()-1; i++) {
            if (A[i] < A[i+1]) {
                if (status == 1) return false;
                status = 0;
            } else if (A[i] > A[i+1]) {
                if (status == 0) return false;
                status = 1;
            }
        }
        return true;
    }
};
