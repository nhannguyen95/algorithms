// Hashing + 2 pointers
// O(255) in space, O(N) in time
int Solution::lengthOfLongestSubstring(string s) {
    unordered_set<char> chars;
    int ans = 0;
    int low = 0;
    for(int high = 0; high < (int)s.size(); high++) {
        while(chars.find(s[high]) != chars.end()) {
            chars.erase(s[low++]);
        }
        chars.insert(s[high]);
        ans = max(ans, high - low + 1);
    }

    return ans;
}
