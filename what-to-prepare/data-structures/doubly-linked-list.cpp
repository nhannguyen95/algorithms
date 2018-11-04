/* Doubly linked list (tested)

3 operations of dynamic sets are implemented on linked list:
  - INSERT(S, x) as INSERT(L, k), O(1)
  - DELETE(S, x) as REMOVE(L, x), O(1)
  - SEARCH(S, k) as SEARCH(L, k), O(n)

Follow up: to implement doubly linked list, instead of using
2 values x.prev and x.next, we can only use one value on each
item x.np = x.next XOR x.prev (assume that all pointer values
can be interpreted as k-bit integers, and NIL is represented by 0).
We utilize this property of XOR operator: A XOR (A XOR B) = B.

To iterate:
p = NIL
x = L.head
x = p XOR x.np  # next item after head

*/

// ----------------INCLUDE-----------------

#include <iostream>
using namespace std;

// -------------IMPLEMENTATION-------------

class Node {
public:
  int key;  // Satelite data can be stored in somewhere else
  Node * next;
  Node * prev;

  Node(int key) : key(key), next(NULL), prev(NULL) {}
};

class DoublyLinkedList {
private:
  Node * head;

  Node* makeNode(int key) {
    return new Node(key);
  }

public:
  DoublyLinkedList() : head(NULL) {}

  void insert(int key) {
    Node * x = makeNode(key);
    if (head != NULL)
      head->prev = x;
    x->next = head;
    head = x;
  }

  Node * search(int key) {
    Node * x = head;
    while(x != NULL && x->key != key)
      x = x->next;
    return x;
  }

  void remove(Node * x) {
    if (x->prev != NULL)
      x->prev->next = x->next;
    else
      head = x->next;
    if (x->next != NULL)
      x->next->prev = x->prev;
    delete x;
  }

  friend ostream& operator<<(
    ostream & os, const DoublyLinkedList & l) {
    Node * p = l.head;
    while(p != NULL) {
      os << p->key << ' ';
      p = p->next;
    }
    os << '\n';
    return os;
  }
};

// ----------------------------------------

int main() {
  DoublyLinkedList l;

  l.insert(5);
  l.insert(4);
  l.insert(3);
  cout << l;  // 3 4 5

  // l.remove(l.search(4));
  // cout << l;  // 3 5

  // l.remove(l.search(3));
  // cout << l;  // 4 5

  l.remove(l.search(5));
  cout << l;  // 3 4

  return 0;
}
