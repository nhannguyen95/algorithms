/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::maxDepth(TreeNode* node) {
    if (node == NULL) return 0;

    return 1 + max(maxDepth(node->left), maxDepth(node->right));
}
