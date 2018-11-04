bool Solution::isPower(int X) {
    if (X <= 0) return false;
    if (X == 1) return true;
    // X = A^B?
    for(int x = 2; x <= sqrt(A); x++) {
        int t = x;
        while(1) {
            if (t == A) return true;
            if (t > A / x) break;
            t *= x;
        }
    }
    return false;
}
