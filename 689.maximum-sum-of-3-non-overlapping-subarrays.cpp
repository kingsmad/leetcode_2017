#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = (ll)INT_MAX + 10;

class Solution {
 public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<ll> sum(n, 0);
    int st = 0, ed = 0;
    ll tot = 0;
    for (int i = 0; i + k <= n; ++i) {
      while (st < i) { tot -= nums.at(st++); }
      while (ed < n && ed < i + k) { tot += nums.at(ed++); }
      sum[i] = tot;
    }

    vector<int> mas1(n, -1);
    vector<int> mas2(n, -1);

    mas1[0] = 0;
    mas2[n - k] = n-k;
    for (int i = 1; i + k <= n; ++i) {
      if (sum[i] > sum[mas1[i - 1]]) {
        mas1[i] = i;
      } else {
        mas1[i] = mas1[i - 1];
      }
    }

    for (int i = n - k - 1; i >= 0; --i) {
      if (sum[i] > sum[mas2[i + 1]]) {
        mas2[i] = i;
      } else {
        mas2[i] = mas2[i + 1];
      }
    }

    ll res = -inf;
    vector<int> ans;
    for (int i = k; i + k + k <= n; ++i) {
      ll cur = max(res, sum[mas1.at(i - k)] + sum[mas2.at(i + k)] + sum[i]);
      if (cur > res) {
        res = cur;
        ans = {mas1.at(i - k), i, mas2.at(i + k)};
      }
    }

    return ans;
  }
};
