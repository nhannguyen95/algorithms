// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

// Solution 1
class Solution {
public:
    int cntSetBits(int x) {
        int cnt = 0;
        while(x) {
            cnt++;
            x &= (x - 1);
        }
        return cnt;
    }
    
    int countPrimeSetBits(int L, int R) {
        unordered_set<int> primes({2,3,5,7,11,13,17,19});
        int ans = 0;
        for(int i = L; i <= R; i++) {
            if (primes.find(cntSetBits(i)) != primes.end()) {
                ans++;
            }
        }
        return ans;
    }
};
