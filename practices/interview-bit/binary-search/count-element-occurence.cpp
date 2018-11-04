int findLeftMost(const vector<int> &nums, int x) {
    int low = 0;
    int high = (int)nums.size() - 1;
    int ans = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

int findRightMost(const vector<int> &nums, int x) {
    int low = 0;
    int high = (int)nums.size() - 1;
    int ans = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] <= x) {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}

int Solution::findCount(const vector<int> &nums, int x) {
    if (nums.size() == 0) return 0;

    int left = findLeftMost(nums, x);
    if (left == -1) return 0;

    int right = findRightMost(nums, x);
    return right - left + 1;
}
