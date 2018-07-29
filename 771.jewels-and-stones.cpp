#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numJewelsInStones(string J, string S) {
    unordered_set<char> ms;    
    for (char c : J) ms.insert(c);
    
    int cnt = 0;
    for (char c : S) if (ms.count(c) > 0) ++cnt;
    return cnt;
  }
};
