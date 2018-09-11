/* Insertion sort (tested) */

// ----------------INCLUDE-----------------

#include <iostream>
#include <vector>
using namespace std;

// ----------------------------------------

// -------------INSERTION SORT-------------

void insertionSort(vector<int>& arr) {
  for(int i = 1; i < arr.size(); i++) {
    
    // sorted:   [0, i)
    // unsorted: [i, n)
    
    // insert arr[i] into sorted
    int j = i;
    while(j > 0 && arr[j - 1] > arr[j]) {
      swap(arr[j - 1], arr[j]);
      j--;
    }
  }
}

// ----------------------------------------

int main() {
  vector<int> arr({3,6,2,1,4}); 
  insertionSort(arr);
  
  return 0;
}
