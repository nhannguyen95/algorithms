/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* node) {
    if (node == NULL) return NULL;

    node->left = invertTree(node->left);
    node->right = invertTree(node->right);

    TreeNode * tmpLeft = node->left;
    node->left = node->right;
    node->right = tmpLeft;

    return node;
}
