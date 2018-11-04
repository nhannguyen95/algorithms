// Solution 1: recursive
// N = number of nodes(S), M = number of nodes(T)
// O(N + M) in space in worst case (skewed tree)
// O(logN + logM) in space average case
// O(N * M) in time in worst case, but this can be deceiving
// O(N + kM) in time, k = number of occurences of T's root in S.
class Solution {
public:
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL) return false;
        return s->val == t->val &&
               isSameTree(s->left, t->left) &&
               isSameTree(s->right, t->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) return true;
        if (s == NULL) return false;
        if (t == NULL) return true;
        return isSameTree(s, t) ||
               isSubtree(s->left, t) ||
               isSubtree(s->right, t);
    }
};


// Solution 2: iterative
// Make use of this statement:
// Two tree has the same structure if they
// have the same pre/post-order traversal
// Please refer to solution 1 in Python file.
