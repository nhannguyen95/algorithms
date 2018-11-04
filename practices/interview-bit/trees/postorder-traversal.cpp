// Solution 1: Using recursion
void traverse(TreeNode * node, vector<int> & ans) {
    if (node == NULL) return;

    traverse(node->left, ans);
    traverse(node->right, ans);
    ans.push_back(node->val);
}

vector<int> Solution::postorderTraversal(TreeNode* node) {
    vector<int> ans;
    traverse(node, ans);
    return ans;
}

// Solution 2: No recursion
// Use the idea of 'preorder no recursion'
vector<int> Solution::postorderTraversal(TreeNode* tree) {
    vector<int> ans;

    // Base case
    if (tree == NULL) return ans;

    stack<TreeNode *> S;
    S.push(tree);
    // root-right-left
    while(!S.empty()) {
        TreeNode * node = S.top();
        S.pop();
        ans.push_back(node->val);

        if (node->left != NULL) S.push(node->left);
        if (node->right != NULL) S.push(node->right);
    }

    reverse(ans.begin(), ans.end());  // post order: left-right-root
    return ans;
}

// Solution 3: No recursion
// Source: https://en.wikipedia.org/wiki/Tree_traversal#Iterative_Traversal
vector<int> Solution::postorderTraversal(TreeNode* node) {
    vector<int> ans;
    stack<TreeNode *> S;
    TreeNode* lastNodeVisited = NULL;
    while(!S.empty() || node != NULL) {
        if (node != NULL) {
            S.push(node);
            node = node->left;
        } else {
            TreeNode * peekNode = S.top();
            if (peekNode->right != NULL && lastNodeVisited != peekNode->right) {
                node = peekNode->right;
            } else {
                ans.push_back(peekNode->val);
                lastNodeVisited = peekNode;
                S.pop();
            }
        }
    }
    return ans;
}

// 
