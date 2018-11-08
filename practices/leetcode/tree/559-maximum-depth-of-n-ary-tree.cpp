// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

// Solution 1: Just normal dfs, so O(V + E) = O(N + N - 1) = O(N) in time
// O(H) in space
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        
        int depth = 0;
        for(auto child : root->children)
            depth = max(depth, maxDepth(child));
        return depth + 1;
    }
};
