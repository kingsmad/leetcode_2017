#include <algorithm>
#include <iostream>
#include <vector>
// Mark

using namespace std;

class Solution {
 public:
  bool isAdditiveNumber(string num) {
    int n = num.size();

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        if (Check(i, j, num)) return true;
      }

    return false;
  }

  string Add(const string s1, const string s2) {
    vector<int> v1;
    for (int i = s1.size() - 1; i >= 0; --i) { v1.push_back(s1.at(i) - '0'); }

    vector<int> v2;
    for (int i = s2.size() - 1; i >= 0; --i) { v2.push_back(s2.at(i) - '0'); }

    vector<int> ans;
    int carry = 0;
    int p = 0, q = 0, n1 = s1.size(), n2 = s2.size();

    while (p < n1 || q < n2 || carry) {
      int d = 0;
      if (p < n1) d += v1.at(p++);
      if (q < n2) d += v2.at(q++);
      if (carry) {
        d += carry;
        carry = 0;
      }

      if (d >= 10) {
        d -= 10;
        carry = 1;
      }

      ans.push_back(d);
    }

    string str;
    for (int i = ans.size() - 1; i >= 0; --i) {
      str.push_back(ans.at(i) + '0');
    }

#ifdef ROACH_ONLINE_JUDGE
    cout << s1 << " + " << s2 << " = " << str << endl;
#endif
    return str;
  }

  bool Check(int p, int q, const string& num) {
    int st1 = 0, ed1 = p, st2 = p, ed2 = q, st3 = q;
    int n = num.size();

    while (st3 < n) {
      if (ed1 > st1 + 1 && num.at(st1) == '0') return false;
      if (ed2 > st2 + 1 && num.at(st2) == '0') return false;

      const string s =
          Add(num.substr(st1, ed1 - st1), num.substr(st2, ed2 - st2));
      if (s == num.substr(st3, s.size())) {
        if (s.size() > 1 && s.at(0) == '0') return false;
        st1 = st2, ed1 = ed2;
        st2 = st3, ed2 = st2 + s.size();
        st3 = ed2;
      } else
        return false;
    }

    return true;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  string str;
  cin >> str;
  Solution sol;

  bool ok = sol.isAdditiveNumber(str);
  if (ok)
    printf("OK\n");
  else
    printf("NO\n");

  return 0;
}
#endif
