// Solution 1:
// O(1) in space, O(N) in time
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast++) {
            // Same problem: move non-zero elements to the head.
            if (nums[fast] != 0) swap(nums[slow++], nums[fast]);
        }
    }
};
