class Solution {
  using ll = long long ;
public:
    int findKthNumber(int m, int n, int k) {
      if (m > n) swap(m, n);
      auto count = [m, n, k](int x) {
        ll ans = 0;
        for (int i=1; i<=m; ++i) {
          ans += min(n, x/i);
        }
        return ans;
      };

      ll l = 1, r = INT_MAX;
      while(l < r) {
        int md = (l+r) / 2;
        if (count(md) < k) l = md + 1;
        else r = md;
      }
      return l;
    }
};
