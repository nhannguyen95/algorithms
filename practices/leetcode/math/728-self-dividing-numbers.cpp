// https://leetcode.com/problems/self-dividing-numbers/

// Solution 1:
// D = number of self dividing numbers
// log_10(R) = maximum number of digits of each number
// => O(D*log_10(R)) in time
// O(D) in space - the length of result
class Solution {
public:
    bool isSelfDividingNumber(int x) {
        int t = x;
        while(t) {
            int digit = t % 10;
            if (digit == 0 || x % digit != 0) return false;
            t /= 10;
        }
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++)
            if (isSelfDividingNumber(i))
                ans.push_back(i);
        return ans;
    }
};
