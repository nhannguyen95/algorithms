int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int sizeA = (int)A.size();
    int sizeB = (int)B.size();
    int sizeC = (int)C.size();
    int i = 0, j = 0, k = 0;
    int ans = INT_MAX;
    while(i < sizeA && j < sizeB && k < sizeC) {
        int mn = min(A[i], min(B[j], C[k]));
        int mx = max(A[i], max(B[j], C[k]));
        ans = min(ans, mx - mn);
        
        if (mn == A[i]) i++;
        else if (mn == B[j]) j++;
        else k++;
    }
    return ans;
}
