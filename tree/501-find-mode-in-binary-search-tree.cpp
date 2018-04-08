// Solution 1: recursive
// O(1) in space (don't count recursion stack call)
// O(N) in time
class Solution {
public:
    void inorder(TreeNode* node, vector<int>& modes, int & maxCnt, int & cnt, int & pre) {
        if (node == NULL) return;

        inorder(node->left, modes, maxCnt, cnt, pre);

        if (node->val == pre) cnt++;
        else {
            if (cnt > maxCnt) {
                modes.clear();
                modes.push_back(pre);
                maxCnt = cnt;
            } else if (cnt == maxCnt) {
                modes.push_back(pre);
            }
            cnt = 1;
        }
        pre = node->val;

        inorder(node->right, modes, maxCnt, cnt, pre);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        if (root == NULL) return modes;
        int maxCnt = 0;
        int cnt = 0;
        int pre = root->val;
        inorder(root, modes, maxCnt, cnt, pre);
        if (cnt > maxCnt) {
            modes.clear();
            modes.push_back(pre);
            maxCnt = cnt;
        } else if (cnt == maxCnt) {
            modes.push_back(pre);
        }

        cnt = 1;
        return modes;
    }
};
