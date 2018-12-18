// https://leetcode.com/problems/minimum-distance-between-bst-nodes

// Solution 1: Recursive
class Solution {
public:
    void inorder(TreeNode* node, int & minDiff, int *& pre) {
        if (node == NULL) return;
        
        inorder(node->left, minDiff, pre);
        if (pre != NULL)
            minDiff = min(minDiff, node->val - *pre);
        pre = &node->val;
        inorder(node->right, minDiff, pre);
    }
    
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        int *pre = NULL;
        inorder(root, minDiff, pre);
        return minDiff;
    }
};

// Solution 2: iterative
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* node = root;
        int minDiff = INT_MAX;
        int *pre = NULL;
        while(!s.empty() || node != NULL) {
            if (node != NULL) {
                s.push(node);
                node = node->left;
            } else {
                node = s.top();
                s.pop();
                if (pre != NULL)
                    minDiff = min(minDiff, node->val - *pre);
                pre = &node->val;
                
                node = node->right;
            }
        }
        return minDiff;
    }
};

// Solution 3: Morris Inorder Tree Traversal
class Solution {
public:
    TreeNode* getPredecessor(TreeNode* node) {
        TreeNode* p = node->left;
        while(p->right != NULL && p->right != node)
            p = p->right;
        return p;
    }
    
    int minDiffInBST(TreeNode* root) {
        TreeNode* node = root;
        int minDiff = INT_MAX;
        int *pre = NULL;
        while(node != NULL) {
            if (node->left == NULL) {
                // Visit node
                if (pre != NULL)
                    minDiff = min(minDiff, node->val - *pre);
                pre = &node->val;
                
                node = node->right;
            } else {
                TreeNode* p = getPredecessor(node);
                
                if (p->right == NULL) {
                    p->right = node;
                    node = node->left;
                } else {
                    // Visit node
                    if (pre != NULL)
                        minDiff = min(minDiff, node->val - *pre);
                    pre = &node->val;
                    
                    node = node->right;
                    p->right = NULL;
                }
            }
        }
        return minDiff;
    }
};
