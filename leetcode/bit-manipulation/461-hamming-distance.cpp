// Solution 1: O(32) in time, O(1) in space
class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        for(int d = x ^ y; d; d &= (d-1))
            distance++;
        return distance;
    }
};
