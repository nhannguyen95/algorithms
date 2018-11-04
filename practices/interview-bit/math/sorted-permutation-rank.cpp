int Solution::findRank(string A) {
    // Base case
    if (A.size() == 1) return 1;

    int mod = 1000003;

    // Precalculate fac[N] = N!
    vector<int> fac((int)A.size() + 1, 1);
    for(int i = 2; i <= (int)A.size(); i++) {
        fac[i] = (i * fac[i - 1]) % mod;
    }

    // f[i] = number of j such as i < j and A[i] > A[j]
    vector<int> f((int)A.size(), 0);
    for(int i = 0; i < (int)A.size(); i++) {
        for(int j = i + 1; j < (int)A.size(); j++) {
            if (A[j] < A[i]) f[i]++;
        }
    }

    int pre = 1, cur;
    for(int i = (int) A.size() - 2; i >= 0; i--) {
        cur = ((f[i] * fac[(int)A.size() - i - 1]) % mod + pre) % mod;
        pre = cur;
    }
    return pre % mod;
}
