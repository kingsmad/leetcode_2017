#include <cstring>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
const int maxn = 40;
ll sum[maxn];

class Solution {
 public:
  bool PredictTheWinner(vector<int>& nums) {

    memset(sum, 0, sizeof(sum));
    sum[0] = nums.at(0);
    for (int i=1; i<nums.size(); ++i) {
      sum[i] = sum[i-1] + nums.at(i);  
    }

    ll fans = Calc(0, nums.size()-1, nums);
    return fans >= sum[nums.size()-1] - fans;
  }

  ll Calc(int st, int ed, const vector<int>& nums) {
    if (st == ed) return nums.at(st); 

    ll sm = 0;
    if (st == 0) sm = sum[ed];
    else sm = sum[ed] - sum[st-1];

    ll ans = max(sm - Calc(st+1, ed, nums) + nums.at(st), 
                 sm - Calc(st, ed-1, nums) + nums.at(ed));
    return ans;
  }
};
