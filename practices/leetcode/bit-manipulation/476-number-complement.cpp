// Solution 1
// n = 0* 1 ?* => mask = 0* 0 1*
// result = ~n & mask
// O(32) in time, O(1) in space
class Solution {
public:
    int findComplement(int num) {
        int mask = num;
        while((mask & (mask - 1)) != 0)
            mask &= (mask - 1);
        mask = mask - 1;
        
        return ~num & mask;
    }
};

// Solution 2:
// n = 0* 1 ?* => mask = 1* 0 0*
// result = ~n & ~mask
class Solution {
public:
    int findComplement(int num) {
        int mask = ~0;
        while(mask & num)
            mask <<= 1;
        return ~num & ~mask;
    }
};

// Solution 3: Most optimal one
// n = 0* 1 ?* => mask = 0* 1 1*
// result = n ^ mask = ~n & mask
class Solution {
public:
    int findComplement(int num) {
        int mask = num;
        mask |= (mask >> 1);   // 2
        mask |= (mask >> 2);   // 4
        mask |= (mask >> 4);   // 8
        mask |= (mask >> 8);   // 16
        mask |= (mask >> 16);  // 32
        return num ^ mask;  // or ~num & mask
    }
};
