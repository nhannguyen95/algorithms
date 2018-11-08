// https://leetcode.com/problems/n-ary-tree-postorder-traversal

// Solution 1: Wrong Answer, don't know how
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
    vector<int> postorder(Node* root) {
        vector<int> order;
        stack<Node*> S;
        Node *node = root, *lastVisited = NULL;
        while(node != NULL || !S.empty()) {
            if (node != NULL) {
                S.push(node);
                for(int i = node->children.size() - 2; i > 0; i--)
                    S.push(node->children[i]);
                
                if (node->children.size() > 0)
                    node = node->children[0];
                else
                    node = NULL;
            } else {
                Node* peak = S.top();
                if (peak->children.size() > 1 && peak->children.back() != NULL && peak->children.back() != lastVisited) {
                    node = peak->children.back();
                } else {
                    order.push_back(peak->val);
                    S.pop();
                    lastVisited = peak;
                }
            }
        }
        return order;
    }
};

// Solution 2: induce from preorder
class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<Node*> s;
        s.push(root);
        vector<int> order;
        while(!s.empty()) {
            Node * node = s.top();
            s.pop();
            if (node != NULL) {
                order.push_back(node->val);
            
                for(auto p : node->children)
                    s.push(p);
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};
