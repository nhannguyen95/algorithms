// Solution 1: Maintain 2 stacks
// O(N + X) in space, where X = number of places where minimum changes or the element is the same as the minimum
deque<int> s;
deque<int> sMin;

MinStack::MinStack() {
    s.clear();
    sMin.clear();
}

void MinStack::push(int x) {
    s.push_back(x);

    if (sMin.empty() || sMin.back() >= x) {
        sMin.push_back(x);
    }
}

void MinStack::pop() {
    if (s.empty()) return;

    int top = s.back();
    s.pop_back();

    if (top == sMin.back()) {
        sMin.pop_back();
    }
}

int MinStack::top() {
    if (!s.empty()) return s.back();
    return -1;
}

int MinStack::getMin() {
    if (!sMin.empty()) return sMin.back();
    return -1;
}
