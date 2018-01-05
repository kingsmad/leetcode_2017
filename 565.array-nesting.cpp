#include <map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;
const int maxn = 1e5 + 10;
int n;
int fa[maxn]; 
int findset(int x) { return (x == fa[x]) ? x : fa[x] = findset(fa[x]);}
void join(int x, int y) {
  int u = findset(x), v = findset(y);
  if (u == v) return ;
  fa[v] = u;
}
class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    n = nums.size();
    for (int i=0; i<n; ++i) fa[i] = i;
    for (int i=0; i<n; ++i) join(i, nums.at(i));

    map<int, int> ms;
    for (int i=0; i<n; ++i) {
      ++ms[findset(i)];
    }

    int ans = 0;
    for (auto& it : ms) ans = max(ans, it.second);
    return ans;
  }
};
