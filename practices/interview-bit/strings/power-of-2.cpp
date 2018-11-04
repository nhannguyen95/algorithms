string divideByTwo(const string & A) {
    string ans = "";
    int lend = 0;
    for(int i = 0; i < (int)A.size(); i++) {
        int sum = (A[i] - '0') + lend;
        lend = 0;
        if (sum % 2 != 0) {
            sum--;
            lend = 10;
        }

        if (sum == 0 && ans.size() == 0) continue;
        ans.push_back((sum / 2) + '0');
    }
    return ans;
}

int Solution::power(string A) {
    if (A.back() == '1') return 0;

    while(A.size() >= 2) {
        if ((A.back() - '0') % 2 == 1) return 0;
        A = divideByTwo(A);
    }
    return A.back() == '1' || A.back() == '2'
        || A.back() == '4' || A.back() == '8';
}
