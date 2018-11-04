// Solution 1:
// N = number of node of original tree,
// M = number of node of trimmed tree.
// Worst case: M = N
// O(NlogN) in time in worst case
// O(N+M) in space in worst case (skewed tree)
// O(logN + M) in space in average
class Solution {
public:

    // Convention:
    // v <  root->val: v belongs to left,
    // v >= root->val: v belongs to right.

    TreeNode* trimmedNode = NULL;

    void insertNode(TreeNode *& root, int val) {
        if (root == NULL) {
            root = new TreeNode(val);
            return;
        }

        // If val belongs to left subtree
        if (val < root->val) {
            if (root->left == NULL) root->left = new TreeNode(val);
            else insertNode(root->left, val);
            return;
        }

        // If val belongs to right subtree
        if (root->right == NULL) root->right = new TreeNode(val);
        else insertNode(root->right, val);
    }

    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == NULL)
            return trimmedNode;

        if (L <= root->val && root->val <= R)
            insertNode(trimmedNode, root->val);

        if (root->val > L)
            trimBST(root->left, L, R);

        if (root->val <= R)
            trimBST(root->right, L, R);

        return trimmedNode;
    }
};

// Solution 2:
// O(N) in time in worst case (if all node belongs to [L, R])
// O(N) in space in worst case (if skewed tree)
// Pattern: preorder
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == NULL) return root;
        if (root->val < L) return trimBST(root->right, L, R);
        if (root->val > R) return trimBST(root->left, L, R);

        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};

// Solution 3: iterative
// time and space complexity same as 2
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        stack<TreeNode**> stack;
        stack.push(&root);

        while(!stack.empty()) {
            TreeNode** node = stack.top();
            stack.pop();

            if (*node == NULL) continue;

            if ((*node)->val < L) {
                (*node) = (*node)->right;
                stack.push(node);
                continue;
            }
            if ((*node)->val > R) {
                (*node) = (*node)->left;
                stack.push(node);
                continue;
            }

            stack.push(&((*node)->right));
            stack.push(&((*node)->left));
        }
        return root;
    }
};
