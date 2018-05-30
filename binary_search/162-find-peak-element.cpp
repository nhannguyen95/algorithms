// Solution 1: naive
// O(N) in time, O(1) in space
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;
        for(int i = 1; i < n-1; i++)
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1])
                return i;
        return -1;
    }
};

// Solution 2: improved naive
// O(N) in time, O(1) in space
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; i++) 
            if (nums[i] > nums[i+1]) return i;
        return nums.size()-1;
    }
};

// Solution 3: binary search
// O(logN) in time, O(1) in space
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = (int)nums.size();
        assert(n > 0);
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;
        int low = 0;
        int high = (int)nums.size()-1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            else if (nums[mid] < nums[mid+1]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;  // should never reach
    }
};

// Solution 4: improved binary search
// O(logN) in time, O(1) in space
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while(low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] < nums[mid+1])
                low = mid + 1;
            else high = mid;
        }
        return low;
    }
};
