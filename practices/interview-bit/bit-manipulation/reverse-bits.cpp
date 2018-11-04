// Solution 1: brute force
int getBit(const unsigned int A, const int i) {
    return (A & (1 << i)) != 0;
}

unsigned int Solution::reverse(unsigned int A) {
    unsigned int ans = 0;
    for(int i = 0; i < sizeof(A) * 8; i++) {
        ans = 2 * ans + getBit(A, i);
    }
    return ans;
}

// Solution 2: using swap function
unsigned int swapBits(unsigned int A, int i, int j) {
    unsigned int lo = ((A >> i) & 1);
    unsigned int hi = ((A >> j) & 1);
    if (lo ^ hi) {  // Swap 2 different bits
        A ^= ((1U << i) | (1U << j));
    }
    return A;
}

unsigned int Solution::reverse(unsigned int A) {
    int n = sizeof(A) * 8;
    for(int i = 0; i < n / 2; i++) {
        A = swapBits(A, i, n - i - 1);
    }
    return A;
}
