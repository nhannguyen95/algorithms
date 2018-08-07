// Solution 1:
// O(N) in time, O(1) in space
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max1s = 0;
        for(int num : nums) {
            count = (num == 0) ? 0 : (count + 1);
            max1s = std::max(max1s, count);
        }
        return max1s;
    }
};
