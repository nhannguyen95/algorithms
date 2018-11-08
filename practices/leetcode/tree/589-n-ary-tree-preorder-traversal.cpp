// https://leetcode.com/problems/n-ary-tree-preorder-traversal

// Solution 1: Preorder iterative
// O(N) in time
// Depending on the tree structure we might need to save all tree so O(N) in space
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> preOrder;
        stack<Node*> S;
        Node* node = root;
        while(node != NULL || !S.empty()) {
            if (node != NULL) {
                // Visit this node.
                preOrder.push_back(node->val);
                
                for(int i = node->children.size() - 1; i >= 1; i--)
                    S.push(node->children[i]);
                
                if (node->children.size() > 0)
                    node = node->children[0];
                else
                    node = NULL;
            } else {
                node = S.top();
                S.pop();
            }
        }
        return preOrder;
    }
};
