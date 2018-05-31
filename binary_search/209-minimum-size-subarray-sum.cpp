// Solution 1: Two pointers
// O(N) in time, O(1) in space
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        long long sum = 0;
        int len = nums.size() + 1;
        for(int slow = 0, fast = 0; fast < nums.size(); fast++) {
            sum += nums[fast];
            while(sum >= s) {
                len = min(len, fast - slow + 1);
                sum -= nums[slow++];
            }
        }
        return (len <= nums.size() ? len : 0);
    }
};

// Solution 2: accumulative sum + binary search
// O(NlogN) in time, O(N) in space
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<long long> acSum(n+1, 0);  // Accumulative sum
        for(int i = 1; i <= n; i++)
            acSum[i] = acSum[i-1] + nums[i-1];
        
        int len = n+1;
        for(int i = 1; i <= n; i++) {
            int low = 1;
            int high = i+1;
            while(low < high) {
                int mid = low + (high-low+1)/2;
                if (acSum[i] - acSum[mid-1] >= s)
                    low = mid;
                else high = mid - 1;
            }
            if (acSum[i] - acSum[low-1] >= s)
                len = min(len, i-low+1);
        }
        return (len <= n ? len : 0);
    }
};
