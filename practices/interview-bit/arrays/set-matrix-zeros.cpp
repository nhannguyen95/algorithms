void Solution::setZeroes(vector<vector<int> > &A) {
    int rows = (int)A.size();
    if (rows == 0) return;
    int cols = (int)A[0].size();

    /* Should we zero out first column, first row? */
    bool zeroFirstRow = false;
    for(int col = 0; col < cols; col++) {
        if (A[0][col] == 0) {
            zeroFirstRow = true;
            break;
        }
    }

    bool zeroFirstCol = false;
    for(int row = 0; row < rows; row++) {
        if (A[row][0] == 0) {
            zeroFirstCol = true;
            break;
        }
    }

    /* Find row(s), col(s) we should zero out */
    for(int row = 1; row < rows; row++) {
        for(int col = 1; col < cols; col++) {
            if (A[row][col] == 0) {
                A[row][0] = 0;  // Means we should zero out row row-th
                A[0][col] = 0;  // Means we should zero out col col-th
            }
        }
    }

    /* Zeroing rows */
    for(int row = 1; row < rows; row++) {
        if (A[row][0] == 0) {
            for(int col = 1; col < cols; col++) {
                A[row][col] = 0;
            }
        } else if (zeroFirstCol) {
            A[row][0] = 0;
        }
    }

    /* Zeroing cols */
    for(int col = 1; col < cols; col++) {
        if (A[0][col] == 0) {
            for(int row = 1; row < rows; row++) {
                A[row][col] = 0;
            }
        } else if (zeroFirstRow) {
            A[0][col] = 0;
        }
    }

    /* We haven't considered A[0][0] */
    if (zeroFirstRow || zeroFirstCol) {
        A[0][0] = 0;
    }
}
