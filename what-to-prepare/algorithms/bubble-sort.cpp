/* Bubble sort (tested) 

Time complexity:
  - Best case: already sorted array, O(N)
  - Average & Worst case: O(N^2)

Space complexity: O(1)

Stable: Swapping 2 consecutive different elements doesn't change
their relative position to same key elements.

BS is impratical and too slow.

BS and IS all have the advantage over other algorithms: the ability
to detect that the list is sorted efficiently is built into the algorithm.

We iterate and swap the array from left to right:
  - An element whose correct position is in the right will move quickly.
  - An element whose correct position is in the left will move slower.

Read more: https://nhannguyen95.github.io/bubble-sort/
*/

// ----------------INCLUDE-----------------

#include <iostream>
#include <vector>
using namespace std;

// ---------------BUBBLE SORT--------------

void bubbleSort(vector<int>& arr) {
  // arr[0..n): unsorted
  for(int n = (int)arr.size(); n > 0; n--) {
    // Bring largest element in arr[0, n) to (n-1) position
    bool hasSwap = false;
    for(int i = 1; i < n; i++)
      if (arr[i-1] > arr[i]) {
        swap(arr[i-1], arr[i]);
        hasSwap = true;
      }

    // Break if there's no swap
    if (!hasSwap) break;
  }
}

// ----------OPTIMIZED BUBBLE SORT---------
// Idea: At k-th iteration, there are not neccessarily
// only k (largest) elements placed at their correct position
// (at the end of the array), but maybe more, maybe we have 
// k' elements at their corrected position.

// k' is at the last swap at current iteration.

void optimizedBubbleSort(vector<int>& arr) {
  // arr[0, n): unsorted
  for(int n = (int)arr.size(); n > 0; ) {
    int newn = 0;
    for(int i = 1; i < n; i++)
      if (arr[i-1] > arr[i]) {
        swap(arr[i-1], arr[i]);
        newn = i;
      }
    n = newn;
  }
}

// ----------------------------------------

void printArray(const vector<int> & arr) {
  for(auto x : arr) cout << x << ' ';
  cout << '\n';
}

int main() {
  vector<int> arr({3,2,1}); 
  bubbleSort(arr);
  printArray(arr);
  
  return 0;
}
