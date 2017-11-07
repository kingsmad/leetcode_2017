/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
  vector<int> mvec;
  int sz = 0;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
      mvec.clear();
      sz = 0;
      for (const NestedInteger& p : nestedList) dfs(p);
    }

    void dfs(const NestedInteger& nest) {
      if (nest.isInteger()) { mvec.push_back(nest.getInteger()); return;}
      for (const NestedInteger& p : nest.getList()) {
        dfs(p);
      }
    }

    int next() {
      return mvec.at(sz++);          
    }

    bool hasNext() {
      return sz < mvec.size(); 
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
