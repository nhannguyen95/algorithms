// Solution 1:
// O(2logN) in time, O(1) in space
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        // Starting
        int st = 0;
        int low = 0;
        int high = n-1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= target) {
                st = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        // Ending
        int ed = 0;
        low = 0;
        high = n - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] <= target) {
                ed = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        if (n == 0 || nums[st] != target) return vector<int>({-1, -1});
        return vector<int>({st, ed});
    }
};
