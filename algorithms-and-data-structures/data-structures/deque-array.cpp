/* Deque implementation using array

4 major operations:
  - INSERT(S, x) as PUSH_FRONT(D, s) and PUSH_BACK(D, s), O(1)
  - DELETE(S, x) as POP_FRONT(D) and POP_BACK(D), O(1)

*/

// ----------------INCLUDE-----------------

#include <iostream>
#include <exception>
using namespace std;

// --------------DEQUE ARRAY---------------

class Deque {
private:
  int * A;
  int size;
  int head;
  int count;

  int adjustIndex(int i) {
    return ((i % size) + size) % size;
  }

  int previousIndex(int i) {
    return adjustIndex(i - 1);
  }

  int nextIndex(int i) {
    return adjustIndex(i + 1);
  }

  int getTail() {
    return adjustIndex(head + count);
  }

public:
  Deque(int size) {
    this->size = size;
    A = new int[size];
    head = 0;
    count = 0;
  }

  int back() {
    if (isEmpty()) throw underflow_error("Deque is empty!");
    return A[previousIndex(getTail())];
  }

  int front() {
    if (isEmpty()) throw underflow_error("Deque is empty!");
    return A[head];
  }

  void push_back(int x) {
    if (isFull()) throw overflow_error("Deque is full!");
    A[getTail()] = x;
    count++;
  }

  void push_front(int x) {
    if (isFull()) throw overflow_error("Deque is full!");
    head = previousIndex(head);
    A[head] = x;
    count++;
  }

  int pop_back() {
    int x = back();
    count--;
    return x;
  }

  int pop_front() {
    int x = front();
    head = nextIndex(head);
    count--;
    return x;
  }

  bool isFull() {
    return count == size;
  }

  bool isEmpty() {
    return count == 0;
  }

  // Debug purpose only
  friend ostream& operator<<(
    ostream& os, const Deque & d) {
    for(int i = 0; i < d.size; i++)
      os << d.A[i] << ' ';
    os << '\n';
    return os;
  }
};

// ----------------------------------------

int main() {
  Deque d(5);

  d.push_back(1);
  cout << d;

  d.push_front(2);
  cout << d;

  d.push_front(3);
  cout << d;

  d.push_back(-1);
  cout << d;

  // Should be: 3 2 1 -1
  while(!d.isEmpty()) {
    cout << d.pop_front() << ' ';
  }
  cout << '\n';

  // Should be: -1 1 2 3
  // while(!d.isEmpty()) {
  //   cout << d.pop_back() << ' ';
  // }
  // cout << '\n';

  return 0;
}
