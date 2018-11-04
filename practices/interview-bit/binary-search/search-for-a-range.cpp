// Solution 1
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int n = (int)A.size();
    if (n == 0) return vector<int>({-1, -1});

    int low = 0;
    int high = n - 1;
    while(low < high) {
        int mid = (low + high) >> 1;
        if (A[mid] >= B) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    if (A[high] != B) return vector<int>({-1, -1});

    vector<int> ans({high});
    low = high;
    high = n - 1;
    while(low < high) {
        int mid = ((low + high) >> 1) + 1;
        if (A[mid] <= B) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    ans.push_back(low);
    return ans;
}

// Solution 2
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int n = (int)A.size();
    if (n == 0) return vector<int>({-1, -1});

    int low = 0;
    int high = n - 1;
    while(low < high) {
        int mid = (low + high) >> 1;
        if (A[mid] < B) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    if (low >= n || A[low] != B) return vector<int>({-1, -1});

    vector<int> ans({low});
    high = n - 1;
    while(low < high) {
        int mid = ((low + high) >> 1) + 1;  // biased to the right
        if (A[mid] > B) {
            high = mid - 1;
        } else {
            low = mid;
        }
    }
    ans.push_back(high);
    return ans;
}
