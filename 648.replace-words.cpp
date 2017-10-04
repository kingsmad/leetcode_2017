#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
const int maxnode = 1e5 + 10;
const int sigma_sz = 26;

struct Trie {
  int ch[maxnode][sigma_sz], val[maxnode], sz; 

  void clear() {
    memset(ch, 0, sizeof(ch));
    memset(val, 0, sizeof(val));
    sz = 1;
  }

  inline int idx(char c) { return c - 'a';}

  void insert(const string s) {
    int u = 0;
    for (char c : s) {
      int x = idx(c);
      if (ch[u][x] == 0) {
        ch[u][x] = sz++;
      }
      u = ch[u][x];
    }
    val[u] = 1;  
  }

  string query(const string& s) {
    int u = 0, p = 0;
    while(p < s.size()) {
      if (val[u] == 1) break;
      int x = idx(s.at(p));
      if (ch[u][x] == 0) return s; 
      u = ch[u][x];
      ++p;
    }
    
    return s.substr(0, p); 
  }

} trie;

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
      trie.clear();  
      for (const string& s : dict) {
        trie.insert(s);
      }
      
      string ans = "";
      istringstream in(sentence);
      string s = "";
      while(getline(in, s, ' ')) {
        if (ans != "") ans.push_back(' ');
        ans += trie.query(s);
      }
      return ans;
    }
};
