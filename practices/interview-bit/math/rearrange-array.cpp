// O(1) in time
void Solution::arrange(vector<int> &A) {
    int n = (int) A.size();
    for(int i = 0; i < n; i++) {
        int encodeBaseN = A[A[i]];
        int oldValue = encodeBaseN % n;
        A[i] = oldValue * n + A[i];
    }
    for(int i = 0; i < n; i++) {
        A[i] /= n;
    }
}
