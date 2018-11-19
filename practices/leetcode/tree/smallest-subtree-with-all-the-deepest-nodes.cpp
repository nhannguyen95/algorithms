// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes

// Solution 1: 2 DFS
class Solution {
public:
	struct Result {
		TreeNode* root;
		int nDeepest;
		Result(TreeNode* node, int nDeepest) :
			root(node), nDeepest(nDeepest) {}
	};

    int getTreeDepth(TreeNode* root) {
        if (root == NULL)
            return -1;
        if (root->left == NULL && root->right == NULL)
            return 0;
        
        return 1 + max(getTreeDepth(root->left), getTreeDepth(root->right));
    }

    Result subtreeWithAllDeepest(TreeNode* root, const int treeDepth, int depth=0) {
        if (root == NULL) return Result(root, 0);
        if (depth == treeDepth) return Result(root, 1);

        Result left = subtreeWithAllDeepest(root->left, treeDepth, depth + 1);
        Result right = subtreeWithAllDeepest(root->right, treeDepth, depth + 1);

        if (left.nDeepest == 0) return right;
        if (right.nDeepest == 0) return left;

        return Result(root, left.nDeepest + right.nDeepest);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // Return deepest level and number of deepest nodes.
        int treeDepth = getTreeDepth(root);

        return subtreeWithAllDeepest(root, treeDepth).root;
    }
};

// Solution 2: 1 DFS
class Solution {
public:
	struct Result {
		TreeNode* root;
        int depth;
		int nDeepest;
		Result(TreeNode* node, int depth, int nDeepest) :
			root(node), depth(depth), nDeepest(nDeepest) {}
	};

    Result subtreeWithAllDeepest(TreeNode* root, int depth) {
        if (root == NULL)
            return Result(root, -1, 0);
        if (root->left == NULL && root->right == NULL)
            return Result(root, 0, 1);
        
        Result left = subtreeWithAllDeepest(root->left, depth + 1);
        Result right = subtreeWithAllDeepest(root->right, depth + 1);

        if (left.depth > right.depth) {
            left.depth++;
            return left;
        }
        if (left.depth < right.depth) {
            right.depth++;
            return right;
        }

        return Result(root, 1 + left.depth, left.nDeepest + right.nDeepest);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return subtreeWithAllDeepest(root, 0).root;
    }
};
