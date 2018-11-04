#include <iostream>
using namespace std;

class Stack {
private:
  unsigned int capacity;
  unsigned int size;
  int * arr;

public:
  Stack(int capacity) {
    this->capacity = capacity;
    arr = new int[capacity];
    size = 0;
  }

  void push(const int x) {
    if (isFull()) {
      cout << "Push: Stack is full!";
      return;
    }
    arr[size++] = x;
  }

  void pop() {
    if (isEmpty()) {
      cout << "Pop: Stack is empty!";
      return;
    }
    size--;
  }

  int top() {
    if (isEmpty()) {
      cout << "Top: Stack is empty!";
      return -1;
    }
    return arr[size - 1];
  }

  bool isEmpty() {
    return (size == 0);
  }

  bool isFull() {
    return (size == capacity);
  }

  unsigned int getSize() {
    return size;
  }
};

int main() {
  Stack stack(100);

  stack.push(2);
  cout << stack.getSize() << '\n';
  cout << stack.top() << '\n';

  stack.pop();
  cout << stack.isEmpty();
  
  return 0;
}
