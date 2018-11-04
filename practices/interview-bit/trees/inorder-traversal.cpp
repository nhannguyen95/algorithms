// Solution 1: recursion
void traverse(TreeNode * node, vector<int> & ans) {
    if (node == NULL) return;

    traverse(node->left, ans);
    ans.push_back(node->val);
    traverse(node->right, ans);
}

vector<int> Solution::inorderTraversal(TreeNode* tree) {
    vector<int> ans;
    traverse(tree, ans);
    return ans;
}

// Solution 2: iterative using stack
vector<int> Solution::inorderTraversal(TreeNode* tree) {
    vector<int> ans;
    stack<TreeNode *> S;
    while(!S.empty() || tree != NULL) {
        if (tree != NULL) {
            S.push(tree);
            tree = tree->left;
        } else {
            tree = S.top(); S.pop();
            ans.push_back(tree->val);
            tree = tree->right;
        }
    }
    return ans;
}
