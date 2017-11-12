#include <string>
#include <cstring>
#include <vector>

using namespace std;
const int maxnode = 1e5 + 10;
const int sigma_sz = 26;
int val[maxnode], ch[maxnode][sigma_sz], sz = 1;

class Trie {
 public:
  /** Initialize your data structure here. */
  Trie() {
    memset(val, 0, sizeof(val));
    memset(ch, 0, sizeof(ch));
    sz = 1;
  }

  inline int idx(char c) { return c - 'a';}

  /** Inserts a word into the trie. */
  void insert(string word) {
    int u = 0;
    for (char c : word) {
      int x = idx(c);
      if (!ch[u][x]) {
        ch[u][x] = sz++;
      }
      u = ch[u][x];
    }
    val[u] = 1;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    int u = 0;
    for (char c : word) {
      int x = idx(c);
      if (!ch[u][x]) return false;
      u = ch[u][x];
    }

    return val[u] == 1;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    int u = 0;
    for (char c : prefix) {
      int x = idx(c);
      if (!ch[u][x]) return false;
      u = ch[u][x];
    }
    return dfs(u);
  }

  bool dfs(int u) {
    if (val[u]) return true; 
    for (int i=0; i<sigma_sz; ++i) if (ch[u][i] && dfs(ch[u][i])) return true;
    return false;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
