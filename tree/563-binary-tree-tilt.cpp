// Solution 1: recursion inside recursion
// N = number of nodes in tree
// O(NlogN) in time in average
// Proof: by solving T1, T2
// O(N) in space if skewed tree
// O(logN) in space in average
class Solution {
public:
    // T2(n) = n
    int getSum(TreeNode* node) {
        if (node == NULL) return 0;
        return node->val + getSum(node->left) + getSum(node->right);
    }

    // T1(n) = 2T2(n/2) + 2T1(n/2)
    int findTilt(TreeNode* root) {
        // Base case
        if (root == NULL) {
            return 0;
        }

        int sumLeft = getSum(root->left);
        int sumRight = getSum(root->right);

        return abs(sumLeft - sumRight) +
               findTilt(root->left) +
               findTilt(root->right);
    }
};

// Solution 2: 1 recursion
// Instead of compute sum of each node while traversing,
// we can pre-compute them and save the sum in a hash map.
// O(2N) = O(N) in time
// O(N) in space in average
class Solution {
public:
    int getSum(TreeNode* node, unordered_map<TreeNode*, int> & sum) {
        if (node == NULL) {
            return sum[node] = 0;
        }

        return sum[node] = node->val +
                           getSum(node->left, sum) +
                           getSum(node->right, sum);
    }

    int findTilt_(TreeNode* node, unordered_map<TreeNode*, int> & sum) {
        if (node == NULL) {
            return 0;
        }

        return abs(sum[node->left] - sum[node->right]) +
               findTilt_(node->left, sum) +
               findTilt_(node->right, sum);
    }

    int findTilt(TreeNode* root) {
        unordered_map<TreeNode*, int> sum;
        getSum(root, sum);  // pre-calculate sum of tree at each node in O(N) time

        return findTilt_(root, sum);  // calculate the tilt of each node in O(N) time
    }
};

// Solution 3: optimal recursion
// Computing the tile of each node while computing
// the sum
// O(N) in time
// O(N) in space if skewed tree
// O(logN) in space in average
// pattern: post-order traverse
class Solution {
public:
    int getSum(TreeNode* node, int & tilt) {
        if (node == NULL) return 0;

        int sumLeft = getSum(node->left, tilt);
        int sumRight = getSum(node->right, tilt);

        tilt += abs(sumLeft - sumRight);

        return node->val + sumLeft + sumRight;
    }

    int findTilt(TreeNode* root) {
        int tilt = 0;
        getSum(root, tilt);
        return tilt;
    }
};

// Solution 4: iterative solution
// Please refer to Python version, solution 1.
