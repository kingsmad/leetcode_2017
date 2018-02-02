#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isScramble(string s1, string s2) {
    int n = s2.size();
    return isScramble(0, n, 0, n, s1, s2);
  }

  bool isScramble(int st1, int ed1, int st2, int ed2, const string& s1,
                  const string& s2) {
    if (!check(st1, ed1, st2, ed2, s1, s2)) return false;
    if (ed1 - st1 <= 2) return true;
    for (int i = 1; i < ed1 - st1; ++i) {
      if (isScramble(st1, st1 + i, st2, st2 + i, s1, s2)
          && isScramble(st1 + i, ed1, st2 + i, ed2, s1, s2))
        return true;
      if (isScramble(st1, st1 + i, ed2 - i, ed2, s1, s2)
          && isScramble(st1 + i, ed1, st2, ed2-i, s1, s2))
        return true;
    }
    return false;
  }

  bool check(int st1, int ed1, int st2, int ed2, const string& s1,
             const string& s2) {
    vector<int> b(26, 0);
    for (int i = st1; i < ed1; ++i) ++b[s1[i] - 'a'];
    for (int i = st2; i < ed2; ++i)
      if (--b[s2[i] - 'a'] < 0) return false;
    for (int i = 0; i < 26; ++i)
      if (b[i] != 0) return false;
    return true;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  string s1, s2;
  cin >> s1 >> s2;
  Solution sol;
  bool ans = sol.isScramble(s1, s2);

  if (ans)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
#endif
