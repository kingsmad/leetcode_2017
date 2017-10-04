#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class MagicDictionary {
  unordered_set<string> smp;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
       smp.clear(); 
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
      smp.clear();
      for (string& c: dict) smp.emplace(c); 
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
      for (const string& s : smp) if (cmp(s, word)) return true;
      return false;
    }

    bool cmp(const string& s1, const string& s2) {
      if (s1.size() != s2.size()) return false;
      int cnt = 0;
      for (int i=0; i<s1.size(); ++i) if (s1.at(i) != s2.at(i)) {
        if (++cnt >= 2) return false;
      }
      return cnt == 1;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
