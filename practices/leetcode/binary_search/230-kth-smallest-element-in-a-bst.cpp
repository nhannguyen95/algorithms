# Solution 1: hash table + tree traversal
# This solution answers the follow up
# N = number of nodes, H = height of tree
# O(N + H) in space
# O(N + H) in time
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        unordered_map<TreeNode*, int> cnt;
        countNodes(root, cnt);
        
        return findKthSmallest(root, k, cnt);
    }
    
    int findKthSmallest(TreeNode* node, int k, unordered_map<TreeNode*, int> cnt) {
        if (k == 1 + cnt[node->left]) return node->val;
        if (k <= cnt[node->left]) return findKthSmallest(node->left, k, cnt);
        return findKthSmallest(node->right, k - cnt[node->left] - 1, cnt);
    }
    
    int countNodes(TreeNode* node, unordered_map<TreeNode*, int> & cnt) {
        if (node == NULL) return cnt[node] = 0;
        return cnt[node] = countNodes(node->left, cnt) + countNodes(node->right, cnt) + 1;
    }
};

# Solution 2: inorder traversal
# O(1) in space, O(K) in time
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res;
        inorder(root, k, res);
        return res;
    }
    
    void inorder(TreeNode* node, int & k, int & res) {
        if (node->left != NULL) inorder(node->left, k, res);
        if (--k == 0) {
            res = node->val;
            return;
        }
        if (node->right != NULL) inorder(node->right, k, res);
    }
};
