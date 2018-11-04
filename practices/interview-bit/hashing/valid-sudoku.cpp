int Solution::isValidSudoku(const vector<string> &A) {
    bool rows[9][9];
    bool cols[9][9];
    bool cells[9][9];

    memset(rows, false, sizeof rows);
    memset(cols, false, sizeof cols);
    memset(cells, false, sizeof cells);

    for(int row = 0; row < 9; row++) {
        for(int col = 0; col < 9; col++) {
            if (A[row][col] == '.') continue;

            int cell = (row/3)*3 + (col/3);
            int v = A[row][col] - '1';

            if (rows[row][v] || cols[col][v] || cells[cell][v])
                return 0;

            rows[row][v] = true;
            cols[col][v] = true;
            cells[cell][v] = true;
        }
    }
    return 1;
}
