#include <map>
#include <vector>
#include <string>

using namespace std;

const int maxn = 1e5 + 10;

struct State {
  int st, ed, f1, f2;
  State(int d1, int d2, int d3, int d4) : st(d1), ed(d2), f1(d3), f2(d4) { }
  bool operator<(const State& rhs) const {
    if (st != rhs.st) return st < rhs.st;
    if (ed != rhs.ed) return ed < rhs.ed;
    if (f1 != rhs.f1) return f1 < rhs.f1;
    return f2 < rhs.f2;
  }
};

map<State, int> smp;

class Solution {
 public:
  int rob(vector<int>& nums) {
    smp.clear();
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums.front();
    int v = max(Calc(0, n-1, 0, 1, nums), Calc(0, n-1, 1, 0, nums));
    v = max(v, Calc(0, n-1, 0, 0, nums));
    return v;
  }

  int Calc(int st, int ed, int f1, int f2, const vector<int>& nums) {
    if (st > ed) return 0;
    if (st == ed) {
      if (f1 != f2) return 0;
      if (!f1) return 0;
      return nums.at(st);
    } else if (st + 1 == ed) {
      if (f1 && f2) return 0;
      if (f1) return nums.at(st);
      else if (f2) return nums.at(ed);
      return 0;
    }

    if (smp.count((State){st, ed, f1, f2}) > 0) {
      return smp.at((State){st, ed, f1, f2});
    }

    int v = 0;

    if (f1 == 0 && f2 == 1) {
      v = max(Calc(st+1, ed-1, 1, 0, nums), Calc(st+1, ed-1, 0, 0, nums)) + nums.at(ed); 
    } else if (f1 == 1 && f2 == 0) {
      v = max(Calc(st+1, ed-1, 0, 1, nums), + Calc(st+1, ed-1, 0, 0, nums)) + nums.at(st);
    } else if (f1 == 0 && f2 == 0) {
      for (int i=0; i<2; ++i) for (int j=0; j<2; ++j) {
        v = max(v, Calc(st+1, ed-1, i, j, nums));
      }
    } else {
      v = max(v, Calc(st+1, ed-1, 0, 0, nums) + nums.at(st) + nums.at(ed));
    }

    return smp[State(st, ed, f1, f2)] = v;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  Solution sol; 
  int n; scanf("%d", &n);
  vector<int> ans;
  for (int i=0; i<n; ++i) { int d; scanf("%d", &d); ans.push_back(d); }
  int rs = sol.rob(ans);
  return 0 * printf("%d\n", rs);
}
#endif
