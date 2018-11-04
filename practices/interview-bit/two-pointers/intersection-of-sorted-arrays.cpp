vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int i = 0, j = 0;
    vector<int> dups;
    while(i < (int)A.size() && j < (int)B.size()) {
        if (A[i] == B[j]) {
            dups.push_back(A[i]);
            i++; j++;
        } else if (A[i] > B[j]) {
            j++;
        } else {
            i++;
        }
    }
    return dups;
}
