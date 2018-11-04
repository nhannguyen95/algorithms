// O(A) in time
// O(A) in space
vector<int> Solution::getRow(int A) {
    vector<int> ans(A + 1);
    ans[0] = 1;
    for(int i = 1; i <= A; i++) {
        // C(A, i) = C(A, i -1) * (A - i + 1) / i
        ans[i] = (ans[i - 1] * (A - i + 1)) / i;
    }
    return ans;
}
