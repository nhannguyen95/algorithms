// https://leetcode.com/problems/score-of-parentheses

// Solution 1: Divide and Conquer
// Time complexity in average case
// - T(N) = 2T(N/2) + O(N) = O(NlogN) in average
// Time complexity in worst case
// - T(N) = T(N-2) + O(N) = O(N^2)
class Solution {
public:
    int score(const string & S, int l, int r) {
        if (l+1 == r) return 1;
        
        int nLeft = 0;
        int m = l+1;
        for(int i = l; i <= r; i++) {
            if (S[i] == '(') nLeft++;
            else if (S[i] == ')') nLeft--;
            
            if (nLeft == 0) {
                m = i;
                break;
            }
        }
        
        if (m == r) return 2 * score(S, l+1, r-1);
        return score(S, l, m) + score(S, m+1, r);
    }
    
    int scoreOfParentheses(string S) {
        return score(S, 0, S.size()-1);
    }
};
    
// Solution 2: using stack
// O(N) in time and space
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> stack({0});
        for(char c : S) {
            if (c == '(') stack.push(0);
            else {
                int v = stack.top(); stack.pop();
                int w = stack.top(); stack.pop();
                stack.push(w + max(2*v, 1));
            }
        }
        return stack.top();
    }
};

// Solution 3: math
// O(N) in time, O(1) in space
class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 0;
        int bal = 0;
        for(int i = 0; i < S.size(); i++) {
            if (S[i] == '(') bal++;
            else {
                bal--;
                if (S[i-1] == '(')
                    ans += 1 << bal;
            }
        }
        return ans;
    }
};
    
