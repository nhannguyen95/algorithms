// Solution 1: Segment tree
// Time complexity: O(NlogN), can be deduce from T(N) = 2T(N/2) + N
class Solution {
public:
    int count(vector<int>& nums, int l, int r, int x) {
        int cnt = 0;
        for(int i = l; i <= r; i++)
            cnt += nums[i] == x;
        return cnt;
    }
    
    // Return the element that appears the most in nums[l..r].
    // Since the problem warranty that the majority elements
    // always exist => the final result is correct.
    int find(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        
        int m = l + (r - l) / 2;
        int left = find(nums, l, m);
        int right = find(nums, m+1, r);
        
        if (left == right) return left;
        
        int cntLeft = count(nums, l, m, left);
        int cntRight = count(nums, m+1, r, right);
        return cntLeft > cntRight ? left : right;
    }
    
    int majorityElement(vector<int>& nums) {
        return find(nums, 0, nums.size()-1);
    }
};

// Solution 2: Boyer-Moore Voting Algorithm
// Brilliant explanation: 0 | 0 | 0 | Ma Ma Mi
// O(1) in space, O(N) in time
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candidate = 0;
        for(int num : nums) {
            if (cnt == 0) {
                candidate = num;
            }
            cnt += (candidate == num) ? 1 : -1;
        }
        return candidate;
    }
};
