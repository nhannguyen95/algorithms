// n = number of elements
// M = number of satisfied combination (maximum is 2^n)
// O(nlogn + M) in time
// O(n + nM) = O(nM) = O(n2^n) in space
void findComb(const vector<int> & C, const int & targetSum, int i,
              int sum, vector<int> & comb, vector<vector<int>> & combs) {

    if (sum == targetSum || i == (int)C.size()) {
        if (sum == targetSum) combs.push_back(comb);
        return;
    }

    int j = i + 1;
    while(j < (int)C.size() && C[i] == C[j]) {
        j++;
    }


    for(int opt = 0; opt <= min(j - i, (targetSum - sum) / C[i]); opt++) {
        for(int k = 0; k < opt; k++) comb.push_back(C[i]);

        findComb(C, targetSum, j, sum + opt*C[i], comb, combs);

        for(int k = 0; k < opt; k++) comb.pop_back();
    }
}

vector<vector<int>> Solution::combinationSum(vector<int> &C, int T) {
    sort(C.begin(), C.end());

    vector<int> comb;
    vector<vector<int>> combs;
    findComb(C, T, 0, 0, comb, combs);

    return combs;
}
