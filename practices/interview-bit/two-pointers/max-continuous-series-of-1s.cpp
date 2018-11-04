// Algorithm: flip (maximum) M consecutive 0s -> 2 pointers
// O(N) in time
// O(N) in space (for the result array)
vector<int> Solution::maxone(vector<int> &A, int M) {
    int n = (int)A.size();
    int i = 0;
    int j = 0;
    int maxi = 0;
    int maxj = 0;
    int cnt0 = 0;
    while(j < n) {
        if (A[j] == 0) cnt0++;

        if (cnt0 <= M) {
            if (j - i > maxj - maxi) {
                maxi = i;
                maxj = j;
            }
        } else {
            while(cnt0 > M)
                if (A[i++] == 0) cnt0--;
        }

        j++;
    }

    vector<int> indices;
    while(maxi <= maxj) indices.push_back(maxi++);
    return indices;
}
