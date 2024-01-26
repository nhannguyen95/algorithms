## Problems
- https://leetcode.com/problems/closest-prime-numbers-in-range/

## Theory

```c++
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Check primability of numbers in [1, n]
// O(nloglogn)
vector<bool> sieve(const int n) {
  vector<bool> isPrime(n+1, true);
  isPrime[0] = isPrime[1] = false;
  for(int i = 2; i*i <= n; i++) {
    if (isPrime[i]) {
      for(int j = i*i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }
  return isPrime;
}

int main() {

  vector<bool> isPrime = sieve(100);

  for(int i = 1; i <= 100; i++) {
    if (isPrime[i])
      cout << i << '\n';
  }

  return 0;
}
```
