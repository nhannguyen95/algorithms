// Solution 1
#define mp make_pair
typedef pair<string, int> psi;

int Solution::romanToInt(string A) {
    map<char, vector<psi>> extended;
    extended['I'] = vector<psi>({mp("IX", 9), mp("IV", 4), mp("III", 3), mp("II", 2), mp("I", 1)});
    extended['V'] = vector<psi>({mp("VIII", 8), mp("VII", 7), mp("VI", 6), mp("V", 5)});
    extended['X'] = vector<psi>({mp("XC", 90), mp("XL", 40), mp("XXX", 30), mp("XX", 20), mp("X", 10)});
    extended['L'] = vector<psi>({mp("LXXX", 80), mp("LXX", 70), mp("LX", 60), mp("L", 50)});
    extended['C'] = vector<psi>({mp("CM", 900), mp("CD", 400), mp("CCC", 300), mp("CC", 200), mp("C", 100)});
    extended['D'] = vector<psi>({mp("DCCC", 800), mp("DCC", 700), mp("DC", 600), mp("D", 500)});
    extended['M'] = vector<psi>({mp("M", 1000)});

    int pos = 0;
    int ans = 0;
    while(pos < (int)A.size()) {
        vector<psi> & v = extended[A[pos]];
        for(int i = 0; i < v.size(); i++) {
            int len = v[i].first.size();
            if (A.compare(pos, len, v[i].first) == 0) {
                ans += v[i].second;
                pos += len;
                break;
            }
        }
    }

    return ans;
}

// Solution 2 (more efficient)
int romanCharToInt(const char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int Solution::romanToInt(string A) {

    int ans = 0;
    for(int i = 0; i < (int)A.size(); i++) {
        if (i < (int)A.size() - 1 && (romanCharToInt(A[i]) < romanCharToInt(A[i + 1]))) {
            ans -= romanCharToInt(A[i]);
        } else {
            ans += romanCharToInt(A[i]);
        }
    }

    return ans;
}
