// Solution 1: recursive
// pattern: post order
// O(H) in space, H = height of tree
// O(N) in time, N = number of nodes
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int maxLen = 0;
        helper(root, maxLen);
        return maxLen;
    }

    int helper(TreeNode* node, int & maxLen) {
        // Base cases
        if (node == NULL) return 0;
        if (node->left == NULL && node->right == NULL)
            return 1;

        int l = helper(node->left, maxLen);
        if (node->left != NULL && node->val != node->left->val)
            l = 0;

        int r = helper(node->right, maxLen);
        if (node->right != NULL && node->val != node->right->val)
            r = 0;

        maxLen = max(maxLen, l + r);

        return 1 + max(l, r);
    }
};

// Solution 2: iterative
// O(N) in time and space
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) return 0;
        stack<TreeNode*> stack({root});
        unordered_map<TreeNode*, int> f;
        f[NULL] = 0;
        int maxLen = 0;
        while(!stack.empty()) {
            TreeNode* node = stack.top();
            if (f.find(node->left) != f.end() &&
                f.find(node->right) != f.end()) {
                int l = f[node->left];
                if (node->left != NULL && node->left->val != node->val)
                    l = 0;

                int r = f[node->right];
                if (node->right != NULL && node->right->val != node->val)
                    r = 0;

                f[node] = 1 + max(l, r);
                maxLen = max(maxLen, l + r);
                stack.pop();
            } else {
                if (node->left != NULL) stack.push(node->left);
                if (node->right != NULL) stack.push(node->right);
            }
        }
        return maxLen;
    }
};
