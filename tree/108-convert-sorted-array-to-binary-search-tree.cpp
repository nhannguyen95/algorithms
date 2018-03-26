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
