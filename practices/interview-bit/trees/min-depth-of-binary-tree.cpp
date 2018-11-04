// N = total nodes
// O(N) in time and space
int Solution::minDepth(TreeNode* node) {
    if (node == NULL) return 0;

    if (node->left == NULL && node->right == NULL) return 1;

    if (!node->left) return 1 + minDepth(node->right);
    if (!node->right) return 1 + minDepth(node->left);

    return 1 + min(minDepth(node->left), minDepth(node->right));
}
