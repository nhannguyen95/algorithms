/* Suffix Array
(tested at https://www.spoj.com/problems/SARRAY/)

Suffix Array has similar funcitonalities as Suffix Tree but much
simpler to construct and use.

Suffix Array (SA) of a given string T of length n is an integer
array that stores a permutation of n indices of sorted suffixes of T.

For example T = "GATAGACA", its suffixes:

i    Suffix
0    GATAGACA
1    ATAGACA
2    TAGACA
3    AGACA
4    GACA
5    ACA
6    CA
7    A

Sort lexicographically to achieve Suffix Array SA:

i    SA[i]   Suffix
0    7       A         
1    5       ACA
2    3       AGACA
3    1       ATAGACA
4    6       CA  
5    4       GACA
6    0       GATAGACA
7    2       TAGACA

To build the Suffix Array of a string, we use the method
int CP3 p.255, 256 which takes O(Nlog^2N) in time.

Applications (similar as Suffix Trie):
- String matching: given a string P of length m,
find P in T in O(MlogN) time: find the suffix SA[i] whose
prefix is P using binary search.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class SuffixArray {
private:
  string s;
  int n, k;
  vector<int> sa, ra, rb;

  bool cmp(int i, int j) {
    int raik = (i + k < n) ? ra[i+k] : 0;
    int rajk = (j + k < n) ? ra[j+k] : 0;
    return (ra[i] < ra[j]) ||
           (ra[i] == ra[j] && raik < rajk);
  }

  void build() {
    for(int i = 0; i < n; i++) sa[i] = i;
    for(int i = 0; i < n; i++) ra[i] = s[i];
    for(k = 1; k < n; k <<= 1) {
      sort(sa.begin(), sa.end(), 
        [&](int i, int j) -> bool { return cmp(i, j); }
      );
      // we index rank from 1 (to n) to make all rank value 
      // greater than the rest of ra array (which is 0 by default)
      rb[sa[0]] = 1;
      for(int i = 1; i < n; i++)
        rb[sa[i]] = rb[sa[i-1]] + cmp(sa[i-1], sa[i]);
      for(int i = 0; i < n; i++)
        ra[sa[i]] = rb[sa[i]];
      if (ra[sa[n-1]] == n) break;
    }
  }

public:
  // O(Nlog^2N)
  SuffixArray(const string & s) {
    this->s = s;
    this->n = s.size();
    this->sa.assign(n, 0);
    this->ra.assign(n, 0);
    this->rb.assign(n, 0);
    build();
  }

  // String matching: O(MlogN)
  vector<int> find(const string & p) {
    pair<int, int> range;
    int m = p.size();
    vector<int> pos;

    // Find lower bound.
    int lo = 0, hi = n;
    while(lo < hi) {
      int mi = (lo + hi) / 2;
      if (s.compare(sa[mi], m, p) < 0) lo = mi+1;
      else hi = mi;
    }

    if (s.compare(sa[lo], m, p) != 0) return pos;
    range.first = lo;

    // Find upper bound.
    lo = -1, hi = n-1;
    while(lo < hi) {
      int mi = (lo + hi + 1) / 2;
      if (s.compare(sa[mi], m, p) > 0) hi = mi-1;
      else lo = mi;
    }

    range.second = hi;

    for(int i = range.first; i <= range.second; i++)
      pos.push_back(sa[i]);

    return pos;
  }

  void print() {
    for(int i = 0; i < n; i++)
      cout << sa[i] << ' ' << s.substr(sa[i]) << '\n';
    cout << '\n';
  }
};

int main() {
  string T = "GATAGACA";
  SuffixArray sa(T);
  sa.print();

  string P = "GA";
  vector<int> pos = sa.find(P);
  for(int i : pos) {
    cout << i << ' ' << T.substr(i) << '\n';
  }
  cout << '\n';

  return 0;
}

