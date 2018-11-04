// 693. Binary Number with Alternating Bits
// https://leetcode.com/problems/binary-number-with-alternating-bits/description/

// Solution 1:
// O(1) in time and space
class Solution {
public:
    bool hasAlternatingBits(int n) {
                                  // n = 00101
        int all0 = n & (n >> 1);  //   = 00000
        int all1 = n | (n >> 1);  //   = 00111
        return (all0 == 0) && (((all1 + 1) & all1) == 0);
    }
};

// Solution 2: Complete bits
class Solution {
public:
    bool hasAlternatingBits(int n) {
        return !((n ^= n/2) & n + 1);
    }
};

// Solution 3: Cancel bits
class Solution {
public:
    bool hasAlternatingBits(int n) {
        return !((n ^= n/4) & n-1);
    }
};
