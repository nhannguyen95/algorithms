// Solution 1: recursion
// N = number of nodes
// If the tree is symmetric: (worst case)
// O(N/2) = O(N) in time
// O(2H) = O(H) in space (H = height of tree)
class Solution {
public:
    bool isSymmetric2(TreeNode* node1, TreeNode* node2) {
        if (node1 == NULL && node2 == NULL) return true;
        if (node1 == NULL || node2 == NULL) return false;
        return node1->val == node2->val &&
               isSymmetric2(node1->left, node2->right) &&
               isSymmetric2(node1->right, node2->left);
    }

    bool isSymmetric(TreeNode* root) {
        return isSymmetric2(root, root);
    }
};

// Solution 2: iterative using stack
// Please refer to solution 1 of Python file.
