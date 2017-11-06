#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution {
 public:
  bool isValidSerialization(string preorder) {

    string str = Parse(preorder);

    vector<int> mv;
    for (char c : str) {
      mv.push_back(c);
      while (mv.size() >= 3 && mv.back() == mv.at(mv.size()-2) \
             && mv.back() == '#') {
        mv.pop_back();
        mv.pop_back();

        if (mv.back() == '#') return false;

        mv.pop_back();
        mv.push_back('#');
      }
    }

    return mv.size() == 1 && mv.at(0) == '#';
  }

  string Parse(const string& preorder) {
    string str = "";
    int n = preorder.size();
    for (int i=0; i<n; ) {
      while(i < n && preorder.at(i) == ',') ++i;
      if (i == n) break;
      int q = i + 1;
      while(q < n && preorder.at(q) != ',') ++q;

      str.push_back(preorder.at(i));
      i = q; 
    }
    return str;
  }
};

#ifdef ROACH_ONLINE_JUDGE

int main(int argc, char** argv) {
  string s; cin >> s;
  Solution sol;
  bool ok = sol.isValidSerialization(s);
  if (ok) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}

#endif
