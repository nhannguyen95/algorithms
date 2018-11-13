// https://leetcode.com/problems/complete-binary-tree-inserter

// Solution 1: Using queue to store parents
// Time complexity:
//   - O(N) for construction, O(1) for all other methods
// Space complexity: O(N/2) for the queue
class CBTInserter {
private:
    TreeNode* root;
    queue<TreeNode*> parents;  // Save nodes whose number of childrent = 0 or 1
    
    TreeNode* getParent() {
        TreeNode* parent = this->parents.front();
        if (parent->left == NULL || parent->right == NULL)
            return parent;
        this->parents.pop();
        return this->parents.front();
    }
    
    void addParent(TreeNode* node) {
        this->parents.push(node);
    }
    
public:
    // O(N) in time
    CBTInserter(TreeNode* root) {
        this->root = root;
        this->parents = queue<TreeNode*>();
        
        // Save future parents for performing insert.
        queue<TreeNode*> Q({root});
        int size = 1;
        bool parentFound = false;
        while(!Q.empty()) {
            while(size--) {
                TreeNode* node = Q.front();
                Q.pop();
                
                // If this node is the next parent, we save
                // all subsequent nodes from this one.
                if (!parentFound && node->right == NULL) {
                    parentFound = true;
                }
                if (parentFound) addParent(node);
                
                if (node->left != NULL) Q.push(node->left);
                if (node->right != NULL) Q.push(node->right);
            }
            size = Q.size();
        }
    }
    
    // O(1) in time
    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        TreeNode* parent = getParent();
        
        if (parent->left == NULL)
            parent->left = node;
        else if (parent->right == NULL)
            parent->right = node;
        
        addParent(node);
        
        return parent->val;
    }
    
    // O(1) in time
    TreeNode* get_root() {
        return this->root;    
    }
};
