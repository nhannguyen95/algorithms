int Solution::maxSubArray(const vector<int> &A) {
    long long sum = 0;
    long long maxSum = LONG_LONG_MIN;
    for(int i = 0; i < (int) A.size(); i++) {
        sum += A[i];
        maxSum = max(maxSum, sum);

        if (sum < 0) sum = 0;
    }
    return maxSum;
}
