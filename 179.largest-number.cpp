#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> vs;
    for (int d : nums) {
      char s[100];
      sprintf(s, "%d", d);
      vs.push_back(string(s));
    }

    sort(vs.begin(), vs.end(), [](const string& s1, const string& s2) {
      string t1 = s1 + s2;
      string t2 = s2 + s1;
      return t1 > t2;
    });

    string ans = "";
    for (const string& s : vs) ans += s;

    int p = 0;
    while(p+1 < ans.size() && ans.at(p) == '0') ++p;
    return ans.substr(p, ans.size());
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  int n; scanf("%d", &n);
  vector<int> nums(n, -1);
  for (int i=0; i<n; ++i) scanf("%d", &nums[i]);

  Solution sol;
  string ans = sol.largestNumber(nums);
  cout << ans << endl;

  return 0;
}
#endif
