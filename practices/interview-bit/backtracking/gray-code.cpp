// Solution 1: inefficient one
int binToDec(const string bin) {
    int dec = 0;
    for(char c : bin)
        dec = 2 * dec + (c - '0');
    return dec;
}

void generateCode(string & bin, set<int> & used, vector<int> & ans) {
    for(int i = 0; i < (int)bin.size(); i++) {
        // Try to change one bit at 'i'
        bin[i] = '0' + '1' - bin[i];
        int dec = binToDec(bin);

        // If changed number hasn't appeared before,
        // add it to result
        if (used.find(dec) == used.end()) {
            used.insert(dec);
            ans.push_back(dec);
            generateCode(bin, used, ans);  // Continue generating next number from this
            return;
        }

        bin[i] = '0' + '1' - bin[i];
    }
}

vector<int> Solution::grayCode(int n) {
    string bin(n, '0');
    vector<int> ans({0});
    set<int> used({0});
    generateCode(bin, used, ans);
    return ans;
}

// Solution 2: mirroring
vector<int> Solution::grayCode(int n) {
    if (n == 0) return vector<int>();

    vector<int> ans(1, 0);
    for(int i = 0; i < n; i++) {
        for(int j = ans.size() - 1; j >= 0; j--) {
            ans.push_back(ans[j] + (1 << i));
        }
    }
    return ans;
}
