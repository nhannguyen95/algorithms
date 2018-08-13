// Solution 1: Hash table
// O(N) in space and time
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seens;
        for(int num : nums) {
            if (seens.find(num) != seens.end())
                return true;
            seens.insert(num);
        }
        return false;
    }
};

// Solution 2: Sorting
// O(NlogN) in time, O(1) in space
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) return true;
        }
        return false;
    }
};
