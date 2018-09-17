/* Max Heap implementation

From wiki: A heap is a specialized tree-based data
structure that satisfies the heap property:
  - Key(Parent) >= Key(Children) if Max Heap, OR
  - Key(Parent) <= Key(Children) if Min Heap

A common implementation of a heap is the binary heap
(the tree is a binary tree)

Since majority operations of a heap is O(lgN),
any operation that affects the tree structure must
maintain the tree as a complete one. For example
when we Insert or Delete some element from the heap,
think about the way it interacts with the right-most
node at the last level of the tree (let's call this node 'extreme' node).

Heaps are usually implemented in an array, we will
implement a max-heap using an array.

If we use an array to imply a tree, so:
  - left(i) = 2i + 1        (if 1-based)
  - right(i) = 2i + 2       (if 1-based)
  - parent(i) = (i - 1) / 2 (if 1-based)
  - Important: so the last element of the array
    (the element with highest index) is the
    extreme node of the tree.

An advantage of implementing heap by an array
is that we can have the direct access to some element
(node) by its index, actually we don't really need
to access some middle element (it's more useful to
access only first element (root node) and last
element (extreme node)), but still, index makes
everything easier.

*/

// ----------------INCLUDE-----------------

#include <iostream>
#include <vector>
#include <climits>
#include <initializer_list>
using namespace std;

// ----------------MAX HEAP----------------

class MaxHeap {
private:
  vector<int> A;

  int left(int i) {
    return (i << 1) + 1;
  }

  int right(int i) {
    return (i << 1) + 2;
  }

  int parent(int i) {
    return (i - 1) / 2;
  }

  // O(lgn)
  // Condition: current A[i] <= key, since we are
  // 'bubble' this element up.
  // Kind of opposite of `heapify`
  void increaseKey(int i, int key) {
    A[i] = key;
    while(i > 0 && A[parent(i)] < A[i]) {
      A[i] = A[parent(i)];
      i = parent(i);
    }
    A[i] = key;
  }

  bool valid(int i) {
    return 0 <= i && i < size();
  }

  // O(lgn)
  // Float down element A[i]
  void heapify(int i) {
    while(valid(i)) {
      int l = left(i);
      int r = right(i);

      int largest = i;
      if (valid(l) && A[l] > A[largest])
        largest = l;
      if (valid(r) && A[r] > A[largest])
        largest = r;

      if (largest != i) {
        swap(A[i], A[largest]);
        i = largest;
      } else {
        break;
      }
    }
  }

public:
  // O(n)
  MaxHeap(initializer_list<int> l) {
    for(int e : l) insert(e);
  }

  // O(lgn)
  void insert(int key) {
    // This changes the structure of the implicit
    // tree such that the tree is expanding to
    // the extreme node, thus maintain its completeness
    //
    // I.e. the new slot is not created anywhere else
    // rather than next to the extreme node
    A.push_back(INT_MIN);
    increaseKey(size() - 1, key);
  }

  // O(1)
  int max() {
    if (size() == 0) return -1;
    return A[0];
  }

  // O(lgn)
  int extractMax() {
    int mx = max();
    if (mx != -1) {
      A[0] = A.back();
      A.pop_back();
      heapify(0);
    }
    return mx;
  }

  int size() {
    return A.size();
  }

  // O(lgn)
  void remove(int i) {
    if (!valid(i)) return;
    A[i] = A.back();
    A.pop_back();
    heapify(i);
  }

  // This methods just for testing
  void printArray() {
    for(auto x : A)
      cout << x << ' ';
    cout << '\n';
  }
};

// -----------------LINEAR-----------------

int main() {
  // Build a heap of some elements.
  MaxHeap heap({4,10,3,2,5,3,1});

  // Test some operations.
  heap.printArray();

  // Remove an element
  heap.remove(1);

  // Should be in descending order.
  // 10 4 3 3 2 1
  while(heap.size() > 0) {
    cout << heap.extractMax() << ' ';
  }

  return 0;
}
