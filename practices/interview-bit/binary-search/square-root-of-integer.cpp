int Solution::sqrt(int A) {
    assert(A >= 0);
    if (A == 0) return 0;
    int low(1), high(A), ans;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if (mid <= A / mid) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
