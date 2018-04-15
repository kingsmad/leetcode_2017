#include <bits/stdc++.h>
using namespace std;
int row, col;
using ll = long long;
class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    row = matrix.size(), col = matrix.at(0).size();
    ll l = min_element(matrix), r = max_element(matrix) + 1;
    while (l < r) {
      int md = floor((l + r) / 2.0);
      int cnt = calc(md, matrix);
      if (cnt <= k - 1)
        l = md + 1;
      else
        r = md;
    }
    return l - 1;
  }

  int min_element(const vector<vector<int>>& matrix) {
    int ans = INT_MAX;
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j) ans = min(ans, matrix[i][j]);
    return ans;
  }

  int max_element(const vector<vector<int>>& matrix) {
    int ans = INT_MIN;
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j) { ans = max(ans, matrix[i][j]); }
    return ans;
  }

  int calc(int x, const vector<vector<int>>& matrix) {
    int ans = 0;
    for (int i = 0; i < row; ++i) {
      int p = lower_bound(matrix[i].begin(), matrix[i].end(), x)
              - matrix[i].begin();
      ans += p;
    }
    return ans;
  }
};
#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  int row, col, k;
  scanf("%d%d%d", &row, &col, &k);
  vector<vector<int>> matrix(row, vector<int>(col, 0));
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) scanf("%d", &matrix[i][j]);

  Solution sol;
  int ans = sol.kthSmallest(matrix, k);

  printf("%d\n", ans);
  return 0;
}
#endif
