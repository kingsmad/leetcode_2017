/*#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<string> removeComments(vector<string>& source) {
    vector<string> result;
    bool comment = false;

    string s;
    for (auto& word : source) {
      int n = word.size();
      for (int i = 0; i < n; ++i) {
        char c = word[i];
        int j = i + 1;

        if (!comment && j < n && c == '/' && word[j] == '/') {
          break;
        } else if (!comment && j < n && c == '/' && word[j] == '*') {
          comment = true;
          i = j;
        } else if (comment && j < n && c == '*' && word[j] == '/') {
          comment = false;
          i = j;
        } else if (!comment) {
          s += c;
        }
      }

      if (!comment && !s.empty()) {
        result.emplace_back(s);
        s.clear();
      }
    }

    return result;
  }
};*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  vector<string> removeComments(vector<string>& source) {
    int state = 0;
    stringstream ss("", ios_base::in | ios_base::out | ios_base::ate);
    for (const string& s : source) {
      ss << s; 
      ss << "\n";
    }

    stringstream out("", ios_base::in | ios_base::out | ios_base::ate);
    while(ss.peek() != EOF) {
      char c = ss.get(), nc = ss.peek();
      if (state == 0) {
        if (c == '/' && nc == '/') {
          state = 1;
          ss.get();
        } else if (c == '/' && nc == '*') { 
          state = 2;
          ss.get();
        } else {
          out.put(c);
        }
        continue;
      }

      if (state == 1) {
        if (c == '\n') {
          state = 0;
          out.put(c);
        }
        continue;
      }

      if (state == 2) {
        if (c == '*' && nc == '/') {
          state =  0;
          ss.get();
        }
        continue;
      }
    }

    vector<string> ans;
    for (string line; getline(out, line); ) {
      if (line.size() > 0) ans.push_back(line);
    }
    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int ,char**) {
  vector<string> input = {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
  for (string& s : input) {
    cout << s << endl;
  }
  Solution sol;
  vector<string> ans = sol.removeComments(input);
  for (const string& s: ans) cout << s << endl;


  cout << "\n\n\nsample:" << endl;
  vector<string> sample = {"int main()","{ ","  ","int a, b, c;","a = b + c;","}"};
  for (const string& s : sample) cout << s << endl;

  return 0;
}
#endif
