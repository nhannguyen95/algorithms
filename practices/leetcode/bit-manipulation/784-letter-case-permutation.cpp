// 784. Letter Case Permutation
// https://leetcode.com/problems/letter-case-permutation/description/

// Solution 1: Recursion
// O(2^len(S)) = O(2^12) in time
// O(2^12) in space
class Solution {
public:
    bool isDigit(char c) {
        return '0' <= c && c <= '9';    
    }
    
    bool isLowercase(char c) {
        return 'a' <= c && c <= 'z';
    }
    
    char toggleCase(char c) {
        if (isLowercase(c))
            return c - 'a' + 'A';
        return c - 'A' + 'a';
    }
    
    void generateString(string & S, int i, vector<string> & res) {
        if (i == S.size()) { res.push_back(S); return; }
        if (isDigit(S[i])) { generateString(S, i+1, res); return; }
        
        char oldChar = S[i];
        char newChar = toggleCase(S[i]);
        
        /* Case 1: keep using old character */
        generateString(S, i+1, res);
        
        /* Case 2: use new character */
        // Update
        S[i] = newChar;
        generateString(S, i+1, res);
        
        // Reset
        S[i] = oldChar;   
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        generateString(S, 0, res);
        return res;
    }
};

// Solution 2: Toggling using bit manipulation
// upperCase + 32 = lowerCase
// lowerCase - 32 = upperCase
// 32 = 2^5 = (1 << 5)
// And +- 32 means toggling 5th bit
// Same time and space complexity of #1 solution
class Solution {
public:
    void generateString(string & S, int i, vector<string> & res) {
        if (i == S.size()) { res.push_back(S); return; }
        generateString(S, i + 1, res);
        if (isalpha(S[i])) {
            S[i] ^= (1 << 5);
            generateString(S, i + 1, res);
        }    
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        generateString(S, 0, res);
        return res;
    }
};
