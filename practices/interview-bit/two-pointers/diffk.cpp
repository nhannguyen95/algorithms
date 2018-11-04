int Solution::diffPossible(vector<int> &A, int k) {
    int n = (int)A.size();

    if (n <= 1) return 0;

    int i = 0, j = 1;
    while(i <= j && i < n && j < n) {
        if (i == j) j++;

        if (A[j] - A[i] == k) return 1;
        else if (A[j] - A[i] > k) i++;
        else j++;
    }

    return 0;
}
