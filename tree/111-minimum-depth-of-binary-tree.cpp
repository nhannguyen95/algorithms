// Solution 1: recursive
// O(H) in space, H = height of tree
// O(N) in time
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if (root->left == NULL) return 1 + r;
        if (root->right == NULL) return 1 + l;
        return 1 + min(l, r);
    }
};

// Solution 2: iterative using stack
// preorder Pattern
// O(N) in space and time complexity
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        stack<TreeNode*> stack({root});
        unordered_map<TreeNode*, int> height;
        height[NULL] = 0;
        while(!stack.empty()) {
            TreeNode* node = stack.top();
            if ((height.find(node->left) != height.end()) &&
                height.find(node->right) != height.end()) {
                if (node->left == NULL) height[node] = 1 + height[node->right];
                else if (node->right == NULL) height[node] = 1 + height[node->left];
                else height[node] = 1 + min(height[node->left], height[node->right]);
                stack.pop();
            } else {
                if (node->left != NULL) stack.push(node->left);
                if (node->right != NULL) stack.push(node->right);
            }
        }
        return height[root];
    }
};

// Solution 3: iterative using queue
// Space complexity: https://www.youtube.com/watch?v=yNMyH9p66Yo
// Time complexity: O(N)
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> curr({root});
        int i = 1;
        while(!curr.empty()) {

            queue<TreeNode*> next;
            while(!curr.empty()) {
                TreeNode* node = curr.front();
                curr.pop();

                if (node->left == NULL && node->right == NULL)
                    return i;

                if (node->left != NULL) next.push(node->left);
                if (node->right != NULL) next.push(node->right);
            }

            i++;
            curr = next;
        }
        return i;  // should never reach this
    }
};
