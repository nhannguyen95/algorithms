/*  Counting sort (tested)

Given n-element array in the range of k

Time complexity: O(n+k)

Space complexity: O(n+k)

NOT IN-PLACE

STABLE:
  Note that in the for statement (*), the stability
  of the algorithm doesn't depend on the direction
  of this for loop, but on the data structure used
  to store the frequency instead (freq) in this case
  (i.e. whether it's FILO or FIFO).

*/

// ----------------INCLUDE-----------------

#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <vector>
using namespace std;

// -------------COUNTING SORT--------------

void countingSort(vector<int> & A) {
  // Base case
  if (A.size() == 0) return;

  // A[i] in [0..k]
  int k = *max_element(A.begin(), A.end());
  vector<int> freq(k+1, 0);

  // Count frequency
  for(int e : A) freq[e]++;

  // freq[e] = number of elements <= e
  for(int i = 0; i <= k; i++)
    freq[i] += freq[i-1];

  // Put elements to correct position
  vector<int> B(A.size(), 0);
  for(int i = A.size() - 1; i >= 0; i--) {  /* (*) */
    // If element e has C[e] frequency,
    // then correct position of e in sorted array
    // in at index C[e]
    B[freq[A[i]]] = A[i];

    // Next equal element is placed right before that.
    freq[A[i]]--;
  }
}

// -----------------HELPER-----------------

void printArray(const vector<int> & A) {
  for(int x : A) cout << x << ' ';
  cout << '\n';
}

// ----------------------------------------

int main() {
  vector<int> A({5,3,6,1});
  countingSort(A);
  printArray(A);
  return 0;
}
