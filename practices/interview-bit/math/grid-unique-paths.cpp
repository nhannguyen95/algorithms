int Solution::uniquePaths(int A, int B) {
    // The result is C(A + B - 2, A - 1) = C(A + B - 2, B - 1)
    // = A * (A + 1) * .. * (A + B - 1) / (B - 1)!
    if (A == 1 || B == 1) return 1;

    int ans = 1;
    for(int i = 1; i < B; i++) {
        ans *= (A + i - 1);
        ans /= i;
    }
    return ans;
}
