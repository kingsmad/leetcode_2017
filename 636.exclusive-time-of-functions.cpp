// KINGSMAD MARK
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  bool Parse(const string& str, int* time, int* sid) {
    bool is_start = (str.find("start") < str.size());
    if (is_start) {
      sscanf(str.c_str(), "%d:start:%d", sid, time);
    } else {
      sscanf(str.c_str(), "%d:end:%d", sid, time);
    }
    return is_start;
  }

  vector<int> exclusiveTime(int n, vector<string>& logs) {
    map<int, int> smp;
    for (int i=0; i<n; ++i) smp.emplace(i, 0);

    stack<int> mstack;
    int ptm = 0;

    for (const string& s : logs) {
      int psid = (mstack.empty()) ? -1 : mstack.top();
      int tm, sid;
      bool is_start = Parse(s, &tm, &sid);
      if (psid != -1) smp[psid] += tm - ptm + !is_start;
      if (is_start) mstack.push(sid);
      else mstack.pop();

      ptm = tm + !is_start;
    }

    vector<int> ans;
    for (int i=0; i<n; ++i) ans.push_back(smp.at(i));
    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  int n, m; scanf("%d%d", &n, &m);
  vector<string> logs;
  for (int i=0; i<n; ++i) {
    string str; cin >> str;
    logs.push_back(str); 
  }

  Solution sol;
  vector<int> ans = sol.exclusiveTime(m, logs);
  for (int i=0; i<ans.size(); ++i) printf("%d ", ans.at(i));
  printf("\n");
  return 0;
}
#endif
