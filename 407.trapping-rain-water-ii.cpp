class Solution {
  const int xs[4] = { 0, 1, 0, -1 };
  const int ys[4] = { 1, 0, -1, 0 };
  static vector<vector<int>> * board_;
  vector<vector<int> > inq;
  int dt_ = 0;
  int ans_ = 0;
  int row_, col_;

  struct Cmp {
    bool operator()(pair<int, int> &p1, pair<int, int> &p2) const {
      return board_[p1.first][p1.second] < board_[p2.first][p2.second];
    }
  };

 public:
  bool Check(int r, int c) {
    for (int i = 0; i < 4; ++i) {
      if (r + xs[i] >= 0 && r + xs[i] < row_ && c + ys[i] >= 0 &&
          c + ys[i] < col_) {
        if (!inq[r + xs[i]][c + ys[i]]) {
          return true;
        }
      }
    }
    return false;
  }

  int trapRainWater(vector<vector<int> > &heightMap) {
    if (heightMap.empty()) return 0;
    board_ = &heightMap;
    row_ = heightMap.size();
    col_ = heightMap.at(0).size();
    inq = vector<vector<int> >(row_, vector<int>(col_, false));
    set<pair<int, int>, Cmp > ms1, ms2;

    for (int i = 0; i < col_; ++i) {
      ms1.emplace(0, i);
      ms1.emplace(row_ - 1, i);
    }
    for (int i = 0; i < row_; ++i) {
      ms1.emplace(i, 0);
      ms1.emplace(i, col_ - 1);
    }
    for (auto c : ms1) {
      inq[c.first][c.second] = true;
    }

    vector<pair<int, int> > tbr;

    while (!ms1.empty()) {
      // get nxt
      ms2.clear();
      tbr.clear();
      for (auto c : ms1) {
        int x = c.first, y = c.second;
        bool ok = false;
        int i = 0;
        for (; i < 4; ++i) {
          if (Check(x + xs[i], y + ys[i])) {
            inq[x][y] = true;
            ok = true;
            break;
          }
        }

        if (!ok) {
          tbr.emplace_back(x, y);
        } else {
          ms2.emplace(x + xs[i], y + ys[i]);
        }
      }

      // process
      auto pr = *ms1.begin();
      int mi = (*board_)[pr.first][pr.second];
      for (auto c : ms2) {
        int x = c.first, y = c.second;
        if (mi < (*board_)[x][y]) {
          ans_ += (*board_)[x][y] - mi;
        }
      }

      // clean up
      for (auto c : tbr) ms1.erase(c);
      for (auto c : ms2) ms1.emplace(c);
    }

    return ans_;
  }
};
