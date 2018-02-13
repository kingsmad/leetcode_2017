#include <bits/stdc++.h>

using namespace std;

struct Item {
  int lev;
  string str;
};

class Solution {
 public:
  int lengthLongestPath(string input) {
    vector<Item> path;
    int acnt = 0;
    int tsz = 0;
    std::istringstream ss(input);
    
    string line = "";
    while(std::getline(ss, line)) {
      cout << "line is: " <<  line << endl;
      int tcnt = line.find_last_of('\t') + 1;
      while(path.size() && path.back().lev >= tcnt) {
        Item t = path.back();
        path.pop_back();
        tsz -= t.str.size();
        if (path.size()) --tsz;
      }

      Item t; t.lev = tcnt;
      t.str = line.substr(tcnt, line.size());
      if (path.size()) ++tsz;
      tsz += line.size() - tcnt;
      path.emplace_back(t);

      if (IsFile(line)) acnt = max(tsz, acnt);
    }

    return acnt;
  }

  bool IsFile(const string& s) {
    return s.find_last_of('.') != string::npos;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int ,char**) {
  Solution sol;
  //string str = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
  string str = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";

  int ans = sol.lengthLongestPath(str);
  printf("%d\n", ans);
  return 0;
}
#endif
