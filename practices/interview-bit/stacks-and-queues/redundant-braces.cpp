// O(N) in time
// O(N) in space
bool isOperator(char c) {
    return c == '+' || c == '*' || c == '-' || c == '/';
}

int Solution::braces(string A) {
    // `s` will only contain '(' character
    // ( '(', 0 ) means there is no expression/operator in the current pair of braces
    stack<pair<char, int>> s;
    for(char c : A) {
        if (c == '(') {
            s.push(make_pair(c, 0));
        } else if (c == ')') {
            if (s.empty()) return 1;  // Invalid braces
            if (s.top().second == 0) return 1;  // Inside this pair of braces,
                                                // there is no expression, thus
                                                // redundant
            s.pop();
        } else {
            if (isOperator(c) && !s.empty()) {
                s.top().second = 1;
            }
        }
    }
    if (!s.empty()) return 1;
    return 0;
}
