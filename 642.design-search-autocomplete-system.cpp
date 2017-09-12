// 1. trie sz must be initialized as 1, not 0
// 2. answer string order should be 'important string' to 'not that important'
// 3. path must be recorded every time, which means even if no corresponding 
//    candidates, path should also be added by current character.
// 4. A bug was in find(c), boolean 'dead' was used to indicate this path was 
//    already dead, do not check ch[prev_u][c] again!!!

const int sigma_size = 28;
const int maxnode = 10010;


struct Item {
  string str;
  int cnt;
  bool operator<(const Item& rhs) const {
    if (cnt != rhs.cnt) return cnt < rhs.cnt;
    return str > rhs.str;
  }
  Item(const string& s, int d) : str(s), cnt(d) { }
};

class AutocompleteSystem {
 public:
  int ch[maxnode][sigma_size];
  int val[maxnode], sz;

  int prev_u = 0;
  string path = "";
  bool dead = false;

  void clear() {
    sz = 1;
    memset(ch, 0, sizeof(ch));
    memset(val, 0, sizeof(val));
  }

  int idx(char c) {
    if (c == ' ')
      return 26;
    else if (c == '#')
      return 27;
    return c - 'a';
  }

  char ridx(int x) {
    if (x == 26) return ' ';
    if (x == 27) return '#';
    return x + 'a';
  }

  void insert(const string s, int cnt) {
    int u = 0;
    for (int i = 0; i < s.size(); ++i) {
      int c = idx(s[i]);
      if (!ch[u][c]) {
        memset(ch[sz], 0, sizeof(ch[sz]));
        ch[u][c] = sz++;
      }
      u = ch[u][c];
    }
    val[u] += cnt;
  }

  void dfs(int u, string& str, set<Item>& smp) {
    if (val[u] != 0) {
      smp.emplace(Item(str, val[u]));
      if (smp.size() > 3) { smp.erase(smp.begin()); }
    }

    for (int i = 0; i < sigma_size; ++i) {
      if (ch[u][i]) {
        str.push_back(ridx(i));
        dfs(ch[u][i], str, smp);
        str.pop_back();
      }
    }
  }

  AutocompleteSystem(vector<string> sentences, vector<int> times) {
    clear();
    for (int i = 0; i < times.size(); ++i) {
      insert(sentences.at(i), times.at(i));
    }
  }

  vector<string> input(char c) {
    if (c == '#') {
      insert(path, 1);  
      path = "";
      prev_u = 0;
      dead = false;
      return vector<string>();
    }

    path += c;
    if (dead || !ch[prev_u][idx(c)]) { 
      dead = true;
      return vector<string>();
    }
    
    prev_u = ch[prev_u][idx(c)];
    set<Item> smp;
    string pre_str = path;
    dfs(prev_u, pre_str, smp);

    vector<string> ans;
    for (auto c=smp.rbegin(); c!=smp.rend(); ++c) ans.emplace_back(c->str);
    return ans;
  }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */
