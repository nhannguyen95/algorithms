// Solution 1:
// O(logN) in average, O(N) in worst case
// O(1) in memory
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = (int)nums.size()-1;
        while(l <= r) {
            int mid = (l+r)/2;
            if (nums[mid] == target) return true;
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                l++; r--;  // deal with duplicates
            } else if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return false;
    }
};
