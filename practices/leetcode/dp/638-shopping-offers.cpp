// Solution 1: Naive DP
class Solution {
public:
    // Return true if the amount of items in `needs` is good to buy the `offer`
    bool canBuyOffer(const vector<int> & offer, const vector<int> & needs) {
        for(int i = 0; i < needs.size(); i++) {
            if (needs[i] < offer[i]) return false;
        }    
        return true;
    }
    
    // Return `needs` - `offer`
    vector<int> subtract(const vector<int> & needs, const vector<int> & offer) {
        vector<int> remainings;
        for(int i = 0; i < needs.size(); i++) {
            remainings.push_back(needs[i] - offer[i]);
        }
        return remainings;
    }
    
    int dp(vector<int>& price, vector<vector<int>>& special, vector<int> needs) {
        // Case 1: we don't use any offer
        int lowestPrice = 0;
        for(int i = 0; i < needs.size(); i++) {
            lowestPrice += needs[i] * price[i];
        }
        
        // Case 2: use 1 offer
        for(int i = 0; i < special.size(); i++) {
            if (canBuyOffer(special[i], needs)) {
                lowestPrice = min(lowestPrice, dp(price, special, subtract(needs, special[i])) + special[i].back());
            }
        }
        
        return lowestPrice;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dp(price, special, needs);
    }
};

// Solution 2: Memo DP
class Solution {
public:
    // Return true if the amount of items in `needs` is good to buy the `offer`
    bool canBuyOffer(const vector<int> & offer, const vector<int> & needs) {
        for(int i = 0; i < needs.size(); i++) {
            if (needs[i] < offer[i]) return false;
        }    
        return true;
    }
    
    // Return `needs` - `offer`
    vector<int> subtract(const vector<int> & needs, const vector<int> & offer) {
        vector<int> remainings;
        for(int i = 0; i < needs.size(); i++) {
            remainings.push_back(needs[i] - offer[i]);
        }
        return remainings;
    }
    
    string state(const vector<int> & needs) {
        string key = "";
        for(int item : needs)
            key += to_string(item) + "#";
        return key;
    }
    
    int dp(vector<int>& price, vector<vector<int>>& special, vector<int> needs, unordered_map<string, int> & memo) {
        // If we already solved this state
        string key = state(needs);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        // Case 1: we don't use any offer
        int lowestPrice = 0;
        for(int i = 0; i < needs.size(); i++) {
            lowestPrice += needs[i] * price[i];
        }
        
        // Case 2: use 1 offer
        for(int i = 0; i < special.size(); i++) {
            if (canBuyOffer(special[i], needs)) {
                lowestPrice = min(lowestPrice, dp(price, special, subtract(needs, special[i]), memo) + special[i].back());
            }
        }
        
        return memo[key] = lowestPrice;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string, int> memo;
        return dp(price, special, needs, memo);
    }
};
