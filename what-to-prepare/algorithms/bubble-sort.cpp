/* Bubble sort (tested) 

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
