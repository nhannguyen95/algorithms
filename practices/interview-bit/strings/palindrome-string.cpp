bool isLetter(char c) {
    return ('a' <= c && c <= 'z')
        || ('A' <= c && c <= 'Z');
}

bool isDigit(char c) {
    return '0' <= c && c <= '9';
}

char toLowerCase(const char c) {
    if (isDigit(c)) return c;
    if ('a' <= c && c <= 'z') return c;
    return c - 'A' + 'a';
}

int Solution::isPalindrome(string A) {
    int n = (int)A.size();
    int i = 0, j = n - 1;
    while(i < j) {
        while(i < n && (!isLetter(A[i]) && !isDigit(A[i]))) i++;
        while(j > 0 && (!isLetter(A[j]) && !isDigit(A[j]))) j--;
        if (i < n && j > 0 && i < j) {
            if (toLowerCase(A[i]) != toLowerCase(A[j])) {
                return false;
            }
        }
        i++; j--;
    }
    return true;
}
