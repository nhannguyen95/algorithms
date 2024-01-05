// This is submitted on https://bit.ly/2zm7iH0
// Segment Tree solving RMQ (Range Minimum Query) problem
// TODO: Segment Tree to support range_update(l, r, v) in
// O(logN) with Lazy Propagation, CP4.1.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
private:
  vector<int> st, A;
  int n;
  
  int left(int p) { return (p << 1) + 1; }

  int right(int p) { return (p << 1) + 2; }
    
  // O(N)
  void build(int p, int l, int r) {
    if (l == r) st[p] = A[l];
    else {
      int m = (l + r) / 2;
      build(left(p), l, m);
      build(right(p), m+1, r);
      st[p] = min(st[left(p)], st[right(p)]);
    }
  }

  // O(logN)
  int query(int p, int l, int r, int i, int j) {
    if (r < i || j < l) return INT_MAX;
    if (l >= i && r <= j) return st[p];

    int m = (l + r) / 2;
    int p1 = query(left(p), l, m, i, j);
    int p2 = query(right(p), m+1, r, i, j);
    return min(p1, p2);
  }

  // O(logN)
  void update(int p, int l, int r, int i, int v) {
    if (i < l || i > r) return;
    if (l == r) {
        A[i] = v;
        st[p] = v;
    }
    else {
      int m = (l + r) / 2;
      update(left(p), l, m, i, v);
      update(right(p), m+1, r, i, v);
      st[p] = min(st[left(p)], st[right(p)]);
    }
  }

public:
  SegmentTree(const vector<int> & _A) {
    A = _A; n = _A.size();
    st.assign(4*n, 0);  // 2n is enough, but we use a loose upper bound
                        // of space complexity
    build(0, 0, n-1);
  }

  int query(int l, int r) {
    return query(0, 0, n-1, l, r);
  }

  void update(int i, int v) {
    update(0, 0, n-1, i, v);
  }

};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);    
    
  int N, Q;
  cin >> N >> Q;

  vector<int> A;
  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    A.push_back(x);
  }

  SegmentTree st(A);
  while(Q--) {
    char c; cin >> c;
    if (c == 'q') {
      int l, r;
      cin >> l >> r;
      cout << st.query(--l, --r) << '\n';
    } else {
      int i, v;
      cin >> i >> v;
      st.update(--i, v);
    }
  }

  return 0;
}
