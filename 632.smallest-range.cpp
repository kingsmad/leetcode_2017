struct Board {
  // vector<int> cnt;
  unordered_map<int, int> mmp;
  int k;
  Board(int tk) : k(tk) {}
  inline void AddList(int pth) { ++mmp[pth]; }
  void Minus(const Board& rhs) {
    for (auto c : rhs.mmp) { mmp[c.first] -= c.second; }
  }

  void AddBoard(const Board& rhs) {
    for (auto c : rhs.mmp) { mmp[c.first] += c.second; }
  }

  bool IsFull() {
    for (int i = 0; i < k; ++i) {
      auto it = mmp.find(i);
      if (it == mmp.end() || it->second <= 0) return false;
    }
    return true;
  }
  bool IsEmpty() { return mmp.empty(); }
};

class Solution {
  const int kValSize = 2e5 + 1;
 public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    if (nums.empty()) return vector<int>();

    int k = nums.size();

    vector<Board> boards(kValSize, k);

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < nums.at(i).size(); ++j) {
        int v = nums[i][j] + 1e5;
        boards[v].AddList(i);
      }
    }

    vector<int> vals;
    for (int i = 0; i <= kValSize; ++i) {
      if (!boards[i].IsEmpty()) vals.push_back(i);
    }

    Board tmp(k);
    int p = 0, q = 0;
    int ap = 0, aq = vals.size() - 1;
    while (1) {
      if (q > vals.size()) break;
      if (tmp.IsFull()) {
        if (vals.at(aq) - vals.at(ap) > vals.at(q) - vals.at(p)) {
          ap = p, aq = q;
        }
        tmp.Minus(boards[p++]);
      } else {
        if (q == vals.size()) break;
        tmp.AddBoard(boards[q++]);
      }
    }

    return vector<int>({vals.at(ap), vals.at(aq)});
  }
};
