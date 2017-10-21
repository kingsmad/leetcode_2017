#include <vector>
using namespace std;

class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int state = 0, ans = 0;
    int cnt[2] = { 0, 0 };
    
    for (int d : nums) {
      switch(state) {
        case 0:
          if (d == 1) ans = max(ans, ++cnt[0]);
          else { state = 1; ans = max(ans, cnt[0] + 1); }
          break;
        case 1:
          if (d == 1) ans = max(ans, cnt[0] + (++cnt[1]) + 1);
          else {
            ans = max(ans, cnt[0] + cnt[1] + 1); 
            cnt[0] = cnt[1];
            cnt[1] = 0;
            state = 1;
          }
          break;
        default:
          break;
      }
    }

    return ans;
  }
};
