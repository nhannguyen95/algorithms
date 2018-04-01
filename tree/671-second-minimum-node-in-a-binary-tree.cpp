// Solution 1: recursion
// N = number of nodes
// pattern: post-order
// O(N) in time (when the second minimum node
// is in the right most of the tree, then
// need to visit all the node to find it)
// O(N) in space in worst case ("skewed" tree, of
// course each node still has 2 sub nodes)
// O(h) in average, h = height of tree.
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
        if (geLeft == -1) return geRight;
        if (geRight == -1) return geLeft;
        return min(geLeft, geRight);
    }
};

// Solution 2: iterative solution of solution 1
// Please refer to Python file.

// Solution 3: another iterative solution
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL) return -1;
        int min_ = root->val;
        stack<TreeNode*> stack({root});
        int res = INT_MAX;
        while(!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            if (min_ < node->val && node->val < res)
                res = node->val;
            if (node->left != NULL) {
                stack.push(node->left);
                stack.push(node->right);
            }
        }
        return (res == INT_MAX) ? -1 : res;
    }
};
