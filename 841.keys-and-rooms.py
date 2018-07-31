class Solution(object):
    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        n = len(rooms)
        fa = [i for i in range(0, n)]
        def findset(x):
            if x == fa[x]: return fa[x]
            fa[x] = findset(fa[x])
            return fa[x]
        def join(x, y):
            fa[findset(x)] = fa[findset(y)]

        for i, vl in enumerate(rooms):
            for j in vl:
                join(i, j)

        ms = set()
        for i in range(n): ms.add(findset(i))

        return len(ms) == 1



