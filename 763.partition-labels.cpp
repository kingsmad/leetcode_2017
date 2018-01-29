#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string S) {
    int n = S.size();
    vector<int> vlast(26, -1);
    for (int i=n-1; i>=0; --i) {
      int x = S.at(i) - 'a';
      if (vlast[x] == -1) vlast[x] = i;
    }

    vector<int> ans;
    for (int i=0; i<n; ) {
      int q = i + 1;
      for (int j=i; j<q; ++j) {
        int x = S.at(j) - 'a';
        q = max(q, vlast[x]+1);
      }
      ans.push_back(q - i);
      i = q;
    }

    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char **argv) {
  Solution sol;
  string str;
  cin >> str;
  vector<int> ans = sol.partitionLabels(str);
  for (int d : ans) { cout << d << " "; }

  return 0 * printf("\n");
}
#endif
