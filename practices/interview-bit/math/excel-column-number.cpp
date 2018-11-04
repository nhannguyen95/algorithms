int Solution::titleToNumber(string A) {
    int dec = 0;
    for(int i = 0; i < (int) A.size(); i ++) {
        dec = 26 * dec + (A[i] - 'A' + 1);
    }
    return dec;
}
