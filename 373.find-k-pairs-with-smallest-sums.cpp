#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class Solution {
 public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                        int k) {
    auto fn = [](pair<int, int> p1, pair<int, int> p2) { 
      return p1.first + p1.second < p2.first + p2.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(fn)> mq(fn); 
    
    int n1 = nums1.size(), n2 = nums2.size();
    int p = 0, qcap = n2;

    while(p < n1) {
      for (int i=0; i<qcap; ++i) {
        if (mq.size() < k) {
          mq.push(make_pair(nums1[p], nums2[i])); 
        } else if (fn(make_pair(nums1[p], nums2[i]), mq.top())) {
          mq.push(make_pair(nums1[p], nums2[i])); 
          mq.pop();
        } else {
          qcap = i;
          break;
        }
      }
      ++p;
    }

    vector<pair<int, int>> ans;
    while(!mq.empty()) {
      ans.push_back(mq.top());
      mq.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
