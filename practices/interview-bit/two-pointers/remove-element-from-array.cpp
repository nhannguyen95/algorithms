int Solution::removeElement(vector<int> &nums, int v) {
    int j = 0;
    for(int i = 0; i < (int)nums.size(); i++) {
        if (nums[i] != v) {
            nums[j++] = nums[i];
        }
    }
    return j;
}
