#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <climits>

using namespace std;
using ll = long long;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int neg_cnt = 0;
    for (int d : nums) if (d < 0) ++neg_cnt;
    bool neg = (neg_cnt % 3 == 0) ? false : true;

    vector<int> ans, tmp;
    for (int d : nums) {
      Convert(d, tmp); 
      Xor(ans, tmp);
    }

    int rs = Convert(ans);
    return neg ? -rs : rs;
  }

  void Convert(ll x, vector<int>& s) {
    s.clear();
    x = (x < 0) ? -x : x;
    while( x > 0) {
      ll v = x % 3;
      x = x / 3;
      s.push_back(v);
    }
    return;
  }

  void Xor(vector<int>& s1, vector<int>& s2) {
    int n = max(s1.size(), s2.size()); 
    s1.resize(n, 0);
    s2.resize(n, 0);
    for (int i=0; i<n; ++i) {
      s1[i] = (s1[i] + s2[i]) % 3;
    }
  }

  ll Convert(const vector<int>& v) {
    ll ans = 0, pw = 1;
    for (int d : v) {
      ans += d * pw;
      pw = pw * 3;
    }
    return ans;
  }

};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  Solution sol;
  int n; scanf("%d", &n);
  vector<int> ans;
  for (int i=0; i<n; ++i) { int d; scanf("%d", &d); ans.push_back(d);}

  int rs = sol.singleNumber(ans);
  return 0 * printf("%d\n", rs);
}
#endif
