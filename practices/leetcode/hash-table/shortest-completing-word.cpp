// Solution 1: hash table

class Solution {
public:
    // Returns true if `small` is subset of `big`.
    // O(size of hash table `small`) in average
    bool isSubset(unordered_map<char, int> & small,
                  unordered_map<char, int> & big) {
        for(unsigned i = 0; i < small.bucket_count(); i++) {
            for(auto it = small.begin(i); it != small.end(i); it++) {
                char c = it->first;
                int freq = it->second;
                if (big.find(c) == big.end() || big[c] < freq)
                    return false;
            }
        }
        return true;
    }
    
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> licenseFreq;
        for(char c : licensePlate) 
            if (isalpha(c)) licenseFreq[tolower(c)]++;
        
        string ans = "";
        for(string & word : words) {
            unordered_map<char, int> wordFreq;
            for(char c : word) wordFreq[c]++;
            
            if (isSubset(licenseFreq, wordFreq)) {
                if (ans.compare("") == 0 || word.size() < ans.size()) {
                    ans = word;
                }
            }
        }
        return ans;
    }
};
