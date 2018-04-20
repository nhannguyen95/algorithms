// Solution 1: sorting + heap
// N = length of string.
// Time complexity: O(NlogN) sorting + O(N) counting freq + O(NlogN) building res
// = O(NlogN)
// Space complexity: O(N)
class Solution {
public:
    string frequencySort(string s) {
        sort(s.begin(), s.end());
        priority_queue<pair<int, char>> Q;
        for(int i = 0, cnt = 0; i < (int)s.size(); i++) {
            cnt++;
            if ((i == (int)s.size() - 1) || (s[i] != s[i+1])) {
                Q.push(make_pair(cnt, s[i]));
                cnt = 0;   
            }    
        }
        
        string res = "";
        while(!Q.empty()) {
            res += string(Q.top().first, Q.top().second);
            Q.pop();
        }
        return res;
    }
};
