// Solution 1: recursive
// pattern: post-order
// O(H) in space, H = height of tree
// O(N) in time, N = number of nodes
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        count1(root);
        return root;
    }

    int count1(TreeNode* node) {
        if (node == NULL) return 0;

        int l = count1(node->left);
        int r = count1(node->right);

        if (l == 0) node->left = NULL;
        if (r == 0) node->right = NULL;

        return l + r + (node->val == 1);
    }
};

// Solution 2: iterative using stack
// O(N) in time and space
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL) return root;
        stack<TreeNode*> stack({root});
        unordered_map<TreeNode*, int> num1s;
        num1s[NULL] = 0;
        while(!stack.empty()) {
            TreeNode* node = stack.top();
            if (num1s.find(node->left) != num1s.end() &&
                num1s.find(node->right) != num1s.end()) {
                num1s[node] = num1s[node->left] + num1s[node->right] +
                              (node->val == 1);
                if (num1s[node->left] == 0) node->left = NULL;
                if (num1s[node->right] == 0) node->right = NULL;
                stack.pop();
            } else {
                if (node->left != NULL) stack.push(node->left);
                if (node->right != NULL) stack.push(node->right);
            }
        }
        return root;
    }
};

// Solution 3: a more subtle recursive solution
TreeNode* pruneTree(TreeNode* root) {
    if (root == NULL) return root;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    return (!root->val && !root->left && !root->right) ? NULL: root;
}
