/* 

Fenwick Tree is a useful data structure for implementing
dynamic cumulative frequency tables.

First we need to understand what (x & (-x)) mean, since
negative numbers in C++/Java are represented by 2's complement:
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
- point_update(i, v): update A[i] += v (v can be positive or negative)
- range_query(l, r): return sum(A[l..r])

The default Fenwick Tree that supports these 2 operations is
widely known as Point Update and Range (Sum) Query (PURQ) Fenwick Tree.

The Fenwick Tree will have an array ft of [1..n] nodes,
the node at index i-th is responsible for elements in the range
of [i-LSOne(i)+1 .. i], meaning that in this problem:
ft[i] = sum(A[i-LSOne(i)+1..i])

With this arrangement, we can calculate range_query(l, r) from
range_query(b) which is the cumulative sum of A[1..b] by adding:
  ft[b]
+ ft[b'  = b - LSOne(b)]
+ ft[b'' = b' - LSOne(b')]
(.. until the index = 0)
(Easily see this runs in O(logN))
By doing this, f[i] is responsible for disjoint ranges of A.

Having sum of A[1..b], we can query sum of A[l..r]

How about update A[b] += v? We need to update the nodes that are
responsible for the ranges that contain b too, starting from b-th:
update ft[b]
update ft[b'  = b + LSOne(b)]
update ft[b'' = b' + LSOne(b')]
(.. until the index > n)
(Easily see this runs in O(logN))
By doing this, f[i >= b] is responsible for parent ranges of ft[b].
Proff: denote b' = b + LSOne(b), we prove 2 things:
- Range represented by ft[b'] covers range represented by ft[b].
  Proof: This can be easily to point out. For example:
  ft[010010] covers [010001..010010]
  ft[010100] covers [010001..010100]
- Range represented by ft[b'-LSOne(b')] is disjoint with range represented by
  ft[b].
  Proof: By definition of ft, ft[b'] is disjoint with ft[b'-LSOne(b')], and
  since ft[b] is within ft[b'] (proved above) => ft[b] is disjoint with
  ft[b'-LSOne(b')].


In summary, Fenwick Tree takes:
- O(N) in space
- O(logN) for update, query 
- O(NlogN) for build

Besides summation, BIT can also be used to support other types of
operations, e.g. dynamic range minimum query (RMQ), while
maintaining the same time complexity of O(logN), but require more
complicated implementation:
https://ioinformatics.org/journal/v9_2015_39_44.pdf

------------------------------------------------------------------

Range Update Point Query (RUPQ) Fenwick Tree:
- range_update(l, r, v): update A[l..r] += v (v can be
positive/negative) in O(logN).
- point_query(i): return A[i] in O(logN).

For the range update operation, the idea is to perform 2 updates:
- update(l, v): makes all indices in [l..n] have +v value.
- update(r+1, -v): makes all indices in [r+1..n] have -v value,
canceling previous update.

For the Point Query operation, now if we query range_query(i), we
will correctly get A[i].

------------------------------------------------------------------

Range Update Range Query (RURQ) Fenwick Tree:
- range_update(l, r, v): update A[l..r] += v(v can be
positive/negative).
- range_query(l, r): return sum(A[l..r]).

TODO: CP 4.1.

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
  // O(nlogn)
  FenwickTree(const vector<int> & _A) {
    n = _A.size();
    ft.assign(n + 1, 0);
    for(int b = 0; b < n; b++)
      update(b+1, _A[b]);
  }

  void update(int b, int v) {
    for(; b <= n; b += lsone(b))
      ft[b] += v;
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
  cout << ft.query(2, 3) << '\n';
 
  return 0;
}
