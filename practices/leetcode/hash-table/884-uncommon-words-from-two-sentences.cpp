// Solution 1
class Solution {
public:
    vector<string> split(string & s, string delim = " ") {
        vector<string> tokens;
        size_t i = 0;
        for(size_t p = 0; (p = s.find(delim, i)) != s.npos;) {
            string token = s.substr(i, p - i);
            if (token != "")
                tokens.push_back(token);
            i = p + delim.size();
        }
        if (i < s.size()) tokens.push_back(s.substr(i)); 
        return tokens;
    }
    
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> cntWord;
        for(auto & word : split(A, " ")) {
            cntWord[word]++;
        }
        for(auto & word : split(B, " ")) {
            cntWord[word]++;
        }
        
        vector<string> ans;
        for(auto it = cntWord.begin(); it != cntWord.end(); it++)
            if (cntWord[it->first] == 1) ans.push_back(it->first);
        return ans;
    }
};
