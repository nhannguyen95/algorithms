#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

class MyQueue {
private:
  stack<int> newStack;  // Contain new elements
  stack<int> oldStack;  // Contain old elements

  void shiftStacks() {
    if (oldStack.empty()) {
      while(!newStack.empty()) {
        oldStack.push(newStack.top());
        newStack.pop();
      }
    }
  }
public:
  int front() {
    // Ensure oldStack has the current elements.
    shiftStacks();

    if (!oldStack.empty())
      return oldStack.top();
    exit(1);
  }

  void pop() {
    // Ensure oldStack has the current elements.
    shiftStacks();

    if (!oldStack.empty()) {
      oldStack.pop();
      return;
    }
    exit(1);
  }

  void push(int x) {
    newStack.push(x);
  }
};

int main() {
  MyQueue queue;

  queue.push(1);
  queue.push(2);
  cout << queue.front() << '\n';  // Should be 1
  
  queue.pop();
  cout << queue.front() << '\n';  // Should be 2

  queue.push(3);
  queue.pop();
  cout << queue.front() << '\n';  // Should be 3

  return 0;
}
