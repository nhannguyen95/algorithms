// Solution 1
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n, 1);
        
        // Fill the first (k+1) values so that
        // they creates k distinct differences.
        int temp_k = k;
        for(int i = 1; i <= k; i++) {
            ans[i] = ans[i-1] + (((i % 2) == 1) ? temp_k : -temp_k);
            temp_k--;
        }
        
        // Fill the rest (n-k-1) values so that
        // their difference is 1.
        for(int i = k+1; i < n; i++)
            ans[i] = i + 1;
        
        return ans;
    }
};
