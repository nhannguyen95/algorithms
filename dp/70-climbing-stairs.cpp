// Solution 1: top down
// O(N) in time and space
class Solution {
public:
    int nClimbs(int n, vector<int> & memo) {
        if (n == 0 || n == 1) return memo[n] = 1;
        if (memo[n] > 0) return memo[n];
        return memo[n] = nClimbs(n-1, memo) + nClimbs(n-2, memo);
    }
    
    int climbStairs(int n) {
        vector<int> memo(n+1, 0);
        return nClimbs(n, memo);
    }
};

// Solution 2: improved bottom up
// O(N) in time, O(1) in space
class Solution {
public:
    int climbStairs(int n) {
        int cur = 1, pre1 = 1, pre2 = 1;
        for(int i = 2; i <= n; i++) {
            cur = pre1 + pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};
