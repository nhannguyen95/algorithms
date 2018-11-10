// https://leetcode.com/problems/stone-game/

// Solution 1
// dp[i][j] = maximum of difference if some player picks first.
class Solution {
public:
    int getDiff(vector<int>& piles, int l, int r, vector<vector<int>> & memo) {
        if (l == r) return memo[l][r] = piles[l];
        if (memo[l][r]) return memo[l][r];
        
        return memo[l][r] = max(
            piles[l] - getDiff(piles, l+1, r, memo),
            piles[r] - getDiff(piles, l, r-1, memo)
        );
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> memo(n, vector<int>(n, 0));
        return getDiff(piles, 0, n-1, memo) > 0;
    }
};
