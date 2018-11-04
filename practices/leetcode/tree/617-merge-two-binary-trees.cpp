// Solution 1: recursion
// N = node(T1), M = node(T2)
// O(max(N, M)) in time
// O(max(N, M) - min(N, M)) in space
// Pattern: pre-order
class Solution {
public:
    // Merge t2 into t1
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // Base case
        if (t1 == NULL && t2 == NULL)
            return NULL;

        if (t1 == NULL) t1 = new TreeNode(0);
        if (t2 == NULL) t2 = new TreeNode(0);

        t1->val += t2->val;

        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        return t1;
    }
};

// Solution 2: faster, uses less space than #1
// O(number of common nodes) in time
// O(logN) in space in average (due to the stack recursion)
// O(N) if the tree is skewed
class Solution {
public:
    // Merge t2 into t1
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 != NULL && t2 != NULL) {
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
            return t1;
        }

        // t1 == NULL or t2 == NULL
        if (t1 == NULL) return t2;
        return t1;
    }
};

// Solution 3: same as 2
class Solution {
public:
    // Merge t2 into t1
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL)
          return t2;
        if (t2 == NULL)
          return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};

// Solution 3: iterative
class Solution {
public:
    // Merge t2 into t1
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL)
            return t2;

        stack<TreeNode*> stack;

        stack.push(t1);
        stack.push(t2);

        while(!stack.empty()) {
            TreeNode * n2 = stack.top();
            stack.pop();

            TreeNode * n1 = stack.top();
            stack.pop();

            if (n1 == NULL || n2 == NULL)
                continue;

            n1->val += n2->val;

            // Process for left substrees
            if (n1->left == NULL) {
                n1->left = n2->left;
            } else {
                stack.push(n1->left);
                stack.push(n2->left);
            }

            // Process for right substrees
            if (n1->right == NULL) {
                n1->right = n2->right;
            } else {
                stack.push(n1->right);
                stack.push(n2->right);
            }
        }

        return t1;
    }
};
