void generate(const int & n, vector<string> & all, string & cur,
                int cntOpen, int cntClose) {
    if ((int)cur.size() == 2 * n) {
        all.push_back(cur);
        return;
    }
    
    // Try to add '('
    if (cntOpen < n) {
        cur.push_back('(');
        generate(n, all, cur, cntOpen + 1, cntClose);
        cur.pop_back();
    }

    // Try to add ')'
    if (cntOpen > cntClose) {
        cur.push_back(')');
        generate(n, all, cur, cntOpen, cntClose + 1);
        cur.pop_back();
    }
}

vector<string> Solution::generateParenthesis(int n) {
    vector<string> all;
    string cur = "";
    generate(n, all, cur, 0, 0);
    return all;
}
