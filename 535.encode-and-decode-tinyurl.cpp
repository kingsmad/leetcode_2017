#include <bits/stdc++.h>
using namespace std;
const string mytemp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
const int maxn = 10;
class Solution {
  map<string, string> smp;
  map<string, string> rsmp;
 public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    if (smp.count(longUrl) > 0) return smp.at(longUrl);
    string tmp;
    while(1) {
      tmp = RandomString();
      if (smp.count(tmp) == 0) break;
    }
    smp[longUrl] = tmp;
    rsmp[tmp] = longUrl;
    return tmp;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    return rsmp.at(shortUrl);
  }
  
  string RandomString() {
    int len = mytemp.size(); 
    string ans;
    for (int i=0; i<maxn; ++i) {
      int d = random() % len;
      ans.push_back(mytemp.at(d));
    }
    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  Solution sol;
  string url = "https://leetcode.com/problems/design-tinyurl";
  assert(url == sol.decode(sol.encode(url)));
}
#endif

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
