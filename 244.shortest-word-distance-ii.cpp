#include <map>
#include <string>
#include <vector>

using namespace std;
map<string, vector<int> > ms;
int n;

class WordDistance {
 public:
  WordDistance(vector<string> words) {
    ms.clear();
    n  = words.size();
    for (int i=0; i<n; ++i) {
      const string& s = words.at(i);
      if (ms.count(s) == 0) ms.emplace(s, vector<int>());
      ms[s].push_back(i);
    }
  }

  int shortest(string word1, string word2) {
    vector<int>& v1 = ms[word1];
    vector<int>& v2 = ms[word2];

    int ans =  n + 1;
    int p = 0, q = 0; 
    while(1) {
      if ( p == v1.size() || q == v2.size()) break;
      ans = min(ans, abs(v1.at(p) - v2.at(q))); 
      if (v1.at(p) < v2.at(q)) ++p;
      else ++q;
    }
    return ans;
  }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
