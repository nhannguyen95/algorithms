/* Selection sort (tested) */

// ----------------INCLUDE-----------------

#include <iostream>
#include <vector>
using namespace std;

// -------------SELECTION SORT-------------

void selectionSort(vector<int>& arr) {
  for(int i = 0; i < (int)arr.size() - 1; i++) {
    // Sorted: [0, i-1)
    // Unsorted: [i, n)
    
    // "Select" the minimum element in [i, n)
    int minId = i;
    for(int j = i + 1; j < arr.size(); j++)
      if (arr[j] < arr[minId]) minId = j;
    
    // Swap it with the element at i
    swap(arr[i], arr[minId]);
  }
}

// ----------------------------------------

void printArray(const vector<int> & arr) {
  for(auto x : arr) cout << x << ' ';
  cout << '\n';
}

int main() {
  vector<int> arr({3,2,1}); 
  selectionSort(arr);
  
  printArray(arr);

  return 0;
}
