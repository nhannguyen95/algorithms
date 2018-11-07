// Solution 1
class Solution {
public:
    // N = len(words)
    // M = max{len(words[i])}
    // K = avg{len(morses[i])}
    // O(N*M*K*(1 + logN)) in time
    // O(N*M*K) in space
    int uniqueMorseRepresentations(vector<string>& words) {
        string morses[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> uniqueCodes;
        for(auto & word : words) {
            string code = "";
            for(auto & letter : word)
                code += morses[letter - 'a'];
            uniqueCodes.insert(code);
        }
        return uniqueCodes.size();
            
    }
};

