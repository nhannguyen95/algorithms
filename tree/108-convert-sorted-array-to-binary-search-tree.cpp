// Solution 1: recursion
// Assume that there are no duplicates in array
// N = number of elements
// O(N) in time (each node need to be visited once)
// O(logN) in time in all cases
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, (int)nums.size() - 1);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
        if (l > r) return NULL;

        int m = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = sortedArrayToBST(nums, l, m - 1);
        root->right = sortedArrayToBST(nums, m + 1, r);

        return root;
    }
};

// Solution 2: recursion
// Assume that there are duplicates in array
// values < root belongs to left subtree
// values >= root belongs to right subtree
// O(N) in time
// O(N) in space in case the array contains only 1 value
// (the tree is now right skewed)
// O(logN) in space in average
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, (int)nums.size() - 1);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
        if (l > r) return NULL;

        int m = l + (r - l) / 2;
        int lb = lower_bound(nums.begin() + l, nums.begin() + r, nums[m]) - nums.begin();
        TreeNode* root = new TreeNode(nums[lb]);
        root->left = sortedArrayToBST(nums, l, lb - 1);
        root->right = sortedArrayToBST(nums, lb + 1, r);

        return root;
    }
};

// Solution 3: iterative with no duplicates
// O(N) in time
// This is a BFS algorithm, so the maximum size of the queue
// is the number of nodes at level with has most nodes.
// => Complexity?
// In the worst case: the tree is full binary tree,
// so O(N/2) = O(N) in space (the queue contains all leaf nodes)
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Base case
        if (nums.size() == 0) return NULL;

        TreeNode* root = new TreeNode(0);  // 0 as a place holder

        queue<TreeNode*> qNodes({root});
        queue<int> qPairs({0, (int)nums.size() - 1});

        while(!qPairs.empty()) {
            int lo = qPairs.front(); qPairs.pop();
            int hi = qPairs.front(); qPairs.pop();
            int mi = lo + (hi - lo) / 2;
            TreeNode* node = qNodes.front(); qNodes.pop();
            node->val = nums[mi];

            if (lo <= mi - 1) {
                qPairs.push(lo);
                qPairs.push(mi - 1);
                qNodes.push(node->left = new TreeNode(0));
            }
            if (mi + 1 <= hi) {
                qPairs.push(mi + 1);
                qPairs.push(hi);
                qNodes.push(node->right = new TreeNode(0));
            }
        }

        return root;
    }

};
