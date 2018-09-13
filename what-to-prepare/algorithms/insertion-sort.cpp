/* Insertion sort (tested) 

Time complexity: 
  - T(N): the running time of the algorithm on an input of n values
    T(N) = aN^2 + b 
    => order of growth = N^2
    => running time of Θ(N^2)
    and: aN^2 + b ∈ Θ(N^2)
  - Best case: the array is already sorted, O(N)
  - Average: O(N^2)
  - Worst case: the array sorted in reverse order, O(N^2)
  
Space complexity: O(1)

Stable: keep the relative position of elements with equal keys.

Insertion sort is one of the fastest for sorting small arrays (N = 7..50), why?
  - Compare to Merge sort, Quick sort: they have some extra overhead,
    (while insertion sort is very simple):
    - Recursive calls
    - Partition: need to split N to two (N/2), and so on...
    - There are some swaps need to be taken care in each partition..
  - Compare to Selection sort, Bubble sort: probably faster because fewer scans,
    iterations..
    
i < j, A[i] > A[j] => (i, j) is an inversion of A.
Number of swaps in IS (when sort A) = number of inversion of A.
Prove: Hint: call I(i) = number of j | j < i and A[j] > A[j]

Read more: https://nhannguyen95.github.io/insertion-sort/

*/

// ----------------INCLUDE-----------------

#include <iostream>
#include <vector>
using namespace std;

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
