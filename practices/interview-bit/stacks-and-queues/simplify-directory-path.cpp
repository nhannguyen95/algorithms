// O(N) in time
// O(N) in space
string Solution::simplifyPath(string A) {
    if (!A.empty() && A.back() != '/')
        A.push_back('/');

    string ans = "/";
    string fname = "";
    for(char c : A) {
        if (c == '/') {
            if (!fname.compare("")) continue;

            if (!fname.compare("..")) {
                while(!ans.empty() && ans.back() != '/') {
                    ans.pop_back();
                }
                if (ans.back() == '/' && ans.size() > 1)  // Don't delete the last `/`
                    ans.pop_back();
            } else if (fname.compare(".")) {
                if (ans.back() != '/')
                    ans.push_back('/');
                ans += fname;
            }
            fname = "";

        } else if (c != '/') {
            fname.push_back(c);
        }
    }
    return ans;
}
