/*  Order statistic: Find k-th smallest number in an array
(tested)

Solution: utilize quicksort

Expected running time: E[T(n)] = O(n)

Worst case running time: Θ(n^2)
(There's a algorithm which can run linearly in worst case running time)

*/

// ----------------INCLUDE-----------------

#include <iostream>
#include <vector>
#include <cassert>
#include <random>
using namespace std;

// ----------------HELPERS-----------------

int random(int min, int max) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(min, max);
  return dis(gen);
}

int partition(vector<int> & A, int l, int r) {
  int p = l - 1;
  for(int i = l; i < r; i++)
    if (A[i] <= A[r])
      swap(A[i], A[++p]);
  swap(A[p+1], A[r]);
  return p+1;
}

int randomizedPartition(
  vector<int> & A, int l, int r) {
  int p = random(l, r);
  swap(A[p], A[r]);
  return partition(A, l, r);
}

// -----------RECURSIVE VERSION------------

int orderStatistic(
  vector<int> & A, int k, int l, int r) {
  int p = randomizedPartition(A, l, r);
  if (k-1 == p) return A[p];
  if (k-1 < p) return orderStatistic(A, k, l, p - 1);
  return orderStatistic(A, k, p + 1, r);
}

int orderStatistic(
  // Pass in a copy if you don't want to modify
  // the outside array.
  vector<int> A, int k) {
  assert(1 <= k && k <= A.size());
  return orderStatistic(A, k, 0, A.size() - 1);
}

// -----------RECURSIVE VERSION------------


int main() {
  vector<int> A({5,4,3,7,1});
  // 2nd smallest number, should be 3
  cout << orderStatistic(A, 2);
  return 0;
}
