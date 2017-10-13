#include <vector>
#include <cstring>
#include <iostream>
#include <climits>

using namespace std;

const int maxn = 1e6 + 10;

int Sid(const vector<int>& v) {
  int ans = 0;
  for (int i=0; i<v.size(); ++i) {
    ans = ans * 7 + v.at(i); 
  }
  return ans; 
}

int dp[maxn];

bool Greater(const vector<int>& v1, const vector<int>& v2) {
  for (int i=0; i<v1.size(); ++i) {
    if (v1.at(i) < v2.at(i)) return false;
  }

  return true;
}

void Minus(vector<int>& v1, const vector<int>& v2) {
  for (int i=0; i<v1.size(); ++i) v1[i] -= v2.at(i);
}

void Add(vector<int>& v1, const vector<int>& v2) {
  for (int i=0; i<v1.size(); ++i) v1[i] += v2.at(i);
}

int calc(vector<int>& state, const vector<int>& price, 
         const vector<vector<int>>& special) {
  int sid = Sid(state);
  int n = state.size();
  if (dp[sid] != -1) return dp[sid];
  if (sid == 0) return dp[sid] = 0;
  
  dp[sid] = INT_MAX; 
  for (int i=0; i<n; ++i) {
    if (state.at(i) > 0) {
      --state[i];
      dp[sid] = min(dp[sid], price.at(i) + calc(state, price, special));
      ++state[i];
    }
  }

  for (const vector<int>& sp : special) {
    if (!Greater(state, sp)) continue;
    Minus(state, sp);
    dp[sid] = min(dp[sid], sp.back() + calc(state, price, special));
    Add(state, sp);
  }

  return dp[sid];
}

class Solution {
 public:
  int shoppingOffers(vector<int>& price, vector<vector<int>>& special,
                     vector<int>& needs) {
    memset(dp, -1, sizeof(dp)); 
    int ans = calc(needs, price, special);     
    return ans;
  }
};
