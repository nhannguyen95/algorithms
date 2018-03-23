// Solution 1: recursion
// N = number of nodes in tree
// O(N) in time
// O(N) in space in worst case (skewed tree)
// O(logN) in space in average
// pattern: right->node->left (inorder)
class Solution {
public:
    long long sum = 0;

    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        convertBST(root->right);

        sum += root->val;
        root->val = sum;

        convertBST(root->left);

        return root;
    }
};


// Solution 2: iteration
// Space & Time Complexity same as solution 1
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode * node = root;
        long long sum = 0;
        while(node != NULL || !stk.empty()) {
            if (node != NULL) {
                stk.push(node);
                node = node->right;
            } else {
                TreeNode* cur = stk.top();
                stk.pop();

                sum += cur->val;
                cur->val = sum;

                node = cur->left;
            }
        }
        return root;
    }
};


// Solution 3: iteration + O(1) space
// Nice explanation here:
// https://leetcode.com/problems/convert-bst-to-greater-tree/solution/
//
// The basic idea: considering a node A (in right->in->left
// order), if A->right != NULL, we need to traverse
// its right child first. We also need to find a way to
// go back to A when we done traversing its right child.
//
// So how to do that without O(N) space complexity?
//
// We need to create a link from some node in a A's right
// subtree to A.
//
// Naturally, we're gonna choose the node so that A is
// visited immediately after this node.
//
// That is the smallest node whose value greater than A's,
// let's call it B.
//
// Easy to see that B->left == NULL, we can link to A using
// this left: B->left = A
//
// O(3N) = O(N) in time
// O(1) in space
class Solution {
public:

    TreeNode* getSuccessor(TreeNode* node) {
        TreeNode* succ = node->right;
        while ((succ->left != NULL) && (succ->left != node)) {
            succ = succ->left;
        }
        return succ;
    }

    TreeNode* convertBST(TreeNode* root) {
        TreeNode* node = root;
        long long sum = 0;
        while (node != NULL) {
            // While node hasn't reached the left child of smallest node

            // If there is no right child, we can visit this node and
            // continue traversing left child
            if (node->right == NULL) {
                sum += node->val;
                node->val = sum;
                node = node->left;
            } else {
                // If there is right child, there must be a greater node
                // than current node, should visit it first
                TreeNode* succ = getSuccessor(node);

                // There is no link yet, create a link to current node
                // (so that we can go back when done traversing right subtree)
                if (succ->left == NULL) {
                    succ->left = node;
                    node = node->right;
                } else {
                    // It's a link we created, we done traversing
                    // current node's right subtree, now should
                    // visit this node and move to its left subtree
                    succ->left = NULL;  // remove link
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                }
            }
        }
        return root;

    }
};
