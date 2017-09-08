class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
      if (grid.empty()) return 0;
      vector<int> v1, v2;     
      for (int i=0; i<grid.size(); ++i) {
        for (int j=0; j<grid.at(0).size(); ++j) {
          if (grid[i][j] != 1) continue;
          v1.push_back(i);
          v2.push_back(j);
        }
      }

      sort(v1.begin(), v1.end());
      sort(v2.begin(), v2.end());
      

      int ans = 0;
      int x = v1.at(v1.size()/2), y = v2.at(v2.size()/2);

      for (int i=0; i<grid.size(); ++i) {
        for (int j=0; j<grid.at(0).size(); ++j) {
          if (grid[i][j] == 1) {
            ans += abs(i - x);
            ans += abs(j - y);
          }
        }
      }

      return ans;
      
    }

};
