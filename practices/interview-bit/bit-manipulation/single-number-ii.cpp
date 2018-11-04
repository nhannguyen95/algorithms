// Approach 0
int Solution::singleNumber(const vector<int> &A) {

    assert(A.size() > 0);

    int ans = 0;
    for(int i = sizeof(A) * 8; i >= 0; i--) {
        int cntBits[2] = {0};
        for(int x : A) {
            cntBits[(x >> i) & 1]++;
        }
        // Determine the i-th bit of the answer
        ans = ans * 2;
        if (cntBits[1] > 0 && ((cntBits[1] - 1) % 3 == 0))
            ans++;
    }

    return ans;
}

// Approach 1
int Solution::singleNumber(const vector<int> &A) {

    assert(A.size() > 0);

    int ans = 0;
    int count[32] = {0};
    for(int i = 0; i < 32; i++) {
        for(int x : A) {
            if ((x >> i) & 1)
                count[i]++;
        }

        ans |= (count[i] % 3) << i;
    }
    return ans;
}

// Approach 2
// ones as a bitmask to represent the ith bit had appeared once.
// twos as a bitmask to represent the ith bit had appeared twice.
// threes as a bitmask to represent the ith bit had appeared three times.
// When the ith bit had appeared for the third time, clear the ith bit of both ones and twos to 0. The final answer will be the value of ones.
int Solution::singleNumber(const vector<int> &A) {

    assert(A.size() > 0);

    int ones = 0, twos = 0, threes = 0;
    for(int x : A) {
        twos |= ones & x;
        ones ^= x;
        threes = ones & twos;
        ones &= ~threes;
        twos &= ~threes;
    }
    return ones;
}
