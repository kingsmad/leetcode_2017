#include <vector>
#include <string>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
 public:
   int Dis(vector<int>& v1, vector<int>& v2) {
     return abs(v1.at(0) - v2.at(0)) + abs(v1.at(1) - v2.at(1));
   }

  int minDistance(int height, int width, vector<int>& tree,
                  vector<int>& squirrel, vector<vector<int>>& nuts) {
    int sum = 0;
    for (int i=0; i<nuts.size(); ++i) {
      sum += 2 * Dis(tree, nuts.at(i));
    }

    int ans = INT_MAX;
    for (vector<int>& v : nuts) {
      int t = sum - Dis(v, tree) + Dis(squirrel, v);  
      ans = min(ans, t);
    }

    return ans;
  }
};
