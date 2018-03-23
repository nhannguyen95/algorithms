// Solution 1: recursion
// N = number of nodes in tree
// O(N) in time
// O(N) in memory in average (to save the string)
// pattern: preorder
class Solution {
public:
    string tree2str(TreeNode* t) {
        if (t == NULL)
            return "";

        string ans = to_string(t->val);
        if (t->left != NULL || t->right != NULL) {
            ans += "(" + tree2str(t->left) + ")";
            if (t->right != NULL)
                ans += "(" + tree2str(t->right) + ")";
        }

        return ans;
    }
};

// Solution 2: iteration using stack
// Time & Complexity same as solution 1
//
// Observation 1: for every node: ans += (node->val
// Observation 2: when done traversing a node: ans += ")"
//
// If we just implement the iterative version of perorder
// traversal like normal, we can't achieve the 2nd observation.
// To achieve it, we need to know when we are done traversing
// a node.
//
// By memerize which node we already visited (using a hash
// table for example).
class Solution {
public:
    string tree2str(TreeNode* root) {
        // Base case
        if (root == NULL)
            return "";

        stack<TreeNode*> s;
        s.push(root);
        unordered_set<TreeNode*> visited;
        string ans = "";
        while(!s.empty()) {
            TreeNode* node = s.top();
            if (visited.find(node) != visited.end()) {
                // This node is already visited
                ans += ")";
                s.pop();
            } else {
                ans += "(" + to_string(node->val);
                visited.insert(node);
                if (node->left == NULL && node->right != NULL)
                    ans += "()";
                if (node->right != NULL)
                    s.push(node->right);
                if (node->left != NULL)
                    s.push(node->left);
            }
        }
        return ans.substr(1, (int)ans.size() - 2);
    }
};
