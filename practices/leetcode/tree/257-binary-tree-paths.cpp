// Solution 1: iterative solution using stack
// N = number of nodes
// O(N) in time (each node is visited once)
// O(N) in space (for storing the result array)
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<pair<TreeNode*, string>> stack({make_pair(root, "")});
        vector<string> ans;
        while(!stack.empty()) {
            auto p = stack.top();
            stack.pop();

            TreeNode* node = p.first;
            string & path = p.second;

            if (node == NULL) continue;

            if (node->left == NULL && node->right == NULL) {
                ans.push_back(path + to_string(node->val));
                continue;
            }

            if (node->left != NULL)
                stack.push(make_pair(node->left, path + to_string(node->val) + "->"));
            if (node->right != NULL)
                stack.push(make_pair(node->right, path + to_string(node->val) + "->"));
        }
        return ans;
    }
};
