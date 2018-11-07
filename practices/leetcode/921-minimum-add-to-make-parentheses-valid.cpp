// Solution 1: Stack
// O(N) in time space
class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> stack;
        for(char & c : S) {
            if (c == '(') stack.push(c);
            else {
                if (stack.size() > 0 && stack.top() == '(')
                    stack.pop();
                else stack.push(c);
            }
        }
        return stack.size();
    }
};

// Solution 2: O(1) in space, O(N) in time
class Solution {
public:
    int minAddToMakeValid(string S) {
        int ans = 0, bal = 0;  // bal = '('s - ')'s
        for(auto & c : S) {
            bal += (c == '(') ? 1 : -1;
            if (bal == -1) {  // bal >= -1
                bal += 1;
                ans += 1;
            }
        }
        return ans + bal;
    }
};
