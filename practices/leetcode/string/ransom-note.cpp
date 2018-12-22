// https://leetcode.com/problems/ransom-note/

// Solution 1
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> c;
        for(char letter : magazine)
            c[letter]++;
        
        for(char letter : ransomNote) {
            c[letter]--;
            if (c[letter] < 0) return false;
        }
        return true;
    }
};
