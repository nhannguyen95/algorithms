// Solution 1: divide and conquer, recursive
// O(logN) in time and space
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) return 1/x * 1/myPow(x, -(n+1));
        if (n == 0) return 1.0;
        double half = myPow(x, n / 2);
        if (n % 2 == 0) return half * half;
        return half * half * x;
    }
};

// Solution 2: iterative
// O(1) in space, O(logn) in time
// Think like this:
// First iteration x ^ n
// 2nd iteration: (x^2) ^ (n/2)
// 3rd iteration: ((x^2)^2)^((n/2)/2)
// The res value at each time will take care of odd-n cases
double myPow(double x, int n) {
  unsigned int posn = abs(n);
  double res = 1;
  while(posn) {
      if ((posn & 1) == 1) {  // Odd
          res = res * x;
      }
      posn >>= 1;
      x *= x;
  }
  return (n < 0) ? 1 / res : res;
}
