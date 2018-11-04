// O(NlogN) in time, O(1) in space
vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(), A.end());
    for(int i = 1; i < (int) A.size(); i += 2) {
        swap(A[i - 1], A[i]);
    }
    return A;
}
