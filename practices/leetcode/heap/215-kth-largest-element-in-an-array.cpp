// Solution 1: sorting
// N = number of elements
// O(NlogN) in time, O(1) in space
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        return nums[k-1];
    }
};

// Solution 2: heap
// Maintain a min-heap of size k.
// O(NlogK) in time, O(K) in space
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> Q;
        for(int num : nums) {
            Q.push(num);
            if (Q.size() > k) Q.pop();
        }
        return Q.top();
    }
};
