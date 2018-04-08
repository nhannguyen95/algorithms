// Solution 1: recursive
// O(H) in time and complexity, H = height of tree.
// pattern: post-order
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height;
        return isBalanced2(root, height);
    }

    bool isBalanced2(TreeNode* node, int & height) {
        if (node == NULL) {
            height = -1;
            return true;
        }
        int hLeft;
        bool bLeft = isBalanced2(node->left, hLeft);
        int hRight;
        bool bRight = isBalanced2(node->right, hRight);

        height = 1 + max(hLeft, hRight);
        return abs(hLeft - hRight) <= 1 && bLeft && bRight;
    }
};


// Solution 2: iterative
// O(N) in time and space
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        stack<TreeNode*> stack({root});
        unordered_map<TreeNode*, int> height;
        height[NULL] = -1;
        while (!stack.empty()) {
            TreeNode* node = stack.top();
            if ((node->left == NULL || height.find(node->left) != height.end()) &&
                (node->right == NULL || height.find(node->right) != height.end())) {
                int d = abs(height[node->left] - height[node->right]);
                if (d > 1) return false;
                height[node] = 1 + max(height[node->left], height[node->right]);
                stack.pop();
            } else {
                if (node->left != NULL) stack.push(node->left);
                if (node->right != NULL) stack.push(node->right);
            }
        }
        return true;
    }
};
