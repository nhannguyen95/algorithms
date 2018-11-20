// Solution 1: sorting
class Solution {
public:
    char findTheDifference(string s, string t) {
        assert((s.size() + 1) == t.size());
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        for(int i = 0; i < s.size(); i++)
            if (s[i] != t[i]) return t[i];
        return t.back();
    }
};

// Solution 2: O(N) in time, O(26) in space
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cntChar(26, 0);
        for(char c : s) cntChar[c - 'a']++;
        for(char c : t) cntChar[c - 'a']++;
        for(char i = 0; i < 26; i++)
            if (cntChar[i] % 2 == 1)
                return i + 'a';
    }
};

// Solution 3: bit manipulation, O(1) in space
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        for(char c : s) ans ^= c;
        for(char c : t) ans ^= c;
        return ans;
    }
};
