// https://leetcode.com/problems/search-in-a-binary-search-tree

// Solution 1: O(H) in time in worst case, O(1) in space
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode * node = root;
        while(node != NULL) {
            if (node->val == val) break;
            if (node->val > val) node = node->left;
            else node = node->right;
        }
        return node;
    }
};
