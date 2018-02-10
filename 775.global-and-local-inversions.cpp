#include <bits/stdc++.h>

using namespace std;
inline int lowbit(int x) { return x & (-x);}
const int maxn = 5e3 + 10;

struct BIT {
  int n, c[maxn];
  void init(int tn) {
    memset(c, 0, sizeof(c));
    n = tn+1; 
  }

  void update(int x, int v) {
    for (int i=x; i<=n; i+=lowbit(i)) {
      c[i] += v;
    }
  }

  int query(int x) {
    int ans = 0;
    for (int i=x; i>0; i-=lowbit(i)) ans += c[i];
    return ans;
  }
} bit;


class Solution {
 public:
  bool isIdealPermutation(vector<int>& A) {
    return calc(A) == calc_local(A);
  }

  int calc(const vector<int>& nums) {
    bit.init(nums.size());
    int ans = 0;
    for (int i=nums.size()-1; i>=0; --i) {
      int d = nums[i];
      ans += bit.query(d);
      bit.update(d+1, 1);
    }
    return ans;
  }

  int calc_local(const vector<int>& nums) {
    int ans = 0;
    for (int i=0; i+1<nums.size(); ++i) {
      if (nums[i] > nums[i+1]) ++ans;
    }
    return ans;
  }
};
