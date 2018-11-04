// O(1) in space, O(N) in time
// Find [L, R] such as minimize 0(s) - 1(s) in [L, R]
// Replace 1 with -1 -> find maximum subarray.
vector<int> Solution::flip(string A) {
    int n = (int)A.size();
    assert(n > 0);

    int sum = 0;
    int maxSum = 0;
    int left = 0, right = 0;
    int i = 0;
    for(int j = 0; j < n; j++) {
        if (A[j] == '0') sum++;
        else sum--;

        if (sum > maxSum) {
            maxSum = sum;
            left = i;
            right = j;
        }

        if (sum < 0) {
            sum = 0;
            i = j + 1;
        }
    }

    if (maxSum == 0) return vector<int>();
    return vector<int>({left + 1, right + 1});
}

// O(1) in space, O(N^2) in time
vector<int> Solution::flip(string A) {
    int n = (int)A.size();
    assert(n > 0);

    vector<int> countOnes(n, 0);
    for(int i = 0; i < n; i++) {
        countOnes[i] = countOnes[i - 1] + (A[i] - '0');
    }

    vector<int> ans;
    int maxOnes = 0;
    for(int l = 0; l < n; l++) {
        for(int r = l; r < n; r++) {
            // Flip [l, r]
            int leftOnes = (l > 0) ? countOnes[l - 1] : 0;
            int rightOnes = countOnes[n - 1] - countOnes[r];
            int midZeros = (r - l + 1) - (countOnes[r] - leftOnes);

            int totalOnes = leftOnes + midZeros + rightOnes;
            if (totalOnes > countOnes[n - 1] && totalOnes > maxOnes) {
                maxOnes = totalOnes;
                if (ans.empty()) {
                    ans.resize(2);
                }
                ans[0] = l + 1;
                ans[1] = r + 1;
            }
        }
    }
    return ans;
}
