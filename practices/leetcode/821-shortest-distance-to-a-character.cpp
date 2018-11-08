// https://leetcode.com/problems/shortest-distance-to-a-character/

// Solution 1: O(2N) in time and space
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> posC;
        for(int i = 0; i < S.size(); i++)
            if (S[i] == C) posC.push_back(i);
        
        int i = 0;
        vector<int> ans;
        for(int j = 0; j < S.size(); j++) {
            int dis1 = (i < posC.size()) ? (posC[i] - j) : INT_MAX;
            int dis2 = (i > 0) ? (j - posC[i-1]) : INT_MAX;
            ans.push_back(min(dis1, dis2));
            
            if (i < posC.size() && j == posC[i]) i++;
        }        
        return ans;
    }
};

// Solution 2:
// O(2N) in time
// O(N) in space
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size();
        vector<int> ans(n, 0);
        int pos = -n;
        for(int i = 0; i < n; i++) {
            if (S[i] == C) pos = i;
            ans[i] = i - pos;
        }
        
        
        for(int i = n-1; i >= 0; i--) {
            if (S[i] == C) pos = i;
            ans[i] = min(ans[i], abs(pos - i));
        }
        return ans;
    }
};
