// https://leetcode.com/problems/find-bottom-left-tree-value

// Solution 1
class Solution {
public:
    void inorder(TreeNode* root, int depth, int& maxDepth, TreeNode*& node) {
        if (root->left != NULL)
            inorder(root->left, depth+1, maxDepth, node);
        
        if (depth > maxDepth) {
            maxDepth = depth;
            node = root;
        }
        
        if (root->right != NULL)
            inorder(root->right, depth+1, maxDepth, node);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = -1;
        TreeNode* node;
        inorder(root, 0, maxDepth, node);
        return node->val;
    }
};
