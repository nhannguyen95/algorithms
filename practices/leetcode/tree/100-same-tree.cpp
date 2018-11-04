// Solution 1: recursion
// N = number of nodes in tree
// O(N) in time
// O(2N) = O(N) in space in worst case (skewed tree)
// O(2logN) = O(logN) in space in average
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL && q != NULL) return false;
        if (p != NULL && q == NULL) return false;
        return (p->val == q->val) &&
                isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right);
    }
};


// Solution 2: iteration using stack
// O(N) in time
// O(M) in space, M = number of nodes at most-node level.
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stackp;
        stack<TreeNode*> stackq;

        stackp.push(p);
        stackq.push(q);

        while(!stackp.empty() && !stackq.empty()) {
            TreeNode * nodep = stackp.top();
            stackp.pop();
            TreeNode * nodeq = stackq.top();
            stackq.pop();

            if (nodep == NULL && nodeq == NULL) continue;
            if (nodep == NULL && nodeq != NULL) return false;
            if (nodep != NULL && nodeq == NULL) return false;
            if (nodep->val != nodeq->val) return false;

            stackp.push(nodep->left);
            stackp.push(nodep->right);

            stackq.push(nodeq->left);
            stackq.push(nodeq->right);
        }
        return true;
    }
};

// Solution 3: minimal version of solution 1
// Solution 2 can be fixed similarly
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) return (p == q);
        return (p->val == q->val) &&
                isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right);
    }
};

// Solution 4: iteration only 1 stack
// Please refer to Python file.
