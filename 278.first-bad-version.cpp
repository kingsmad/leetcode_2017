// Forward declaration of isBadVersion API.
bool isBadVersion(int version);
using ll = long long;

class Solution {
public:
  int firstBadVersion(int n) {
    if (isBadVersion(1)) return 1;
    ll l = 1, r = n;
    while(l < r) {
      ll md = (l+r) / 2;
      if (isBadVersion(md)) r = md;
      else l = md + 1;
    }
    return l;
  }
};
