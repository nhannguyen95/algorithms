int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());
    int ans = INT_MAX;
    for(int i = 1; i < (int)A.size(); i++) {
        ans = min(ans, A[i] ^ A[i - 1]);
    }
    return ans;
}
