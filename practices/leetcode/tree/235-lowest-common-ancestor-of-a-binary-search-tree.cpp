// Solution 1: find 2 paths: root->p, root->q
// then lca(p, q) = last node in common prefixes
// of 2 paths.
// Works for unduplicated/duplicated nodes in tree.
// N = number of nodes
// O(2H) = O(H) in space (H = height of tree) for storing the paths.
// O(H) in time also.
class Solution {
public:
    bool findPathFromRoot(TreeNode* root, TreeNode* node, vector<TreeNode*> & path) {
        if (root == NULL) return false;
        path.push_back(root);
        if (root == node) return true;
        bool res = findPathFromRoot(root->left, node, path) ||
                   findPathFromRoot(root->right, node, path);
        if (!res) path.pop_back();
        return res;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == NULL || q == NULL) return NULL;
        vector<TreeNode*> pathp;
        vector<TreeNode*> pathq;
        findPathFromRoot(root, p, pathp);
        findPathFromRoot(root, q, pathq);

        int i = 0;
        while(i < min(pathp.size(), pathq.size()) && pathp[i] == pathq[i]) {
            i++;
        }
        return pathp[i-1];
    }
};

// Solution 2: optimal recursive for unduplicates.
// O(H) in time and space complexity.
// Pattern: preorder
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) return NULL;
        if (p == q) return p;
        return lca(root, p, q);
    }

    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        int mn = min(p->val, q->val);
        int mx = max(p->val, q->val);
        if (root->val < mn) return lca(root->right, p, q);
        if (root->val > mx) return lca(root->left, p, q);
        return root;
    }
};

// Solution 3: iterative version of solution 2
// O(H) in time
// O(1) in space
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) return NULL;
        if (p == q) return p;
        TreeNode* node = root;
        int mn = min(p->val, q->val);
        int mx = max(p->val, q->val);
        while(node != NULL) {
            if (node->val < mn) node = node->right;
            else if (node->val > mx) node = node->left;
            else return node;
        }
        return node;
    }
};

// Solution 4: recursive solution for duplicated nodes in tree
// Unverified yet
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) return NULL;
        if (p == q) return p;
        return lca(root, p, q);
    }

    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root == q || root == p) return root;
        int mn = min(p->val, q->val);
        int mx = max(p->val, q->val);
        if (root->val <= mn) return lca(root->right, p, q);
        if (root->val > mx) return lca(root->left, p, q);
        if (root->val == mx) {
            if (root->val <= mn) return lca(root->right, p, q);
            else return root;
        }
        return root;  // mn < root->val < mx
    }
};
