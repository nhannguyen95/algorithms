/* Merge sort (tested) */

// ----------------INCLUDE-----------------

#include <iostream>
#include <vector>
using namespace std;

// ---------------MERGE SORT---------------

void merge(vector<int>& arr, int l, int m, int r) {
  // Merge 2 sorted sub arrays into tmp array.
  vector<int> tmp;
  int i = l, j = m + 1;
  while(i <= m && j <= r) {
    if (arr[i] < arr[j]) tmp.push_back(arr[i++]);
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
