// https://leetcode.com/problems/insert-into-a-binary-search-tree/

// Solution 1:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// O(1) in space
// O(H) in time
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode** p = &root;
        while(*p != NULL) {
            if ((*p)->val > val) p = &((*p)->left);
            else p = &((*p)->right);
        }
        (*p) = new TreeNode(val);
        return root;
    }
};
