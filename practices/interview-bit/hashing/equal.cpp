// Solution 1: Using hash table
// Partially accepted
// O(N^3) in time
// O(N) in space
void updateResult(vector<int> & ans, int a1, int b1, int c1, int d1) {
    vector<int> newAns({a1, b1, c1, d1});
    if (ans.empty() || ans > newAns) {
        ans = newAns;
    }
}

vector<int> Solution::equal(vector<int> &A) {
    vector<int> ans;
    unordered_map<int, int> M;  // M[v] = lowest id such that A[id] = v
    for(int i = 0; i < (int)A.size()-2; i++) {
        for(int j = i+1; j < (int)A.size()-1; j++) {
            for(int k = j+1; k < (int)A.size(); k++) {
                int AA1, A1;
                // If B1 is i: A[A1] = A[j] + A[k] - A[i]
                AA1 = A[j] + A[k] - A[i];
                if (M.find(AA1) != M.end()) {
                    updateResult(ans, M[AA1], i, j, k);
                }

                // If B1 is j: A[A1] = A[i] + A[k] - A[j]
                AA1 = A[i] + A[k] - A[j];
                if (M.find(AA1) != M.end()) {
                    updateResult(ans, M[AA1], j, i, k);
                }

                // If B1 is k: A[A1] = A[i] + A[j] - A[k]
                AA1 = A[i] + A[j] - A[k];
                if (M.find(AA1) != M.end()) {
                    updateResult(ans, M[AA1], k, i, j);
                }
            }
        }

        if (M.find(A[i]) == M.end()) M[A[i]] = i;
    }
    return ans;
}

// Solution 2
// O(N^2) in time
// O(N^2) in space

// Return true if p1 < p2
bool ltPair(const pair<int, int> p1, const pair<int, int> p2) {
    return (p1.first < p2.first) ||
           ((p1.first == p2.first) && (p1.second < p2.second));
}

void updateMap(unordered_map<long long, pair<int, int>> & M, const long long sum, int i, int j) {
    pair<int, int> newPair(i, j);

    if (M.find(sum) == M.end()) {
        M[sum] = newPair;
        return;
    }

    pair<int, int> oldPair = M[sum];
    if (ltPair(newPair, oldPair)) {  // newPair < oldPair
        M[sum] = newPair;
    }
}

bool updateAnswer(vector<int> & ans, int a1, int b1, int c1, int d1) {
    // Invalid
    if (!(a1<b1 && c1<d1 && a1<c1 && b1!=c1 && b1!=d1)) return false;

    vector<int> newAnswer({a1, b1, c1, d1});
    if (ans.empty() || ans > newAnswer) {
        ans = newAnswer;
        return true;
    }

    return false;
}

vector<int> Solution::equal(vector<int> &A) {
    vector<int> ans;
    unordered_map<long long, pair<int, int>> M;
    // M[sum] = lowest (i,j) such that A[i]+A[j]=sum
    for(int i = 0; i < (int)A.size()-1; i++) {
        for(int j = i+1; j < (int)A.size(); j++) {
            long long sum = A[i]*1LL + A[j];
            if (M.find(sum) != M.end()) {
                // Try to think about why M[sum] = (a1, b1), (i, j) = (c1, d1)
                // It's brilliant!
                updateAnswer(ans, M[sum].first, M[sum].second, i, j);
            }

            updateMap(M, sum, i, j);
        }
    }
    return ans;
}
