class Solution {
using ll = long long;
 public:
  int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
    ll res = 0;        
    int n = Capital.size();
    vector<int> sids;
    for (int i=0; i<n; ++i) sids.push_back(i);
    sort(sids.begin(), sids.end(), [&](int p, int q) { 
        return Capital[p] < Capital[q]; 
    });
    
    ll sum = W;
    int p = 0;
    priority_queue<int> mq;
    while(1) {
      if (k <= 0) break;
      while(p < n && Capital[sids[p]] <= sum) {
        mq.push(Profits[sids[p]]);
        ++p;
      }
      if (mq.empty()) break;
      sum += mq.top();
      mq.pop();
      --k;
    }

    return sum;
  }
};
