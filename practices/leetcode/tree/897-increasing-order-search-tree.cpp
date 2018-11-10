// https://leetcode.com/problems/increasing-order-search-tree/

// Soluton 1: Modify the tree
class Solution {
public:
    void inorder(TreeNode* node, TreeNode**& pre) {
        if (node == NULL) return;
        
        inorder(node->left, pre);
        
        node->left = NULL;
        (*pre)->right = node;
        pre = &node;
        
        inorder(node->right, pre);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode * dummy = new TreeNode(0);
        TreeNode** pre = &dummy;
        inorder(root, pre);
        return dummy->right;
    }
};

// Solution 2:
class Solution {
public:
    void inorder(TreeNode* node, vector<TreeNode*> & nodes) {
        if (node == NULL) return;
        inorder(node->left, nodes);
        nodes.push_back(node);
        inorder(node->right, nodes);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);
        for(int i = 0; i < nodes.size(); i++) {
            nodes[i]->left = NULL;
            if (i < nodes.size() - 1)
                nodes[i]->right = nodes[i+1];
        }
        return nodes[0];
    }
};
