// https://leetcode.com/problems/minimum-absolute-difference-in-bst

// Solution 1: recursive
class Solution {
public:
    void inorder(TreeNode* node, int *& pre, int & minDiff) {
        if (node == NULL) return;
        inorder(node->left, pre, minDiff);
        if (pre != NULL)
            minDiff = min(minDiff, abs(node->val - *pre));
        pre = &node->val;
        inorder(node->right, pre, minDiff);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        int *pre = NULL;
        inorder(root, pre, minDiff);
        return minDiff;
    }
};

// Solution 2: iterative
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        TreeNode* node = root;
        stack<TreeNode*> s;
        int minDiff = INT_MAX;
        int *pre = NULL;
        while(node != NULL || !s.empty()) {
            if (node != NULL) {
                s.push(node);
                node = node->left;
            } else {
                node = s.top(); s.pop();
                if (pre != NULL)
                    minDiff = min(minDiff, abs(node->val - *pre));
                pre = &node->val;
                node = node->right;
            }
        }
        return minDiff;
    }
};

// Solution 3: Morris
class Solution {
public:
    TreeNode* getPredecessor(TreeNode* node) {
        TreeNode* p = node->left;
        while(p->right != NULL && p->right != node) {
            p = p->right;
        }
        return p;
    }

    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        int *pre = NULL;
        TreeNode* node = root;
        while(node != NULL) {
            if (node->left == NULL) {
                if (pre != NULL)
                    minDiff = min(minDiff, abs(node->val - *pre));
                pre = &node->val;
                
                node = node->right;
            } else {
                TreeNode *p = getPredecessor(node);
                
                if (p->right == NULL) {
                    p->right = node;
                    node = node->left;
                } else {
                    if (pre != NULL)
                        minDiff = min(minDiff, abs(node->val - *pre));
                    pre = &node->val;
                    
                    node = node->right;
                    p->right = NULL;
                }
            }
        }
        return minDiff;
    }
};
