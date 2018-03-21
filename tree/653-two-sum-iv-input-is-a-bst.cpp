// Solution 1: inorder traversal + binary search.
// N = number of nodes in tree
// O(N) traversal + O(NlogN) binary search = O(N + NlogN) = O(NlogN) in time
// O(N) in space (in order to get element to an array)
class Solution {
public:

    void inorderTraverse(TreeNode* node, vector<int>& a) {
        if (node != NULL) {
            inorderTraverse(node->left, a);
            a.push_back(node->val);
            inorderTraverse(node->right, a);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        // inorder traversal outputs element in sorted order
        vector<int> a;
        inorderTraverse(root, a);

        for(int i = 1; i < (int)a.size(); i++) {
            if (binary_search(a.begin(), a.begin()+i, k-a[i])) {
                return true;
            }
        }
        return false;
    }
};

// Solution 2: inorder traversal + two pointers.
// O(N) traversal + O(N) 2 pointers = O(2N) = O(N) in time
// O(N) in space
class Solution {
public:
    void inorderTraverse(TreeNode* node, vector<int>& a) {
        if (node != NULL) {
            inorderTraverse(node->left, a);
            a.push_back(node->val);
            inorderTraverse(node->right, a);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        // inorder traversal outputs element in sorted order
        vector<int> a;
        inorderTraverse(root, a);

        // Two pointers on sorted array
        int i = 0;
        int j = (int)a.size() - 1;
        while(i < j) {
            int sum = a[i] + a[j];
            if (sum == k) return true;
            else if (sum < k) i++;
            else j--;
        }
        return false;
    }
};

// Solution 3: inorder traversal + hash table
// Time & Space complexity same as solution 1
// Actually O(2N) = O(N) in space
///
// This is my silly implementation because if
// we use hash table, the array is not necessary
// in sorted order hence it doesn't matter which
// type of traversal we're using here.
class Solution {
public:

    void inorderTraverse(TreeNode* node, vector<int>& a) {
        if (node != NULL) {
            inorderTraverse(node->left, a);
            a.push_back(node->val);
            inorderTraverse(node->right, a);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        // inorder traversal outputs element in sorted order
        vector<int> a;
        inorderTraverse(root, a);

        unordered_set<int> seens;  // save elements that have been seen
        for(int v : a) {
            // Need to check if we've seen (k-v) element
            if (seens.find(k-v) != seens.end()) {
                return true;
            }
            seens.insert(v);
        }
        return false;
    }
};

// Solution 4: idea same as solution 3
// But O(N) in space instead of O(2N)
// because we use hash table right when
// we traverse the tree.
// pattern: pre-order
class Solution {
public:
    bool findTarget(TreeNode* node, const int & k, unordered_set<int> & seens) {
        if (node == NULL)
            return false;

        if (seens.find(k-node->val) != seens.end())
            return true;
        seens.insert(node->val);

        return findTarget(node->left, k, seens) ||
               findTarget(node->right, k, seens);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seens;
        return findTarget(root, k, seens);
    }
};

// Solution 5: iterative using stack
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seens;
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();

            if (node == NULL) continue;

            if (seens.find(k-node->val) != seens.end())
                return true;
            seens.insert(node->val);

            stack.push(node->right);
            stack.push(node->left);
        }
        return false;
    }
};

// Solution 6: BSTIterator + 2 pointers
// BSTIterator helps significantly reduce
// the space complexity from O(N) to O(lgN)
//
// The idea is that the BSTIterator provides
// a technique to traverse the BST (in inorder
// order or vice-versa) and only costs O(logN)
// space complexity at any time.
//
// Actually the inorder traverse can also do
// that (retrieving elements in inorder order)
// in only O(1) space complexity.
//
// The important thing here is that with the
// O(logN) trade off, the BSTIterator is packed
// into a class and provides us a technique
// to traverse the tree like normal and can also
// do other things outside the traversal process.
// (This trade off makes everything easier)
//
// That other thing here is 2-pointers.
//
// The implementation of BSTIterator class is exactly
// the same way with the iterative version of inorder
// traversal. We just return right when retrieve an
// element.
//
// Reference:
// + https://www.interviewbit.com/problems/inorder-traversal/
// + https://github.com/nhannguyen95/interviewbit/blob/master/programming/trees/inorder-traversal.cpp
class BSTIterator {
private:
    stack<TreeNode*> stk;
    TreeNode* node;
    bool forward;
public:
    BSTIterator(TreeNode* root, bool _forward) : node(root), forward(_forward) {};

    int next() {
        while(node || !stk.empty()) {
            if (node) {
                stk.push(node);
                node = forward ? node->left : node->right;
            } else {
                node = stk.top();
                stk.pop();
                int ret = node->val;
                node = forward ? node->right : node->left;
                return ret;
            }
        }
        return -1;  // never reach
    }

    bool hasNext() {
        return (node != NULL) || !stk.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL)
            return false;

        BSTIterator l(root, true);
        BSTIterator r(root, false);
        for(int i = l.next(), j = r.next(); i < j;) {
            int sum = i + j;
            if (sum == k) return true;
            else if (sum < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};
