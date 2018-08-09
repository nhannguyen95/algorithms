// Solution 1: dynamic programming
// Can use memoization technique to improve
class Solution {
public:
    bool endsWith(vector<int>& bits, int i, int c) {
        // Some base cases
        if (i < 0) return true;
        if (i < 1 && c == 1) return false;
            
        if (c == 0)
            return (bits[i] == 0) &&
                   (endsWith(bits, i-1, c) || endsWith(bits, i-1, 1-c));   
        
        return (bits[i-1] == 1) &&
               (endsWith(bits, i-2, c) || endsWith(bits, i-2, 1-c));
    }
    
    bool isOneBitCharacter(vector<int>& bits) {
        return endsWith(bits, bits.size()-1, 0);
    }
};

// Solution 2: I overthought! This problem is fucking simple
// O(N) in time, O(1) in space
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        while (i < bits.size() - 1) {
            i += bits[i] + 1;
        }
        return i == bits.size() - 1;
    }
};
