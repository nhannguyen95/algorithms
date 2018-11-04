// O(A^2) in time
// O(A^2) in space
vector<vector<int> > Solution::generate(int A) {
    vector<vector<int>> ans;

    if (A == 0) return ans;

    for(int i = 0; i < A; i++) {
        vector<int> row(i + 1);
        ans.push_back(row);

        for(int j = 1; j < i; j++) {
            ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
        }
        ans[i][0] = ans[i][i] = 1;
    }

    return ans;
}
