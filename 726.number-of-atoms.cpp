#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string countOfAtoms(string formula) {
    map<string, int> ms;
    istringstream ss(formula);
    dfs(ss, ms);

    string ans;
    for (auto& pr : ms) {
      ans += pr.first;
      if (pr.second > 1) ans += to_string(pr.second);
    }
    return ans;
  }

  void dfs(istringstream& ss, map<string, int>& oms) {
    map<string, int> cms;
    while (ss.peek() != EOF) {
      if (isupper(ss.peek())) {
        string buf;    
        buf.push_back(ss.get());
        while(islower(ss.peek())) {
          buf.push_back(ss.get());
        }
        int d;
        if (ss >> d) cms[buf] += d;
        else { ss.clear(); cms[buf] += 1;}
        continue;
      }
      if (ss.peek() == '(') {
        ss.get();
        dfs(ss, cms);
        continue;
      }
      if (ss.peek() == ')') {
        ss.get();
        int d;
        if (ss >> d) {
          for (auto& pr : cms) pr.second *= d;
        } else {
          ss.clear();
        }
        break;
      }
    }
    for (auto pr : cms) {
      const string str = pr.first;
      int v = pr.second;
      oms[str] += v;
    }
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  //string str; cin >> str;
  string str = "K4(ON(SO3)2)2";
  Solution sol;
  const string ans = sol.countOfAtoms(str);
  cout << ans << endl;
}
#endif
