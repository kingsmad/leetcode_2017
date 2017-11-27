#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

class Solution {
 public:
  string getPermutation(int n, int k) {
    --k;
    string ans = "";
    set<int> ms;
    for (int i=1; i<=n; ++i) ms.insert(i);

    while(ms.size()) {
      auto it = ms.begin();
      if (ms.size() > 1) {
        int page = factor(ms.size()-1);
        int x = k / page;
        k = k % page;

        while(x--) ++it;
      }

      ans.push_back(*it + '0');
      ms.erase(it);
    }


    return ans;
  }

  ll factor(ll x) {
    if (x == 0) return 1;
    ll ans = 1;
    for (int i=2; i<=x; ++i) ans *= i;
    return ans;
  }
};
