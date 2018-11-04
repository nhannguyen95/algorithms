// Solution 1:
// Serialize: BFS to build level order string representation of tree
// Deserialize: linear scan to build the tree
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> s({root});
        string str = "";
        while(!s.empty()) {
            TreeNode* node = s.front();
            s.pop();
            if (node == NULL) {
                str += "null,";
            } else {
                str += to_string(node->val) + ",";
                s.push(node->left);
                s.push(node->right);
            }
        }
        if (str.size()) str.pop_back();  // Remove last ',' character
        return str;
    }
    
    vector<string> splitAll(const string & s, string delim = ",") {
        vector<string> tokens;
        size_t last = 0;
        for(size_t next = 0; (next = s.find(delim, last)) != s.npos; ) {
            tokens.push_back(s.substr(last, next - last));
            last = next + delim.size();
        }
        tokens.push_back(s.substr(last));
        return tokens;
    }
        
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> datas = splitAll(data);
        while(datas.size() && datas.back() == "null")
            datas.pop_back();
        
        int n = datas.size();
        cout << n << '\n';
        vector<TreeNode*> nodes(n, NULL);
        for(int i = 0; i < n; i++)
            if (datas[i] != "null")
                nodes[i] = new TreeNode(stoi(datas[i]));
        
        int j = 1;
        for(int i = 0; i < n; i++) {
            if (nodes[i] != NULL) {
                nodes[i]->left = j < n ? nodes[j] : NULL; j++;
                nodes[i]->right = j < n ? nodes[j] : NULL; j++;
            }    
        }
        return n ? nodes[0] : NULL;
    }
}; 
