// Solution 1
class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt[2] = {0, 0};
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j <= 1; j++)  {
                char c = '0' + j;
                char d = '0' + (1 - j);
                if (s[i] == c) {
                    if (i > 0 && s[i-1] == d) cnt[j] = 1;
                    else cnt[j]++;
                } else {
                    if (cnt[j] > 0) {
                        ans++;
                        cnt[j]--;
                    }
                }
            }
        }
        return ans;
    }
};

// Solution 2
class Solution {
public:
    int countBinarySubstrings(string s) {
        int pre(0), cur(1), ans(0);
        for(int i = 1; i < s.size(); i++) {
            if (s[i-1] != s[i]) {
                ans += min(pre, cur);
                pre = cur;
                cur = 1;
            } else {
                cur++;
            }
        }
        return ans + min(pre, cur);
    }
};
