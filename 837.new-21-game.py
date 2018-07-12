class Solution(object):
    def new21Game(self, N, K, W):
        """
        :type N: int
        :type K: int
        :type W: int
        :rtype: float
        """
        ms = { }
        def calc(x):
            if x == 1: return 1.0 / W
            if x in ms.keys():
                return ms[x]
            p = 0.0
            for y in range(1, W+1):
                if 0 <= x - y < K:
                    p += 1.0 / W * calc(x - y)
            ms[x] = p
            return p

        return sum(calc(i) for i in range(K, N+1))
