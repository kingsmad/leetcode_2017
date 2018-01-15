#include <assert.h>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

#ifdef ROACH_ONLINE_JUDGE
struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};
#endif

class Solution {
  using Node = UndirectedGraphNode;
  unordered_map<Node*, Node*> ms;
 public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    using Node = UndirectedGraphNode;
    ms.clear();
    unordered_set<Node*> vis;
    dfs(node, vis);
    vector<Node*> nodes(vis.begin(), vis.end());

    int n = nodes.size();
    vector<Node*> ans(n, nullptr);
    for (int i=0; i<n; ++i) { 
      //ans[i] = (Node*)malloc(sizeof(Node));
      ans[i] = new Node(nodes[i]->label);
      //memcpy(ans[i], nodes[i], sizeof(Node));
      ans[i]->neighbors = nodes[i]->neighbors;
      ms.emplace(nodes[i], ans[i]);
    }

    for (Node* p : ans) {
      for (int i=0; i<p->neighbors.size(); ++i) {
        p->neighbors[i] = ms[p->neighbors[i]];
      }
    }

    return ms[node];
  }

  void dfs(Node* o, unordered_set<Node*>& vis) {
    using Node = UndirectedGraphNode;
    if (!o || vis.count(o) > 0) return;

    vis.insert(o);
    for (Node* p : o->neighbors) dfs(p, vis);
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  using Node = UndirectedGraphNode;
  vector<Node*> nodes(3, 0);
  for (int i=0; i<3; ++i) nodes[i] = new Node(0);
  for (int i=0; i<3; ++i) nodes[i]->neighbors.push_back(nodes[(i+1)%3]);

  Solution sol;
  Node* o = sol.cloneGraph(nodes[0]);
  return 0;
}
#endif
