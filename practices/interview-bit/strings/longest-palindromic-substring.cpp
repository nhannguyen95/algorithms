// O(N^2) in time
// O(N^2) in space
string Solution::longestPalindrome(string A) {
    // dp[i][j] = true if sub string A[i]..A[j] is palindrome
    vector<vector<bool>> dp(A.size() + 1, vector<bool>(A.size() + 1, false));
    int maxLen = 1;
    for(int len = 1; len <= (int)A.size(); len++) {
        for(int i = 0; i < (int)A.size() - len + 1; i++) {
            int j = i + len - 1;

            if (len == 1) dp[i][j] = true;
            else if (len == 2) dp[i][j] = (A[i] == A[j]);
            else dp[i][j] = (A[i] == A[j] && dp[i + 1][j - 1]);

            if (dp[i][j]) maxLen = max(maxLen, len);
        }
    }

    // Trace the result
    for(int i = 0; i < (int)A.size() - maxLen + 1; i++) {
        int j = i + maxLen - 1;
        if (dp[i][j]) return A.substr(i, maxLen);
    }
}

// Solution 2 with O(N^2) in time and O(N) in space
// The same idea to come up with O(N^2) in time and O(1) in space
string expandAroundCenter(const string & A, int l, int r) {
    while(l >= 0 && r < (int)A.size() && A[l] == A[r]) {
        l--;
        r++;
    }
    return A.substr(l+1,r-l-1);
}

string Solution::longestPalindrome(string A) {
    string longest(A.substr(0, 1));
    for(int i = 0; i < (int)A.size() - 1; i++) {
        string p1 = expandAroundCenter(A, i, i);
        if (p1.size() > longest.size()) {
            longest = p1;
        }

        string p2 = expandAroundCenter(A, i, i + 1);
        if (p2.size() > longest.size()) {
            longest = p2;
        }
    }

    return longest;
}
