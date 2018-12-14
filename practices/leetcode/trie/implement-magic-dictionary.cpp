// https://leetcode.com/problems/implement-magic-dictionary/

struct TrieNode {
    vector<TrieNode*> children;
    bool isWord;
    TrieNode() {
        children.assign(26, (TrieNode*)NULL);
        isWord = false;
    }
};

class MagicDictionary {
private:
    TrieNode* root;
    
    void insert(string & s) {
        TrieNode* node = root;
        for(char c : s) {
            if (node->children[c-'a'] == NULL)
                node->children[c-'a'] = new TrieNode();
            node = node->children[c-'a'];
        }
        node->isWord = true;
    }
    
    bool dfs(int i, TrieNode* node, string & s, int cntModifies) {
        if (i == s.size()) {
            if (node->isWord && cntModifies == 1) return true;
            return false;
        }
        
        bool ans = false;
        for(int j = 0; j < 26; j++) {
            TrieNode* next = node->children[j];
            if (next != NULL) {
                if (j == s[i] - 'a')
                    ans = ans || dfs(i+1, next, s, cntModifies);
                else
                    ans = ans || dfs(i+1, next, s, cntModifies+1);
            }
        }
        return ans;
    }
    
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        // this->root = new TrieNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        root = new TrieNode();
        for(string & word : dict)
            insert(word);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return dfs(0, root, word, 0);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
