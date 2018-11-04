int reverse(int x) {
    int rev(0), digit;
    while(x > 0) {
        digit = x % 10;
        if (rev > (INT_MAX / 10) || (rev == (INT_MAX / 10) && digit > (INT_MAX % 10))) {
            return -1;
        }
        rev = 10 * rev + digit;
        x /= 10;
    }
    return rev;
}

bool Solution::isPalindrome(int A) {
    if (A < 0) return false;

    return A == reverse(A);
}
