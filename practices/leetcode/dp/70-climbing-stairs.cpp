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

// Solution 3: matrix multiplication
// O(logN) in time & space
typedef vector<vector<int>> mat;
    
mat operator*(const mat & m1, const mat & m2) {
    mat p;
    p.assign(2, vector<int>(2, 1));
    p[0][0] = m1[0][0]*m2[0][0] + m1[0][1]*m2[1][0];
    p[0][1] = m1[0][0]*m2[0][1] + m1[0][1]*m2[1][1];
    p[1][0] = m1[1][0]*m2[0][0] + m1[1][1]*m2[1][0];
    p[1][1] = m1[1][0]*m2[0][1] + m1[1][1]*m2[1][1];
    return p;
}
    
class Solution {
public:
    
    mat matPow(const mat & m, int n) {
        if (n == 1) return m;
        mat t = matPow(m, n/2);
        if (n % 2 == 0) return t * t;
        return t * t * m;
    }
    
    int climbStairs(int n) {
        if (n == 1) return 1;
        mat base;
        base.assign(2, vector<int>(2, 1));
        base[0][0] = 0;
        base = matPow(base, n-1);
        return base[0][1] + base[1][1];
    }
};
