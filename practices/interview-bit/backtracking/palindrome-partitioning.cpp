bool isPalindrome(const string & s) {
    int size = (int)s.size();
    for(int i = 0; i < size/2; i++) {
        if (s[i] != s[size-i-1]) {
            return false;
        }
    }
    return true;
}

void findPartition(const string & s, int index, vector<string> & par, vector<vector<string>> & pars) {
    if (index == (int)s.size()) {
        pars.push_back(par);
        return;
    }

    for(int i = index + 1; i <= (int)s.size(); i++) {
        string subStr = s.substr(index, i-index);
        if (isPalindrome(subStr)) {
            par.push_back(subStr);
            findPartition(s, i, par, pars);
            par.pop_back();
        }
    }
}

// bool cmp(const vector<string> & par1, const vector<string> & par2) {
//     int i = 0;
//     while(i < min((int)par1.size(), (int)par2.size())) {
//         int sz1 = (int)par1[i].size();
//         int sz2 = (int)par2[i].size();
//         if (sz1 < sz2) return true;
//         else if (sz1 > sz2) return false;
//         i++;
//     }
//     return false;
// }

vector<vector<string> > Solution::partition(string s) {
    vector<string> par;
    vector<vector<string>> pars;
    findPartition(s, 0, par, pars);

    // sort(pars.begin(), pars.end(), cmp);
    return pars;
}
