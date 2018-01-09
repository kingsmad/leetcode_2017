#include <iostream>
#include <vector>

using namespace std;

class ZigzagIterator {
  vector<int> buf;
  int pos;
public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    buf.clear();
    pos = 0;
    vector<vector<int>* > ma({&v1, &v2});
    int n = max(v1.size(), v2.size());
    for (int j=0; j<n; ++j) for (int i=0; i<2; ++i) {
      vector<int>* vc = ma[i];
      if (j < vc->size()) {
        buf.push_back((*vc)[j]);
      }
    }
  }


  int next() {
    return buf.at(pos++);
  }

  bool hasNext() {
    return pos < buf.size();
  }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
