struct Board {
  vector<int> cnt;
  int k;
  Board(int tk) : k(tk) { cnt = vector<int>(tk, 0); }
  inline void AddList(int pth) { ++cnt[pth]; }
  void Minus(const Board& rhs) {
    for (int i = 0; i < k; ++i) { cnt[i] -= rhs.cnt[i]; }
  }

  void AddBoard(const Board& rhs) {
    for (int i = 0; i < k; ++i) { cnt[i] += rhs.cnt[i]; }
  }

  bool IsFull() {
    for (int i = 0; i < k; ++i)
      if (!cnt[i]) return false;
    return true;
  }
};

class Solution {
  const int kValSize = 211;

 public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    if (nums.empty()) return vector<int>();

    int k = nums.size();

    vector<Board> boards(kValSize, k);

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < nums.at(i).size(); ++j) {
        int v = nums[i][j] + 105;
        boards[v].AddList(i);
      }
    }

    Board tmp(k);
    int p = 0, q = 0;
    int ap = 0, aq = kValSize;
    while (1) {
      if (q > kValSize) break;
      if (tmp.IsFull()) {
        if (aq - ap > q - p) { ap = p, aq = q; }
        tmp.Minus(boards[p++]);
      } else {
        if (q == kValSize) break;
        tmp.AddBoard(boards[q++]);
      }
    }

    return vector<int>({ap-105, aq-106});
  }
};
