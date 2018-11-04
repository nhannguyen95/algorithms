// K is the average number of digit of all numbers
// N is the number of numbers (size of A array)
// O(NKlogN + NK) in time and O(NK) in time
bool cmp(int x, int y) {
    string xStr = to_string(x);
    string yStr = to_string(y);
    string xy = xStr + yStr;
    string yx = yStr + xStr;
    return xy.compare(yx) > 0;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<int> numbers(A);
    sort(numbers.begin(), numbers.end(), cmp);

    string ans = "";
    for(int i = 0; i < (int) numbers.size(); i++) {
        ans += to_string(numbers[i]);
    }

    // Eliminaing heading 0(s)
    int pos = 0;
    while(pos + 1 < (int) ans.size() && ans[pos] == '0') {
        pos++;
    }
    return ans.substr(pos);
}
