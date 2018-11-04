// Solution 1: dynamic programming
// O(N) in time
// O(N) in space
int Solution::trap(const vector<int> &A) {
    int n = (int)A.size();
    if (n <= 2) return 0;

    vector<int> maxLeft(n);
    maxLeft[0] = INT_MIN;
    for(int i = 1; i < n; i++)
        maxLeft[i] = max(A[i - 1], maxLeft[i - 1]);

    vector<int> maxRight(n);
    maxRight[n - 1] = INT_MIN;
    for(int i = n - 2; i >= 0; i--)
        maxRight[i] = max(A[i + 1], maxRight[i + 1]);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int minBoth = min(maxLeft[i], maxRight[i]);
        if (minBoth > A[i]) ans += (minBoth - A[i]);
    }
    return ans;
}

// Solution 2: two pointers
// O(N) in time
// O(1) in space
int Solution::trap(const vector<int> &A) {
    int left = 0, right = (int)A.size() - 1;
    int maxLeft = 0, maxRight = 0;
    int ans = 0;
    while(left <= right) {
        if (A[left] <= A[right]) {
            if (A[left] > maxLeft) maxLeft = A[left];
            else ans += (maxLeft - A[left]);  // Because we move the lower-value pointer,
                                              // and the 'max...' is only updated after that,
                                              // maxLeft is always < A[right]
            left++;
        } else {
            if (A[right] > maxRight) maxRight = A[right];
            else ans += (maxRight - A[right]);
            right--;
        }
    }

    return ans;
}
