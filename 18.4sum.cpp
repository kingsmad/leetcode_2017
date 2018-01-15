#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

const ll h1 = 19260817;
const ll h2 = 19660813;

ll khash(const vector<int>& v) {
  return h1 * v[0] + h2 * v[1] + 19 * v[2] + 7 * v[3];
}

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> ms;
    for (int i=0; i<n; ++i) {
      for (int j=i+1; j<n; ++j) {
        int tv = target - nums.at(i) - nums.at(j);
        int p = j+1, q = n-1;
        while(p < q) {
          int cv = nums.at(p) + nums.at(q);
          if (cv == tv) {
            ms.insert({nums[i], nums[j], nums[p], nums[q]});
            ++p;
          } else if (cv < tv) {
            ++p;
          } else {
            --q;
          }
        }
      }
    }

    return vector<vector<int>> (ms.begin(), ms.end());
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  int n, target; scanf("%d%d", &n, &target);
  vector<int> nums;
  for (int i=0; i<n; ++i) { int d; scanf("%d", &d); nums.push_back(d);}

  Solution sol;
  vector<vector<int>> ans = sol.fourSum(nums, target);
  for (const vector<int>& v: ans) {
    for (int d: v) printf("%d ", d);
    printf("\n");
  }
  return 0;
}
#endif
