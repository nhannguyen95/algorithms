int Solution::atoi(const string &A) {
    int sign = 1, i = 0;
    while(A[i] == ' ') i++;
    if (A[i] == '-' || A[i] == '+') {
        sign = (A[i++] == '-') ? -1 : 1;
    }

    int ans = 0;
    while(A[i] >= '0' && A[i] <= '9') {
        int digit = A[i++] - '0';

        // Overflow
        if ((ans > INT_MAX / 10) || (ans == INT_MAX / 10 && digit > 7)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        ans = ans * 10 + digit;
    }
    return sign * ans;
}
