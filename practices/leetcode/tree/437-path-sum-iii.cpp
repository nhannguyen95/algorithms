// Solution 1: recursive + hash table
// N = number of nodes
// O(N) in time complexity (each node is visted once)
// O(N) in space complexity (for the hash table)
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<long long, int> summed;
        summed[0] = 1;
        int ans = 0;
        cntPathSum(root, sum, 0, ans, summed);
        return ans;
    }

    void cntPathSum(TreeNode* node, const int & target, int sum,
                   int & cnt, unordered_map<long long, int> summed) {
        if (node == NULL) return;
        cnt += summed[sum + node->val - target];
        summed[sum + node->val]++;
        cntPathSum(node->left, target, sum + node->val, cnt, summed);
        cntPathSum(node->right, target, sum + node->val, cnt, summed);
        summed[sum + node->val]--;
    }
};

// Solution 2: iterative using stack
// Time and Space complexity same as solution 1
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        unordered_map<long long, int> summed;
        summed[0] = 1;
        unordered_set<TreeNode*> visited;
        stack<TreeNode*> stack({root});
        int cnt = 0;
        long long curSum = 0;
        while(!stack.empty()) {
            TreeNode* node = stack.top();
            if (visited.find(node) == visited.end()) {
                curSum += node->val;
                cnt += summed[curSum - sum];
                summed[curSum]++;
                visited.insert(node);

                if (node->left != NULL) stack.push(node->left);
                if (node->right != NULL) stack.push(node->right);
            } else {
                summed[curSum]--;
                curSum -= node->val;
                stack.pop();
            }
        }
        return cnt;
    }
};
