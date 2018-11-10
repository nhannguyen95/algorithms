// https://leetcode.com/problems/find-largest-value-in-each-tree-row/

// Solution 1
class Solution {
public:
    void computeMax(TreeNode* node, int depth, vector<int> & ans) {
        if (node == NULL) return;
        
        if (depth >= ans.size()) ans.push_back(node->val);
        else ans[depth] = max(ans[depth], node->val);
        
        computeMax(node->left, depth+1, ans);
        computeMax(node->right, depth+1, ans);
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        computeMax(root, 0, ans);
        return ans;
    }
};
