// Solution 1:
// O(NlogN + N) in time, O(1) in space
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};

// Solution 2:
// K = range of numbers
// O(K + N) in time, O(K) in space
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // Counting sort
        vector<int> count(20000+1, 0);
        for(int num : nums) count[num + 10000]++;
        
        // Sum over the odd
        int sum = 0;
        int cnt = 0;
        for(int num = 0; num <= 20000; num++) {
            for(int i = 0; i < count[num]; i++) {
                cnt++;
                if (cnt % 2 == 1) sum += (num - 10000);
            }
        }
        return sum;
    }
};
