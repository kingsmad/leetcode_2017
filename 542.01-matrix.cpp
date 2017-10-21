#include <queue>
#include <iostream>
#include <vector>

using namespace std;

const int rs[4] = { 0, 0, 1, -1};
const int cs[4] = { 1, -1, 0, 0};
const int inf = 1e9 + 7;

struct Node {
  int x, y;
  Node(int d1, int d2) : x(d1), y(d2) { }
};

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int r = matrix.size(), c = matrix.at(0).size();

    vector<vector<int>> ans(r, vector<int>(c, -1));

    queue<Node> mq;
    for (int i=0; i<r; ++i) for (int j=0; j<c; ++j) {
      ans[i][j] = inf;
      if (matrix[i][j] == 0) { mq.push(Node(i, j)); ans[i][j] = 0;}
    }

    while(!mq.empty()) {
      Node o = mq.front();
      mq.pop();

      for (int i=0; i<4; ++i) {
        int p = o.x + rs[i], q = o.y + cs[i];
        if (p < 0 || p >= r || q < 0 || q >= c) continue;
        if (ans[p][q] > ans[o.x][o.y] + 1) {
          mq.push(Node(p, q));
          ans[p][q] = ans[o.x][o.y] + 1;
        }
      }

    }

    return ans;
  }
};
