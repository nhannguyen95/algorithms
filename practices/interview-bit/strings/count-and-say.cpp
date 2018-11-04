string Solution::countAndSay(int n) {
    if (n <= 0) return "";

    string ans = "1";
    for(int i = 2; i <= n; i++) {
        string tmp("");
        int cnt = 1;
        for(int j = 0; j < (int)ans.size(); j++) {
            if (j == (int)ans.size() - 1 || (ans[j] != ans[j + 1])) {
                tmp.push_back('1' + cnt - 1);
                tmp.push_back(ans[j]);
                cnt = 1;
            } else {
                cnt++;
            }
        }
        ans = tmp;
    }

    return ans;
}
