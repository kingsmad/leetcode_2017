#include <bits/stdc++.h>

using namespace std;

class LRUCache {
  map<int, list<pair<int, int>>::iterator> ms;
  list<pair<int, int>> mlist;
  int cap;

 public:
  LRUCache(int capacity) {
    ms.clear();
    mlist.clear();
    cap = capacity;
  }

  int get(int key) {
    if (ms.count(key) == 0) return -1;

    auto it = ms.at(key);
    int v = it->second;

    mlist.erase(it);
    ms.erase(key);

    mlist.push_front({key, v});
    ms.emplace(key, mlist.begin());
    return v;
  }

  void put(int key, int value) {
    if (ms.count(key) > 0) {
      auto it = ms.at(key);
      mlist.erase(it);
      ms.erase(key);
    }
    if (mlist.size() == cap) {
      int k = mlist.back().first;
      mlist.pop_back();
      ms.erase(k);
    }

    mlist.push_front({key, value});
    ms.emplace(key, mlist.begin());
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
