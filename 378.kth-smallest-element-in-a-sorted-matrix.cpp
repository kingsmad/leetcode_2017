#include <queue>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int row = matrix.size(), col = matrix.at(0).size();

    multiset<int> mset;

    for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) {
      mset.insert(matrix[i][j]);
      if (mset.size() > k) {
        auto it = mset.end(); --it;
        mset.erase(it);
      }
    }

    auto it = mset.end(); --it;
    return *it;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  int row, col, k; scanf("%d%d%d", &row, &col, &k);
  vector<vector<int>> matrix(row, vector<int>(col, 0));
  for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) scanf("%d", &matrix[i][j]);
  
  Solution sol;
  int ans = sol.kthSmallest(matrix, k);

  printf("%d\n", ans);
  return 0;
}
#endif
