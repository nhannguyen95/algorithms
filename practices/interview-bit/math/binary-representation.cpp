// O(logA) in time
// O(logA) in space
string Solution::findDigitsInBinary(int A) {
    if (A == 0) return "0";
    string bin("");
    while(A > 0) {
        bin.push_back('0' + (A % 2));
        A /= 2;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}
