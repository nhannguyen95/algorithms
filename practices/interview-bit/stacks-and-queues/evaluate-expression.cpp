// O(N) in space
// O(N) in time
bool isOperator(const string & s) {
    return !s.compare("+") || !s.compare("-") ||
           !s.compare("*") || !s.compare("/");

}

int compute(int num1, int num2, const string & s) {
    if (!s.compare("+")) return num1 + num2;
    if (!s.compare("-")) return num1 - num2;
    if (!s.compare("*")) return num1 * num2;
    if (!s.compare("/")) return num1 / num2;
    return 0;
}

int Solution::evalRPN(vector<string> &A) {
    stack<int> nums;
    for(string s : A) {
        if (!isOperator(s)) {
            nums.push(stoi(s));
        } else {
            int num2 = nums.top(); nums.pop();
            int num1 = nums.top(); nums.pop();
            int res = compute(num1, num2, s);
            nums.push(res);
        }
    }
    return nums.top();
}
