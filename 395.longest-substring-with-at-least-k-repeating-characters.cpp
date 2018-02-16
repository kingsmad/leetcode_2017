#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int longestSubstring(string s, int k) {
    if (s == "") return 0;
    vector<int> cnt(26, 0);
    for (char c : s) ++cnt[c - 'a'];

    set<int> nums;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] < k && cnt[i] > 0) nums.insert(i);
    }

    if (nums.empty()) return s.size();

    int pre = -1, n = s.size();
    int ans = 0;
    for (int i=0; i<n; ++i) {
      if (nums.count(s[i]-'a') > 0) {
        ans = max(ans, longestSubstring(s.substr(pre+1, i-pre-1), k));
        pre = i;
      }
    }
    ans = max(ans, longestSubstring(s.substr(pre+1, n-pre-1), k));
    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  freopen("in.txt", "r", stdin);
  string str; int n;
  cin >> str >> n;
  Solution sol;
  int ans = sol.longestSubstring(str, n);
  cout << ans << endl;
  return 0;
}
#endif
