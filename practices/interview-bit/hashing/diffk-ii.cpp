// N = A.size()

// Solution 1: Brute force
// O(1) in space, O(N^2) in time
int Solution::diffPossible(const vector<int> &A, int k) {
    for(int i = 0; i < (int)A.size()-1; i++) {
        for(int j = i+1; j < (int)A.size(); j++) {
            if (abs(A[j] - A[i]) == k) {
                return 1;
            }
        }
    }
    return 0;
}

// Solution 2: Sorting and binary search
// O(1) if sorting in place, O(N) otherwise in space
// O(NlogN) in time
int Solution::diffPossible(const vector<int> &A, int k) {
    vector<int> B(A);
    sort(B.begin(), B.end());
    for(int i = 1; i < (int)B.size(); i++) {
        if (binary_search(B.begin(), B.begin()+i, B[i]-k)) {
            return 1;
        }
    }
    return 0;
}

// Solution 3: Using hash table
// O(N) in space, O(N) in time

int Solution::diffPossible(const vector<int> &A, int k) {
    unordered_set<int> comp;
    for(int x : A) {
        if (comp.find(x - k) != comp.end() || comp.find(x + k) != comp.end()) {
            return 1;
        }
        comp.insert(x);
    }
    return 0;
}
