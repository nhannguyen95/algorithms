#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> s) {
  while(!s.empty()) {
    cout << s.top() << ' ';
    s.pop();
  }
}

int main() {
  stack<int> s({3,1,4,5,4,4,4,5});
  stack<int> temp;

  /* Time complexity: O(N^2), N = len(s).
   * Space complexity: O(N). 
   */

  // Bring elements from `s` to `temp`,
  // so that largest elements are at top of `temp`.
  while(!s.empty()) {
    // Retrieve top element of `s`.
    int val = s.top();
    s.pop();

    // Put this to `temp` at correct position.
    while(!temp.empty() && temp.top() > val) {
      s.push(temp.top());
      temp.pop();
    }
    temp.push(val);
  }

  // So when elements are brought to `s`,
  // the order is reverseed: smallest elements are
  // at top of `s`.
  while(!temp.empty()) {
    s.push(temp.top());
    temp.pop();
  }

  printStack(s);  // Should be in ascending order

  return 0;
}
