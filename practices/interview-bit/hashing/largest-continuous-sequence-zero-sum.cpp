// O(N) in space
// O(N) in time
vector<int> Solution::lszero(vector<int> &A) {
    unordered_map<long long, int> s2i;  // s2i[s] = lowest i such that A[0]+..+A[i] = 0
    s2i[0] = -1;

    long long curSum = 0;
    int imax = -1, jmax = -2;
    for(int j = 0; j < (int)A.size(); j++) {
        curSum += A[j];
        if (s2i.find(curSum) != s2i.end()) {
            if (j-s2i[curSum] > jmax-imax+1) {
                imax = s2i[curSum]+1;
                jmax = j;
            }
        } else {
            s2i[curSum] = j;
        }
    }
    if (imax != -1) return vector<int>(A.begin()+imax, A.begin()+jmax+1);
    return vector<int>();
}
