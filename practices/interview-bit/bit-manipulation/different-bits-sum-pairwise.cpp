int Solution::cntBits(vector<int> &A) {
    long long ans = 0;
    int MOD = 1e9 + 7;
    for(int i = 0; i < 32; i++) {
        int cnt[2] = {0};
        for(int x : A) {
            cnt[(x & (1 << i)) != 0]++;
        }
        ans = (ans + (cnt[0] * 1LL * cnt[1]) % MOD) % MOD;
    }
    return (2 * ans) % MOD;
}
