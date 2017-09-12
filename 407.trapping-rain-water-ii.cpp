#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;
class Solution {
  const int xs[4] = { 0, 1, 0, -1 };
  const int ys[4] = { 1, 0, -1, 0 };
  vector<vector<bool> > vis;
  vector<vector<bool> > del;
  int ans_ = 0;
  int row_, col_;

 public:
  bool Next(int r, int c, int *tx, int *ty) {
    for (int i = 0; i < 4; ++i) {
      if (r + xs[i] >= 0 && r + xs[i] < row_ && c + ys[i] >= 0 &&
          c + ys[i] < col_ && !vis[r+xs[i]][c+ys[i]]) {
          *tx = r + xs[i];
          *ty = c + ys[i];
          return true;
      }
    }
    return false;
  }

  bool check(int r, int c) {
    for (int i = 0; i < 4; ++i) {
      if (r + xs[i] >= 0 && r + xs[i] < row_ && c + ys[i] >= 0 &&
          c + ys[i] < col_) {
        if (!vis[r + xs[i]][c + ys[i]]) {
          return true;
        }
      }
    }

    return false;
  }

  int trapRainWater(vector<vector<int> > &heightMap) {
    if (heightMap.empty()) return 0;
    row_ = heightMap.size();
    col_ = heightMap.at(0).size();
    vis = vector<vector<bool> >(row_, vector<bool>(col_, false));
    del = vector<vector<bool> >(row_, vector<bool>(col_, false));
    ans_ = 0;
    auto fn = [&](const pair<int, int> &p1, const pair<int, int> &p2) {
      return heightMap[p1.first][p1.second] > heightMap[p2.first][p2.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(fn)> pq(fn);

    queue<pair<int, int> > mq;
    for (int i = 0; i < col_; ++i) {
      pq.emplace(0, i);
      pq.emplace(row_ - 1, i);
      mq.emplace(0, i);
      mq.emplace(row_ - 1, i);
      vis[0][i] = vis[row_-1][i] = true;
    }
    for (int i = 0; i < row_; ++i) {
      pq.emplace(i, 0);
      pq.emplace(i, col_ - 1);
      mq.emplace(i, 0);
      mq.emplace(i, col_ - 1);
      vis[i][0] = vis[i][col_-1] = true;
    }


    while (!mq.empty()) {
      auto c = mq.front();
      mq.pop();
      int x = c.first, y = c.second, tx = -1, ty = -1;

      int mi = 0;
      while(!pq.empty()) {
        auto c = pq.top();
        if (del[c.first][c.second]) pq.pop();
        else { mi = heightMap[c.first][c.second];}
      }

      while (Next(x, y, &tx, &ty)) {
        printf("mi is %d\n", mi);
        if (heightMap[tx][ty] < mi) {
          ans_ += mi - heightMap[tx][ty];
          printf("calculating %d %d, ans_ plus %d\n", tx, ty, mi - heightMap[tx][ty]);
          heightMap[tx][ty] = mi;
        }

        vis[tx][ty] = true;
        mq.push(make_pair(tx, ty));
        pq.push(make_pair(tx, ty));
        printf("inserted %d %d\n", tx, ty);
      }

      del[x][y] = 1;
    }

    return ans_;
  }
};

int main(int argc, char **argv) {
  freopen("in.txt", "r", stdin);
  int row, col;
  scanf("%d%d", &row, &col);
  vector<vector<int> > board(row, vector<int>(col, 0));
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) scanf("%d", &board[i][j]);

  Solution sol;
  int ans = sol.trapRainWater(board);

  printf("%d\n", ans);
  return 0;
}
