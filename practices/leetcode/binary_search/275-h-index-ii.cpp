// Solution 1: binary search
// Find min mid such that citations[mid] >= n-mid
// Answer: n-mid
// O(logN) in time, O(1) in space
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0;
        int high = n;
        while(low < high) {
            int mid = (low + high) / 2;
            if (citations[mid] < n-mid)
                low = mid + 1;
            else
                high = mid;
        }
        return n-low;
    }
};
