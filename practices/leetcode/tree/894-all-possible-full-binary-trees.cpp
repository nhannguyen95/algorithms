// https://leetcode.com/problems/all-possible-full-binary-trees/

// Solution 1: DP top down
// Time complexity:
// - T(1) = 1, T(event) = 0
// - T(N) = sum[k=1..N-1]T(k)T(N-k) ~ N/2-th Catalan number ~ O(2^N)
// Space complexity:
// - O(2^N)

class Solution {
public:
    vector<TreeNode*> & allPossibleFBT(int n, vector< vector<TreeNode*> > & memo) {
        if (memo[n].size() != 0 || n % 2 == 0)
            return memo[n];
        
        if (n == 1)
            return memo[n] = vector<TreeNode*>({new TreeNode(0)});
        
        for(int i = 2; i <= n - 1; i += 2) {
            vector<TreeNode*> & leftRoots = allPossibleFBT(i - 1, memo);
            vector<TreeNode*> & rightRoots = allPossibleFBT(n - i, memo);
            
            if (leftRoots.size() != 0 && rightRoots.size() != 0) {
                for(TreeNode* & leftRoot : leftRoots) {
                    for(TreeNode* & rightRoot : rightRoots) {
                        TreeNode* root = new TreeNode(0);
                        root->left = leftRoot;
                        root->right = rightRoot;
                        memo[n].push_back(root);
                    }
                }
            }
                
        }
        return memo[n];
    }
    
    vector<TreeNode*> allPossibleFBT(int N) {
        vector< vector<TreeNode*> > memo(N + 1, vector<TreeNode*>());
        return allPossibleFBT(N, memo);
    }
};

// Solution 1: DP bottom up, avoid space complexity for stack trace
// TODO
