// Solution 1: recursion
// N = number of nodes in tree
// O(N) in time
// O(N) in space if skewed tree
// O(logN) in average
// pettern: preorder
class Solution {
public:
    long long sum = 0;

    bool isLeaf(TreeNode* node) {
        return (node != NULL) &&
                (node->left == NULL) &&
                (node->right == NULL);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)
            return 0;

        if (isLeaf(root->left))
            sum += root->left->val;
        else
            sumOfLeftLeaves(root->left);

        sumOfLeftLeaves(root->right);
        return sum;
    }
};

// Solution 2: iteration
// O(N) in time
// O(M) with M = number of nodes at most node level.
// To be more specific, assume that is is a perfect
// binary tree, the space complexity will be O(N/2)
// (when the stack contains all the nodes in the
// last level) = O(N)
class Solution {
public:
    bool isLeaf(TreeNode* node) {
        return node != NULL &&
            node->left == NULL &&
            node->right == NULL;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> stack;
        stack.push(root);
        long long sum = 0;
        while(!stack.empty()) {
            TreeNode * node = stack.top();
            stack.pop();
            if (node == NULL) continue;
            if (isLeaf(node->left))
                sum += node->left->val;
            else
                stack.push(node->left);
            stack.push(node->right);
        }
        return sum;
    }
};

// Solution 3: a more subtle solution than 1
// Please refer to Python file.
