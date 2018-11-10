// https://leetcode.com/problems/daily-temperatures/

// Solution 1: stack
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
//      T = [73, 74, 75, 71, 69, 72, 76, 73] 
//          [1, 1, 4, 2, 1, 1, 0, 0]
        int n = T.size();
        stack<int> s;
        vector<int> ans(n, 0);
        for(int i = n-1; i >= 0; i--) {
            while(!s.empty() && T[s.top()] <= T[i])
                s.pop();
            ans[i] = s.empty() ? 0 : (s.top() - i);
            s.push(i);
        }
        return ans;
    }
};
