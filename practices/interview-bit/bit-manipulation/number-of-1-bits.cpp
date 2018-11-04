// Solution 1: brute force
int getBit(const unsigned int & x, const int pos) {
    return (x & (1 << pos)) != 0;
}

int Solution::numSetBits(unsigned int A) {
    int countBit1 = 0;
    for(int i = 0; i < 32; i++) {
        if (getBit(A, i) == 1) {
            countBit1++;
        }
    }
    return countBit1;
}

// Solution 2: (x-1) bit manipulation trick
//  x      ~ ...100
// (x - 1) ~ ...011
int Solution::numSetBits(unsigned int x) {
    int countBit1 = 0;
    while(x != 0) {
        x = x & (x - 1);
        countBit1++;
    }
    return countBit1;
}
