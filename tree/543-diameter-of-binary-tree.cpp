// Solution 1: recursive
// Compute the diameter of the path which pass
// through the current node while computing
// its height.
//
// N = number of nodes in tree
// O(N) in time (since each node is visited once)
// O(N) in space in worst case (skewed tree)
// O(logN) in space in average
//
// pattern: post order traversal
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        getHeight(root, diameter);
        return diameter;
    }

    int getHeight(TreeNode* node, int & diameter) {
        if (node == NULL)
            return 0;

        int heightLeft = getHeight(node->left, diameter);
        int heightRight = getHeight(node->right, diameter);

        diameter = max(diameter, heightLeft + heightRight
                                + (node->left != NULL)
                                + (node->right != NULL));
        return max(heightLeft + (node->left != NULL),
                   heightRight + (node->right != NULL));
    }
};

// Solution 2: iterative using stack + hash table
// Please refer to Python file, solution 1.
// The idea is same as solution 1, we use hash table
// to store the height at each node.
// Time & Complexity same as solution 1

// Solution 3: optimal recursive solution, improvation
// of solution 1, using the fact that height(null) = -1.
// Think like we also count NULL as a node in tree.
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        getHeight(root, diameter);
        return diameter;
    }

    int getHeight(TreeNode* node, int & diameter) {
        if (node == NULL)
            return -1;

        int heightLeft = getHeight(node->left, diameter);
        int heightRight = getHeight(node->right, diameter);
        diameter = max(diameter, 2 + heightLeft + heightRight);

        return 1 + max(heightLeft, heightRight);
    }
};

// Solution 4: optimal iterative solution, improvation
// of solution 2, using same idea as solution 3
// Please refer to Python file, solution 2
