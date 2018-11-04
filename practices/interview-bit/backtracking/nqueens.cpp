vector<bool> cols, mDiags, aDiags;

void solve(const int n, int row, vector<string> & board, vector<vector<string>> & solutions) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for(int col = 0; col < n; col++) {
        int mDiag = row - col + (n-1);
        int aDiag = row + col;

        if (cols[col] || mDiags[mDiag] || aDiags[aDiag]) continue;

        board[row][col] = 'Q';
        cols[col] = true;
        mDiags[mDiag] = true;
        aDiags[aDiag] = true;

        solve(n, row + 1, board, solutions);

        board[row][col] = '.';
        cols[col] = false;
        mDiags[mDiag] = false;
        aDiags[aDiag] = false;

    }
}

vector<vector<string> > Solution::solveNQueens(int n) {
    // Init
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> solutions;

    cols.assign(n, false);
    mDiags.assign(2*n-1, false);
    aDiags.assign(2*n-1, false);

    solve(n, 0, board, solutions);

    return solutions;
}
