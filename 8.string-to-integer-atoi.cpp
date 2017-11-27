#include <climits>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

class Solution {
 public:
  int myAtoi(string str) {
    if (str.size() == 0) return 0;
    int n = str.size();
    int st = 0; while(st < n && str.at(st) == ' ') ++st; 
    if (st == n) return 0;

    bool neg = str.at(st) == '-';
    if (str.at(st) == '+' || str.at(st) == '-') ++st;
    if (st == n) return 0;

    if (!isdigit(str.at(st))) return 0;

    ll ans = 0;
    for (int i=st; i<n; ++i) {
      if (!isdigit(str.at(i))) break;
      ans = ans * 10 + str.at(i) - '0'; 

      ll t = neg ? -ans : ans;
      if (t >= INT_MAX) return INT_MAX;
      if (t <= INT_MIN) return INT_MIN;
    }

    ans = neg ? -ans : ans;
    return static_cast<int>(ans);
  }
};
