# Definition for a point.
# class Point(object):
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution(object):
    def outerTrees(self, points):
        """
        :type points: List[Point]
        :rtype: List[Point]
        """

        def sign(p, q, r):
            return cmp((p.x - r.x) * (q.y - r.y), (p.y - r.y) * (q.x - r.x))

        def drive(hull, r):
            hull.append(r)
            while len(hull) >= 3 and sign(*hull[-3:]) < 0:
                    hull.pop(-2);
            return hull

        points.sort(key=lambda p:(p.x, p.y))
        lower = reduce(drive, points, [])
        upper = reduce(drive, points[::-1], [])
        return list(set(lower+upper))
