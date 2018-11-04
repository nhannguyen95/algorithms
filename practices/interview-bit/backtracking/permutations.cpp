void generatePermute(vector<int> & A, int index, vector<vector<int>> & pers) {
    if (index == (int)A.size()) {
        pers.push_back(A);
    }

    for(int i = index; i < (int)A.size(); i++) {
        swap(A[index], A[i]);
        generatePermute(A, index + 1, pers);
        swap(A[index], A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> pers;
    generatePermute(A, 0, pers);

    return pers;
}
