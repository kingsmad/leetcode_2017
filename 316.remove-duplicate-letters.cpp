class Solution {
 public:
  string removeDuplicateLetters(string s) {
    string str = "";
    int cnt[26];  memset(cnt, 0, sizeof(cnt));
    for (int i=0; i<s.size(); ++i) ++cnt[s[i]-'a']; 
    bool inq[26]; memset(inq, 0, sizeof(inq));

    int p = 0;
    while(p < s.size()) {
      --cnt[s[p]-'a'];
      if (inq[s[p]-'a']) { ++p; continue;}
      while(!str.empty() && str.back() > s[p] && cnt[str.back()-'a'] > 0) {
        char c = str.back();
        str.pop_back();
        inq[c-'a'] = false;
      }
      str.push_back(s[p]);
      inq[s[p]-'a'] = true;
      ++p;
    }
    
    return str;
  }
    
};
