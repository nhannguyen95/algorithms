int Solution::removeDuplicates(vector<int> &A) {
    int i = 0;
    for(int j = 1; j < (int)A.size(); j++) {
        if (A[j] > A[i]) swap(A[++i], A[j]);
    }
    return i + 1;
}
