#include <set>
#include <vector>
using namespace std;
using ll = long long;
class Solution {
  struct Node {
    int lst, cnt;
    Node(int d1, int d2) : lst(d1), cnt(d2) { }
  };
public:
  bool isPossible(vector<int>& nums) {
    auto cmp = [](const Node& n1, const Node& n2) { 
      if (n1.lst != n2.lst) return n1.lst < n2.lst;
      if (n1.cnt != n2.cnt) return n1.cnt < n2.cnt;
      return (ll)(&n1) < (ll)(&n2);
    };
    multiset<Node, decltype(cmp)> mset(cmp);

    for (int d : nums) {
      auto it = mset.lower_bound(Node(d-1, 0));
      if (it == mset.end() || it->lst != d-1) {
        mset.emplace(Node(d, 1));
      } else {
        Node tmp = *it;
        mset.erase(it);
        tmp.lst = d;
        ++tmp.cnt;
        mset.emplace(tmp);
      }
    }

    for (const Node& o : mset) {
      if (o.cnt < 3) return false;
    }

    return true;
  }
};
