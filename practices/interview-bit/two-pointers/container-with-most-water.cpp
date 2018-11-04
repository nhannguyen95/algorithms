int Solution::maxArea(vector<int> &A) {
    int n = (int)A.size();

    if (n < 1) return 0;

    long long maxArea = 0;
    int i = 0, j = n - 1;
    while(i < j) {
        maxArea = max(maxArea, (j - i) * 1LL * min(A[i], A[j]));

        if (A[i] > A[j]) j--;
        else i++;
    }

    return maxArea;
}
