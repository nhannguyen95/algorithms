// https://leetcode.com/problems/fair-candy-swap

// Solution 1: hash table
// Time complexity for average case
// Na = len(A), Nb = len(B)
// O(2Na + 2Nb) in time
// O(Nb) in space
// Look at the complexities we can optimize the space to O(min(Na, Nb))
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        unordered_set<int> bValues;
        for(int bValue : B) bValues.insert(bValue);
        
        vector<int> ans(2);
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        for(int aValue : A) {
            int bValue = (sumB - sumA) / 2 + aValue;
            if (bValues.find(bValue) != bValues.end()) {
                ans[0] = aValue;
                ans[1] = bValue;
                break;
            }
        }
        return ans;
    }
};
