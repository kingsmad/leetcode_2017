#include <iostream>
#include <map>
#include <set>
#include <vector>


using namespace std;

int n, total;
map<pair<int, int>, int> smp;
int bs;

class Solution {
 public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    n = maxChoosableInteger, total = desiredTotal; 
    bs = 0;
    for (int i=n+1; i<32; ++i) bs = bs & (1<<i);
    return Calc(bs, total);
  }

  bool Calc(int bs, int sum) {
    if (smp.count(make_pair(bs, sum)) > 0) return smp.at(make_pair(bs, sum)); 

    int cnt = 0, t = 0; 
    if (sum <= 0) goto myfalse;
    for (int i=0; i<n; ++i) if (!(bs & (1<<i))) { 
      if (i + 1 >= sum) goto mytrue;
      ++cnt; t += i+1;
    }
    
    if (t < sum || cnt == 0) goto myfalse;

    for (int i=0; i<n; ++i) {
      if (!(bs & (1<<i))) {
        int nbs = bs & (1<<i);
        if (!Calc(nbs, sum-i-1)) goto mytrue;
      }
    }

myfalse:
    smp[make_pair(bs, sum)] = false;
    return false;

mytrue:
    smp[make_pair(bs, sum)] = true;
    return true;
  }
};
