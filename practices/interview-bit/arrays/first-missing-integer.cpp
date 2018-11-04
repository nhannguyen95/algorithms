int Solution::firstMissingPositive(vector<int> &A) {
    int n = (int) A.size();

    /* Change negative elements to 0 */
    bool allNegative = true;
    for(int i = 0; i < n; i++) {
        if (A[i] < 0) A[i] = 0;
        else allNegative = false;
    }

    if (allNegative) return 1;

    for(int i = 0; i < n; i++) {
        int v = abs(A[i]);
        if (v == 0 || v > n) continue;  // 1 <= v <= n

        // The value v exists, mark its existence
        // using (v-1) position. So A[i] >= 0 means
        // the value (i+1) doesn't exist in array.
        if (A[v - 1] == 0) {
            A[v - 1] = -n;
        } else if (A[v - 1] > 0) {
            A[v - 1] = -A[v - 1];
        }
    }

    for(int i = 1; i <= n; i++) {
        if (A[i - 1] >= 0) {  // If i doesn't exist in array
            return i;
        }
    }
    return n + 1;
}
