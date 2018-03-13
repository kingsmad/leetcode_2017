#include <bits/stdc++.h>

using namespace std;
const int inf = 2e9 + 10;
const int maxn = 1e5 + 10;

class Solution {
 public:
  int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
    return calc(A, R)  - calc(A, L-1);
  }

  int calc(const vector<int>& A, int target) {
    int n = A.size(), q = 0, cnt = 0;
    deque<int> moq;
    for (int i=0; i<n; ++i) {
      while(moq.size() && moq.front() < i) moq.pop_front();
      q = max(q, i); 
      while(q < n) {
        int v = A[q];
        if (moq.size()) v = max(v, A[moq.front()]);
        if (v <= target) {
          while(moq.size() && A[moq.back()] < A[q]) moq.pop_back();
          moq.push_back(q++);
        } else break;
      }
      cnt += q - i;
    }

    return cnt;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  // vector<int> A = {2, 9, 2, 5, 6};
  // vector<int> A = {2, 1, 4, 3};
  vector<int> A = {73, 55, 36, 5, 55, 14, 9, 7, 72, 52};

  Solution sol;
  int ans = sol.numSubarrayBoundedMax(A, 32, 69);
  printf("%d\n", ans);
  return 0;
}
#endif
