#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans;
    for (int d : asteroids) {
      if (d > 0) { ans.push_back(d); continue; }
      while(1) {
        if (ans.empty() || ans.back() < 0) { 
          ans.push_back(d); break;
        }

        if (ans.back() > -d) break;
        if (ans.back() < -d) { ans.pop_back(); continue;}
        if (ans.back() == -d) { ans.pop_back(); break;}
      }
    }

    return ans;
  }
};
