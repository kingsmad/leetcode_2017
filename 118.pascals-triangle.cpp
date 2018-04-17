#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    if (numRows == 0) return ans;

    vector<int> b = {1};
    ans.push_back(b);

    while(--numRows) {
      vector<int> tmp;
      tmp.push_back(1);
      for (int i=0; i+1<b.size(); ++i) tmp.push_back(b[i]+b[i+1]); 
      tmp.push_back(1);
      ans.emplace_back(tmp);
      b = tmp;
    }
    return ans;
  }
};
