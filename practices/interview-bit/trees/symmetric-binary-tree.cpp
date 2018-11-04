/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool symmetric(TreeNode * l, TreeNode * r) {
    if (l == NULL && r == NULL) return true;

    if (l == NULL || r == NULL) return false;

    return (l->val == r->val) &&
            symmetric(l->left, r->right) &&
            symmetric(l->right, r->left);
}

int Solution::isSymmetric(TreeNode* A) {
    if (A == NULL) return true;
    return symmetric(A->left, A->right);
}
