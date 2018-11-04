// Solution 1: Using recursion
// N = total nodes
// O(N) in time
// O(N) in space
void preorder(TreeNode * node, vector<int> & ans) {
    if (node == NULL) return;

    ans.push_back(node->val);
    preorder(node->left, ans);
    preorder(node->right, ans);
}

vector<int> Solution::preorderTraversal(TreeNode* node) {
    vector<int> ans;
    preorder(node, ans);
    return ans;
}

// Solution 2: No recursion
// O(N) in time
// O(N) in space
vector<int> Solution::preorderTraversal(TreeNode* tree) {
    vector<int> ans;
    stack<TreeNode*> S;

    while(!S.empty() || tree != NULL) {
        if (tree == NULL) {
            tree = S.top();
            S.pop();
        } else {
            ans.push_back(tree->val);
            if (tree->right != NULL) S.push(tree->right);
            tree = tree->left;
        }
    }
    return ans;
}

// Solution 3: More intuitive
vector<int> Solution::preorderTraversal(TreeNode* tree) {
    vector<int> ans;

    // Base case
    if (tree == NULL) return ans;

    stack<TreeNode*> S;
    S.push(tree);
    // root - left - right
    while(!S.empty()) {
        TreeNode * node = S.top();
        S.pop();
        ans.push_back(node->val);

        if (node->right != NULL)
            S.push(node->right);
        if (node->left != NULL)
            S.push(node->left);
    }

    return ans;
}
