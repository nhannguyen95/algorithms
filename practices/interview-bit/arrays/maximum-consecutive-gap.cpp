// O(N) in space
// O(N) in time
int Solution::maximumGap(const vector<int> &A) {
    int n = (int) A.size();
    if (n < 2) return 0;

    int mn = *min_element(A.begin(), A.end());
    int mx = *max_element(A.begin(), A.end());

    int gap = (mx - mn - 1) / (n - 1) + 1;

    vector<int> bucketsMin(n - 1, INT_MAX);
    vector<int> bucketsMax(n - 1, INT_MIN);
    for(int i = 0; i < n; i++) {
        if (A[i] != mn && A[i] != mx) {
            int bucketId = (A[i] - mn) / gap;
            bucketsMin[bucketId] = min(bucketsMin[bucketId], A[i]);
            bucketsMax[bucketId] = max(bucketsMax[bucketId], A[i]);
        }
    }

    int maxGap = INT_MIN;
    int previous = mn;
    for(int i = 0; i < n - 1; i++) {
        if (bucketsMin[i] == INT_MAX && bucketsMax[i] == INT_MIN) {
            continue;
        }
        maxGap = max(maxGap, bucketsMin[i] - previous);
        previous = bucketsMax[i];
    }
    maxGap = max(maxGap, mx - previous);
    return maxGap;
}
