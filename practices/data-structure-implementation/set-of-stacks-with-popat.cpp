#include <iostream>
#include <vector>
using namespace std;

struct Node {
	Node* above;
	Node* below;
	int val;
	Node(int val) : above(NULL), below(NULL), val(val) {}
};

class Stack {
private:
	Node* top;
	Node* bottom;
	int capacity;
	int size;

	void join(Node* above, Node* below) {
		if (above != NULL) above->below = below;
		if (below != NULL) below->above = above;
	}

public:
	Stack(int capacity) : top(NULL), bottom(NULL), capacity(capacity), size(0) {}

	bool isFull() {
		return size == capacity;
	}

	void push(int x) {
		if (isFull()) {
			cout << "Push: stack is full!\n";
			exit(1);
		}
		Node* n = new Node(x);
		if (++size == 1) bottom = n;
		join(n, top);
		top = n;
	}

	int pop() {
		if (isEmpty()) {
			cout << "Pop: stack is empty!\n";
			exit(1);
		}
		Node* n = top;
		int ret = n->val;
		top = top->below;
		if (top) top->above = NULL;
		delete n;
		size--;
		return ret;
	}

	bool isEmpty() {
		return size == 0;
	}

	int removeBottom() {
		if (isEmpty()) {
			cout << "Remove bottom: stack is empty!\n";
			exit(1);
		}
		Node* n = bottom;
		int ret = n->val;
		bottom = bottom->above;
		if (bottom != NULL) bottom->below = NULL;
		delete n;
		size--;
		return ret;
	}
};

class SetOfStacks {
private:
	vector<Stack*> stacks;
	int capacity;  // Capacity of each stack in set

	Stack* getLastStack() {
		return stacks.empty() ? NULL : stacks.back();
	}

public:
	SetOfStacks(int capacity) : capacity(capacity) {}

	void push(int x) {
		Stack* last = getLastStack();
		if (last == NULL || last->isFull()) {
			Stack* stack = new Stack(capacity);
			stack->push(x);
			stacks.push_back(stack);
		} else {
			last->push(x);
		}
	}

	int pop() {
		Stack* last = getLastStack();
		if (last == NULL) {
			cout << "Pop: stack is empty!\n";
			exit(1);
		}
		int ret = last->pop();
		if (last->isEmpty()) stacks.pop_back();  // This is important, the logic here is
												 // we don't keep empty stack in our set
		return ret;
	}

	int popAt(int index) {
		return leftShift(index, true);
	}

	int leftShift(int index, bool removeTop) {
		Stack* stack = stacks[index];
		int removedItem;
		if (removeTop) removedItem = stack->pop();
		else removedItem = stack->removeBottom();
		if (stack->isEmpty()) {
			stacks.erase(stacks.begin() + index);
		} else if (index + 1 < stacks.size()) {
			int v = leftShift(index + 1, false);
			stack->push(v);
		}
		return removedItem;
	}
};

int main() {
	SetOfStacks s(2);

	s.push(1);
	cout << s.pop() << '\n';  // Should be 1

	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.pop() << '\n';  // Should be 3

	s.push(3);
	s.push(4);  // s is now [1 2] [3 4]
	cout << s.popAt(0) << '\n';  // Should be 2

	s.push(5);  // s is now [1 3] [4 5]
	cout << s.popAt(1) << '\n';  // Should be 5

	return 0;
}
