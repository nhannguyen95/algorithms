// Solution 1:
// O(1) in space (not count result array)
// O(N) in time
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> dups;
        for(int i = 0; i < nums.size(); i++) {
            int v = abs(nums[i]);
            if (nums[v-1] < 0) dups.push_back(v);
            else nums[v-1] = -nums[v-1];
        }
        return dups;
    }
};
