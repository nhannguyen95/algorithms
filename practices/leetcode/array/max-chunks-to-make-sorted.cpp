// https://leetcode.com/problems/max-chunks-to-make-sorted/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int maxE = -1;
        for(int i = 0; i < arr.size(); i++) {
            maxE = max(maxE, arr[i]);
            if (maxE == i) {
                ans++;
                maxE = -1;
            }
        }
        return ans;
    }
};
