class Solution {
public:
  int Calc(vector<vector<int>>& grid, int r, int c) {
      int ans = 0;

      for (int i=0; i<grid.size(); ++i) {
        for (int j=0; j<grid.at(0).size(); ++j) {
          if (grid[i][j] == 1) {
            ans += abs(r - i);
            ans += abs(c - j);
          }
        }
      }
      return ans;
  }

    int minTotalDistance(vector<vector<int>>& grid) {
      if (grid.empty()) return 0;
      int x = 0, y = 0, cnt = 0;
      for (int i=0; i<grid.size(); ++i) {
        for (int j=0; j<grid.at(0).size(); ++j) {
          if (grid[i][j] == 1) {
            x += i;
            y += j;
            ++cnt;
          }
        }
      }

      int ans = 0;
      ans = 
      
      return ans;
    }

    
};
