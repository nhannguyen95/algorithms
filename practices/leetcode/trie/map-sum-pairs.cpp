// https://leetcode.com/problems/map-sum-pairs/solution/

// Solution 1: Brute force with binary search tree (map)
// Time complexity: K = average of key (prefix), N = number of keys in the map
// - insert: O(logN)
// - sum: O(logN + N * P)
class MapSum {
private:
    map<string, int> m;
    
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key] = val;    
    }
    
    int sum(string prefix) {
        auto it = m.lower_bound(prefix);
        int ans = 0;
        while(it != m.end() && (it->first).compare(0, prefix.size(), prefix) == 0) {
            ans += it->second;
            it++;
        }
        return ans;
    }
};

// Solution 2: Trie
struct TrieNode {
    int score;
    map<char, TrieNode*> children;
    TrieNode(int score) : score(score) {}
};

class MapSum {
private:
    map<string, int> mapScore;
    TrieNode* root;
    
public:
    MapSum() {
        root = new TrieNode(0);
    }
    
    void insert(string key, int val) {
        int delta = val - mapScore[key];
        mapScore[key] = val;
        
        TrieNode* node = root;
        for(int i = 0; i < key.size(); i++) {
            char c = key[i];
            if (node->children[c] == NULL)
                node->children[c] = new TrieNode(0);
            node = node->children[c];
            node->score += delta;
        }
    }
    
    int sum(string prefix) {
        TrieNode* node = root;
        for(int i = 0; i < prefix.size(); i++) {
            char c = prefix[i];
            if (node->children.find(c) != node->children.end()) {
                node = node->children[c];
                if (i == (int)prefix.size() - 1)
                    return node->score;
            } else break;
        }
        return 0;
    }
};
    
