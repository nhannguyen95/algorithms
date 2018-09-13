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
  int n = (int)arr.size();
  for(int k = 1; k < n; k++) {
    // Now we bring the k-th largest element
    // to the end of the array (i.e. to the
    // (n-k) index)
    bool hasSwap = false;
    for(int i = 0; i < n-k; i++)
      if (arr[i] > arr[i+1]) {
        swap(arr[i], arr[i+1]);  // bubble up
        hasSwap = true;
      }
    
    // Break if there's no more swap
    if (!hasSwap) return;
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
