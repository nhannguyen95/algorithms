// Solution 1: Deduce from dp
// O(1) in space, O(N) in time
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        
        int buy = -prices[0];
        int sell = 0;
        for(int i = 1; i < prices.size(); i++) {
            int curSell = max(sell, buy + prices[i]);
            int curBuy = max(buy, sell - prices[i]);
            
            sell = curSell;
            buy = curBuy;
        }
        return max(sell, buy);
    }
};
