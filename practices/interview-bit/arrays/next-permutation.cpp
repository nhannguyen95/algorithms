// O(size(A)) in time
// O(1) in space
void Solution::nextPermutation(vector<int> &A) {
    if (A.size() <= 1) return;

    for(int i = (int) A.size() - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            for(int j = (int) A.size() - 1; j > i; j--) {
                if (A[i] < A[j]) {
                    swap(A[i], A[j]);
                    reverse(A.begin() + i + 1, A.end());
                    return;
                }
            }
        }
    }
    sort(A.begin(), A.end());
}
