// O(NlogN) in time
// O(1) in space
int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    int countCurrent = 0;
    for(int i = (int)A.size() - 1; i >= 0; i--) {
        // Update the countCurrent
        if (i == (int) A.size() - 1) countCurrent = 1;
        else if (A[i] != A[i + 1]) countCurrent = 1;
        else countCurrent++;

        int greater = ((int)A.size() - i) - countCurrent);
        if (A[i] == greater) {
            return 1;
        }
    }
    return -1;
}
