int Solution::singleNumber(const vector<int> &A) {
    // x xor x = 0
    // x xor 0 = x
    int ans = A[0];
    for(int i = 1; i < (int)A.size(); i++)
        ans ^= A[i];
    return ans;
}
