int Solution::removeDuplicates(vector<int> &A) {
    int n = (int)A.size();
    int i = 0, cnt = 0;
    for(int j = 0; j < n; j++) {
        cnt++;
        if (j == n - 1 || A[j] != A[j + 1]) {
            A[i++] = A[j];
            if (cnt >= 2) A[i++] = A[j];
            cnt = 0;
        }
    }
    return i;
}
