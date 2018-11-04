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

# Solution 2: The tortoise and hare algorithm
# https://nhannguyen95.github.io/the-tortoise-and-hare-algorithm/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int rua = 0;
        int tho = 0;
        do {
            rua = nums[rua];
            tho = nums[nums[tho]];
        } while(rua != tho);
        
        tho = 0;
        while(rua != tho) {
            rua = nums[rua];
            tho = nums[tho];
        }
        return rua;
    }
};
