#include <vector>
#include <string>
#include <iostream>
using namespace std;
int row, col;
class Solution {
 public:
  int findBlackPixel(vector<vector<char>>& picture, int N) {
     row = picture.size(); 
     if (row == 0) return 0;
     col = picture.at(0).size();

     vector<int> rcnt(row, 0), ccnt(col, 0);
     for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) {
       if (picture[i][j] == 'B') ++rcnt[i], ++ccnt[j];
     }

     int ans = 0;
     for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) {
       if (picture[i][j] == 'W' || rcnt[i] != N || ccnt[j] != N) continue;
       bool ok = true;
       for (int z=0; z<row; ++z) {
         if (picture[z][j] == 'W') continue;
         if (!check(i, z, picture)) { ok = false; break;}
       }
       if (ok) ++ans;
     }
     return ans;
  }

  bool check(int x, int y, const vector<vector<char>>& pic) {
    if (x == y) return true;
    for(int j=0; j<col; ++j) if (pic[x][j] != pic[y][j]) return false;
    return true;
  }
};
