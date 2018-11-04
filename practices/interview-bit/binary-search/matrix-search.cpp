// Solution 1
bool isBetween(int left, int right, int x) {
    return left <= x && x <= right;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n = (int)A.size();
    if (n == 0) return 0;
    int m = (int)A[0].size();
    if (m == 0) return 0;

    int lowR = 0;
    int highR = n - 1;
    while(lowR <= highR) {
        int midR = (lowR + highR) / 2;
        int minRow = A[midR][0];
        int maxRow = A[midR][m - 1];
        if (isBetween(minRow, maxRow, B)) {
            int low = 0;
            int high = m - 1;
            while(low <= high) {
                int mid = (low + high) / 2;
                if (A[midR][mid] == B) return 1;
                else if (A[midR][mid] > B) high = mid - 1;
                else low = mid + 1;
            }
            return 0;

        } else if (B < minRow) {
            highR = midR - 1;
        } else {
            lowR = midR + 1;
        }
    }
    return 0;
}

// Solution 2
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n = (int)A.size();
    if (n == 0) return 0;
    int m = (int)A[0].size();
    if (m == 0) return 0;

    int low = 0;
    int high = n * m - 1;
    while(low < high) {
        int mid = (low + high) >> 1;
        if (A[mid / m][mid % m] < B) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return A[high / m][high % m] == B;
}
