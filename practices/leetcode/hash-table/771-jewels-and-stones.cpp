// Solution 1:
// N = len(J)
// M = len(S)
// O(N + M) in time
// O(N) in space
// Since J contains only letter
// => hash table never exceeds 24 + 24 characters
// => O(1) in space
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> jewels;
        for(char & c : J)
            jewels.insert(c);
            
        int nJewels = 0;
        for(char & c : S)
            nJewels += jewels.find(c) != jewels.end();
        return nJewels;
    }
};
