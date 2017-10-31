#include <string>

using namespace std;

class Solution {
 public:
  string validIPAddress(string IP) {
    if (ValidIpv6(IP)) return "IPv6";
    if (ValidIpv4(IP)) return "IPv4";
    return "Neither";
  }

  inline bool IsLow(char c) { return c >= 'a' && c <= 'f';}
  inline bool IsUp(char c) { return c >= 'A' && c <= 'F';}

  bool ValidIpv6(const string& ip) {
    int n = ip.size(), cnt = 0;
    for (char c : ip) if (c == ':') ++cnt;
    if (cnt != 7) return false;

    for (int i=0; i<n; ) {
      if(i < n && ip.at(i) == ':') ++i;
      if (i == n) break;
      if (ip.at(i) == ':') return false;
      int q = i + 1;
      while(q < n && ip.at(q) != ':') ++q;
      if (q - i > 4 ) return false;

      for (int j=i; j<q; ++j) {
        char c = ip.at(j);
        if (!isdigit(c) && !IsLow(c) && !IsUp(c)) return false;
      }

      if (q >= i + 2 && ip.at(i) == ip.at(i+1) && ip.at(i) == '0') {
        for (int j=i; j<q; ++j) if (ip.at(j) != '0') return false;  
      }

      i = q;
    }

    return true;
  }

  bool ValidIpv4(const string& ip) {
    int n = ip.size(), cnt = 0;
    for (char c : ip) if (c == '.') ++cnt;
    if (cnt != 3) return false;

    for (char c : ip) if (!isdigit(c) && c != '.') return false;
    int v[4]; for (int i=0; i<4; ++i) v[i] = -1;
    
    sscanf(ip.c_str(), "%d.%d.%d.%d", v, v+1, v+2, v+3);
    
    for (int i=0; i<4; ++i) {
      if (v[i] < 0 || v[i] > 255) return false;
    }

    for (int i=0; i<ip.size(); ) {
      if (i < n && ip.at(i) == '.') ++i;
      if (i ==n ) break;
      if (ip.at(i) == '.') return false;

      int q = i + 1;
      while(q < n && ip.at(q) != '.') ++q;
      if (ip.at(i) == '0' && q != i+1) return false;
      i = q;
    }

    return true;
  }
};
