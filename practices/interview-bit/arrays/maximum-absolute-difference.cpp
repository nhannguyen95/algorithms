// O(1) in space
int Solution::maxArr(vector<int> &A) {
    int n = (int) A.size();

    int min1 = INT_MAX, max1 = INT_MIN;  // A[i] + i
    int min2 = INT_MAX, max2 = INT_MIN;  // A[i] - i

    for(int i = 0; i < n; i++) {
        min1 = min(min1, A[i] + i + 1);
        max1 = max(max1, A[i] + i + 1);
        min2 = min(min2, A[i] - i - 1);
        max2 = max(max2, A[i] - i - 1);
    }

    return max(max1 - min1, max2 - min2);
}
