/*  Trie

2 status of a vertex: isWord = true - this vertex marks
the end of a word in the dictionary.

Space complexity: If the dictionary has N words, and each word
has M characters in average, then Trie will have N*M nodes, and
building the Trie obviously takes O(N*M).

The information in the Node depends on problems.

You can implement Suffix Trie or Prefix Trie on a string.

When build Suffix Trie or Prefix Trie, the node which has isWord=True
saves the index of the suffix or the prefix.

Suppose we already built the Suffix Trie of a given string T (n = len(T)),
some applications:
- String matching: find some pattern string P in T with O(len(P) + number of occurences)
- Find Longest Repeated Substring in O(n)
- Find Longest Common Substring of 2 or more strings in linear time.

*/

#include <iostream>
#include <vector>
using namespace std;

struct Node {
  bool isWord;
  vector<Node*> next;
  Node() {
    isWord = false;
    next.assign(26, NULL);
  }
};

class Trie {
private:
  Node* root;

  void dfs(Node* node, string & word, const string & prefix, vector<string> & words) {
    if (node->isWord)
      words.push_back(prefix + word);
    for(int i = 0; i < 26; i++) {
      if (node->next[i] != NULL) {
        word.push_back('a' + i);
        dfs(node->next[i], word, prefix, words);
        word.pop_back();
      }
    }
  }

public:
  Trie() { root = new Node(); }

  // `word` contains only lowercase letters.
  void insert(const string word) {
    Node* node = root;
    for(char c : word) {
      int letter = c - 'a';
      node->next[letter] = (node->next[letter] != NULL) ? node->next[letter] : new Node();
      node = node->next[letter];
    }
    node->isWord = true;
  }

  vector<string> prefixSearch(const string prefix) {
    vector<string> words;
    Node* node = root;
    for(char c : prefix) {
      int letter = c - 'a';
      if (node->next[letter] == NULL)
        return words;
      node = node->next[letter];
    }

    string word;
    dfs(node, word, prefix, words);
    return words;
  }
};

int main() {
  Trie trie;
  trie.insert("set");
  trie.insert("lol");
  trie.insert("setter");
  trie.insert("setting");
  trie.insert("settings");
  
  string query = "setting";
  cout << "All words whose prefix is '" << query << "':\n";
  vector<string> words = trie.prefixSearch(query);
  if (words.size()) {
    for(string & word : words)
      cout << word << '\n';
  }
  else {
    cout << "No\n";
  }

  return 0;
}
