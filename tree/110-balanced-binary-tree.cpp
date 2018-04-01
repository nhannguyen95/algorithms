// Solution 1: recursive
// O(H) in time and complexity, H = height of tree.
// pattern: post-order
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height;
        return isBalanced2(root, height);
    }

    bool isBalanced2(TreeNode* node, int & height) {
        if (node == NULL) {
            height = -1;
            return true;
        }
        int hLeft;
        bool bLeft = isBalanced2(node->left, hLeft);
        int hRight;
        bool bRight = isBalanced2(node->right, hRight);

        height = 1 + max(hLeft, hRight);
        return abs(hLeft - hRight) <= 1 && bLeft && bRight;
    }
};
