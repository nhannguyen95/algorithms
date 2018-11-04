// Solution 1: recursive
// O(H) in space (H = height of tree)
// O(N) in time
class Solution {
public:
    bool hasPathSum2(TreeNode* node, const int & target, int curSum) {
        if (node == NULL) return false;
        if (node->left == NULL && node->right == NULL)
            return (curSum + node->val == target);
        return hasPathSum2(node->left, target, curSum + node->val) ||
               hasPathSum2(node->right, target, curSum + node->val);
    }

    bool hasPathSum(TreeNode* root, int sum) {
        return hasPathSum2(root, sum, 0);
    }
};

// Solution 2: recursive 2
// Time & Space complexity of solution 1
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        if (root->left == NULL && root->right == NULL)
            return root->val == sum;
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};

// Solution 2: iterative (preorder pattern)
// O(N) in space
// O(N) in time
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        stack<TreeNode*> stack({root});
        long long curSum = 0;
        unordered_set<TreeNode*> visited;
        while(!stack.empty()) {
            TreeNode* node = stack.top();
            if (visited.find(node) == visited.end()) {
                curSum += node->val;
                visited.insert(node);
                if (node->right != NULL) stack.push(node->right);
                if (node->left != NULL) stack.push(node->left);
            } else {
                if (node->left == NULL && node->right == NULL &&
                    curSum == sum) return true;
                curSum -= node->val;
                stack.pop();
            }
        }
        return false;
    }
};
