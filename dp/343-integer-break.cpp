// Solution 1: DP
// O(58) in space, O(58*58) in time
class Solution {
public:
    int integerBreak(int n) {
        vector<int> f(59);
        f[2] = 1;
        for(int i = 3; i <= n; i++) {
            for(int j = 2; j < i; j++) {
                f[i] = max(f[i], max(f[j] * (i - j), j * (i - j)));
            }
        }
        return f[n];
    }
};

// Solution 2: Greedy + Inequality
// Assume N = a1 + .. + ak
// According to AM-GM: N = a1 + .. + ak >= k * (a1*..*ak)^(1/k)
// => Product <= (N/k)^k
// The equality holds <=> a1 = .. = ak
// This tells us in order to get the maximum product, we should break N into same numbers.
// Let's say that number is x: N = kx
// We maximize the product function f = x^(N/x)
// Take the derivative and do some calculation, x should approach e
// In integers, x should be 2 or 3 (since 2 < e < 3)
// But 2 or 3? Let's say N = 6, we have N = 2 + 2 + 2 = 3 + 3 and 2 * 2 * 2 < 3 * 3.
// This tells us to prefer 3, or we should only have at most two 2's.
// O(1) in space
// O(n) in time
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int product = 1;
        while(n > 4) {
            n -= 3;
            product *= 3;
        }
        product *= n;
        return product;
    }
};
