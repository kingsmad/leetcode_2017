import itertools
class Solution(object):
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """

        n = len(seats)
        dis = [n+1] * n
        for i in range(n):
            if seats[i] == 1:
                dis[i] = 0

        mq = collections.deque(x for x in range(n) if seats[x] == 1)
        while len(mq) > 0:
            x = mq.popleft()
            if x + 1 < n and dis[x+1] > dis[x] + 1:
                dis[x+1] = dis[x] + 1
                mq.append(x+1)
            if x - 1 >= 0 and dis[x-1] > dis[x] + 1:
                dis[x-1] = dis[x] + 1
                mq.append(x-1)

        return max(dis)
