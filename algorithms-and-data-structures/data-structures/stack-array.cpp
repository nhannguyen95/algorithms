/* Stack implementation using array (tested)

Two operations of dynamic sets are implemented on stacks:
  - INSERT(S, x) as PUSH(S, x) in O(1) time
  - DELETE(S, x) as POP(S) in O(1) time

*/

// ----------------INCLUDE-----------------

#include <iostream>
#include <exception>
using namespace std;

// --------------STACK ARRAY---------------

class Stack {
private:
  int * A;
  int _top;
  int size;

public:
  Stack(int size) {
    this->size = size;
    _top = -1;
    A = new int[size];
  }

  int top() {
    if (isEmpty()) throw underflow_error("Stack is empty!");
    return A[_top];
  }

  void push(int x) {
    if (isFull()) throw overflow_error("Stack is full!");
    A[++_top] = x;
  }

  int pop() {
    int x = top();
    A[_top--] = 0;
    return x;
  }

  bool isFull() {
    return _top + 1 == size;
  }

  bool isEmpty() {
    return _top == -1;
  }

  // Debug purpose only
  friend ostream& operator<<(
    ostream& os, const Stack & s) {
    for(int i = 0; i < s.size; i++)
      os << s.A[i] << ' ';
    os << '\n';
    return os;
  }
};

// ----------------------------------------

int main() {
  Stack s(3);

  // s.top();  // Should throw exception

  s.push(1);
  cout << s;

  s.pop();
  cout << s;
  // s.pop();  // Should throw exception

  s.push(1);
  s.push(2);
  s.push(3);
  cout << s;

  s.push(4);
  cout << s;

  s.pop();
  cout << s;
  cout << s.top();

  return 0;
}
