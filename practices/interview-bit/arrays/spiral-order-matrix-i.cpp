bool isBetween(int x, int left, int right) {
    return (left <= x) && (x <= right);
}

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;

	// Get size of matrix A
	int m = (int) A.size();
	if (m == 0) return vector<int>();
	int n = (int) A[0].size();

	int i = 0, j = 0;
	int diri[4] = {0, 1, 0, -1};
	int dirj[4] = {1, 0, -1, 0};
	int curDir = 0;  // left to right
	int pads[4] = {0, 0, 0, 0};
	for(int count = 0; count < m * n; count++) {
	    result.push_back(A[i][j]);

	    i += diri[curDir];
	    j += dirj[curDir];

	    if (!isBetween(i, pads[0], m - 1 - pads[2]) || !isBetween(j, pads[3], n - 1 - pads[1])) {
	        // roll back
	        i -= diri[curDir];
	        j -= dirj[curDir];

	        // update pads
	        pads[curDir]++;

	        // change direction
	        curDir = (curDir + 1) % 4;

	        // go to first new cell (avoid duplicating cell)
	        i += diri[curDir];
	        j += dirj[curDir];
	    }
	}

	return result;
}
