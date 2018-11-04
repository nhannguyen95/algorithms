string Solution::convert(string text, int nRows) {
    // Base case
    if (nRows == 1) return text;

    vector<string> textInRows(nRows);
    int dir = 1;
    int curRowId = 0;
    for(int i = 0; i < (int)text.size(); i++) {
        textInRows[curRowId].push_back(text[i]);

        // Go to next row (in the current direction)
        curRowId += dir;

        // If out of bound
        if (curRowId == -1 || curRowId == nRows) {
            // Change direction
            dir = -dir;

            // Roll back
            curRowId += 2*dir;
        }
    }

    string ans;
    for(int i = 0; i < nRows; i++) {
        ans.append(textInRows[i]);
    }
    return ans;
}
