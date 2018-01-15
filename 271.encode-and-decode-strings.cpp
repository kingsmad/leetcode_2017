#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int buf_sz = 1e3 + 10;

union header {
  int64_t d;
  char s[8];
};

class Codec {
 public:
  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    char* buf = (char*)malloc(buf_sz);
    int offset = 0;
    string ans;
    for (const string& s : strs) {
      const char* str = s.c_str();
      int src_st = 0;

      // add string header
      union header hd;
      hd.d = (int64_t)s.size();
      ans += string(hd.s, 8);
       
      // add the string itself
      offset = 0;
      while(src_st < s.size()) {
        int wlen = min((int)s.size() - src_st, buf_sz - offset);    
        memcpy(buf+offset, str + src_st, wlen * sizeof(char));
        offset += wlen;
        src_st += wlen;
        
        ans += string(buf, offset);
        offset = 0;
      }
    }
    return ans;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    int n = s.size();
    int pos = 0;
    vector<string> ans;
    while(pos < n) {
      union header hd;
      memcpy(hd.s, s.c_str() + pos, 8);
      pos += 8;
      int len = hd.d;
      
      ans.push_back(string(s.substr(pos, len))); 
      pos += len;
    }

    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  Codec codec;
  int n; cin >> n;
  vector<string> strs;
  for (int i=0; i<n; ++i) {
    string str; cin >> str;
    strs.push_back(str); 
  }

  string enc_str = codec.encode(strs);
  cout << enc_str << endl;

  vector<string> dec_strs = codec.decode(enc_str);
  for (int i=0; i<dec_strs.size(); ++i) {
    cout << dec_strs.at(i) << endl;
  }

  return 0;
}
#endif

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
