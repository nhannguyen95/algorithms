// Solution 1
string Solution::addBinary(string A, string B) {
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    // Add zeroes if len(A) <> len(B)
    while(A.size() < B.size()) A.push_back('0');
    while(B.size() < A.size()) B.push_back('0');

    string ans("");
    int carry = 0;
    for(int i = 0; i < (int)A.size(); i++) {
        int digitA = A[i] - '0';
        int digitB = B[i] - '0';
        ans.push_back('0' + (digitA + digitB + carry) % 2);
        carry = (digitA + digitB + carry) / 2;
    }
    if (carry > 0) ans.push_back('1');
    reverse(ans.begin(), ans.end());
    return ans;
}

// Solution 2: more efficient in terms of memory and speed
string Solution::addBinary(string A, string B) {
    int i = (int)A.size() - 1;
    int j = (int)B.size() - 1;
    string ans("");
    int carry(0), sum(0);
    while(i >= 0 || j >= 0 || carry) {
        sum = carry;
        if (i >= 0) sum += (A[i] - '0');
        if (j >= 0) sum += (B[j] - '0');
        ans.push_back('0' + (sum % 2));
        carry = sum / 2;
        i--; j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
