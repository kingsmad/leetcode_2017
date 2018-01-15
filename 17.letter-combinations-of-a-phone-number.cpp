#include <vector>
#include <string>

using namespace std;

class Solution {
  vector<string> ans;
 public:
  vector<string> letterCombinations(string digits) {
    ans.clear();
    if (digits == "") return ans; 
    string path;
    dfs(0, path, digits);
    return ans;
  }

  void dfs(int p, string& path, const string& digits) {
    if (p == digits.size()) {
      ans.push_back(path); 
      return;
    }
    const string& s = nums[digits[p]-'0'];
    for (char c : s) {
      path.push_back(c);
      dfs(p+1, path, digits);
      path.pop_back();
    }
  }

 private:
  string nums[10] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
  };
};
