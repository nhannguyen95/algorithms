// https://leetcode.com/problems/partition-labels/

// Solution 1
// O(N) in time and space
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> lastId(26, -1);
        for(int i = S.size() - 1; i >= 0; i--)
            if (lastId[S[i] - 'a'] == -1)
                lastId[S[i] - 'a'] = i;
        
        vector<int> lens;
        int i = 0;
        while(i < S.size()) {
            int maxLast = lastId[S[i] - 'a'];
            int j = i + 1;
            while(j <= min(maxLast, (int)S.size() - 1)) {
                maxLast = max(maxLast, lastId[S[j] - 'a']);
                j++;
            }
            lens.push_back(j - i);
            i = j;
        }
        return lens;
    }
};
