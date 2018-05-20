# Solution 1: dynamic programming
# O(nA*nB) in time and space
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int nA = A.size(), nB = B.size();
        vector<vector<int>> d(nA, vector<int>(nB, 0));
        int maxLen = 0;
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < B.size(); j++) {
                if (A[i] == B[j]) {
                    d[i][j] = 1;
                    if (i > 0 && j > 0) d[i][j] += d[i-1][j-1];
                }
                maxLen = max(maxLen, d[i][j]);
            }
        }
        return maxLen;
    }
};

# Solution 2: binary search + Rabin Karp
# Wrong answer, unknown reason
class Solution {
public:
    typedef unsigned long long ull;
    ull base = 113;
    ull MOD = 1e9 + 7;
    
    // Returns (x^n) % MOD
    ull pow(ull x, ull n) {
        if (n == 0) return 1;
        ull t = mod(pow(x, n/2));
        if (n % 2 == 0) return mod(t*t);
        return mod(x*mod(t*t));
    }
    
    ull mod(ull x) {
        return (x % MOD + MOD) % MOD;
    }
    
    unordered_set<ull> rolling(vector<int>& A, int guess) {
        ull t = pow(base, guess-1);
        ull hash = 0;
        unordered_set<ull> hashs;
        for(int i = 0; i < A.size(); i++) {
            if (i < guess) hash = mod(mod(base*hash) + A[i]);
            else hash = mod(mod(base*mod(hash-mod(t*A[i-guess])))+A[i]);
            
            if (i >= guess-1) hashs.insert(hash);
        }
        return hashs;
    }
    
    bool check(vector<int>& A, vector<int>& B, int guess) {
        unordered_set<ull> hashAs = rolling(A, guess);
        unordered_set<ull> hashBs = rolling(B, guess);
        for(ull hashA : hashAs) 
            if (hashBs.find(hashA) != hashBs.end()) return true;
        return false;
    }
    
    int findLength(vector<int>& A, vector<int>& B) {
        int low = 0;
        int high = min(A.size(), B.size());
        while(low < high) {
            int guess = (low + high + 1) / 2;
            if (check(A, B, guess)) low = guess;
            else high = guess - 1;
        }
        return low;
    }
};
