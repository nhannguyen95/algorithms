int mod(long long x, int d) {
    return (x % d + d) % d;
}

int Solution::pow(int x, int n, int d) {
    if (n == 0) return mod(1, d);
    long long t = pow(x, n / 2, d);
    t = mod(t * t, d);
    if (n % 2 == 0) return t;
    return mod(t * x, d);
}
