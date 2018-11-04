string unitIntToRoman(int unitInt, int level, const vector<string> & unit1, const vector<string> & unit5) {
    string _i = unit1[level];
    string _x = (level + 1 < unit1.size()) ? unit1[level + 1] : "";
    string _v = (level < unit5.size()) ? unit5[level] : "";

    switch(unitInt) {
        case 1: return _i;
        case 2: return _i + _i;
        case 3: return _i + _i + _i;
        case 4: return _i + _v;
        case 5: return _v;
        case 6: return _v + _i;
        case 7: return _v + _i + _i;
        case 8: return _v + _i + _i + _i;
        case 9: return _i + _x;
        default: return "";
    }
}

string Solution::intToRoman(int A) {
    vector<string> unit1({"I", "X", "C", "M"});
    vector<string> unit5({"V", "L", "D"});
    int level = 0;
    string ans;
    while(A > 0) {
        if (A % 10 != 0) {
            ans = unitIntToRoman(A % 10, level, unit1, unit5).append(ans);
        }
        level++;
        A /= 10;
    }
    return ans;
}
