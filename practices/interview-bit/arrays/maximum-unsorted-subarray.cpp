// O(N) in time
// O(1) in space
vector<int> Solution::subUnsort(vector<int> &A) {
    // Base case
    int n = (int) A.size();
    if (n <= 1) return vector<int>({-1});

    /* Find min and max of the subsequence unsorted array */
    int i = 0;
    while(i < n - 1 && A[i] <= A[i + 1]) i++;

    int j = n - 1;
    while(j > 0 && A[j - 1] <= A[j]) j--;

    if (i == n - 1) {  // The array is already sorted
        return vector<int>({-1});
    }

    // Min and max are in [i, j]
    int mn = A[i], mx = A[i];
    for(int k = i + 1; k <= j; k++) {
        mn = min(mn, A[k]);
        mx = max(mx, A[k]);
    }

    /* Find the minimum subsequence unsorted array */
    // Let A = B + C + D, C = finding array.
    // B, D is increasing
    // max(B) <= min(C)
    // min(D) >= max(C)
    int l = 0;
    while(l <= i && A[l] <= mn) l++;

    int r = n - 1;
    while(r >= j && A[r] >= mx) r--;

    if (l > r) return vector<int>({-1});
    return vector<int>({l, r});
}
