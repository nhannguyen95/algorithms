// Solution 1: Top down dp
// O(N) in time and space
class Solution {
public:
    int minCost(int n, vector<int>& cost, vector<int>& memo) {
        if (n == 0 || n == 1) return 0;
        if (memo[n] != 0) return memo[n];
        return memo[n] = min(minCost(n-1, cost, memo)+cost[n-1], 
                             minCost(n-2, cost, memo)+cost[n-2]);
    }
        
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size()+1, 0);
        return minCost(cost.size(), cost, memo);
    }
};

// Solution 2: Bottom up
// O(N) in time and space
class Solution {
public: 
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size()+1, 0);
        for(int i = 2; i <= cost.size(); i++)
            memo[i] = min(memo[i-1]+cost[i-1], memo[i-2]+cost[i-2]);
        return memo[cost.size()];
    }
};

// Solution 3: improved bottom up
// O(N) in time, O(1) in space
class Solution {
public: 
    int minCostClimbingStairs(vector<int>& cost) {
        int curCost = 0, cost1 = 0, cost2 = 0;
        for(int i = 2; i <= cost.size(); i++) {
            curCost = min(cost1+cost[i-1], cost2+cost[i-2]);
            cost2 = cost1;
            cost1 = curCost;
        }
        return curCost;
    }
};
