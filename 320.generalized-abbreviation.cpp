#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<string> generateAbbreviations(string word) {
    vector<string> ans;
    int n = word.size();
    vector<int> a(n, 0);
    int cnt = pow(2, n);

    while(cnt--) {
      Add(a);
      ans.push_back(Parse(a, word));
    }

    return ans;
  }

  void Add(vector<int>& v) {
    int carry = 1, n = v.size();
    int p = v.size() - 1;

    while(p >= 0) {
      v[p] += carry;
      if (v[p] == 2) {
        v[p] = 0;
        carry = 1;
        --p;
      } else break;
    }
  }

  string Parse(const vector<int>& v, const string& word) {
    string ans = "";
    int n = v.size();
    for (int i=0; i<n; ) {
      if (v.at(i) == 1) {
        int q = i + 1;
        while(q < n && v.at(q) == 1) ++q;
        ans = ans + to_string(q - i);
        i = q;
      } else {
        while(i < n && v.at(i) == 0) {
          ans.push_back(word.at(i++));
        }
      }
    }

    return ans;
  }
};
