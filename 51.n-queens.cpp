#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  vector<int> ans_;
  vector<vector<string>> vans_;
  int n_;
 public:
  bool check(int p, int q) {
    int x1 = p, y1 = ans_[p]; 
    int x2 = q, y2 = ans_[q];

    return x1 == x2 || y1 == y2 || y1 - y2 == x1 - x2 || y1 - y2 == x2 - x1;
  }

  void build() {
    vector<string> str(n_, string(n_, '.'));
    for (int i=0; i<n_; ++i) {
      str[i][ans_[i]-1] = 'Q';
    }
    vans_.emplace_back(str);
  }

  void dfs(int ps) {
    if (ps == n_) {
      build(); 
      return;
    }
    for (int i=1; i<=n_; ++i) {
      ans_.push_back(i);
      bool ok = true;
      for (int j=0; j+1<ans_.size(); ++j) if (check(j, ans_.size()-1)) {
        ok = false; break;
      }
      if (!ok) ans_.pop_back();
      else {
        dfs(ps+1);
        ans_.pop_back();
      }
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    ans_.clear();
    vans_.clear();
    n_ = n;
    dfs(0);
    return vans_;
  }
};
