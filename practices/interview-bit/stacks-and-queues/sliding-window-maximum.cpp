// Two pointer + deque
vector<int> Solution::slidingMaximum(const vector<int> &A, int w) {
    // Base case
    int n = (int)A.size();
    if (n == 0) return vector<int>();

    deque<int> dmax;
    vector<int> B;
    int j = 0;
    for(int i = 0; i < n; i++) {
        while(!dmax.empty() && A[dmax.back()] <= A[i]) {
            dmax.pop_back();
        }
        dmax.push_back(i);

        if (i - j + 1 == w) {
            B.push_back(A[dmax.front()]);
            j++;
            while (!dmax.empty() && dmax.front() < j) {
                dmax.pop_front();
            }
        }
    }

    // w > n
    if (B.empty()) {
        B.push_back(A[dmax.front()]);
    }

    return B;
}
