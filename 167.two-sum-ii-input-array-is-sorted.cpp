class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int n = numbers.size();
      int p = 0, q = n-1;
      while(p < q) {
        int v = numbers[p] + numbers[q]; 
        if (v < target) ++p;
        else if (v > target) --q;
        else return {p+1, q+1};
      }
      return {-1, -1};
    }
};
