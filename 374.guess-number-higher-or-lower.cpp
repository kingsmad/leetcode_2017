// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);
using ll = long long;

class Solution {
 public:
  int guessNumber(int n) {
    if (guess(n) == 0) return n;
    ll l = 0, r = n; 
    while(l < r) {
      int md = ((ll)l+r)/ 2;
      int v = guess(md);
      if (v > 0) l = md + 1;
      else if (v < 0) r = md;
      else return md;
    }

    return -1;
  }
};
