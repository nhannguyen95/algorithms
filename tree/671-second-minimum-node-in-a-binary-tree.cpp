// Solution 1: recursion
// N = number of nodes
// pattern: post-order
// O(N) in time (each node is visited once)
// O(N) in space in worst case (skewed tree)
//
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        return helper(root, root->val);
    }

    int helper(TreeNode* node, const int & smallest) {
        if (node == NULL) return -1;
        if (node->val > smallest) return node->val;

        int geLeft = helper(node->left, smallest);
        int geRight = helper(node->right, smallest);
        int mn = min(geLeft, geRight);
        int mx = max(geLeft, geRight);
        if (mn > smallest) return mn;
        return (mx <= smallest) ? -1 : mx;
    }
};
