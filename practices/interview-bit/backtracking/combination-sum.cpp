// Solution 1
void generateComb(const vector<int> & C, const int & T, int index, int sum, vector<int> & comb, vector<vector<int>> & combs) {
    if (index == (int)C.size() || sum == T) {
        if (sum == T) {
            combs.push_back(comb);
        }
        return;
    }

    // Instead of for i = 0 .. sup, let i decrease.
    // The backtracking algorithm will generate the combination
    // with the appearance of the smallest elements first.
    // Then the combinations are sorted in ascending order.
    for(int i = (T - sum) / C[index]; i >= 0 ; i--) {
        for(int j = 0; j < i; j++) comb.push_back(C[index]);
        generateComb(C, T, index + 1, sum + i*C[index], comb, combs);
        for(int j = 0; j < i; j++) comb.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &C, int T) {
    sort(C.begin(), C.end());
    C.resize(unique(C.begin(), C.end()) - C.begin());

    vector<int> comb;
    vector<vector<int>> combs;
    generateComb(C, T, 0, 0, comb, combs);

    // sort(combs.begin(), combs.end());
    return combs;
}

// Solution 2
void generateComb(const vector<int> & C, const int T, int index, int sum, vector<int> & comb, vector<vector<int>> & combs) {
    if (sum > T) {
        return;
    }

    if (sum == T) {
        combs.push_back(comb);
        return;
    }

    for(int i = index; i < (int)C.size(); i++) {
        comb.push_back(C[i]);
        generateComb(C, T, i, sum + C[i], comb, combs);
        comb.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &C, int T) {
    sort(C.begin(), C.end());
    C.resize(unique(C.begin(), C.end()) - C.begin());

    vector<int> comb;
    vector<vector<int>> combs;
    generateComb(C, T, 0, 0, comb, combs);
    return combs;
}
