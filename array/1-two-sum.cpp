// Solution 1: Hash table
// O(N) in time
// O(N) in space
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> h;
        for(int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
            if (h.find(comp) != h.end())
                return vector<int>({h[comp], i});
            h[nums[i]] = i;
        }
        return vector<int>({});
    }
};

