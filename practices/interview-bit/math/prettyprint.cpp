vector<vector<int> > Solution::prettyPrint(int A) {
    if (A <= 0) return vector<vector<int>>();

    int size = 2*A - 1;
    vector<vector<int>> ans(size, vector<int>(size, 0));
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            int minGapVer = min(i, size - i - 1);
            int minGapHor = min(j, size - j - 1);
            int minGap = min(minGapVer, minGapHor);
            ans[i][j] = A - minGap;
        }
    }

    return ans;
}
