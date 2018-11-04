// O(N^2) in time
int Solution::threeSumClosest(vector<int> &S, int target) {
    sort(S.begin(), S.end());

    int minDiff = INT_MAX, ans;
    for(int i = 0; i < (int)S.size() - 2; i++) {
        // S[j] + S[k] closest to target - S[i]
        int j = i + 1, k = (int)S.size() - 1;
        while(j < k) {
            int curDiff = abs(S[i] + S[j] + S[k] - target);
            int sum = S[j] + S[k];

            if (curDiff < minDiff) {
                minDiff = curDiff;
                ans = sum + S[i];
            }

            if (sum > target - S[i]) k--;
            else j++;
        }
    }
    return ans;
}
