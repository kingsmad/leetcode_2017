#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      reverse(digits.begin(), digits.end());
      int carry = 1;
      for (int i=0; i<digits.size() && carry; ++i) {
        digits[i] += carry;
        carry = 0;
        if (digits[i] >= 10) { digits[i] -= 10; carry = 1;}
      }

      if (carry) digits.push_back(1);

      reverse(digits.begin(), digits.end());
      return digits;
    }
};
