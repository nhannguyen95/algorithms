int Solution::reverse(int A) {
    if (A == 0) return 0;

    int sign = (A > 0) ? 1 : -1;
    A = abs(A);

    int rev(0), digit;
    while(A > 0) {
        digit = A % 10;
        if (rev > (INT_MAX / 10) || ((rev == INT_MAX / 10) && (digit > INT_MAX % 10))) {
            return 0;
        }
        rev = 10 * rev + digit;
        A /= 10;
    }
    return sign * rev;
}
