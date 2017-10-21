#include <map>
#include <vector>
using namespace std;
using ll = long long;

class Solution {
 public:
  int leastBricks(vector<vector<int>>& wall) {
    map<int, int> smp;
    for (int i=0; i<wall.size(); ++i) {
      int sum = 0;
      for (int j=0; j+1<wall.at(i).size(); ++j) {
        sum += wall[i][j];
        ++smp[sum];
      } 
    }

    int ans = 0;
    for (auto it=smp.begin(); it!=smp.end(); ++it) ans = max(ans, it->second);
    return wall.size() - ans;
  }
};
