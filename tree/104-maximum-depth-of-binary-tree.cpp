// Solution 1: recursion
// N = number of nodes in tree
// O(N) in time
// O(N) in space in worst case (skewed tree)
// O(N) in space in average
// pattern: pre-order
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// Solution 2: iterative using BFS
// Time & Space complexity same as solution 1
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case
        if (root == NULL) return 0;

        int depth = 0;
        stack<TreeNode*> currLevel;
        currLevel.push(root);
        while(!currLevel.empty()) {
            stack<TreeNode*> nextLevel;
            depth++;

            // Traverse all nodes in current level
            while(!currLevel.empty()) {
                TreeNode* node = currLevel.top();
                currLevel.pop();

                // Save nodes in the next level
                if (node->left != NULL) nextLevel.push(node->left);
                if (node->right != NULL) nextLevel.push(node->right);
            }

            // Bfs to the next level
            currLevel = nextLevel;
        }

        return depth;
    }
};
