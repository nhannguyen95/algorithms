/* Binary Search Tree (tested)

- SEARCH

- MINIMUM

- MAXIMUM

- PREDECESSOR

- SUCCESSOR

- INSERT

- DELETE

All is O(H) in time

*/

// ----------------INCLUDE-----------------

#include <iostream>
#include <initializer_list>
#include <stack>
#include <queue>
#include <cmath>
#include <utility>
using namespace std;

// ------------------BST-------------------

class Node {
public:
  int key;
  Node *parent, *left, *right;
  Node(int key) :
    key(key), parent(NULL), left(NULL), right(NULL){}
};

class BinarySearchTree {
private:
  Node * root;

  vector<vector<Node*> > nodesInLevels() {
    Node * node = root;
    vector<vector<Node*> > levels;
    queue<Node*> cur({root});
    while(1) {
      levels.push_back(vector<Node*>());
      vector<Node*> next;
      while(!cur.empty()) {
        Node * node = cur.front(); cur.pop();
        levels.back().push_back(node);
        next.push_back((node == NULL) ? NULL : node->left);
        next.push_back((node == NULL) ? NULL : node->right);
      }

      // Stop condition
      bool allNull = true;
      for(auto node : next) {
        cur.push(node);
        if (node != NULL) allNull = false;
      }
      if (allNull) break;
    }
    return levels;
  }

  Node* minimum(Node * node) {
    while(node->left != NULL)
      node = node->left;
    return node;
  }

  Node* maximum(Node * node) {
    while(node->right != NULL)
      node = node->right;
    return node;
  }

  // Helper transplant(u, v)
  // u != NULL, v may == NULL
  void transplant(Node* u, Node* v) {
    if (u->parent == NULL) root = v;
    else if (u->parent->left == u)
      u->parent->left = v;
    else
      u->parent->right = v;
    if (v != NULL)
      v->parent = u->parent;
  }

public:
  // The expected height of randomly built tree is lgN
  BinarySearchTree(initializer_list<int> l) {
    root = NULL;
    for(int key : l) insert(key);
  }

  // INSERT: O(H)
  // Note: the modification operations like
  // init, delete, insert in a binary search tree
  // does not maintain  the "balanced" property
  // of the tree, meaning that H is not always
  // close to lgN.
  void insert(int key) {
    Node * node = root;
    Node * parent = NULL;
    while(node != NULL) {
      parent = node;
      if (node->key >= key) node = node->left;
      else node = node->right;
    }

    Node* newNode = new Node(key);
    newNode->parent = parent;
    if (parent == NULL) root = newNode;
    else if (parent->key >= key) parent->left = newNode;
    else parent->right = newNode;
  }

  // MIN: O(H)
  Node* minimum() {
    return minimum(root);
  }

  // MAX: O(H)
  Node* maximum() {
    return maximum(root);
  }

  // SUCCESSOR(node): O(H)
  Node* successor(Node* node) {
    if (node->right != NULL)
      return minimum(node->right);
    while(node->parent != NULL && node->parent->left != node)
      node = node->parent;
    return node->parent;
  }

  // PREDECESSOR(node): O(H)
  Node* predecessor(Node* node) {
    if (node->left != NULL)
      return maximum(node->left);
    while(node->parent != NULL && node->parent->right != node)
      node = node->parent;
    return node->parent;
  }

  // SEARCH(key): O(H)
  pair<Node*, bool> search(int key) {
    pair<Node*, bool> result;
    Node * node = root;
    while(node != NULL) {
      if (node->key == key) return make_pair(node, true);
      if (node->key > key) node = node->left;
      else node = node->right;
    }
    return make_pair((Node*)NULL, false);
  }

  // DELETE(node): O(H)
  // This operation is undoubtedly the hardest to implement,
  // and the most difficult scenario is when the deleted node
  // (called `node`) has 2 children, in that case, we find its
  // successor `t`:
  //  - If node->right == t, then we just simply transplant
  //    t (and t's subtree) into node's position, adjust some
  //    relation and delete node.
  //  - Else, first we transplant t->right into t, and make t
  //    the root of the original t's subtree, then transplant t
  //    into `node` (the first case)
  void remove(Node* node) {
    if (node->left == NULL)
      transplant(node, node->right);
    else if (node->right == NULL)
      transplant(node, node->left);
    else {
      Node * t = successor(node);
      if (node->right != t) {  // node has 2 children, so node's
                               // successor t has no left child.
        transplant(t, t->right);
        t->right = node->right;
        node->right->parent = t;
      }
      transplant(node, t);
      t->left = node->left;
      t->left->parent = t;
    }
    delete node;
  }

  void inorder() {
    cout << "Inorder:";
    Node * node = root;
    stack<Node*> s;
    while(node != NULL || !s.empty()) {
      if (node == NULL) {
        node = s.top(); s.pop();
        cout << ' ' << node->key;
        node = node->right;
      } else {
        s.push(node);
        node = node->left;
      }
    }
    cout << '\n';
  }

  friend ostream& operator<<(
    ostream& os, BinarySearchTree & tree) {
    auto levels = tree.nodesInLevels();
    int nSpaces = 80;
    for(auto nodes : levels) {
      int nNodes = nodes.size();
      int gap = (nSpaces - nNodes) / (nNodes + 1);
      for(auto node : nodes) {
        os << string(gap, ' ');
        if (node == NULL) os << 'N';
        else os << node->key;
      }
      os << '\n';
    }
    return os;
  }
};

// -----------------TEST-------------------

int main() {
  BinarySearchTree tree({8,4,19,6,21,3,13,10,15,2,7,20});

  tree.inorder();  // Increasing order

  cout << tree;

  cout << "Minumum (2): " << tree.minimum()->key << '\n';

  cout << "Maximum (20): " << tree.maximum()->key << '\n';

  cout << "Is 5 in tree? (0): " << tree.search(5).second << '\n';
  cout << "Is 2 in tree? (1): " << tree.search(2).second << '\n';

  Node * node7 = tree.search(7).first;
  cout << "Next of 7 is (8): " << tree.successor(node7)->key << '\n';

  Node * node3 = tree.search(3).first;
  cout << "Prev of 3 is (2): " << tree.predecessor(node3)->key << '\n';

  // Toggle one of these

  // 1. Delete 3
  // tree.remove(node3);
  // cout << "Deleted 3\n";
  // cout << tree;

  // 2. Delete 6
  // Node * node6 = tree.search(6).first;
  // tree.remove(node6);
  // cout << "Deleted 6\n";
  // cout << tree;

  // 3. Delete 19
  // Node * node19 = tree.search(19).first;
  // tree.remove(node19);
  // cout << "Deleted 19\n";
  // cout << tree;

  // 4. Delete the root 8
  Node * node8 = tree.search(8).first;
  tree.remove(node8);
  cout << "Deleted 8\n";
  cout << tree;

  return 0;
}
