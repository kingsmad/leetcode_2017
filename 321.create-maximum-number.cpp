#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> ans(k, 0);
    for (int i=0; i<=k; ++i) {
      vector<int> vc = merge(sample(nums1, i), sample(nums2, k-i));
      if (vc.size() != k) continue;
      ans = max(ans, vc);
    }

    return ans;
  }

  vector<int> sample(const vector<int>& nums, int cnt) {
    int n = nums.size();
    if (cnt >= n) return nums;
    vector<int> ans;

    cnt = n - cnt;
    for (int d : nums) {
      while(ans.size() && ans.back() < d && cnt > 0) { ans.pop_back(); --cnt;}
      ans.push_back(d);
    }

    while(cnt--) ans.pop_back();
    return ans;
  }
  
  // nums are not monotone, must use mygreat
  vector<int> merge(const vector<int>& nums1, const vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    if (n == 0) return nums2;
    if (m == 0) return nums1;
    vector<int> ans;
    int p = 0, q = 0;
    while(p < n || q < m) {
      if (p < n && q < m) {
        if (mygreat(nums1, p, nums2, q)) ans.push_back(nums1.at(p++));
        else ans.push_back(nums2.at(q++));
        continue;
      }
      if (p < n) ans.push_back(nums1.at(p++));
      else ans.push_back(nums2.at(q++));
    }
    return ans;
  }

  bool mygreat(const vector<int>& nums1, int p, const vector<int>& nums2, int q) {
    int n = nums1.size(), m = nums2.size();
    while(p < n && q < m) {
      if (nums1.at(p) != nums2.at(q)) return nums1[p] > nums2[q];
      ++p, ++q;
    }
    if (p < n ) return true;
    return false;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  //vector<int> v1 = {3, 4, 6, 5};
  //vector<int> v2 = {9, 1, 2, 5, 8, 3};
  vector<int> v2 = {6, 7, 5};
  vector<int> v1 = {4, 8, 1};
  Solution sol;
  vector<int> ans = sol.maxNumber(v1, v2, 3);
  for (int d : ans) printf("%d ", d);
  return 0 * printf("\n");
}
#endif
