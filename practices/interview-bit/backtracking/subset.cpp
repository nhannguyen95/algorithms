void generateSubset(const vector<int> & A, int index, vector<int> & subset, vector<vector<int>> & subsets) {
    if (index == (int)A.size()) {
        subsets.push_back(subset);
        return;
    }

    subset.push_back(A[index]);
    generateSubset(A, index + 1, subset, subsets);
    subset.pop_back();

    generateSubset(A, index + 1, subset, subsets);
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());

    vector<int> subset;
    vector<vector<int>> subsets;
    generateSubset(A, 0, subset, subsets);

    sort(subsets.begin(), subsets.end());
    return subsets;
}
