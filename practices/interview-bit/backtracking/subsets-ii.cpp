/* Solution 1: Using a set (built in data structure) to avoid duplicate

TIME COMPLEXITY:
- Sorting all elements takes O(nlogn)
- M = number of subsets, maximum is 2^n (n = number of elements)
- Inserting each subset into set takes O(logM)
- Iterating the set takes O(M)
- Time complexity = O(nlogn + MlogM + M) = O(nlogn + MlogM)
                  = O(nlogn + 2^nlog2^n) = O(n * logn + n * 2^n * log2)
                  = O(n * logn + n * 2^n) = O(n(logn + 2^n))

SPACE COMPLEXITY:
- Deepest depth of recursive call = n, need O(n) to store the current generated subset
- Need O(nM) to store all subsets
- Space complexity = O(nM + n) = O(n2^n + n) = O(n2^n)
*/

void generateSubset(const vector<int> & A, int i, vector<int> & subset, set<vector<int>> & subsets) {
    if (i == (int)A.size()) {
        subsets.insert(subset);
        return;
    }

    for(int opt = 0; opt <= 1; opt++) {
        if (opt == 1) subset.push_back(A[i]);

        generateSubset(A, i + 1, subset, subsets);

        if (opt == 1) subset.pop_back();
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(), A.end());

    vector<int> subset;
    set<vector<int>> subsets;
    generateSubset(A, 0, subset, subsets);

    vector<vector<int>> ans;
    for(vector<int> subset : subsets) {
        ans.push_back(subset);
    }
    return ans;
}

/* Solution 2: avoid duplicate by controlling the repeated number of each elements

TIME and SPACE COMPLEXITY: same as Solution 1

*/
void generateSubset(const vector<int> & A, int i, vector<int> & subset, vector<vector<int>> & subsets) {
    if (i == (int)A.size()) {
        subsets.push_back(subset);
        return;
    }

    int j = i + 1;
    while(j < (int)A.size() && A[j] == A[i]) {
        j++;
    }

    for(int opt = 0; opt <= (j - i); opt++) {
        for(int k = 0; k < opt; k++) subset.push_back(A[i]);

        generateSubset(A, j, subset, subsets);

        for(int k = 0; k < opt; k++) subset.pop_back();
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(), A.end());

    vector<int> subset;
    vector<vector<int>> subsets;
    generateSubset(A, 0, subset, subsets);

    sort(subsets.begin(), subsets.end());
    return subsets;
}
