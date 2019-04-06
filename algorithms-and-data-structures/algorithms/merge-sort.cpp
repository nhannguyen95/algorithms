/* Merge sort (tested)

Time complexity and Space complexity: read more
(Recurrence Equation: công thức truy hồi)

  - Θ(NlogN) time (in worst case)
  T(n) = C (if right == left => n = 1)
        = 2 T(n/2) + n
   T(n) = 2 T(n/2) + n = 2(2 T(n/4) + n/2) + n = 2^2 T (n / 2^2) + 2n
        = 2^2 (2 T(n / 2^3) + n / 2^2 ) + 2n
        = 2^3 T(n / 2^3) + 3n  ...
        = 2^logn T(n / 2^logn) + nlogn
        = Cn + nlogn
   => T(N) = Θ(NlogN) in time

   - O(N) space:
   S(n) = 1 (if right == left => n = 1)
   S(n) = S(n/2) + n = S(n/2^2) + n + n/2 = S(n/2^3) + n + n/2 + n/2^2 ..
        = S(n/2^logn) + n + n/2 + .. + n/2^(logn - 1)
        = n + n/2 + .. + n/2^(logn - 1) + n/2^logn
        = n(1 + 1/2 + .. + 1/2^logn) -> 2n
   => O(N) = N in space (not in-place)

Stable

Not in-place

Read more: https://nhannguyen95.github.io/merge-sort/

*/

// ----------------INCLUDE-----------------

#include <iostream>
#include <vector>
using namespace std;

// ----------MERGE SORT (TOP DOWN)---------

void merge(vector<int>& arr, int l, int m, int r) {
  // Merge 2 sorted sub arrays into tmp array.
  vector<int> tmp;
  int i = l, j = m + 1;
  while(i <= m && j <= r) {
    if (arr[i] <= arr[j]) tmp.push_back(arr[i++]);
    else tmp.push_back(arr[j++]);
  }

  while(i <= m) tmp.push_back(arr[i++]);
  while(j <= r) tmp.push_back(arr[j++]);

  // Copy sorted array tmp to unsorted arr[l..r].
  for(int k = 0; k < (int)tmp.size(); k++)
    arr[l + k] = tmp[k];
}

void mergeSort(vector<int>& arr, int l, int r) {
  // Base case
  if (l - r >= 0) return;

  int m = l + (r - l) / 2;
  mergeSort(arr, l, m);
  mergeSort(arr, m+1, r);
  merge(arr, l, m, r);
}

void mergeSort(vector<int>& arr) {
  mergeSort(arr, 0, (int)arr.size() - 1);
}

// ---------MERGE SORT (BOTTOM UP)---------
// Can be optimized to O(1) space complexity

void mergeSortBottomUp(vector<int>& arr) {
  int n = (int)arr.size();
  for(int width = 1; width < n; width *= 2) {
    // `arr` contains consecutives sub arrays of
    // length `width` that are already sorted.

    // Now we sort 2 consecutives sub arrays of
    // length `width` to obtain a sorted sub arrays
    // of length `2*width`.
    for(int i = 0; i < n; i += 2*width) {
      merge(arr, i, min(i + width - 1, n - 1), min(i + 2*width - 1, n - 1));
    }
  }
}

// ----------------------------------------

void printArray(const vector<int> & arr) {
  for(auto x : arr) cout << x << ' ';
  cout << '\n';
}

int main() {
  vector<int> arr({3,2,1});
  mergeSort(arr);

  printArray(arr);

  return 0;
}
