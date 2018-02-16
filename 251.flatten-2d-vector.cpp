#include <bits/stdc++.h>

using namespace std;

class Vector2D {
  vector<int> tmp;
  vector<int>::iterator iter;
 public:
  Vector2D(vector<vector<int>>& vec2d) {
    tmp.clear(); 
    for (const vector<int>& v : vec2d) {
      tmp.insert(tmp.end(), v.begin(), v.end());
    }
    
    iter = tmp.begin();
  }

  int next() {
    return *iter++;
  }

  bool hasNext() {
    return iter != tmp.end();
  }

};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
