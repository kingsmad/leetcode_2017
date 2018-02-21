#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int sigma_sz = 2;
struct Trie {
  int n, ch[maxn][sigma_sz], val[maxn], sz;
  void init(int tn) {
    n = tn;
    memset(ch, 0, sizeof(ch));
    sz = 1;
    memset(val, -1, sizeof(val));
  }

  void insert(int x) {
    int u = 0;
    for (int i = 31; i >= 0; --i) {
      int c = (x & (1 << i)) ? 1 : 0;
      if (ch[u][c] == 0) { ch[u][c] = sz++; }
      u = ch[u][c];
    }
    val[u] = x;
  }

  // the longest reverse match node
  int query(int x) {
    int u = 0;
    for (int i = 31; i >= 0; --i) {
      int c = (x & (1 << i)) ? 0 : 1;
      if (ch[u][c] == 0) c = 1 - c;
      if (ch[u][c] == 0) break;
      u = ch[u][c];
    }
    assert(val[u] != -1);
    return val[u];
  }
} trie;

class Solution {
 public:
  int findMaximumXOR(vector<int>& nums) {
    int n = nums.size();
    trie.insert(0);
    trie.init(n);
    for (int x : nums) trie.insert(x);

    int ans = 0;
    for (int x : nums) {
      int y = trie.query(x);
      ans = max(ans, x ^ y);
    }
    return ans;
  }
};
