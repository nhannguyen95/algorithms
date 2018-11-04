// Solution 1: DP
// N = len of array, M = range of element
// O(3M) in space, O(2N) in time
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        int M = 50000;
        vector<int> firstPos(M, -1), lastPos(M, -1), freq(M);
        int maxFreq = 1;
        for(int i = 0; i < n; i++) {
            if (firstPos[nums[i]] == -1) firstPos[nums[i]] = i;
            if (lastPos[nums[n-i-1]] == -1) lastPos[nums[n-i-1]] = n-i-1;
            freq[nums[i]]++;
            maxFreq = max(maxFreq, freq[nums[i]]);
        }
        
        int len = n;
        for(int num : nums) {
            if (freq[num] == maxFreq) {
                len = min(len, lastPos[num] - firstPos[num] + 1);
            }
        }
        return len;
    }
};

// Solution 2: DP, improve solution 1 a bit with one pass
// O(2M) in space, O(N) in time
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        int M = 50000;
        vector<int> firstPos(M, -1), freq(M);
        int maxDegree = 0;
        int len = n;
        for(int i = 0; i < n; i ++) {
            if (firstPos[nums[i]] == -1) firstPos[nums[i]] = i;
            if (++freq[nums[i]] > maxDegree) {
                maxDegree = freq[nums[i]];
                len = i - firstPos[nums[i]] + 1;
            } else if (freq[nums[i]] == maxDegree) {
                len = min(len, i - firstPos[nums[i]] + 1);
            }
        }
        return len;
    }
};
