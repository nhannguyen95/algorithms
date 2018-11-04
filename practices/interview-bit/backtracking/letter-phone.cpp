vector<string> cs({"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});

void generateComb(const string & A, int index, string & comb, vector<string> & combs) {
    if (index == (int)A.size()) {
        combs.push_back(comb);
        return;
    }

    for(char c : cs[A[index] - '0']) {
        comb.push_back(c);
        generateComb(A, index + 1, comb, combs);
        comb.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A) {
    string comb = "";
    vector<string> combs;
    generateComb(A, 0, comb, combs);

    return combs;
}
