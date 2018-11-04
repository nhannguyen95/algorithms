// O(N^2) in time
// O(1) in space
void Solution::rotate(vector<vector<int> > &A) {
    int n = (int) A.size();
    for(int layer = 0; layer < n / 2; layer++) {
        int top = layer;
        int bot = n - layer - 1;
        int left = layer;
        int right = n - layer - 1;

        for(int col = layer; col < n - layer - 1; col++) {
            int offset = col - layer;

            // Move top to right
            int tmp = A[top + offset][right];
            A[top + offset][right] = A[top][col];

            // Move right to bottom
            int tmp2 = A[bot][right - offset];
            A[bot][right - offset] = tmp;

            // Move bottom to left
            tmp = A[bot - offset][left];
            A[bot - offset][left] = tmp2;

            // Move left to top
            A[top][col] = tmp;
        }
    }
}
