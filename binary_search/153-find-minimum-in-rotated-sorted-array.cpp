# Solution 1: binary search
# O(1) in space, O(logN) in time
class Solution {
public:
    int findMin(vector<int>& nums, int low, int high) {
        // Base case
        if (low == high) return nums[low];
        
        // Not rotated
        if (nums[high] > nums[low]) return nums[low];  
        
        int mid = (low + high) / 2;
        if (nums[mid] >= nums[0]) return findMin(nums, mid+1, high);
        return findMin(nums, low, mid);
    }
    
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size()-1);
    }
};
