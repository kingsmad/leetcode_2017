#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
  set<char> digits;
 public:
  void Next(string& tm) {
    int h, m;
    sscanf(tm.c_str(), "%d:%d", &h, &m);
    m = (++m) % 60;
    if (m == 0) ++h;
    h = h % 24;

    char b[20];
    sprintf(b, "%02d:%02d", h, m);
    tm = string(b);
  }

  bool IsLegal(const string& tm) {
    for (char c : tm) if (c != ':' && digits.count(c) == 0) return false;
    return true;
  }

  string nextClosestTime(string time) {
    digits.clear();
    for (char c : time) if (isdigit(c)) digits.insert(c);
    
    while(1) {
      Next(time);
      if (IsLegal(time)) break;
    }

    return time;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  string str; cin >> str;
  Solution sol;
  cout << sol.nextClosestTime(str) << endl;
}
#endif
