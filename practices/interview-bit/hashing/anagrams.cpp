int getHashKey(unordered_map<string, int> & hash, string word) {
    sort(word.begin(), word.end());
    if (hash.find(word) != hash.end()) {
        return hash[word];
    }
    int size = hash.size();
    return hash[word] = size;
}

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int>> ans;
    unordered_map<string, int> hash;  // anagrams have the same hash key, key = sort(anagram).
                                      // The associated value of the key is the anagrams group id
                                      // in 'ans'.
    for(int i = 0; i < (int)A.size(); i++) {
        int groupId = getHashKey(hash, A[i]);
        if (groupId < (int)ans.size()) {
            ans[groupId].push_back(i+1);
        } else {
            ans.push_back(vector<int>({i+1}));
        }
    }

    return ans;
}
