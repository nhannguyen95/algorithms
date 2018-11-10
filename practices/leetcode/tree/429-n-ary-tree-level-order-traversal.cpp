// https://leetcode.com/problems/n-ary-tree-level-order-traversal

// Solution 1: BFS
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        
        queue<Node*> q;
        q.push(root);
        int levelSize = 1;
        while(!q.empty()) {
            ans.push_back(vector<int>());
            while(levelSize--) {
                Node* node = q.front();
                q.pop();
                ans.back().push_back(node->val);
                for(auto child : node->children)
                    if (child != NULL)
                        q.push(child);
            }   
            levelSize = q.size();
        }
        return ans;
    }
};
