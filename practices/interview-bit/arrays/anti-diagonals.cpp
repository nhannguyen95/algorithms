// O(N^2) in time
// O(N^2) in space
bool isBetween(int x, int left, int right) {
    return (left <= x) && (x <= right);
}

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = (int) A.size();
    assert(n > 0);
    assert(n == A[0].size());

    vector<pair<int, int>> diags;
    for(int col = 0; col < n; col++) {
        diags.push_back(make_pair(0, col));
    }
    for(int row = 1; row < n; row++) {
        diags.push_back(make_pair(row, n - 1));
    }

    vector<vector<int>> ans;
    for(int i = 0; i < diags.size(); i++) {
        int row = diags[i].first;
        int col = diags[i].second;
        vector<int> diag;
        while(isBetween(row, 0, n - 1) && isBetween(col, 0, n - 1)) {
            diag.push_back(A[row++][col--]);
        }
        ans.push_back(diag);
    }

    return ans;
}
