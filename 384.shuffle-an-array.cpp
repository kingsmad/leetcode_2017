#include <iostream>
#include <vector>

using namespace std;
class Solution {
  vector<int> nums_;
  vector<int> vt;
public:
    Solution(vector<int> nums) {
       nums_ = nums; 
       vt = nums_;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
      vt = nums_; 
      return vt;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
      for (int i=0; i<vt.size(); ++i) {
        int j = rand() % (vt.size()-i);
        swap(vt[i], vt[i+j]);
      }
      return vt;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
