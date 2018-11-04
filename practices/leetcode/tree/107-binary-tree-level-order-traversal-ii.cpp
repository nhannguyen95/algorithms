// Solution 1: find top-down level order the reverse
// pattern: pre-order
// N = number of nodes of binary tree
// O(N) in time
// O(N) in space (for the result)
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levels;
        levelOrderTop(root, levels, 0);
        reverse(levels.begin(), levels.end());
        return levels;
    }

    void levelOrderTop(TreeNode* node, vector<vector<int>> & levels, int depth) {
        if (node == NULL) return;

        if (depth == (int)levels.size()) {
            levels.push_back(vector<int>());
        }
        levels[depth].push_back(node->val);

        levelOrderTop(node->left, levels, depth+1);
        levelOrderTop(node->right, levels, depth+1);
    }
};

// Solution 2: iterative solution using bfs + queue
// Refer to solution 1, python file
