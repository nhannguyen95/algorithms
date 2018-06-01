// Solution 1: based on height of right child
// O(logN) in space, O(log^2N) in time
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getRightLength(TreeNode* root) {
        if (root == NULL) return 0;
        return getRightLength(root->right) + 1;
    }
    
    int getLeftLength(TreeNode* root) {
        if (root == NULL) return 0;
        return getLeftLength(root->left) + 1;
    }
        
    int countNodes(TreeNode* root) {
        // Base case 1
        if (root == NULL) return 0;
        
        int nNodes = 0;
        int d = 0, p = 1, nNodesLevel = 1;
        while(root != NULL) {
            nNodes += nNodesLevel;
            nNodesLevel *= 2;
            if (root->right == NULL) {
                if (root->left != NULL) nNodes += 2*(p-1)+1;
                else nNodes += 2*(p-1);
                break;
            }
            
            int leftLen = getRightLength(root->left);    // O(logN)
            int rightLen = getRightLength(root->right);  // O(logN)
            if (leftLen == rightLen) {
                root = root->left;
                p = 2*(p-1)+1;
            } else { // leftLen > rightLen
                root = root->right;
                p = 2*p;
            }
            d++;
        }
        return nNodes;
    }
};

// Solution 2: based on height of left child
// Complexity same as Solution 1's
class Solution {
public:
    int height(TreeNode* root) {
        return root == NULL ? -1 : (1 + height(root->left));
    }
    
    int countNodes(TreeNode* root) {
        int h = height(root);
        return h < 0 ? 0 :
               h-1==height(root->right) ? (1<<h) + countNodes(root->right) :
                                          (1<<(h-1)) + countNodes(root->left);
    }
};
