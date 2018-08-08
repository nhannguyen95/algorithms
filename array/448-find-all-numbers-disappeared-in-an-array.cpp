// Solution 1: Use original array to mark present elements
// 2 for loops.
// O(1) in space (does not count the resulting array)
// O(N) in time
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int j = abs(nums[i]) - 1;
            if (nums[j] > 0) nums[j] = -nums[j];
        }
        
        vector<int> missings;
        for(int i = 1; i <= n; i++) {
            if (nums[i-1] > 0) missings.push_back(i);
        }
        
        return missings;
    }
};
