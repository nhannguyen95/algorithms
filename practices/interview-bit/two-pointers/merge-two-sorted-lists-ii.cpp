// O(n + m) in time
// O(m) in space
void Solution::merge(vector<int> &A, vector<int> &B) {
    int n = (int)A.size();
    int m = (int)B.size();

    A.resize(n + m);

    int imerged = n + m - 1, i = n - 1, j = m - 1;
    while(j >= 0) {
        if (i >= 0 && A[i] > B[j]) {
            A[imerged] = A[i];
            i--;
        } else {
            A[imerged] = B[j];
            j--;
        }
        imerged--;
    }
}
