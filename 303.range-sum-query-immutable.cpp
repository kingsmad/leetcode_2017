#include <bits/stdc++.h>
using namespace std;

inline int lowbit(int x) { return x & -x; }
struct BIT {
  vector<int> c;
  int n;

  void init(int tn) {
    n = tn;
    c.clear();
    c.resize(tn + 1);
  }

  void update(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) { c[i] += v; }
  }

  int query(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) { ans += c[i]; }
    return ans;
  }

  int query(int l, int r) { 
    if (l == 1) return query(r);
    return query(r) - query(l - 1); 
  }
} bit;

class NumArray {
 public:
  NumArray(vector<int> nums) {
    bit.init(nums.size()+1); 
    for (int i=0; i<nums.size(); ++i) {
      bit.update(i+1, nums[i]);
    }
  }

  int sumRange(int i, int j) {
    return bit.query(i+1, j+1);
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
