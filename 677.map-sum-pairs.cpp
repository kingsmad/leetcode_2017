#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

using ll = long long;
class MapSum {
  map<string, int> smp;

 public:
  /** Initialize your data structure here. */
  MapSum() {}

  void insert(string key, int val) { smp[key] = val; }

  int sum(string prefix) {
    auto fst = smp.lower_bound(prefix);
    auto lst = smp.upper_bound(prefix + "z");
    int ans = 0;
    for (auto it = fst; it != lst; ++it) { ans += it->second; }
    return ans;
  }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 *
 */
