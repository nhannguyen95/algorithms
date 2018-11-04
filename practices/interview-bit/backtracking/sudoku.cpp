bool rows[9][9];
bool cols[9][9];
bool cells[9][9];

pair<int, int> move(int row, int col) {
    if (col < 8) col++;
    else { row++; col = 0; }
    return make_pair(row, col);
}

bool solve(vector<vector<char>> & A, int row, int col) {
    if (row == 9) {
        return true;
    }

    // This cell is already filled
    if (A[row][col] != '.') {
        pair<int, int> newRC = move(row, col);
        return solve(A, newRC.first, newRC.second);
    }

    for(int opt = 1; opt <= 9; opt++) {
        int cell = (row/3)*3 + (col/3);
        if (rows[row][opt-1] || cols[col][opt-1] || cells[cell][opt-1]) continue;

        A[row][col] = ('0' + opt);
        rows[row][opt-1] = true;
        cols[col][opt-1] = true;
        cells[cell][opt-1] = true;

        pair<int, int> newRC = move(row, col);
        if (solve(A, newRC.first, newRC.second))
            return true;

        A[row][col] = '.';
        rows[row][opt-1] = false;
        cols[col][opt-1] = false;
        cells[cell][opt-1] = false;
    }

    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    memset(rows, false, sizeof rows);
    memset(cols, false, sizeof cols);
    memset(cells, false, sizeof cells);

    for(int row = 0; row < (int)A.size(); row++)
        for(int col = 0; col < (int)A[0].size(); col++) {
            if (A[row][col] == '.') continue;

            int cell = (row/3)*3 + (col/3);
            int opt = A[row][col] - '1';
            rows[row][opt] = true;
            cols[col][opt] = true;
            cells[cell][opt] = true;
        }

    solve(A, 0, 0);
}
