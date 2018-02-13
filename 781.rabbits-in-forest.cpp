#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numRabbits(vector<int>& answers) {
    sort(answers.begin(), answers.end());

    int ans = 0;
    int n = answers.size();
    for (int i=0; i<n; ) {
      int q = i + 1;
      while(q < n && q < i+answers[i]+1 && answers[q] == answers[i]) ++q;
      ans += answers[i] + 1;
      i = q;
    }

    return ans;
  }
};
