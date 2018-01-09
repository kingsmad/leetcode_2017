#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

class Solution {
 public:
  int shortestDistance(vector<string>& words, string word1, string word2) {
    int n = words.size();
    vector<int> buf;
    for (int i=0; i<n; ++i) if (word1 == words.at(i) || word2 == words.at(i))
      buf.push_back(i);

    int ans = n + 1;
    for (int i=0; i+1<buf.size(); ++i) {
      int p = buf.at(i), q = buf.at(i+1);
      if (words.at(p) != words.at(q)) ans = min(ans, q - p);
    }
    return ans;
  }
};
