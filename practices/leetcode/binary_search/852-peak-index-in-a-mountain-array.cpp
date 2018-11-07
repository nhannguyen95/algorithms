// https://leetcode.com/problems/peak-index-in-a-mountain-array/

// Solution 1: O(1) in space, O(logN) in time
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int lo = 0;
        int hi = A.size() - 1;
        while(lo < hi) {
            int mi = (lo + hi) / 2;
            if (A[mi] > A[mi+1]) hi = mi;
            else lo = mi + 1;
        }
        return hi;
    }
};
