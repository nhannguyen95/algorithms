vector<int> Solution::maxset(vector<int> &A) {
    long long sum, ansSum;
    int start, end, ansStart, ansEnd;

    sum = ansSum = 0;
    start = ansStart = 0;
    end = ansEnd = -1;

    for(int i = 0; i < (int) A.size(); i++) {
        if (A[i] >= 0) {  // Update the current sub-array
            sum += A[i];
            end = i;
        }

        if (A[i] < 0 || i == (int) A.size() - 1) { // Update the result
            if (((sum == ansSum) && (end - start > ansEnd - ansStart))
               || sum > ansSum) {
                    ansStart = start;
                    ansEnd = end;
                    ansSum = sum;
               }

            // Reset for new sub-array
            start = i + 1;
            sum = 0;
        }
    }

    if (ansStart <= ansEnd) {
        return vector<int>(A.begin() + ansStart, A.begin() + ansEnd + 1);
    }
    return vector<int>();
}
