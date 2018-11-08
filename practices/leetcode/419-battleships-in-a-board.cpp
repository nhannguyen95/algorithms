// https://leetcode.com/problems/battleships-in-a-board/

// Solution 1: O(1) in space, O(N^2) in space
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int R = board.size();
        if (R == 0) return 0;
        int C = board[0].size();
        if (C == 0) return 0;
        
        // We count the head of ships.
        int nShips = 0;
        for(int r = 0; r < R; r++) {
            for(int c = 0; c < C; c++) {
                if (board[r][c] == 'X') {
                    // These 'X' is body.
                    if (r > 0 && board[r-1][c] == 'X') continue;
                    if (c > 0 && board[r][c-1] == 'X') continue;
                    
                    // This 'X' is head.
                    nShips++;
                }
            }
        }
        
        return nShips;
    }
};
