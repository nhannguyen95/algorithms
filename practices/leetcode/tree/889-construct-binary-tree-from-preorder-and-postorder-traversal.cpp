// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

// Solution 1:
// Preorder:  [root][......left......][...right..]
// Postorder: [......left......][...right..][root]
// Preorder.first() == Postorder.last() == root
// Recursion on left and right
// => need to know position of preorder in postorder
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/discuss/161286/C%2B%2B-O(N)-recursive-solution
class Solution {
public:    
    unordered_map<int, int> m;  // value->index
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = post.size();
        for(int i = 0; i < n; i++)
            m[post[i]] = i;
        return construct(pre, post, 0, n-1, 0, n-1);
    }
    
    TreeNode* construct(vector<int>& pre, vector<int>& post, int a, int b, int c, int d) {
        TreeNode* n = new TreeNode(pre[a]);
        if (a == b) return n;
        int t = pre[a + 1];
        int idx = m[t];  // position of t in post
        int len = idx - c + 1;
        n->left = construct(pre, post, a+1, a+len, c, c+len-1);
        if (idx + 1 == d) return n;
        n->right = construct(pre, post, a+len+1, b, idx+1, d-1);
        return n;
    }
};
