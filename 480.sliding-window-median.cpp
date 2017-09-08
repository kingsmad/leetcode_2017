class Solution {
  class KsQueue {
    public:
    void Push(int x) {
      ms1.insert(x);  
      if (ms1.size() > k_/2) {
        auto c = ms1.end(); --c;
        x = *c;
        ms1.erase(c);
        ms2.insert(x);
      } 
    }

    double FindMedian() {
      if (k_ & 1) {
        return *ms2.begin();
      } else {
        auto c = ms1.end(); --c;
        return (*c + *ms2.begin()) / 2.0;
      }
    }

    void Erase(int x) {
      auto c = ms1.find(x);
      if (c != ms1.end()) {
        ms1.erase(c);
        int x = *ms2.begin();
        ms2.erase(ms2.begin());
        ms1.insert(x);
      } else {
        auto it = ms2.find(x);
        if (it == ms2.end()) return;
        ms2.erase(it);
      }
    }

    void Init(int k) {
      k_ = k;
      ms1.clear();
      ms2.clear();
    }

  private:
    multiset<double> ms1, ms2;
    int k_;
  } ksqueue;
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
      ksqueue.Init(k);
      vector<double> ans;
      for (int i=0; i<k; ++i) ksqueue.Push(nums.at(i));
      for (int i=0; i+k<=nums.size(); ++i) {
        ans.push_back(ksqueue.FindMedian());
        ksqueue.Erase(nums.at(i));
        if (i+k < nums.size()) 
          ksqueue.Push(nums.at(i+k));
      }
     
      return ans;
    }
};
