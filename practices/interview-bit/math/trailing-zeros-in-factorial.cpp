int Solution::trailingZeroes(int A) {
    int cnt5 = 0;
    for(int i = 1; i <= A; i++) {
        int num = i;
        while(num > 0 && num % 5 == 0) {
            cnt5++;
            num /= 5;
        }
    }
    return cnt5;
}
