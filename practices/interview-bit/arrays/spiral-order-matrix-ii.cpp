// O(A^2) in time
// O(1) in space
bool isBetween(int x, int left, int right) {
    return (left <= x) && (x <= right);
}

vector<vector<int> > Solution::generateMatrix(int A) {
    assert(A > 0);
    vector<vector<int>> ans(A, vector<int>(A, 0));
    int i = 0, j = 0, curDir = 0;
    int di[4] = {0, 1, 0, -1};  // Right, Down, Left, Up
    int dj[4] = {1, 0, -1, 0};
    for(int num = 1; num <= A * A; num++) {
        ans[i][j] = num;

        // Next cell
        i += di[curDir];
        j += dj[curDir];

        // If out of bound or meet already filled cell
        if (!isBetween(i, 0, A - 1) || !isBetween(j, 0, A - 1) || ans[i][j] != 0) {
            // Roll back
            i -= di[curDir];
            j -= dj[curDir];

            // Change direction
            curDir = (curDir + 1) % 4;

            // Omit filled cell of old direction
            i += di[curDir];
            j += dj[curDir];
        }
    }
    return ans;
}
