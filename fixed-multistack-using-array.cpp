#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class FixedMultiStack {
private:
  int numberOfStacks = 3;
  int stackCapacity;
  int* sizes;
  int* values;

  int indexAtTop(int stackNum) {
    int offset = stackNum * stackCapacity;
    int size = sizes[stackNum];
    return offset + size - 1;
  }

public:
  FixedMultiStack(int stackCapacity) {
    this->stackCapacity = stackCapacity;
    sizes = new int[numberOfStacks];
    values = new int [numberOfStacks * stackCapacity];

    // memset(sizes, 0, sizeof sizes);
    for(int i = 0; i < numberOfStacks; i++)
      sizes[i] = 0;
  }

  void push(int x, int stackNum) {
    if (isFull(stackNum)) {
      printf("Push: stack %d is full!\n", stackNum);
      return;
    }
    sizes[stackNum]++;
    values[indexAtTop(stackNum)] = x;
  }

  void pop(int stackNum) {
    if (isEmpty(stackNum)) {
      printf("Pop: stack %d is emtpy!", stackNum);
      return;
    }
    sizes[stackNum]--;
  }

  int top(int stackNum) {
    if (isEmpty(stackNum)) {
      printf("Top: stack %d is empty!\n", stackNum);
      return -1;
    }
    return values[indexAtTop(stackNum)];
  }

  bool isEmpty(int stackNum) {
    return (sizes[stackNum] == 0);
  }

  bool isFull(int stackNum) {
    return (sizes[stackNum] == stackCapacity);
  }

  bool getSize(int stackNum) {
    return sizes[stackNum];
  }
};

int main() {  
  FixedMultiStack stacks(1);  // Define 3 stacks, capacity of each is 1.

  stacks.push(7, 0);
  cout << stacks.getSize(0) << '\n';
  cout << stacks.getSize(1) << '\n';
  cout << stacks.getSize(2) << '\n';

  stacks.push(8, 1);
  stacks.push(9, 2);
  cout << stacks.top(0) << '\n';
  cout << stacks.top(1) << '\n';
  cout << stacks.top(2) << '\n';

  stacks.push(10, 0);  // Should have warning!

  stacks.pop(1);
  cout << stacks.getSize(0) << '\n';
  cout << stacks.getSize(1) << '\n';
  cout << stacks.getSize(2) << '\n';

  return 0;
}
