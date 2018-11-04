// Solution 1: recursive
// N = number of nodes
// O(N) in time
// O(N) in space in worst case (skewed tree)
// O(logN) in space in average
// pattern: post-order
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Base case
        if (root == NULL)
            return NULL;

        TreeNode* invertedLeft = invertTree(root->left);
        TreeNode* invertedRight = invertTree(root->right);

        root->left = invertedRight;
        root->right = invertedLeft;

        return root;
    }
};

// Solution 2: recursive
// Basically same as solution 1, but shorter than a bit
// pattern: postorder
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Base case
        if (root == NULL)
            return NULL;

        TreeNode* tmpLeft = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmpLeft);

        return root;
    }
};

// Solution 3: recursive
// Time & Space complexity same as solution 1
// pattern: preorder
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Base case
        if (root == NULL)
            return NULL;

        TreeNode* tmpLeft = root->left;
        root->left = root->right;
        root->right = tmpLeft;
        // or swap(root->left, root->right)

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

// Solution 4: iterative using stack
// O(N) in time
// O(K) in space, with K = number of nodes at level which has most node
// If tree is complete: K = number of nodes at last level = 2^(d-1),
// with d = depth of tree
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> stack;
        stack.push(root);

        while(!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();

            if (node == NULL)
                continue;

            // Swap 2 children
            TreeNode* tmpLeft = node->left;
            node->left = node->right;
            node->right = tmpLeft;
            // or swap(node->left, node->right)

            stack.push(node->right);
            stack.push(node->left);
        }

        return root;
    }
};
