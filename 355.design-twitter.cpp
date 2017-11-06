#include <queue>
#include <map>
#include <vector>
#include <iostream>
#include <set>
#include <deque>

using namespace std;

struct Tweet {
  int sid, tm, val; 
  Tweet(int d1, int d2, int d3) : sid(d1), tm(d2), val(d3) { }
};

class Twitter {
 map<int, deque<Tweet>> smp; 
 map<int, set<int> > fmp;
 int tm = 0;
 public:
  /** Initialize your data structure here. */
  Twitter() {
    smp.clear();
    fmp.clear();
    tm = 0;
  }

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    Init(userId);

    smp[userId].push_back(Tweet(userId, tm++, tweetId));
    if (smp[userId].size() > 10) smp[userId].pop_front();
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
   * in the news feed must be posted by users who the user followed or by the
   * user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    Init(userId);

    auto fn = [](Tweet& t1, Tweet& t2) {
      return t1.tm < t2.tm;
    };
    priority_queue<Tweet, vector<Tweet>, decltype(fn)> mq(fn);

    for (int sid : fmp.at(userId)) {
      for (const Tweet& t : smp.at(sid)) mq.push(t);
    }

    int cnt = 10;
    vector<int> ans;
    while(!mq.empty() && cnt--) { ans.push_back(mq.top().val); mq.pop();}

    return ans;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a
   * no-op. */
  void follow(int followerId, int followeeId) {
    Init(followerId);
    Init(followeeId);
    fmp[followerId].insert(followeeId);
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op. */
  void unfollow(int followerId, int followeeId) {
    Init(followerId);
    Init(followeeId);
    if (followerId == followeeId) return;
    fmp[followerId].erase(followeeId);
  }

  void Init(int sid) {
    if (smp.count(sid) == 0) smp.emplace(sid, deque<Tweet>());
    if (fmp.count(sid) == 0) fmp.emplace(sid, set<int>({sid}));
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
