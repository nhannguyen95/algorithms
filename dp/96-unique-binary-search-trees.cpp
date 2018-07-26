// Solution 1: DP without memo
// Time complexity: 
// - T(1) = 1
// - T(n) = T(1)T(n-1) + T(2)T(n-2) + ... + T(n-1)T(1)
//        = sum[i=1..n-1] T(i)T(n-i)
// T(n) is Catalan numbers: https://en.wikipedia.org/wiki/Catalan_number
// Space complexity:
// - I believe it's O(N)
class Solution {
public:
    int f(int l, int r) {
        if (l >= r) return 1;
        int res = 0;
        for(int i = l; i <= r; i++) {
            res += f(l, i-1) * f(i+1, r);
        }    
        return res;
    }
    
    int numTrees(int n) {
        return f(1, n);
    }
};

// Solution 2: DP + memo
// O(N^2) in space and time
class Solution {
public:
    int f(int l, int r, vector<vector<int>> & memo) {
        if (memo[l][r]) return memo[l][r];
        if (l >= r) return memo[l][r] = 1;
        int res = 0;
        for(int i = l; i <= r; i++) {
            res += f(l, i-1, memo) * f(i+1, r, memo);
        }    
        return memo[l][r] = res;
    }
    
    int numTrees(int n) {
        vector<vector<int>> memo(n+2, vector<int>(n+2, 0));
        return f(1, n, memo);
    }
};

// Solution 3: DP improved space complexity
// Utilize the fact that number of bst built from 1..n
// = number of bst build from (1+k)..(n+k)
class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n+1, 0);
        f[0] = 1;
        for(int i = 1; i <= n; i++) {
            // Pick i as root
            for(int j = 1; j <= i; j++) {
                f[i] += f[j-1] * f[i-j];
            }
        }
        return f[n];
    }
};

// Solution 4: Compute Catalan number
// f[n] = C[n] = 2*(2n+1)*C[n-1] / (n+2)
class Solution {
public:
    int numTrees(int n) {
        long long ans = 1;  // f[0]
        for(int i = 1; i <= n; i++) {
            ans = 2*ans*(2*i-1)/(i+1);
        }
        return ans;
    }
};
