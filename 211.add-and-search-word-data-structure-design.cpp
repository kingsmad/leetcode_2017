#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxnode = 1e5 + 10;
const int sigma_sz = 26;

struct Trie {
  int ch[maxnode][sigma_sz], val[maxnode], sz;
  void init() {
    memset(ch, 0, sizeof(ch));
    memset(val, 0, sizeof(val));
    sz = 1;
  }

  inline int sid(char c) { return c - 'a';}

  void insert(const string& word) {
    int u = 0;
    for (char c : word) {
      int x = sid(c);
      if (!ch[u][x]) ch[u][x] = sz++;
      u = ch[u][x];
    }
    val[u] = 1;
  }

  bool dfs(string s, int root) {
    int u = root;
    for (int i=0; i<s.size(); ++i) {
      if (s[i] == '.') {
        for (int j=0; j<sigma_sz; ++j) 
          if (ch[u][j] && dfs(s.substr(i+1, s.size()), ch[u][j]))
            return true;
        return false;
      }
      int x = sid(s[i]);
      if (!ch[u][x]) return false;
      u = ch[u][x];
    }
    return val[u] == 1;
  }

} trie;

class WordDictionary {
 public:
  /** Initialize your data structure here. */
  WordDictionary() {trie.init();}

  /** Adds a word into the data structure. */
  void addWord(string word) {
    trie.insert(word);
  }

  /** Returns if the word is in the data structure. A word could contain the dot
   * character '.' to represent any one letter. */
  bool search(string word) {
    return trie.dfs(word, 0);
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
