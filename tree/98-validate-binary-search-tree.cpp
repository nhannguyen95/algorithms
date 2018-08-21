// Solution 1: [min, max] range, recursive
// Pattern: preorder
// O(N) in time (since each node is visited once)
// O(H) in space (in average case)
// Using long long to avoid overflow.
class Solution {
public:
    bool isValidBSTHelper(TreeNode* node, long long mn, long long mx) {
        if (node == NULL) return true;
        return (mn <= node->val && node->val <= mx) &&
               isValidBSTHelper(node->left, mn, node->val - 1LL) &&
               isValidBSTHelper(node->right, node->val + 1LL, mx);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, INT_MIN, INT_MAX);
    }
};

// Solution 2: [min, max] range, recursive
// Same complexity as #1
class Solution {
public:
    bool isValidBSTHelper(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if (node == NULL) return true;
        return (minNode == NULL || minNode->val < node->val) &&
               (maxNode == NULL || node->val < maxNode->val) &&
               isValidBSTHelper(node->left, minNode, node) &&
               isValidBSTHelper(node->right, node, maxNode);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, NULL, NULL);
    }
};

// Solution 3:
// Using the property that the inorder of a bst will be an ascending array
// Same complexity as #1
class Solution {
public:
    bool inorder(TreeNode* node, TreeNode*& prev) {
        if (node == NULL) return true;
        
        if (!inorder(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return inorder(node->right, prev);
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return inorder(root, prev);
    }
};
