#include <iostream>
using namespace std;

class StackWithMin {
private:
  int capacity;
  int size, minSize;
  int* values;
  int* minValues;

  bool isMinEmpty() {
    return (minSize == 0);
  }

public:
  StackWithMin(int capacity) {
    this->capacity = capacity;
    size = minSize = 0;
    values = new int[capacity];
    minValues = new int[capacity];
  }

  void push(int value) {
    if (isFull()) {
      cout << "Push: stack is full!\n";
      return;
    }

    // Push to stack
    values[size++] = value;
    
    // Push to min stack
    if (isMinEmpty() || top() <= min()) {
      minValues[minSize++] = value;
    }
  }

  void pop() {
    if (isEmpty()) {
      cout << "Pop: stack is empty!\n";
      return;
    }

    // Remove from stack
    int value = top();
    size--;

    // Remove from min stack
    if (value == min()) {
      minSize--;
    }
  }

  int top() {
    if (isEmpty()) {
      cout << "Top: stack is empty!\n";
      return -1;
    }
    return values[size - 1];
  }

  int min() {
    if (isEmpty()) {
      cout << "Min: stack is empty!\n";
      return -1;
    }
    return minValues[minSize - 1];
  }

  bool isEmpty() {
    return (size == 0);
  }

  bool isFull() {
    return (size == capacity);
  }
};

int main() {
  StackWithMin stack(5);

  stack.push(4);
  stack.push(1);
  stack.push(3);
  stack.push(2);
  stack.push(1);
  cout << stack.top() << '\n';  // Should be 1
  cout << stack.min() << '\n';  // Should be 1

  stack.pop();  // 4 1 3 2
  cout << stack.min() << '\n';  // Should be 1
  
  stack.pop();  // 4 1 3
  cout << stack.min() << '\n';  // Should be 1

  stack.pop();  // 4 1
  cout << stack.min() << '\n';  // Should be 1

  stack.pop();  // 4
  cout << stack.min() << '\n';  // Should be 4

  stack.pop();  // Empty
  cout << stack.min() << '\n';  // Should have error

  return 0;
}
