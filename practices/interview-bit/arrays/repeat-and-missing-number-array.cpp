vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Base case
    if (A.size() < 2) return vector<int>();

    long long oriSum = 0, oriSum2 = 0;
    long long curSum = 0, curSum2 = 0;
    for(int i = 0; i < (int) A.size(); i++) {
        oriSum += (i + 1);
        curSum += A[i];
        oriSum2 += (long long) (i + 1) * (i + 1);
        curSum2 += (long long) (A[i]) * A[i];
    }

    long long sub = curSum - oriSum;            // A - B
    long long sum = (curSum2 - oriSum2) / sub;  // A + B

    int twiceNum = (sub + sum) / 2;    // A
    int missingNum = (sum - sub) / 2;  // B

    return vector<int>({twiceNum, missingNum});
}
