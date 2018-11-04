// Solution 1
// O(N) in time, O(1) in space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPrice = INT_MAX;
        for(int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            if (prices[i] - minPrice > maxPro) 
                maxPro = prices[i] - minPrice;
        }
        return maxPro;
    }
};
