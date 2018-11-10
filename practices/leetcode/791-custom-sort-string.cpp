// https://leetcode.com/problems/custom-sort-string

// Solution 1: bubble sort
class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> p(26, -1);
        for(int i = 0; i < S.size(); i++)
            p[S[i] - 'a'] = i;
        
        int n = T.size();
        for(int i = n; i > 0; i--)
            for(int j = 0; j < i-1; j++)
                if (p[T[j]-'a'] > p[T[j+1]-'a'])
                    swap(T[j], T[j+1]);
        
        return T;
    }
};

// Solution 2: counting sort
class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> priority(26, -1);
        for(int i = 0; i < S.size(); i++)
            priority[S[i] - 'a'] = i;
        
        vector<int> freq(26, 0);
        string ans;
        for(char c : T) {
            int p = priority[c - 'a'];
            if (p == -1) ans.push_back(c);
            else freq[p]++;
        }
        
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < freq[i]; j++) {
                ans.push_back(S[i]);
            }
        }
        
        return ans;
    }
};
