// https://leetcode.com/problems/leaf-similar-trees/

// Solution 1
class Solution {
public:
    bool isLeaf(TreeNode* node) {
        return (node != NULL) && (node->left == NULL) && (node->right == NULL);
    }
    
    void findLeafSequence(TreeNode* node, vector<int>& sequence) {
        if (node == NULL) return;
        
        findLeafSequence(node->left, sequence);
        findLeafSequence(node->right, sequence);
        if (isLeaf(node)) sequence.push_back(node->val);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> sequence1;
        vector<int> sequence2;
        
        findLeafSequence(root1, sequence1);
        findLeafSequence(root2, sequence2);
        
        return sequence1 == sequence2;
    }
};
