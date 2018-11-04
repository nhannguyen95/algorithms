void Solution::sortColors(vector<int> &A) {
    if (A.size() < 2) return;

    int low = 0, high = (int)A.size() - 1;
    // Sweep all 0s to left and 2s to right
    for(int i = low; i <= high; i++) {
        if (A[i] == 0 && i != low) {
            swap(A[low++], A[i--]);
        } else if (A[i] == 2 && i != high) {
            swap(A[i--], A[high--]);
        }
    }
}
