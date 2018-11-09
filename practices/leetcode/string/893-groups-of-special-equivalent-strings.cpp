// Solution 1
class Solution {
public:
    bool equal(const string & s, const string & t) {
        vector<vector<int>> countS(2, vector<int>(26, 0));
        vector<vector<int>> countT(2, vector<int>(26, 0));
        for(int i = 0; i < s.size(); i++) {
            countS[i % 2][s[i] - 'a']++;
            countT[i % 2][t[i] - 'a']++;
        }
        return countS == countT;
        
    }
    
    int numSpecialEquivGroups(vector<string>& A) {
        int n = A.size();
        vector<bool> inS(n, false);
        
        int nGroups = 0;
        for(int i = 0; i < n; i++) {
            if (inS[i]) continue;
            inS[i] = true;
            nGroups++;
            for(int j = i + 1; j < n; j++)
                if (equal(A[i], A[j]))
                    inS[j] = true;
        }
        return nGroups;
    }
};
