/* D-ary max heap implementation (tested)

In D-ary performs faster SiftUp operation than binary heap, at the expense of slower SiftDown operation.

This tradeoff leads to better running times for algorithms such as Dijkstra's algorithm.

Additionally, d-ary heaps have better memory cache behavior than binary heaps, allowing them to run more quickly in practice despite having a theoretically larger worst-case running time.

*/

// ----------------INCLUDE-----------------

#include <iostream>
#include <initializer_list>
#include <vector>
#include <climits>
using namespace std;

// -------------D-ARY MAX HEAP-------------

class DHeap {
private:
  int d;
  vector<int> A;  // 0-based

  bool valid(int i) {
    return 0 <= i && i < A.size();
  }

  // SiftDown: O(d log_d(n))
  void heapify(int i) {
    while(valid(i)) {
      int largest = i;
      for(int j = d*i+1; j <= d*i+d; j++)
        if (valid(j) && A[largest] < A[j])
          largest = j;
      
      if (largest != i) {
        swap(A[i], A[largest]);
        i = largest;
      } else {
        break;
      }
    }
  }

  // SiftDown
  void remove(int i) {
    if (!valid(i)) return;
    swap(A[i], A.back());
    A.pop_back();
    heapify(i);
  }

  int parent(int i) {
    return (i - 1) / d;
  }

  // SiftUp: O(log_d(n))
  void increaseKey(int i, int newKey) {
    if (A[i] >= newKey) return;
    A[i] = newKey;
    while(i > 0 && A[i] > A[parent(i)]) {
      swap(A[i], A[parent(i)]);
      i = parent(i);
    }
  }

public:
  // O(n)
  DHeap(int d, initializer_list<int> l) {
    this->d = d;
    for(int key : l) A.push_back(key);
    for(int i = A.size() - 1; i >= 0; i--)
      heapify(i);
  }

  // O(1)
  int max() {
    return (size() == 0) ? -1 : A[0];
  }

  int extractMax() {
    int mx = max();
    if (size()) remove(0);
    return mx;
  }

  void insert(int key) {
    A.push_back(INT_MIN);
    increaseKey(size() - 1, key);
  }

  int size() {
    return A.size();
  }

  // Only for debug purpose
  void printArray() {
    for(int & key : A) cout << key << ' ';
    cout << '\n';
  }
};

// ----------------------------------------

int main() { 
  DHeap heap(4, {5,3,6,4,1});  // 4-ary max heap

  heap.printArray();

  cout << heap.max() << '\n';  // Should be 6

  heap.extractMax();
  cout << heap.max() << '\n';  // Should be 5

  heap.insert(10);
  cout << heap.max() << '\n';  // Should be 10

  while(heap.size()) {
    cout << heap.extractMax() << '\n';
  }


  return 0;
}
