// Solution 1: Simple math, dp intuition
// O(1) in space, O(1) (O(10)) in time
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;   // 0
        if (n == 1) return 10;  // 0-9
        int res = 10, pre = 9;
        for(int i = 2; i <= min(n, 10); i++) {
            int cur = pre * max(10 - i + 1, 0);
            pre = cur;
            res += pre;
        }
        return res;
    }
};
