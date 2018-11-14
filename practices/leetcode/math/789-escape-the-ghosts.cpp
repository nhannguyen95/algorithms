// https://leetcode.com/problems/escape-the-ghosts/

// Solution 1:
// O(1) in space
// O(len(ghosts)) in time
class Solution {
public:
    int distance(vector<int> a, vector<int> b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);    
    }
    
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int youToDes = distance(vector<int>({0, 0}), target);
        for(auto & ghost : ghosts) {
            int ghostToDes = distance(ghost, target);
            if (ghostToDes <= youToDes) return false;
        }
        return true;
    }
};
