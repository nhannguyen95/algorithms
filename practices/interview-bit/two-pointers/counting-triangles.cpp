// O(N^2) in time
// O(1) in space
int Solution::nTriang(vector<int> &A) {
    sort(A.rbegin(), A.rend());
    int ans = 0;
    int MOD = 1e9 + 7;
    for(int i = 0; i < (int)A.size() - 2; i++) {
        // Count A[j] + A[k] > A[i]
        int j = i + 1;
        int k = (int)A.size() - 1;
        while(j < k) {
            int sum = A[j] + A[k];
            if (sum <= A[i]) k--;
            else {
                ans = (ans + (k - j)) % MOD;
                j++;
            }
        }
    }
    return ans;
}
