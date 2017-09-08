class Solution {
public:
    int candy(vector<int>& ratings) {
      int len = ratings.size();
      vector<int> v(len, 1);
      for (int i=0; i+1<len; ++i) {
        if (ratings[i] > ratings[i+1] && v[i] <= v[i+1]) 
          v[i] = v[i+1] + 1;
        if (ratings[i] < ratings[i+1] && v[i] >= v[i+1]) 
          v[i+1] = v[i] + 1;
      }

      for (int i=len-1; i>0; --i) {
        if (ratings[i] > ratings[i-1] && v[i] <= v[i-1]) 
          v[i] = v[i-1] + 1;
        if (ratings[i] < ratings[i-1] && v[i] >= v[i-1]) 
          v[i-1] = v[i] + 1;
      }

      int res = 0;
      for (int i=0; i<len; ++i) res += v[i]; 
      return res;
    }
};
