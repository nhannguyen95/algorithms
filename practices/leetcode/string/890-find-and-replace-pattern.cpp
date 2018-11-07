// https://leetcode.com/problems/find-and-replace-pattern/

// Solution 1: 2 maps
// N = len(words)
// M = max length of words
// O(N * M) in time
// O(N * M + M) in space
class Solution {
public:
    int isMatch(const string & word, const string & pattern) {
        if (word.size() != pattern.size()) return 0;
        
        unordered_map<char, char> mapTo;    // mapTo[a] = b: a maps to b
        unordered_map<char, char> mapFrom;  // mapFrom[b] = a: b is mapped from a
        for(int i = 0; i < word.size(); i++) {
            char w = word[i];
            char p = pattern[i];
            
            // Check if a maps to 2 different values.
            if (mapTo.find(w) != mapTo.end() && mapTo[w] != p)
                return false;
            
            // Check if b is mapped from 2 different values.
            if (mapFrom.find(p) != mapFrom.end() && mapFrom[p] != w)
                return false;
            
            mapTo[w] = p;
            mapFrom[p] = w;
        }
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto & word : words)
            if (isMatch(word, pattern))
                ans.push_back(word);
        return ans;
    }
};

// Solution 2: 1 map
// mapTo: a -> b, c -> b
// post processor: ensure there's no a -> x, b -> y such that x == y
