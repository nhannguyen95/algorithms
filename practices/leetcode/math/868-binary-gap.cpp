// https://leetcode.com/problems/binary-gap/

// Solution 1
class Solution {
public:
    int binaryGap(int N) {
        int maxGap = 0, curGap = -30;
        for(int i = 0; i < 30; i++) {
            int bit = (N >> i) & 1;
            if (bit == 0) curGap++;
            else {
                maxGap = max(maxGap, curGap + 1);
                curGap = 0;
            }
        }
        return maxGap;
    }
};
