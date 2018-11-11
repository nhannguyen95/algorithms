// https://leetcode.com/problems/goat-latin/

// Solution 1: string manipulation
class Solution {
public:
    
    vector<string> split(const string & s, const string delim) {
        vector<string> tokens;
        size_t i;
        for(size_t p = 0; (p = s.find(delim, i)) != s.npos;) {
            string token = s.substr(i, p-i);
            if (token.compare("")) {
                cout << token << '\n';
                tokens.push_back(token);
            }
            i = p + delim.size();
        }
        if (i < s.size()) tokens.push_back(s.substr(i));
        return tokens;
    }
    
    bool isVowel(char c) {
        unordered_set<char> vowels({'a','e','i','o','u','A','E','I','O','U'});
        return vowels.find(c) != vowels.end();
    }
    
    string toGoatLatin(string S) {
        string goatLatin = "";
        string suffix = "a";
        for(string word : split(S, " ")) {
            goatLatin += ' ';
            if (isVowel(word[0]))
                goatLatin += word + "ma";
            else {
                word += word[0];
                goatLatin += word.substr(1) + "ma";
            }
            
            goatLatin += suffix;
            suffix += 'a';
        }
        return goatLatin.substr(1);
    }
};
