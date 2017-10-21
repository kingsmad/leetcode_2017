#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifdef ROACH_ONLINE_JUDGE
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
 public:
  TreeNode *str2tree(string s) {
    if (s == "") return nullptr;

    TreeNode* o = new TreeNode(-1);
    bool ok = false;
    for (char c : s) if (c == '(') { ok = true; break;}

    if (!ok) {
      sscanf(s.c_str(), "%d", &o->val);
      return o;
    }

    int n = s.size();
    int p = 0; while(p < n && s[p] != '(') ++p;
    int cnt = 1, q = p + 1;
    while(q < n && cnt > 0) {
      if (s[q] == ')') --cnt;
      else if (s[q] == '(') ++cnt;
      ++q;
    }

    sscanf(s.c_str(), "%d", &o->val);
    o->left = str2tree(s.substr(p+1, q-p-2));
    if (q + 1 < n) o->right = str2tree(s.substr(q+1, n-2-q-1+1));

    return o;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  string s; cin >> s; 
  Solution sol;
  TreeNode* root = sol.str2tree(s);
  return 0;
}
#endif
