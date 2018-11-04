// O(C(n,k)) in time
// O(kC(n,k)) in space
void generateCombs(const int & n, const int & k, int index, vector<int> & comb, vector<vector<int>> & combs) {
    if ((int)comb.size() == k) {
        combs.push_back(comb);
        return;
    }

    for(int i = index; i <= n; i++) {
        comb.push_back(i);

        generateCombs(n, k, i+1, comb, combs);

        comb.pop_back();
    }
}

vector<vector<int> > Solution::combine(int n, int k) {
    vector<int> comb;
    vector<vector<int>> combs;
    generateCombs(n, k, 1, comb, combs);
    return combs;

}
