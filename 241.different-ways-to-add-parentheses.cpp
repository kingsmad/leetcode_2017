#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;
map<pair<int, int>, vector<int>> ms;

class Solution {
 public:
  vector<int> diffWaysToCompute(string input) {
    ms.clear();
    int n = input.size();
    return Calc(0, n, input);
  }

  vector<int> Calc(int st, int ed, const string& s) {
    if (ms.count(make_pair(st, ed))) return ms.at(make_pair(st, ed)); 
    vector<int> vans;
    if (st == ed) return vans;
    
    vector<int> ans;
    bool pure_number = true;
    for (int i=st; i<ed; ++i) {
      if (!isdigit(s.at(i))) {
        pure_number = false;
        vector<int> v1 = Calc(st, i, s);
        vector<int> v2 = Calc(i+1, ed, s);
        if (s.at(i) == '+') {
          for (int d1 : v1) for (int d2 : v2) ans.push_back(d1 + d2);
        }
        if (s.at(i) == '-') {
          for (int d1 : v1) for (int d2 : v2) ans.push_back(d1 - d2);
        }
        if (s.at(i) == '*') {
          for (int d1 : v1) for (int d2 : v2) ans.push_back(d1 * d2);
        }
      }
    }

    if (pure_number) {
      int x = 0;
      for (int i=st; i<ed; ++i) x = x * 10 + s.at(i) - '0';
      ans.push_back(x);
    }

    ms.emplace(make_pair(st, ed), ans);

    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  Solution sol;
  string str; cin >> str;
  vector<int> ans = sol.diffWaysToCompute(str);
  for (int d : ans) cout << d << " ";
  cout << endl;
}
#endif
