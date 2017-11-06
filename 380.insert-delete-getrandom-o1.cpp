#include <vector>
#include <string>
#include <map>

using namespace std;
  vector<int> mvec;
  map<int, int> val2idx;

class RandomizedSet {
 public:
  /** Initialize your data structure here. */
  RandomizedSet() {
    mvec.clear();
    val2idx.clear();
  }

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (val2idx.count(val) > 0) return false;
    mvec.push_back(val);
    val2idx.emplace(val, mvec.size() - 1);

    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (val2idx.count(val) == 0) return false;

    int x = val2idx.at(val);
    mvec[x] = mvec.back();
    val2idx[mvec.back()] = x;
    
    mvec.pop_back();
    val2idx.erase(val);

    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    int x = rand() % mvec.size();
    return mvec.at(x);
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
