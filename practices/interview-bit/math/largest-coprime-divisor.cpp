int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int Solution::cpFact(int A, int B) {
    while(gcd(A, B) != 1) {
        A /= gcd(A, B);
    }
    return A;
}
