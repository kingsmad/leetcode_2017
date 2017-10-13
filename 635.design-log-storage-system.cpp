#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

using ll = long long;

class LogSystem {
  map<ll, int> sid2rid;
public:
    LogSystem() {
        
    }

    ll str2sid(const string& s) {
      int data[6];
      sscanf(s.c_str(), "%d:%d:%d:%d:%d:%d", data, data+1, data+2, data+3,
             data+4, data+5);
      // 18 * 13 * 32 * 25 * 61 * 61;
      ll ans = data[0] - 2000;
      ans = ans * 13 + data[1];
      ans = ans * 32 + data[2];
      ans = ans * 25 + data[3];
      ans = ans * 61 + data[4];
      ans = ans * 61 + data[5];
      return ans;
    }
    
    void put(int id, string timestamp) {
      sid2rid.emplace(str2sid(timestamp), id);  
    }
    
    ll Floor(ll sid, const string& gra) {
      if (gra == "Second") return sid;
      if (gra == "Minute") return sid - sid % 61;
      if (gra == "Hour") return sid - sid % (61 * 61);
      if (gra == "Day") return sid - sid % (61 * 61 * 25);
      if (gra == "Month") return sid - sid % (61 * 61 * 25 * 32);
      return sid - sid % (61 * 61 * 25 * 32 * 13);
    }

    ll Ceil(ll sid, const string& gra) {
      if (gra == "Second") return sid;
      if (gra == "Minute") return sid - sid % 61 + 61;
      if (gra == "Hour") return sid - sid % (61 * 61) + 61 * 61;
      if (gra == "Day") return sid - sid % (61 * 61 * 25) + 61 * 61 * 25;
      if (gra == "Month") return sid - sid % (61 * 61 * 25 * 32) + 61*61*25*32;
      return sid - sid % (61 * 61 * 25 * 32 * 13) + 61 * 61 * 25 * 32 * 13;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
      ll st = Floor(str2sid(s), gra), ed = Ceil(str2sid(e), gra);
      
      auto fst = sid2rid.lower_bound(st);
      auto lst = sid2rid.upper_bound(ed);

      vector<int> ans;
      for (auto it = fst; it != lst; ++it) {
        ans.push_back(it->second); 
      }

      return ans;
    }
};

#ifdef ROACH_ONLINE_JUDGE
/*int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  int m, n; scanf("%d%d", &m, &n);
  vector<string> vstr;
  while(m--) {
    string str; cin >> str;
    vstr.emplace_back(str);
  }

  Solution sol;
  

}*/
#endif

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
