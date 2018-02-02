#include <stack>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1e3 + 10;
int row, col;

class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix.at(0).empty()) return 0;
    row = matrix.size(), col = matrix.at(0).size();
    vector<vector<int>> umx(row, vector<int>(col, 0));

    for (int j=0; j<col; ++j) umx[row-1][j] = matrix[row-1][j] - '0';

    for (int i=row-2; i>=0; --i) {
      for (int j=0; j<col; ++j) {
        if (matrix[i][j] == '1') {
          umx[i][j] = umx[i+1][j] + 1;
        } else {
          umx[i][j] = 0;
        }
      }
    }

    int ans = 0;
    for (int i=0; i<row; ++i) ans = max(ans, largestRectangleArea(umx[i]));
    return ans;
  }

  int largestRectangleArea(vector<int>& nums) {
    stack<int> ms;
    int n = nums.size();

    vector<int> lans(n, 0);
    vector<int> rans(n, 0);

    for (int i = 0; i < n; ++i) {
      while (!ms.empty() && nums.at(ms.top()) >= nums.at(i)) { ms.pop(); }
      int v = 0;
      if (ms.size())
        v = (i - ms.top()) * nums.at(i);
      else
        v = (i + 1) * nums.at(i);

      lans[i] = v;
      ms.push(i);
    }

    ms = stack<int>();
    for (int i = n - 1; i >= 0; --i) {
      while (!ms.empty() && nums.at(ms.top()) >= nums.at(i)) { ms.pop(); }
      int v = 0;
      if (ms.size())
        v = (ms.top() - i) * nums.at(i);
      else
        v = (n - i) * nums.at(i);

      rans[i] = v;
      ms.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
      ans = max(ans, lans[i] + rans[i] - nums.at(i));

    return ans;
  }
};
