int modifiedBinSearch(const vector<int> & A, int left, int right, int x) {
    int mid = (left + right) / 2;
    if (x == A[mid]) return mid;
    if (right < left) return -1;

    if (A[left] < A[mid]) {  // Left is normally ordered
        if (A[left] <= x && x < A[mid]) {
            return modifiedBinSearch(A, left, mid - 1, x);  // Search left
        } else {
            return modifiedBinSearch(A, mid + 1, right, x);  // Search right
        }
    } else if (A[left] > A[mid]) {  // Right is normally ordered
        if (A[mid] < x && x <= A[right]) {
            return modifiedBinSearch(A, mid + 1, right, x);  // Search right
        } else {
            return modifiedBinSearch(A, left, mid - 1, x);  // Search left
        }
    } else if (A[left] == A[mid]) {  // Left or right half is all repeats
        if (A[mid] != A[right])  {  // If right is different, seach it
            return modifiedBinSearch(A, mid + 1, right, x);
        } else {  // Else, we have to search both halves
            int result = modifiedBinSearch(A, left, mid - 1, x);
            if (result == -1) {
                return modifiedBinSearch(A, mid + 1, right, x);
            }
            return result;
        }
    }

    return -1;
}

int Solution::search(const vector<int> &A, int B) {
    return modifiedBinSearch(A, 0, (int)A.size() - 1, B);
}
