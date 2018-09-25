/* Queue implemented using array (tested)

Two operations of dynamic sets are implemented on queues:
  - INSERT(S, x) as ENQUEUE(Q, x) in O(1) time
  - DELETE(S, x) as DEQUEUE(Q) in O(1) time

*/

#include <iostream>
using namespace std;

class Queue {
private:
  int * A;
  int size;
  int head;
  int count;

  int getTail() {
    return (head + count) % size;
  }

  int nextIndex(int i) {
    return (i + 1) % size;
  }

public:
  Queue(int size) {
    this->size = size;
    head = 0;
    count = 0;
    this->A = new int[size];  // Denote 0 as empty cell
  }

  int front() {
    // Denote -1 as error code
    return isEmpty() ? -1 : A[head];
  }

  void enqueue(int x) {
    if (isFull()) return;
    int tail = getTail();
    A[tail] = x;
    count++;
  }

  int dequeue() {
    int x = front();
    if (x != -1) {  // Not empty
      A[head] = 0;  // Clear cell, not necessary
      head = nextIndex(head);
      count--;
    }
    return x;
  }

  bool isFull() {
    return count == size;
  }

  bool isEmpty() {
    return count == 0;
  }

  // Debug purpose only
  void print() {
    for(int i = 0; i < size; i++)
      cout << A[i] << ' ';
    cout << '\n';
  }
};

int main() {
  Queue q(5);

  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.print();

  q.dequeue();
  q.print();

  q.dequeue();
  q.print();

  q.enqueue(4);
  q.enqueue(5);
  q.print();

  q.enqueue(6);
  q.print();

  q.enqueue(7);
  q.print();

  q.dequeue();
  q.print();

  q.enqueue(8);
  q.print();

  return 0;
}
