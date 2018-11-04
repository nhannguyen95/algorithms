// Solution 1: Top down DP without memo
class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        int res = n;
        for(int i = 2; i <= n/2; i++) {
            if (n % i == 0) {
                res = min(res, minSteps(i) + (n/i));
            }
        }
        return res;
    }
};
