bool check(const vector<string> & L, unordered_map<string, int> & CWORDS, unordered_map<string, int> & cWords) {
    for(string word : L) {
        if (CWORDS[word] != cWords[word]) {
            return false;
        }
    }
    return true;
}

vector<int> Solution::findSubstring(string S, const vector<string> &L) {
    // Base cases: return an empty list
    if (S == "" || L.size() == 0) return vector<int>();

    // Count the occurences of words
    unordered_map<string, int> CWORDS;
    for(auto word : L) CWORDS[word]++;

    vector<int> ans;
    int nWord = L[0].size();
    int allChars = L.size() * nWord;
    for(int i = 0; i < (int)S.size() - allChars + 1; i++) {
        unordered_map<string, int> cWords;
        bool ok = true;
        // Check if [i..i+alChars-1] forms a concatenation
        for(int j = i; (j-i)/nWord < (int)L.size(); j += nWord) {
            string word = S.substr(j, nWord);
            cWords[word]++;
            if (cWords[word] > CWORDS[word]) {
                ok = false;
                break;
            }
        }
        if (ok && check(L, CWORDS, cWords)) {
            ans.push_back(i);
        }
    }
    return ans;
}
