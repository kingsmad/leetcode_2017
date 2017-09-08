class Solution {
  const int xs[4] = { 0, 1, 0, -1};
  const int ys[4] = { 1, 0, -1, 0};
  vector<vector<int>> vis;
  int dt_ = 0;
 public:
  bool Check(vector<vector<int>>& mmp, int r, int c) {
    int row = mmp.size();  
    int col = mmp.at(0).size();
    for (int i=0; i<4; ++i) {
      if (r+xs[i]>=0 && r+xs[i]<row && c+ys[i]>=0 && c+ys[i]<col) {
        if (!vis[r+xs[i]][c+ys[i]]) return true;
      }
    }
    return false;
  }
  
  int NextPos(int* r, int* c) {
    for (int i=0; i<4; ++i) {
      dt_ = (dt_+i) % 4;
      if (*r+xs[dt_] < row && *r+xs[dt_]>=0 && *c+ys[dt_]>=0 && *c+ys[dt_]<col
          && !vis[*r+xs[dt_]][*c+ys[dt_]]) {
        *r += xs[dt_];
        *c += ys[dt_];
      }
    }
    return -1;
  }
  
  int trapRainWater(vector<vector<int>>& heightMap) {
    if (heightMap.empty()) return 0;
    int row = heightMap.size(); 
    int col = heightMap.at(0).size();
    vis = vector<vector<int>>(row, vector<int>(col, false));

    int x = 0, y = 0;
    int cnt = 2 * row + 2 * col - 4;
    while(cnt--) {
      
    }
    
  }
};
