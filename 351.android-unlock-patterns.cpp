#include <set>
#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int numberOfPatterns(int m, int n) {
    int ans = 0;
    vector<int> path;
    for (int k=m; k<=n; ++k) {
      path.clear();
      unordered_set<int> ms;
      for (int i=1; i<=9; ++i) ms.insert(i);

      dfs(k, ms, path, ans); 
    }
    
    return ans;
  }

  void dfs(int hc, unordered_set<int>& ms, vector<int>& path, int& ans) {
    if (hc == 0) {
      if (Judge(path)) ++ans;
      return;
    }

    if (hc > 0) {
      for (int i=1; i<=9; ++i) {
        if (ms.count(i) == 0) continue;
        ms.erase(i);
        path.push_back(i);

        dfs(hc-1, ms, path, ans);

        ms.insert(i);
        path.pop_back();
      }
    }
  }

  bool Judge(const vector<int>& vc) {
    for (int i=0; i+1<vc.size(); ++i) {
      if (!IsAdj(vc.at(i), vc.at(i+1))) {
        bool found = false;
        int target = (vc.at(i) + vc.at(i+1)) / 2;
        for (int j=0; j<i; ++j) {
          if (vc.at(j) ==  target) { found = true; break;}
        }
        if (found) continue;
        return false;
      }
    }

    return true;
  }

  bool IsAdj(int x, int y) {
    switch (x) {
      case 1 : 
        return y != 3 && y != 7 && y != 9;
      case 2 :
        return y != 8;
      case 3 : 
        return y != 1 && y != 7 && y != 9;
      case 4 : 
        return y != 6;
      case 5 : 
        return true;
      case 6 :
        return y != 4;
      case 7 :
        return y != 1 && y != 3 && y != 9;
      case 8 :
        return y != 2;
      case 9 :
        return y != 1 && y != 3 && y != 7;
    }
  }

};
