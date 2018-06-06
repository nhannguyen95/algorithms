class NumArray {
private:
    vector<int> nums;
    vector<int> dp;
    
public:
    NumArray(vector<int> nums) {
        this->nums = nums;
        for(int i = 0; i < nums.size(); i++)
            dp.push_back(nums[i] + (i > 0 ? dp.back() : 0));
    }
    
    int sumRange(int i, int j) {
        return dp[j] - (i > 0 ? dp[i-1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
