#include <iostream>
#include <vector>
using namespace std;

void update(vector<int> & p, int l, int r, int v) {
  p[l] += v;
  p[r+1] -= v;
}

int query(vector<int> & prefixSum, int l, int r) {
  return prefixSum[r] - prefixSum[l-1];
}

int main() {
  // We use 1-based indexing for not-verbose code.

  int N = 10;
  vector<int> a(N+1, 0);  // Can be init as random value

  // Update a[l..r] += v
  vector<int> p(N+1, 0);
  update(p, 1, 3, 1);
  update(p, 1, 6, -3);
  update(p, 5, 9, 7);
  for(int i = 1; i <= N; i++) {
    p[i] += p[i-1];         // p[i] is changed value of a[i] ()
    a[i] += a[i-1] + p[i];  // So: a[i] + p[i] now is the new value of a[i] after all updates,
                            // We store the prefix sum in `a` array itself.
  }
  
  // Query sum(a[l..r])
  cout << query(a, 1, 3) << '\n';  // Should be -6
  cout << query(a, 3, 5) << '\n';  // Should be -1

  return 0;
}
