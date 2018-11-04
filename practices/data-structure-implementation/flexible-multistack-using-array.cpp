#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class MultiStack {
private:
  class StackInfo {
  private:
    MultiStack* multiStack;
    int start, size, capacity;
    friend class MultiStack;
  
  public:
    StackInfo() : start(0), size(0), capacity(0), multiStack(NULL) {}

    StackInfo(int start, int capacity, MultiStack* multiStack) {
      this->start = start;
      this->capacity = capacity;
      size = 0;
      this->multiStack = multiStack;
    }

    bool isFull() {
      return (size == capacity);
    }

    int lastCapacityIndex() {
      return multiStack->adjustIndex(start + capacity - 1);
    }

    int lastElementIndex() {
      return multiStack->adjustIndex(start + size - 1);
    }

    // Check if an index on the full array is withing the stack boundaries. The stack can wrap around to the start of the arry.
    bool isWithinStackCapacity(int index) {
      // If outside of bounds of array, return false.
      if (index < 0 || index >= multiStack->capacity)
        return false;

      // If index wraps around, adjust it.
      int contiguousIndex = index < start ? index + multiStack->capacity : index;
      int end = start + capacity;
      return start < contiguousIndex && contiguousIndex < end;
    }

    // index = 1, start = 0, end = 2
    // contiguousIndex = 1 => ok
    //
    // index = 0, start = 0, end = 2
    // contiguousIndex = 
    // 1 1 2 

    bool isEmpty() {
      return (size == 0);
    }
  };

  int capacity;
  int numberOfStacks;
  StackInfo* info;
  int* values;

public:
  MultiStack(int numberOfStacks, int defaultSize) {
    this->numberOfStacks = numberOfStacks;
    this->capacity = numberOfStacks * defaultSize;
    info = new StackInfo[numberOfStacks];
    for(int i = 0; i < numberOfStacks; i++)
      info[i] = StackInfo(i * defaultSize, defaultSize, this);
    values = new int[this->capacity];
  }

  /* Push value onto stack num, shifting/expanding stacks as necessary. Display warning message if all stacks are full. */
  void push(int stackNum, int value) {
    if (allStacksAreFull()) {
      printf("Push: All stacks are full!");
      return;
    }

    // If this stack is full, expand it.
    StackInfo& stack = info[stackNum];
    if (stack.isFull()) {
      expand(stackNum);
    }

    // Find the index of the top element in the array + 1, and increment the stack pointer.
    stack.size++;
    values[stack.lastElementIndex()] = value;
  }

  // Remove value from stack.
  void pop(int stackNum) {
    StackInfo& stack = info[stackNum];
    if (stack.isEmpty()) {
      printf("Pop: Stack %d is empty!", stackNum);
      return;
    }

    // Remove last element.
    stack.size--;
  }

  // Get top element of stack.
  int top(int stackNum) {
    StackInfo& stack = info[stackNum];
    return values[stack.lastElementIndex()];
  }

  // Expand stack by shifting over other stacks.
  void expand(int stackNum) {
    shift((stackNum + 1) % numberOfStacks);
    info[stackNum].capacity++;
  }

  // Shift items in stack over by one element. If we have available capacity, then we'll end up shrinking the stack by one element. If we don't have available capacity, then we'll need to shift the next stack over too.
  void shift(int stackNum) {
    StackInfo& stack = info[stackNum];

    // If this stack is at its full capacity, then you need to move the next stack over by one element. This stack can now claim the freed index.
    if (stack.size >= stack.capacity) {  // Should be '==' ?
      int nextStack = (stackNum + 1) % numberOfStacks;
      shift(nextStack);
      stack.capacity++;
    }

    // Shift all elements in stack over by one.
    int index = stack.lastCapacityIndex();
    while(stack.isWithinStackCapacity(index)) {
      values[index] = values[previousIndex(index)];
      index = previousIndex(index);
    }

    // Adjust stack data.
    values[stack.start] = 0;  // Clear item
    stack.start = nextIndex(stack.start);
    stack.capacity--;
  }

  int nextIndex(int index) {
    return adjustIndex(index + 1);
  }

  int previousIndex(int index) {
    return adjustIndex(index - 1);
  }

  bool allStacksAreFull() {
    return numberOfElements() == capacity;
  }

  int numberOfElements() {
    int size = 0;
    for(int i = 0; i < numberOfStacks; i++)
      size += info[i].size;
    return size;
  }

  int adjustIndex(int index) {
    return ((index % capacity) + capacity) % capacity;  // Ensure the the result is positive
  }

  bool isEmpty(int stackNum) {
    StackInfo& stack = info[stackNum];
    return stack.isEmpty();
  }
};

int main() {  
  MultiStack stacks(2, 1);

  stacks.push(0, 2);
  stacks.push(0, 3);
  cout << stacks.top(0) << '\n';      // Should be 3
  cout << stacks.isEmpty(1) << '\n';  // Should be true

  stacks.pop(0);
  stacks.push(1, 4);
  cout << stacks.top(0) << '\n';  // Should be 2
  cout << stacks.top(1) << '\n';  // Should be 4

  stacks.pop(0);
  cout << stacks.top(1) << '\n';  // Should be 4

  stacks.push(1, 5);
  cout << stacks.top(1) << '\n';  // Should be 5

  return 0;
}
