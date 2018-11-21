/* 

Fenwick Tree is a useful data structure for implementing
dynamic cumulative frequency tables.

First we need to understand what (x & (-x)) mean, since
negative numbers are in C++ are represented by 2's complement:
x & (-x) = x & (~x + 1)
For example:
        x = 1011010100
       ~  = 0100101011
       +1 = 0100101100
=> x & -x = 0000000100
=> x & -x returns the Least Significant One-bit of x.

We denote x & (-x) = LSOne(x)

Consider the Range Sum Query problem: you are given an array
A of size n, 2 kinds of query:
- update i, v: update A[i] = v
- query l, r: return sum(A[l..r])

The Fenwick Tree will have an array ft of [1..n] nodes,
the node at index i-th is responsible for elements in the range
of [i-LSOne(i)+1 .. i], meaning that in this problem:
ft[i] = sum(A[i-LSOne(i)+1..i])

With this arrangement, we can obtain the cumulative sum of A[1..b]
by adding:
  ft[b]
+ ft[b'  = b - LSOne(b)]
+ ft[b'' = b' - LSOne(b')]
(.. until the index != 0)
(Easily see this runs in O(logN))

Having sum of A[1..b], we can query sum of A[l..r]

How about update A[b] = v? We need to update the nodes that are
responsible for the range that contains b too, starting from b-th:
update ft[b]
update ft[b'  = b + LSOne(b)]
update ft[b'' = b' + LSOne(b')]
(.. until the index > n)
(Easily see this runs in O(logN))

In summary, Fenwick Tree takes:
- O(N) in space
- O(logN) for update, query 
*/

#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
private:
  vector<int> ft;  // 1-based index.
  int n;

  int lsone(int b) { return b & (-b); }

public:
  FenwickTree(const vector<int> & _A) {
    n = _A.size();
    ft.assign(n + 1, 0);
    for(int b = 0; b < n; b++)
      update(b+1, _A[b]);
  }

  void update(int b, int newv) {
    int delta = -query(b, b) + newv;
    for(; b <= n; b += lsone(b))
      ft[b] += delta;
  }

  int query(int b) {
    int sum = 0;
    for(; b; b -= lsone(b))
      sum += ft[b];
    return sum;
  }

  int query(int l, int r) {
    return query(r) - (l <= 1 ? 0 : query(l - 1));
  }
};

int main() {
  vector<int> A({1,2,3});
  FenwickTree ft(A);

  cout << ft.query(1) << '\n';  // 1
  cout << ft.query(2) << '\n';  // 3
  cout << ft.query(3) << '\n';  // 6

  ft.update(2, 10);
  cout << ft.query(2, 3) << '\n';  // 13
 
  return 0;
}
