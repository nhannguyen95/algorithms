// Solution 1: DP
// O(3N) in space, O(N) in time
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<long long>> f(n, vector<long long>(3, 0));
        enum STATE { SELL = 0, BUY = 1, NO = 2 };
        long long res = 0, maxPreBuy = LONG_LONG_MIN;
        for(int i = 0; i < n; i++) {
            if (i == 0) {
                // Seed
                f[i][NO] = f[i][SELL] = 0;
                f[i][BUY] = -prices[i]-fee;
            } else {
                f[i][BUY] = max(f[i-1][SELL], f[i-1][NO])-prices[i]-fee;
                f[i][SELL] = maxPreBuy + prices[i];
                f[i][NO] = max(f[i-1][NO], f[i-1][SELL]);
            }
            maxPreBuy = max(maxPreBuy, f[i][BUY]);
            res = max(res, max(f[i][SELL], f[i][NO]));
        }
        return res;
    }
};

// Solution 2: DP + No space
// O(N) in time, O(1) in space
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        long long preBuy = 0, preSell = 0, preNo = 0;
        long long res = 0, maxPreBuy = LONG_LONG_MIN;
        for(int i = 0; i < n; i++) {
            long long curBuy, curSell, curNo;
            if (i == 0) {
                // Seed
                curSell = curNo = 0;
                curBuy = - prices[i] - fee;
            } else {
                curBuy = max(preSell, preNo) - prices[i] - fee;
                curSell = maxPreBuy + prices[i];
                curNo = max(preNo, preSell);
            }
            maxPreBuy = max(maxPreBuy, curBuy);
            res = max(res, max(curSell, curNo));
            
            preBuy = curBuy;
            preSell = curSell;
            preNo = curNo;
        }
        return res;
    }
};

// Solution 3: A more subtle DP
// O(N) in time, O(1) in space
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];
        for(int i = 1; i < prices.size(); i++) {
            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};
