#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int shortestWordDistance(vector<string>& words, string word1, string word2) {
    vector<int> sids;
    for (int i=0; i<words.size(); ++i) {
      if (words.at(i) == word1 || words.at(i) == word2) sids.push_back(i);
    }

    int ans = words.size() + 1;
    if (word1 != word2) {
      for (int i=0; i+1<sids.size(); ++i) {
        if (words.at(sids[i]) != words.at(sids[i+1])) 
          ans = min(ans, sids[i+1] - sids[i]);
      }
    } else {
      for (int i=0; i+1<sids.size(); ++i) {
        ans = min(ans, sids[i+1] - sids[i]);
      }
    }

    return ans;
  }
};
