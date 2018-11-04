// Solution 1: DP
// N = size(nums), Nu = size(unique(nums))
// Time complexity: O(NlogN) + O(Nu) + O(Nu)
// Space complexity: O(N) + O(2Nu) + O(Nu)= O(20000) + O(20000) + O(10000)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> M;
        for(int num : nums) M[num]++;
        
        vector<pair<int, int>> V;
        for(auto p : M) V.push_back(p);
        
        int n = V.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++) {
            int cur = V[i].first;
            int fre = V[i].second;
            if (i == 0) dp[i] = cur * fre;
            else {
                int pre = V[i-1].first;
                dp[i] = max(dp[i-1], cur*fre + (pre + 1 != cur ? dp[i-1] : i >= 2 ? dp[i-2] : 0));
            }
        }
        return dp[n-1];
    }
};

// Solution 2: DP
// Time complexity: O(N) + O(N)
// Space complexity: O(10001)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int count[10001];
        memset(count, 0, sizeof(count));
        for(int num : nums) count[num]++;

        int pre = -1, use = 0, avoid = 0;
        for(int num = 0; num < 10001; num++) {
            if (count[num] > 0) {
                int m = max(use, avoid);
                if (pre + 1 != num) {
                    use = num * count[num] + m;
                    avoid = m;
                } else {
                    use = num * count[num] + avoid;
                    avoid = m;
                }     
                pre = num; 
            }
        }
        return max(use, avoid);
    }
};
