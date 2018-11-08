// https://leetcode.com/problems/smallest-range-i/

// Solution 1: O(N) in time, O(1) in space
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int mn = *min_element(A.begin(), A.end());
        int mx = *max_element(A.begin(), A.end());
        return max(mx - mn - 2*K, 0);
    }
};
