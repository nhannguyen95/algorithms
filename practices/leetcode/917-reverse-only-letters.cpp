// https://leetcode.com/problems/reverse-only-letters/

// Solution 1
class Solution {
public:
    bool isLetter(char c) {
        return ('a' <= c && c <= 'z') ||
               ('A' <= c && c <= 'Z');
    }
    
    string reverseOnlyLetters(string S) {
        int i = 0, j = S.size() - 1;
        while(i < j) {
            while(!isLetter(S[i])) i++;
            while(!isLetter(S[j])) j--;
            if (i >= j) break;
            swap(S[i++], S[j--]);
        }
        return S;
    }
};
