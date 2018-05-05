# Solution 1: marking using sign + modify the array
# O(N) in time, O(1) in space
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // index = [0, n]
        for(int i = 0; i < (int)nums.size(); i++) {
            // num = [1, n]
            if (nums[abs(nums[i])] < 0) return abs(nums[i]);
            nums[abs(nums[i])] *= -1;
        }
        return 0;  // should never happen
    }
};

# Solution 2:
