// https://leetcode.com/problems/lemonade-change/

class Solution {
public:
    bool makeChange(int bill, map<int, int> & changes) {
        int change = bill - 5;
        for(auto it = changes.rbegin(); it != changes.rend(); it++) {
            while(change >= it->first && it->second > 0) {
                it->second--;
                change -= it->first;
            }
        }
        if (change == 0) {
            changes[bill]++;
            return true;
        }
        return false;
    }
    
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> changes = {{5, 0}, {10, 0}};
        for(int bill : bills) {
            bool possible = makeChange(bill, changes);
            if (!possible) return false;
        }
        return true;
    }
};
