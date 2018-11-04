string Solution::longestCommonPrefix(vector<string> &A) {
    if ((int)A.size() == 0) return "";

    int prefixLen;
    for(prefixLen = 0; prefixLen < (int)A[0].size(); prefixLen++) {
        bool stop = false;
        for(int i = 0; i < (int)A.size(); i++) {
            if (i == (int)A.size() - 1) break;

            if (A[i].size() <= prefixLen || A[i][prefixLen] != A[i + 1][prefixLen]) {
                stop = true;
                break;
            }
        }
        if (stop) break;
    }

    return A[0].substr(0, prefixLen);
}
