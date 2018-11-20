/* Quicksort (tested)

The running time of quicksort depends on whether the
partitioning is balanced or unbalanced, which in turn
depends on which elements are used for partitioning.

If balanced (p at mid):
  - T(n) = 2T(n/2) + Θ(n) => Θ(NlogN) in time (*)

If unbalanced (p bias to left or right):
  - T(n) = T(n-1) + Θ(n)  => Θ(N^2) in time  (**)
  - This worst case scenario happens when the
    array is already sort, p is always bias to right.

Therefore, the partition affects heavily to the time
complexity. You need to distinguish two kinds of
partition:
  - n -> (n - c) and c
    => T(n) = T(n-c) + Θ(n)
    => T(n) = O(n^2)

  - n -> n/k and n(1 - 1/k)
    It is shown that if the propotion k happens at
    every recursive level, the time complexity
    is still O(nlogn)
    (CLRS Balanced partitioning p.175, 176)

Compare to other algorithms:
  - Insertion sort beats Quicksort if the input array
    is "almost-sorted":
    If each element is at most c positions from its
    correct place in the sorted array. In insertion
    sort, each elements needs c swaps, so T(n) = O(cn)
    = O(n). While it's O(n^2) in quicksort.

We derive equation (*) and (**) only theorically, since
it's not true that we always achieve the same
propotion at every recursive level. A more rigorous
equation for both cases would be (randomized version):
  - Worst case: T(n) = max(T(q) + T(n-q-1)) + Θ(n)
                    (q = 0..n-1)
              => T(n) = Θ(n^2)
  - Expected running time: O(nlogn)
    Proof in CLRS p.181..184

NOT STABLE

IN-PLACE

*/

// ----------------INCLUDE-----------------

#include <iostream>
#include <vector>
#include <random>
using namespace std;

// ---------------QUICKSORT----------------

int partition(vector<int> & A, int l, int r) {
  /*
  Choose pivot = A[some element]
  Partition goal:
    - Put pivot in its correct position p (pivot = A[p])
    - Rearrange A so that A[l..p-1] <= A[p] <= A[p+1..r]
    - Return p as a splitting point

  Note:
    - This partition is actually Dutch National Flag
      algoritm that divide the array into 2 halves,
      each satifies a complementary condition.
    - A[l, p) <= pivot
      A[p, i) > pivot
      A[i, r] = unknown

    - Update: This is Lomuto partition scheme,
      we can also use Hoare partition scheme.
  */
  // FOR version
  // int pivot = A[r];
  // int p = l - 1;
  // for(int i = l; i < r; i++)
  //   if (A[i] <= pivot)
  //     swap(A[i], A[++p]);
  // swap(A[p+1], A[r]);
  // return p+1;

  // WHILE version
  int pivot = A[r];
  int e = r - 1;
  while(l <= e) {
    if (A[l] <= pivot) l++;
    else swap(A[l], A[e--]);
  }
  swap(A[l], A[r]);
  return l;
}

int random(int min, int max) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(min, max);
  return dis(gen);
}

int randomizedPartition(vector<int> & A, int l, int r) {
  int p = random(l, r);
  swap(A[p], A[r]);
  return partition(A, l, r);
}

void quicksort(vector<int> & A, int l, int r) {
  if (l >= r) return;

  // int m = partition(A, l, r);
  int m = randomizedPartition(A, l, r);
  quicksort(A, l, m-1);
  quicksort(A, m+1, r);
}

void quicksort(vector<int> & A) {
  quicksort(A, 0, A.size() - 1);
}

// -----------------HELPER-----------------

void printArray(const vector<int> & A) {
  for(int x : A) cout << x << ' ';
  cout << '\n';
}

// ----------------------------------------

int main() {
  vector<int> A({5,5,2,5});
  quicksort(A);
  printArray(A);
  return 0;
}
