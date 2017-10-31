#include <list>
#include <set>
#include <vector>
#include <iostream>

using namespace std;
using ll = long long;
int ans = 0;

class Solution {
 public:
  int countArrangement(int N) {
    ans = 0;
    const int n = N;

    vector<int> path;
    set<int> ms;
    for(int i=1; i<=n; ++i) ms.insert(i);

    dfs(ms, path);

    return ans;
  }


  void dfs(set<int>& ms, vector<int>& path) {
    if (!check(path)) return;

    if (ms.empty()) { ++ans; return;}

    vector<int> tmp(ms.begin(), ms.end());
    
    for (int d : tmp) {
      ms.erase(d);
      path.push_back(d);

      dfs(ms, path);

      ms.insert(d);
      path.pop_back();
    }
  }

  bool check(vector<int>& v) {
    if (v.empty()) return true;

    const int n = v.size();
    for (int i=0; i<n; ++i) {
      if ((v.at(i) % (i+1) != 0) && ((i+1) % v.at(i) != 0)) 
        return false;
    }

    return true;
  }

};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  Solution sol;
  int n; scanf("%d", &n);
  int ans = sol.countArrangement(n);
  return 0 * printf("%d\n", ans);
}
#endif
