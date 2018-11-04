#include <iostream>
using namespace std;

class Node {
private:
  int val;
  Node* next;
  Node(int x) : val(x), next(NULL) {}

  friend class Queue;
};

class Queue {
private:
  unsigned int size;
  Node* head;
  Node* tail;

public:
  Queue() : size(0), head(NULL), tail(NULL) {}

  void push(const int x) {
    if (isEmpty()) {
      head = tail = new Node(x);
    } else {
      tail->next = new Node(x);
      tail = tail->next;
    }
    size++;
  }

  void pop() {
    if (isEmpty()) {
      cout << "Pop: Queue is empty!";
      return;
    }
    Node* temp = head;
    head = head->next;
    if (head == NULL) tail = NULL;
    delete temp;
    size--;
  }

  int front() {
    if (isEmpty()) {
      cout << "Front: Queue is empty!";
      return -1;
    }
    return head->val;
  }

  bool isEmpty() {
    return (size == 0);
  }

  unsigned int getSize() {
    return size;
  }

};

int main() {  
  Queue queue;
  queue.push(2);
  queue.push(3);
  cout << queue.front() << '\n';
  cout << queue.getSize() << '\n';

  queue.pop();
  cout << queue.getSize() << '\n';
  cout << queue.isEmpty() << '\n';

  return 0;
}
