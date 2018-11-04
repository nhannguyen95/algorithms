// O(32N) in time
// O(1) in space
int getBit(int x, int pos) {
    return (x & (1 << pos)) != 0;
}

int Solution::hammingDistance(const vector<int> &A) {
    int ans = 0;
    int mod = 1000000007;
    for(int pos = 0; pos < 31; pos++) {
        int count[2] = {0};
        for(int x : A) {
            count[getBit(x, pos)]++;
        }
        ans += (2LL * count[0] * count[1]) % 1000000007;
        ans %= 1000000007;
    }
    return ans;
}
