/* Selection sort (tested)

Time complexity:
  - All cases: O(N^2)

Space complexity: O(1)

NOT stable:
  - Because when we swap the current smallest element with
    A[i], we kind of change the position of A[i], this makes A[i] lose
    its relative position compared to other "A[i]".
  - We can squeeze the swap process by using linked-list to
    make the algorithm stable (i.e. instead of swap with A[i], we
    insert the value in between A[i-1] and A[i].

In-place

Compare to Insertion sort:
  - Advantage: on average case, let's say [0, i) is sorted. Insertion
    sort takes (i/2) swaps, while Selection sort takes (n - i) comparisions
    => so on average, IS performs half as many comparisions as SS.
  - Disadvantage: IS performs many writes (due to the swaps) than SS.

Compare to Bubble sort and Gnome sort: always faster.



Read more: https://nhannguyen95.github.io/selection-sort/

*/

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
