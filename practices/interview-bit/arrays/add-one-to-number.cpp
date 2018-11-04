vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> sum;
    int carry = 1;
    for(int i = (int) A.size() - 1; i >= 0; i--) {
        carry += A[i];
        sum.push_back(carry % 10);
        carry /= 10;
    }
    if (carry != 0) sum.push_back(carry);
    while(sum.size() > 1 && sum.back() == 0) sum.pop_back();  // remove heading zeroes

    reverse(sum.begin(), sum.end());
    return sum;
}
