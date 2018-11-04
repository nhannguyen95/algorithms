// Solution 1: Brute force
// O(1) in space, O(N^2) in time
vector<int> Solution::twoSum(const vector<int> &A, int target) {
    for(int i = 1; i < (int)A.size(); i++) {
        for(int j = 0; j < i; j++) {
            if (A[i] + A[j] == target) {
                return vector<int>({j+1, i+1});
            }
        }
    }
    return vector<int>();
}

// Solution 2: Hash table
// O(N) in space, O(N) in time
vector<int> Solution::twoSum(const vector<int> &A, int target) {
    unordered_map<int, int> v2i;  // v2i[v] = lowest i such that A[i] = v
    for(int i = 0; i < (int)A.size(); i++) {
        int pre = target - A[i];
        if (v2i.find(pre) != v2i.end()) {
            return vector<int>({v2i[pre]+1, i+1});
        }

        if (v2i.find(A[i]) == v2i.end()) {
            v2i[A[i]] = i;
        }
    }
    return vector<int>();
}
