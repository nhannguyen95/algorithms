// Solution 1: binary search to the right
class Solution {
public:
    int mySqrt(int x) {
        // Find max y such that y^2 = x
        int lo = 0;
        int hi = x;
        while(lo < hi) {
            int dt = hi - lo;
            int mi = lo + dt / 2 + (dt % 2);
            
            if (mi <= x / mi) lo = mi;
            else hi = mi - 1;
        }
        return lo;
    }
};

// Solution 2: binary search to the left
class Solution:
    def mySqrt(self, x: int) -> int:
        lo = 1
        hi = x + 1
        while lo < hi:
            mi = (lo + hi) // 2
            if mi * mi > x: hi = mi
            else: lo = mi + 1
        return hi - 1
