#include <math.h>
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

struct Node {
  int val, inq;
  Node() { val = -1; inq = 0;}
};

class Solution {
  public:
    inline int lc(int o) { return 2*o + 1;}
    inline int rc(int o) { return 2*o + 2;}
    int GetId(int l, int x){
      return pow(2, l-1) + x - 2;
    }

    void InitNode(int x, vector<Node>& nodes) {
      int v = x % 10; x = x / 10;
      int p = x % 10; x = x / 10;
      int l = x;

      int sid = GetId(l, p);
      nodes[sid].val = v; 
      nodes[sid].inq = 1;
    }

    void dfs(int o, vector<Node>& nodes, int& ans, int& path) {
      if (o >= 16 || nodes[o].inq == 0) return; 
      path += nodes[o].val;
      if (IsLeaf(o, nodes)) { ans += path; path -= nodes[o].val; return;}
      dfs(lc(o), nodes, ans, path);
      dfs(rc(o), nodes, ans, path);
      path -= nodes[o].val;
    }

    bool IsLeaf(int o, vector<Node>& nodes) {
      int x = lc(o);
      if (x < 16 && nodes[x].inq) return false;
      x = rc(o);
      if (x < 16 && nodes[x].inq) return false;
      return true;
    }

    int pathSum(vector<int>& nums) {
      vector<Node> nodes(16);
      for (int d : nums) InitNode(d, nodes);

      int ans = 0, path = 0;
      dfs(0, nodes, ans, path);

      return ans;
    }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  int n; scanf("%d", &n);
  vector<int> nums;
  for (int i=0; i<n; ++i) {
    int d; scanf("%d", &d);
    nums.push_back(d);
  }
  Solution sol;
  int ans = sol.pathSum(nums);
  
  printf("%d\n", ans);
}

#endif
