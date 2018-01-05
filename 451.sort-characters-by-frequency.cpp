#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
 public:
  string frequencySort(string s) {
    map<char, int> ms;
    for (char c : s) ++ms[c];

    sort(s.begin(), s.end(), [&](char c1, char c2) { 
        if (ms[c1] != ms[c2]) return ms[c1] > ms[c2];
        return c1 < c2;
    });
    return s;
  }
};
