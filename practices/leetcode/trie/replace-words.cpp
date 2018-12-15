// https://leetcode.com/problems/replace-words

struct TrieNode {
    bool isWord;
    map<char, TrieNode*> children;
    TrieNode() {
        isWord = false;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    string findRoot(string & word) {
        string prefix = "";
        TrieNode* node = root;
        for(char c : word) {
            if (node->children.find(c) == node->children.end())
                break;
            node = node->children[c];
            prefix.push_back(c);
            if (node->isWord)
                return prefix;
        }
        return "";
    }
    
    void insert(string & word) {
        TrieNode* node = root;
        for(char c : word) {
            if (node->children.find(c) == node->children.end())
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isWord = true;
    }
};

class Solution {
public:
    
    vector<string> split(string & s, string delim = " ") {
        vector<string> tokens;
        size_t i = 0;
        for(size_t p = 0; (p = s.find(delim, i)) != s.npos;) {
            string token = s.substr(i, p - i);
            tokens.push_back(token);
            i = p + delim.size();
        }
        if (i < s.size()) tokens.push_back(s.substr(i));
        return tokens;
    }
    
    string replaceWords(vector<string>& dict, string sentence) {
        Trie trie;
        for(string & root : dict)
            trie.insert(root);
        
        string ans = "";
        vector<string> words = split(sentence);
        for(string & word : words) {
            ans += " ";
            string root = trie.findRoot(word);
            if (root.compare("") == 0) ans += word;
            else ans += root;
        }
        return ans.substr(1);
    }
};
